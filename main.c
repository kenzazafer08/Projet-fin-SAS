#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

void main() {
	// menu variables
	int choix,Trie,Vente,Search;
    //produit variables
    int nbr=0,NV,tmp;
	Produit *p;
	Achat *A;
	int N=0;
	char code[10];
	int quant;
	do {
		printf("\n\t---Menu principale---");
		printf("\nPour inserer un nouveaux produit Entrer 1 : ");
		printf("\nPour inserer plusieurs nouveaux produits Entrer 2 : ");
		printf("\nPour afficher la liste des produit Entrer 3 : ");
		printf("\nPour acheter un produit Entrer 4 : ");
		printf("\nPour rechercher un produit Entrer 5 : ");
		printf("\nPour afficher l'etat de stock Entrer 6 : ");
		printf("\nPour alimenter le stock Entrer 7 : ");
		printf("\nPour supprimer un produit Entrer 8 : ");
		printf("\nPour afficher les statistique de vente en journée courante Entrer 9 : ");
		printf("\nPour quitter Entrer 0 : ");
		printf("\nVotre choix : ");
		scanf("%d",&choix);
		switch(choix){
			case 0 :
				printf("done !");
				break;
			case 1 :
			//Ajouter une case pour inserer un nouveau produit
				if(nbr==0){
				nbr=1;
				p = malloc(nbr*sizeof(Produit));
				p = saisieun(p,nbr);
				}else{
					nbr=nbr+1;
					p = realloc(p,nbr*sizeof(Produit));
					p = saisieun(p,nbr);
				}
				break;
			case 2 :
				printf("\nCombien de produit vous voulez saisie : ");
				scanf("%d",&NV);
	            if(nbr==0){
				nbr = NV;
				p = malloc(nbr*sizeof(Produit));
				p = saisie(p,1,nbr);
				}else{
					tmp=nbr;
					nbr=nbr+NV;
					p = realloc(p,sizeof(Produit)*nbr);
					p = saisie(p,tmp,nbr);
				}
				break;
			case 3 :
				printf("\nOrdre alphabétique croissant du nom 1 : ");
                printf("\nOrdre décroissant du prix 2 : ");
                printf("\nVotre choix : ");
                scanf("%d",&Trie);
                switch(Trie){
                	case 1 :
							affichage(p,nbr,Trie);
                		break;
                	case 2 :
							affichage(p,nbr,Trie);
                		break;
                	default :
				        printf("\n\tChoix non valid !\n");
			        	break;
				}
				break;
			case 4 :
				printf("Entrer le code de produit que vous voulez acheter : ");
				scanf("%s",code);
                printf("Enter la quantité que vous voulez acheter : ");
                scanf("%d",&quant);
				if(N==0){
			    N = 1;
			    A = malloc(N*sizeof(Achat));
			    A = PAchat(p,A,code,nbr,quant);
			    p = Achatp(p,nbr,code,quant);
			    }else{
			    N=N+1;
		     	A = realloc(A,N*sizeof(Achat));
		     	A = PAchat(p,A,code,nbr,quant);
		     	p = Achatp(p,nbr,code,quant);
		    	}
				break;
			case 5 :
	            printf("\nChercher par code 1 : ");
                printf("\nChercher par quantité 2 : ");
                printf("\nVotre choix : ");
                scanf("%d",&Search);
                switch(Search){
                	case 1 :
						printf("Entrer le code de produit que vous voulez chercher : ");
				        scanf("%d",&code);

                		break;
                	case 2 :
						printf("Entrer le code de produit que vous voulez chercher : ");
				        scanf("%d",&code);
                		break;
					default :
				        printf("\n\tChoix non valid !\n");
				        break;
				}
				break;
			case 6 :
				break;
			case 7 :
				break;
			case 8 :
				break;
			case 9 :
				printf("\nAfficher le total des prix des produits vendus en journée courante 1 : ");
                printf("\nAfficher la moyenne des prix des produits vendus en journée courante 2 : ");
                printf("\nAfficher le Max des prix des produits vendus en journée courante 3 : ");
                printf("\nAfficher le Min des prix des produits vendus en journée courante 4 : ");
                printf("\nVotre choix : ");
                scanf("%d",&Vente);
                switch(Vente){
                	case 1 :
                		break;
                	case 2 :
                		break;
                	case 3 :
                		break;
                	case 4 :
                		break;
					default :
				      printf("\n\tChoix non valid !\n");
				      break;
				}
				break;
			default :
				printf("\n\tChoix non valid !\n");
				break;
	}
	}
	while(choix!=0);
}
