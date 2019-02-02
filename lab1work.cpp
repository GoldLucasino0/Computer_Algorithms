#include <iostream>
#include <vector>
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

     for (int end_index = len-1; end_index>0; end_index--)
     {
                for (int i=0; i<=end_index-1;i++)
                        if (a[i] > a[i+1])
                                swap(a[i], a[i+1]);
     }

}


template <class T>
void selectionsort (T a[], int len)
{
    int i, j, min_idx;
    //  One by one move boundary of unsorted subarray
    for (i =0; i< len-1; i++)
        {
        //  Find the minimum element in unosrted array
        min_idx = i;
        for (j = i+1; j <len; j++)
            if (a[j] < a[min_idx])
            min_idx = j;

        //  Swap the found minimum element with the first element
        swap(a[min_idx], a[i]);
        }
};

template <class T>
void insertionsort (T a[], int len)
{
    //  Function to sort an array using insertion sort
    int i, key, j;
    for (i = 1; i < len; i++)
    {
        key = a[i];
        j = i-1;

        //  Move elements of array[0.. i-1], that are greater than key, to one position ahead of their current position
        while (j >= 0 && a[j] > key)
        {
            a[j+1] = a[j];
            j = j-1;
        }
        a[j+1] = key;
    }
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

        cout<< "Testing bubble sort" << endl;
        PrintArray(array,10);
        bubblesort(array,10);
        cout<< endl;
        cout<< "After: " << endl;
        PrintArray(array,10);
        if(IsSorted(array,10))
        {
                cout<< "BubbleSort passed testing";
                cout<< endl;
        }
        else
        {
                cout<< "BubbleSort does not work!" << endl;
        }
        cout<< endl;

        cout<< "Testing selection sort" << endl;
        PrintArray(duplicate,10);
        selectionsort(duplicate,10);
        cout<< endl;
        cout<< "After: " << endl;
        PrintArray(duplicate,10);
        if(IsSorted(array,10))
        {
                cout<< "Selection sort passed testing";
               cout<< endl;
        }
        else
        {
                cout<< "Selection sort does not work!" << endl;
        }
        cout<< endl;

        cout<< "Testing insertion sort" << endl;
        PrintArray(duplicate_2,10);
        insertionsort(duplicate_2,10);
        if(IsSorted(array,10))
        {
                cout<< "Insertion sort passed testing";
                cout<< endl;
        }
        else
        {
                cout<< "Insertion sort does not work!" << endl;
        }
        cout<< endl;
        cout<< "After: " << endl;
        PrintArray(duplicate_2,10);
        cout<< endl;
        return 0;
