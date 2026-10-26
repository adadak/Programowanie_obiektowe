#include "stack.h"
#include <iostream>
#include <stdexcept>
#include <new>
#include <vector>

int main() {

    std::vector<tstack*> stacks; //wektor wskaźników do n stosów

    try {

//Stwórz wektor do wybranej licby wskaźników
        std::cout << "How many stacks? \n";
        int n = 0;
        if (!(std::cin >> n) || n <= 0) { //cin z walidacją typu i czy <= 0
            throw std::invalid_argument("Invalid argument");
        }
        stacks.reserve(n); //kontener vector rezerwuje miejsce dla n wskaźników
        for (int i = 0; i < n; i++) {
            stacks.push_back(init()); //wstaw wkaźnik do kolejnego miejsca tablicy vector
        }
        std::cout << "Created: " << stacks.size() << '\n';

//Wstawianie liczb round robin do n stosów
        int perStack = 0;

        std::cout << "How many numbers per stack? \n";
        if (!(std::cin >> perStack) || perStack < 0) {
            throw std::invalid_argument("Invalid argument");
        }

        for (int i = 0; i < n * perStack; i++) {
            int index = i % n; //modulo liczby stosów
            std::cout << "Current stack: " << index + 1 << '\n';
            int el;
            if (!(std::cin >> el)) { // podstawienie liczby do el i walidacja typu
                throw std::invalid_argument("Invalid argument");
            }
            push(stacks[index], el); //push iteracyjnie dla każdego indeksu
        }

// Użycie funkcji pop
        std::cout << "\nPopping stacks:\n";

        for (int i = 0; i < n; i++) {
            std::cout << '\n' << "Stack: " << i + 1 << '\n';

            while (!isempty(stacks[i])) { //dopóki i-ty element tablicy wskaźników stacks nie jest pusty
                std::cout << pop(stacks[i]) << ' '; //wypisz poppowane i oddziel spacją
            }
        }
        try { // wywołanie wyjątku i catch
            pop(stacks[0]);
        } catch (const std::underflow_error& e) {
            std::cout << "\nExpected exception: " << e.what() << '\n';
        }

        std::cout << '\n';


    } catch (const std::invalid_argument& e) {
        std::cerr << "Invalid argument: " << e.what() << '\n';
    } catch (const std::bad_alloc& e) {
        std::cerr << "Allocation error: " << e.what() << '\n';
    } catch (const std::underflow_error& e) {
        std::cerr << "Underflow error: " << e.what() << '\n';
    } catch (const std::exception& e) {
        std::cerr << "Unknown exception: " << e.what() << '\n';
    }

    for (tstack* s : stacks) {
        close(s);

    }
}
