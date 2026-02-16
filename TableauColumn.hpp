#ifndef TABLEAUCOLUMN_H
#define TABLEAUCOLUMN_H

#include <vector>
#include "Card.hpp"

class TableauColumn
{
private:
    std::vector<Card> cards;

public:
    void addCard(const Card& card);
    void addCards(const std::vector<Card>& newCards);

    bool canPlaceCard(const Card& card) const;
    bool canMoveSequence(int index) const;

    std::vector<Card> removeFrom(int index);

    void flipTopCard();
    bool empty() const;
    int size() const;

    bool hasCompleteSequence();  
    std::vector<Card> removeCompleteSequence();

    void draw() const;
};

#endif