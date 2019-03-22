#! /bin/sh

#for i in $(seq 10)
#do
	gcc exo2.c -o exo2
	./exo2

	R CMD BATCH draw.R
	mv Rplots.pdf $i.pdf
#done