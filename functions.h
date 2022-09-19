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
}Produit;
typedef struct {
    char code[10];
    int prix;
    int quant;
	Date d;
	float pTTC;
    char name[10];
}Achat;
int pttc(int prix){
	int r;
	r = prix + ((prix*15)/100);
	return r;
}
Date today(){
    Date d;
    int day, mois, an;
     time_t now;
     time(&now);
      struct tm *local = localtime(&now);
      day = local->tm_mday;
      mois = local->tm_mon + 1;
      an = local->tm_year + 1900;
      d.jour=day;
      d.mois=mois;
      d.annee=an;
      return d;
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
}
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
        if(strcmp(P[i].name,P[i+1].name)>0){
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
       if(nbr==0){
        printf("Aucun produit");
       }else {
        if(T==1){
	   	P = triNOM(P,nbr);
	   }else P = triNOM(P,nbr);
    for(i=0;i<nbr;i++){
     printf("\n\tProduit %d: ",i+1);
     printf("\nCode : %s",P[i].code);
     printf("\nNom : %s",P[i].name);
	 printf("\nPrix : %d DH",P[i].prix);
	 printf("\nQuantite : %d",P[i].quant);
    }
       }
	    
    }
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
	int i,c=0,p,q;
    char *n;
	for(i=0;i<N;i++){
		if(strcmp(P[i].code, code)==0){
			c=P[i].pTTC;
            n=P[i].name;
            p=P[i].prix;
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
		A[i].pTTC=c;
        A[i].prix=p;
        code = strcpy(A[i].code,code);
        n = strcpy(A[i].name,n);
		A[i].d.jour=day;
		A[i].d.mois=mois;
		A[i].d.annee=an;
		if(c!=0){
        printf("Produit acheter : ");
        printf("\nCode : %s",code);
        printf("\nNom : %s",n);
	    printf("\nPrix : %d DH",A[i].prix);
	    printf("\nQuantite : %d",quant);
		printf("\nPrix TTC : %.2f DH",A[i].pTTC);
		printf("\nDate achat : %d/%d/%d",A[i].d.jour,A[i].d.mois,A[i].d.annee);
		}

	return A;
}
void searchcode(Produit *P,int N,char *code){
    int i,D=0,C=0;
    Produit *PS;
    for(i=0;i<N;i++){
        if(strcmp(P[i].code,code)==0){
            C=C+1;
            if(D==0){
                D=D+1;
                PS = malloc(D*sizeof(Produit));
            }else {
                D=D+1;
                PS = realloc(PS,D*sizeof(Produit));
            }
            PS[i]=P[i];
        }
    }
    if(C==0){
        printf("\nAucun produit trouver ! ");
    }else {
        printf("\n\tLes produit trouver :  ");
        for(i=0;i<D;i++){
            printf("\n\tProduit %d: ",i+1);
            printf("\nCode : %s",PS[i].code);
            printf("\nNom : %s",PS[i].name);
	        printf("\nPrix : %d DH",PS[i].prix);
	        printf("\nQuantite : %d",PS[i].quant);
        }
    }
}
void searchquant(Produit *P,int N,int quant){
    int i,D=0,C=0;
    Produit *PS;
    for(i=0;i<N;i++){
        if(P[i].quant==quant){
            C=C+1;
            if(D==0){
                D=D+1;
                PS = malloc(D*sizeof(Produit));
            }else {
                D=D+1;
                PS = realloc(PS,D*sizeof(Produit));
            }
            PS[i]=P[i];
        }
    }
    if(C==0){
        printf("\nAucun produit trouver ! ");
    }else {
        printf("\n\tLes produit trouver :  ");
        for(i=0;i<D;i++){
            printf("\n\tProduit %d: ",i+1);
            printf("\nCode : %s",PS[i].code);
            printf("\nNom : %s",PS[i].name);
	        printf("\nPrix : %d DH",PS[i].prix);
	        printf("\nQuantite : %d",PS[i].quant);
        }
    }
}
void etatstock(Produit *P,int N){
    int i,D=0,C=0;
    Produit *PS;
    for(i=0;i<N;i++){
        if(P[i].quant < 3){
            C=C+1;
            if(D==0){
                D=D+1;
                PS = malloc(D*sizeof(Produit));
            }else {
                D=D+1;
                PS = realloc(PS,D*sizeof(Produit));
            }
            PS[i]=P[i];
        }
    }
    if(C==0){
        printf("\nAucun produit ! ");
    }else {
        for(i=0;i<D;i++){
            printf("\n\tProduit %d: ",i+1);
            printf("\nCode : %s",PS[i].code);
            printf("\nNom : %s",PS[i].name);
	        printf("\nPrix : %d DH",PS[i].prix);
	        printf("\nQuantite : %d",PS[i].quant);
        }
    }
}
Produit* alimenterstock(Produit *P,int N,char *code,int quant){
    int i,c=0;
    for(i=0;i<N;i++){
        if(strcmp(P[i].code,code)==0){
            c=c+1;
            P[i].quant=P[i].quant+quant;
        }if(c==0){
            printf("\nCode invalid !");
        }else printf("\nDone !");
    }return P;
}
Produit* supprimer(Produit *P,int N,char *code){
    int i,j,c=0;
    for(i=0;i<N;i++){
        if(strcmp(P[i].code,code)==0){
            c=c+1;
            for(j=i;j<N;j++){
               P[i]=P[i+1]; 
            }

}
}if(c==0){
    printf("Code invalid ! ");
}else printf("Done !");
    return P;
}
Achat* achartoday(Achat *A,int N){
    Achat *AT;
    Date d;
    int i,j=0,T=0,C;
    d=today();
    for(i=0;i<N;i++){
        if((A->d.jour==d.jour) && (A->d.mois==d.mois) && (A->d.annee==d.annee)){
           C=C+1;
            if(T==0){
                T=T+1;
                AT = malloc(T*sizeof(Produit));
            }else {
                T=T+1;
                AT = realloc(AT,T*sizeof(Produit));
            }
            AT[j]=A[i];
            j++;
        }
    }return AT;
}
int total(Achat *A,int N){
    Date d;
    int i,T=0;
    int p;
    d=today();
    for(i=0;i<N;i++){
        if((A->d.jour==d.jour) && (A->d.mois==d.mois) && (A->d.annee==d.annee)){
            p=A[i].prix;
           T=T+p;
        }
    }return T;
}
float moyenne(Achat *A,int N){
    float M;
    M=total(A,N)/N;
    return M;
}
int max(Achat *A,int N){
    int max,i;
    A = achartoday(A,N);
    max = A[0].prix;
    for(i=0;i<N;i++){
        if(A[i].prix > max){
            max = A[i].prix;
        }
    } 
    return max;
}
int min(Achat *A,int N){
    int min,i;
    A = achartoday(A,N);
    min = A[0].prix;
    for(i=0;i<N;i++){
        if(A[i].prix < min){
            min  = A[i].prix;
        }
    } 
    return min;
}