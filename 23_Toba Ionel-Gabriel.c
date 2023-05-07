#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// functie ca sa verifice daca este prim sau nu
int prim(int n)
{
	// cazuri general adevarate
	if (n <= 1)
		return 0;
	if (n <= 3)
		return 1;

	// aceasta verificare este ca sa trecem direct la 5 in bucla
	if (n % 2 == 0 || n % 3 == 0)
		return 0;

	for (int i = 5; i * i <= n; i = i + 6)
		if (n % i == 0 || n % (i + 2) == 0)
			return 0;

	return 1;
}

//functia care verifica daca numarul este prim circular sau nu
int primCircular(int n)
{
	int cnt = 0;//numarul de cifre
	int	a = n;//copie a numarului
	int div;//numarul fara o cifra
	int rem;//cifra pe care vrem sa o adaugam la "div" ca sa circulam numarul

	while (a) {// numara cifrele numarului
		cnt++;
		a /= 10;
	}

	int num = n;
	while (prim(num)) {//facem permutarile si verificam daca sunt prime

		// generam urmatoarea permutare a cifrelor numarului
		// mutam ultima cifra pe prima pozitie
		rem = num % 10;
		div = num / 10;
		num = (pow(10, cnt - 1)) * rem + div;

		// daca se parcurg toate permutarile si la final reiese acelasi numar 
		// cu care am intrat iesim din bucla
		if (num == n)
			return 1;
	}

	return 0;
}

int main()
{
	int n;//numarul pana la care verificam daca exista numere prime circulare
	int j;//numarul de numere prime circulare
	int i;//parcurge fiecare numar de la 2 pana la n
	j = 0;//numara cate numere prime circulare avem pana la n
	//declararea fisierelor
	FILE* f;
	FILE* g;
	f = fopen("in.txt", "rt");
	g = fopen("out.txt", "wt");

	fscanf(f, "%d", &n);

	for (i = 2; i < n; i++)//parcurgerea numerelor
	{
		if (primCircular(i))
			j++;
	}

	fprintf(g, "%d", j);//afisarea

	//inchiderea fisierelor
	fclose(f);
	fclose(g);

	return 0;
}