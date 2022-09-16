#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){
    string s;
   
    int num=1;
   
    //입력
    while(true){
         int cnt=0;
         stack<char> st;
        cin>>s;
        if(s[0]=='-') break;
        for(int i=0; i<s.length(); i++){
            if(s[i]=='}' && !st.empty() && st.top()=='{') st.pop();
            else st.push(s[i]);
        }
        while(!st.empty()){
            char c = st.top();
            st.pop();
            char d= st.top(); st.pop();
            if(c!=d) cnt+=2;
            else cnt+=1;
           

        }


        //출력
        cout<<num++<<". "<<cnt<<'\n';
    }
    return 0;
}