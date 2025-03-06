#include <gtest/gtest.h>

#include "src/JsonNode.h"
#include "src/JsonReader.h"

TEST(JsonParserTest, ParseNull)
{
    mjjson::JsonReader reader;

    mjjson::JsonNode node{ reader.parse("null") };
    EXPECT_EQ(std::get<std::nullptr_t>(node.value), nullptr);

    node = reader.parse("   null");
    EXPECT_EQ(std::get<std::nullptr_t>(node.value), nullptr);
}

TEST(JsonParserTest, ParseBool)
{
    mjjson::JsonReader reader;

    mjjson::JsonNode node{ reader.parse("true") };
    EXPECT_EQ(std::get<bool>(node.value), true);

    node = reader.parse("   true");
    EXPECT_EQ(std::get<bool>(node.value), true);

    node = reader.parse("false");
    EXPECT_EQ(std::get<bool>(node.value), false);
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
