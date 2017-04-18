#ifndef __LIB_BATTLESHIP__
#define __LIB_BATTLESHIP__

struct battleship {
	int *body;     /* pointer to an array */
	int size;      /* battleship size */
	int pos;       /* battleship position */
};

/* Returns 1 if the ship is operational; 0 otherwise */
int shipState(struct battleship ship);


/* Print ship info */
void shipInfo(struct battleship ship);


/*
 * Makes a battleship with specified size at the specified position.
 * Initializes all elements of ship.body to 1.
 */
struct battleship makeShip(int size, int pos);


/*
 * Returns 1 if attackpos lands on a undamaged segment of a ship.
 * Registers damage to the hit segment.
 */
int hitShip(struct battleship *ship, int attackpos);


/* Return 1 if at least one ship is operational; 0 otherwise. */
int fleetState(struct battleship *fleet, int numships);


/* Handles attack event on fleet of ships given user's attack. */
void attack(struct battleship *fleet, int numships, int attackpos);


/* Makes a fleet from configuration file; sets boardsize and numships */
struct battleship *setupGame(char *filename, int *boardsize, int *numships);


/*
 * Game loop: reads attack positions from standard input, registers
 * damage on ships, indicates hit/miss events, indicates sunkin ship events,
 * and terminates when all ships are sunk.
 * Returns number of turns to sink all ships.
 */
int playGame(struct battleship *fleet, int numships, int boardsize);


#endif
