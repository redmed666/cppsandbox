#include "curlCpp/curlcppexception.hpp"

CurlCpp::CurlCppException::CurlCppException(std::string errorMessage) : _errorMessage(errorMessage) {

}

const char* CurlCpp::CurlCppException::what() const throw () {
    return _errorMessage.c_str();
}
