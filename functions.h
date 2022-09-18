#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//Structure des produits
typedef struct{
        int jour;
        int mois;
        int annee;
    }Date;
typedef struct{
	int Quant;
	int prix;
    float pTTC;
	int code;
	char nom[10];
}Produit;

typedef struct{
	float pTTC;
    Date date;
}Achat;

//Fonction de l'insertion d'un seul produit
Produit* saisieone(Produit *P,int N){
	int i;
		i=N-1; //pour ajouter le produit dans la dernier case
		printf("\n\tEntrer les information du produit %d ! \n",i+1);	
		//Lire les information du produit

		printf("Code : ");
		scanf("%d",&P[i].code);
		printf("nom : ");
		scanf("%s",P[i].nom);
		printf("Prix : ");
		scanf("%d",&P[i].prix);
		printf("Quantité : ");
		scanf("%d",&P[i].Quant);
		P[i].pTTC=(P[i].prix*15)/100;
		
		printf("\n\tMerci ! \n");
	return P;
}

//Fonction de l'insertion de plusieurs produits
Produit* saisieall(Produit *P,int N,int M){
	int i;//pour ajouter les produit dans les derniers cases
	
	for(i=M;i<N;i++){
		printf("\n\tEntrer les information du produit %d ! \n",i+1);	
		//Lire les information du produit	
		printf("Code : ");
		scanf("%d",&P[i].code);
		printf("nom : ");
		scanf("%s",P[i].nom);
		printf("Prix : ");
		scanf("%d",&P[i].prix);
		printf("Quantité : ");
		scanf("%d",&P[i].Quant);
		P[i].pTTC=(P[i].prix*15)/100;
	}	
		printf("\n\tMerci ! \n");
	return P;
}
Produit* triprix(Produit *P,int N){
	int c,i;
        do{
       c=0;
      for(i=0;i<N-1;i++){
        if(P[i].prix>P[i+1].prix){
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
Produit* triNOM(Produit *P,int N){
	int c,i;
        do{
       c=0;
      for(i=0;i<N-1;i++){
        if(P[i].nom[0]>P[i+1].nom[0]){
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
void affichage(Produit *E,int N,int t){
int i;
if(t==1){E = triprix(E,N);
}else E = triNOM(E,N);
    for(i=0;i<N;i++){
        printf("\n\tProduit %d: ",i+1);
        printf("\nNom : %s",E[i].nom);
        printf("\nCode : %d",E[i].code);
        printf("\nPrix : %d",E[i].prix);
        printf("\nPrix TTC: %.2f",E[i].pTTC);
        printf("\nQuantité : %d",E[i].Quant);
    }
}
Produit* Achatp(Produit *P,int N,int code,int quant){
	int i,c;
	for(i=0;i<N;i++){
		if(P[i].code==code){
			c=1;
			P[i].Quant= P[i].Quant - quant;
		}
	}	
	if(c==0){
		printf("\nVous avez entrer un code non valid !");
	}
	return P;
}
Achat* PAchat(Produit *P,Achat *A,int code,int N){
	int i,c=0;
	for(i=0;i<N;i++){
		if(P[i].code==code){
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
		A[i].pTTC=c;
		A[i].date.jour=day;
		A[i].date.mois=mois;
		A[i].date.annee=an;
		printf("\nPrix TTC : %d",A[i].pTTC);
		printf("\nDate achat : %d/%d/%d",A[i].date.jour,A[i].date.mois,A[i].date.annee);
	return A;
}
void searchcode(Produit *P,int code,int N){
    Produit PS;
	int i,c=0;
	for(i=0;i<N;i++){
		if(P[i].code==code){
			c=1;
			PS = P[i];
	}	
	if(c==0){
		printf("Pas de poduit avec ce code !");
		
	}else{
				    printf("\n\tProduit trouver ");
                    printf("\nNom : %s",PS.nom);
                    printf("\nPrix : %d",PS.prix);
                    printf("\nPrix TTC: %.2f",PS.pTTC);
                    printf("\nQuantité : %d",PS.Quant);
	}
}}

void searchquant(Produit *P,int quant,int N){
    Produit PS;
	int i,c=0;
	for(i=0;i<N;i++){
		if(P[i].Quant==quant){
			c=1;
			PS = P[i];
	}	
	if(c==0){
		printf("Pas de poduit avec ce code !");
		
	}else{
				    printf("\n\tProduit trouver ");
                    printf("\nNom : %s",PS.nom);
                    printf("\nPrix : %d",PS.prix);
                    printf("\nPrix TTC: %.2f",PS.pTTC);
                    printf("\nQuantité : %d",PS.Quant);
	}
}}
