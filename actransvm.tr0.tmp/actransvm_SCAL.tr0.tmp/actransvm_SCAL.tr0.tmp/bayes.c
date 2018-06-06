#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define PREF 30000
//#define P 100000127
#define P 1100000
#define N 30
#define eps 1.0
int cnt[P][2];
int dotrain, doprint;

char judge[100], file[200];
unsigned char buf[PREF];
int i,j,k,n;
unsigned b,h;
int isspam;
double tot[2];

double spammy[N], hammy[N], ratio, weight, sv[N], hv[N];
double hamscore, spamscore;
int nspammy, nhammy;
int nfv,F,V,Cnt;

main(){
   tot[0] = tot[1] = 10*eps;
   nfv = scanf("%d",&F);
   while (nfv == 1){
      if (F == 0) strcpy(judge,"Ham");
      else if (F == -1) strcpy(judge,"ham");
      else strcpy(judge,"spam");
      dotrain = strcmp(judge,"Ham") && strcmp(judge,"Spam");
      doprint = strcmp(judge,"SPAM") && strcmp(judge,"HAM");
      isspam = !strcasecmp(judge,"spam");
      //printf("%s %d\n",judge,isspam);
// pass 1
   if (!strcmp(judge,"Ham")) { 
      sprintf(file,"%6d\t",++Cnt);
      nspammy = nhammy= 0;
      while (2 == (nfv = scanf("%d:%d",&F,&V))) {
         h = F;
         if (cnt[h][isspam] < 0) continue;
         if (cnt[h][0]<0 || cnt[h][1]<0) printf("oops %d %d\n",cnt[h][0],cnt[h][1]);
         ratio = (cnt[h][1]+eps)/(cnt[h][0]+eps) * tot[0]/tot[1];
         //printf("num %d den %d tot %lg %lg\n",(cnt[h][1]),(cnt[h][0]),tot[1],tot[0]);
         //printf("%c%c%c%c: %d %lg\n",b>>24,b>>16,b>>8,b,cnt[h][isspam],ratio);
         for (k=0;k<nspammy && ratio > spammy[k];k++){}
         if (nspammy < N) {
            for (j=nspammy++;j>k;j--) {spammy[j] = spammy[j-1]; sv[j] = sv[j-1];}
            spammy[k] = ratio; sv[k] = 1.0/tot[0] + 1.0/tot[1] + 1.0/(eps+cnt[h][1]) + 1.0/(eps+cnt[h][0]);
            //printf("svk %lg %lg %lg %lg %lg \n",sv[k],1.0/tot[0] , 1.0/tot[1] , (eps+cnt[h][1]) , (eps+cnt[h][0]));
            //printf("cnts %d %d %lg %lg\n",cnt[h][1], cnt[h][0],1/(eps+cnt[h][1]),1/(eps+cnt[h][0]));
            //printf("spam insert %d %lg\n",k-1,ratio);
         } else if (k > 0) {
            for (j=0;j<k;j++) {spammy[j] = spammy[j+1]; sv[j] = sv[j+1];}
            spammy[k-1] = ratio; sv[k-1] = 1.0/tot[0] + 1.0/tot[1] + 1.0/(eps+cnt[h][1]) + 1.0/(eps+cnt[h][0]);
            //printf("spam insert %d %lg\n",k,ratio);
            //printf("svkm1 %lg\n",sv[k-1]);
         }
         for (k=0;k<nhammy && ratio < hammy[k];k++){}
         if (nhammy < N) {
            for (j=nhammy++;j>k;j--) {hammy[j] = hammy[j-1]; hv[j] = hv[j-1];}
            hammy[k] = ratio; hv[k] = 1.0/tot[0] + 1.0/tot[1] + 1.0/(eps+cnt[h][1]) + 1.0/(eps+cnt[h][0]);
            //printf("ham insert %d %lg\n",k,ratio);
         } else if (k > 0) {
            for (j=0;j<k;j++) {hammy[j] = hammy[j+1]; hv[j] = hv[j+1];}
            hammy[k-1] = ratio; hv[k-1] = 1.0/tot[0] + 1.0/tot[1] + 1.0/(eps+cnt[h][1]) + 1.0/(eps+cnt[h][0]);
            //printf("ham insert %d %lg\n",k,ratio);
         }
         //cnt[h][isspam] = - cnt[h][isspam] - 1;
      }
      //printf("nspammy %d nhammy %d\n",nspammy, nhammy);
      hamscore = spamscore = ratio = 0; weight = 0;
      for (i=0;i<nspammy;i++){
         //printf("spammy: %lg\n",spammy[i]);
         spamscore += log(spammy[i]);
         //printf("sp %lg var %lg %lg %lg\n",spammy[i],sv[i],ratio,weight);
      }
      spamscore /= nspammy;
      for (i=0;i<nhammy;i++){
         //printf("hammy: %lg\n",hammy[i]);
         hamscore += log(hammy[i]);
         //printf("%lg %lg\n",ratio,weight);
      }
      hamscore /= nhammy;
      ratio = hamscore + spamscore;
      if (doprint) printf("%s%0.5lf\n",file,ratio);
      //printf("%d %s judge=%s class=%s score=%0.5lf\n",dotrain,file,judge,ratio>0?"spam":"ham",ratio/nspammy);

   } else {
// pass 2
      tot[isspam]++;
      while (2 == (nfv = scanf("%d:%d",&F,&V))) cnt[F][isspam]++;
   }
  }
}
