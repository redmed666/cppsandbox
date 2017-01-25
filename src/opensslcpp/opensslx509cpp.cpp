#include "opensslcpp/opensslx509cpp.hpp"
#include <iostream>

namespace OpensslCpp {
    OpensslX509Cpp::OpensslX509Cpp() {
    }

    OpensslX509Cpp::~OpensslX509Cpp() {
        //if(_vrfy_ctx) {X509_STORE_CTX_free(_vrfy_ctx);}
        //if(_store){X509_STORE_free(_store);}
        if(_cert){X509_free(_cert);}
        if(_publicKey){EVP_PKEY_free(_publicKey);}

    }

    X509* OpensslX509Cpp::getX509() {
        return _cert;
    }

    void OpensslX509Cpp::loadCert(std::string filename) {
        FILE *fp = fopen(filename.c_str(), "r");
        _cert = PEM_read_X509(fp, NULL, NULL, NULL);
        _asn1Serial = X509_get_serialNumber(_cert);
        fclose(fp);
    }

    ASN1_INTEGER* OpensslX509Cpp::getSerialNumber() {
        return _asn1Serial;
    }

    void OpensslX509Cpp::printCertificate() {
        X509_print_ex_fp(stdout, _cert, NULL, NULL);
    }

    EVP_PKEY* OpensslX509Cpp::getPublicKey() {
        _publicKey = X509_get_pubkey(_cert);
        return _publicKey;
    }


}
