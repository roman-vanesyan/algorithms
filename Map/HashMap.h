#ifndef __HASH_MAP_GUARD
#define __HASH_MAP_GUARD

#include "Map/Map.h"
#include "RBTree/RbTree.h"

#define __FNV_32_PRIME 16777619
#define __FNV_32_OFFSET 0x811c9dc5

// Both should be power of 2
#define __HASH_MAP_MIN_CAPACITY 32
#define __HASH_MAP_MAX_CAPACITY 1 << 30

static inline int fnv32(void* key)
{
    int size = sizeof(key);
    char *bytes = static_cast<char *>(static_cast<void *>(key));
    int h = __FNV_32_OFFSET;
    for (int i = 0; i < size; i++)
    {
        h = h * __FNV_32_PRIME;
        h = h ^ bytes[i];
    }

    return h;
}

template <typename K, typename  V>
static class Node
{
  public:
    K key;
    V value;

    Node() {}
    Node(K key, V value) : key(key), value(value)
     {}

    int operator==(Node o)
    { return key == o.key; }

    int operator<(Node o)
    { return key < o.key; }

    operator>(Node o)
    { return key > o.key; }
};

template <typename K, typename V>
class HashMap : public Map<K, V>
{
  private:
    int size_;
    int capacity;
    RBTree<Node<K, V>*> buckets;

    int hash(K key)
    {
        int h = fnv32(key);
        return h % capacity_;
    }

    void clean_up()
    {
        for (int i = 0; i < capacity_; i++)
            buckets.clear();
    }

    void grow()
    {
        // code
    }

  public:
    HashMap() : Map(), capacity(__HASH_MAP_MIN_CAPACITY), size_(0)
    { buckets = new Node[capacity]; }

    ~HashMap()
    { clean_up(); }

    inline int size()
    { return size_; }

    inline int is_empty()
    { return size() == 0; }

    bool insert(K key, V value) override
    {
        int h = hash(key);
        int ok = buckets[h].insert(new Node(key, value));
        if (ok)
            size_++;

        return ok;
    }

    V find(K key) override
    {
        int h = hash(key);
        RBTree<Node<K, V>> bucket = buckets[h];
        Node<K, V> n = bucket.find(k);

        return n->value;
    }

    void clear()
    {
        clean_up();
        _size = 0;
    }
};

#endif
