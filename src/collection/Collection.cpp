#include "Collection.h"
#include "store/MemoryStore.h"

pdb::Collection pdb::Collection::CreateMemoryCollection(const Schema &schema_definition)
{
    pdb::Collection collection;

    collection.schema_ = schema_definition;
    collection.store_ = std::make_unique<MemoryStore>();

    // Initialize store

    return collection;
}