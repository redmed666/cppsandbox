#pragma once
#include <curl/curl.h>
#include "curlcpp/curlcppexception.hpp"

namespace CurlCpp {
    class CurlHandlerCpp {
    public:
        CurlHandlerCpp();
        CurlHandlerCpp(const CurlHandlerCpp& source);
        ~CurlHandlerCpp();
        CURL* getHandler();
        const CurlHandlerCpp& operator= (const CurlHandlerCpp &source);

    private:
        CURL* _curlHandler;
    };
}
