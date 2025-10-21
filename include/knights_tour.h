/* knights_tour.h
 *
 *  - Knight-move offsets (8 mulige træk) angives som konstanter.
 *  - Funktioner: move_is_possible, tour_greedy, greedy_tour_from_each_square.
 *
 */

#ifndef KNIGHTS_TOUR_H
#define KNIGHTS_TOUR_H

#include <stddef.h>
#include <stdbool.h>

/*
 * SIZE er brættets sidelængde (default 8)
 * MOVE_COUNT er antallet af mulige springertræk. 
 */
#define SIZE 8
#define MOVE_COUNT 8

/* Knightens 8 relative træk (deklareret her, defineret i knights_tour.c).
 * Eksempel på brug: nx = x + MOVES_X[i]; ny = y + MOVES_Y[i];
 */
extern const int MOVES_X[MOVE_COUNT];
extern const int MOVES_Y[MOVE_COUNT];

typedef unsigned int Board[SIZE][SIZE];
typedef Board board_t;

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * move_is_possible
 * Formål: Afgør om ryk 'move_id' fra (x,y) holder sig på brættet og lander på et ubesøgt felt.
 * Regler: - Trækket skal være 1 af 8 mulige             (0 <= move_id < MOVE_COUNT)
 *         - Feltet skal være placeret på skakbrættet    (0 <= ny < SIZE, 0 <= nx < SIZE)
 *         - Feltet må ikke have været besøgt tidligere  (besoegt[ny][nx] == 0)  {array, positiv værdi > 0 indikeret besøgt felt}
 * Return: true hvis lovligt, ellers false.
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
bool move_is_possible(size_t move_id, size_t x, size_t y, board_t besoegt);

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * tour_greedy
 * Formål:      Udfør én "greedy tour" fra angivet startfelt (start_x, start_y):
 *              Det FØRSTE lovlige træk (i rækkefølgen 0..7) skal altid vælges.
 * Funktion:    Opretter et skakbræt (som array) til forsøget og markerer besøgte felter undervejs i turen.
 *              Stopper når ingen lovlige træk er tilbage.
 * Return:      Antal besøgte felter (>=1 ved gyldig start).
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
unsigned int tour_greedy(size_t start_x, size_t start_y);

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * greedy_tour_from_each_square
 * Formål: Kør "greedy tour" for ALLE startfelter (x,y) og
 *         udskriv en SIZE×SIZE-matrix med antal besøgte felter
 *         for hvert startfelt (tal separeret af mellemrum, én række per linje).
 * Note:   Blev ikke implementeret.
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
void greedy_tour_from_each_square(void);

#endif /* KNIGHTS_TOUR_H */