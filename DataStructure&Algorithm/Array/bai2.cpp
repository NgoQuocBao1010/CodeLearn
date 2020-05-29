#include <iostream>

using namespace std;


int main(){
    freopen("testInput.txt", "r", stdin);
    int n;
    cin >> n;

    int sum = 0;

    for (int i=0; i<n; i++){
        int element;
        cin >> element;
        sum += element;
    }

    cout << sum;
}