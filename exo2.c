#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <math.h>

int nb_arrivees(float p0, float p2){
	double r = (double)rand()/RAND_MAX;
	if(r < p0)
		return 0;
	else if(r < 1-p2)
		return 1;
	return 2;
}

int main(){
	srand(getpid());
	FILE* f1 = fopen("exo2.csv", "w");

	long int arrivees = 0;
	long int tempsVide = 0;
	long int nbClients = 0;
	long int cumuleClients = 0;
	double epsilon = 10e-6;
	double avg = 0;
	double avgPrec = 1;
	double avgVide;
	for(long int i = 1; i < 10e6; i++){
		if(fabs(avgPrec - avg) < epsilon  && i > 1000){
			printf("Early stop : %d\n", i);
			break;
		}
		avgPrec = avg;
		nbClients += nb_arrivees(0.4, 0.35);
		cumuleClients += nbClients;
		if(nbClients > 0)
			nbClients--;
		if(nbClients == 0)
			tempsVide++;
		
		avgVide = (double)tempsVide /(double)i;
		avg = (double)cumuleClients / (double)i;
		fprintf(f1, "%d %f\n", i, avg);
	}
	printf("Moyenne de clients: %f \n", avg);
	printf("Proba que la file soit vide: %f \n", avgVide);
}