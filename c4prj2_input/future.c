#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "deck.h"
#include "future.h"
#include "cards.h"

void add_future_card(future_cards_t * fc, size_t index, card_t * ptr){
  if (index >= fc->n_decks) {
    fc->decks = realloc(fc->decks, (index+1) * sizeof(deck_t));
    for (size_t i = fc->n_decks; i <= index; i++) {
      fc->decks[i].n_cards = 0;
      fc->decks[i].cards = NULL;
    }
    fc->n_decks = index+1;
  }
    fc->decks[index].cards = realloc(fc->decks[index].cards,(fc->decks[index].n_cards+1)*sizeof(*(fc->decks[index].cards)));
    fc->decks[index].cards[fc->decks[index].n_cards]= ptr;
    fc->decks[index].n_cards++;
  }
}
 

void future_cards_from_deck(deck_t * deck, future_cards_t * fc){
  
  if (deck->n_cards < fc->n_decks){
    perror("ERROR: not enough cards in deck to fill future cards\n");
    exit(EXIT_FAILURE);
  }
  else{
    
  for ( int i = 0 ; i < fc->n_decks ; i++){
    if (fc->decks[i].n_cards == 0){
      continue;
    }
    for (int j = 0 ; j < fc->decks[i].n_cards ; j++){
      *fc->decks[i].cards[j] = *deck->cards[j];
      }
  }
}
}
