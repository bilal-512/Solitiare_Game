#include "Card.hpp"
#include <iostream>

Card::Card(Suit s, int r)
    : suit(s), rank(r), faceUp(false) {}

void Card::flip()
{
    faceUp = !faceUp;
}

void Card::setFaceUp(bool value)
{
    faceUp = value;
}

bool Card::isFaceUp() const
{
    return faceUp;
}

int Card::getRank() const
{
    return rank;
}

Card::Suit Card::getSuit() const
{
    return suit;
}

std::string Card::getSuitString() const
{
    switch (suit)
    {
    case Hearts:
        return "Hearts";
    case Diamonds:
        return "Diamonds";
    case Clubs:
        return "Clubs";
    case Spades:
        return "Spades";
    default:
        return "";
    }
}

std::string Card::getRankString() const
{
    switch (rank)
    {
    case 1:
        return "A";
    case 11:
        return "J";
    case 12:
        return "Q";
    case 13:
        return "K";
    default:
        return std::to_string(rank);
    }
}

void Card::draw() const
{
    if (faceUp)
        std::cout << getRankString() << " of " << getSuitString() << std::endl;
    else
        std::cout << "[Face Down]" << std::endl;
}

bool Card::canPlaceOn(const Card &other) const
{
    return rank == other.rank - 1;
}