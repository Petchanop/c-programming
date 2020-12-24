#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cards.h"


void assert_card_valid(card_t c) {
  assert(2 <= c.value && c.value <= VALUE_ACE);
  assert(SPADES == c.suit || c.suit == CLUBS
	 || c.suit == DIAMONDS || c.suit == HEARTS );
}

const char * ranking_to_string(hand_ranking_t r) {
  switch (r){
  case  STRAIGHT_FLUSH:return "STRAIGHT_FLUSH";
  case  FOUR_OF_A_KIND:return "FOUR_OF_A_KIND";
  case  FULL_HOUSE:return "FULL_HOUSE";
  case  FLUSH:return "FLUSH";
  case  STRAIGHT:return "STRAIGHT";
  case  THREE_OF_A_KIND:return "THREE_OF_A_KIND";
  case  TWO_PAIR:return "TWO_PAIR";
  case  PAIR:return "PAIR";
  case  NOTHING:return "NOTHING";
  }}

char value_letter(card_t c){

  if (2 <=  c.value && c.value  <= 9){
    printf("%d",c.value) ;

  }
  else{
    switch (c.value){
    case VALUE_ACE: printf("A");break;
    case VALUE_KING: printf("K");break;
    case VALUE_QUEEN: printf("Q");break;
    case VALUE_JACK: printf("J");break;
    case 10:  printf("0");break;
    default: printf("?");break;
    }}
  return 0; }



char suit_letter(card_t c) {

  switch (c.suit){
  case CLUBS: printf("c");break;
  case DIAMONDS: printf("d");break;
  case HEARTS: printf("h");break;
  case SPADES: printf("s");break;
  default: printf("?");break;
  }
  return 0;
}

void print_card(card_t c) {

  printf("%c%c\n",suit_letter(c),value_letter(c));
}

card_t card_from_letters(char value_let, char suit_let) {
  card_t temp;
  temp.value = value_let;
  temp.suit =suit_let;
  assert_card_valid(temp);
  temp.value = value_letter(temp);
  temp.suit = suit_letter(temp);
  return temp;
}

card_t card_from_num(unsigned c) {
  card_t temp;

  if (0 <= c && c < 52 )
    {
      temp.suit = c/13+1;
      if (0 <= c && c <= 12){
	temp.value = c + 2;
      }
      if (12 < c && c <= 25){
	temp.value = c - 11;
      }
      if (25 < c && c <= 38){
	temp.value = c - 24;
      }
      if (38 < c && c < 52){
	temp.value = c - 37;
      }

      return temp;
    }}
  
