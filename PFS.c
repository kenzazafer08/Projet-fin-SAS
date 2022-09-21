#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct{
	int day;
	int mois;
	int year;
}Date;
typedef struct{
	int code;
	char nom[10];
	int quant;
	int prix;
	int pTTC;
}Produit;
typedef struct{
	Produit p;
	Date d;
}Achat;
//Ajouter un produit
void saisiun(Produit *p,int NP){
	printf("\n\t---Produit %d---",NP);
	printf("\nNom : ");
	scanf("%s",p[NP-1].nom);
	printf("Prix : ");
	scanf("%d",&p[NP-1].prix);
	printf("Quantite : ");
	scanf("%d",&p[NP-1].quant);
	p[NP-1].pTTC=p[NP-1].prix +((p[NP-1].prix * 15)/100);
	p[NP-1].code = NP;
}
//Ajouter plusieurs produits
void saisi(Produit *p,int NP,int tmp){
	int i;
	for(i=tmp;i<NP;i++){
	printf("\n\t---Produit %d---",i+1);
	printf("\nNom : ");
	scanf("%s",p[i].nom);
	printf("Prix : ");
	scanf("%d",&p[i].prix);
	printf("Quantite : ");
	scanf("%d",&p[i].quant);
	p[i].pTTC=p[i].prix +((p[i].prix * 15)/100);
	p[i].code = i+1;
    }
}
//Tri par prix
void Triprix(Produit *tab,int N){
        int c,i;
        do{
       c=0;
      for(i=0;i<N-1;i++){
        if(tab[i].prix < tab[i+1].prix){
           Produit tmp;
           tmp=tab[i];
           tab[i]=tab[i+1];
           tab[i+1]=tmp;
           c++;
        }
      }
    }while(c>0);
    }
//Tri par nom
void Trinom(Produit *tab,int N){
        int c,i;
        do{
       c=0;
      for(i=0;i<N-1;i++){
        if(strcmp(tab[i].nom,tab[i+1].nom) >= 0){
           Produit tmp;
           tmp=tab[i];
           tab[i]=tab[i+1];
           tab[i+1]=tmp;
           c++;
        }
      }
    }while(c>0);
}
//Affichage des produits
void affichage(Produit *P,int nbr,int T){
       int i;
       if(nbr==0){
        printf("Aucun produit");
		printf("\n");
       }else {
	if(T == 1){
		 Trinom(P,nbr);
	} else {
	    Triprix(P,nbr);
	   }
    for(i=0;i<nbr;i++){
     printf("\n\tProduit %d: ",i+1);
     printf("\nCode : %d",P[i].code);
     printf("\nNom : %s",P[i].nom);
	 printf("\nPrix : %d DH",P[i].prix);
	 printf("\nQuantite : %d",P[i].quant);
	 printf("\n");
    }
       }

    }
//Date d'aujourdh'ui
Date today(){
	int day, mois, an;
	Date d;
     time_t now;
     time(&now);
      struct tm *local = localtime(&now);
      day = local->tm_mday;
      mois = local->tm_mon + 1;
      an = local->tm_year + 1900;
      d.day=day;
      d.mois=mois;
      d.year=an;
      return d;
}
//Acheter un produit
void Acheter(Produit *P,int nbr,int na,Achat *A,int code,int quantite){
	int i,c=0;
	for(i=0;i<nbr;i++){
		if(P[i].code==code && P[i].quant >= quantite) {
			c++;
			P[i].quant = P[i].quant - quantite ;
			A[na-1].p.quant =  quantite;
			A[na-1].p.code =  code;
			A[na-1].p.prix =  P[i].prix * quantite;
            A[na-1].p.pTTC =  P[i].pTTC;
			strcpy(A[na-1].p.nom,P[i].nom);
			A[na-1].d=today();
		}
	}
	if(c==0){
		printf("\nCode invalid ou quantite insufisante !");
		printf("\n");
	}else {
	printf("\n\tProduit acheter : ");
	printf("\nCode : %d",A[na-1].p.code);
    printf("\nNom : %s",A[na-1].p.nom);
	printf("\nPrix : %d DH",A[na-1].p.prix);
	printf("\nPrix TTC : %d DH",A[na-1].p.pTTC);
	printf("\nQuantite : %d",A[na-1].p.quant);
	printf("\nDate d'achat : %d/%d/%d ",A[na-1].d.day,A[na-1].d.mois,A[na-1].d.year);
	printf("\n");
	}
}
//Recherche par code
void searchcode(Produit *P,int N,int code){
 int i,J=0,C=0;
    for(i=0;i<N;i++){
        if(P[i].code == code){
			C++;
            printf("\n\tProduit %d: ",J+1);
            printf("\nCode : %d",P[i].code);
            printf("\nNom : %s",P[i].nom);
	        printf("\nPrix : %d DH",P[i].prix);
	        printf("\nQuantite : %d",P[i].quant);
            J++;
			}
			printf("\n");
    }
    if(C==0){
        printf("\nAucun produit ! ");
		printf("\n");
    }
}
//Recherche par quantite
void searchquantite(Produit *P,int N,int quant){
	int i,J=0,C=0;
    for(i=0;i<N;i++){
        if(P[i].quant == quant){
			C++;
            printf("\n\tProduit %d: ",J+1);
            printf("\nCode : %d",P[i].code);
            printf("\nNom : %s",P[i].nom);
	        printf("\nPrix : %d DH",P[i].prix);
	        printf("\nQuantite : %d",P[i].quant);
            J++;
			}
			printf("\n");
    }
    if(C==0){
        printf("\nAucun produit ! ");
		printf("\n");
    }
}
//Recherche des produit dont la quantite est inferieur a 3
void etatstock(Produit *P,int N){
    int i,J=0,C=0;
    for(i=0;i<N;i++){
        if(P[i].quant < 3){
			C++;
            printf("\n\tProduit %d: ",J+1);
            printf("\nCode : %d",P[i].code);
            printf("\nNom : %s",P[i].nom);
	        printf("\nPrix : %d DH",P[i].prix);
	        printf("\nQuantite : %d",P[i].quant);
            J++;
			}printf("\n");
    }
    if(C==0){
        printf("\nAucun produit ! ");
		printf("\n");
    }
}

