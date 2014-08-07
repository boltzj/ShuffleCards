//
//  main.cpp
//  ShuffleCards
//
//  Created by boltz_j on 06/08/14.
//  Copyright (c) 2014 bLabs. All rights reserved.
//

#include <iostream>
#include "CardDeck.h"

int main(int argc, const char * argv[])
{
    if (argc != 2)
    {
        std::cerr << "Usage: " << argv[0] << " size_of_deck\n";
        return EXIT_FAILURE;
    }

    int size_of_deck;

    try
    {
        size_of_deck = std::stoi(argv[1]);
    }
    catch (std::invalid_argument&)
    {
        std::cerr << argv[1] << " is not a valid integer\n";
        return EXIT_FAILURE;
    }

    // Init Game
    CardDeck* game = new CardDeck(size_of_deck);

    // Compute and print result
    std::cout << game->compute() << "\n";

    // Exit
    return EXIT_SUCCESS;
}
