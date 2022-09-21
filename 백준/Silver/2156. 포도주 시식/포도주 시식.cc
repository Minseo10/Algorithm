#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

int maxWine(int n, vector<int> wine, vector<int> dp){
    dp[1] = wine[1];
    dp[2] = wine[1]+wine[2];
    for(int i=3;i<=n;i++) {
        dp[i] = max(dp[i - 3] + wine[i - 1] + wine[i], dp[i - 2] + wine[i]);
        dp[i] = max(dp[i - 1], dp[i]);
    }
    return dp[n];
}

int main(){
    int n;

    cin>>n;
    vector<int> wine(n+1);
    vector<int> dp(n+1, 0); //동적계획법
    for(int i=1;i<=n;i++){
        cin>>wine[i];
    }

    cout<<maxWine(n,wine,dp)<<'\n';
    return 0;
}