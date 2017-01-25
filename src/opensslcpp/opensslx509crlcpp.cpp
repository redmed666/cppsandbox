#include "opensslcpp/opensslx509crlcpp.hpp"
#include <iostream>

namespace OpensslCpp {
    OpensslX509CRLCpp::OpensslX509CRLCpp() {
    }

    OpensslX509CRLCpp::~OpensslX509CRLCpp() {
        if(_crl){X509_CRL_free(_crl);}
    }

    X509_CRL* OpensslX509CRLCpp::getX509CRL() {
        return _crl;
    }

    void OpensslX509CRLCpp::loadCRL(std::string filename) {
        _crlMutex.lock();
        FILE *fp = fopen(filename.c_str(), "r");
        PEM_read_X509_CRL(fp, &_crl, 0, NULL);
        fclose(fp);
        _crlMutex.unlock();

        _issuer = X509_CRL_get_issuer(_crl);
        _version = X509_CRL_get_version(_crl);
        STACK_OF(X509_REVOKED)* revokedTmp = _crl->crl->revoked;

        for (int j = 0; j < sk_X509_REVOKED_num(revokedTmp); j++) {
            X509_REVOKED *entry = sk_X509_REVOKED_value(revokedTmp, j);
            _revokedCerts.push_back(entry);
        }
        
    }

    void OpensslX509CRLCpp::printCRL() {
        X509_CRL_print_fp(stdout, _crl);
    }

    void OpensslX509CRLCpp::printRevokedCerts() {
        BIO* outputbio = BIO_new_fp(stdout,BIO_NOCLOSE);
        for(auto element : _revokedCerts) {
            ASN1_INTEGER* asn1Serial = element->serialNumber;
            i2a_ASN1_INTEGER(outputbio, asn1Serial);
            BIO_printf(outputbio, "\n");
        }
        BIO_free_all(outputbio);
    }
}
