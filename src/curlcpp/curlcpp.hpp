#pragma once
#include <curl/curl.h>
#include <iostream>
#include <vector>
#include "curlcpp/curlcppexception.hpp"
#include "curlcpp/curlhandlercpp.hpp"
#include "curlcpp/curlheaderscpp.hpp"

namespace CurlCpp {
    class CurlCpp {
    public:
        CurlCpp();
        ~CurlCpp();
        void setUrl(std::string urlPort);
        int performRequest();
        std::string getResponseBody();
        curl_slist* getHeaders();
        CURL* getHandler();
        std::vector<std::string> getVecStrHeaders();
        void appendHeaders(std::string header);

        template<typename T, typename TCurl>
        void setopt(TCurl curlOption, T input) { curl_easy_setopt(this->_curlHandler->getHandler(), curlOption, input); }

    private:
        std::auto_ptr<CurlHeadersCpp> _headers;
        CURLcode _curlInitCode;
        std::auto_ptr<CurlHandlerCpp> _curlHandler;
        std::string _url = "NULL";
        std::string _responseBody;
    };
}
