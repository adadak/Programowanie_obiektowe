#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

struct stack { //aka tstack
    int *data; //pointer tablicy danych
    int size; //rozmiar tablicy
    int top; //pierwszy wolny adres aka indeks
}

tstack *init(void) {
    tstack *s = malloc(sizeof(*s));

        //defaulty:
    s->data = NULL;
    s->size = 0;
    s->top = 0;

    return s;
}

int isempty(tstack *s) {
    return s->top == 0; //indeks 0 == brak elementów
};

int push(tstack *s, int el) {
    int n;
    if (s->top == s->size) { //zapełnienie
        n = s->size + s->size / 2; //nowy rozmiar
        if (n < 16) //warunek startowy kiedy 0 == 0
            n = 16;
            int *p = malloc(n * sizeof(*p)); //inicjalizacja tablicy n-elementowej typu p
        //walidacja
        if (p==NULL){
            return -1;
    }
