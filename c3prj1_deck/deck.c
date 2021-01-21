#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "deck.h"

void print_hand(deck_t * hand){
  card_t * p;
   for (int i  = 0; i < hand->n_cards ; i++){
     p = hand->cards[i]; 
    print_card(* p);
     printf(" ");
  }
}

int deck_contains(deck_t * d, card_t c) {
    for (int i = 0 ; i < d->n_cards; i++){
      if (d->cards[i]->value == c.value && d->cards[i]->suit == c.suit){
        return 1;
    }
   } 
  return 0;
  }
  
void shuffle(deck_t * d){
  card_t * temp;
  for (int i = 0;  i < d->n_cards ; i++) {
    int num = rand()%(d->n_cards);
    temp = (d->cards)[i] ; 
    (d->cards)[i] = (d->cards)[num];
    (d->cards)[num] = temp;
    }
}

void assert_full_deck(deck_t * d) {
  card_t * q;
  for (int i = 0 ; i < d->n_cards; i++){
    q = d->cards[i];
    assert_card_valid(* q);
  }
}
