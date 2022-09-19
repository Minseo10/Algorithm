#include<iostream>
#include<stack>
#include<string>
#include<vector>

using namespace std;

/*about stack
->스택에선 st[2]이런게 안된다!
->top()은 삭제x 리턴만
->pop은 리턴x 삭제만*/
/*벡터에서 pop_back()도 리턴x 삭제만*/

stack<char> merge(stack<char> st1, stack<char> st2) { //스택1,2에 있는 문자 합쳐서 새로운 스택에 저장
    /*st2는 아래에서부터, st1은 위에서부터 출력해야함*/
    while(!st1.empty()){
        st2.push(st1.top());
        st1.pop();
    }
    return st2;
}

string find_password(string keyboard) { //각 키보드 입력에 해당하는 비밀번호 찾는 함수
    string password;
    //스택2개 사용-> 스택1의 top이 커서라고 생각
    //즉, 커서 뒤에 있는 문자는 스택2에 저장한다
    stack<char> st1, st2;

    /*if else if문 대신에 switch case 써도 됨*/
    for (int i = 0; i < keyboard.length(); i++) { //커서 뒤쪽의 문자 스택2로 옮겨놓기
        if (keyboard[i] == '<') {
            if(!st1.empty()) { /*not empty 조건 잊지 않기!*/
                st2.push(st1.top());
                st1.pop();
            }
        } else if (keyboard[i] == '>') {//커서 앞쪽의 문자 스택1으로 옮겨놓기
            if(!st2.empty()) {
                st1.push(st2.top());
                st2.pop();
            }
        } else if (keyboard[i] == '-') {//문자 1개 지우기
            if(!st1.empty()) {
                st1.pop();
            }
        } else { //문자 입력
            st1.push(keyboard[i]);
        }
    }

    stack<char> st = merge(st1, st2);

    /*스택은 pop해주면 사이즈가 바뀌니까 st.size()만큼 for문 도는 것보단,
     * empty() 쓰는 편이 낫다*/
    while(!st.empty()) { //비밀번호 password에 저장
        password.push_back(st.top());
        st.pop();
    }
    return password;
}


vector<string> sol(vector<string> K, int L) { //비밀번호들 벡터 리턴
    vector<string> P;
    for (int i = 0; i < K.size(); i++) {
        /* P[i] = find_password(K[i]); -> 여기서 segmentation fault 에러
        P의 사이즈 확정하지 않은 상태에서 배열처럼 인덱스로 접근하면 안된다*/
        P.push_back(find_password(K[i]));
    }

    return P;
}

int main() {
    int L;
    //키보드 입력와 그에 해당하는 비밀번호를 모두 string타입 vector에 저장
    vector<string> K;
    vector<string> P;

    //입력
    cin >> L;
    for (int i = 0; i < L; i++) {
        string temp;
        cin >> temp;
        K.push_back(temp);
    }

    P = sol(K, L);

    //출력
    for (int i = 0; i < L; i++) {
        cout << P[i] << '\n';
    }

    return 0;
}

