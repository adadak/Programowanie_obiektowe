#include "stack.h"
#include <stdexcept>

struct stack { //aka tstack
    int *data; //pointer tablicy danych
    int size; //rozmiar tablicy
    int top; //pierwszy wolny adres aka indeks
};

tstack *init(void) {
    //konwersja wskaźnika void na tstack
    //static_cast<TYP_DOCELOWY>(wyrażenie)
    //tstack *s = static_cast<tstack*>(malloc(sizeof(tstack)));
    tstack *s = new tstack; //inicjalizacja pól w stosie

    //defaulty:
    s->data = nullptr;
    s->size = 0;
    s->top = 0;

    return s;
};

int isempty(tstack *s) {
    return s->top == 0; //indeks 0 == brak elementów
};

int push(tstack *s, int el) {
    int n;
    if (s->top == s->size) { //zapełnienie
        n = s->size + s->size / 2; //nowy rozmiar
        if (n < 16) //warunek startowy kiedy 0 == 0
            n = 16;
        //konwersja musi być jawna a nie jak w C:int *p = malloc(n * sizeof(int));
        int *p = new int[n]; //nowa tablica n-elementowa

        for (int i = 0; i < s->top; ++i) { //kopiowanie danych do nowej tablicy p
            p[i] = s->data[i]; //cel = źródło kopiowania
        }
        delete[] s->data; //czyścimy starą tablicę
        s->data = p; // wskaźnik przerzucony na nową tablicę
        s->size = n; // nowy rozmaiar to +50% starego
    }

    s->data[s->top] = el; // el zapisana pod indeksem top tablicy danych
    s->top++; // wolny teraz jest następny indeks
    return el;
};

int pop(tstack *s) {
    if (isempty(s)) {
        throw std::underflow_error("Stack is empty");
    } else
        s->top--;
    return s->data[s->top];
};

void close(tstack *s) {
    delete[] s->data; //tablica
    delete s; //struktura
}

