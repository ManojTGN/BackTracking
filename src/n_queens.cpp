#include <stdio.h>

using namespace std;

bool canPlace(){

    return false;
}

void nqueen(int *board){
    
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
    nqueen(board);

    //End
    delete[] board;
    return 0;
}
