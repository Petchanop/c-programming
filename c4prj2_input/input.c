#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "deck.h"
#include "eval.h"
#include "input.h"
#include "future.h"

deck_t * hand_from_string(const char * str, future_cards_t * fc){
  deck_t * hand;
  fc = realloc(fc,(fc->n_decks+1)*sizeof(*fc));
  char * copy = malloc(strlen(str)*sizeof(copy));
  strcpy(copy,str);
  char * card = strtok(copy," ");
  while ( card != NULL){  
    card_t c = card_from_letter(copy[0],copy[1]);
    if( c->value != "?"){
      add_card_to(fc->deck[n_decks],c);
    }
    else{
      card_t * unknown = add_empty_card(hand);
     add_future_card(fc,fc->n_decks[n_decks]->cards[deck->n_cards],unknown);
    }
    card = strtok(NULL," ");
}
  fc->n_decks++;
  return fc->deck;
}

deck_t ** read_input(FILE * f, size_t * n_hands, future_cards_t * fc){
  char * input = NULL;
  deck_t ** read = malloc(n_hands*sizeof(*read));
  size_t sz = 0;
  int i = 0;
  while (getline(&input,&sz, f) >= 0) {
    read[i] = hand_from_string(input,fc);
    i++;
   }
  read->n_cards = i;
   free(input);
return read;
}
