#include <algorithm>
#include <random>
#include "Deck.hpp"

Deck::Deck(int suitMode)
{
    using Suit = Card::Suit;
    std::vector<Suit> suits;
    if (suitMode == 1)
    {
        suits = {Suit::Spades};
    }
    else if (suitMode == 2)
    {
        suits = {Suit::Spades, Suit::Hearts};
    }
    else
        {
            suits = {Suit::Spades, Suit::Hearts, Suit::Diamonds, Suit::Clubs};
        }
    int deckCount = 104 / (suits.size() * 13);
    for (int d = 0; d < deckCount; d++)
    {
        for (Suit s: suits)
        {
            for (int rank = 0; rank < 13; rank++)
            {
                cards.emplace_back(s, rank);
            }
        }
    }
}
void Deck::shuffleCards()
{
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(cards.begin(), cards.end(),g);
}
Card Deck::dealCard()
{
    Card topCard = cards.back();
    cards.pop_back();
    return topCard;
}
bool Deck::isEmpty() const
{
    return cards.empty();
}
int Deck::size() const
{
    return cards.size();
}