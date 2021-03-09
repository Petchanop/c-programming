#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "deck.h"
#include "future.h"
#include "cards.h"

void add_future_card(future_cards_t * fc, size_t index, card_t * ptr){
  fc->decks = realloc(fc->decks,(fc->n_decks+1)*sizeof(*fc->decks));
  ptr += index;
  fc->decks[fc->n_decks]->cards = ptr;
 
}

void future_cards_from_deck(deck_t * deck, future_cards_t * fc){
  for ( int i = 0 ; i < fc->n_decks ; i++){
     for (int j = deck->n_cards ; j > fc->decks[i].n_cards ; j--){
       add_future_card(fc,i,deck->cards[j]); 
    }
  }
}

