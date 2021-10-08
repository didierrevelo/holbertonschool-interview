#include "menger.h"
#include <stdio.h>
#include <math.h>


/**
 * first - Checks if indices are (1, 1), if so, then square is blank
 *
 * @row: Row Index
 * @colum: Column Index
 *
 * Return: 1 if (1, 1), 0 otherwise
 */

int first(int row, int colum)
{
	while (row != 0 && colum != 0)
	{
		if (row % 3 == 1 && colum % 3 == 1)
			return (0);

		row /= 3, colum /= 3;
	}
	return (1);
}

/**
 * menger - Entry point
 *
 * @level: level of the Menger Sponge to draw
 *
 * Return: Nothing
 */
void menger(int level)
{
	int runner1, runner2, limit;

	if (level < 0)
		return;

	for (runner1 = 0, limit = pow(3, level); runner1 < limit; runner1++)
	{
		for (runner2 = 0; runner2 < limit; runner2++)
		{
			first(runner1, runner2) == 1 ? printf("%c", '#') : printf("%c", ' ');
		}
		printf("\n");
	}
}
