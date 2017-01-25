#ifndef MONGOCLIENT_HPP
#define MONGOCLIENT_HPP

#include <bsoncxx/json.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/stdx.hpp>
#include <mongocxx/uri.hpp>
#include <iostream>
#include <json.hpp>

using bsoncxx::builder::stream::close_array;
using bsoncxx::builder::stream::close_document;
using bsoncxx::builder::stream::document;
using bsoncxx::builder::stream::finalize;
using bsoncxx::builder::stream::open_array;
using bsoncxx::builder::stream::open_document;

/** @brief Mongo client wrapper
  * Mongo client wrapper helps creating a client for a mongo db
  */

class MongoClient {
public:
    /**
      * Constructor
      * @param uri Address of the mongo db
      * @param db DataBase you want to connect to
      * @param field_name Crappy stuff to put but necessary in order to extract the info of the documents
      */
    MongoClient(std::string uri, std::string db, std::string field_name);
    ~MongoClient();

    /**
    * Get all the collections of the selected database
    */
    std::vector<std::string> getCollections();

    /**
    * Get all documents from the collection selected
    */
    std::vector<std::string> getDocuments(std::string in_collection);

private:
    mongocxx::uri* _uri;
    mongocxx::client* _client;
    mongocxx::database* _db;
    mongocxx::cursor* _cursor_db;
    mongocxx::collection _collection;
    std::vector<std::string> _v_collections;
    std::string _field_name;

};

#endif
