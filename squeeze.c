#include <stdlib.h>
#include <stdio.h>
#include "except.h"

void squeeze(char s1[], char s2[]);

int main(int argc, char *argv[])
{
	TRY
		squeeze(argc, argv);
	ELSE
		fprintf(stderr, "Wystąpił wewnętrzny błąd wymagający zakończenia pracy "
				"aplikacji.\nProsimy zgłosić ten błąd naszemu działowi "
				"obsługi technicznej\npod numerem 800-777-1234. Prosimy "
				"też podać poniższy komunikat\no błędzie, który pomoże "
				"naszemu personelowi technicznemu określić\ndokładną "
				"przyczynę błędu.\n\n")
		RERAISE;
	END_TRY;
	return EXIT_SUCCESS;
}
/*squeeze: usuń z s1 wszystkie znaki występujące w s2*/
void squeeze(char s1[], char s2[])
{
	int i, j, k;
	
	for (i = k = 0; s1[i] != '\0'; i++) {
		for (j = 0; s2[j] != '\0' && s2[j] != s1[i]; j++)
			;	/*każdego s1[i] szukaj w s2*/
		if (s2[j] == '\0') /*koniec tekstu s2 - nie znaleziono*/
			s1[k++] = s1[i];
	}
	s1[k] = '\0';
}
