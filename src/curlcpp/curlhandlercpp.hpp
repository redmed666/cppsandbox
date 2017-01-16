#pragma once
#include <curl/curl.h>
#include "curlcpp/curlcppexception.hpp"

namespace CurlCpp {
    class CurlHandlerCpp {
    public:
        CurlHandlerCpp();
        ~CurlHandlerCpp();
        CURL* getHandler();

    private:
        CURL* _curlHandler;
    };
}
