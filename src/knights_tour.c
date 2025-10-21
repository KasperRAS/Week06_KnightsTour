#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>
#include "knights_tour.h"

#define SIZE 8       /** Size of the board. */

/**
 * Knight move offsets
 *
 * Moves that a knight can make relative to the current position.
 * For example,
 * x += MOVES_X[0]; y += MOVES_Y[0]
 * corresponds to one of the eight moves that a knight can make, where `x` and
 * `y` represent the current position.
 */
#define MOVE_COUNT 8 /**< Number of moves that a knight can make */
const int MOVES_X[MOVE_COUNT] = {2, 1, -1, -2, -2, -1, 1, 2};
const int MOVES_Y[MOVE_COUNT] = {1, 2, 2, 1, -1, -2, -2, -1};

/*
 * move_is_possible
 * ----------------
 * Formål: Afgør om springeren kan foretage et bestemt af de 8 mulige ryk fra (x,y).
 * Regler: 1) Ryk-id skal være i [0..MOVE_COUNT-1].
 *         2) Nyt felt skal være placeret på brættet (0 <= nx < SIZE, 0 <= ny < SIZE).
 *         3) Nyt felt må ikke have været besøgt tidligere (besoegt[ny][nx] == 0).
 * Return: true: hvis alle tre regler er opfyldt/overholdt; ellers false.
 */

 bool move_is_possible(size_t move_id, size_t x, size_t y, board_t besoegt)
{
    /* Afvis ugyldigt ryk-id (udenfor [0..7] ved standard). */
    if (move_id >= MOVE_COUNT)
        return false;

    /* Beregn næste koordinat: cast til int før vi lægger et (negativt) offset til. */
    int nx = (int)x + MOVES_X[move_id];
    int ny = (int)y + MOVES_Y[move_id];

    /* Tjek om det nye felt ligger på brættet (0..SIZE-1). */
    if (nx < 0 || nx >= (int)SIZE)
        return false;
    if (ny < 0 || ny >= (int)SIZE)
        return false;

    /* Tjek om feltet allerede er besøgt (positiv værdi betyder 'besøgt' i opgaven). */
    if (besoegt[(size_t)ny][(size_t)nx] > 0)
        return false;

    /* Alle tjek bestået: rykket er lovligt og feltet er ubesøgt. */
    return true;
}

/*
 * tour_greedy
 * -----------
 * Formål: Udfør ét ridt (tour) med springeren fra (start_x,start_y)
 *         ved altid at vælge det FØRSTE lovlige af de 8 foruddefinerede træk.
 * Mekanik:
 *   1) Opret et lokalt bræt (besøgstabel) og nulstil til 0.
 *   2) Marker startfeltet som besøgt (#1) og sæt nuværende (x,y) dertil.
 *   3) I en løkke: søg move_id=0..MOVE_COUNT-1 efter første lovlige træk.
 *      - Hvis fundet: gå til feltet, marker besøgstæller, fortsæt.
 *      - Hvis intet træk er lovligt: stop.
 * Returnerer: Antal felter, der blev besøgt (>=1 hvis start var gyldig).
 */

unsigned int tour_greedy(size_t start_x, size_t start_y)
{
    board_t besoegt = {0};
    unsigned int antal_besoegte = 0;          /* Antal besøgte felter */

    if (start_x >= SIZE || start_y >= SIZE)  /* Startfelt udenfor brættet? */
        return 0;

    size_t x = start_x, y = start_y;         /* Nuværende position på brættet. */
    besoegt[y][x] = ++antal_besoegte;         /* Marker startfeltet som #1. */

    for (;;) {                               /* Kør, indtil vi ikke kan flytte mere.  */
        bool traek_fundet = false;           /* Flag: Lovligt træk? */

        for (size_t move_id = 0; move_id < MOVE_COUNT; ++move_id) { /* Prøv 0..7 i rækkefølge. */
            if (!move_is_possible(move_id, x, y, besoegt))          /* Er dette træk ulovligt?  */
                continue;                                           /* Ja: prøv næste træk.     */

            /* Beregn næste felt for det valgte (første lovlige) træk. */
            int nx = (int)x + MOVES_X[move_id];
            int ny = (int)y + MOVES_Y[move_id];

            /* Opdater position og marker feltet som besøgt (næste løbenummer). */
            x = (size_t)nx;
            y = (size_t)ny;
            besoegt[y][x] = ++antal_besoegte;
            traek_fundet = true;
            break;
        }

        if (!traek_fundet)                    /* Ingen mulige træk? */
            break;                            /* Ja: Turen er slut. */
    }

    return antal_besoegte;                     /* Returnerer antal besøgte felter i alt */
}
