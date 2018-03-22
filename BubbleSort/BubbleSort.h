#ifndef __BUBBLE_SORT_GUARD
#define __BUBBLE_SORT_GUARD

template<typename E>
static void swap(E *a, E *b)
{
    E tmp = *a;
    *a = *b;
    *b = tmp;
}

template<typename E>
void sort(E[] *array, int size)
{
    for (int i = 1; i < size; i++)
    {
        for (int k = 1; k < size; k++)
        {
            if (array[k] > array[k - 1])
                swap(array[k - 1], array[k]);
        }
    }
}

#endif
