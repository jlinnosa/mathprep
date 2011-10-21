#include <stdlib.h>
#include <stdio.h>

/*
 * The text interface.
 */

int ask(int x, int y, char op)
{
	int answer, result;

	switch (op) {
	case '+':
		result = x + y;
		break;
	case '-':
		result = x - y;
		break;
	case '*':
		result = x * y;
		break;
	case '/':
		result = x / y;
		break;
	default:
		/* illegal operand */
		return 0;
	}

	for (;;) {
		printf("%i %c %i = ", x, op, y);
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
