#include "iostream"
#include "vector"
using namespace std;

int solution(int n, int m, int r, int c, int d, vector<vector<int>> board){
    int ans=0;
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1}; //0번째:북 1:동 2:남 3:서 로 이동 나타냄
    int nx, nd, ny, check; //check: 4방향 다 확인했는지?

    while(1){
        if(board[r][c]==0){ //현재 위치 청소
            ans++;
            board[r][c]=2;
        }
        for(check=0;check<4;check++){ //2-1,2:왼쪽방향으로 회전하면서 탐색
            d= (d+3)%4; //왼쪽방향으로 갱신
            nx= r+ dx[d]; ny=c+dy[d];
            if(board[nx][ny] == 0){ //빈 공간 있으면 청소
                //board[nx][ny] = 2; 다음 while문에서 2로 바꿔줌
                r=nx; c=ny; break; //왼쪽칸으로 좌표 갱신
            }
        }
        if(check==4){ //2-3
            nd= (d+2)%4; //뒤쪽방향
            nx=r+dx[nd]; ny=c+dy[nd];
            if(board[nx][ny]==1) break; //후진한 칸이 벽일때
            r=nx; c=ny; //후진한 칸으로 좌표 갱신
        }
    }
    return ans;
}

int main(){
    int N, M, r, c, d;
    //vector<vector<int>> board(N, vector<int>(M,0));
    //N,M 입력을 받고 선언을 해야지 미친거아니냐
    //청소 안한 빈칸:0 벽:1 청소함:2

    cin>>N>>M;
    vector<vector<int>> board(N, vector<int>(M,0));
    cin>>r>>c>>d;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >>board[i][j];
        }
    }

    cout <<solution(N,M,r,c,d,board)<<'\n';
    return 0;
}
