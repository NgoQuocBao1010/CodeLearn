#include<iostream>
#include<stack>

using namespace std;

int main(){
    freopen("testInput.txt", "r", stdin);
	int n;
    cin >> n;
    stack<int> s;

    int remainder;
    while (n != 0){
        remainder = n % 2;
        s.push(remainder);

        n = n/2;
    }

    while (!s.empty()){
        cout << s.top();
        s.pop();
    }
	
	return 0;
}