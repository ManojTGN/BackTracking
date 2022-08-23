#include <iostream>
#include <stdlib.h>
#define N 10

using namespace std;

bool isFinishFound(int* playerPos,int* finishPos){
    return (playerPos[0] == finishPos[0]) && (playerPos[1] == finishPos[1]);
}

void printMaze(int MAZE[N][N]){

    int playerPos[2] = {-1,-1};
    int finishPos[2] = {-1,-1};

    for(int i=0;i<N+2;i++) cout<<"#";
    cout<<endl;

    for(int x = 0; x < N; x++){
        cout<<"#";
        for(int y = 0; y < N; y++){
            if(MAZE[x][y] == 0) cout<<" ";
            else if(MAZE[x][y] == 1) cout<<"#";
            else if(MAZE[x][y] == 2) cout<<"*";
            else if(MAZE[x][y] == 6) {cout<<"x";playerPos[0]=x;playerPos[1]=y;}
            else if(MAZE[x][y] == 9) {cout<<"o";finishPos[0]=x;finishPos[1]=y;}
            else cout<<" ";
        }cout<<"#"<<endl;
    }

    for(int i=0;i<N+2;i++) cout<<"#";
    cout<<endl<<"playerPos:["<<playerPos[0]<<","<<playerPos[1]<<"] isFound:"<<isFinishFound(playerPos,finishPos)<<endl;
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

void moveTo(int MAZE[N][N],int* playerPos,char direction,int* storeNewPosTo){

    MAZE[playerPos[0]][playerPos[1]] = 0;
    int playerTmpPos[2] = {playerPos[0],playerPos[1]};

    if(direction == 'U'){ playerTmpPos[0] -= 1; }
    else if(direction == 'D'){ playerTmpPos[0] += 1;}
    else if(direction == 'L'){ playerTmpPos[1] -= 1;}
    else { playerTmpPos[1] +=1;}
    
    storeNewPosTo[0] = playerTmpPos[0];
    storeNewPosTo[1] = playerTmpPos[1];
}

void getPlayerMoves(int MAZE[N][N], int* playerLastPos, int* playerCurrentPos, bool* Direction){
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

bool mazeSolver(int MAZE[N][N],int* playerLastPosition,int* FinishPos){

    int playerPos[2] = {-1,-1};
    int playerTmpPos[2] = {-1,-1};

    getPlayer(MAZE,playerPos);
    if(isFinishFound(playerPos,FinishPos)){
        system("CLS");
        printMaze(MAZE);
        return true;
    }

    bool direction[4] = {false,false,false,false};
    getPlayerMoves(MAZE,playerLastPosition,playerPos,direction);

    for(int i = 0; i < 4; i++){
        if(!direction[i]) continue;

        if(direction[i] && i == 0) moveTo(MAZE,playerPos,'U',playerTmpPos);
        else if(direction[i] && i == 1) moveTo(MAZE,playerPos,'D',playerTmpPos);
        else if(direction[i] && i == 2) moveTo(MAZE,playerPos,'L',playerTmpPos);
        else if(direction[i] && i == 3) moveTo(MAZE,playerPos,'R',playerTmpPos);

        MAZE[playerPos[0]][playerPos[1]] = 0;
        MAZE[playerPos[0]][playerPos[1]] = 2;
        MAZE[playerTmpPos[0]][playerTmpPos[1]] = 6;
        
        system("CLS");
        printMaze(MAZE);

        if(mazeSolver(MAZE,playerPos,FinishPos)) return true;

        MAZE[playerTmpPos[0]][playerTmpPos[1]] = 0;
        MAZE[playerPos[0]][playerPos[1]] = 6;
        
    }

    return false;
}

int main(){
    int MAZE[N][N]={
        {6,0,0,0,0,0,0,0,0,0},
        {0,1,1,0,1,1,1,1,1,1},
        {0,1,1,0,1,0,0,0,0,0},
        {0,0,0,0,1,0,0,0,0,0},
        {1,1,1,1,1,0,0,0,0,0},
        {0,0,1,0,1,0,0,0,0,0},
        {0,0,1,0,1,0,0,0,0,0},
        {0,0,1,0,1,0,0,0,0,0},
        {0,0,1,0,1,0,0,0,0,0},
        {0,0,1,0,1,0,0,0,0,0}
    };

    int FinishPosition[2] = {2,9};
    int PlayerPosition[2] = {-1,-1};
    getPlayer(MAZE,PlayerPosition);
    getFinisher(MAZE,FinishPosition);

    mazeSolver(MAZE,PlayerPosition,FinishPosition);

    return 0;
}