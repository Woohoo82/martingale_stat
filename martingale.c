#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#define N 14					// hány előfordulásig statisztikázzon
#define ITERATIONS 100000000	// tesztesetek száma

int main() {
	unsigned char n, prev = 0; 	// aktuális és korábbi véletlen szám
	unsigned long count = 0;	// számláló (ez címzi a tömböt)
	unsigned long stat[N];		// előfordulások tömbje

	for (int i=0; i<N; i++) stat[i] = 0;

	printf("Ennyi az esélye, hogy érmefeldobás sorozatnál x darab vesztő egymást követi.\n\n");

	for (int i=0; i<ITERATIONS; i++) {
		n = rand() & 1;
		if (n == prev) {
			count++;
		} else {
			if (count < N)		// figyelmen kívül hagyás, ha nem kell
				stat[count]++;
			count = 0;			// számolás újrakezdése
		}
		prev = n;
	}

	for (int i=3; i<N; i++) {
		// A stat tömb az egymás utáni egyformák előfordulását méri.
		// Annak, hogy csak az egyik fajtából fordul elő ennyi, fele akkora az esélye.
		double val = (double)stat[i] / 2.0;
		// átszámolás százalékba
		val = val / ITERATIONS * 100;
		// kiíratás, space-el behúzás, a tömb számozása csúszik (0-dik jelenti az 1-et ...)
		if (i<9) printf(" ");
		printf("%d: %f%%\n", i+1, val);
	}

	return 0;
}