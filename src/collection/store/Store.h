#ifndef PDB_STORE_H
#define PDB_STORE_H

#include <cstdlib>
#include <map>
#include <memory>
#include <vector>

namespace pdb
{
    class Slice
    {
    protected:
        std::size_t chunk_size_;
        std::size_t seed_;

    public:
        virtual std::size_t Capacity() const noexcept = 0;

        friend class SliceView;
    };

    class SliceView
    {
    public:
        Slice& slice;

        explicit SliceView(Slice& slice) : slice(slice) {};
    };

    class Store
    {
    protected:
        std::map<std::size_t, std::unique_ptr<Slice>> slices_;

    public:
        virtual SliceView CreateSlice(std::size_t id, std::size_t chunk_size, std::size_t seed) = 0;
        virtual void ReleaseSlice(std::size_t id) = 0;

        virtual SliceView GetSlice(std::size_t id) = 0;
    };
}

#endif //PDB_STORE_H
