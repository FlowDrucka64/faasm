#pragma once

#include <string>
#include <vector>

namespace util {
    std::vector<std::string> tokeniseString(const std::string &input, char delimiter);

    bool isAllWhitespace(const std::string &input);

    bool startsWith(const std::string &input, const std::string &subStr);
}