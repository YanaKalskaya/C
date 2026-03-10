#include <iostream>

void printArray(const int a[], int n, const char *label)
{
    std::cout << label;
    for (int i = 0; i < n; ++i)
    {
        std::cout << a[i] << (i + 1 == n ? "" : " ");
    }
    std::cout << "\n";
}

void minMaxSort(int a[], int n)
{
    int left = 0;
    int right = n - 1;
    while (left < right)
    {
        int minIndex = left;
        int maxIndex = left;
        for (int i = left; i <= right; ++i)
        {
            if (a[i] < a[minIndex])
                minIndex = i;
            if (a[i] > a[maxIndex])
                maxIndex = i;
        }
        std::swap(a[left], a[minIndex]);
        if (maxIndex == left)
            maxIndex = minIndex;
        std::swap(a[right], a[maxIndex]);
        ++left;
        --right;
    }
}

void bubbleSort(int a[], int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        bool swapped = false;
        for (int j = 0; j < n - 1 - i; ++j)
        {
            if (a[j] > a[j + 1])
            {
                std::swap(a[j], a[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}

int partitionAsc(int a[], int low, int high)
{
    int pivot = a[high];
    int i = low - 1;
    for (int j = low; j < high; ++j)
    {
        if (a[j] <= pivot)
        {
            ++i;
            std::swap(a[i], a[j]);
        }
    }
    std::swap(a[i + 1], a[high]);
    return i + 1;
}

void quickSortAsc(int a[], int low, int high)
{
    if (low < high)
    {
        int pivotIndex = partitionAsc(a, low, high);
        quickSortAsc(a, low, pivotIndex - 1);
        quickSortAsc(a, pivotIndex + 1, high);
    }
}

void sortEvenAscOddDesc(int a[], int n)
{
    int even[100], odd[100];
    int ne = 0, no = 0;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] % 2 == 0)
            even[ne++] = a[i];
        else
            odd[no++] = a[i];
    }
    if (ne > 0)
        quickSortAsc(even, 0, ne - 1);
    if (no > 0)
        quickSortAsc(odd, 0, no - 1);
    int k = 0;
    for (int i = 0; i < ne; ++i)
        a[k++] = even[i];
    for (int i = no - 1; i >= 0; --i)
        a[k++] = odd[i];
}

void sortRangeAsc(int a[], int n1, int n2)
{
    for (int i = n1; i < n2; ++i)
    {
        for (int j = i + 1; j <= n2; ++j)
        {
            if (a[i] > a[j])
                std::swap(a[i], a[j]);
        }
    }
}

void sortRangeDesc(int a[], int n1, int n2)
{
    for (int i = n1; i < n2; ++i)
    {
        for (int j = i + 1; j <= n2; ++j)
        {
            if (a[i] < a[j])
                std::swap(a[i], a[j]);
        }
    }
}

bool readRange(int n, int &n1, int &n2)
{
    std::cout << "Введите N1 и N2 (0.." << (n - 1) << "): ";
    std::cin >> n1 >> n2;
    if (!std::cin)
        return false;
    if (n1 < 0 || n2 < 0 || n1 >= n || n2 >= n || n1 > n2)
        return false;
    return true;
}

int main()
{
    system("chcp 1251 > nul");
    int source[] = {2, 5, -8, 1, -4, 6, 3, -5, -9, 13, 0, 4, 9};
    const int n = sizeof(source) / sizeof(source[0]);

    std::cout << "Задание 1: Сортировка мини-макс\n";
    {
        int a1[n];
        for (int i = 0; i < n; ++i)
            a1[i] = source[i];
        printArray(a1, n, "Исходный: ");
        minMaxSort(a1, n);
        printArray(a1, n, "Отсортированный: ");
        std::cout << "\n";
    }

    std::cout << "Задание 2: Сортировка пузырьком и быстрая сортировка\n";
    {
        int b[n], q[n];
        for (int i = 0; i < n; ++i)
            b[i] = q[i] = source[i];
        bubbleSort(b, n);
        quickSortAsc(q, 0, n - 1);
        printArray(b, n, "Пузырьком: ");
        printArray(q, n, "Быстрая:   ");
        std::cout << "\n";
    }

    std::cout << "Задание 3: Четные по возрастанию, нечетные по убыванию\n";
    {
        int a3[n];
        for (int i = 0; i < n; ++i)
            a3[i] = source[i];
        printArray(a3, n, "Исходный: ");
        sortEvenAscOddDesc(a3, n);
        printArray(a3, n, "Результат: ");
        std::cout << "\n";
    }

    int n1 = 0, n2 = 0;
    if (!readRange(n, n1, n2))
    {
        std::cout << "Некорректный интервал. Программа завершена.\n";
        return 0;
    }

    std::cout << "Задание 4: Сортировка по возрастанию на интервале [N1..N2]\n";
    {
        int a4[n];
        for (int i = 0; i < n; ++i)
            a4[i] = source[i];
        printArray(a4, n, "Исходный: ");
        sortRangeAsc(a4, n1, n2);
        printArray(a4, n, "Результат: ");
        std::cout << "\n";
    }

    std::cout << "Задание 5: Сортировка по убыванию на интервале [N1..N2]\n";
    {
        int a5[n];
        for (int i = 0; i < n; ++i)
            a5[i] = source[i];
        printArray(a5, n, "Исходный: ");
        sortRangeDesc(a5, n1, n2);
        printArray(a5, n, "Результат: ");
    }

    return 0;
}