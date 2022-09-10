#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int l, c;
string code; //조교가 암호로 사용했을 법한 문자들
bool visited[16] = { 0, }; //각 문자들 선택 여부

//cnt: 여태까지 선택한 문자 개수, current: 현재 선택한 알파벳이 code에서 몇 번째 문자인지
void dfs(int cnt, int current) {
	if (cnt == l) { //l개 다 선택했으면
		int vowel = 0, consonant = 0; //사용한 모음, 자음 개수

		for (int i = 0;i < code.size();i++) { //모음, 자음 개수 count
			if (visited[i]) {
				if (code[i] == 'a' || code[i] == 'e' || code[i] == 'i' || code[i] == 'o' || code[i] == 'u') vowel++;
				else 
					consonant++;
			}
		}

		//암호 출력
		if (vowel >= 1 && consonant >= 2) {
			for (int i = 0;i < code.size();i++) {
				if (visited[i]) cout << code[i];
			}
			cout << '\n';
		}
		return;
	}

	//아직 l개 다 선택하지 않았으면
	for (int i = current;i < code.size();i++) {
		if (!visited[i]) {
			visited[i] = true;
			dfs(cnt + 1, i); 
			visited[i] = false;
		}
	}
	return;
}

int main() {
	cin >> l >> c;

	for (int i = 0;i < c;i++) {
		char tmp;
		cin >> tmp;
		code += tmp;
	}
	
	//암호로 사용했을 법한 문자들 알파벳순으로 정렬(암호도 알파벳순이니까)
	sort(code.begin(), code.end());

	dfs(0, 0);
	return 0;
}