#pragma once
#include <openssl/ssl.h>
#include <openssl/crypto.h>
#include <openssl/objects.h>
#include <openssl/evp.h>
#include <openssl/pkcs12.h>
#include <openssl/err.h>
#include <string>
#include <unordered_map>

#include "opensslcpp/opensslcppexception.hpp"
#include "opensslcpp/opensslbiocpp.hpp"
#include "opensslcpp/opensslx509cpp.hpp"
#include "opensslcpp/opensslx509crlcpp.hpp"

namespace OpensslCpp {
    class OpensslCpp {
    public:
        OpensslCpp();
        ~OpensslCpp();
        void newBIO(std::string name, BIO_METHOD* type);
        void newBIOFp(std::string name, FILE* stream, int flags);
        void newBIOFile(std::string name, std::string filename, char* mode);
        void puts(std::string bioName, std::string message);
        void printf(std::string bioName, std::string message);
        void loadCert(std::string certFilename);
        void loadCRL(std::string crlFilename);
        void printSerialNumber(std::string bioName);
        void printCertificate();
        void printCRL();
        void printRevokedCerts();
        void printPublicKey(std::string bioName);
        std::shared_ptr<OpensslX509Cpp> getCert();

    private:
        std::string _caBundle;
        std::string _certFilestr;
        std::string _crlFilestr;
        std::unordered_map<std::string, std::shared_ptr<OpensslBIOCpp>> _bio;
        std::unordered_map<std::string, std::shared_ptr<OpensslBIOCpp>> _bioFp;
        std::shared_ptr<OpensslX509Cpp> _cert;
        std::shared_ptr<OpensslX509CRLCpp> _crl;
    };
}
