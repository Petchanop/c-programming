#include "cards.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cards.c"
int main(void) {
 
    card_t c1;
    c1.value = 14;
    c1.suit = 2;
    assert_card_valid(c1);   
    print_card(c1);

    card_t c2;
    c2.value = 5;
    c2.suit = 1;
    print_card(c2);

    card_t c3;
    c3.value = 11;
    c3.suit = 3;
   
    print_card(c3);

    card_t c4 = card_from_num(51);
    assert_card_valid(c4);
    print_card(c4);

    card_t c5 = card_from_letters('9','d');
    print_card(c5);

   
       return EXIT_SUCCESS;
}
    
