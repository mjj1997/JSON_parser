#include "JsonNode.h"

namespace mjjson {

JsonNode::JsonNode()
    : value(nullptr)
{}

JsonNode::JsonNode(bool b)
    : value(b)
{}

} // namespace mjjson
