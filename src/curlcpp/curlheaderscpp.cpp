#include "curlcpp/curlheaderscpp.hpp"

namespace CurlCpp {
    CurlHeadersCpp::CurlHeadersCpp() {
        _headers = nullptr;
    }

    CurlHeadersCpp::CurlHeadersCpp(const CurlHeadersCpp& source) {

        // allocate variables
        CurlHeadersCpp::CurlHeadersCpp();

        // copy values
        operator = (source);
    }

    const CurlHeadersCpp& CurlHeadersCpp::operator= (const CurlHeadersCpp &source) {
        _headers = source._headers;
        _vecStrHeaders = source._vecStrHeaders;
        return *this;
    }

    CurlHeadersCpp::~CurlHeadersCpp() {
        if(_headers) { curl_slist_free_all(_headers); }
    }

    curl_slist* CurlHeadersCpp::getHeaders() {
        return _headers;
    }

    void CurlHeadersCpp::appendHeaders(std::string newHeader) {
        _headers = curl_slist_append(_headers, newHeader.c_str());
        _vecStrHeaders.push_back(newHeader);
    }

    std::vector<std::string> CurlHeadersCpp::getVecStrHeaders() {
        return _vecStrHeaders;
    }
}
