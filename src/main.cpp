#include <QApplication>
#include <QPushButton>
#include <QQmlComponent>
#include <QQmlEngine>
#include <QQmlProperty>
#include <QDebug>
#include <QQuickView>

#include "Mainwindow/mainwindow.hpp"
#include "MongoClient/MongoClient.hpp"
#include "util/util.hpp"
// QT android CMake => https://github.com/LaurentGomila/qt-android-cmake


int main(int argc, char** argv) {

    QApplication app(argc, argv);
    /*
    Mainwindow *mainwindow = Mainwindow::instance();
    mainwindow->show();
    */

    QQmlEngine engine;
    QQmlComponent component(&engine, QUrl("qrc:/qml/MyItem.qml"));
    QObject *object = component.create();

    qDebug() << "Property value:" << QQmlProperty::read(object, "someNumber").toInt();

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
    delete object;

    return app.exec();
}
