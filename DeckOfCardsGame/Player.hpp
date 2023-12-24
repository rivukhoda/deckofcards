//
//  Player.hpp
//  DeckOfCardsGame
//

#ifndef Player_hpp
#define Player_hpp

#include <vector>

#include "Card.hpp"

/*
 Player object represents an individual that is participating in a game. A player is uniquely identified
 with a name (string), and is able to have cards in hand (vector<Card>)
 */
class Player {
public:
    Player(std::string name = "");
    
    std::string getName() const;
    std::vector<Card> getCards() const;
    
    // Adds cards to the hand of cards
    void setCards(std::vector<Card> cards);
    
    // Computes total value from the hand of cards
    int getScore() const;
    
private:
    const std::string name;
    std::vector<Card> cards;
};

#endif /* Player_hpp */
