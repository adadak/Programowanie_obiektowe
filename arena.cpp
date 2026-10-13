#include "stack.h"
#include "arena.h"
#include <iostream>
#include <stdexcept>
#include <new>
#include <cstddef>

arena* arena::create() {
    arena* a = new arena;

    return a;
}

int* arena::allocate(std::size_t count) {

    if (this->first == nullptr) { //dla pierwszego kubełka
        bucket* b = new bucket;
        this->first = b; //kopia adresu b do pola first
        this->current = b; //też do current, bo dla pierwszego przydziału first == current

        //1. adaptacyjne dobieranie pojemnośći pustego kubełka:
        std::size_t p = 1;
        while(p < count) {
            p *= 2;
        }
        b->capacity = p; //default to 2 ^ log_2(count)

        b->data = new int [b->capacity]; //tablica int o rozmiarze z pola capacity adres której pierwszego indeksu kopiuję do pola data
        b->used = count; // used to argument count
        return b->data;

    } else { // dla NIE-pierwszego kubełka
        bucket* b = this->current; //zmienna lokalna dla current bucket
        if (b->capacity - b->used >= count) {

        //2. dołączanie jeśli starczy miejsca w kubełku:
            int* p = b->data + b->used; //zmienna lokalna pierwszy wolny indeks
            b->used += count;
            return p;

        } else {

        //3. tworzenie nowego kubełka kiedy aktualny jest za mały:
        bucket* next = new bucket;
        b->next = next;
        }

    }



}

void arena::destroy(arena* a) {
    delete a;
}
