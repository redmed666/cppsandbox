#pragma once
#include <curl/curl.h>
#include "curlcpp/curlcppexception.hpp"
#include <string>
#include <vector>

namespace CurlCpp {
    class CurlHeadersCpp {
    public:
        CurlHeadersCpp();
        ~CurlHeadersCpp();
        curl_slist* getHeaders();
        std::vector<std::string> getVecStrHeaders();
        void appendHeaders(std::string header);

    private:
        curl_slist* _headers;
        std::vector<std::string> _vecStrHeaders;
    };
}
