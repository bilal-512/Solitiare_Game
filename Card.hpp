#ifndef CARD_H
#define CARD_H

#include <string>

class Card
{
public:
    enum Suit { Hearts, Diamonds, Clubs, Spades };

private:
    Suit suit;
    int rank;        
    bool faceUp;

public:
    Card(Suit s, int r);

    void flip();
    void setFaceUp(bool value);

    bool isFaceUp() const;
    int getRank() const;
    Suit getSuit() const;

    std::string getSuitString() const;
    std::string getRankString() const;

    void draw() const;

    bool canPlaceOn(const Card& other) const;
};

#endif