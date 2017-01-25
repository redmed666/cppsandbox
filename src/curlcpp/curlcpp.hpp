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
        CurlCpp(const CurlCpp &source);
        ~CurlCpp();
        void setUrl(std::string urlPort);
        std::string getUrl();
        int performRequest();
        std::string getResponseBody();
        curl_slist* getHeaders();
        CURL* getHandler();
        std::vector<std::string> getVecStrHeaders();
        void appendHeaders(std::string header);

        const CurlCpp& operator= (const CurlCpp &source);

        template<typename T, typename TCurl>
        void setopt(TCurl curlOption, T input) { curl_easy_setopt(_curlHandler->getHandler(), curlOption, input); }

    private:
        std::shared_ptr<CurlHeadersCpp> _headers;
        CURLcode _curlInitCode;
        std::shared_ptr<CurlHandlerCpp> _curlHandler;
        std::string _url;
        std::string _responseBody;
    };
}
