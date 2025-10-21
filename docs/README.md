# Week06_KnightsTour
Formålet med programmet er et simulere et forløb, hvor en springer (knight) bevæges rundt på et skakbræt (eller en anden størrelse spillebræt), indtil alle felter er blevet besøgt. Hvert felt må kun besøges én gang per tur.

# Funktion
Programmet fungerer ved, at main.c kalder funktionerne i knights_tour.c (move_is_possible() og tour_greedy()) med de givne/indtastede parametre for størrelse af bræt og startfelt. På nuværende tidspunkt er dog kun ét hardcoded forløb muligt (en demo), da jeg ikke har fået implementeret valg af brætstørrelse og startfelt m.v.
Workaround: Alternativt kan man indsætte andre brætstørrelser og startfelter inden kompilering.

# knights_tour.c
Dette modul indeholder funktionerne til at foretage trækkene.

# main.c
Kalder funktionerne i knights_tour.c med de givne parametre (når implementeret) og outputter resultatet til terminalen.

# Projektets filer
main.c              - Hovedprogram
knights_tour.c      - Funktioner til håndtering af Knight's Tour
knights_tour.h      - Headerfil for knights_tour.c
KnightsFlow.svg     - Flowchart
