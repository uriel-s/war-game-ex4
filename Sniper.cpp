#pragma once
#include <vector>
#include <stdexcept>
#include<cmath>
#define Min_VAL -1
using namespace std;

#include "Sniper.hpp"
namespace WarGame {




  pair<int,int> Sniper::Strongest_Soldier(std::vector<std::vector<Soldier*>>& board,pair <int,int> loction ) {
    pair<int,int> target ;
    double d = Min_VAL;
for (int i = 0; i < board.size(); i++)
{
 for (int j = 0; j <board[0].size(); j++){
    if(board[i][j] != nullptr &&
       board[i][j]->team != board[loction.first][loction.second]->team  &&  
       (i!=loction.first && j!= loction.second)){
       int tmp =board[i][j]->health;

        if (tmp > d){
            d=tmp; 
        target.first = i;
        target.second = j;
      }
    }
   }
}
return target;
}

void Sniper::attack( std::vector<std::vector<Soldier*>>& board ,pair <int,int> loction ){
pair<int,int> target  = Strongest_Soldier(board , loction) ;
int x = target.first;
int y = target.second;
board[x][y]->health -= this->damage; 
if(board[x][y]->health <= 0){
   delete board[x][y];
   board[x][y] = nullptr;
  }
}

  void Sniper::fullAttack (std::vector<std::vector<Soldier*>>& board,pair <int,int> loction)
  {
  attack(board,loction);
}

}