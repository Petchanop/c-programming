#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include "cards.h"
#include "deck.h"
#include "eval.h"
#include "future.h"
#include "input.h"

int main(int argc, char ** argv) {
  //YOUR CODE GOES HERE
  if (argc > 3){
    fprintf(stdout,"Too many arguments");
    return EXIT_FAILURE;
  }
  FILE * f = fopen(argv[1],"r");
  future_cards_t * fc = malloc(sizeof(future_cards_t));
  fc->n_decks = 0;
  fc->decks = NULL;
  size_t n_hands = 0;
  deck_t ** hand = read_input(f,&n_hands,fc);
  fclose(f);
 //monte carlo
  int num_trials;
  if (argv[2] != NULL){
    num_trials = atoi(argv[2]);
  }
  else{
    num_trials = 10000;
  }
  int t = 0;
  int * arr = malloc((n_hands+1)*sizeof(*arr));
  int ar = 0;
  while ( ar <= n_hands){
    arr[ar] = 0;
    ar++;
  }
  deck_t * deck = build_remaining_deck(hand,n_hands);
  deck_t * Winner;
  // Ties->cards = NULL;
  // Ties->n_cards = 0;
  while (t < num_trials){
    shuffle(deck);
    future_cards_from_deck(deck,fc);
    Winner = hand[0];
    int wid = 0;
    for (int i = 1; i < n_hands ; i++){
      int comp = compare_hands(Winner,hand[i]);
      if (comp == -1){
     	Winner = hand[i];
	wid = i;
        }
      if (comp == 0){
	 wid = n_hands;
      }
    }
    arr[wid]++;
    t++;
	}
  
  for (size_t w = 0; w < n_hands ; w++){
  double  pro = (arr[w]/(float)t)*100;
  printf("Hand %zu won %u / %u times (%.2f%%)\n",w,arr[w],t,pro);
  }
  printf("And there were %u ties\n",arr[n_hands]);
  free(arr);
  free_deck(deck);
  for (int i = 0; i < n_hands; i++) {
    free_deck(hand[i]);
  }
  free(hand);
  for (int i = 0; i < fc->n_decks; i++) {
    free(fc->decks[i].cards);
  }
  free(fc->decks);
  free(fc);
  return EXIT_SUCCESS;
}
