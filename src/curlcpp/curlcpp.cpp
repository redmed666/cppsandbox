#include <curlcpp/curlcpp.hpp>
#include <boost/lexical_cast.hpp>

namespace CurlCpp {
    CurlCpp::CurlCpp() : _headers(new CurlHeadersCpp), _curlHandler(new CurlHandlerCpp){
        try {
            _curlInitCode = curl_global_init(CURL_GLOBAL_DEFAULT);
            if(_curlInitCode != CURLE_OK) {
                const char *pszErrorCode = curl_easy_strerror(_curlInitCode);
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

    CurlCpp::CurlCpp(const CurlCpp& source) {

        // allocate variables
        CurlCpp::CurlCpp();

        // copy values
        operator = (source);
    }

    const CurlCpp& CurlCpp::operator = (const CurlCpp &source) {
        _headers = source._headers;
        _curlInitCode = source._curlInitCode;
        _curlHandler = source._curlHandler;
        _url = source._url;
        _responseBody = source._responseBody;
        return *this;
    }

    CurlCpp::~CurlCpp() {
        curl_global_cleanup();
    }

    void CurlCpp::setUrl(std::string urlPort) {
        _url = urlPort;
        curl_easy_setopt(getHandler(), CURLOPT_URL, urlPort.c_str());
    }

    std::string CurlCpp::getUrl() {
        return _url;
    }

    int CurlCpp::performRequest() {
        int responseCode = 0;
        try {
            if(_url.empty()) {
                throw CurlCppException("No URL defined.");
            }

            auto WriteCallback = [](void *contents, size_t size, size_t nmemb, void *userp)
            {
                ((std::string*)userp)->append((char*)contents, size * nmemb);
                return size * nmemb;
            };

            std::string responseBody;

            typedef size_t(*CURL_WRITEFUNCTION_PTR)(void*, size_t, size_t, void*);
            setopt(CURLOPT_WRITEFUNCTION, static_cast<CURL_WRITEFUNCTION_PTR>(WriteCallback));
            setopt(CURLOPT_WRITEDATA, &responseBody);
            curl_easy_perform(_curlHandler->getHandler());
            curl_easy_getinfo(_curlHandler->getHandler(), CURLINFO_RESPONSE_CODE, &responseCode);

            _responseBody = responseBody;
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
        return _responseBody;
    }

    curl_slist* CurlCpp::getHeaders() {
        return _headers->getHeaders();
    }

    CURL* CurlCpp::getHandler() {
        return _curlHandler->getHandler();
    }

    std::vector<std::string> CurlCpp::getVecStrHeaders() {
        return _headers->getVecStrHeaders();
    }

    void CurlCpp::appendHeaders(std::string header) {
        _headers->appendHeaders(header);
        return;
    }

}
