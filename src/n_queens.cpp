#include <iostream>

using namespace std;

void print(int **Board, int n){
    //Just Printing The Board
    for (int x = 0; x < n; x++){
        for (int y = 0; y < n; y++) cout<<Board[x][y]<<" ";
        cout<<endl;
    }cout<<endl;
}

bool canPlace(int **Board, int n, int x, int y){
    int r = 0;int c = 0;
    //Row Checker
    for(r = 0; r < n; r++){
        if(Board[x][r] == 1) return false;
    }

    //Column Checker
    for(c = 0; c < n; c++){
        if(Board[c][y] == 1) return false;
    }

    //Diagonal Upward Left
    r = x;c = y;
    while( r >= 0 && c >= 0 ) {
        if(Board[r][c] == 1) return false;
        r--;c--;
    }

    //Diagonal Upward Right
    r = x;c = y;
    while( r >= 0 && c < n ) {
        if(Board[r][c] == 1) return false;
        r--;c++;
    }

    //Diagonal Downward Left
    r = x;c = y;
    while( r < n && c >= 0 ) {
        if(Board[r][c] == 1) return false;
        r++;c--;
    }

    //Diagonal Downward Right
    r = x;c = y;
    while( r < n && c < n ) {
        if(Board[r][c] == 1) return false;
        r++;c++;
    }
    
    //If No Queen Attacks At (x,y) Then Return True
    return true;
}

bool nqueen(int **Board, int n, int placed = 0){

    //Checking If All n Queens Are Placed
    if(placed == n){
        print(Board,n);
        return true;
    }

    //BackTracking Method
    for(int x = 0; x < n; x++){
        for(int y = 0; y < n; y++){
            
            //Checking If Can Queen Be Placed At (x,y)
            if(canPlace(Board, n, x, y)){
                
                //Placing The Queen At (x,y)
                Board[x][y] = 1;

                //Calling NQueen Function Again To Place The Next Queen
                if(nqueen(Board,n,placed+1) == true)
                    //It Is Only Triggered When All Queens Are Placed In The Right Place
                    return true;

                //*If The Above If Statement Returns False Then
                //This Track is Not A Right One And We Should Undo The Board
                
                //Removing The Queen At (x,y)
                Board[x][y] = 0;
            }
            
        }
    }

    //If All The Tracks Were Invalid Then It Returns False
    return false;
}

int main(){

    //Getting The Board Length (n)
    int n;cout<<"Enter (n):";cin>>n;

    //Creating A 2D Dynamic Array (board)
    int** Board = new int*[n];
    for (int x = 0; x < n; x++){
        Board[x] = new int[n];
        for (int y = 0; y < n; y++) Board[x][y] = 0;
    }

    //Calling The N-Queen Function
    nqueen(Board,n);

    //Deleting The Pointers
    for (int i = 0; i < n; i++)delete[] Board[i]; 
    delete[] Board;

    return 0;

}