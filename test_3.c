#include <stdio.h>
#include "libbattleship.h"

int main(void)
{
	char *name="config.txt";
	struct battleship *battle;
    int i;
    int bs=0;
    int numship=0;

	battle=setupGame(name,&bs,&numship);
    playGame(battle,numship,bs);
  

	return 0;
}




