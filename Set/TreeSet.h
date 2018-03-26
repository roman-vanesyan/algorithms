#ifndef __TREE_SET_GUARD
#define __TREE_SET_GUARD

#include "Set/Set.h"
#include "RBTree/RBTree.h"

template <typename E>
static class TreeSet: public Set<E>
{
  private:
    RBTree<E> *tree;

  public:
    TreeSet() {
        tree = new RBTree<E>();
    }

    ~TreeSet() {
        delete tree;
    }

    inline int is_empty()
    { return tree->is_empty(); }

    inline bool insert(E element)
    { return tree->insert(element); }

    inline bool remove(E element)
    { return tree->remove(element); }

    inline void clear()
    { return tree->clear(); }
};

#endif
