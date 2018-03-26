#ifndef __GUARD_SET
#define __GUARD_SET

template <typename E>
class Set
{
public:
    Set();
    // Set(const Set<E> &other);
    virtual bool is_empty() = 0;
    virtual void clear() = 0;
    virtual bool insert(E element) = 0;
    virtual bool remove(E element) = 0;
};

#endif
