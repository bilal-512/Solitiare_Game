#ifndef DECK_H
#define DECK_H

#include <vector>
#include "Card.hpp"

class Deck
{
private:
    std::vector<Card> cards;

public:
    Deck(int suitMode = 4);  // 1, 2, or 4 suits

    void shuffleCards();
    Card dealCard();

    bool isEmpty() const ;
    int size() const
};

#endif