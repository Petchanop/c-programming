#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>
#include "deck.h"
#include "eval.h"
#include "input.h"
#include "future.h"

deck_t * hand_from_string(const char * str, future_cards_t * fc){
  deck_t * hand = malloc(sizeof(*hand));
  hand->cards = malloc(sizeof(*hand->cards));
  hand->n_cards = 0;
  size_t j = 0;
  for(int i= 0; i < strlen(str) ; i++){
    if (isspace(str[i])){
          if ( str[i-2] == '?') { 
        card_t * unknown = add_empty_card(hand);
        add_future_card(fc,j,unknown);
         }
	  else{
    	card_t x = card_from_letters(str[i-2],str[i-1]);
    	add_card_to(hand,x);
     }
    j++;
     }
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
