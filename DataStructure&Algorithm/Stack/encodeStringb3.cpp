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
        character = s[i];

        if (st.top() != character || i == s.length() - 1){     
            if (i == s.length() - 1)
                st.push(character);
                
            element += st.top();

            int count = 0;
            
            while (!st.empty()){
                st.pop();
                count++;
            }
            // cout << char (count + '0') << endl;
            element += char (count + '0');
        }
        st.push(character);
    }
    cout << element;
	return 0;
}