#include <iostream>#include <iostream>
#include <sys/time.h>
using namespace std;

int * GenerateRandomArray(int len)
{       
        int * random = new int[len];
        for(int i=0;i<len;i++)
            random[i] = (rand() % 100000);
        return random;
};


void PrintArray (int* array, int len)
{
        for (int i=0; i<len; i++)
                cout<< array[i] << endl;
};


int * DuplicateArray (int* orig, int len)
{       
        int * temp = new int[len];
        for(int i=0;i<len;i++)
                temp[i] = orig[i];
        return temp;
};


template <class T>
void bubblesort (T a[], int len)
{
        // Base case
        if (len == 1)
                return;
        // One pass of bubble sort. After
        // this pass, the largest element
        // is moved (or bubbled) to end.
        for (int i=0; i<len-1; i++)
                if (a[i] > a[i+1])
                        swap(a[i], a[i+1]);
        // Largest element is fixed,
        // recur for remaining array
        bubblesort(a, len-1);
}


int minIndex(int a[], int i, int j)
{
        if (i == j)
                return i;
        // Find minimum of remaining elements
        int k = minIndex(a, i + 1, j);

        // Return minimum of current and remaining.
        return (a[i] < a[k])? i : k;
}


template <class T>
void selectionsort (T a[], int len, int index = 0)
{
        if (index == len)
                return;

        // calling minimum index function for minimum index 
        int k = minIndex(a, index, len-1);

        // Swapping when index nd minimum index are not same 
        if (k != index)
                swap(a[k], a[index]);

        // Recursively calling selection sort function 
        selectionsort(a, len, index + 1);
};


template <class T>
void insertionsort (T a[], int len)
{
        // Base case 
        if (len <= 1)
                return;

        // Sort first n-1 elements 
        insertionsort( a, len-1 );

        // Insert last element at its correct position 
        // in sorted array. 
        int last = a[len-1];
        int j = len-2;

        /* Move elements of arr[0..i-1], that are 
           greater than key, to one position ahead 
           of their current position */

        while (j >= 0 && a[j] > last)
        {
                a[j+1] = a[j];
                j--;
        }
        a[j+1] = last;
};


template <class T>
bool IsSorted(T a[], int len)
{
        if (len == 1 || len == 0)
                return true;

        for (int i = 1; i < len; i++)
                if (a[i-1] > a[i])
                        return false;

        if (a[len-1] < a[len-2])
                return 0;
};


int main()
{
        int * array = GenerateRandomArray(10);
        int * duplicate = DuplicateArray(array, 10);
        int * duplicate_2 = DuplicateArray(array, 10);
        int len;
        int result1, result2, result3;
        struct timeval begin,end;
        double elapsed;
        int * time = GenerateRandomArray(20);

        cout<< "1. Testing the three algorithms:" << endl;
        cout<< "Testing bubble sort with an array of size 10: ";
        bubblesort(array,10);
        if(IsSorted(array,10))
                cout<< "correct" << endl;
        else
                cout<< "Array is not sorted" << endl;

        cout<< "Testing selection sort with an array of size 10: ";
        selectionsort(duplicate,10);
        if(IsSorted(duplicate,10))
                cout<< "correct" << endl;
        else
                cout<< "Array is not sorted" << endl;

        cout<< "Testing insertion sort with an array of size 10: ";
        insertionsort(duplicate_2,10);
        if(IsSorted(duplicate_2,10))
                cout<< "correct" << endl;
        else
                cout<< "Array is not sorted" << endl;

        cout<< "2. Measuring the three sorting algorithms with 10 randomly generated inputs" << endl;
        cout<< "Measuring running time for array of size 20" << endl;
        for (int i=1;i<=20;i++)
        {
                gettimeofday (&begin,NULL);
                result1 = bubblesort(time,len);
                gettimeofday (&end,NULL);
                elapsed = (end.tv_sec-begin.tv_sec)+ ((end.tv_usec-begin.tv_usec)/1000000.0);
        }
        cout << elapsed;
        cout<< "3. Summary of measurement result" << endl;
        cout<< "Input-size      bubble  selection       insert"<< endl;
        cout<< "20      " << endl;
        return 0;
}
