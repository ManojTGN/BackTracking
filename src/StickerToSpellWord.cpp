#include <iostream>
#include <string>
#include <limits>
#define StickerCount 3

using namespace std;


bool FindMinimumSticker(string Stickers[], string target, int CurrentScore, int &minScore,int usedStickers[StickerCount]){
    if(target.length() == 0){
        if(CurrentScore < minScore) minScore = CurrentScore;
        for(int i = 0; i < StickerCount; i++) usedStickers[i] = -1;
        return true;
    } 

    int finder;
    for(int i = target.length(); i >= 0 ; i--){

        string substring = target.substr(0, i);
        for(int j = 0; j < StickerCount; j++){

            finder = Stickers[j].find(substring);
            if( finder != -1 && finder != 0 ){
                string remaining = target.substr(i,target.length());
                if(usedStickers[j] == 1) {
                    FindMinimumSticker(Stickers,remaining,CurrentScore,minScore,usedStickers);
                }else{
                    usedStickers[j] = 1;
                    FindMinimumSticker(Stickers,remaining,CurrentScore+1,minScore,usedStickers);
                } 
                
            }

        }
    }

    return false;
}

int main(){
    string target = "thehat";
    string Stickers[StickerCount] = {"with","example","science"};

    int minScore = numeric_limits<int>::max();
    int usedStickers[StickerCount] = {-1,-1,-1};

    FindMinimumSticker(Stickers,target,0,minScore,usedStickers);
    cout<<"Minimum Sticker Score: "<<minScore<<endl;

    return 0;
}
