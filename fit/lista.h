#ifndef LISTA_H
#define LISTA_H

#include "nodo.h"

struct lista {
    int size;
    struct nodo *head;
};

inline struct lista *lista_new() {
    struct lista *l = malloc(sizeof(struct lista));
    l->size = 0;
    l->head = NULL;

    return l;
}

inline void lista_add(struct lista *l, void *data) {
    l->head = nodo_new(data, l->head);
    l->size++;
}

inline void *lista_remove(struct lista *l) {
    if (l->size == 0) {
        return NULL;
    }

    struct nodo *n = l->head;

    void *data = n->data;
    l->head = n->next;

    free(n);

    l->size--;

    return data;
}

inline void lista_free(struct lista *l) {
    struct nodo *current = l->head;

    while (current != NULL) {
        struct nodo *next = current->next;

        free(current);

        current = next;
    }

    free(l);
}

#endif //LISTA_H