//Alimenter le stock
void alimenter(Produit *p,int nbr,int quant,int code){
	int i,c=0;
	for(i=0;i<nbr;i++){
		if(p[i].code==code){
		c++;
		p[i].quant+=quant;
		printf("\nDone !");
		}
	} if(c==0){
		printf("\nCode non valid !");
		printf("\n");
	}
}

//Suprrimer produit
void sup(Produit *p,int nbr,int i){
	int j;
	   for(j=i;j<nbr;j++) {
		  p[j]=p[j+1];
		}
}
void suprrimer(Produit *p,int nbr,int code){
	int i,j,c=0;
	for(i=0;i<nbr;i++){
		if(p[i].code==code){
          sup(p,nbr,i);
          c++;
		}
	}

	if(c==0){
		printf("\nCode non valid !");
		printf("\n");
	}else printf("\nDone !");
}
//Total prix
int total(Achat *A,int nbr){
	 int i,somme=0;
	 Date d=today();
	 for(i=0;i<nbr;i++){
		if((A[i].d.day==d.day) && (A[i].d.mois==d.mois) && (A[i].d.year==d.year)){
	    somme += A[i].p.prix;
		}
	 }return somme;
}
//Moyenne prix
int moyenne(Achat *A,int nbr){
	 int moyenne,i,somme=0,N=0;
	 Date d=today();
	 for(i=0;i<nbr;i++){
		if((A[i].d.day==d.day) && (A[i].d.mois==d.mois) && (A[i].d.year==d.year)){
	    somme += A[i].p.prix;
		N++;
		}
	}
     moyenne= somme/N;
	 return moyenne;
}
//MAX prix
int max(Achat *A,int nbr){
	 int i,max=0;
     Date d=today();
	 for(i=0;i<nbr;i++){
		if((A[i].d.day==d.day) && (A[i].d.mois==d.mois) && (A[i].d.year==d.year) && A[i].p.prix > max){
	    max = A[i].p.prix;
		}
	 }return max;
}
//MIN prix
int min(Achat *A,int nbr){
	 int i,min=max(A,nbr);
  Date d=today();
	 for(i=0;i<nbr;i++){
		if((A[i].d.day==d.day) && (A[i].d.mois==d.mois) && (A[i].d.year==d.year) && A[i].p.prix < min){
	    min = A[i].p.prix;
		}
	 }return min;
}
//Affichage du menu
void menu(){
        printf("\n\t---Menu principale---");
		printf("\n  1 - Inserer un nouveaux produit : ");
		printf("\n  2 - Inserer plusieurs nouveaux produits : ");
		printf("\n  3 - Afficher la liste des produit : ");
		printf("\n  4 - Acheter un produit : ");
		printf("\n  5 - Rechercher un produit : ");
		printf("\n  6 - Afficher l'etat de stock : ");
		printf("\n  7 - Alimenter le stock : ");
		printf("\n  8 - Supprimer un produit : ");
		printf("\n  9 - Afficher les statistique de vente en journee courante : ");
		printf("\n  0 - Quitter : ");
}

