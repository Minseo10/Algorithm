#include <string>
#include <vector>

using namespace std;
int maxDiff=0;//최대 점수차

//ryan이랑 answer 비교해서 작은점수에 화살수가 더 많으면 true 리턴
bool cmp(vector<int> ryan, vector<int> &answer){ 
    for(int i=10;i>=0;i--){
        if(ryan[i]>answer[i]) return true;
        else if(ryan[i]<answer[i]) return false;
    }
}

//쏜 화살 배열을 토대로 점수 계산해서 answer에 저장
void calcScore(vector<int> ryan, vector<int> apeach, vector<int> &answer){
    int ryanScore = 0; int apeachScore = 0;
    
    for(int i=0;i<=10;i++){
        if(ryan[i]>apeach[i]) ryanScore+=10-i;
        else if(apeach[i]>0) apeachScore+=10-i;
    }
    
    int diff=ryanScore-apeachScore;
    if(diff>0 && diff>=maxDiff){
        if(diff == maxDiff && !cmp(ryan, answer)) return; //갱신x
        //점수answer에 갱신하는 경우(점수차가 더 크거나, 점수차는 같은데 작은점수에 더 많은 경우)
        //최대점수차도 갱신
        answer=ryan;
        maxDiff = diff;
    }
}

//dfs: 라이언이 화살 쏘는 함수 ->결정해서 ryan에 저장
//idx: 현재 몇점에 화살을 쏘는지 arrows: 라이언한테 남은 화살 수
void shoot(int idx, int arrows, vector<int> ryan, vector<int> apeach, vector<int> &answer){
    
    if(idx == 11 || arrows == 0){
        ryan[10]+=arrows; //0점 칸에 남은 화살 몰빵하기
        calcScore(ryan, apeach, answer); //점수 계산!
        ryan[10]-=arrows; //되돌려놓기
        return;
    }
    
    if(apeach[idx]<arrows){ //idx점 칸에 화살 쏘는 경우
        ryan[idx]+=apeach[idx]+1;
        shoot(idx+1, arrows-1-apeach[idx], ryan, apeach, answer);
        ryan[idx]-=apeach[idx]+1; //되돌려놓기
    }
    
    //idx점 칸에 화살 안쏘는 경우
    shoot(idx+1, arrows, ryan, apeach, answer);
}

vector<int> solution(int n, vector<int> info) { //n: 화살수, info: 어피치가 쏜 화살 배열
    vector<int> ryan(11, 0);
    vector<int> answer(11,-1); //최대점수차+작은점수에 화살수 많은 경우 저장
    
    shoot(0, n, ryan, info, answer); //apeach 아니고 info!!!
    
    if(answer[0]==-1){ //라이언이 어피치 이기는게 불가능한 경우
        vector<int> impossible(1, -1); //함수 리턴타입이 벡터니까 얘도 벡터로,,
        return impossible; 
    }
    
    return answer;
}