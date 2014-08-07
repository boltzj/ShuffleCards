//
// Created by boltz_j on 06/08/14.
// Copyright (c) 2014 bLabs. All rights reserved.
//


#ifndef __CardDeck_H_
#define __CardDeck_H_


class CardDeck
{
private:
    // Number of cards in the deck
    int  size_of_deck;
    // Lookup Table used to store card distribution for a round
    int* shuffle_table;
    // Test if a deck is ordered
    bool is_over(int* deck);

public:
    // Constructor
    CardDeck(int size_of_deck);
    // Destructor
    ~CardDeck();
    // Compute the number of rounds to comeback to the original deck
    int compute();
};

#endif //__CardDeck_H_
