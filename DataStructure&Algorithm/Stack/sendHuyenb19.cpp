#include<iostream>
#include<queue>

using namespace std;

#define MaxSize 1000007

void printQueue(queue<int> q){
    while (!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

void sendHuyen(){
    int numOfMess;
    cin >> numOfMess;

    int* mess = new int[numOfMess];

    for (int i=0; i<numOfMess; i++)
        cin >> mess[i];
    
    queue<int> q;
    bool* visited = new bool[MaxSize];

    for (int i=0; i<MaxSize; i++)
        visited[i] = false;
    
    int k;
    cin >> k;

    for (int i=0; i<numOfMess; i++){
        if (q.size() < k && !visited[mess[i]]){
            q.push(mess[i]);
            visited[mess[i]] = true;
        }
        else {
            if (visited[mess[i]])
                continue;
            else {
                visited[q.front()] = false;
                q.pop();
                q.push(mess[i]);
                visited[mess[i]] = true;
            }
        }
        // printQueue(q);
    }
    printQueue(q);
}

int main(){
    freopen("testInput.txt", "r", stdin);
    sendHuyen();
}