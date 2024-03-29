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
	float pTTC;
}Produit;
typedef struct{
	Produit p;
	Date d;
}Achat;

//Ajouter un produit
void saisiun(Produit *p,int NP){
	int code,j;
	printf("\n\t---Medicament %d---",NP);
	code :
	printf("\n  Code : ");
	scanf("%d",&code);
	for ( j = 0; j < NP; j++)
        {
            if (p[j].code == code)
            {
				printf ("  Ce code existe deja essayer de saisir un autre !");
                goto  code;
            }
        }
    p[NP-1].code = code;
	printf("  Nom : ");
	scanf("%s",p[NP-1].nom);
	printf("  Prix : ");
	scanf("%d",&p[NP-1].prix);
	printf("  Quantite : ");
	scanf("%d",&p[NP-1].quant);
	p[NP-1].pTTC=p[NP-1].prix +((p[NP-1].prix * 15)/100);
}
//Ajouter plusieurs produits
void saisi(Produit *p,int NP,int tmp){
	int i,code,j;
	for(i=tmp;i<NP;i++){
    printf("\n\t---Medicament %d---",i+1);
    code :
	printf("\n  Code : ");
	scanf("%d",&code);
	for (j = 0; j < NP; j++)
        {
            if (p[j].code == code)
            {
                printf ("  Ce code existe deja essayer de saisir un autre !");
                goto  code;
            }
        }
    p[i].code = code;
	printf("  Nom : ");
	scanf("%s",p[i].nom);
	printf("  Prix : ");
	scanf("%d",&p[i].prix);
	printf("  Quantite : ");
	scanf("%d",&p[i].quant);
	p[i].pTTC=p[i].prix +((p[i].prix * 15)/100);
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
        printf("  Aucun Medicament");
		printf("\n");
       }else {
	if(T == 1){
		 Trinom(P,nbr);
	} else {
	    Triprix(P,nbr);
	   }
    for(i=0;i<nbr;i++){
     printf("\n\t  Medicament %d: ",i+1);
     printf("\n  Code : %d",P[i].code);
     printf("\n  Nom : %s",P[i].nom);
	 printf("\n  Prix : %d DH",P[i].prix);
	 printf("\n  Prix TTC : %.2f DH",P[i].pTTC);
	 printf("\n  Quantite : %d",P[i].quant);
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
		printf("\n  Code invalid ou quantite insufisante !");
		printf("\n");
	}else {
	printf("\n\t  Medicament acheter : ");
	printf("\n  Code : %d",A[na-1].p.code);
    printf("\n  Nom : %s",A[na-1].p.nom);
	printf("\n  Prix : %d DH",A[na-1].p.prix);
	printf("\n  Prix TTC : %.2f DH",A[na-1].p.pTTC);
	printf("\n  Quantite : %d",A[na-1].p.quant);
	printf("\n  Date d'achat : %d/%d/%d ",A[na-1].d.day,A[na-1].d.mois,A[na-1].d.year);
	printf("\n");
	}
}
//Recherche par code
void searchcode(Produit *P,int N,int code){
 int i,C=0;
    for(i=0;i<N;i++){
        if(P[i].code == code){
			C++;
            printf("\n\t  Medicament Trouver : ");
            printf("\n  Code : %d",P[i].code);
            printf("\n  Nom : %s",P[i].nom);
	        printf("\n  Prix : %d DH",P[i].prix);
	        printf("\n  Prix TTC : %.2f DH",P[i].pTTC);
	        printf("\n  Quantite : %d",P[i].quant);
			}
			printf("\n");
    }
    if(C==0){
        printf("\n  Aucun Medicament ! ");
		printf("\n");
    }
}
//Recherche par quantite
void searchquantite(Produit *P,int N,int quant){
	int i,J=0,C=0;
    for(i=0;i<N;i++){
        if(P[i].quant == quant){
			C++;
            printf("\n\t  Medicament %d: ",J+1);
            printf("\n  Code : %d",P[i].code);
            printf("\n  Nom : %s",P[i].nom);
	        printf("\n  Prix : %d DH",P[i].prix);
	        printf("\n  Prix TTC : %.2f DH",P[i].pTTC);
	        printf("\n  Quantite : %d",P[i].quant);
            J++;
			}
			printf("\n");
    }
    if(C==0){
        printf("  Aucun Medicament ! ");
		printf("\n");
    }
}
//Recherche des produit dont la quantite est inferieur a 3
void etatstock(Produit *P,int N){
    int i,J=0,C=0;
    for(i=0;i<N;i++){
        if(P[i].quant < 3){
			C++;
            printf("\n\t  Medicament %d: ",J+1);
            printf("\n  Code : %d",P[i].code);
            printf("\n  Nom : %s",P[i].nom);
	        printf("\n  Prix : %d DH",P[i].prix);
	        printf("\n  Prix TTC : %.2f DH",P[i].pTTC);
	        printf("\n  Quantite : %d",P[i].quant);
	        printf("\n");
            J++;
			}
    }
    if(C==0){
        printf("  Aucun Medicament ! ");
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
		printf("\n  Done !");
		}
	} if(c==0){
		printf("\n  Code non valid !");
		printf("\n");
	}
}

