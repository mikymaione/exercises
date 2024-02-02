#ifndef PARTITA_H
#define PARTITA_H

#include <stdbool.h>

struct partita {
    char id_partita[11];

    char giocatore1[20];
    char giocatore2[20];

    int ris1[3];
    int ris2[3];
};

inline bool partita_same_giocatore(char giocatore_a[], char giocatore_b[]) {
    for (size_t i = 0; i < 20; ++i) {
        const char a = giocatore_a[i];
        const char b = giocatore_b[i];

        if (a == '\0' || b == '\0')
            break;

        if (a != b)
            return false;
    }

    return true;
}

inline bool partita_contains_giocatore(struct partita *p, char giocatore[]) {
    const bool a = partita_same_giocatore(p->giocatore1, giocatore);
    const bool b = partita_same_giocatore(p->giocatore2, giocatore);

    return a || b;
}

inline bool partita_is_same_torneo(char id_torneo_a[], char id_torneo_b[]) {
    for (int i = 0; i < 3; ++i)
        if (id_torneo_a[i] != id_torneo_b[i])
            return false;

    return true;
}

inline bool partita_same_torneo(const struct partita *p, char id_torneo_b[]) {
    char id_torneo_a[3];

    for (int i = 0; i < 3; ++i)
        id_torneo_a[i] = p->id_partita[i];

    return partita_is_same_torneo(id_torneo_a, id_torneo_b);
}

inline int partita_vincitore(const struct partita *p) {
    int r = 0;

    for (int i = 0; i < 3; ++i)
        if (p->ris1[i] > p->ris2[i])
            r--;
        else if (p->ris1[i] < p->ris2[i])
            r++;

    return r;
}

#endif //PARTITA_H
