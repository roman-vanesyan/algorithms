#ifndef __TREE_GUARD
#define __TREE_GUARD

template <typename E>
class Tree
{
  public:
    void insert(E element);
    void remove(E element);
    int size();
    bool is_empty();
};

#endif
