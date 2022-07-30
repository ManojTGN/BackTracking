#include <iostream>
#include <bits/stdc++.h>
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

list<int> getAvailable(int Board[N][N], int x, int y){

    list<int> Available = {1,2,3,4,5,6,7,8,9};
    //Row Numbers
    for(int i = 0; i < N; i++)
        Available.remove(Board[x][i]);
    //Column Numbers
    for(int j = 0; j < N; j++)
        Available.remove(Board[j][y]);
    
    return Available;

}

void sudokuSolver(int Board[N][N], int x, int y){
    list<int> Available = getAvailable(Board,x,y);
    list<int>::iterator it;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            for (it = Available.begin(); it != Available.end(); it++){
                
            }
        }
    }
}

int main(){
    int Board[N][N] = {
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0}
    };


    sudokuSolver(Board,0,0);
    print(Board);
    return 0;
}
