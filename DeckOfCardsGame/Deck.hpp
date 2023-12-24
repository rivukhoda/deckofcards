//
//  Deck.hpp
//  DeckOfCardsGame
//

#ifndef Deck_hpp
#define Deck_hpp

#include <vector>

#include "Card.hpp"

class Deck {
public:
    Deck();
    std::vector<Card> getCards() const;

private:
    std::vector<Card> cards;
};

#endif /* Deck_hpp */
