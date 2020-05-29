#include<iostream>
#include<queue>

using namespace std;

int main(){
    queue<int> q;
    int n, k, temp;
    cin >> n;
    for (int i = 0; i < n; i++){
    	cin >> temp;
    	q.push(temp);
	}
	cin >> k;
    for (int i = 0; i < k; i++){
        int x = q.front();
        q.pop();
        q.push(x);
    }
    while (!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
    
    return 0;
}

// Capacity
// size()	Trả về số lượng phần tử của queue
// empty()	Trả về true(1) nếu queue rỗng, ngược lại là false (0)
// Element access:	
// front()	Truy xuất phần tử ở đầu queue (phần tử đầu tiên được thêm vào)
// back()	Truy xuất phần tử ở cuối queue (phần tử cuối cùng được thêm vào)
// Modifier:
// push (const x)	Thêm phần tử có giá trị x vào cuối queue. Kích thước queue tăng thêm 1.
// pop ()	Loại bỏ phần tử ở đầu queue. Kích thước queue giảm đi 1.