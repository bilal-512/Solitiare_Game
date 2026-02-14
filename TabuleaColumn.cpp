#include "TabuleaColumn.hpp"
#include "Card.hpp"
#include <iostream>
using namespace std;

void TabuleaColumn::addCard(Card card)
{
    cards.push_back(card);
}
Card TabuleaColumn::removeCard()
{
    return cards.pop_back()
}
bool TabuleaColumn::isValidMove()
{
    if ( )
}