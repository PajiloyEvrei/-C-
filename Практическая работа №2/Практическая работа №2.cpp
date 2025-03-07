﻿#include <iostream>
#include <chrono>
using namespace std;

void equatingArr(int arr[], int sourceArr[], const int sizeArr) {
    for (int i = 0; i < sizeArr; i++) {
        arr[i] = sourceArr[i];
    }
}

void printArr(int arr[], const int sizeArr) {
    for (int i = 0; i < sizeArr; ++i) {
        cout << arr[i] << " ";
    }
}

void createArr(int arr[], const int sizeArr) {
    srand(time(0));
    int start = -99, end = 99;
    for (int i = 0; i < sizeArr; i++) {
        arr[i] = rand() % (end - start + 1) + start;
    }
}

void findMaxAndMinElArr(int arr[], int unsortArr[], const int sizeArr) {
    int max, min;
    auto timeStart1 = chrono::steady_clock::now();
    max = arr[sizeArr - 1];
    min = arr[0];
    auto timeEnd1 = chrono::steady_clock::now();
    cout << "Поиск в остортированном массиве time:  " << chrono::duration_cast<chrono::nanoseconds>(timeEnd1 - timeStart1).count() << " nanosec\n" << "max: " << max << "  min: " << min << endl;
    auto timeStart2 = chrono::steady_clock::now();
    max = unsortArr[0];
    min = unsortArr[0];
    for (int i = 1; i < sizeArr; ++i) {
        if (unsortArr[i] > max) {
            max = unsortArr[i];
        }
        if (unsortArr[i] < min) {
            min = unsortArr[i];
        }
    }
    auto timeEnd2 = chrono::steady_clock::now();
    cout << "Поиск в неостортированном массиве time:  " << chrono::duration_cast<chrono::nanoseconds>(timeEnd2 - timeStart2).count() << " nanosec\n" << "max: " << max << "  min: " << min << endl;
}

void findAverageValue(int arr[], int unsortArr[], const int sizeArr) {
    int max, min, average, count = 0, flag = 0;
    auto timeStart1 = chrono::steady_clock::now();
    max = arr[sizeArr - 1];
    min = arr[0];
    average = (max + min) / 2;
    for (int i = 0; i < sizeArr && arr[i] <= average; ++i) {
        if (arr[i] == average) {
            //cout << i << " ";
            ++count;
        }
    }
    auto timeEnd1 = chrono::steady_clock::now();
    flag = 0;
    for (int i = 0; i < sizeArr; ++i) {
        if (arr[i] == average) {
            cout << i << " ";
            flag = 1;
        }
        else if (flag == 1) {
            break;
        }
    }
    cout << " : индексы элементов равных среднему, всего их: " << count << endl;
    cout << "Поиск и вывод индексов в остортированном массиве time:  " << chrono::duration_cast<chrono::nanoseconds>(timeEnd1 - timeStart1).count() << " nanosec\n" << "среднее от max и min: " << average << endl;
    auto timeStart2 = chrono::steady_clock::now();
    count = 0;
    average = 0;
    max = -sizeArr;
    min = sizeArr;
    for (int i = 0; i < sizeArr; ++i) {
        if (unsortArr[i] > max) {
            max = unsortArr[i];
        }
        if (unsortArr[i] < min) {
            min = unsortArr[i];
        }
    }
    average = (max + min) / 2;
    for (int i = 0; i < sizeArr; ++i) {
        if (unsortArr[i] == average) {
            ++count;
        }
    }
    auto timeEnd2 = chrono::steady_clock::now();
    for (int i = 0; i < sizeArr; ++i) {
        if (unsortArr[i] == average) {
            cout << i << " ";
        }
    }
    cout << " : индексы элементов равных среднему, всего их: " << count << endl;
    cout << "Поиск и вывод индексов в неостортированном массиве time:  " << chrono::duration_cast<chrono::nanoseconds>(timeEnd2 - timeStart2).count() << " nanosec\n" << "среднее от max и min: " << average << endl;
}

void findLessThenNumb(int arr[], int number, const int sizeArr) {
    int count = 0;
    for (int i = 0; i < sizeArr; ++i) {
        if (arr[i] < number) {
            ++count;
        }
        else {
            break;
        }
    }
    cout << "\nКол-во элементов меньших чем введёное число: " << count;
}

void findMoreThenNumb(int arr[], int number, const int sizeArr) {
    int count = 0;
    for (int i = sizeArr - 1; i >= 0; --i) {
        if (arr[i] > number) {
            ++count;
        }
        else {
            break;
        }
    }
    cout << "\nКол-во элементов больших чем введёное число: " << count;
}

