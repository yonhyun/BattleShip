#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libbattleship.h"

int main(int argc,char *argv[])
{
	//char *name="config.txt";
    char *ptr;
    char name[15];
    strcpy(name,argv[1]);

   if(name==NULL){

   /* char *name="config.txt";
	struct battleship *battle;
    int i;
    int bs=0;
    int numship=0;

	battle=setupGame(name,&bs,&numship);
    playGame(battle,numship,bs);*/

    printf("Usage: %s config-file\n",name);

	return 0;

    }

    else{


       printf("Loading %s...\n",name);


       struct battleship *battle;
       int boardsize=0;
       int numship=0;
       int turns;
       battle=setupGame(name,&boardsize,&numship);
       turns=playGame(battle,numship,boardsize);

       if(turns>0){
            printf("You sank %d battleships in %d turns!\n",numship,turns);
            return 0;
       }
       else{
        return 0;
       }


   }


}




