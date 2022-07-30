#include <iostream>
#include <stdlib.h>
#define N 9

using namespace std;

void print(int Board[N][N]){

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout<<Board[i][j]<<" ";
            if(j == 2 || j == 5) cout<<"| ";
        }
        if(i == 2 || i == 5) cout<<endl<<"------x-------x------"<<endl;
        else cout<<endl;
    }

}

bool canPlace(int Board[N][N], int x, int y, int n){
    if(Board[x][y] != 0) return false;

    int gridx = (x/3)*3;int gridy = (y/3)*3;
    for(int i = 0; i < N; i++){
        if(Board[x][i] == n) return false;
        if(Board[i][y] == n) return false;
        
        if(Board[gridx][gridy] == n) return false;
        if((i+1)%3==0){gridx+=1;gridy-=2;}else{gridy+=1;}
    }
    return true;
}

bool isEmptyAvailable(int Board[N][N]){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(Board[i][j] == 0) return true;
        }
    }

    return false;
}

bool sudokuSolver(int Board[N][N]){
    if(!isEmptyAvailable(Board)) {
        print(Board);
        return true;
    }
        
    for (int row = 0; row < N; row++){
        for (int col = 0; col < N; col++){
            if(Board[row][col] != 0) continue;

            for(int i = 1; i <= N; i++){
                if(canPlace(Board,row,col,i)){
                    Board[row][col] = i;
                    if(sudokuSolver(Board)) return true;
                    Board[row][col] = 0;
                }
            }
            
            
        }
        system("CLS");
        print(Board);

    }
        
    return false;
}

int main(){
    int Board[N][N] = {
        {5,0,0,3,0,6,0,0,0},
        {0,0,0,0,5,4,7,3,0},
        {0,9,0,0,0,0,0,0,6},
        {0,5,0,8,0,0,9,6,0},
        {3,0,0,0,4,0,0,0,0},
        {7,8,0,0,0,0,1,0,3},
        {9,0,1,0,7,0,0,0,0},
        {2,0,6,4,9,8,3,0,5},
        {8,0,5,1,0,3,2,9,7}
    };
    
    if(!sudokuSolver(Board)) cout<<"No Possible Solutions Were Found!"<<endl;
    
    return 0;
}
/*
EASY
{5,0,0,3,0,6,0,0,0},
{0,0,0,0,5,4,7,3,0},
{0,9,0,0,0,0,0,0,6},
{0,5,0,8,0,0,9,6,0},
{3,0,0,0,4,0,0,0,0},
{7,8,0,0,0,0,1,0,3},
{9,0,1,0,7,0,0,0,0},
{2,0,6,4,9,8,3,0,5},
{8,0,5,1,0,3,2,9,7}

HARD
{4,0,6,1,0,0,0,0,3},
{0,2,0,0,6,0,0,0,0},
{0,9,0,0,0,0,4,0,0},
{0,0,0,0,0,8,0,0,1},
{0,4,0,0,0,0,0,0,0},
{5,0,7,0,9,0,3,0,0},
{0,0,0,9,0,0,0,7,0},
{0,0,2,0,0,0,0,0,0},
{6,0,3,0,7,0,5,0,0}
*/