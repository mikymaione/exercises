#ifndef NODO_H
#define NODO_H

#include <stdlib.h>

struct nodo {
    void *data;
    struct nodo *next;
};

inline struct nodo *nodo_new(void *data, struct nodo *next) {
    struct nodo *n = malloc(sizeof(struct nodo));
    n->data = data;
    n->next = next;

    return n;
}

#endif //NODO_H
