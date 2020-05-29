#include <iostream>

using namespace std;

#define MaxSize 1000007


int main(){
    freopen("testInput.txt", "r", stdin);
    int n;
    cin >> n;

    int* arr = new int[n];

    int element;
    for (int i=0; i<n; i++){
        cin >> element;
        arr[i] = element;
    }

    bool increasing = false;
    bool decreasing = false;
    bool equal = false;

    for (int i=0; i<n-1; i++){
        if (arr[i] > arr[i + 1])
            increasing = true;
        else if (arr[i] < arr[i + 1])
            decreasing = true;
        else
            equal = true;
    }

    if ((increasing && decreasing) || equal )
        cout << "NO";
    else
        cout << "YES";
}