#pragma once
#include <openssl/x509.h>
#include <openssl/x509v3.h>
#include <openssl/x509_vfy.h>
#include <openssl/pem.h>

#include "opensslcpp/opensslcppexception.hpp"

namespace OpensslCpp {
    class OpensslX509Cpp {
    public:
        OpensslX509Cpp();
        ~OpensslX509Cpp();

        void loadCert(std::string filename);
        void loadCRL(std::string filename);
        X509* getX509();
        ASN1_INTEGER* getSerialNumber();
        EVP_PKEY* getPublicKey();

        void printCertificate();
        void printCRL();
    private:
        X509* _cert = nullptr;
        X509_CRL* _crl = nullptr;
        ASN1_INTEGER* _asn1Serial = nullptr;
        EVP_PKEY* _publicKey = nullptr;
    };
}
