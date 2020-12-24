#include "cards.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cards.c"
int main(void) {
 
    card_t c1;
    c1.value = 14;
    c1.suit = 2;
    assert_card_valid(card_t c1)
    print_card(c1);

    card_t c2;
    c2.value = 5;
    c2.suit = 1;
    assert_card_valid(card_t c2)
    print_card(c2);

    card_t c3;
    c3.value = 11;
    c3.suit = 3;
    assert_card_valid(card_t c3)
    print_card(c3);
    return EXIT_SUCCESS;
}
    
