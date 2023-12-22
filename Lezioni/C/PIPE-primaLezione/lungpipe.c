/* FILE: lungpipe.c */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int count; /* variabile globale */

int main()
{
   int piped[2]; 	/* array per i lati lettura/scrittura della pipe  */
   int count;		/* variabile per contare i caratteri scritti sulla pipe (che non verranno letti da nessuno!) */
   char c = 'x'; 	/* non serviva inizializzare il valore del carattere che viene scritto sulla pipe, tanto nessuno lo legge */

	if (pipe(piped) < 0) { printf("Errore nella creazione pipe\n"); exit(1); }

	for (count = 0;;)	/* ciclo infinito con azzeramento del contatore */
	{
		write(piped[1], &c, 1); 	/* scrittura sulla pipe */

		if ((++count % 1024) == 0)	/* per evitare di stampare il contatore tutte le volte, lo stampiamo solo a multipli di 1024 */
			printf("%d caratteri nella pipe\n", count);
	}

	exit(0); /* non si arrivera' mai qui dato che abbiamo un ciclo infinito con sospensione del processo ad un certo punto sulla write */
}

