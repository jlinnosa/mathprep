#include <stdlib.h>
#include <stdio.h>

/*
 * The text interface.
 */

int ask(char *str, int result)
{
	int answer;

	for (;;) {
		printf("%s = ", str);
		if (!scanf("%i", &answer))
			return 0;
		if (result == answer) {
			printf("Oikein!\n\n");
			return 1;
		} else {
			printf("Ei ihan. Koita uudestaan!\n");
		}
	}
}
