#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

//공유기 간 최단거리 dist일때 설치할 수 있는 공유기 수 구하는 함수
int count(int dist, vector<int> &house){
    int cnt=1;//첫번째 집에는 무조건 공유기 설치
    int cur =house[0]; //현재 집의 번호

    for(int i=1;i<house.size();i++){
        if(house[i]-cur>=dist){
            cnt++;
            cur=house[i];
        }
    }
    return cnt;
}

//target: c, left: 설치된 공유기 사이 최단거리 right:공유기사이 최대거리
//이분탐색 이용
int getUpperbound(int left, int right, int target, vector<int>& house){

    while(left<=right){
        int mid=(left+right)/2;
        int installed= count(mid, house); //공유기 최단거리 mid일때 공유기 수

        if(target<= installed){ //installed를 줄이려면 최단거리를 늘려야 함-> left증가
            left=mid+1;
        }
        else{
            right=mid-1;
        }
    }
    return left;
}

int solution(int n, int c, vector<int> &house){
    sort(house.begin(), house.end());
    return getUpperbound(1, house[n-1]-house[0], c, house)-1;
}

int main(){
    int n,c;
    cin >> n>>c;
    vector<int> house(n,0);

    for(int i=0;i<n;i++){
        cin>>house[i];
    }

    cout<<solution(n,c,house)<<'\n';
    return 0;
}