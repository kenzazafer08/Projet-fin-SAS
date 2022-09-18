#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main(int argc, char *argv[]) {
	// menu variables
	int choix,T,V,S;
    //produit variables
    Produit *P;
    Achat *A;
    int N=0,i;
	int NA,D,M;
	int  code;
    int quant; 
	do {
		printf("\n\t---Menu principale---");
		printf("\nPour inserer un nouveaux produit Entrer 1 : ");
		printf("\nPour inserer plusieurs nouveaux produits Entrer 2 : ");
		printf("\nPour afficher la liste des produit Entrer 3 : ");
		printf("\nPour acheter un produit Entrer 4 : ");
		printf("\nPour rechercher un produit Entrer 5 : ");
		printf("\nPour alimenter le stock Entrer 6 : ");
		printf("\nPour supprimer un produit Entrer 7 : ");
		printf("\nPour afficher les statistique de vente en journée courante Entrer 8 : ");
		printf("\nPour quitter Entrer 0 : \n");
		scanf("%d",&choix);
		switch(choix){
			case 0 : 
				printf("done !");
				break;
			case 1 : 
			//Ajouter une case pour inserer un nouveau produit
			if(N==0){
			N=N+1;
			P = malloc(N*sizeof(Produit));
			P = saisieone(P,N);
			}else{
			N=N+1;
			P = realloc(P,N);
			P = saisieone(P,N);
			}
				break;
			case 2 :
			printf("Combien de produit vous voulez ajouter ? ");
			scanf("%d",&D);
			if(N==0){
			M=N;
			N=D;
			P = malloc(N*sizeof(Produit));
			P = saisieall(P,N,M);
			}else{
			M=N;
			N=M+D;
			P = realloc(P,N);
			P = saisieall(P,N,M);
			}
		
				break;
			case 3 :
				printf("\nOrdre alphabétique croissant du nom 1 : ");
                printf("\nOrdre décroissant du prix 2 : ");
                scanf("%d",&T);
                switch(T){
                	case 1 :
                		printf("LE nombres des produit est : %d",N);
                		affichage(P,N,1);
                		break;
                	case 2 :
                		printf("LE nombres des produit est : %d",N);
                		affichage(P,N,0);
                		break;
				}
				break;			
			case 4 :
				printf("Entrer le code de produit que vous voulez acheter : ");
				scanf("%d",&code);
                printf("Enter la quantité que vous voulez acheter : ");
                scanf("%d",&quant);
                if(N==0){
			    NA=NA+1;
			    A = malloc(NA*sizeof(Achat));
			    A = PAchat(P,A,code,N);
			    P = Achatp(P,N,code,quant);
			    }else{
			    NA=NA+1;
		     	A = realloc(A,NA);
		     	A = PAchat(P,A,code,N);
		     	P = Achatp(P,N,code,quant);
		    	}
                printf("Done !");
				break;
			case 5 :
				printf("\nChercher par code 1 : ");
                printf("\nChercher par quantité 2 : ");
                scanf("%d",&S);
                switch(S){
                	case 1 :
                	printf("Entrer le code de produit que vous voulez chercher : ");
				    scanf("%d",&code);
				    searchcode(P,code,N);
                		break;
                	case 2 :
                	printf("Entrer la qantite de produit que vous voulez chercher : ");
				    scanf("%d",&quant);
				    searchquant(P,quant,N);
                		break;
				}
				break;
			case 6 :
				break;
			case 7 :
				break;
			case 8 :
				printf("\nAfficher le total des prix des produits vendus en journée courante 1 : ");
                printf("\nAfficher la moyenne des prix des produits vendus en journée courante 2 : ");
                printf("\nAfficher le Max des prix des produits vendus en journée courante 3 : ");
                printf("\nAfficher le Min des prix des produits vendus en journée courante 4 : ");
                scanf("%d",&V);
                switch(V){
                	case 1 :
                		break;
                	case 2 :
                		break;
                	case 3 :
                		break;
                	case 4 :
                		break;
				}
				break;
	}
	}
	while(choix!=0);
	return 0;
}
