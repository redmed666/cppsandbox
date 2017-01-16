#include <curlcpp/curlcpp.hpp>
#include <boost/lexical_cast.hpp>

namespace CurlCpp {
    CurlCpp::CurlCpp() : _headers(new CurlHeadersCpp), _curlHandler(new CurlHandlerCpp){
        try {
            _curlInitCode = curl_global_init(CURL_GLOBAL_DEFAULT);
            if(_curlInitCode != CURLE_OK) {
                const char *pszErrorCode = curl_easy_strerror(this->_curlInitCode);
                std::string errorMessageGlobalInit = "Failed during curl_global_init with error message = " + std::string(pszErrorCode);
                throw CurlCppException(errorMessageGlobalInit);
            }


        }
        catch (CurlCppException &error) {
            std::cout << error.what() << std::endl;
        }
        catch (std::bad_alloc &error) {
            std::cout << error.what() << std::endl;
        }
    }

    CurlCpp::~CurlCpp() {
        curl_global_cleanup();
    }

    void CurlCpp::setUrl(std::string urlPort) {
        this->_url = urlPort;
        curl_easy_setopt(this->getHandler(), CURLOPT_URL, urlPort.c_str());
    }

    int CurlCpp::performRequest() {
        int responseCode = 0;
        try {
            if("NULL" == this->_url) {
                throw CurlCppException("No URL defined.");
            }

            auto WriteCallback = [](void *contents, size_t size, size_t nmemb, void *userp)
            {
                ((std::string*)userp)->append((char*)contents, size * nmemb);
                return size * nmemb;
            };

            std::string responseBody;

            typedef size_t(*CURL_WRITEFUNCTION_PTR)(void*, size_t, size_t, void*);
            this->setopt(CURLOPT_WRITEFUNCTION, static_cast<CURL_WRITEFUNCTION_PTR>(WriteCallback));
            this->setopt(CURLOPT_WRITEDATA, &responseBody);
            curl_easy_perform(this->_curlHandler->getHandler());
            curl_easy_getinfo(this->_curlHandler->getHandler(), CURLINFO_RESPONSE_CODE, &responseCode);

            this->_responseBody = responseBody;
            if(responseCode != 200) {
                std::string errorMessage = "HTTP Request failed. Response code is " + boost::lexical_cast<std::string>(responseCode);
                throw CurlCppException(errorMessage);
            }
        }

        catch(CurlCppException &error) {
            std::cout << error.what() << std::endl;
        }

        return responseCode;
    }

    std::string CurlCpp::getResponseBody() {
        return this->_responseBody;
    }

    curl_slist* CurlCpp::getHeaders() {
        return this->_headers->getHeaders();
    }

    CURL* CurlCpp::getHandler() {
        return this->_curlHandler->getHandler();
    }

    std::vector<std::string> CurlCpp::getVecStrHeaders() {
        return this->_headers->getVecStrHeaders();
    }

    void CurlCpp::appendHeaders(std::string header) {
        this->_headers->appendHeaders(header);
        return;
    }

}
