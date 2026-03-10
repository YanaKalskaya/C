#define _CRT_SECURE_NO_WARNINGS
#include <cstdlib>
#include <string.h>
#include <iostream>

void punkt1BibliotechnieFunkcii(char *str1, char *str2)
{
    std::cout << "\nПункт 1: библиотечные функции из <string.h>\n";
    std::cout << "str1='" << str1 << "', str2='" << str2 << "'\n";
    std::cout << "strlen(str1)=" << strlen(str1) << ", strlen(str2)=" << strlen(str2) << "\n";

    char cpy[100] = {0};
    strcpy(cpy, str1);
    std::cout << "strcpy(cpy, str1) -> cpy='" << cpy << "'\n";

    std::cout << "strcmp(str1, str2)=" << strcmp(str1, str2) << "\n";

    char cat[100] = {0};
    strcpy(cat, str1);
    strcat(cat, str2);
    std::cout << "strcat(str1, str2) -> '" << cat << "'\n";
}

int dlina1(char *s)
{
    int i = 0;
    while (s[i] != '\0')
    {
        ++i;
    }
    return i;
}

int dlina2(char *s)
{
    char *p = s;
    while (*p != '\0')
    {
        ++p;
    }
    return static_cast<int>(p - s);
}

int dlina3(char *s)
{
    if (*s == '\0')
    {
        return 0;
    }
    return 1 + dlina3(s + 1);
}

void kopir(char *dst, char *src)
{
    while ((*dst++ = *src++) != '\0')
    {
    }
}

int sravn(char *a, char *b)
{
    while (*a != '\0' && *a == *b)
    {
        ++a;
        ++b;
    }
    return static_cast<unsigned char>(*a) - static_cast<unsigned char>(*b);
}

void konkat(char *dst, char *src)
{
    while (*dst != '\0')
    {
        ++dst;
    }

    while ((*dst++ = *src++) != '\0')
    {
    }
}

void punkt2SvoiFunkcii(char *str1, char *str2)
{
    std::cout << "\nПункт 2: собственные функции\n";
    std::cout << "Длина str1 (dlina1)=" << dlina1(str1) << ", str2=" << dlina1(str2) << "\n";
    std::cout << "Длина str1 (dlina2)=" << dlina2(str1) << ", str2=" << dlina2(str2) << "\n";
    std::cout << "Длина str1 (dlina3)=" << dlina3(str1) << ", str2=" << dlina3(str2) << "\n";

    char cpy[100] = {0};
    kopir(cpy, str1);
    std::cout << "Результат kopir: str1='" << str1 << "', копия='" << cpy << "'\n";

    std::cout << "Результат sravn(str1, str2): " << sravn(str1, str2) << "\n";

    char cat[100] = {0};
    kopir(cat, str1);
    konkat(cat, str2);
    std::cout << "Результат konkat(str1, str2): '" << cat << "'\n";
}

void punkt3DinamicheskieStroki(char *s1, char *s2)
{
    std::cout << "\nПункт 3: те же функции с динамической памятью (calloc)\n";

    char *str1 = static_cast<char *>(calloc(100, sizeof(char)));
    char *str2 = static_cast<char *>(calloc(100, sizeof(char)));
    if (str1 == nullptr || str2 == nullptr)
    {
        std::cerr << "Ошибка выделения памяти.\n";
        free(str1);
        free(str2);
        std::exit(1);
    }

    kopir(str1, s1);
    kopir(str2, s2);

    std::cout << "Длина str1=" << dlina1(str1) << ", длина str2=" << dlina1(str2) << "\n";

    char *cpy = static_cast<char *>(calloc(100, sizeof(char)));
    char *cat = static_cast<char *>(calloc(100, sizeof(char)));
    if (cpy == nullptr || cat == nullptr)
    {
        std::cerr << "Ошибка выделения памяти.\n";
        free(str1);
        free(str2);
        free(cpy);
        free(cat);
        std::exit(1);
    }

    kopir(cpy, str1);
    std::cout << "Копирование: cpy='" << cpy << "'\n";
    std::cout << "Сравнение: " << sravn(str1, str2) << "\n";

    kopir(cat, str1);
    konkat(cat, str2);
    std::cout << "Сцепление: '" << cat << "'\n";

    free(str1);
    free(str2);
    free(cpy);
    free(cat);
}

void punlt4RaznicaMallocCalloc()
{
    std::cout << "\nПункт 4: malloc и calloc\n";
    std::cout << "malloc(size) выделяет цельный блок памяти, но его байты не инициализируются.\n";
    std::cout << "calloc(n, size) выделяет n*size байт и заполняет память нулями.\n";
    std::cout << "В этой работе calloc удобен, так как строка изначально заполнена '\\0'.\n";

    // Демонстрация разницы
    int n = 10;
    char *pm = (char *)malloc(n * sizeof(char));
    char *pc = (char *)calloc(n, sizeof(char));
    if (!pm || !pc)
    {
        std::cout << "Ошибка выделения памяти для демонстрации.\n";
        free(pm);
        free(pc);
        return;
    }
    std::cout << "\nСодержимое памяти после malloc (могут быть мусорные значения):\n";
    for (int i = 0; i < n; ++i)
    {
        std::cout << (int)(unsigned char)pm[i] << ' ';
    }
    std::cout << "\nСодержимое памяти после calloc (все нули):\n";
    for (int i = 0; i < n; ++i)
    {
        std::cout << (int)(unsigned char)pc[i] << ' ';
    }
    std::cout << "\n";
    free(pm);
    free(pc);
}

void punkt5MassivStrok()
{
    std::cout << "\nПункт 5: массив строк\n";

    const int N = 3;
    char src0[] = "apple";
    char src1[] = "banana";
    char src2[] = "citrus";
    char *src[N] = {src0, src1, src2};

    char *arr[N] = {nullptr, nullptr, nullptr};
    for (int i = 0; i < N; ++i)
    {
        arr[i] = static_cast<char *>(calloc(100, sizeof(char)));
        if (arr[i] == nullptr)
        {
            std::cerr << "Ошибка выделения памяти.\n";
            for (int j = 0; j < N; ++j)
            {
                free(arr[j]);
            }
            std::exit(1);
        }
        kopir(arr[i], src[i]);
    }

    for (int i = 0; i < N; ++i)
    {
        std::cout << "arr[" << i << "]='" << arr[i] << "', длина=" << dlina1(arr[i]) << "\n";
    }
    std::cout << "Сравнение arr[0] и arr[1]: " << sravn(arr[0], arr[1]) << "\n";

    char *all = static_cast<char *>(calloc(300, sizeof(char)));
    if (all == nullptr)
    {
        std::cerr << "Ошибка выделения памяти.\n";
        for (int i = 0; i < N; ++i)
        {
            free(arr[i]);
        }
        std::exit(1);
    }

    for (int i = 0; i < N; ++i)
    {
        if (i > 0)
        {
            char probel[] = " ";
            konkat(all, probel);
        }
        konkat(all, arr[i]);
    }
    std::cout << "Склеивание всех строк массива: '" << all << "'\n";

    free(all);
    for (int i = 0; i < N; ++i)
    {
        free(arr[i]);
    }
}

int main()
{
    system("chcp 1251 > nul");

    char str1[] = "qwerty";
    char str2[] = "1234567890";

    punkt1BibliotechnieFunkcii(str1, str2);
    punkt2SvoiFunkcii(str1, str2);
    punkt3DinamicheskieStroki(str1, str2);
    punlt4RaznicaMallocCalloc();
    punkt5MassivStrok();

    return 0;
}