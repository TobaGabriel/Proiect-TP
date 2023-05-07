#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main()
{
	int k;//numarul de caractere speciale din secventa
	int lm;//lungimea fisierului
	char s[46];//cel mai lung cuvant in romana are 44 de caractere
	char sc[2];//caracterul din fisier
	char c;//caracterul din secventa in program
	//siruri care ajuta la crearea secventei cu caractere
	char* s1;
	char* s2;

	//declararea fisierelor
	FILE* f;
	FILE* g;
	f = fopen("in.txt", "rt");
	g = fopen("out.txt", "wt");

	fseek(f, 0, SEEK_END);//seteaza poz cursorului la sfarsitu fisierului
	lm = ftell(f);//calculeaza lungimea fisierului
	fseek(f, 0, SEEK_SET);//reseteaza poz cursorului

	fscanf(f, "%d %s", &k, sc);

	c = sc[0];//caracterul

	s1 = (char*)calloc(k, sizeof(char));//folosesc calloc pt ca initiaza sirul NULL (gol)
	s2 = (char*)malloc(k * sizeof(char));//folosesc malloc pt ca initiaza sirul cu caractere random si le pot inlocui
	strset(s2, c);
	strncat(s1, s2, k);//creaza sirul pe care o sa il folosim la inlocuire



	while (ftell(f) != lm)
	{
		fscanf(f, "%s", s);
		if ((s[0] > 'A' && s[0] < 'Z') || s[0] == 'A' || s[0] == 'Z')//verifcam daca primul caracter este litera mare
		{
			fprintf(g, "%s", s1);
			if (isalnum(s[strlen(s) - 1]) == 0)//verifica daca ultimul caracter din sir este litera sau cifra
				fprintf(g, "%c", s[strlen(s) - 1]);//daca nu este litera sau cifra o sa fie adaugat la final
			fprintf(g, " ");
		}
		else
			fprintf(g, "%s ", s);//afisare normala
	}

	//inchiderea fisierelor
	fclose(f);
	fclose(g);

	return 0;
}