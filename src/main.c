/* main.c
 *
 *      1) move_is_possible()       — tjekker et enkelt ryk
 *      2) tour_greedy()            — kører én grådig tur fra en startkoordinat
 *
 */

#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>
#include "knights_tour.h"   /* Kalder funktionerne fra knights_tour.c */

int main(void)
{
    /* Kort demo: Tjekker ét ryk fra en prædefineret startkoordinat */
    size_t start_kolonne = 0u;  /* X-koordinat */
    size_t start_raekke  = 0u;  /* Y-koordinat */
    size_t ryk_id        = 0u;  /* prøv det første af de 8 mulige ryk */

    board_t besoegt = {0};      /* Det anvendte "bræt". Hvis besoegt = 0 er feltet ubesøgt. */

    bool muligt = move_is_possible(ryk_id, start_kolonne, start_raekke, besoegt);
    printf("move_is_possible(ryk=%zu, x=%zu, y=%zu) => %s\n",
           ryk_id, start_kolonne, start_raekke, muligt ? "true" : "false");

    /* Kører en enkel "greedy tour" fra samme startfelt */
    unsigned int antal_besogte = tour_greedy(start_kolonne, start_raekke);  /* Returnerer antal besøgte felter. */
    printf("tour_greedy(x=%zu, y=%zu) besøgte i alt: %u felter\n\n",
           start_kolonne, start_raekke, antal_besogte);

    return 0;
}

