// Core dump
#include <iostream>
#include <sys/time.h>
#include <algorithm>
#include <random>
using namespace std;

//Function that generates an array with random values
int *  GenerateRandomArray(int size)
{
        int * random = new int{size};
        for (int i=0;i<size;i++)
                random[i] = (rand() % 1000000);
        return random;
};

//Function that prints elements in an array
void PrintArray (int * array, int size)
{
        for (int i=0; i<size; i++)
                cout<< array[i] << endl;
};

//Function that duplicates an array as well as the elements inside it
int * DuplicateArray (int* orig, int size)
{
        int * temp = new int[size];
        for(int i=0; i<size; i++)
                temp[i] = orig[i];
        return temp;
};

//Function taat cehcks that array is sorted
bool IsSorted(int* array, int size)
{
        if (size == 1 || size == 0)
                return 1;
        if (array[size-1] < array[size-2])
                return 0;;
};


//Function that performs Bubble Sort algorithm
void BubbleSort(int* array, int size)
{
        int i, j;
        for (i=0; i<size-1; i++)
                for (j=0; j<size-i-1; j++)
                        if (array[j] > array[j+1])
                                swap(array[j], array[j+1]);
};


//Function that performs Selection Sort algorithm
void SelectionSort(int* array, int size)
{
        int i, j, min_idx;
        for (i=0; i<size-1; i++)
        {
                min_idx = i;
                for (j=i+1; j<size; j++)
                        if(array[j] < array[min_idx])
                                min_idx = j;
                swap(array[min_idx], array[i]);
        }
};

//Function that performs Insertion Sort algorithm
void InsertionSort (int* array, int size)
{
        int i, key, j;
        for (i=1; i<size; i++)
        {
                key = array[i];
                j = i-1;

                while(j>=0 && array[j] > key)
                {
                        array[j+1] = array[j];
                        j = j-1;
                }
                array[j+1] = key;
        }
};


//Function that checks the run time of each sorting algorithm
void MeasuringSortingFunction(int input_size, int run_number)
{
        struct timeval begin, end;
        double elapsed;
        for (int i=run_number; i<=10; i++)
        {
                gettimeofday(&begin,NULL);
                gettimeofday(&end,NULL);

                elapsed = (end.tv_sec-begin.tv_sec)+((end.tv_usec-begin.tv_usec)/1000000.0);
        }
};


int main()
{
        int * array = GenerateRandomArray(10);
        int * orig = array;
        int * duplicate = DuplicateArray(orig, 10);
        int * duplicate_2 = DuplicateArray(orig,10);

        int size;

        cout<< "1. Testing the three algorithms" << endl;
        cout<< "Testing Bubble Sort with an array of size 10:" << endl;
        cout<< "Bubble Sort array:" << endl;
        PrintArray(array,10);
        BubbleSort(array,10);
        cout<< endl;
        cout << "After:" << endl;
        PrintArray(array,10);
        if (IsSorted (array,10))
        {
                cout<< "BubbleSort passed testing!" << endl;
                cout<< endl;
        }
        else
        {
                cout<< "BubbleSort does not work!" << endl;
                cout<< endl;
        }

        cout<< "Testing Selection Sort with an array of size 10:" << endl;
        cout<< "Selection Sort array:" << endl;
        PrintArray(duplicate,10);
        SelectionSort(duplicate,10);
        cout<< endl;
        cout<< "After:" << endl;
        PrintArray(duplicate,10);
        if (IsSorted (duplicate,10))
        {
                cout<< "Selection Sort passed testing!" << endl;
                cout<< endl;
        }
        else
        {
                cout<< "Selection Sort does not work!" << endl;
                cout<< endl;
        }

        cout<< "Testing Insertion Sort with an array of size 10:" << endl;
        cout<< "Insertion Sort array:" << endl;
        PrintArray(duplicate_2,10);
        InsertionSort(duplicate_2,10);
        cout<< endl;
        cout<< "After:" << endl;
        PrintArray(duplicate_2,10);
        if (IsSorted (duplicate_2,10))
                cout<< "Insertion Sort passed testing!" << endl;
        else
                cout<< "Insertion Sort does not work!" << endl;

        delete [] array;

        return 0;
