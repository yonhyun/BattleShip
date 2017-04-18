#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libbattleship.h"


int shipState(struct battleship ship)
{
	int i;

	for (i = 0; i < ship.size; i++) {
		if (ship.body[i] == 1)
			return 1;
	}

	return 0;
}


void shipInfo(struct battleship ship)
{
	int i;

	printf("Ship size: %d\n", ship.size);
	printf("Ship position: %d\n", ship.pos);

	for (i = 0; i < ship.size; i++) {
		if (ship.body[i] == 1)
			printf("Ship segment %d is not damaged!\n", i);
		else
			printf("Ship segment %d is damaged!\n", i);
	}

	if (shipState(ship) == 1)
		printf("The ship is operational!\n");
	else
		printf("The ship is sunk!\n");
}

struct battleship makeShip(int size, int pos){
int i;
struct battleship bs;
//printf("---(Makeship)---\n");
//printf("size: %d pos: %d\n",size,pos);
bs.size=size;
bs.pos=pos;


bs.body=(int *)malloc(bs.size*sizeof(int));

for(i=0;i<size;i++){
    //printf("%d\n",i);
    bs.body[i]=1;

}
//printf("makeship function\n");
return bs;
}
int hitShip(struct battleship *ship, int attackpos){

int index;
index=attackpos-(ship->pos);

if(ship->body[index]==1){

    ship->body[index]=0;

    return 1;
}
else{
    return 0;

}


}

int fleetState(struct battleship *fleet,int numships){

int i;

int result=0;

for(i=0;i<numships;i++){


    if(shipState(fleet[i])==1){
        return 1;

    }
}

return 0;


}
void attack(struct battleship *fleet, int numships, int attackpos){

int result=0;
int i;
for(i=0;i<numships;i++){

    int start=fleet[i].pos;
    int size=fleet[i].size;
    int max=start+size;
    //printf("your attack position is %d\n",attackpos);
    //printf("your minimum range is %d and max is less than %d\n",start,max);

    if(start<=attackpos && attackpos<max){

        if(hitShip(&fleet[i],attackpos)==1){
            printf("Hit!\n");
            //shipInfo(fleet[i]);

            if(shipState(fleet[i])==0){
                printf("You sunk my battleship!\n");
                break;
            }else{
                break;
            }

        }

    }
    else if(i==numships-1){
        printf("Miss!\n");
    }


}



}
struct battleship *setupGame(char *filename, int *boardsize, int *numships){
FILE *f;
struct battleship *fleet;
char *notuse;
char *notuse2;
int i;

//printf("%s\n",filename );
f=fopen(filename,"r");//open, do not forget to close

int *boardsize2;
int *numships2;

/*printf("---(setupGame)---\n");
printf("in setupgame(boardsize) %d\n",*boardsize);
printf("in setupgame (numships) %d\n",*numships);*/
if(f==NULL){
	perror("error open");
}else{

	fscanf(f,"%s %d",&notuse2,&boardsize2);

	fscanf(f,"%s %d",&notuse,&numships2);
}

/*printf("in setupgame(boardsize) %d\n",*boardsize);
printf("in setupgame (numships) %d\n",*numships);*/
int a =(int)boardsize2;
int b =(int)numships2;

*boardsize=a;
*numships=b;

//printf("in setupgame(boardsize) %d\n",(int)boardsize2);
//printf("in setupgame (numships) %d\n",(int)numships2);

//printf("in setupgame(boardsize) %d\n",a);
//printf("in setupgame (numships) %d\n",*numships);

fleet=(struct battleship *)malloc(*numships * sizeof(struct battleship));

//printf("---(setupGame)---\n");

for(i=0;i<*numships;i++){

   // printf("for loop inside %d\n",i);
    int size;
    int pos;

    fscanf(f,"%s %d %d",&notuse,&size,&pos);
    //printf("size=%d, pos=%d\n",size,pos);
    fleet[i]=makeShip(size,pos);


}


fclose(f);

return fleet;
}

int playGame(struct battleship *fleet, int numships, int boardsize){
//printf("---(PlayGame Function)---\n");
/*printf("numships?? %d\n",numships);
printf("boardsize?? %d\n",boardsize);*/
int turn;
int input;

while(fleetState(fleet,numships)==1){


    printf("Enter attack coordinate (0 - %d):\n",boardsize-1);
    /*char line[100];
    fgets(line,sizeof(line),stdin);
    input=atoi(line);
    printf("the  %d\n",input);*/
    scanf("%d",&input);

    if(input<0 || input >boardsize-1){

        printf("Invalid attack coordinate.\n");

    }
    else{
        turn=turn+1;
        attack(fleet,numships,input);


    }


}


return turn;


}
