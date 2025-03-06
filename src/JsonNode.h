#pragma once

#include <variant>

namespace mjjson {

class JsonNode
{
public:
    JsonNode();
    explicit JsonNode(bool b);

    std::variant<std::nullptr_t, bool> value;
};

} // namespace mjjson
