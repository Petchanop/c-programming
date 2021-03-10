#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "deck.h"
#include "future.h"
#include "cards.h"

void add_future_card(future_cards_t * fc, size_t index, card_t * ptr){
  if(index < fc->n_decks){
  fc->decks[index].cards = realloc(fc->decks[index].cards,(fc->decks[index].n_cards+1)*sizeof(*fc->decks[index].cards));
  fc->decks[index].cards[fc->decks[index].n_cards]=ptr;
  fc->decks[index].n_cards ++; 
}
  else{
    while(fc->n_decks <= index){
      fc->decks=realloc(fc->decks,(fc->n_decks+1)*sizeof(*fc->decks));
      fc->decks[fc->n_decks].cards = NULL;
      fc->decks[fc->n_decks].n_cards = 0;
      fc->n_decks++;
    }
    fc->decks[index].cards = realloc(fc->decks[index].cards,(fc->decks[index].n_cards+1)*sizeof(*fc->decks[index].cards));
    fc->decks[index].cards[fc->decks[index].n_cards]=ptr;
    fc->decks[index].n_cards ++;
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
      fc->decks[i].cards[j]->value = c->value;
      fc->decks[i].cards[j]->suit = c->suit;
    }
  }
  int count = 0;
  //loop through all decks in fc
  for ( int i = 0; i < fc->n_decks; i++){
    //if the deck isn't empty, remove that element by shifting the array elements back one (you'll have empty crap at the end)
    if ( fc->decks[i].cards[0]->suit != NUM_SUITS){
      for (int k = i; k < (fc->n_decks - 1); k++){
	fc->decks[i] = fc->decks[i+1];
      }
      if (fc->decks[i].cards[0]->suit != NUM_SUITS){
	i-=1;
      }
      fc->n_decks--;
      count++;
    }
  }//end loop through decks in fc

  if ( count > 0 ){
    fc->decks = realloc(fc->decks, (fc->n_decks)*sizeof(deck_t));
  }

}





