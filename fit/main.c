#include <stdio.h>

#include "lista.h"
#include "partita.h"

struct lista *leggi_partite(struct partita partite[], const size_t len) {
    struct lista *l = lista_new();

    for (size_t i = 0; i < len; ++i)
        lista_add(l, &partite[i]);

    return l;
}

int vittorie_giocatore_torneo(const struct lista *l, char id_torneo[3], char giocatore[20]) {
    int vittorie = 0;

    const struct nodo *current = l->head;

    while (current != NULL) {
        struct partita *p = current->data;

        if (partita_same_torneo(p, id_torneo))
            if (partita_contains_giocatore(p, giocatore)) {
                const int v = partita_vincitore(p);

                if (v < 0) {
                    // p1
                    if (partita_same_giocatore(p->giocatore1, giocatore))
                        vittorie += 1;
                } else if (v > 0) {
                    // p2
                    if (partita_same_giocatore(p->giocatore2, giocatore))
                        vittorie += 1;
                }
            }

        current = current->next;
    }

    return vittorie;
}

#define num_partite 4

int main() {
    const struct partita p1 = {
        "Wim210",

        "Bianchi",
        "Rossi",

        {4, 7, 4},
        {6, 5, 6}
    };

    const struct partita p2 = {
        "Wim211",

        "Gialli",
        "Rossi",

        {6, 6, 0},
        {3, 2, 0}
    };

    const struct partita p3 = {
        "Wim212",

        "Rossi",
        "Gialli",

        {6, 2, 7},
        {2, 6, 6}
    };

    const struct partita p4 = {
        "Rol184",

        "Rossi",
        "Gialli",

        {4, 2, 7},
        {6, 6, 5}
    };

    struct partita partite[num_partite] = {p1, p2, p3, p4};

    struct lista *l = leggi_partite(partite, num_partite);

    const int wim_bianchi = vittorie_giocatore_torneo(l, "Wim", "Bianchi");
    const int wim_rossi = vittorie_giocatore_torneo(l, "Wim", "Rossi");
    const int rol_rossi = vittorie_giocatore_torneo(l, "Rol", "Rossi");

    printf("Wimbledon | Bianchi: %i\n", wim_bianchi);
    printf("Wimbledon | Rossi: %i\n", wim_rossi);
    printf("Roland-Garros | Rossi: %i\n", rol_rossi);

    lista_free(l);

    return 0;
}
