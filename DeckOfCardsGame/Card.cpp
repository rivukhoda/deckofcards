//
//  Card.cpp
//  DeckOfCardsGame
//

#include "Card.hpp"

const std::map<int, std::string> suitToString = {
    {0, "Heart"},
    {1, "Diamond"},
    {2, "Spade"},
    {3, "Club"}
};

void printCard(Card card) {
    auto it = suitToString.find(card.suit);
    std::string suit = it->second;
    std::cout << suit << " " << card.value << std::endl;
};
