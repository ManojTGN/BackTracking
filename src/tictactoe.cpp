#include <stdio.h>
#include <bits/stdc++.h>
#define N 3
#define PLAYER 0
#define CPU 1

void printBoard(int Board[N][N]){
    for(int x = 0; x < N; x++){
        for(int y = 0; y < N; y++){
            if(Board[x][y] == 0) printf(" o ");
            else if(Board[x][y] == 1) printf(" x ");
            else printf("   ");

            if(y < N-1) printf("|");
        } 
        if(x < N-1) printf("\n---x---x---\n");
    }
        
}

int isWinner(int Board[N][N]){
    if(Board[0][0] == PLAYER && Board[0][1] == PLAYER && Board[0][2] == PLAYER) return PLAYER;
    if(Board[1][0] == PLAYER && Board[1][1] == PLAYER && Board[1][2] == PLAYER) return PLAYER;
    if(Board[2][0] == PLAYER && Board[2][1] == PLAYER && Board[2][2] == PLAYER) return PLAYER;

    if(Board[0][0] == PLAYER && Board[1][0] == PLAYER && Board[2][0] == PLAYER) return PLAYER;
    if(Board[0][1] == PLAYER && Board[1][1] == PLAYER && Board[2][1] == PLAYER) return PLAYER;
    if(Board[0][2] == PLAYER && Board[1][2] == PLAYER && Board[2][2] == PLAYER) return PLAYER;

    if(Board[0][0] == PLAYER && Board[1][1] == PLAYER && Board[2][2] == PLAYER) return PLAYER;
    if(Board[0][2] == PLAYER && Board[1][1] == PLAYER && Board[2][0] == PLAYER) return PLAYER;

    if(Board[0][0] == CPU && Board[0][1] == CPU && Board[0][2] == CPU) return CPU;
    if(Board[1][0] == CPU && Board[1][1] == CPU && Board[1][2] == CPU) return CPU;
    if(Board[2][0] == CPU && Board[2][1] == CPU && Board[2][2] == CPU) return CPU;

    if(Board[0][0] == CPU && Board[1][0] == CPU && Board[2][0] == CPU) return CPU;
    if(Board[0][1] == CPU && Board[1][1] == CPU && Board[2][1] == CPU) return CPU;
    if(Board[0][2] == CPU && Board[1][2] == CPU && Board[2][2] == CPU) return CPU;

    if(Board[0][0] == CPU && Board[1][1] == CPU && Board[2][2] == CPU) return CPU;
    if(Board[0][2] == CPU && Board[1][1] == CPU && Board[2][0] == CPU) return CPU;

    return -1;
}
 
bool getBestMove(int Board[N][N],int whosTurn,int* setTheMove[2]){
    printf("[1.SetMove: %d %d]\n",*setTheMove[0],setTheMove[1]);

    int winner = isWinner(Board);
    if(winner == CPU) return true;
    else if(winner == PLAYER) return false;

    int tmp = -1;
    for(int x = 0; x < N; x++){
        for(int y = 0; y < N; y++){
            if(Board[x][y] != -1) continue;
            
            tmp = Board[x][y];
            Board[x][y] = whosTurn;

            if(getBestMove(Board,!whosTurn,setTheMove)){
                printf("[2.SetMove: %d %d]\n",*setTheMove[0],*setTheMove[1]);
                *setTheMove[0] = x;
                *setTheMove[1] = y;
            }

            Board[x][y] = tmp;
            tmp = -1;
        }
    }

    return false;
}

void TicTacToe(int Board[N][N]){

    int move[2];int *MOVE = move;
    MOVE[0] = -1;MOVE[1] = -1;

    int winner = -1;
    while(true){

        while(true){
            printf("Enter Your Move[1]:");scanf("%d",&MOVE[0]);
            printf("Enter Your Move[2]:");scanf("%d",&MOVE[1]);
            if(Board[MOVE[0]][MOVE[1]] == -1) break;
            else printf("Invalid Location! Try:[0-3][0-3]\n");
        }
        Board[MOVE[0]][MOVE[1]] = PLAYER;
        
        if(!getBestMove(Board,CPU,&MOVE)){
            for(int x = 0; x < N; x++){
                for(int y = 0; y < N; y++){
                    if(Board[x][y] == -1){
                        MOVE[0] = x;
                        MOVE[1] = y;
                        break;
                    }
                }
            }
        }
        Board[MOVE[0]][MOVE[1]] = CPU;
        printBoard(Board);

        winner = isWinner(Board);
        if(winner == 0 || winner == 1) break;
    }
    
    if(winner == 0) printf(" Winner Is : Player");
    else printf("Winner is : CPU");
}

int main(){
    int Board[N][N] = {
        {-1,-1,-1},
        {-1,-1,-1},
        {-1,-1,-1}
    };

    TicTacToe(Board);
    return 0;
}