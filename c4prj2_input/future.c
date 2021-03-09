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
  fc->decks[index].cards[fc->decks[index].n_cards]=ptr;
  fc->decks[index].n_cards ++; 
}

void future_cards_from_deck(deck_t * deck, future_cards_t * fc){
  if (deck->n_cards < fc->n_decks){
    fprintf(stderr,"future_cards_from_deck");
    return;
  }
  for ( int i = 0 ; i < fc->n_decks ; i++){
    if(fc->decks[i].n_cards == 0) continue;
     for (int j = 0 ; j < fc->decks[i].n_cards ; j++){
       fc->decks[i].cards[j] = deck->cards[j];
     }
  }
}

