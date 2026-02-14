#ifdef TABULEACOLUMN_H
#define TABULEACOLUMN_H
#include "Card.hpp"
#include<vector>
class TabuleaColumn
{
private:
    vector<Card> cards;
public:
    void addCard(Card c);
    Card removeCard( );
    bool isValidMove();

};



#endif