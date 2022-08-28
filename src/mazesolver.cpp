#include <iostream>
#include <stdlib.h>
#include <bits/stdc++.h>
#include <windows.h>

#define N 10

using namespace std;

int BESTMAZE[N][N];

bool isFinishFound(int* playerPos,int* finishPos){
    return (playerPos[0] == finishPos[0]) && (playerPos[1] == finishPos[1]);
}

void printMaze(int MAZE[N][N]){

    system("CLS");
    for(int i=0;i<N+2;i++) cout<<"# ";
    cout<<endl;

    for(int x = 0; x < N; x++){
        cout<<"# ";
        for(int y = 0; y < N; y++){
            if(MAZE[x][y] == 0) cout<<"  ";
            else if(MAZE[x][y] == 1) cout<<"# ";
            else if(MAZE[x][y] == 2) cout<<". ";
            else if(MAZE[x][y] == 6) cout<<"@ ";
            else if(MAZE[x][y] == 9) cout<<"X ";
            else cout<<"  ";
        }cout<<"# "<<endl;
    }

    for(int i=0;i<N+2;i++) cout<<"# ";
    cout<<endl;
}

void getPlayer(int MAZE[N][N],int* PlayerPos){

    for(int x = 0; x < N; x++){
        for(int y = 0; y < N; y++){

            if(MAZE[x][y] == 6){
                PlayerPos[0] = x;PlayerPos[1] = y;
                return;
            }

        }
    }

}

void getFinisher(int MAZE[N][N],int* FinsherPos){
    for(int x = 0; x < N; x++){
        for(int y = 0; y < N; y++){

            if(MAZE[x][y] == 9){
                FinsherPos[0] = x;FinsherPos[1] = y;
                return;
            }

        }
    }
}

void moveTo(int* playerPos,char direction){
    if(direction == 'U'){ playerPos[0] -= 1; }
    else if(direction == 'D'){ playerPos[0] += 1;}
    else if(direction == 'L'){ playerPos[1] -= 1;}
    else { playerPos[1] +=1;}
}

void getPlayerMoves(int MAZE[N][N], int* playerCurrentPos, bool* Direction){
    //CHECKING UP
    if( 
        playerCurrentPos[0]-1 >= 0 && 
        MAZE[playerCurrentPos[0]-1][playerCurrentPos[1]] != 1 && 
        MAZE[playerCurrentPos[0]-1][playerCurrentPos[1]] != 2
    ) Direction[0] = true;

    //CHECKING DOWN
    if( 
        playerCurrentPos[0]+1 < N && 
        MAZE[playerCurrentPos[0]+1][playerCurrentPos[1]] != 1 && 
        MAZE[playerCurrentPos[0]+1][playerCurrentPos[1]] != 2
    ) Direction[1] = true;

    //CHECKING LEFT
    if( 
        playerCurrentPos[1]-1 >= 0 && 
        MAZE[playerCurrentPos[0]][playerCurrentPos[1]-1] != 1 && 
        MAZE[playerCurrentPos[0]][playerCurrentPos[1]-1] != 2
    ) Direction[2] = true;

    //CHECKING RIGHT
    if( 
        playerCurrentPos[1]+1 < N && 
        MAZE[playerCurrentPos[0]][playerCurrentPos[1]+1] != 1 && 
        MAZE[playerCurrentPos[0]][playerCurrentPos[1]+1] != 2
    ) Direction[3] = true;
}

void mazeSolver(int MAZE[N][N],int FinishPos[2],int currentDepth,int* minDepth,bool visualize=false){

    int playerPos[2] = {-1,-1};
    int playerTmpPos[2] = {-1,-1};

    getPlayer(MAZE,playerPos);
    if(isFinishFound(playerPos,FinishPos) && currentDepth < *minDepth){
        *minDepth = currentDepth;
        for(int x = 0; x < N; x++)
            for(int y = 0; y < N; y++)
                BESTMAZE[x][y] = MAZE[x][y];
        return;
    }

    bool direction[4] = {false,false,false,false};
    getPlayerMoves(MAZE,playerPos,direction);

    for(int i = 0; i < 4; i++){

        if(!direction[i]) continue;
        playerTmpPos[0] = playerPos[0];playerTmpPos[1] = playerPos[1];
        MAZE[playerPos[0]][playerPos[1]] = 2;

        if(direction[i] && i == 0) moveTo(playerPos,'U');
        else if(direction[i] && i == 1) moveTo(playerPos,'D');
        else if(direction[i] && i == 2) moveTo(playerPos,'L');
        else if(direction[i] && i == 3) moveTo(playerPos,'R');


        MAZE[playerPos[0]][playerPos[1]] = 6;
        
        if(visualize){printMaze(MAZE);Sleep(0);}
        mazeSolver(MAZE,FinishPos,currentDepth+1,minDepth,visualize);

        MAZE[playerTmpPos[0]][playerTmpPos[1]] = 6;
        if(playerPos[0]==FinishPos[0]&&playerPos[1]==FinishPos[1]){MAZE[playerPos[0]][playerPos[1]] = 9;}
        else{MAZE[playerPos[0]][playerPos[1]] = 0;}
        playerPos[0] = playerTmpPos[0]; playerPos[1] = playerTmpPos[1];

    }

}

int main(){
    int MAZE[N][N]={
        {6,0,0,0,1,0,0,0,0,1},
        {1,1,1,0,1,1,1,1,0,0},
        {0,0,0,0,1,0,0,1,0,1},
        {0,1,1,0,1,1,0,0,0,1},
        {0,1,0,0,0,0,0,0,0,0},
        {0,1,0,0,1,0,1,1,1,0},
        {0,0,0,1,1,0,0,9,1,0},
        {1,1,1,1,0,0,1,0,1,0},
        {0,1,0,0,0,1,1,0,1,0},
        {0,0,0,1,0,1,1,0,0,0}
    };
    for(int x = 0; x < N; x++)for(int y = 0; y < N; y++)BESTMAZE[x][y] = MAZE[x][y];

    int minDepth = INT_MAX;
    int FinishPosition[2] = {-1,-1};
    getFinisher(MAZE,FinishPosition);
    mazeSolver(MAZE,FinishPosition,0,&minDepth,true);

    printMaze(BESTMAZE);

    return 0;
}
/*
{0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0}
*/