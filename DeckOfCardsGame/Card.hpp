//
//  Card.hpp
//  DeckOfCardsGame
//

#ifndef Card_hpp
#define Card_hpp

#include <map>
#include <string>
#include <iostream>

enum Suit {
    Heart,
    Diamond,
    Spade,
    Club
};

struct Card {
    
    Suit suit;
    int value;
};

extern const std::map<int, std::string> suitToString;

void printCard(Card card);

#endif /* Card_hpp */
