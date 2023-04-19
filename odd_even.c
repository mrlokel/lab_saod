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

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Функция для выполнения четно-нечетной сортировки массива целых чисел
void oddEvenSort(int arr[], int size) {
    int sorted = 0;

    while (!sorted) {
        sorted = 1;

        // Выполнение нечетно-четных сравнений и обменов
        for (int i = 1; i < size-1; i += 2) {
            if (arr[i] > arr[i+1]) {
                swap(&arr[i], &arr[i+1]);
                sorted = 0;
            }
        }
        for (int i = 0; i < size-1; i += 2) {
            if (arr[i] > arr[i+1]) {
                swap(&arr[i], &arr[i+1]);
                sorted = 0;
            }
        }
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
        oddEvenSort(arr, size);
        double result_time = wtime() - one_time;
        sum_result_time += result_time;
        len++;
    }
    itog = sum_result_time / 100;

    printf("%d %f\n", size, itog);

    return 0;
}