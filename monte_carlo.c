#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

float mc_pi(int);

float frandom() {
  long int q = random();
  float ret = (float)q/(float)RAND_MAX;
  return ret;
}

int main(void) {
  float pi0;
  float pi1;
  
  pi0 = mc_pi(25000);
  pi1 = mc_pi(25000);
  printf("%f %f\n", pi0, pi1);
  
  if (pi0 == pi1) {
      printf("Two separate estimates of pi are exactly the same. This is unlikely.\n");
      abort();
    }

  if (fabs(pi0 - pi1) > 0.05) {
      printf("Two separate estimates %f and %f are too different.\n", pi0, pi1);
      abort();
  }

    
  for (int i=2000; i<5000; i++) {
    pi0 = mc_pi(i);
    if (!(fabs(pi0 - M_PI) < 0.4)) {
      printf("Estimate with even %d iterations is %f which is not accurate enough.\n", i, pi0);
      abort();
    }
  }
} 

float mc_pi(int i ){ 
  float x,y,z ; 
  int squ = 0;
  int cir = 0;
  float pi; 
  
  while (i>0) { 
    x = frandom() ;
    y = frandom() ;
    z = x*x + y*y ;
    if (z<=1) { 
      squ++; 
      cir++;
    } 
    else { 
      squ++; 
    } 
    i--; 
  } 
  pi = 4*(float)(cir)/squ;
  reurn pi;
}
     

