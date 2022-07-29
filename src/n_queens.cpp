#include <iostream>

using namespace std;

void print(int *board, int n){
    for (int x = 0; x < n; x++){
        for (int y = 0; y < n; y++) {
            cout<<*(board + x * n + y)<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

bool canPlace(int *board, int n, int x, int y){

    //Checking The Rows
    for(int r = 0; r < n; r++){
        if(*(board + r * n + y) == 1){
            return false;
        }
    }

    //Checking The Columns
    for(int c = 0; c < n; c++){
        if(*(board + x * n + c) == 1){
            return false;
        }
    }

    int r = x;int c = y;
    while( r>=0 && c>=0 ){
        if(*(board + r*n + c) == 1){
            return false;
        }
        r--;
        c--;
    }

    r = x;c = y;
    while( r>=0 && c<n ){
        if(*(board + r*n + c) == 1){
            return false;
        }
        r--;
        c++;
    }

    r = x;c = y;
    while( r<n && c<n ){
        if(*(board + r*n + c) == 1){
            return false;
        }
        r++;
        c++;
    }

    r = x;c = y;
    while( r<n && c>=0 ){
        if(*(board + r*n + c) == 1){
            return false;
        }
        r++;
        c--;
    }

    return true;
}

bool nqueen(int *board, int n, int *answer){

    //Checking If All n Queens Are Placed
    int placed = 0;
    for(int i = 0; i < n; i++){
        if(*(answer + i) != -1){
            placed+=1;continue;
        }
        break;
    }

    if(placed == n){
        print(board,n);
        return true;
    }

    for(int x = 0; x < n; x++){
        for(int y = 0; y < n; y++){

            if(canPlace(board, n, x, y)){
                int i;
                *(board + x * n + y) = 1;
                for(i = 0; i < n; i++){
                    if(*(answer + i) == -1){
                        *(answer + i) = x * n + y;
                        break;
                    }
                }

                if(nqueen(board,n,answer) == true){
                    return true;
                }

                *(board + x * n + y) = 0;
                *(answer + i) = -1;
            }
        }
    }

    return false;
}

int main(){

    //Getting The Board Length (n)
    int n;
    printf("N-Queens Problem\nEnter 'n':");
    scanf("%d",&n);

    //Creating A 2D Dynamic Array (board)
    int* board = new int[n * n];
    for (int x = 0; x < n; x++){
        for (int y = 0; y < n; y++) {
            *(board + x * n + y) = 0;
        }
    }

    //Creating Answer Array & Calling The Nqueen Function
    int* answer = new int[n];
    for(int i = 0; i < n; i++){
        *(answer + i) = -1;
    }
    nqueen(board,n,answer);

    //End
    delete[] board;
    return 0;
}