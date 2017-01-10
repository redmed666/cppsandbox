#include "gtest/gtest.h"
#include "util/util.cpp"

TEST(TestUtilParseString, classicalString) {
    std::string input = "Un,dos,tres";
    char separator = ',';
    std::vector<std::string> output = {"Un", "dos", "tres"};
    auto result = ::Util::parseString(input, separator);
    for(int i = 0; i < output.size(); ++i){
        ASSERT_EQ((output[i]), (result[i]));
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
