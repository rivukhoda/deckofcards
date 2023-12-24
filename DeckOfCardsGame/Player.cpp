//
//  Player.cpp
//  DeckOfCardsGame
//

#include <string>
#include <iostream>

#include "Player.hpp"

Player::Player(std::string name) : name(name) {};

std::string Player::getName() const {
    return name;
};


std::vector<Card> Player::getCards() const {
    return cards;
};

/*
  Appends the list of cards received as paramter to the cards attribute, which represents the list of cards held by the player.
 */
void Player::setCards(std::vector<Card> receievedCards) {
    cards.insert(cards.end(), receievedCards.begin(), receievedCards.end());
}

/*
 Computes the sum of values associated to each card held by the player.
 */
int Player::getScore() const {
    int totalValue = 0;
    
    for (const auto& card: cards){
        totalValue += card.value;
    }
    
    return totalValue;
};
