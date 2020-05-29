#include <iostream>

using namespace std;

#define MaxSize 1000007


void printArray(int arr[], int size){
    for (int i=0; i<size; i++)
        cout << arr[i] << " ";
}


bool primeNumber(int n){
    if (n < 2)
        return false;
    
    if (n == 2 || n == 3)
        return true;
    
    if (n % 2 == 0)
        return false;
    
    for (int i=3; i*i <= n; i++){
        if (n % i == 0)
            return false;
    }

    return true;
}

int main(){
    freopen("testInput.txt", "r", stdin);
    int n;
    cin >> n;


    for (int i=0; i<n; i++){
        int element;
        cin >> element;

        if (primeNumber(element))
            cout << element << " ";
    }
}