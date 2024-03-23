#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

// функция для слияния двух подмассивов 
static void mergeSort(int *arr, int leftBorder, int middleIndex, int rightBorder) {

    int firstArrLength = middleIndex - leftBorder + 1; 
    int secondArrLength = rightBorder - middleIndex;     

    int* firstArr = new int[firstArrLength]; 
    int* secondArr = new int[secondArrLength]; 

    // копируем значения во временные массивы
    for (int i = 0; i < firstArrLength; i++)
        firstArr[i] = arr[leftBorder + i];
    for (int j = 0; j < secondArrLength; j++)
        secondArr[j] = arr[middleIndex + 1 + j];

    int i = 0, j = 0, k = leftBorder;

    // сливаем временные массивы в arr
    while (i < firstArrLength && j < secondArrLength) {
        if (firstArr[i] <= secondArr[j]) {
            arr[k] = firstArr[i++];
        }
        else {
            arr[k] = secondArr[j++];
        }
        k++;
    }

    // копируем оставшиеся элементы из первого массива, если такие есть
    while (i < firstArrLength) {
        arr[k++] = firstArr[i++];
    }

    // копируем оставшиеся элементы из первого массива, если такие есть
    while (j < secondArrLength) {
        arr[k++] = secondArr[j++];
    }

    delete[] firstArr; 
    delete[] secondArr; 
}

// функция для сортировки arr слиянием
static void naturalMergeSort(int *arr, int leftBoder, int rightBorder) {
    if (leftBoder < rightBorder) {
        int midleIndex = leftBoder + (rightBorder - leftBoder) / 2;

        // сортируем обе половины
        naturalMergeSort(arr, leftBoder, midleIndex);
        naturalMergeSort(arr, midleIndex + 1, rightBorder);

        // сливаем два отсортированных подмассива
        mergeSort(arr, leftBoder, midleIndex, rightBorder);
    }
}

int main() {

    system("chcp 1251 > Null");

    int size = 25;
    int* arr = new int[size]; 

    for (int i = 0; i < size; i++) {
        cout << "Введите " << i + 1 << " элемент массива: "; cin >> arr[i];
    }

    cout << "\nИсходный массив:" << endl;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    auto start = high_resolution_clock::now();

    naturalMergeSort(arr, 0, size - 1);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);


    cout << "\nОтсортированный массив:" << endl;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "\nВремя сортировки (в микросекундах): " << duration.count() << endl;

    delete[] arr; 

    return 0;
}