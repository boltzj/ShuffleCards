#ShuffleCards

ShuffleCards implementation in C++

## Problem Statement

You have a deck containing X number of cards. While holding the deck, do the following:

    a. Take the top card off the deck and set it on the table  
    b. Take the next card off the top of desk and put it on the bottom of the deck in your hand.  
    c. Continue doing (a) and (b) until all the cards are on the table.  

>**This is a round.** 

Pick up the deck and repeat steps (a), (b), (c) until the deck is in the original order. 

Write a program to determine how many rounds it will take to put the deck back in original order. Please make sure the program can take a command line argument for number of cards in deck.  
We will test the solution with different sizes of decks e.g. 100, 200, 300, 313. 

## Usage

To compile the application using:  
```
make
```


run the application using:  
```
./shufflecards 313
```

## Notes

For a fixed size deck, for a round the distribution of cards will be the same.  
This implementation use a lookup table to compute only one time this distribution
at the initialization of the card deck.  
This way, for each round the application use the lookup table to avoid computing the distribution.   