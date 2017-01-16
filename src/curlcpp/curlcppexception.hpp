#pragma once
#include <exception>
#include <string>

namespace CurlCpp {
    class CurlCppException : public std::exception {
    public:
        CurlCppException(std::string errorMessage);
        virtual const char* what() const throw();

    private:
        std::string _errorMessage;
    };
}
