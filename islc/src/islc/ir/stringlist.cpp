#include "stringlist.h"

namespace islc
{
    uint32_t StringList::add(const std::string &string)
    {
        m_strings.push_back(string);
        return m_strings.size() - 1;
    }

    const std::string &StringList::operator[](uint32_t index) const { return m_strings[index]; }

    uint32_t StringList::size() const { return m_strings.size(); }
}