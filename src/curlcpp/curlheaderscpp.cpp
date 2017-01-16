#include "curlcpp/curlheaderscpp.hpp"

namespace CurlCpp {
    CurlHeadersCpp::CurlHeadersCpp() {
        this->_headers = nullptr;
    }

    CurlHeadersCpp::~CurlHeadersCpp() {
        if(this->_headers) { curl_slist_free_all(this->_headers); }
    }

    curl_slist* CurlHeadersCpp::getHeaders() {
        return _headers;
    }

    void CurlHeadersCpp::appendHeaders(std::string newHeader) {
        curl_slist_append(this->_headers, newHeader.c_str());
        this->_vecStrHeaders.push_back(newHeader);
    }

    std::vector<std::string> CurlHeadersCpp::getVecStrHeaders() {
        return this->_vecStrHeaders;
    }
}
