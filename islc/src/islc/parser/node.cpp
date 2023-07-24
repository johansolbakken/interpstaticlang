#include "node.h"

namespace islc {
    std::string Node::toString() const {
        return "Node (" + std::to_string((int)type) + ", " + value + ")";
    }
}