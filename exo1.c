#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void dix_random(){
	for(int i = 0; i < 10; i++)
		printf("%d\n", rand());
}

int Bernoulli(float p){
	double r = (double)rand()/RAND_MAX;
	printf("%f, ", r);
	if(r < p){
		return 1;
	}
	return 0;
}

int nb_arrivees(float p0, float p2){
	double r = (double)rand()/RAND_MAX;
	if(r < p0)
		return 0;
	else if(r < 1-p2)
		return 1;
	return 2;
}

int main() {
	srandom(getpid());
	printf("%d\n", nb_arrivees(0.2, 0.7));
}

/*
Reponses aux questions

2/ initialiser le generateur avec une graine
4/ rand()%100
*/