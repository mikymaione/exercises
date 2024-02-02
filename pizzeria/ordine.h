#ifndef ORDINE_H
#define ORDINE_H

#include <stdbool.h>

#include "pronte.h"

struct ordine {
    char indirizzo[250];
    unsigned int margherita, marinara, capricciosa, funghi;
};

inline bool coda_is_empty(struct ordine ordini[]) {
    return false;
}

inline void stampa_ordine(struct ordine ordine) {
    // stampa
}

inline bool ordine_is_ready(const struct ordine ordine, const struct pronte *pizze_pronte) {
    if (pizze_pronte->margherita < ordine.margherita)
        return false;
    if (pizze_pronte->marinara < ordine.marinara)
        return false;
    if (pizze_pronte->capricciosa < ordine.capricciosa)
        return false;
    if (pizze_pronte->funghi < ordine.funghi)
        return false;

    return true;
}

inline void prepara_consegna(struct ordine ordini[], struct pronte *pizze_pronte) {
    const struct ordine ordine = ordini[0]; // top

    if (ordine_is_ready(ordine, pizze_pronte)) {
        stampa_ordine(ordine);
        // ordini.pop();

        // continua a verificare prossimo ordine
        prepara_consegna(ordini, pizze_pronte);
    }
}

#endif //ORDINE_H