void soumenu1(){
	    printf("\n\t---Menu Affichage---");
        printf("\n  1 - Ordre alphabetique croissant du nom : ");
        printf("\n  2 - Ordre decroissant du prix : ");
		printf("\n  3 - Revenir au menu principale : ");
}
void soumenu2(){
	    printf("\n\t---Menu Recherche---");
        printf("\n  1 - Chercher par code  : ");
        printf("\n  2 - Chercher par quantite  : ");
		printf("\n  3 - Revenir au menu principale  : ");
}
void soumenu3(){
	    printf("\n\t---Menu Statistique---");
        printf("\n  1 - Total des prix des produits vendus : ");
        printf("\n  2 - Moyenne des prix des produits vendus : ");
        printf("\n  3 - Valeur maximale des prix des produits vendus : ");
        printf("\n  4 - Valeur minimale des prix des produits vendus : ");
        printf("\n  5 - Revenir au menu principale : ");
}
//variables de menu
int choix,Tri,Search,Vente;
//declaration du tableau du produit
Produit *p;
//variable de dimention du tableau du produit
int NP=0,tmp,nbr;
//declaration du tableau des achats
Achat *A;
//variable de dimention du tableau des achat
int NA=0;
//variable de recherche
int code,quantite,somme;


int main(int argc, char *argv[]) {
 do  {
 	menu();
	printf("\n");
 	printf("\nVotre choix : ");
 	scanf("%d",&choix);
	switch(choix){
		case 1 :
		    NP+=1;
			if(NP==1){
				p = malloc(NP*sizeof(Produit));
			}else{
				p = realloc(p,NP*sizeof(Produit));
			}
			saisiun(p,NP);
			break;
		case 2 :
			printf("Combien de produit vous voulez acheter ? ");
			scanf("%d",&nbr);
			tmp=NP;
			NP+=nbr;
			if(NP==nbr){
				p = malloc(NP*sizeof(Produit));
			}else{
				p = realloc(p,NP*sizeof(Produit));
			}
			saisi(p,NP,tmp);
			break;
		case 3 :
			do{
			soumenu1();
			printf("\n");
			printf("\nVotre choix : ");
 	        scanf("%d",&Tri);
	        switch(Tri){
	        	case 1 :
				affichage(p,NP,Tri);
	        		break;
				case 2 :
				affichage(p,NP,Tri);
	        		break;
				case 3 :
	        		break;
	        	default :
				printf("Choix non valid ! ");
	        		break;
			}
			}while(Tri!=3);
			break;
		case 4 :
			printf("Entrer le code du produit que vous voulez acheter : ");
			scanf("%d",&code);
			printf("Entrer la quantite : ");
			scanf("%d",&quantite);
			NA+=1;
			if(NA==1){
			  A = malloc(NA*sizeof(Achat));
			} else {
			  A = realloc(A,NA*sizeof(Achat));
			}
			Acheter(p,NP,NA,A,code,quantite);
			break;
		case 5 :
			do{
			soumenu2();
			printf("\n");
			printf("\nVotre choix : ");
 	        scanf("%d",&Search);
 	        switch(Search){
 	        case 1 :
 	        	printf("\nEntrer le code : ");
 	        	scanf("%d",&code);
 	        	searchcode(p,NP,code);
 	        	break;
			case 2 :
				printf("\nEntrer la quantite : ");
 	        	scanf("%d",&quantite);
 	        	searchquantite(p,NP,quantite);
 	        	break;
			case 3 :
 	        	break;
		    default :
			printf("Choix non valid ! ");
	        break;
			 }
			}while(Search != 3);
			break;
		case 6 :
		    printf("Les produit dont la quantite inferieure a 3 :");
			etatstock(p,NP);
			break;
		case 7 :
			printf("Entrer le code du produit que vous voulez alimenter :");
			scanf("%d",&code);
			printf("Entrer la quantite : ");
			scanf("%d",&quantite);
			alimenter(p,NP,quantite,code);
			break;
		case 8 :
            printf("Entrer le code du produit que vous voulez supprimer :");
			scanf("%d",&code);
			suprrimer(p,NP,code);
            NP--;
			break;
		case 9 :
            do {
			soumenu3();
			printf("\n");
            printf("\nVotre choix : ");
 	        scanf("%d",&Vente);
			somme=total(A,NA);
 	        switch(Vente){
 	        	case 1 :

 	        		if(somme==0) {
 	        			printf("Aucune vente aujord'hui !");
					 }  else
					 printf("La somme des prix est : %d",somme);
					 printf("\n");
 	        		break;
				case 2 :
					if(somme==0) {
 	        			printf("Aucune vente aujord'hui !");
					 }  else
					 printf("La moyenne des prix est : %d",moyenne(A,NA));
					 printf("\n");
 	        		break;
				case 3 :
					if(somme==0) {
 	        			printf("Aucune vente aujord'hui !");
					 }  else
					 printf("La valeaur maximale des prix est : %d",max(A,NA));
					 printf("\n");
 	        		break;
 	        	case 4 :
 	        		if(somme==0) {
 	        			printf("Aucune vente aujord'hui !");
					 }  else
					 printf("La valeaur minimale des prix est : %d",min(A,NA));
					 printf("\n");
 	        		break;
				case 5 :
 	        		break;
 	        	default :
 	        		printf("Choix non valid !");
 	        		break;
			 }
			}while(Vente != 5);
			break;
		case 0 :
			break;
		default :
			printf("Choix non valid ! ");
	        break;
		}
 }while(choix!=0);
}
