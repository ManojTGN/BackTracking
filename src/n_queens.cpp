#include <iostream>

using namespace std;


void print(int *board, int n){

    //Just Printing The Board
    for (int x = 0; x < n; x++){
        for (int y = 0; y < n; y++) cout<<*(board + x * n + y)<<" ";
        cout<<endl;
    }
    
}

bool canPlace(int *board, int n, int x, int y){

    //Checking The Rows
    for(int r = 0; r < n; r++){
        if(*(board + r * n + y) == 1) return false;
    }

    //Checking The Columns
    for(int c = 0; c < n; c++){
        if(*(board + x * n + c) == 1) return false;
    }

    //Diagonal Upward Left
    int r = x;int c = y;
    while( r>=0 && c>=0 ){
        if(*(board + r*n + c) == 1) return false;
        r--;c--;
    }

    //Diagonal Upward Right
    r = x;c = y;
    while( r<n && c>=0 ){
        if(*(board + r*n + c) == 1) return false;
        r++;c--;
    }

    //Diagonal DownWard Left
    r = x;c = y;
    while( r>=0 && c<n ){
        if(*(board + r*n + c) == 1) return false;
        r--;c++;
    }

    //Diagonal Downward Right
    r = x;c = y;
    while( r<n && c<n ){
        if(*(board + r*n + c) == 1) return false;
        r++;c++;
    }

    //If No Queen Attacks At (x,y) Then Return True
    return true;
}

bool nqueen(int *board, int n, int placed = 0){

    //Checking If All n Queens Are Placed
    if(placed == n){
        print(board,n);
        return true;
    }

    //BackTracking Method
    for(int x = 0; x < n; x++){
        for(int y = 0; y < n; y++){

            //Checking If Can Queen Be Placed At (x,y)
            if(canPlace(board, n, x, y)){
                
                //Placing The Queen At (x,y)
                //Increasing The Number Of Queens Placed By 1
                *(board + x * n + y) = 1;
                placed +=1;

                //Calling NQueen Function Again To Place The Next Queen
                if(nqueen(board,n,placed) == true)
                    //It Is Only Triggered When All Queens Are Placed In The Right Place
                    return true;

                //*If The Above If Statement Returns False Then
                //This Track is Not A Right One And We Should Undo The Board
                
                //Removing The Queen At (x,y) And QueensPlaced minus -1
                *(board + x * n + y) = 0;
                placed -= 1;
            }

        }
    }

    //If All The Tracks Were Invalid Then It Returns False
    return false;
}

int main(){

    //Getting The Board Length (n)
    int n;
    cout<<"Enter (n):";cin>>n;

    //Creating A 2D Dynamic Array (board)
    int* board = new int[n * n];
    for (int x = 0; x < n; x++){
        for (int y = 0; y < n; y++) *(board + x * n + y) = 0;
    }

    //Calling The N-Queen Function
    nqueen(board,n);

    //Deleting The Pointers
    delete[] board;
    return 0;
}