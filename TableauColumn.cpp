#include "TableauColumn.hpp"
#include <iostream>
#include <vector>
#include "Card.hpp"
#include <string>
#include "raylib.h"

void TableauColumn::addCard(const Card &card)
{
    cards.push_back(card);
}
void TableauColumn::addCards(const std::vector<Card> &newCards)
{
    cards.insert(cards.end(), newCards.begin(), newCards.end());
}
bool TableauColumn::canPlaceCard(const Card &card) const
{
    return (cards.back().getRank() - 1 == card.getRank());
}
bool TableauColumn::canMoveSequence(int index) const
{
    if (index < 0 || index >= cards.size())
        return false;

    for (int i = index; i < cards.size() - 1; i++)
    {
        if (!cards[i].isFaceUp() || !cards[i + 1].isFaceUp())
            return false;

        if (cards[i].getRank() != cards[i + 1].getRank() + 1)
            return false;

        if (cards[i].getSuit() != cards[i + 1].getSuit())
            return false;
    }

    return true;
}

std::vector<Card> TableauColumn::removeFrom(int index)
{
    std::vector<Card> tempCards;

    if (index < 0 || index >= cards.size())
        return tempCards;
    tempCards.insert(tempCards.end(), cards.begin() + index, cards.end());
    cards.erase(cards.begin() + index, cards.end());

    return tempCards;
}

void TableauColumn::flipTopCard()
{
    cards.back().flip();
}

bool TableauColumn::empty() const
{
    return cards.empty();
}

int TableauColumn::size() const
{
    return cards.size();
}

bool TableauColumn::hasCompleteSequence()
{
    if (cards.size() < 13)
        return false;

    int start = (int)cards.size() - 13;

    for (int i = start; i < (int)cards.size() - 1; i++)
    {
        if (!cards[i].isFaceUp() || !cards[i + 1].isFaceUp())
            return false;

        if (cards[i].getRank() != cards[i + 1].getRank() + 1)
            return false;

        if (cards[i].getSuit() != cards[i + 1].getSuit())
            return false;
    }

    if (cards[start].getRank() != 13)
        return false;

    if (cards.back().getRank() != 1)
        return false;

    return true;
}
std::vector<Card> TableauColumn::removeCompleteSequence()
{
    std::vector<Card> completed;

    if (!hasCompleteSequence())
        return completed;

    completed.insert(completed.end(), cards.end() - 13, cards.end());

    cards.erase(cards.end() - 13, cards.end());

    if (!cards.empty() && !cards.back().isFaceUp())
        cards.back().setFaceUp(true);

    return completed;
}

void TableauColumn::draw() const
{
  for (int i = 0; i < cards.size(); i++ )
  {
    cards[i].draw();
  }
}