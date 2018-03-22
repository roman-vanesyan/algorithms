#ifndef __QUICK_SORT_GUARD
#define __QUICK_SORT_GUARD

template <typename E>
static void swap(E *a, E *b)
{
    E tmp = *a;
    *a = *b;
    *b = tmp;
}

template <typename E>
static int partition(E[] array, int low, int high)
{
    E pivot = array[low];
    int i = low;
    int j = high;

    while (1)
    {
        while (array[i] < pivot) i++;
        while (array[j] > pivot) j--;

        if (i >= j)
            return j;

        swap<E>(array[i], array[j]);
    }
}

template <typename E>
static void sort(E[] array, int low, int high)
{
    int pivot = partition(array, low, high);

    sort<E>(array, low, pivot);
    sort<E>(array, pivot - 1, high);
}

template <typename E>
void sort(E[] array, int size)
{
    return sort<E>(array, 0, size - 1);
}

#endif
