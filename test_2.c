#include <stdio.h>
#include "libbattleship.h"

int main(void)
{
	int shipSize = 3;
	int shipPos = 4;
	int attackPos = 5;
	struct battleship ship;

	ship = makeShip(shipSize, shipPos);
	shipInfo(ship); /* healthy ship */

	printf("Attack position %d!\n", attackPos);
	if (hitShip(&ship, attackPos) == 1)
		printf("Hit!\n");
	else
		printf("Miss!\n");
	shipInfo(ship); /* damaged ship */

	return 0;
}
