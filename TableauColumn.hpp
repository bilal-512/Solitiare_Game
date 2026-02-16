#ifndef TABLEAUCOLUMN_H
#define TABLEAUCOLUMN_H

#include <vector>
#include "Card.hpp"

class TableauColumn
{
private:
    std::vector<Card> cards;
    int posX = 0;
    int posY = 0;

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
    void setPosition(int x, int y);
};

#endif