//Suprrimer produit

int suprrimer(Produit *p,int nbr,int code){
	int i,j,c=0;
	for(i=0;i<nbr;i++){
		if(p[i].code==code){
		  for(j=i;j<nbr;j++) {
		  p[j]=p[j+1];

		}
          c++;
		}
	}
	if(c==0){
		printf("\n  Code non valid !");
		printf("\n");
	}else printf("\n  Done !");
	return c;
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
float moyenne(Achat *A,int nbr){
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
		printf("\n  1 - Inserer un nouveaux medicament : ");
		printf("\n  2 - Inserer plusieurs nouveaux medicaments : ");
		printf("\n  3 - Afficher la liste des medicaments : ");
		printf("\n  4 - Acheter un medicament : ");
		printf("\n  5 - Rechercher un medicament : ");
		printf("\n  6 - Afficher l'etat de stock : ");
		printf("\n  7 - Alimenter le stock : ");
		printf("\n  8 - Supprimer un medicament : ");
		printf("\n  9 - Afficher les statistique des medicaments vendu en journee courante : ");
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
        printf("\n  1 - Total des prix des medicaments vendus : ");
        printf("\n  2 - Moyenne des prix des medicaments vendus : ");
        printf("\n  3 - Valeur maximale des prix des medicaments vendus : ");
        printf("\n  4 - Valeur minimale des prix des medicaments vendus : ");
        printf("\n  5 - Revenir au menu principale : ");
}

int main(int argc, char *argv[]) {
	
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
	
	
	printf("\n\n");
	printf("\t>>>>>>Gestion de Pharmacie<<<<<<");
	printf("\n");
    do  {
 	menu();
	printf("\n");
 	printf("\n  Votre choix : ");
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
			printf("  Combien de medicaments vous voulez ajouter ? ");
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
			printf("\n  Votre choix : ");
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
				printf("  Choix non valid ! ");
	        		break;
			}
			}while(Tri!=3);
			break;
		case 4 :
			printf("  Entrer le code du medicament que vous voulez acheter : ");
			scanf("%d",&code);
			printf("  Entrer la quantite : ");
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
			printf("\n  Votre choix : ");
 	        scanf("%d",&Search);
 	        switch(Search){
 	        case 1 :
 	        	printf("\n  Entrer le code : ");
 	        	scanf("%d",&code);
 	        	searchcode(p,NP,code);
 	        	break;
			case 2 :
				printf("\n  Entrer la quantite : ");
 	        	scanf("%d",&quantite);
 	        	searchquantite(p,NP,quantite);
 	        	break;
			case 3 :
 	        	break;
		    default :
			printf("  Choix non valid ! ");
	        break;
			 }
			}while(Search != 3);
			break;
		case 6 :
		    printf("  Les medicaments dont la quantite inferieure a 3 :");
			etatstock(p,NP);
			break;
		case 7 :
			printf("  Entrer le code du medicament que vous voulez alimenter :");
			scanf("%d",&code);
			printf("  Entrer la quantite : ");
			scanf("%d",&quantite);
			alimenter(p,NP,quantite,code);
			break;
		case 8 :
            printf("  Entrer le code du medicament que vous voulez supprimer :");
			scanf("%d",&code);
			int test = suprrimer(p,NP,code);
			if(test > 0){
				NP--;
			}
			break;
		case 9 :
            do {
			soumenu3();
			printf("\n");
            printf("\n  Votre choix : ");
 	        scanf("%d",&Vente);
			somme=total(A,NA);
 	        switch(Vente){
 	        	case 1 :

 	        		if(somme==0) {
 	        			printf("  Aucune vente aujord'hui !");
					 }  else
					 printf("  La somme des prix est : %d",somme);
					 printf("\n");
 	        		break;
				case 2 :
					if(somme==0) {
 	        			printf("  Aucune vente aujord'hui !");
					 }  else
					 printf("  La moyenne des prix est : %.2f",moyenne(A,NA));
					 printf("\n");
 	        		break;
				case 3 :
					if(somme==0) {
 	        			printf("  Aucune vente aujord'hui !");
					 }  else
					 printf("  La valeaur maximale des prix est : %d",max(A,NA));
					 printf("\n");
 	        		break;
 	        	case 4 :
 	        		if(somme==0) {
 	        			printf("  Aucune vente aujord'hui !");
					 }  else
					 printf("  La valeaur minimale des prix est : %d",min(A,NA));
					 printf("\n");
 	        		break;
				case 5 :
 	        		break;
 	        	default :
 	        		printf("  Choix non valid !");
 	        		break;
			 }
			}while(Vente != 5);
			break;
		case 0 :
			break;
		default :
			printf("  Choix non valid ! ");
	        break;
		}
 }while(choix!=0);
}
