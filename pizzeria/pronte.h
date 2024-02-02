#ifndef PRONTE_H
#define PRONTE_H

#include <stdlib.h>

struct pronte {
    unsigned int margherita, marinara, capricciosa, funghi;
};

inline void aggiung_pizza(struct pronte *p) {
    const unsigned int i = rand() % 4;

    switch (i) {
        case 0:
            p->margherita++;
            break;

        case 1:
            p->marinara++;
            break;

        case 2:
            p->capricciosa++;
            break;

        case 3:
            p->funghi++;
            break;

        default:
            break;
    }
}

#endif //PRONTE_H
