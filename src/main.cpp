
#include <QtGui/QGuiApplication>
#include <QtGui/QScreen>
#include <QtQml/QQmlEngine>
#include <QtQml/QQmlComponent>
#include <QtQuick/QQuickWindow>
#include <QtCore/QUrl>

//#include <QDebug>

//#include "mainwindow/mainwindow.hpp"
//#include "mongoclient/mongoclient.hpp"
#include "util/util.hpp"
#include "curlcpp/curlcpp.hpp"
#include "opensslcpp/opensslcpp.hpp"
#include <thread>
#include <ctime>

// QT android CMake => https://github.com/LaurentGomila/qt-android-cmake

int main(int argc, char **argv)
{
    /*
    int test = 1;
    std::string testst = "12";
    testst.length();
    std::cout << "testst.len() = " << testst.length() << std::endl;
    */
    /*
    const clock_t begin_time = clock();

    OpensslCpp::OpensslCpp myOpensslObject;
    myOpensslObject.loadCRL(argv[1]);
    myOpensslObject.loadCert(argv[2]);
    myOpensslObject.printCertificate();
    //myOpensslObject.printCertificate();
    //myOpensslObject.printCRLRevokedCerts();
    //std::cout << myOpensslObject.verifyRevokationCert() << std::endl;
    std::cout << float(clock() - begin_time) / CLOCKS_PER_SEC << std::endl;
    */
    /*
    myOpensslObject.loadCert(std::string(argv[1]));
    myOpensslObject.printCertSerialNumber();
    */
    //myOpensslObject.printPublicKey("outputbio");

    //return 0;

    
    std::vector<std::string> urls{"http://localhost:8000/test1","http://localhost:8000/test2", "http://localhost:8000/", "http://localhost:8000/test4"};
    std::vector<CurlCpp::CurlCpp> vecCurlObjects;

    for(int i = 0; i < 1; ++i) {
        urls.push_back(("http://localhost:8000/"+boost::lexical_cast<std::string>(i)));
    }

    for(auto url : urls) {
        CurlCpp::CurlCpp tmpCurlObject;
        tmpCurlObject.appendHeaders("Another: yes");
        std::string hostHeader = "Host: " + url;
        tmpCurlObject.appendHeaders(hostHeader);
        tmpCurlObject.setUrl(url);
        tmpCurlObject.setopt(CURLOPT_HTTPHEADER, (tmpCurlObject.getHeaders()));
        tmpCurlObject.setopt(CURLOPT_SSL_VERIFYPEER, 1L);
        vecCurlObjects.push_back(tmpCurlObject);
    }

    std::vector<std::thread> requestThreaded;
    for(auto& curlObject : vecCurlObjects) {
        requestThreaded.push_back(std::thread(&CurlCpp::CurlCpp::performRequest, curlObject));
    }

    for(auto& myThread : requestThreaded) {
        myThread.join();
    }

    return 0;
    
    /*
    QGuiApplication app(argc, argv);
    foreach (QScreen *screen, QGuiApplication::screens())
        screen->setOrientationUpdateMask(Qt::LandscapeOrientation | Qt::PortraitOrientation | Qt::InvertedLandscapeOrientation | Qt::InvertedPortraitOrientation);
    QQmlEngine engine;
    QQmlComponent component(&engine);
    QQuickWindow::setDefaultAlphaBuffer(true);
    component.loadUrl(QUrl("qrc:///qml/mainwindow.qml"));
    if (component.isReady())
    {
        component.create();
    }
    else
    {
        qWarning() << component.errorString();
    }
    return app.exec();
    */
    /*
    MongoClient::MongoClient myClient("mongodb://raspberrypi.lan:27017", "recettesDb","Référence;Nom;Origine;Saison;V. papier;Temps;Remarques;Catégories;");
    std::vector<std::string> collections = myClient.getCollections();

    std::vector<std::vector<std::vector<std::string>>> v_all_documents_parsed;

    for (auto collection : collections){
        auto v_documents = myClient.getDocuments(collection.c_str());

        std::vector<std::vector<std::string>> v_documents_parsed;

        for(auto doc : v_documents) {
            auto doc_parsed = Util::parseString(doc, ';');
            v_documents_parsed.push_back(doc_parsed);
        }

        v_all_documents_parsed.push_back(v_documents_parsed);
    }
    */
}
