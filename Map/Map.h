#ifndef __MAP_GUARD
#define __MAP_GUARD

template <typename K, typename V>
class Map
{
  public:
    Map() {}
    ~Map() {}
    virtual bool insert(K key, V value) = 0;
    virtual bool remove(K key) = 0;
    virtual void clear() = 0;
    virtual int size() = 0;
    virtual bool is_empty() = 0;
    virtual V find(K key) = 0;

    // virtual Iterator find(K key) = 0;
    // virtual Iterator begin() = 0;
    // virtual Iterator end() = 0;
};

#endif
