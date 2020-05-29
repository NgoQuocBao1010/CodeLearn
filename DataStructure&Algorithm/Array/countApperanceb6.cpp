#include <iostream>

using namespace std;

#define MaxSize 1000007

// ====================== Merge Sort Integer ======================
// ======================    Small to Big    ======================
void merge(int arr[], int low, int mid, int high){
    int size1, size2;

    // Seperate current arr into 2 parts 
    // from the mid position
    size1 = mid - low + 1;
    size2 = high - mid;

    int* part1 = new int[size1];
    int* part2 = new int[size2];

    for (int i=0; i < size1; i++){
        part1[i] = arr[low + i];
    }
    for (int i=0; i < size2; i++){
        part2[i] = arr[mid + 1 + i];
    }


    // Merge and sorted 2 parts 
    int i = 0;
    int j = 0;
    int k = low;
    while (i < size1 && j < size2){
        if (part1[i] <= part2[j]){
            arr[k] = part1[i];
            i++;
        }
        else {
            arr[k] = part2[j];
            j++;
        }
        k++;
    }

    while (i < size1){
        arr[k] = part1[i];
        i++;
        k++;
    }

    while (j < size2){
        arr[k] = part2[j];
        j++;
        k++;
    }
    delete[] part1;
    delete[] part2;
}

void mergeSort(int arr[], int low, int high){
    if (low < high){
        int mid = low + (high - low) / 2;

        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        merge(arr, low, mid, high);
    }
}


int main(){
    freopen("testInput.txt", "r", stdin);
    int n;
    cin >> n;

    int* arr = new int[n];
    int* countApp = new int[MaxSize];

    for (int i=0; i<MaxSize; i++)
        countApp[i] = 0;

    int element;
    for (int i=0; i<n; i++){
        cin >> element;
        countApp[element] += 1;
        arr[i] = element;
    }
    mergeSort(arr, 0, n - 1);

    for (int i=0; i<n; i++){
        element = arr[i];

        if (countApp[element] != -1){
            cout << element << " - " << countApp[element] << "; ";
            countApp[element] = -1;
        }
    }
}