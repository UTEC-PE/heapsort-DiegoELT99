#include <iostream>
#include <random>
#include <assert.h>
#include <string.h>

using namespace std;

#define MIN 100
#define MAX 500

mt19937 rng;

int generateRandomInt(int min, int max);
void printArray(int *array, size_t size);
void swap(int &A, int &B);
void heapifyUp(int *array, size_t size, int StartingPoint);
void heapsort(int* array, size_t size);
bool validate(int* array, size_t size);

int main(int argc, char *argv[]) {
    for(int i = 0; i < 100; i++)
    {
        rng.seed(random_device()());
        cout << "===========================================================" << endl;
        cout << "\tHeapsort Practice" << endl;
        cout << "===========================================================" << endl << endl;

        const int numberOfElements = generateRandomInt(MIN, MAX);
        int *numbers = new int[numberOfElements];
        for (int i = 0; i < numberOfElements; i++) {
            numbers[i] = generateRandomInt(0, 100);
        }

        cout << "Array Original" << endl;
        cout << "--------------" << endl;
        printArray(numbers, numberOfElements);
        heapsort(numbers, numberOfElements);
        cout << "Array Sorteado" << endl;
        cout << "--------------" << endl;
        printArray(numbers, numberOfElements);
        assert(validate(numbers, numberOfElements) && "The sort is not ordering all the elements");
    }

    return EXIT_SUCCESS;
}

int generateRandomInt(int min, int max) {
    uniform_int_distribution<mt19937::result_type> distribution(min, max); 
    return distribution(rng);
}

void printArray(int *array, size_t size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

void swap(int &A, int &B){
    int temp = A;
    A = B;
    B = temp;
}

void heapifyUp(int *array, size_t size, int StartingPoint){
    int biggestNumber = StartingPoint;
    int leftChild = 2 * StartingPoint + 1;
    int rightChild = 2 * StartingPoint + 2;

    if (leftChild < size && array[leftChild] > array[biggestNumber])
        biggestNumber = leftChild;

    if (rightChild < size && array[rightChild] > array[biggestNumber])
        biggestNumber = rightChild;

    if (biggestNumber != StartingPoint)
    {
        swap(array[StartingPoint], array[biggestNumber]);
        heapifyUp(array, size, biggestNumber);
    }
}

void heapsort(int* array, size_t size)
{
    for(int i = size / 2; i >= 0; i--)
    {
        heapifyUp(array, size, i);
    }

    for(int j = size - 1; j >= 0; j--)
    {
        swap(array[0], array[j]);
        heapifyUp(array, j, 0);
    }
}

bool validate(int* array, size_t size) {
    for (int i = 0; i < size - 1; i++) {
        if (array[i] > array[i + 1]) {
            return false;
        }
    }
    return true;
}