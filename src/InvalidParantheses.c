#include <stdio.h>

int isValid(char* str){
    if( str[0] == ')' || str[str.length()-1] == '(') return false;

    int status = 0;
    for(int i =0; i< str.length(); i++){
        if(str[i] == '(') status++;
        else status--;
    }
    return 0 == status;
}

void removeParanthesis(char* str, char* bestSolution){

    if(isValid(str)){
        if(bestSolutionLength < strLength) {
            for(int i = 0; i < strLength;i++){
                *str[i];
            }
        }
    }
    
    string temp;
    for(int i = 0; i < str.length(); i++){
        temp = str[i];
        str.erase(i,1);

        removeParanthesis(str,maxSolution);

        str.insert(i,temp);
        temp = "";
    }

}

void main(){

    char solution[12];
    char str[12] = "()(()((((())";
    for(int i = 0; i < 12; i++) solution[i] = str[i];

    removeParanthesis(str,&solution);
    printf("%s",solution);

}