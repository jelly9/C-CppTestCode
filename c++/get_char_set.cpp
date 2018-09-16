#include <iostream>
#include <unordered_set>
using namespace std;

int main(){
    string str;
    string res;
    cin >> str;
    unordered_set<char> st;
    for(size_t i = 0; i < str.size(); ++i){
        if(st.find(str[i]) == st.end()){
            st.insert(str[i]);
 //           res += str[i];
            cout << str[i];
        }

    }
//    cout << res.c_str();
    return 0;

}
