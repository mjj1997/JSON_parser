#pragma once

#include <string_view>

namespace mjjson {

class JsonNode;

class JsonReader
{
public:
    JsonReader();

    JsonNode parse(const std::string_view content);

private:
    void skipWhitespace(const std::string_view sv, size_t& pos);
    JsonNode parseValue(const std::string_view sv, size_t& pos);
    JsonNode parseNull(const std::string_view sv, size_t& pos);
    JsonNode parseBool(const std::string_view sv, size_t& pos);
};

} // namespace mjjson
