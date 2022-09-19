#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct{
	int jour;
	int mois;
	int annee;
}Date;
typedef struct {
   char code[10];
   int prix;
   int quant;
   float pTTC;
   char name[10];
}Produit;   
typedef struct {
	Date d;
	float pTTC;
}Achat;
int pttc(int prix){
	int r;
	r = prix + ((prix*15)/100);
	return r;
}
Produit* saisie(Produit *E,int tmp,int N){
    int i;
    for(i=tmp;i<N;i++){
     printf("\nProduit %d: \n",i+1);
     printf("Code : ");
     scanf("%s",E[i].code);
     printf("Nom : ");
     scanf("%s",E[i].name);
	 printf("Prix : ");
     scanf("%d",&E[i].prix);
	 printf("Quantite : ");
     scanf("%d",&E[i].quant);
     E[i].pTTC=pttc(E[i].prix);
    }return E;
}   
Produit* saisieun(Produit *E,int N){
    int i=N-1;
     printf("\nProduit %d: \n",i+1);
     printf("Code : ");
     scanf("%s",E[i].code);
     printf("Nom : ");
     scanf("%s",E[i].name);
	 printf("Prix : ");
     scanf("%d",&E[i].prix);
	 printf("Quantite : ");
     scanf("%d",&E[i].quant);
     E[i].pTTC=pttc(E[i].prix);
    return E;
}
Produit* triprix(Produit *tab,int N){
        int c,i;
        do{
       c=0;
      for(i=0;i<N-1;i++){
        if(tab[i].prix<tab[i+1].prix){
           Produit tmp;
           tmp=tab[i];
           tab[i]=tab[i+1];
           tab[i+1]=tmp;
           c++;
        }
      }
    }while(c>0);
        return tab;
    }
Produit* triNOM(Produit *P,int N){
	int c,i;
        do{
       c=0;
      for(i=0;i<N-1;i++){
        if(P[i].name[0]>P[i+1].name[0]){
           Produit tmp;
           tmp=P[i];
           P[i]=P[i+1];
           P[i+1]=tmp;
           c++;
        }
      }
    }while(c>0);
	return P;
}
void affichage(Produit *P,int nbr,int T){
	   int i;
	   if(T==1){
	   	P = triprix(P,nbr);
	   }else P = triNOM(P,nbr);
    for(i=0;i<nbr;i++){
     printf("\n\tProduit %d: ",i+1);
     printf("\nCode : %s",P[i].code);
     printf("\nNom : %s",P[i].name);
	 printf("\nPrix : %d DH",P[i].prix);
	 printf("\nPrix TTC: %.2f DH",P[i].pTTC);
	 printf("\nQuantite : %d",P[i].quant);
    }
}       
Produit* Achatp(Produit *P,int N,char *code,int quant){
	int i,c;
	for(i=0;i<N;i++){
		if(strcmp(P[i].code, code)==0){
			c=1;
			P[i].quant= P[i].quant - quant;
		}
	}
	if(c==0){
		printf("\nVous avez entrer un code non valid !");
	}
	return P;
}
Achat* PAchat(Produit *P,Achat *A,char *code,int N,int quant){
	int i,c=0;
	for(i=0;i<N;i++){
		if(strcmp(P[i].code, code)==0){
			c=P[i].pTTC;
		}
	}
	int day, mois, an;
     time_t now;
     time(&now);
      struct tm *local = localtime(&now);
      day = local->tm_mday;
      mois = local->tm_mon + 1;
      an = local->tm_year + 1900;
		i=N-1;
		A[i].pTTC=c* quant;
		A[i].d.jour=day;
		A[i].d.mois=mois;
		A[i].d.annee=an;
		if(c!=0){
		printf("\nPrix TTC : %.2f",A[i].pTTC);
		printf("\nDate achat : %d/%d/%d",A[i].d.jour,A[i].d.mois,A[i].d.annee);
		}

	return A;
}
                                          
