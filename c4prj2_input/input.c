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
  char * copy = malloc(strlen(str)*sizeof(copy));
  strcpy(copy,str);
  char * card = strtok(copy," ");
  while ( card != NULL){
    printf("%s\n",copy);
    card_t c = card_from_letters(copy[0],copy[1]);
    print_card(c);
    if (2 <= c.value && c.value <= VALUE_ACE){
      add_card_to(hand,c);
     }
    else{
     card_t * unknown = add_empty_card(hand);
     add_future_card(fc,hand->n_cards,unknown);
    }
    card = strtok(NULL," ");
}
  free(hand);
  fc->n_decks++;
  print_hand(fc->decks);
  return fc->decks;
}

deck_t ** read_input(FILE * f, size_t * n_hands, future_cards_t * fc){
  char * input = NULL;
  deck_t ** read = NULL;
  size_t sz = 0;
  size_t i = 0;
  while (getline(&input,&sz, f) >= 0) {
    read = realloc(read,(i+1)*sizeof(*read));
    printf("%s\n",input);
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
