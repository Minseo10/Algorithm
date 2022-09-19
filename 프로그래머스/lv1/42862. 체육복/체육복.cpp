#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer=0;
    vector<int> clothes(n+2, 1);
    
    //잃어버린 학생, 여벌 가져온 학생
    //lost,reserve 배열은 인덱스0부터 순서대로 원소 저장(학생번호에 저장x)
    for(auto i: lost){ //i에 lost배열의 원소 쭉 입력 
        clothes[i]--;
    }
    for(auto i: reserve){
        clothes[i]++;
    }
    
    for(int i=1;i<=n;i++){
        if(clothes[i]) continue; //체육복 있으면
        
        //체육복 없으면
        if(clothes[i-1]==2){
            clothes[i-1]--;
            clothes[i]++;
           continue;
        }
        
        if(clothes[i+1]==2){
            clothes[i+1]--;
            clothes[i]++;
        }
    }
    
    for(int i=1;i<=n;i++){
        if(clothes[i]) answer++;
    }
    
    return answer;
}