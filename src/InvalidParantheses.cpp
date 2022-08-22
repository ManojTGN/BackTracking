#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

bool isValid(string str){
    if( str[0] == ')' || str[str.length()-1] == '(') return false;

    int status = 0;
    for(int i =0; i< str.length(); i++){
        if(str[i] == '(') status++;
        else status--;
    }
    return 0 == status;
}

void removeParanthesis(string str, string &maxSolution){
    
    if(isValid(str)){
        if(maxSolution.length() < str.length()) maxSolution = str;
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

int main(){
    string str = "()(()((((())";
    string solution = "";
    removeParanthesis(str,solution);
    cout<<solution<<endl;

    return 0;
}
