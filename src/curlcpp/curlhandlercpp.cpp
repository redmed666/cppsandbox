#include "curlcpp/curlhandlercpp.hpp"

namespace CurlCpp {
    CurlHandlerCpp::CurlHandlerCpp() {
        this->_curlHandler = curl_easy_init();
        if(!this->_curlHandler) {
            std::string errorMessageEasyInit = "Failed during curl_easy_init";
            throw CurlCppException(errorMessageEasyInit);
        }
    }

    CurlHandlerCpp::~CurlHandlerCpp() {
        if(this->_curlHandler) { curl_easy_cleanup(this->_curlHandler); }
    }

    CURL* CurlHandlerCpp::getHandler() {
        return _curlHandler;
    }

}
