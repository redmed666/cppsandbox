#include <QApplication>
#include <QPushButton>

#include "mainwindow.hpp"
#include "MongoClient/MongoClient.hpp"
#include <sstream>

// QT android CMake => https://github.com/LaurentGomila/qt-android-cmake

int main(int argc, char** argv) {
    /*
    QApplication app(argc, argv);
    Mainwindow *mainwindow = Mainwindow::instance();
    mainwindow->show();
    */

    MongoClient::MongoClient myClient("mongodb://raspberrypi.lan:27017", "recettesDb","Référence;Nom;Origine;Saison;V. papier;Temps;Remarques;Catégories;");
    std::vector<std::string> collections = myClient.getCollections();

    for(auto collection : collections) {
        std::cout << collection << std::endl;
    }
    auto v_documents = myClient.getDocuments("apero");

    for(auto doc : v_documents) {
        std::cout << doc << std::endl;
        std::stringstream iss(doc);

         while(iss.good())
         {
             std::string SingleLine;
             getline(iss,SingleLine,';');
             std::cout << SingleLine << std::endl;
             // Process SingleLine here
         }
    }

    //return app.exec();
}
