#ifndef __HASH_SET_GUARD
#define __HASH_SET_GUARD

#include "Set/Set.h"
#include "Map/HashMap.h"

#define __HASH_SET_PLACEHOLDER ''
#define __HASH_SET_PLACEHOLDER_TYPE char

template<typename E>
class HashSet: public Set<E> {
private:
    HashMap<E, __HASH_SET_PLACEHOLDER_TYPE> *map;

public:
    HashSet()
    { map = new HashMap<E, __HASH_SET_PLACEHOLDER_TYPE>(); }

    bool insert(E value)
    { return map->insert(value, __HASH_SET_PLACEHOLDER); }

    bool remove(E value)
    { return map->remove(value); }

    inline int size()
    { return map->size(); }

    inline void clear()
    { return map->clear(); }

    inline bool is_empty()
    { return map->is_empty(); }
};

#endif
