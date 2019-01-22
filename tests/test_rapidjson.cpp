#include "catch/catch.hpp"

#include "rapidjson/document.h"


TEST_CASE("Test Library: RapidJSON", "[RapidJSON]"){

    const char* json = R"({"project": "groupmebot", "botid": 10})";
    rapidjson::Document d;
    d.Parse(json);


    std::string project{d["project"].GetString()};
    REQUIRE ( project == "groupmebot" );
    REQUIRE ( d["botid"].GetInt() == 10 );

}
