//
// Created by boltz_j on 06/08/14.
// Copyright (c) 2014 bLabs. All rights reserved.
//

#include "CardDeck.h"
#include <deque>

CardDeck::CardDeck(int size_of_deck)
{
    // Two decks to compute the lookup table
    std::deque<int>* deck;
    std::deque<int>* table_deck;

    // Save the number of cards in the deck
    this->size_of_deck = size_of_deck;

    // Init the main deck
    deck = new std::deque<int>();
    for (int i = 0; i < size_of_deck; i++)
    {
        deck->push_front(i);
    }

    // Compute the Lookup Table as a table deck
    table_deck = new std::deque<int>();
    while (!deck->empty())
    {
        // Step 1 : Take the top card off the deck and set it on the table
        table_deck->push_back(deck->front());
        deck->pop_front();

        // Step 2 : Take the next card off the top of desk and put it on
        // the bottom of the deck in your hand.
        if (!deck->empty())
        {
            deck->push_back(deck->front());
            deck->pop_front();
        }
    }

    // Store the position of the card after one round as the lookup table
    this->shuffle_table = new int [size_of_deck];
    for (int i = 0; i < size_of_deck; ++i)
    {
        this->shuffle_table[i] = table_deck->front();
        table_deck->pop_front();
    }
}

CardDeck::~CardDeck()
{
    delete this->shuffle_table;
}

int CardDeck::compute()
{
    int result = 0;
    int** decks;

    // Using two decks alternatively
    decks = new int* [2];
    decks[0] = new int [this->size_of_deck];
    decks[1] = new int [this->size_of_deck];

    // Init the first deck
    for (int i = 0; i < this->size_of_deck; ++i)
    {
        decks[0][i] = i;
    }

    while (42)
    {
        // Select decks
        int* deck = decks[result % 2];
        int* new_deck = decks[(result + 1) % 2];

        // Shuffle the cards using the LUT
        for (int i = 0; i < this->size_of_deck; ++i)
        {
            new_deck[i] = deck[this->shuffle_table[i]];
        }

        // Increment the number of round
        ++result;

        // Stop if the deck is ordered
        if (this->is_over(new_deck))
            break;
    }

    // release decks
    delete (decks[0]);
    delete (decks[1]);
    delete (decks);

    // Return the number of rounds
    return result;
}

bool CardDeck::is_over(int* deck)
{
    // If one of the cards if not ordered return false
    for (int i = 0; i < this->size_of_deck; ++i)
        if (deck[i] != i)
            return false;

    // Else the game is over :)
    return true;
}