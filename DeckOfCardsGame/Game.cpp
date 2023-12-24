//
//  Game.cpp
//  DeckOfCardsGame
//
//  Created by Rivu Khoda on 2023-11-23.
//

#include "Game.hpp"

/*
 Adds a player to the game by using the name of the player as a key and
 the player object as value to map datastructure that holds all players
 that are playing the game.
*/
void Game::addPlayer(std::string name) {
    if (playerExists(name)) {
        std::cout << "player already exists, please pick a different name" << std::endl;
    }
    else {
        Player newPlayer(name);
        players.insert(std::make_pair(name, newPlayer));
    }
};

/*
 Removes a player from a map data structure that holds all the players
 that are playing the game.
 */
void Game::removePlayer(std::string name) {
    //check to see if there are any players participating in the game
    if (players.empty()) {
        std::cout << "there are no players currently in game" << std::endl;
        std::cout << std::endl;
    }
    else {
        //TODO: can maybe refactor here with playerExist?
        auto result = players.erase(name);
        
        if (result == 0) {
            std::cout << "player not found" << std::endl;
            std::cout << std::endl;
        }
    }
};

/*
 Retrieves a list of cards held by a player by finding the player object
 from the map data structure that holds all players using the player's name
 and accessing its cards attribute with a getter.

 */
std::vector<Card> Game::getPlayerCards(std::string playerName) {
    std::vector<Card> cards;
    
    if (!playerExists(playerName)) {
        std::cout << "player not found" << std::endl;
        std::cout << std::endl;
    }
    else {
        auto it  = players.find(playerName);
        const Player& player = it->second;
        cards = player.getCards();
        
        std::cout << playerName + "'s Cards In Hand" << std::endl;
        std::cout << "----------------------" << std::endl;
        
        for (const auto& card: cards) {
            printCard(card);
        }
        
        std::cout <<std::endl;
    }
    
    return cards;
}

/*
 Retrieves a list of total value of cards held by each player in game. The map datastructure representing
 all of the players in game are iterated over to obtain cards per player, and the sum of the values of cards
 per player is computed.
 */
std::vector<std::pair<std::string, int>> Game::getPlayersScore() {
    std::vector<std::pair<std::string, int>> listOfPlayers;
    
    // compute total value in hand of each player
    for (const auto& pair : players) {
        
        Player player = pair.second;
        int totalValueInHand = player.getScore();
        
        std::pair<std::string, int> playerValue(pair.first, totalValueInHand);
        listOfPlayers.push_back(playerValue);
    }
    
    // sort players by total value in hand
    std::sort(listOfPlayers.begin(), listOfPlayers.end(), [](const auto& lhs, const auto& rhs) {
        return lhs.second > rhs.second;
    });
    
    //print player and their total value in hand
    std::cout << "Total Value in Hand Per Player" << std::endl;
    std::cout << "------------------------------" << std::endl;
    for (const auto& pair : listOfPlayers) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
    std::cout << std::endl;
    
    return listOfPlayers;
};


GameDeck& Game::getGameDeck(){
    return gameDeck;
};

/*
 Checks if a player that sought out by its name exists in the map that contains all players in game.
 if the iterator "it" refers to an element past the end of map, then it is indicative of abscence of
 the item that is looked up.
 */
bool Game::playerExists(std::string name) {
    auto it = players.find(name);
    return it != players.end();
}


/*
 Gets a card from game deck and appends it to the cards attribute of a player, which represents the cards that are held by them.
*/
void Game::dealCards(std::string playerName){
    //TODO: player = playerManagerService.getPlayer();
    // draw a card from the game deck
    std::vector<Card> drawnCards = gameDeck.drawCards(1);
    if (!playerExists(playerName)) {
        return;
    }
    
    Player& player = players[playerName];

    //give the card that was drawn to the player
    player.setCards(drawnCards);
};

