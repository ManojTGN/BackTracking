#include <iostream>
#define N 10

using namespace std;

int* getPlayer(char* MAZE[N][N]){
    int position[2] = {-1,-1};
    for(int x = 0; x < N; x++){
        for(int y = 0; y < N; y++){
            if(MAZE[x][y] == "O"){
                position[0] = x;
                position[1] = y;
                return position;
            }
        }
    }

}

bool* getPlayerMove(char* MAZE[N][N],int* playerLastPos,int* playerCurrentPos){
    bool Direction[4] = {false,false,false,false};
    
    //CHECKING UP
    if(playerCurrentPos)

}

void mazeSolver(char* MAZE[N][N],int* playerLastPosition){
    int* playerPos = getPlayer(MAZE);
    bool* direction = getPlayerMove(MAZE,playerLastPosition,playerPos);
    for(int i = 0; i < 4; i++){
        if(direction[i] && i == 0){

        }else if(direction[i] && i == 1){
            
        }else if(direction[i] && i == 2){
            
        }else if(direction[i] && i == 3){
            
        }
    }
}

int main(){
    char* MAZE[N][N]={
        {" "," "," "," "," "," "," "," "," "," "},
        {" "," "," "," "," "," "," "," "," "," "},
        {" "," "," "," "," "," "," "," "," "," "},
        {" "," "," "," "," "," "," "," "," "," "},
        {" "," "," "," "," "," "," "," "," "," "},
        {" "," "," "," "," "," "," "," "," "," "},
        {" "," "," "," "," "," "," "," "," "," "},
        {" "," "," "," "," "," "," "," "," "," "},
        {" "," "," "," "," "," "," "," "," "," "},
        {" "," "," "," "," "," "," "," "," "," "}
    };
    mazeSolver(MAZE,);

    return 0;
}