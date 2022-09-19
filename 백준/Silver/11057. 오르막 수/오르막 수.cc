#include<iostream>
#include<algorithm>
#include "vector"
const int MOD= 10007;
using namespace std;

/* 1자리: 0 1 2 3 4 5 6 7 8 9 ->10
 * 2자리: 00 01 ... 09     99 -> 10+...+1 =55
 * 3자리 중 맨앞자리 0: 000...009 011...019   099 -> (10+9+...+1)
 * 3자리 중 맨앞 1: 111...119 122...129 199 -> 9+8+...+1
 * 3자리 중 맨앞 9: 999 ->1
 * 따라서 55+45+36+28+21+15+10+6+3+1 = 220
 * */
int dp[1002][11]={0,}; //dp[i][j]: i자리 수 중 j로 시작하는 오르막수의 개수
int sol(int n){
    int ans=0;

    for(int i=0;i<10;i++){
        dp[1][i]=1;
    }

    for(int i=2;i<=n;i++){
        for(int j=0;j<10;j++){
            int cnt=0;

            for(int k=j;k<10;k++){
                cnt+=dp[i-1][k];
            }
            dp[i][j]=cnt%MOD;

        }
    }

    for(int i=0;i<10;i++){
        ans+=dp[n][i];
    }
    ans %= MOD;
    return ans;
}

int main(){
    int N;
    cin>>N;

    cout << sol(N);
    return 0;
}