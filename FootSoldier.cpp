#pragma once
#include <vector>
#include <stdexcept>
#include<cmath>
#define MAX_VAL 9999999
using namespace std;

#include "FootSoldier.hpp"
namespace WarGame {


double distance (int x1, int y1, int x2, int y2  )
{
double  ans = sqrt(pow((x1-x2),2) + pow(y1-y2,2));
return ans;
}

  pair<int,int> FootSoldier::CloserSoldier(std::vector<std::vector<Soldier*>>& board,pair <int,int> loction ) {
    pair<int,int> target ;
    double d = MAX_VAL;
for (int i = 0; i < board.size(); i++)
{
 for (int j = 0; j <board[0].size(); j++){
    if(board[i][j] != nullptr &&
       board[i][j]->team != board[loction.first][loction.second]->team  &&  
       (i!=loction.first && j!= loction.second)){
       
         double t = distance(loction.first,loction.second,i,j);
        if (t < d){
            d=t; 
        target.first = i;
        target.second = j;
      }
    }
   }
}
//Soldier& ans= *target;
return target;
}

void FootSoldier::attack( std::vector<std::vector<Soldier*>>& board ,pair <int,int> loction ){
pair<int,int> target  = CloserSoldier(board , loction) ;
int x = target.first;
int y = target.second;
board[x][y]->health -= this->damage; 
if(board[x][y]->health <= 0){
   delete board[x][y];
   board[x][y] = nullptr;
  }
}

  void FootSoldier::fullAttack (std::vector<std::vector<Soldier*>>& board,pair <int,int> loction)
  {
  attack(board,loction);
}

}