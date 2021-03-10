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
  hand->cards = NULL;
  hand->n_cards = 0;
  char  copy[strlen(str)+1];
  strcpy(copy,str);
  char * card = strtok(copy," ");
  int i = 0;
  while ( card != NULL){
     
    if (card[0] == "?"){ 
    card_t * unknown = add_empty_card(hand);
    add_future_card(fc,i,unknown);
      }
    else{
      card_t c = card_from_letters(card[0],card[1]);
      add_card_to(hand,c);
       }
    i++;
    card = strtok(NULL," ");
}
  free(hand);
  fc->n_decks++;
  return hand;
}

deck_t ** read_input(FILE * f, size_t * n_hands, future_cards_t * fc){
  char * input = NULL;
  deck_t ** read = NULL;
  size_t sz = 0;
  size_t i = 0;
  while (getline(&input,&sz, f) >= 0) {
    read = realloc(read,(i+1)*sizeof(*read));
    deck_t * add = hand_from_string(input,fc);
    if (add == NULL) continue;
    read[i] = add;
    i++;
    print_hand(read[i]);
   }
   free(input);
   *n_hands = i;
return read;
}
