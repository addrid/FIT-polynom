#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
  int *x; /*prvni polynom*/
  int *y; /*druhy polynom*/
  int a,b;                       /*stupne polynomu*/
  int i,j;
  int *vysl; /*vysledek po nasobeni koeficientu*/ 
  int pomocna;
  
  printf("Zadejte stupen polynomu A:\n");
  if(scanf("%d", &a)!=1 || a < 0)
  {
     printf("Nespravny vstup.\n");
     return 0;
  }
  
  x = (int*)malloc((a+1)*sizeof(int));
  printf("Zadejte koeficienty polynomu A:\n");
  for (i=0; i <= a; i++)
  {
     if(scanf("%d", &x[i])!=1)
     {
        printf("Nespravny vstup.\n");
        return 0;
     }
  }
  
  printf("Zadejte stupen polynomu B:\n");
  if(scanf("%d", &b)!=1 || b < 0)
  {
     printf("Nespravny vstup.\n");
     return 0;
  }
  
  y = (int*)malloc((b+1)*sizeof(int));
  printf("Zadejte koeficienty polynomu B:\n");
  for (i=0; i <= b; i++)
  {
     if(scanf("%d", &y[i])!=1)
     {
        printf("Nespravny vstup.\n");
        return 0;
     }
  }

   vysl = (int*)malloc((a+b+1)*sizeof(int));
  
   for(i=0;i<=a+b;i++)
   {
     vysl[i]=0;                   
   }
   
   for(i=0;i<=a;i++)
   {
      for(j=0;j<=b;j++)
      {
         vysl[i+j]+=x[i]*y[j];
      }
   }
   pomocna=a+b;
   for(i=0;i<=a+b;i++)
   {
      if(vysl[i]==0 && pomocna==0 && i==0)
      {
         printf("0\n");
         return 1;
      }               
      if(vysl[i]>0)
      {    /*koeficient je kladny*/  
         if(vysl[i]==1)
         {     
            if(pomocna>1) /*pomocna = exponent*/
            {
               if(i==0)
                  printf("x<sup>%d</sup>",pomocna);
               else
                  printf("+x<sup>%d</sup>",pomocna);
            }
            else
            {
               if(pomocna==1)
               {
                   if(i==0)
                      printf("x");
                   else
                      printf("+x");
               }
               else
               {
                   if(i==0)
                      printf("%d",vysl[i]);
                   else
                      printf("+%d",vysl[i]);
               }
            }
         }
         else /*kladnej koeficient, vetsi nez 1*/
         {
            if(pomocna>1)
            {
               if(i==0)
                  printf("%dx<sup>%d</sup>",vysl[i],pomocna);
               else
                  printf("+%dx<sup>%d</sup>",vysl[i],pomocna);
            }
            else
            {
                if(i==0)
                {
                  if(pomocna==1)
                      printf("%dx",vysl[i]);
                  if(pomocna==0)
                      printf("%d",vysl[i]);    
                }
                else
                {
                  if(pomocna==1)
                      printf("+%dx",vysl[i]);    
                  if(pomocna==0)
                      printf("+%d",vysl[i]);
                }
            }
         }
      }
      
      
      
      
      if(vysl[i]<0)
      {    /*koeficient je zaporny*/  
         if(vysl[i]==-1)
         {     
            if(pomocna>1) /*pomocna = exponent*/
            {
               printf("-x<sup>%d</sup>",pomocna);
            }
            else
            {
               if(pomocna==1)
               {
                   printf("-x");
               }
               else /*pomocna == 0*/
               {
                   printf("%d",vysl[i]);
               }
            }
         }
         else /*zapornej koeficient, mensi nez -1*/
         {
            if(pomocna>1)
            {
               printf("%dx<sup>%d</sup>",vysl[i],pomocna);
            }
            else
            {
               if(pomocna==1)
                   printf("%dx",vysl[i]);
               if(pomocna==0)
                   printf("%d",vysl[i]);
            }
         }
      }
      
      pomocna--;
   }
   
 printf("\n"); 
    
 free(x);
 free(y);
 free(vysl);
    
 return 0;
}
