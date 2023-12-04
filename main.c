#include<stdio.h>
#include<stdlib.h>
#include "time.h"

#define SIZE 300000

int stack[SIZE];

void flush() {

    for (int i = 0; i < SIZE; i++)
        stack[i] = rand() % 100000000;

}

void measureTime(void (*sortFunction)()) {

    flush();

    clock_t start = clock(), end;
    sortFunction();
    end = clock();

    printf("Tempo de execução %ld ms!\n", (end - start));

}


void selectionSort() {

    for (int i = 0; i < SIZE; i++) {

        int currentPos = i;

        for (int k = i + 1; k < SIZE; k++) {

            if (stack[currentPos] > stack[k])
                currentPos = k;

        }

        int aux = stack[i];
        stack[i] = stack[currentPos];
        stack[currentPos] = aux;

    }

}

void bubbleSort() {

    for (int i = 0; i < SIZE; i++) {
        for (int k = 0; k < SIZE - 1; k++) {

            if (stack[k] > stack[k + 1]) {
                int aux = stack[k];
                stack[k] = stack[k + 1];
                stack[k + 1] = aux;
            }

        }
    }

}

void insertionSort() {

    for (int i = 1; i < SIZE; i++) {

        int currentPos = i;

        while (stack[currentPos] < stack[currentPos - 1]) {

            int aux = stack[currentPos - 1];
            stack[currentPos - 1] = stack[currentPos];
            stack[currentPos] = aux;

            if (--currentPos == 0)
                break;

        }

    }

}

int main() {

    printf("Testes de velocidade de diferentes algoritmos de ordenação!\n");

    printf("Selection Sort:\n");
    measureTime(selectionSort);

    printf("Bubble Sort:\n");
    measureTime(bubbleSort);

    printf("Insertion Sort: \n");
    measureTime(insertionSort);

    /*
     * 300.000:
     * Selection Sort = 122.027ms
     * Bubble Sort = 453.885ms
     * Insertion Sort = 88.558ms
     *
     * 100.000:
     * Selection Sort = 12.998ms
     * Bubble Sort = 45.671ms
     * Insertion Sort = 8.957ms
     *
     * 50.000:
     * Selection Sort = 3.900ms
     * Bubble Sort = 12.128ms
     * Insertion Sort = 2.401ms
     *
     * 10.000:
     * Selection Sort = 157ms
     * Bubble Sort = 518ms
     * Insertion Sort = 134ms
     * */

}