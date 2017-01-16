#include <QApplication>
#include <QPushButton>
#include <QQmlComponent>
#include <QQmlEngine>
#include <QQmlProperty>
#include <QDebug>
#include <QQuickView>

#include "mainwindow/mainwindow.hpp"
#include "mongoclient/mongoclient.hpp"
#include "util/util.hpp"
#include "curlcpp/curlcpp.hpp"

// QT android CMake => https://github.com/LaurentGomila/qt-android-cmake


int main(int argc, char** argv) {
    CurlCpp::CurlCpp myCurlObject;
    myCurlObject.appendHeaders("Another: yes");
    myCurlObject.appendHeaders("Host: example.com");
    myCurlObject.setUrl("http://localhost:8000");
    myCurlObject.setopt(CURLOPT_HTTPHEADER, myCurlObject.getHeaders());
    myCurlObject.setopt(CURLOPT_SSL_VERIFYPEER, 1L);
    int responseCode = myCurlObject.performRequest();
    std::cout << "=========== Response body ==============\n" << myCurlObject.getResponseBody() << std::endl;

    return 0;
    /*
    QApplication app(argc, argv);
    Mainwindow *mainwindow = Mainwindow::instance();
    mainwindow->show();
    return app.exec();
    */

    /*
    QApplication app(argc, argv);
    QQmlEngine engine;
    QQmlComponent component(&engine, QUrl("qrc:/qml/MyItem.qml"));
    QObject *object = component.create();

    qDebug() << "Property value:" << QQmlProperty::read(object, "someNumber").toInt();
    delete object;
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
