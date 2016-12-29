#include <QApplication>
#include <QPushButton>

#include "mainwindow.hpp"
#include "MongoClient/MongoClient.hpp"

#include <bsoncxx/json.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/stdx.hpp>
#include <mongocxx/uri.hpp>
#include <iostream>
#include <json.hpp>
// QT android CMake => https://github.com/LaurentGomila/qt-android-cmake

using bsoncxx::builder::stream::close_array;
using bsoncxx::builder::stream::close_document;
using bsoncxx::builder::stream::document;
using bsoncxx::builder::stream::finalize;
using bsoncxx::builder::stream::open_array;
using bsoncxx::builder::stream::open_document;

int main(int argc, char** argv) {
    /*
    QApplication app(argc, argv);
    Mainwindow *mainwindow = Mainwindow::instance();
    mainwindow->show();
    */

    mongocxx::uri uri("mongodb://raspberrypi.lan:27017");
    mongocxx::client client{uri};

    mongocxx::database db = client["recettesDb"];
    mongocxx::cursor cursor_db = db.list_collections();
    std::vector<std::string> v_collections;
    for(auto collection : cursor_db) {
        auto json_collection = nlohmann::json::parse((bsoncxx::to_json(collection)));
        v_collections.push_back(json_collection["name"]);
    }

    for(auto element : v_collections) {
        std::cout << element << std::endl;
    }

/*
    mongocxx::collection coll = db["apero"];
    mongocxx::cursor cursor = coll.find(document{} << finalize);
    for(auto doc : cursor) {
      std::cout << bsoncxx::to_json(doc) << "\n";
    }
    std::cout << "hey" << std::endl;
    */
    //return app.exec();
}
