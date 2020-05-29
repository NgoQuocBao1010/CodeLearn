#include<iostream>
#include<stack>

using namespace std;

int main(){
    // freopen("testInput.txt", "r", stdin);
	string s;
	stack<char> st;
	getline(cin,s);
	for (int i = 0; i < s.length(); i++){
		st.push(s[i]);
	}
	while(!st.empty()){
		cout << st.top();
		st.pop();
	}
	
	return 0;
}

// Stack có các hàm sau (ví dụ cho C++):

// size : trả về kích thước hiện tại của stack. ĐPT O(1).
// empty : true stack nếu rỗng, và ngược lại. ĐPT O(1).
// push : đẩy phần tử vào stack. ĐPT O(1).
// pop : loại bỏ phẩn tử ở đỉnh của stack. ĐPT O(1).
// top : truy cập tới phần tử ở đỉnh stack. ĐPT O(1).