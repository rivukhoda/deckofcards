//
//  Deck.cpp
//  DeckOfCardsGame
//

#include "Deck.hpp"
/*
 * Custom Constructor for Deck Object. A struct of type Card is created for every type of card
 * that is found in a traditional playing cards pack. The Deck object's cards attribute is
 * populated with 52 Card structs composed of distinct suit and value pairs.
 */
Deck::Deck(){
    std::vector<Suit> suits = {Heart, Diamond, Spade, Club};
    
    for (const auto& suit: suits) {
        Card card;
        card.suit = suit;
        
        for (int i = 1; i < 14; ++i) {
            card.value = i;
            cards.push_back(card);
        }
    }
}

std::vector<Card> Deck::getCards() const {
    return cards;
};
