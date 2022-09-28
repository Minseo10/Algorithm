// 스택, 큐, 덱: 17299 오등큰수
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> findNGF(vector<int>& cnt, vector<int>& num, int n){
    stack<int> st;
    vector<int> result(n, -1);

    for (int i = n - 1; i >= 0; i--) {
		while (!st.empty() && cnt[num[i]] >= cnt[st.top()]) { // 스택이 비어있지 않은 경우 오등큰수 찾을 때까지 pop
			st.pop();
		}

		if (!st.empty()) { // 위의 while문을 벗어남 - 오등큰수 찾은 경우
			result[i] = st.top();
		}

		// 현재 참조하는 수가 왼쪽 원소들 중에서 오등큰수가 될 수 있으니 저장
		st.push(num[i]);
	}
    return result;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, input;
    cin >> n;
    vector<int> num(n, 0), cnt(1000001, 0), result; // 선언과 동시에 크기 지정

    for (int i=0; i<n; i++){ // num
        cin >> num[i];
        cnt[num[i]]++;
    }

    result = findNGF(cnt, num, n);
    for (int i=0; i<n; i++){ // num
        cout << result[i] << ' ';
    }
    return 0;
}