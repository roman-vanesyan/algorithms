#ifndef __LINKED_LIST_GUARD
#define __LINKED_LIST_GUARD

template <typename E>
class LinkedList
{
  public:
    virtual LinkedList();
    virtual LinkedList(LinkedList<E> other);
    virtual ~LinkedList();
    virtual void append(E value);
    virtual void prepend(E value);
    virtual inline bool is_empty();
};

#endif
