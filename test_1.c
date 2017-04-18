#include <stdio.h>
#include "libbattleship.h"

int main(void)
{
	int shipSize = 3;
	int shipPos = 4;
	struct battleship ship;
	
	ship = makeShip(shipSize, shipPos);
	
	shipInfo(ship);
	
	return 0;
}