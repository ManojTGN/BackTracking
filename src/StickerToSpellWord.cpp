#include <iostream>
#include <string>

using namespace std;


int FindMinimumSticker(string Stickers[], string target, int stickerCount){
    
    string substring;string remaining;
    if(target.length() == 0) return 1;

    for(int i = target.length(); i >= 0 ; i ++){
        for(int j = 0; j < stickerCount; j++){

            substring = target.substr(0, i);
            if(Stickers[j].find(substring)){
                substring = target.substr(0, i);
                remaining = target.substr(i,target.length());
                FindMinimumSticker(Stickers,remaining,stickerCount);
            }

        }
    }

    return -1;
}

int main(){
    string target = "thehat";
    string Stickers[3] = {"with","example","science"};

    if(FindMinimumSticker(Stickers,target,3) == -1) cout<<"Unable To Find The Target Characters In The Stickers List"<<endl;

    return 0;
}
