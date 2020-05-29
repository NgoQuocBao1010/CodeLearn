#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main(){
    freopen("testInput.txt", "r", stdin);
    string s;
    getline(cin, s);
    stack<char> st;

    st.push(s[0]);

    string element = "";
    char character;
    for (int i=1; i < s.length(); i++){
        character = st.top();

        if (st.top() != s[i]){
            element += character;
            int count = 0;
            
            while (!st.empty()){
                st.pop();
                count++;
            }

            element += char (count + '0');
        }
        st.push(s[i]);
    }

    while (!st.empty()){
        character = st.top();
        element += character;
        int count = 0;
            
        while (!st.empty()){
            st.pop();
            count++;
        }

        element += char (count + '0');
    }
    cout << element;
	return 0;
}