#pragma once
#include <vector>
#include <stdexcept>
#include "FootSoldier.hpp"
using namespace std;
namespace WarGame {

class FootCommander  : public FootSoldier{
    public: 
FootCommander(){}
~FootCommander(){}

FootCommander(int t){
 const int health=150;  
 damage=20;
 life=150;
 team =t;
}
void fullAttack(std::vector<std::vector<Soldier*>>& board ,pair <int,int> loction)override ;
void attack(std::vector<std::vector<Soldier*>>& board ,pair <int,int> loction) ;
pair<int,int> CloserSoldier(std::vector<std::vector<Soldier*>>& board,pair <int,int> loction)  ;
};

}