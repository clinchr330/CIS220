// Rafael Clinch
// Chpt3 PA

#include <stdio.h>

void BubbleSort(int arr[], int n) { // Function for the bubble sort
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) { 
                int temp = arr[j]; // Swaps arr[j] and arr[j+1]
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int arr[] = {93, 52, 72, 42, 3, 63, 100, 19, 61, 44, 21, 98, 6, 41, 78, 5, 51, 60, 67, 11}; // Defines the array that is going to be sorted
    int n = sizeof(arr)/sizeof(arr[0]);
    BubbleSort(arr, n); // Calls the bubble sort function
    printf("The sorted array is: "); // Prints sorted array
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
