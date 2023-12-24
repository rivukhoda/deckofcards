//
//  GameDeck.cpp
//  DeckOfCardsGame
//

#include <iostream>
#include <random>
#include <algorithm>
#include <optional>

#include "GameDeck.hpp"


/*
 Inserts all cards in a Deck object to a vector of Card structs representing
 the game deck.
 */
void GameDeck::addDeck(const Deck deck) {
    std::vector<Card> cards = deck.getCards();
    gameCards.insert(gameCards.end(), cards.begin(), cards.end());
}

/*
 Returns a card from the game deck by popping a card from it.
 */
std::vector<Card> GameDeck::drawCards(const int count) {
    
    std::vector<Card> drawnCards;
    
    for (int i = 0; i < count; ++i) {
        if (gameCards.empty()) {
            std::cout << "no card left in game deck" << std::endl;
            break;
        }
        
        Card drawnCard = gameCards.back();
        gameCards.pop_back();
        drawnCards.push_back(drawnCard);
    }
    
    // print the card that was drawn
    std::cout << "Cards Drawn" << std::endl;
    std::cout << "-----------" << std::endl;
    
    for (const auto& card: drawnCards) {
        printCard(card);
    }
    std::cout << std::endl;
    
    return drawnCards;
}

/*
 Displays the count of cards per suit in the game deck.
 A counter for each type of suit is represented by the int values belonging to each of the element in an array
 e.g. the value indexed at [1] would represent the count of cards associated to suit of Diamond, since
 the numbers 0, 1, 2, 3 are chosen to represent the suits Heart, Diamond, Spade, Club respectively.
 
 */
void GameDeck::listCountPerSuit() {
    const int suitCount = 4;
    int cardCounter[suitCount] = {0};
    
    for (const auto& card: gameCards) {
        cardCounter[card.suit]++;
    }
    
    std::map<Suit, int> countPerSuit = {
        {},
        {},
        {},
        {},
    };
    
    std::cout << "Count Of Cards Per Suit Left In Game Deck" << std::endl;
    std::cout << "-----------------------------------------" << std::endl;
    
    for (int i = 0; i < 4; ++i) {
        auto it = suitToString.find(i);
        std::string suitName = it->second;
        
        std::cout << suitName << ": " << cardCounter[i] << std::endl;
    }
    
    std::cout << std::endl;
}

/*
 Displays the count associated to each type of card in the game deck.
 A counter for each card is represented by int values belonging to each of the element in a two dimensional array.
 e.g. The value indexed at [1][4] would represent the count for the Card (Heart with a value of 4).
 */
void GameDeck::listCountPerCard() {
    // size of the row for the 2d array; the rows represent the suit of a card (0 = heart, 1 = diamond, 2 = spade, 3 = club)
    const int suitCount = 4;
    // size of the column for the 2d array; the columns represent the values of a card (1 to 13)
    const int valueCount = 14; // 14 is chosen so that 13th column is indexable, since there are no zero valued card.
    
    int cardCounter[suitCount][valueCount] = {{0}};
    
    for (const auto& card: gameCards) {
        cardCounter[card.suit][card.value]++;
    }
    
    std::cout << "Count Of Each Card Left In Game Deck" << std::endl;
    std::cout << "------------------------------------" << std::endl;
    
    for (int i = 0; i < 4; ++i) {
        auto it = suitToString.find(i);
        std::string suitName = it->second;
        
        // backward loop is done so that cards are displayed in descending order as per the requirement.
        for (int j = 13; j > 0; --j) {
            std::cout << suitName << " " << j << ": " << cardCounter[i][j] << " remaining" <<  std::endl;
        }
        std::cout << std::endl;
    }
}


/*
 Generates a random number between chosen lowerbound and upperbound integer values.
 */
int generateRandomNumber(int lowerBound, int upperBound) {
    std::random_device rd;   // Obtain a random seed from the hardware
    std::mt19937 gen(rd());  // Seed the generator

    // Create a distribution
    std::uniform_int_distribution<int> distribution(lowerBound, upperBound);

    // Generate a random number
    int randomNumber = distribution(gen);

    return randomNumber;
}

/*
 Shuffles the cards in game deck by linearly iterating through list of cards from left to right
 and randomly generating an index (bounded by the largest possible index) and swapping the current
 card in iteration with another card that is chosen with the randomly generated index.
 */
void GameDeck::shuffle() {
    
    int largestIndex = gameCards.size() - 1; // -1 is used to avoid any out of bounds error.
    
    for (auto& card: gameCards) {
        int randomNumber = generateRandomNumber(0, largestIndex);
        std::swap(card, gameCards[randomNumber]);
    }
}

/*
 Displays all the cards that are present in the game deck when its called.
 */

void GameDeck::listCards() {
    std::cout << "Cards in Game Deck" << std::endl;
    std::cout << "------------------" << std::endl;
    
    for (const auto& card: gameCards) {
            printCard(card);
    }
    
    std::cout << std::endl;
}
