#pragma once
#include <curl/curl.h>
#include "curlcpp/curlcppexception.hpp"
#include <string>
#include <vector>

namespace CurlCpp {
    class CurlHeadersCpp {
    public:
        CurlHeadersCpp();
        CurlHeadersCpp(const CurlHeadersCpp& source);
        ~CurlHeadersCpp();
        curl_slist* getHeaders();
        std::vector<std::string> getVecStrHeaders();
        void appendHeaders(std::string header);
        const CurlHeadersCpp& operator= (const CurlHeadersCpp &source);

    private:
        curl_slist* _headers;
        std::vector<std::string> _vecStrHeaders;
    };
}
