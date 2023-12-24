//
//  main.cpp
//  DeckOfCardsGame
//

#include <iostream>

#include "Game.hpp"

int main(int argc, const char * argv[]) {

    Game game;
    Deck deck1;
    Deck deck2;
    
    GameDeck& gameDeck = game.getGameDeck();
    gameDeck.addDeck(deck1);
    gameDeck.addDeck(deck2);
    gameDeck.listCards();
    
    gameDeck.shuffle();
    gameDeck.listCards();
    
    const std::string player1 = "mario";
    const std::string player2 = "megaman";
    const std::string player3 = "cloud";
    const std::string player4 = "kirby";
    
    game.addPlayer(player1);
    game.addPlayer(player2);
    game.addPlayer(player3);
    game.addPlayer(player4);
    
    game.dealCards(player1);
    game.dealCards(player2);
    game.dealCards(player3);
    game.dealCards(player3);
    
    game.getPlayerCards(player1);
    game.getPlayerCards(player2);
    game.getPlayerCards(player3);
    game.getPlayerCards(player4);
    
    game.getPlayersScore();
    
    game.removePlayer(player3);
    game.getPlayersScore();
    
    gameDeck.listCountPerSuit();
    gameDeck.listCountPerCard();
    
    
    return 0;
}
