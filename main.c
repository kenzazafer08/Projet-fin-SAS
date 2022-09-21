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
	int code;
	int quant;
	int Total;
	do {
		menu();
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
				saisieun(p,nbr);
				}else{
					nbr=nbr+1;
					p = realloc(p,nbr*sizeof(Produit));
					saisieun(p,nbr);
				}
				break;
			case 2 :
				printf("\nCombien de produit vous voulez saisie : ");
				scanf("%d",&NV);
	            if(nbr==0){
				nbr = NV;
				p = malloc(nbr*sizeof(Produit));
				saisie(p,0,nbr);
				}else{
					tmp=nbr;
					nbr=nbr+NV;
					p = realloc(p,sizeof(Produit)*nbr);
					saisie(p,tmp,nbr);
				}
				break;
			case 3 :
			    do{
				soumenu1();
                printf("\nVotre choix : ");
                scanf("%d",&Trie);
                switch(Trie){
                	case 1 :
							affichage(p,nbr,Trie);
                		break;
                	case 2 :
							affichage(p,nbr,Trie);
                		break;
					case 3 :
					    break;
                	default :
				        printf("\n\tChoix non valid !\n");
			        	break;
				}	
				}while (Trie!=3);
				break;
			case 4 :
				printf("Entrer le code de produit que vous voulez acheter : ");
				scanf("%d",&code);
                printf("Enter la quantite que vous voulez acheter : ");
                scanf("%d",&quant);
				if(checkproduit(p,nbr,code,quant)>=0){
				if(N==0){
			    N = 1;
			    A = malloc(N*sizeof(Achat));
			    PAchat(p,A,code,nbr,quant);
			    Achatp(p,nbr,code,quant);
			    }else{
			    N=N+1;
		     	A = realloc(A,N*sizeof(Achat));
		     	PAchat(p,A,code,nbr,quant);
		     	Achatp(p,nbr,code,quant);
		    	}
				}
				else printf("Code ou quantite non valid !");
				break;
			case 5 :
			    do{
                soumenu2();
                printf("\nVotre choix : ");
                scanf("%d",&Search);
                switch(Search){
                	case 1 :
						printf("Entrer le code de produit que vous voulez chercher : ");
				        scanf("%d",&code);
                        searchcode(p,nbr,code);
                		break;
                	case 2 :
						printf("Entrer la quantite de produit que vous voulez chercher : ");
				        scanf("%d",&quant);
						searchquant(p,nbr,quant);
                		break;
					case 3 :
					    break;
					default :
				        printf("\n\tChoix non valid !\n");
				        break;
				}
				}while(Search!=	3);  
				break;
			case 6 :
			    printf("Les produits dont la quantite est inferieure a 3 : ");
				etatstock(p,nbr);
				break;
			case 7 :
			    printf("Entrer le code de produit que vous voulez allimenter : ");
				scanf("%d",&code);
                printf("Enter la quantite : ");
                scanf("%d",&quant);
				alimenterstock(p,nbr,code,quant);
				break;
			case 8 :
			    printf("Entrer le code de produit que vous voulez supprimer : ");
				scanf("%d",&code);
				supprimer(p,nbr,code);
				free(&p[nbr-1]);
				nbr--;
				printf("\nDone !");
				break;
			case 9 :
			    do{
                soumenu3();
				printf("\nVotre choix : ");
                scanf("%d",&Vente);
                switch(Vente){
                	case 1 :
                    Total = total(A,N);
                    if(Total==0 ){
						printf("Aucune vente aujourd'hui");
					}else printf("Le total de prix des vente est %d DH",Total);
                		break;
                	case 2 :
					Total = total(A,N);
					if(Total==0 ){
						printf("Aucune vente aujourd'hui");
					}else printf("La moyenne des prix des vente est %.2f DH",moyenne(A,N));
                		break;
                	case 3 :
					Total = total(A,N);
					if(Total==0 ){
						printf("Aucune vente aujourd'hui");
					}else printf("Le Max des prix des produits vendus est %d DH",max(A,N));
                		break;
                	case 4 :
					Total = total(A,N);
					if(Total==0 ){
						printf("Aucune vente aujourd'hui");
					}else printf("Le Min des prix des produits vendus est %d DH",min(A,N));
                		break;
					case 5 :
					    break;
					default :
				      printf("\n\tChoix non valid !\n");
				      break;
				}
				 }while(Vente!=5);
				break;
			default :
				printf("\n\tChoix non valid !\n");
				break;
	}
	}while(choix!=0);
}
