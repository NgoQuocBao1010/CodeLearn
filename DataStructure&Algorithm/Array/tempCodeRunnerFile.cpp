#include <iostream>

using namespace std;

#define MaxSize 1000007

void insertElement(int arr[], int size, int element){
    for (int i=0; i<size; i++){
        if (element <= arr[i]){
            for (int j=size; j>=i; j--)
                arr[j+1] = arr[j];
            arr[i] = element;
            return;
        }
    }
}

void printArray(int arr[], int size){
    for (int i=0; i<size; i++)
        cout << arr[i] << " ";
}


int main(){
    freopen("testInput.txt", "r", stdin);
    int n;
    cin >> n;

    int* arr1 = new int[n];

    int element;
    for (int i=0; i<n; i++){
        cin >> element;
        arr1[i] = element;
    }

    int m, size;
    cin >> m;

    size = m + n;
    int* result = new int[size];

    for (int i=0; i<m; i++){
        cin >> element;
        result[i] = element;
    }
    size = m;
    // printArray(result, size);

    for (int i=0; i<n; i++){
        element = arr1[i];
        insertElement(result, size, element);
        size ++;
    }

    printArray(result, size);
}