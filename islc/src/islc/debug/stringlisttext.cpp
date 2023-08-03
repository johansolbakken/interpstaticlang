#include "stringlisttext.h"

#include <fstream>
#include <sstream>

#include "islc/core/base.h"

namespace islc
{
    void StringListText::printCsv(const StringList &list, const std::string &filename)
    {
        uint32_t id = 0;
        std::stringstream stream;
        stream << "id:string\n";
        for (const auto &entry : list)
        {
            stream << id << ":" << entry << "\n";
            ++id;
        }
        std::ofstream file(filename);
        file << stream.str();
        file.close();
    }
}