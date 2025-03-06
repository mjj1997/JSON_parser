#include "JsonReader.h"
#include "JsonNode.h"

#include <cctype>
#include <stdexcept>
#include <string_view>

namespace mjjson {

JsonReader::JsonReader() {}

// 解析入口
JsonNode JsonReader::parse(const std::string_view content)
{
    size_t pos{ 0 };

    skipWhitespace(content, pos);

    return parseValue(content, pos);
}

// 跳过空白字符
void JsonReader::skipWhitespace(const std::string_view sv, size_t& pos)
{
    while (pos < sv.size() && std::isspace(sv.at(pos)))
        ++pos;
}

// 解析JSON值（分发到具体类型解析）
JsonNode JsonReader::parseValue(const std::string_view sv, size_t& pos)
{
    skipWhitespace(sv, pos);

    switch (sv.at(pos)) {
    // case '{':
    case 't':
    case 'f':
        return parseBool(sv, pos);
    case 'n':
        return parseNull(sv, pos);
    }
}

// 解析null
JsonNode JsonReader::parseNull(const std::string_view sv, size_t& pos)
{
    if (sv.substr(pos, 4) == "null") {
        pos += 4;
        return JsonNode{};
    }

    throw std::runtime_error{ "无效的null值" };
}

// 解析布尔值
JsonNode JsonReader::parseBool(const std::string_view sv, size_t& pos)
{
    if (sv.substr(pos, 4) == "true") {
        pos += 4;
        return JsonNode{ true };
    } else if (sv.substr(pos, 5) == "false") {
        pos += 5;
        return JsonNode{ false };
    }

    throw std::runtime_error{ "无效的布尔值" };
}

} // namespace mjjson
