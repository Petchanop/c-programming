#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "deck.h"
#include "future.h"
#include "cards.h"

void add_future_card(future_cards_t * fc, size_t index, card_t * ptr){
  if (index > fc->n_decks){
    for (int i = 0 ; i < index i++){ 
    fc->decks = realloc(fc->decks,(fc->n_decks+1)*sizeof(*fc->decks));
    fc->decks[i].cards = malloc(sizeof(* fc->decks[index].cards));
    fc->decks[i].cards = NULL;
    fc->decks[i].n_cards = 0;
    fc->n_decks++;
  }
    }
   size_t add = fc->decks[index].n_cards;
   fc->decks[index].cards = realloc(fc->decks[index].cards, (fc->decks[index].n_cards + 1)*sizeof(card_t*));
   fc->decks[index].cards[add] = ptr;
   fc->decks[index].n_cards++;
   }
 

void future_cards_from_deck(deck_t * deck, future_cards_t * fc){
  
  if (deck->n_cards < fc->n_decks){
    printf("ERROR: not enough cards in deck to fill future cards\n");
    exit(EXIT_FAILURE);
  }
 
  for ( int i = 0 ; i < fc->n_decks ; i++){
    if (fc->decks[i].n_cards == 0){
      continue;
    }
    for (int j = 0 ; j < fc->decks[i].n_cards ; j++){
      card_t * c = deck->cards[i];
      fc->decks[i].cards[j] = c;
    }
  }
}