int binarySearch(int arr[], int number, int start, int end) {
    int rem = 0;
    if ((end - start) / 2 == 0) {
        rem = 1;
    }
    int middleNumb = arr[start + (end - start) / 2 + rem];
    if (middleNumb == number) {
        return start + (end - start) / 2 + rem;
    }
    else if (start + 1 == end || start == end + 1) {
        return -1;
    }
    if (middleNumb > number) {
        end = start + (end - start) / 2 + rem;
        binarySearch(arr, number, start, end);
    }
    else {
        start = start + (end - start) / 2 + rem;
        binarySearch(arr, number, start, end);
    }
}

int simpleSearch(int arr[], int number, const int sizeArr) {
    for (int i = 0; i < sizeArr; ++i) {
        if (arr[i] == number) {
            return i;
        }
    }
    return -1;
}

void tryFindEl(int arr[], int number, const int sizeArr) {
    int idEl;
    auto timeStart1 = chrono::steady_clock::now();
    idEl = binarySearch(arr, number, 0, sizeArr - 1);
    auto timeEnd1 = chrono::steady_clock::now();
    if (idEl == -1) {
        cout << "Такого элемента нет в массиве\n";
    }
    else {
        cout << "ID найденного элемента: " << idEl << endl;
    }
    cout << "Бинарный поиск  time:  " << chrono::duration_cast<chrono::nanoseconds>(timeEnd1 - timeStart1).count() << " nanosec\n";
    auto timeStart2 = chrono::steady_clock::now();
    idEl = simpleSearch(arr, number, sizeArr);
    auto timeEnd2 = chrono::steady_clock::now();
    if (idEl == -1) {
        cout << "Такого элемента нет в массиве\n";
    }
    else {
        cout << "ID найденного элемента: " << idEl << endl;
    }
    cout << "Обычный поиск  time:  " << chrono::duration_cast<chrono::nanoseconds>(timeEnd2 - timeStart2).count() << " nanosec\n";
}

void swapElTime(int arr[], int firstElId, int secondElId) {
    auto timeStart = chrono::steady_clock::now();
    swap(arr[firstElId], arr[secondElId]);
    auto timeEnd = chrono::steady_clock::now();
    cout << "swap time:  " << chrono::duration_cast<chrono::nanoseconds>(timeEnd - timeStart).count() << " nanosec\n";
}

template <const int sizeArr>
void bubbleSort(int arr[]) {
    bool isChanged = true;
    int end = sizeArr - 1;
    while (isChanged == true) {
        isChanged = false;
        for (int i = 0; i < end; ++i) {
            if (arr[i + 1] < arr[i]) {
                swap(arr[i + 1], arr[i]);
                isChanged = true;
            }
        }
        --end;
    }
}

template <const int sizeArr>
void shakerSort(int arr[]) {
    bool isChanged = true;
    int start = 0, end = sizeArr - 1;
    while (isChanged == true) {
        isChanged = false;
        for (int i = start; i < end; ++i) {
            if (arr[i + 1] < arr[i]) {
                swap(arr[i + 1], arr[i]);
                isChanged = true;
            }
        }
        --end;
        if (!isChanged) {
            break;
        }
        for (int i = end; i > start; --i) {
            if (arr[i - 1] > arr[i]) {
                swap(arr[i - 1], arr[i]);
                isChanged = true;
            }
        }
        ++start;
    }
}

template <const int sizeArr>
void combSort(int arr[]) {
    float k = 1.247;
    bool isChanged = true;
    int end = sizeArr - 1, gap = sizeArr - 1;
    while (gap != 1) {
        for (int i = 0; i < sizeArr - gap; ++i) {
            if (arr[i] > arr[i + gap]) {
                swap(arr[i + gap], arr[i]);
            }
        }
        gap /= k;
    }

    while (isChanged == true) {
        isChanged = false;
        for (int i = 0; i < end; ++i) {
            if (arr[i + 1] < arr[i]) {
                swap(arr[i + 1], arr[i]);
                isChanged = true;
            }
        }
        --end;
    }
}

template <const int sizeArr>
void insertSort(int arr[]) {
    int end = sizeArr - 1, stepCount;
    for (int start = 1; start <= end; ++start) {
        stepCount = 0;
        while (arr[start - stepCount] < arr[start - 1 - stepCount]) {
            swap(arr[start - stepCount], arr[start - 1 - stepCount]);
            ++stepCount;
        }
    }
}

void quickSortSep(int arr[], int start, int end) {
    int pivot = start;
    ++start;
    if (start >= end) {
        return;
    }
    for (int i = start; i <= end; ++i) {
        if (arr[i] < arr[pivot]) {
            swap(arr[start], arr[i]);
            ++start;
        }
    }
    swap(arr[pivot], arr[start - 1]);
    quickSortSep(arr, pivot, start - 1);
    quickSortSep(arr, start, end);
}

