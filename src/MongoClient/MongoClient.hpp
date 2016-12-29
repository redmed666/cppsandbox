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

class MongoClient {
public:
    MongoClient();
    MongoClient(std::string uri, std::string db, std::string field_name);
    ~MongoClient();

    std::vector<std::string> getCollections();
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
