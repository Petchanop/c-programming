#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "deck.h"

void add_card_to(deck_t * deck, card_t c){
  deck->cards = realloc(deck->cards,(deck->n_cards+1)*sizeof(*deck->cards));
  card_t * ptrc = &c;
  deck->cards[deck->n_cards] = ptrc;
}

card_t * add_empty_card(deck_t * deck){
           card_t  empty;
	   empty.value = 0;
	   empty.suit = 0;
add_card_to(deck,empty);
return deck->cards[deck->n_cards];
}       

deck_t * make_deck_exclude(deck_t * excluded_cards){
  deck_t * ex = malloc(sizeof(*ex));
for (int i = 0 ; i < 52;i++){
  card_t add = card_from_num(i);
  if (deck_contains(excluded_cards,add)!= 1){
     add_card_to(ex,add);
  }
 }
return ex;
}
        
deck_t * build_remaining_deck(deck_t ** hands, size_t n_hands){
     deck_t * build = make_deck_exclude(*hands);
     return build;
}
  
void free_deck(deck_t * deck){
  free(deck->cards);
  free(deck);
}
  
void print_hand(deck_t * hand){
 
  for (size_t i  = 0; i < hand->n_cards ; i++){
    print_card(*hand->cards[i]);
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
