#ifndef PDB_SCHEMA_H
#define PDB_SCHEMA_H

#include <cstdlib>
#include <cstdint>
#include <map>
#include <string>

namespace pdb
{
    enum MemberFlag : uint64_t
    {
        SIGNED = (1<<0),
        UNIQUE = (1<<1),
    };

    struct Member
    {
        std::string name;
        std::size_t size;
        void* location;
        bool is_numeric;
        MemberFlag flags;
    };

    class Schema
    {
        std::size_t id_tally_ = 0;
        std::map<std::size_t, pdb::Member> members_;

    public:
        std::size_t AddMember(Member member);
    };
}

#endif //PDB_SCHEMA_H
