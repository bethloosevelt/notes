#include <stdio.h>
#include "util.h"


int main(){
int tst_num=1;
int npassed=0;
int nfailed=0;


    
  if(abs_diff(5.0, 3.0) != 2.0){
	printf("test %i failed\n", tst_num);
	nfailed++;
  }
  else {
	npassed++;
  }
  tst_num++;

  if(median3(1, 2, 3) != 2) {
	printf("test %i failed\n", tst_num);
	nfailed++;
  }
  else {
	npassed++;
  }
  tst_num++;

  if(sqrt_floor(4) != 2) {
	printf("test %i failed\n", tst_num);
	nfailed++;
  }
  else {
	npassed++;
  }
  tst_num++;

  if(num_ones(2) != 1) {
	printf("test %i failed\n", tst_num);
	nfailed++;
  }
  else {
	npassed++;
  }

  printf("num_tests:     %i\n", tst_num);
  printf("num_passed:    %i\n", npassed);
  printf("num_failed:    %i\n", nfailed);


}
