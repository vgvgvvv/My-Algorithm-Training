#include "../Utility/Util.h"

void BubbleSort(int* arr, int length) {
    for(int i = 0; i < length; i++) 
    {
        for(int j = i; j < length; j++) 
        {
            if(arr[i] > arr[j]) 
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp; 
            }
        }
    }
}

int main() { 

    int a[] = {1, 3, 2, 5, 4};
    PRINT_ARR(a);

    BubbleSort(a, LENGTHOF(a));

    PRINT_ARR(a);
    return 0;
}