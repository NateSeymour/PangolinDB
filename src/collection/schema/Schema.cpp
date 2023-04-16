#include "Schema.h"

std::size_t pdb::Schema::AddMember(Member member)
{
    std::size_t insertion_id = this->id_tally_++;
    member.location = nullptr;
    this->members_[insertion_id] = std::move(member);

    return insertion_id;
}

