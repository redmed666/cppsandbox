#include "MongoClient/MongoClient.hpp"

MongoClient::MongoClient(std::string uri, std::string db, std::string field_name){
    _uri = new mongocxx::uri(uri);
    _client = new mongocxx::client(*_uri);
    _db = new mongocxx::database((*_client)[db]);
    _cursor_db = new mongocxx::cursor(_db->list_collections());
    _field_name = field_name;
    for(auto collection : *_cursor_db) {
        auto json_collection = nlohmann::json::parse(bsoncxx::to_json(collection));
        _v_collections.push_back(json_collection["name"]);
    }
}

MongoClient::~MongoClient() {
    delete _uri;
    delete _client;
    delete _db;
    delete _cursor_db;
}

std::vector<std::string> MongoClient::getCollections() {
    return _v_collections;
}

std::vector<std::string> MongoClient::getDocuments(std::string in_collection) {
    std::vector<std::string> v_documents;
    mongocxx::collection* coll = new mongocxx::collection((*_db)[in_collection]);
    mongocxx::cursor cursor = coll->find(document{} << finalize);

    for(auto doc : cursor) {
      auto json_collection = nlohmann::json::parse(bsoncxx::to_json(doc));
      v_documents.push_back(json_collection[_field_name]);
    }

    return v_documents;
}
