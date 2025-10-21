/* knights_tour.h
 *
 * Formål:
 *  - Samle alt "Knight's Tour" API og konstanter ét sted.
 *  - Gøre programmet uafhængigt af en fast brætstørrelse via SIZE.
 *
 * Kildekrav fra Uge 6:
 *  - Brug #define SIZE (default 8), men koden skal også virke for andre SIZE. 
 *  - Knight-move offsets (8 mulige træk) angives som konstanter.
 *  - Funktioner: move_is_possible, tour_greedy, greedy_tour_from_each_square.
 *  - Udskrift: SIZE×SIZE tabel med antal besøgte felter pr. startfelt (håndteres i .c). 
 * Se opgaveteksten og prototyperne i materialet. 
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

/* -----------------------------------------------------------
 * move_is_possible
 * Formål: Afgør om ryk 'move_id' fra (x,y) holder sig på brættet
 *         og lander på et ubesøgt felt.
 * Regler: 0 <= move_id < MOVE_COUNT,
 *         0 <= ny < SIZE, 0 <= nx < SIZE,
 *         besoegt[ny][nx] == 0.
 * Return: true hvis lovligt, ellers false.
 * Bemærk: 'besoegt' er et 2D-array, hvor positive værdier betyder "allerede besøgt".
 * ----------------------------------------------------------- */
bool move_is_possible(size_t move_id, size_t x, size_t y, board_t besoegt);

/* -----------------------------------------------------------
 * tour_greedy
 * Formål: Udfør én grådig ridt fra (start_x,start_y):
 *         vælg altid det FØRSTE lovlige træk (i rækkefølgen 0..7).
 * Mekanik: Opretter et lokalt bræt til forsøget, markerer besøgte felter fortløbende.
 * Stopper når ingen lovlige træk er tilbage.
 * Return: Antal felter der blev besøgt (>=1 ved gyldig start).
 * ----------------------------------------------------------- */
unsigned int tour_greedy(size_t start_x, size_t start_y);

/* -----------------------------------------------------------
 * greedy_tour_from_each_square
 * Formål: Kør den grådige tur for ALLE startfelter (x,y) og
 *         udskriv en SIZE×SIZE-matrix med antal besøgte felter
 *         for hvert startfelt (tal separeret af mellemrum, én række per linje).
 * ----------------------------------------------------------- */
void greedy_tour_from_each_square(void);

#endif /* KNIGHTS_TOUR_H */