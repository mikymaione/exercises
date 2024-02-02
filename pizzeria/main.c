#include "ordine.h"
#include "pronte.h"

int main() {
    struct ordine ordini[88];
    struct pronte *pizze_pronte = 0;

    while (!coda_is_empty(ordini)) {
        aggiung_pizza(pizze_pronte);
        prepara_consegna(ordini, pizze_pronte);
    }

    return 0;
}
