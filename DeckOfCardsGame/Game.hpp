//
//  Game.hpp
//  DeckOfCardsGame
//

#ifndef Game_hpp
#define Game_hpp

#include "Player.hpp"
#include "GameDeck.hpp"

/*
 Game object represents all the objects that make up a game. Specifically,
 the players and the game deck. It is responsible for managing all the interactions
 that occur between the two classes.
 */

class Game {
public:
    // Adds player to the game.
    void addPlayer(std::string name);
    
    // Removes player from the game.
    void removePlayer(std::string name);
    
    // Gets all cards associated to a player.
    std::vector<Card> getPlayerCards(std::string playerName);
    
    // Gets the total value of cards held for each player.
    std::vector<std::pair<std::string, int>> getPlayersScore();
    
    // Gets a reference to the game deck.
    GameDeck& getGameDeck();
    
    // Gives a card to a player from the game deck.
    void dealCards(std::string playerName);
    
private:
    std::map<std::string, Player> players;
    GameDeck gameDeck;
    
    // Checks for the existence of a player in the game.
    bool playerExists(std::string name);
    
};

#endif /* Game_hpp */
