#include "opensslcpp/opensslcpp.hpp"
#include <iostream>

namespace OpensslCpp {
    OpensslCpp::OpensslCpp() : _cert(new OpensslX509Cpp), _crl(new OpensslX509CRLCpp){
        ERR_load_crypto_strings();
        OpenSSL_add_all_algorithms();
        //SSL_library_init();
        //OpenSSL_add_all_algorithms();
        //SSL_load_error_strings();
        //ERR_load_crypto_strings();
    }

    OpensslCpp::~OpensslCpp() {
        EVP_cleanup();
        CRYPTO_cleanup_all_ex_data();
        ERR_free_strings();
    }

    void OpensslCpp::newBIO(std::string name, BIO_METHOD* type) {
        _bio[name] = std::make_shared<OpensslBIOCpp>(type);
    }

    void OpensslCpp::newBIOFile(std::string name, std::string filename, char* mode) {
        _bio[name] = std::make_shared<OpensslBIOCpp>(filename, mode);
    }

    void OpensslCpp::newBIOFp(std::string name, FILE* stream, int flags) {
        _bioFp[name] = std::make_shared<OpensslBIOCpp>(stream, flags);
    }

    void OpensslCpp::puts(std::string bioName, std::string message) {
        _bioFp[bioName]->puts(message.c_str());
    }

    void OpensslCpp::printf(std::string bioName, std::string message) {
        _bioFp[bioName]->printf(message.c_str());
    }

    std::shared_ptr<OpensslX509Cpp> OpensslCpp::getCert() {
        return _cert;
    }
    void OpensslCpp::loadCert(std::string certFilename) {
        _certFilestr = certFilename;
        _cert->loadCert(_certFilestr);
    }

    void OpensslCpp::loadCRL(std::string crlFilename) {
        _crlFilestr = crlFilename;
        _crl->loadCRL(crlFilename);
    }

    void OpensslCpp::printSerialNumber(std::string bioName) {
        _bioFp[bioName]->printf("Serial number is ");
        i2a_ASN1_INTEGER(_bioFp[bioName]->getBIO(), _cert->getSerialNumber());
        _bioFp[bioName]->printf("\n");
    }

    void OpensslCpp::printCertificate() {
        _cert->printCertificate();
    }

    void OpensslCpp::printCRL() {
        _bio["printcrl"] = std::make_shared<OpensslBIOCpp>(stdout, BIO_NOCLOSE);
        _crl->printCRL();
    }

    void OpensslCpp::printRevokedCerts() {
        _crl->printRevokedCerts();
    }

    void OpensslCpp::printPublicKey(std::string bioName) {
        _bioFp[bioName]->printf("Public key is ");
        _bioFp[bioName]->printf("%d key \n\n", EVP_PKEY_bits(_cert->getPublicKey()));
        _bioFp[bioName]->writePEMPublicKey(_cert->getPublicKey());
    }

}