template <const int sizeArr>
void quickSortMain(int arr[]) {
    quickSortSep(arr, 0, sizeArr - 1);
}

void mergeSortStep(int arr[], const int sizeArr, int start, int end, int twoSortArr[]) {
    int parity = (end - start + 1) % 2;
    if (end - start <= 1) {
        if (end - start == 1 && arr[end] < arr[start]) {
            swap(arr[start], arr[end]);
        }
        return;
    }
    mergeSortStep(arr, sizeArr, start, (end + start) / 2 - parity, twoSortArr);
    mergeSortStep(arr, sizeArr, (end + start) / 2 + 1 - parity, end, twoSortArr);
    int ind = 0;
    int lArrIndex = start, rArrIndex = (end + start) / 2 + 1 - parity;
    for (int i = 0; i < (end - start + 1); ++i) {
        if (lArrIndex <= (end + start) / 2 - parity && rArrIndex <= end) {
            if (arr[lArrIndex] > arr[rArrIndex]) {
                twoSortArr[ind] = arr[rArrIndex];
                ++rArrIndex;
                ++ind;
            }
            else {
                twoSortArr[ind] = arr[lArrIndex];
                ++lArrIndex;
                ++ind;
            }
        }
        else if (rArrIndex > end) {
            twoSortArr[ind] = arr[lArrIndex];
            ++lArrIndex;
            ++ind;
        }
        else {
            twoSortArr[ind] = arr[rArrIndex];
            ++rArrIndex;
            ++ind;
        }
    }
    ind = 0;
    for (int i = start; i <= end; ++i) {
        arr[i] = twoSortArr[ind];
        ++ind;
    }
}

template <const int sizeArr>
void mergeSortMain(int arr[]) {
    int twoSortArr[sizeArr];
    mergeSortStep(arr, sizeArr, 0, sizeArr - 1, twoSortArr);
}

void leadTime(void (*func)(int[]), const char name[], int arr[]) {
    auto timeStart = chrono::steady_clock::now();
    func(arr);
    auto timeEnd = chrono::steady_clock::now();
    cout << "Время выполнения " << name << ":  " << chrono::duration_cast<chrono::nanoseconds>(timeEnd - timeStart).count() << " nanosec\n";
}

template <const int sizeArr>
void choiseSort(int arr[],int unsortArr[]) {
    int choise;
    cin >> choise;
    switch (choise) {
    case 0:
        cout << "\n";
        leadTime(bubbleSort<sizeArr>, "bubbleSort", arr);
        cout << "\nПолучившийся массив: ";
        printArr(arr, sizeArr);
        break;
    case 1:
        cout << "\n";
        leadTime(shakerSort<sizeArr>, "shakerSort", arr);
        cout << "\nПолучившийся массив: ";
        printArr(arr, sizeArr);
        break;
    case 2:
        cout << "\n";
        leadTime(combSort<sizeArr>, "combSort", arr);
        cout << "\nПолучившийся массив: ";
        printArr(arr, sizeArr);
        break;
    case 3:
        cout << "\n";
        leadTime(insertSort<sizeArr>, "insertSort", arr);
        cout << "\nПолучившийся массив: ";
        printArr(arr, sizeArr);
        break;
    case 4:
        cout << "\n";
        leadTime(quickSortMain<sizeArr>, "quickSort", arr);
        cout << "\nПолучившийся массив: ";
        printArr(arr, sizeArr);
        break;
    case 5:
        cout << "\n";
        leadTime(mergeSortMain<sizeArr>, "mergeSort", arr);
        cout << "\nПолучившийся массив: ";
        printArr(arr, sizeArr);
        break;
    case 6:
        equatingArr(arr, unsortArr, sizeArr);
        cout << "\n";
        leadTime(bubbleSort<sizeArr>, "bubbleSort", arr);

        equatingArr(arr, unsortArr, sizeArr);
        cout << "\n";
        leadTime(shakerSort<sizeArr>, "shakerSort", arr);

        equatingArr(arr, unsortArr, sizeArr);
        cout << "\n";
        leadTime(combSort<sizeArr>, "combSort", arr);

        equatingArr(arr, unsortArr, sizeArr);
        cout << "\n";
        leadTime(insertSort<sizeArr>, "insertSort", arr);

        equatingArr(arr, unsortArr, sizeArr);
        cout << "\n";
        leadTime(quickSortMain<sizeArr>, "quickSort", arr);

        equatingArr(arr, unsortArr, sizeArr);
        cout << "\n";
        leadTime(mergeSortMain<sizeArr>, "mergeSort", arr);

        cout << "\nПолучившийся массив: ";
        printArr(arr, sizeArr);
        break;
    }
}

