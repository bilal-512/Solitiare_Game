#include "TableauColumn.hpp"
#include <iostream>

void TableauColumn::addCard(const Card& card)
{
    cards.push_back(card);
}
void TableauColumn::addCards(const std::vector<Card>& newCards)
{
   cards.insert(cards.end(), newCards.begin(), newCards.end());
}
bool TableauColumn::canPlaceCard(const Card& card) const
{
    return (cards.back().getRank() - 1 == card.getRank());
}
bool TableauColumn::canMoveSequence(int index) const
{
    
}
