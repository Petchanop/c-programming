#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cards.h"


void assert_card_valid(card_t c) {
  assert(2 <= c.value && c.value <= 14);
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
  }
  return 0;}

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
  switch(value_let) {
  case '2' : temp.value = 2; break;
  case '3' : temp.value = 3; break;
  case '4' : temp.value = 4; break;
  case '5' : temp.value = 5; break;
  case '6' : temp.value = 6; break;
  case '7' : temp.value = 7; break;
  case '8' : temp.value = 8; break;
  case '9' : temp.value = 9; break;
  case '0' : temp.value = 10; break;
  case 'J' : temp.value = VALUE_JACK; break;
  case 'Q' : temp.value = VALUE_QUEEN; break;
  case 'K' : temp.value = VALUE_KING; break;
  case 'A' : temp.value = VALUE_ACE; break;
  default : temp.value = 0; }
  switch(suit_let) {
  case 's' : temp.suit = SPADES; break;
  case 'h' : temp.suit = HEARTS; break;
  case 'd' : temp.suit = DIAMONDS; break;
  case 'c' : temp.suit = CLUBS; break;
  default : temp.suit = 0; }
 
  return temp;
}


card_t card_from_num(unsigned c) {
  card_t temp;

  if (0 <= c && c < 52 )
    {
      
      if (0 <= c && c <= 12){
	temp.value = c + 2;
	temp.suit = SPADES;
      }
      if (12 < c && c <= 25){
	temp.value = c - 11;
	temp.suit = HEARTS;
      }
      if (25 < c && c <= 38){
	temp.value = c - 24;
	temp.suit = DIAMONDS;
      }
      if (38 < c && c < 52){
	temp.value = c - 37;
	temp.suit = CLUBS;
      }
    }
 
      return temp;
}
  