int main() {
    setlocale(LC_CTYPE, "Russian");
    constexpr int sizeArr = 100;
    int choise, arr[sizeArr], unsortArr[sizeArr], inputNumber, firstElId, secondElId;
    bool isSorted = false;
    cout << "Исходный массив: ";
    createArr(unsortArr, sizeArr);
    printArr(unsortArr, sizeArr);
    equatingArr(arr, unsortArr, sizeArr);
    do { // Меню выбора
        if (isSorted) {
            cout << "\n\nВыберите нужный пункт:"
                << "\n 0) Переформировать массив"
                << "\n 1) Отсортировать массив"
                << "\n 2) Найти максимальный и минимальный элементы массива"
                << "\n 3) Вывести среднее значение max и min элементов и индексы элементов котрые ему равны"
                << "\n 4) Вывести кол-во элементов МЕНЬШЕ введённого числа"
                << "\n 5) Вывести кол-во элементов БОЛЬШЕ введённого числа"
                << "\n 6) Вывести информацию о том есть ли введённое число в массиве"
                << "\n 7) Поменять местами элементы массива"
                << "\n-1) Закончить выполнение программы\n";
            cin >> choise;
            switch (choise)
            {
            case(0): // Переформировать массвив  
                cout << "Новый исходный массив: ";
                isSorted = false;
                createArr(unsortArr, sizeArr);
                printArr(unsortArr, sizeArr);
                equatingArr(arr, unsortArr, sizeArr);
                break;
            case(1): // Отсортировать массив  
                cout << "\nВыберите выриант сортировки:"
                    << "\n 0) Bubble sort"
                    << "\n 1) Shaker sort"
                    << "\n 2) Comb sort"
                    << "\n 3) Insert sort"
                    << "\n 4) Quick sort"
                    << "\n 5) Merge sort"
                    << "\n 6) Все разом\n";
                equatingArr(arr, unsortArr, sizeArr);
                choiseSort<sizeArr>(arr, unsortArr);
                break;
            case(2): // Найти максимальный и минимальный элементы массива
                findMaxAndMinElArr(arr, unsortArr, sizeArr);
                break;
            case(3): // Вывести среднее значение max и min элементов и индексы элементов котрые ему равны
                findAverageValue(arr, unsortArr, sizeArr);
                break;
            case(4): // Вывести кол-во элементов МЕНЬШЕ введённого числа
                cout << "Введите число: ";
                cin >> inputNumber;
                findLessThenNumb(arr, inputNumber, sizeArr);
                break;
            case(5): // Вывести кол-во элементов БОЛЬШЕ введённого числа
                cout << "Введите число: ";
                cin >> inputNumber;
                findMoreThenNumb(arr, inputNumber, sizeArr);
                break;
            case(6): // Вывести информацию о том есть ли введённое число в массвиве
                cout << "Введите число: ";
                cin >> inputNumber;
                tryFindEl(arr, inputNumber, sizeArr);
                break;
            case(7): // Поменять местами элементы массива
                cout << "Введите через пробел номера двух элементов массива: ";
                cin >> firstElId >> secondElId;
                swapElTime(arr, firstElId, secondElId);
                cout << "Полученный массив: ";
                printArr(arr, sizeArr);
                isSorted = false;
                break;
            }
        }
        else {
            cout << "\n\nВыберите нужный пункт:"
                << "\n 0) Переформировать массив"
                << "\n 1) Отсортировать массив"
                << "\n 7) Поменять местами элементы массива"
                << "\n-1) Закончить выполнение программы\n";
            cin >> choise;
            switch (choise)
            {
            case(0): // Переформировать массвив  
                cout << "Новый исходный массив: ";
                isSorted = false;
                createArr(unsortArr, sizeArr);
                printArr(unsortArr, sizeArr);
                equatingArr(arr, unsortArr, sizeArr);
                break;
            case(1): // Отсортировать массив  
                cout << "\nВыберите выриант сортировки:"
                    << "\n 0) Bubble sort"
                    << "\n 1) Shaker sort"
                    << "\n 2) Comb sort"
                    << "\n 3) Insert sort"
                    << "\n 4) Quick sort"
                    << "\n 5) Merge sort"
                    << "\n 6) Все разом\n";
                isSorted = true;
                choiseSort<sizeArr>(arr, unsortArr);
                break;
            case(7): // Поменять местами элементы массива
                cout << "Введите через пробел номера двух элементов массива: ";
                cin >> firstElId >> secondElId;
                swapElTime(arr, firstElId, secondElId);
                cout << "Полученный массив: ";
                printArr(arr, sizeArr);
                isSorted = false;
                break;
            }
        }
    } while (choise != -1);
    return 0;
}