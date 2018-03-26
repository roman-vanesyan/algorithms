#ifndef __RB_TREE_GUARD
#define __RB_TREE_GUARD

#include "Tree/Tree.h"

// Declare `RBTree` so we can reference it inside of `Node` class.
template <typename E>
class RBTree : public Tree<E>;

enum Color
{
    red,
    black
};

template <typename E>
static class Node
{
  public:
    Color color;
    E value;

    Node<E> *parent;
    Node<E> *left;
    Node<E> *right;

    Node()
    {
        parent = nullptr;
        left = nullptr;
        right = nullptr;
        value = nullptr;
    }

    ~Node()
    {
        delete left;
        delete right;
    }

    Node<E> &sibling()
    {
        if (parent == nullptr)
            return nullptr;

        if (parent->left == this)
            return parent->right;

        return parent->left;
    }

    Node<E> &uncle()
    {
        if (parent == nullptr)
            return nullptr;

        return parent->sibling();
    }

    Node<E> &grandparent()
    {
        if (parent->parent == nullptr)
            return nullptr;

        return parent->parent;
    }

    inline bool is_leaf()
    {
        return left == nullptr && right == nullptr;
    }

    inline bool is_empty()
    {
        return value == nullptr;
    }

    // Consider this node to be `x`, follow the next steps:
    //   * Make left child node of `y` to be right child node of `x`;
    //   * Make parent of `x` to be parent of `y`, means if `x` parent is nil
    //     make y to be root of the hole tree; if parent isn't nil,
    //     if `x` was left child, make `y` also left child, or right child otherwise;
    //   * Make `x` to be left child of `y`, now `x` parent is `y`;
    //
    // This is illustration of the above steps:
    //    (x)                   (y)
    //   /   \                 /   \
    // (a)   (y)      ->     (x)   (c)
    //      /   \           /   \
    //     (b)  (c)        (a)  (b)
    void left_rotate(RBTree *tree)
    {
        Node<E> *y = right;
        right = y->left;
        if (right != nullptr)
            right->parent = this;

        // If parent of `x` is nil so it's root of the tree, make `y` the root.
        if (parent == nullptr)
            tree->root = y;
        else
        {
            if (parent->left == this)
                parent->left = y;
            else
                parent->right = y;
        }

        // Finally put the node `x` to the left of `y`
        y->parent = parent;
        y->left = this;
        parent = y;
    }

    // Right rotation is inverse operation to left rotation.
    // But now this node is `y`.
    void right_rotate(RBTree *tree)
    {
        Node<E> *x = left;
        left = x->right;
        if (left != nullptr)
            left->parent = this;

        if (parent == nullptr)
            tree->root = x;
        else
        {
            if (parent->left == this)
                parent->left = x;
            else
                parent->right = x;
        }

        x->parent = parent;
        x->right = this;
        parent = x;
    }
};

template <typename E>
class RBTree : public Tree<E>
{
  private:
    int size;

    Node<E> &find(const Node<E> &node, E value)
    {
        if (node == nullptr || node->value == value)
            return node;

        if (node->value < value)
        {
            return find(node->left, value);
        }

        return find(node->right, value);
    }

    void repair_insertion(Node<E> &node)
    {
        if (node.parent == nullptr)
            node.color = Color::black;
        else if (node.parent->color == Color::black)
            return;
        else if (node.uncle().color == Color::red)
        {
            node.parent->color = Color::black;
            node.uncle()->color = Color::black;
            node.grandparent()->color = Color::red;

            repair_insertion(node.grandparent());
        } else
        {
            // TODO: fixup cannot reassign reference value
            if (node == node.grandparent()->left->right)
            {
                node.parent().left_rotate(this);
                node = node->left;
            } else if (node == node.grandparent()->right->left)
            {
                node.parent->right_rotate(this);
                node = node->right;
            }

            if (node == node.parent()->left)
                node.grandparent().right_rotate(this);
            else
                node.grandparent().left_rotate(this);

            node.parent()->color = Color::black;
            node.grandparent()->color = Color::red;
        }
    }

    bool insert(Node<E> &dest, Node<E> &node)
    {
        if (dest != nullptr)
        {
            // We explicitly set each value of `RBTree` as unique, so it can be used
            // as backbone for other data structures like `set`, etc.
            // This behavior can vary depending on implementation purposes.
            if (dest->value == node->value)
                return false;

            if (dest->value > node->value)
            {
                if (!dest->is_leaf())
                    return insert(dest->left, node);

                dest->left = node;
            }

            if (dest->value < node->value)
            {
                if (!dest->is_leaf())
                    return insert(dest->right, node);

                dest->right = node;
            }
        }

        node->parent = dest;
        node->color = Color::red;

        repair_insertion(node);
    }

  public:
    Node<E> *root;

    Tree()
    {
        root = new Node<E>();
        root->color = NodeColor::black;
    }

    ~Tree()
    {
        delete root;
    }

    Iterator find(E value) override
    {
        Node<E> *node = find(root, value);
        if (node == nullptr)
        {
            // code
        }
    }

    bool insert(E value)
    {
        Node<E> *node = new Node<E>(value);
        return insert(root, node);
    }

    bool remove(E value)
    {
        
    }

    inline bool is_empty()
    {
        return root->is_empty();
    }
};

#endif
