#include <iostream>
#define N 9

using namespace std;

void print(int Board[N][N]){
    //Just Prinitng The Board
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
    //Checking If The Cell Is Empty Or Has A Number
    if(Board[x][y] != 0) return false;

    //Getting The Grid Starting (x,y)
    int gridx = (x/3)*3;int gridy = (y/3)*3;

    //Checking If (n) Can Be Placed In The Cell
    for(int i = 0; i < N; i++){

        //HorizontalCheck And Vertical Check
        if(Board[x][i] == n) return false;
        if(Board[i][y] == n) return false;
        
        //The Grid(3x3) Check
        if(Board[gridx][gridy] == n) return false;
        if((i+1)%3==0){gridx+=1;gridy-=2;}else{gridy+=1;}
    }

    //If The (n) Can Be Placed Then It Returns True
    return true;
}

bool isEmpty(int Board[N][N],int &row, int &col){
    //Looping Through All The Cells
    for(row = 0; row < N; row++){
        for(col = 0; col < N; col++){

            //Finding The First Empty Cell In The Board
            if(Board[row][col] == 0) return true;
        }
    }

    //If No Cell Is Empty Then It Will Return False
    return false;
}

bool sudokuSolver(int Board[N][N]){
    
    //Checking If The Sudoku Is Completed!
    //And Updating The row,col Variable To The First
    //Empty Cell In The Sudoku Board
    int row,col;
    if(!isEmpty(Board,row,col)) {
        print(Board);
        return true;
    }

    //Trying To Place 1-9 Numbers In The Empty Cell And Calling This Function Again
    for(int i = 1; i <= N; i++){
        if(canPlace(Board,row,col,i)){

            //Setting The Empty Cell To A Number (i)
            Board[row][col] = i;

            //If It Returns True Then We Completed The Sudoku
            if(sudokuSolver(Board)) return true;

            //If It Returns False It Means We Have Placed All The 1-9 Numbers
            //In The Empty Cell But Noting Can Fit In The Box With The Current Board
            //And So We Are Reverting The Cell To Be Empty Again
            Board[row][col] = 0;
        }
    }

    //If We Can't Fit The Cell With Any Number Then It Returns False
    return false;
}

int main(){
    //Initilizing The Main Constant(N) Board 9X9
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
    
    //Calling The Solver! If Not Solved It Will Print This Message
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