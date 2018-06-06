#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

//#define P 100000127
#define P 1000081
#define PREF 30000
#define delta .004  //best for trec05p-1
#define delta2 .004
#define bump .01
//#define delta .002

float w[P],score, prob, prob2;
char dun[P];

comp(unsigned *a, unsigned *b){
   if (*a < *b) return -1;
   if (*a > *b) return 1;
   return 0;
}

char judge[100], file[100];
unsigned char buf[PREF];
unsigned b,h;
int i,j,k,n;
int isspam;
unsigned toks[100000], ntoks;
FILE *of, *testf, *trainf;

main(int argc, char **argv){
   //testf=fopen(argv[2],"w");
   //trainf=fopen(argv[1],"w");
   while (2 == scanf("%s%s",judge,file)){
      FILE *f = fopen(file,"r");
      if (!f) {
         perror(file);
         exit(1);
      }
      if (!strcasecmp(judge,"spam")) isspam = 1;
      else if (!strcasecmp(judge,"ham")) isspam = 0;
      else isspam = -1;
      n = fread(buf,1,PREF,f);
      fclose(f);
      if (n < 4) {
         strcpy(buf,"    ");
         n = 4;
      }
// pass 1
      score = 0; ntoks=0;
      b = (buf[0]<<16) | (buf[1]<<8) | buf[2];
      for (i=3;i<n;i++){
         b = (b<<8) | buf[i];
         h = b % P;
         if (dun[h]) continue;
         dun[h] = 1;
         //printf("%c%c%c%c\n",b>>24,b>>16,b>>8,b);
         toks[ntoks++] = h;
      }
      //prob = 1/(1+exp(-score));
      //if (score > 0) prob2 = 1/(1+exp(-score-bump));
      //else prob2 = 1/(1+exp(-score+bump));
      //printf("%s judge=%s class=%s score=%0.5lf %0.5lf\n",file,judge,score>0?"spam":"ham",score,prob);
      qsort(toks,ntoks,sizeof(unsigned),comp);
      //if (!strcmp(judge,"Ham") || !strcmp(judge,"Spam")) of=testf; else of=trainf;
      //fprintf(of,"%d",isspam*2-1);
      of = stdout;
      fprintf(of,"%s",file);
      for (i=0;i<ntoks;i++) fprintf(of," %d:1",toks[i]+1);
      fprintf(of,"\n");
      //fflush(of);
// pass 2
      b = (buf[0]<<16) | (buf[1]<<8) | buf[2];
      for (i=3;i<n;i++){
         b = (b<<8) | buf[i];
         h = b % P;
         if (dun[h]) {
            dun[h] = 0;
         }
      }
   }
}
