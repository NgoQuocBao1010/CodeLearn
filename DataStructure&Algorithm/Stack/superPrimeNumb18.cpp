#include<iostream>
#include<queue>

using namespace std;

bool isPrimeNumber(int n){
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

void printQueue(queue<int> q){
    while (!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
}

void findSuperPrime(int n){
    queue<int> q;
    
    for (int i=2; i<10; i++){
        if (i > n)
            break;
        if (isPrimeNumber(i))
            q.push(i);
    }
        
    
    if (n < 10){
        printQueue(q);
        return;
    }

    while (!q.empty()){
        int superPrime = q.front();
        q.pop();

        for (int i=0; i<=9; i++){
            int newCheckNum = superPrime * 10 + i;

            if (newCheckNum > n)
                continue;

            if (isPrimeNumber(newCheckNum))
                q.push(newCheckNum);
        }

        cout << superPrime << " ";
    }
    
}

int main(){
    int n;
    cin >> n;
    findSuperPrime(n);
}