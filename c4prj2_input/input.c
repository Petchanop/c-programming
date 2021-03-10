#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "deck.h"
#include "eval.h"
#include "input.h"
#include "future.h"

deck_t * hand_from_string(const char * str, future_cards_t * fc){
  deck_t * hand = malloc(sizeof(*hand));
  hand->cards = malloc(sizeof(*hand->cards));
  hand->n_cards = 0;
  char  copy[strlen(str)+1];
  strcpy(copy,str);
  char * j = copy;
  int i = 0;
  while (*j != '\n'){
      if (*j == '?' ){
     card_t * unknown = add_empty_card(hand);
     add_future_card(fc,i,unknown);
      }
      if ( *j  == ' '){
	card_t c = card_from_letters((*j-2),*(j-1));
      add_card_to(hand,c);
      i++;
       }
    j++;
    }
  return hand;
}

deck_t ** read_input(FILE * f, size_t * n_hands, future_cards_t * fc){
  char * input = NULL;
  deck_t ** read = NULL;
  size_t sz = 0;
  size_t i = 0;
  while (getline(&input,&sz, f) >= 0) {
    read = realloc(read,(i+1)*sizeof(deck_t*));
    deck_t * add = hand_from_string(input,fc);
    read[i] = add;
    i++;
    }
    free(input);
   *n_hands = i;
   return read;
}
