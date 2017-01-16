#include "gtest/gtest.h"
#include "util/util.cpp"
#include "curlcpp/curlcpp.cpp"
#include "curlcpp/curlcppexception.cpp"
#include "curlcpp/curlheaderscpp.cpp"
#include "curlcpp/curlhandlercpp.cpp"

TEST(TestUtilParseString, classicalString) {
    std::string input = "Un,dos,tres";
    char separator = ',';
    std::vector<std::string> output = {"Un", "dos", "tres"};
    auto result = ::Util::parseString(input, separator);
    for(int i = 0; i < output.size(); ++i){
        ASSERT_EQ((output[i]), (result[i]));
    }
}

TEST(TestCurlCpp, PerformRequestOK) {
    CurlCpp::CurlCpp curlObject;
    curlObject.setUrl("http://localhost:8000");
    int responseCodeExpected = 200;
    ASSERT_EQ(responseCodeExpected, curlObject.performRequest());
}

TEST(TestCurlCpp, PerformRequestNOK) {
    CurlCpp::CurlCpp curlObject;
    curlObject.setUrl("http://localhost:8001");
    int responseCodeExpected = 0;
    ASSERT_EQ(responseCodeExpected, curlObject.performRequest());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
