#ifndef PDB_COLLECTION_H
#define PDB_COLLECTION_H

#include <memory>
#include <map>
#include <string>
#include <cstdlib>
#include <cstdint>
#include "store/Store.h"
#include "schema/Schema.h"

namespace pdb
{
    class Collection
    {
        pdb::Schema schema_;
        std::unique_ptr<Store> store_;

    public:
        static Collection CreateMemoryCollection(const pdb::Schema& schema_definition);
    };
}

#endif //PDB_COLLECTION_H
