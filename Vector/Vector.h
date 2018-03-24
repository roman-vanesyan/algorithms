#ifndef __VECTOR_GUARD
#define __VECTOR_GUARD

#define __VECTOR_MIN_SIZE 32
#define __VECTOR_GROW_FACTOR 1.5

template<typename E>
class Vector
{
private:
    int size_;
    int capacity;
    E *buf;

    bool try_grow()
    {
        int capacity = capacity * __VECTOR_GROW_FACTOR;
        E *new_buf = new E[capacity];

        for (int i = 0; i < size; i++)
            new_buf[i] = buf[i];

        delete []buf;
        buf = new_buf;
        capacity = new_capacity;

        return true;
    }

    inline bool ensure_index(int index)
    { return index >= size_ || index < 0; }

public:
    class RangeError {
      public:
        RangeError();
    };

    Vector()
    {
        size_ = 0;
        capacity = __VECTOR_MIN_SIZE;
        buf = new E[capacity];
    }

    Vector(int size) : capacity(__VECTOR_MIN_SIZE), size_(size)
    { buf = new E[capacity]; }

    Vector(Vector<E> vec) : capacity(size), size_(0)
    {
        buf = new E[capacity];
        for (int i = 0; i < vec.size(); i++)
            buf[i] = vec[i];
        size_ = vec.size();
        capacity = vec.capacity();
    }

    E& operator[](int index)
    { return get(index); }

    E get(int index)
    {
        if (ensure_index(index))
            throw RangeError();

        return buf[index];
    }

    inline E back()
    { return buf[size_ - 1]; }

    bool push(E element)
    {
        int ok = true;
        buf[size_] = element;
        size_ += 1;

        if (size_ >= capacity)
            ok = try_grow();

        return ok;
    }

    void erase(int index) {
        if (ensure_index(index))
            throw RangeError();

        for (int i = index + 1; i < size_; i++)
            buf[i - 1] = buf[i];
    }

    inline int capacity() const
    { return capacity_; }

    inline int size() const
    { return size_; }
};

#endif
