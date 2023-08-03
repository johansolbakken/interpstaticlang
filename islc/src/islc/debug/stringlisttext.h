#pragma once

#include "islc/ir/stringlist.h"

namespace islc
{
    class StringListText
    {
    public:
        static void printCsv(const StringList& list, const std::string &filepath = "stringlist.csv");
    };
}