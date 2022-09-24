#include <string>
#include <vector>
#include <iostream>
using namespace std;

//0:기둥 1:보  0:삭제 1: 설치
vector<vector<vector<bool>>> board; 

//(x,y)에 있는 기둥/보가 조건을 만족하는지 아닌지 리턴하는 함수
bool checkVal(int x, int y, int a, int n){//a: 기둥(0)인지 보인지(1)
    if(a == 0){ //기둥
        if(y==0) return true; //바닥 위
        if(board[x][y-1][0] && y>0) return true; //기둥 위
        if(board[x][y][1] || (board[x-1][y][1] && x>0)) return true;
    }
    else{
        if(board[x][y-1][0] && y>0) return true;
        if(board[x+1][y-1][0] && y>0 && x<n) return true;
        if(board[x+1][y][1] && board[x-1][y][1] && x>0 && x<n) return true;
    }
    
    return false;
}

//(x,y)에 있는 구조물 삭제 가능한지 아닌지 리턴하는 함수
bool checkRemove(int x, int y, int n){
    int dx[3]={-1,0,1};  int dy[3]={-1,0,1};
    
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            int nx= x+dx[i]; int ny=y+dy[j];
            
            if(nx<0 || nx>n || ny<0 || ny>n){
                continue;
            }
            for(int k=0;k<2;k++){
                if(board[nx][ny][k] && !checkVal(nx, ny, k, n)){
                    return false;
                }
            }
            
        }
    }
    return true;
    
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    
    board.assign(n+1, vector<vector<bool>>(n+1, vector<bool>(2, false)));
    
    for(int i=0;i<build_frame.size();i++){
        int x = build_frame[i][0];
        int y = build_frame[i][1];
        int a = build_frame[i][2];
        int b = build_frame[i][3];
        
        if(b == 0){//삭제
            board[x][y][a] = false; //일단 없애고
            
            if(!checkRemove(x,y,n)) //삭제할 수 없으면
               board[x][y][a] = true; 
        }
        else if(checkVal(x,y,a,n)){ //b==1(설치) && 설치 가능
            board[x][y][a] = true;
        }    
    }
    
    /*i, j 범위 n까지 포함!!!*/
    for(int i=0;i<=n;i++){ //구조물 answer벡터에 입력
        for(int j=0;j<=n;j++){
            for(int k=0;k<2;k++){
                if(board[i][j][k]) 
                    answer.push_back({i,j,k});
            }
        }
    }
    return answer;
}