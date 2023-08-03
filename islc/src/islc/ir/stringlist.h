#pragma once

#include <vector>
#include <string>



namespace islc
{
    class StringList
    {
    public:
        StringList() = default;
        ~StringList() = default;

        uint32_t add(const std::string &string);
        const std::string &operator[](uint32_t index) const;
        uint32_t size() const;

        const std::vector<std::string> &strings() const { return m_strings; }

        std::vector<std::string>::const_iterator begin() const { return m_strings.begin(); }
        std::vector<std::string>::const_iterator end() const { return m_strings.end(); }

    private:
        std::vector<std::string> m_strings;
    };
}