#include <stdio.h>

double sum,x,denom=1;
main(int argc, char **argv){
   if (argc > 1) sscanf(argv[1],"%lf",&denom);
   while (1 == scanf("%lf",&x)) {
      sum += 1/x;
      printf("%f %f\n",x, sum);
   }
   printf("%0.4lf\n",sum/denom);
}
