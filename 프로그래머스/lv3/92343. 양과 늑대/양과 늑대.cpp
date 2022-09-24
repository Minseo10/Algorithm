#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
*/

int dfs(int currIdx, int wolf, int sheep, vector<int> nextNode, vector<vector<int>> &adjList, vector<int> info, int answer){
    int isWolf=info[currIdx];
    if(!isWolf) sheep++;
    else wolf++;
    
    answer = max(sheep, answer);
    
    if(sheep <= wolf) return answer;
    
    for(int i=0;i<nextNode.size();i++){
        vector<int> next=nextNode;
        next.erase(next.begin()+i);
        
        for(int j=0;j<adjList[nextNode[i]].size();j++){
            next.push_back(adjList[nextNode[i]][j]);
        }
        
        answer = dfs(nextNode[i], wolf, sheep, next, adjList, info, answer);  
    }
     return answer;
}

int solution(vector<int> info, vector<vector<int>> edges) {
    int answer = 1;
    vector<vector<int>> adjList(info.size());
    
    for(int i=0;i<edges.size();i++){
        adjList[edges[i][0]].push_back(edges[i][1]);
    }
    
    vector<int> nextNode;
    for(int i=0;i<adjList[0].size();i++){
        nextNode.push_back(adjList[0][i]);
    }
    
    answer=dfs(0, 0, 0, nextNode, adjList, info, answer);
    return answer;
}