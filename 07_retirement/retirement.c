#include <stdio.h>
#include <stdlib.h>

struct _retire_{
  int months;
  double contribution;
  double rate_of_return;
}_retire_;
typedef struct _retire_ retire_info;
  

void retirement(int startAge,double initial,retire_info r,retire_info s) {
  double accReturns ;
  int i,j;
  for (i = startAge  ; i < startAge + r.months ; i += 1) {
    printf("Age %3d month %2d you have $%.2lf\n",i/12 ,(i % 12),initial);
    accReturns = initial + (initial * r.rate_of_return) + r.contribution;
    initial = accReturns;
  }
  for (j = startAge+r.months  ; j < startAge+r.months+s.months  ; j += 1) {
    printf("Age %3d month %2d you have $%.2lf\n",j/12 ,(j % 12),initial);
    accReturns = initial + (initial * s.rate_of_return) + s.contribution;
    initial = accReturns;
  }
}
int main(){
  retire_info working;
  working.months = 489;
  working.contribution = 1000;
  working.rate_of_return = 0.045/12;

  retire_info retired;
  retired.months = 384;
  retired.contribution = -4000;
  retired.rate_of_return = 0.01/12;
  retirement(327,21345,working,retired);
  return 0;
    }
   

