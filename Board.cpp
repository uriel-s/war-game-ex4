
#include <string>
#include <vector>
#include <stdexcept>
#include "Board.hpp"

using namespace std;
using namespace WarGame;



// operator for putting soldiers on the game-board during initialization.
    Soldier*& Board::operator[](std::pair<int,int> location){
       
			return this->board[location.first][location.second];

    }
        
    // operator for reading which soldiers are on the game-board.
    Soldier* Board::operator[](std::pair<int,int> location) const{
			return this->board[location.first][location.second];

    }

    void Board::move(uint player_number, std::pair<int,int> source, Board::MoveDIR direction){
       
       if (board[source.first][source.second] ==  nullptr 
         ||  board[source.first][source.second]->team != player_number) 
       throw("player cant choose that loction");
       
       std::pair<int,int> Newloction ; 
       switch (direction)
       {
       case  Up:
         Newloction.first  =  source.first+1;
         Newloction.second = source.second   ;
          break;

       case  Down:
          Newloction.first =  source.first-1;
         Newloction.second = source.second  ;
          break;

       case  Left:
          break;
          Newloction.first =  source.first;
         Newloction.second = source.second-1  ;

       case  Right:
       Newloction.first =  source.first;
         Newloction.second = source.second+1  ;
          break;

  if ( Newloction.first <0 || 
       Newloction.first> board.size() || 
       Newloction.second <0 || 
       Newloction.second >board[0].size() ) 
         throw("player cant move  to that loction");

if (board[Newloction.first][Newloction.second] !=nullptr)
         throw("player cant move  to that loction");

     board[Newloction.first][Newloction.second] = board[source.first][source.second];
     board[source.first][source.second] = nullptr ;
      board[Newloction.first][Newloction.second]->fullAttack( board , Newloction);
      
       }
       
       }
   
    bool Board::has_soldiers(uint player_number) const {
        
        for(int i=0;i<board.size();i++)
        {
         for(int j=0 ; j<board[i].size();j++)

        if ( board[i][j]!=nullptr && board[i][j]->team==player_number)   return true;

        }
  return false;
     }
    //
    
    
