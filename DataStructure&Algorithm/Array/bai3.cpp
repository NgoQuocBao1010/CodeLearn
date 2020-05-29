#include <iostream>

using namespace std;

#define MaxSize 1000007


void printArray(int arr[], int size){
    for (int i=0; i<size; i++)
        cout << arr[i] << " ";
}


int main(){
    freopen("testInput.txt", "r", stdin);
    int n;
    cin >> n;

    int* arr = new int[MaxSize];

    for (int i=0; i<n; i++)
        cin >> arr[i];
    
    int k, x;
    cin >>  k >> x;

    for (int i=n; i>=k; i--)
        arr[i + 1] = arr[i];
    arr[k] = x;
    n++;
    printArray(arr, n);

}