#include <stdio.h>
#include <stdlib.h>

size_t maxSeq(int * array, size_t n){
      int temp_seq = 0;
      int  max_seq = 0;
    if ( n == 0){
      return 0;
    }
    if ( n == 1 ){
      return 1;
      }
    else{
       for (size_t i = 1; i < n; i+=1){
	 if ( array[i-1] < array[i] ){
	   max_seq += 1;
	   if ( max_seq > temp_seq ){
	     temp_seq = max_seq;
	   }
	    }
	 else{
	   max_seq = 0;
	     }}
       return temp_seq ;
    }}
		 

	 
   
