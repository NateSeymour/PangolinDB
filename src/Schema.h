#ifndef PDB_SCHEMA_H
#define PDB_SCHEMA_H

#include <string>
#include <map>
#include <cstdlib>

namespace pdb
{
    struct Member
    {
        std::size_t size;
        std::size_t location;
        bool is_numeric;
        bool is_signed;
        bool is_unique;
    };

    struct Schema
    {
        std::map<std::string, Member> members;
    };
}

#endif //PDB_SCHEMA_H
