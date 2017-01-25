#include "curlcpp/curlhandlercpp.hpp"

namespace CurlCpp {
    CurlHandlerCpp::CurlHandlerCpp() {
        _curlHandler = curl_easy_init();
        if(!_curlHandler) {
            std::string errorMessageEasyInit = "Failed during curl_easy_init";
            throw CurlCppException(errorMessageEasyInit);
        }
    }

    CurlHandlerCpp::CurlHandlerCpp(const CurlHandlerCpp& source) {

        // allocate variables
        CurlHandlerCpp::CurlHandlerCpp();

        // copy values
        operator = (source);
    }

    const CurlHandlerCpp& CurlHandlerCpp::operator= (const CurlHandlerCpp &source) {
        _curlHandler = source._curlHandler;
        return *this;
    }

    CurlHandlerCpp::~CurlHandlerCpp() {
        if(_curlHandler) { curl_easy_cleanup(_curlHandler); }
    }

    CURL* CurlHandlerCpp::getHandler() {
        return _curlHandler;
    }

}
