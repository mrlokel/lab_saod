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

// Функция, для замены двух значений
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Функция для быстрой сортировки массива целых чисел.
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[(low+high)/2];
        int left = low;
        int right = high;

        while(left<=right){
            while(arr[left]<pivot){
                left++;
            }

            while(arr[right]>pivot){
                right--;
            }

            if(left<=right){
                swap(&arr[left], &arr[right]);
                left++;
                right--;
            }
        }

        quickSort(arr, low, right);
        quickSort(arr, left, high);
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
        quickSort(arr, 0, size-1);
        double result_time = wtime() - one_time;
        sum_result_time += result_time;
        len++;
    }
    itog = sum_result_time / 100;

    printf("%d %f\n", size, itog);

    return 0;
}