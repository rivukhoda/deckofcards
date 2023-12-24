//
//  GameDeck.hpp
//  DeckOfCardsGame
//

#ifndef GameDeck_hpp
#define GameDeck_hpp

#include "Deck.hpp"

/*
 GameDeck object represents all the cards that are actively used in a game. Since a shoe can
 hold multiple decks, it is no surprise that GameDeck can have duplicate cards.
 */
class GameDeck {
public:
    // Adds 52 unique cards to the game deck.
    void addDeck(const Deck deck);
    
    // Returns and removes a card from the game deck.
    std::vector<Card> drawCards(const int count);
    
    // Displays the counts of remaining cards per suit.
    void listCountPerSuit();
    
    // Dispalys the counts of each card remaining per card type (suit, value).
    void listCountPerCard();
    
    // Randomly permutes the order of cards.
    void shuffle();
    
    // Displays all cards.
    void listCards();
private:
    std::vector<Card> gameCards;
    
    
};

#endif /* GameDeck_hpp */
