#include <iostream>
using namespace std;

int sudoku[10][10];
bool row[10][10]; //x행에 숫자 y가 있으면 true
bool col[10][10]; //x열에 숫자 y가 있으면 true
bool square[10][10]; //x번째 작은 정사각형에 숫자 y가 있으면 true

// row행 col열이 위치한 작은 정사각형 구하기
int get_square(int row, int col){
    return (row/3)*3 + (col/3);
}

//스도쿠 출력
void print(){
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cout << sudoku[i][j] << ' ';
        }
        cout << '\n';
    }
}

// num번째 칸에 숫자 채우는 함수
bool solve(int num){
    // 마지막 칸인 경우 종료
    if(num == 81) {
        print();
        return true;
    }
    
    // 행, 열 구하기
    int x = num/9; int y = num%9;
    
    //빈칸이 아니면 다음 칸으로 넘어가기
    if(sudoku[x][y] != 0){
        return solve(num+1);
    }
    else {//빈칸이면 채울 숫자 정하기
        for(int i=1; i<=9; i++){
            //가로줄, 세로줄, 정사각형에 모두 없는 숫자이면 채운다
            if(!row[x][i] && !col[y][i] && !square[get_square(x, y)][i]){
                row[x][i] = true;
                col[y][i] = true;
                square[get_square(x, y)][i] = true;
                sudoku[x][y] = i;
                
                //다음칸으로 넘어감
                if(solve(num+1)){
                    return true;
                }
                
                // 다시 돌려놓기
                row[x][i] = false;
                col[y][i] = false;
                square[get_square(x, y)][i] = false;
                sudoku[x][y] = 0;
            }
        }
    }
    
    return false;
}

int main(void){
    
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cin >> sudoku[i][j];
            
            // 빈칸이 아닌 경우 
            if(sudoku[i][j] != 0){
                row[i][sudoku[i][j]] = true;
                col[j][sudoku[i][j]] = true;
                square[get_square(i, j)][sudoku[i][j]] = true;
            }
        }
    }
    
    // 0번 칸부터 시작
    solve(0);
    return 0;
}
