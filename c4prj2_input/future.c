#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "deck.h"
#include "future.h"
#include "cards.h"

void add_future_card(future_cards_t * fc, size_t index, card_t * ptr){
  if(fc==NULL){
    fc = malloc(sizeof(*fc));
    fc->decks=NULL;
    fc->n_decks=0;
  }
  size_t n = fc->n_decks;
  if (index < fc->decks[n].n_cards){
     fc->decks[n].cards[index]= ptr;
     }
  else{
    fc->decks[n].cards = realloc(fc->decks[n].cards,(index)*sizeof(*fc->decks[n].cards));
   fc->decks[n].cards[index] = ptr;
   fc->decks[n].n_cards++;
   }
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
