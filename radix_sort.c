#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h> 

// функция для показа текущего времени 
double wtime() 
{ 
 struct timeval t; 
 gettimeofday(&t, NULL); 
 return (double)t.tv_sec + (double)t.tv_usec * 1E-6; 
}

// генерация случайных чисел
int getrand(int min, int max) 
{ 
 return (double)rand() / (RAND_MAX + 1.0) * (max - min) + min; }


// Получение максимального элемента из массива
int getMax(int arr[], int size) {
    int max = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Функция для выполнения сортировки подсчетом на основе цифры, представленной exp
void countSort(int arr[], int size, int exp) {
    int output[size];
    int count[10] = {0};

    // Подсчет кол-ва вхождение числа exp
    for (int i = 0; i < size; i++) {
        count[(arr[i]/exp) % 10]++;
    }

    // складываем предыдущее число, с текущем
    for (int i = 1; i < 10; i++) {
        count[i] += count[i-1];
    }

    // Построить выходной массив
    for (int i = size - 1; i >= 0; i--) {
        output[count[(arr[i]/exp) % 10] - 1] = arr[i];
        count[(arr[i]/exp) % 10]--;
    }

    // Скопировать выходной массив во входной массив
    for (int i = 0; i < size; i++) {
        arr[i] = output[i];
    }
}

// Функция сортировки
void radixSort(int arr[], int size) {
    int max = getMax(arr, size);

    // Выполнить сортировку подсчета для каждой цифры от наименее до наиболее значимого
    for (int exp = 1; max/exp > 0; exp *= 10) {
        countSort(arr, size, exp);
    }
}

int main() {
    int size;
    printf("Enter size elements: ");
    scanf("%d", &size);
    int arr[size];

    int len = 0;
    double sum_result_time = 0.0;
    double itog = 0.0;

    while(len!=100){
        for(int i = 0; i < size; i++) {
            arr[i] = getrand(0, 100000);
        }
        double one_time = wtime();
        radixSort(arr, size);
        double result_time = wtime() - one_time;
        sum_result_time += result_time;
        len++;
    }
    itog = sum_result_time / 100;

    printf("%d %f\n", size, itog);

    return 0;
}