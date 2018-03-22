#ifndef __DOUBLY_LINKED_LIST
#define __DOUBLY_LINKED_LIST

#include "LinkedList/LinkedList.h"

template <typename E>
class DoublyLinkedList<E> : public LinkedList<E>
{
  private:
    class Element
    {
      public:
        Element *prev;
        Element *next;
        E value;

        Element()
        {
            prev = nullptr;
            next = nullptr;
        }

        ~Element()
        {
            prev->prev = next;
            next->prev = prev;
        }
    };

    Element *head;

    void insertAfter(Element *dest, Element *element)
    {
        element->prev = dest;
        element->next = dest->next;
        element->next->prev = element;
        element->prev->next = element;
    }

    void insertBefore(Element *dest, Element *element)
    {
        element->next = dest;
        element->prev = dest->prev;
        element->next->prev = element;
        element->prev->next = element;
    }

    void append(Element *element)
    {
        if (head == nullptr)
        {
            element->next = element;
            element->prev = element;
        }
        else
        {
            insertAfter(head, element);
        }

        head = element;
    }

    void prepend(element)
    {
        if (head == nullptr)
        {
            element->next = element;
            element->prev = element;
        }
        else
        {
            insertBefore(head->next, element);
        }

        head->next = element;
    }

  public:
    DoublyLinkedList() override
    {
        head = nullptr;
    }

    ~DoublyLinkedList() override
    {
        delete head;
    }

    void append(E value) override
    {
        Element *element = new Element(value);
        append(element);
    }

    void prepend(E value) override
    {
        Element *element = new Element(value);
        prepend(element);
    }

    E front() override
    {
        return head->value;
    }

    E back() override
    {
        return head->next->value;
    }

    bool is_empty() override
    {
        return head == nullptr;
    }

    void clear() override
    {
        delete head;

        head = nullptr;
    }
};

#endif
