#include <iostream>

#define size 20


char *items;
int *counts;

void Multiset_init();

auto Multiset_itemExists(int item);

int Multiset_find(int item);

void Multiset_addItem(int item);

void Multiset_pop(int item);

void Multiset_render();

void Multiset_destroy();

int main() {

    // vytváram multiset
    // zisťujem či item už existuje
    // vyhladávam item a vraciam jeho index
    // pridávať doň,
    // vybrať zneho a ak je je counts už na 0 tak nastaviť jeho hodnoty na indexe v oboch poliach na NULL,
    // vymazať celý priestor


    Multiset_init();
    // 5 insertov
    Multiset_addItem(5);
    Multiset_addItem(5);
    Multiset_addItem(5);
    Multiset_addItem(5);
    Multiset_addItem(5);
    // 2 inserty
    Multiset_addItem(3);
    Multiset_addItem(3);

    // Vybratie z multisetu
    Multiset_pop(5);
    Multiset_pop(3);
    Multiset_pop(2);

    // render
    Multiset_render();

    // free used space
    Multiset_destroy();

    return 0;
}


void Multiset_init() {
    items = (char *) malloc(size * sizeof(char));
    counts = (int *) malloc(size * sizeof(int));

    for (int i = 0; i < size; ++i) {
        counts[i] = NULL;
    }

    for (int i = 0; i < size; ++i) {
        items[i] = NULL;
    }
}


auto Multiset_itemExists(int item) {
    for (int i = 0; i < size; ++i) {
        if (items[i] == item)
            return true;
    }
    return false;
}


int Multiset_find(int item) {
    for (int i = 0; i < size; ++i) {
        if (items[i] == item)
            return i;
    }
    std::cout << "Error in finding or multiset is already full";
}

// Pridávam item do multisetu, ak sa tam ten item nenachádza, tak ho pridám na najbližšie voľné miesto
// ak sa tam už nachádza tak ho nepridávam ale len zvyšujem jeho počet v counts o 1

void Multiset_addItem(int item) {

    // pokiaľ nájdeš že už item existuje v poli tak len pridaj k jeho počtu +1
    if (Multiset_itemExists(item)) {
        int index = Multiset_find(item);
        counts[index] += 1;

    }
        // ak sa tam item ešte nenachádza
    else {

        // ulož prvý index kde je hodnota null do index premennej
        int index = Multiset_find(NULL);
        // ulož na tento index do pola items danú hodnotu
        items[index] = item;
        // nastav druhé pole ktoré počíta počet daných prvkov v poli na identickom indexe na hodnotu 1
        counts[index] = 1;

    }


}

void Multiset_render() {

    // render index with value and count of items inside
    for (int i = 0; i < size; ++i) {
        std::cout << "index: " << i << " value: " << items[i];
        std::cout << " count: " << counts[i] << std::endl;
    }
}

// vyber jeden item z multisetu
void Multiset_pop(int item) {
    // ak už existuje v multisete tak zmeň jeho počet o jednu menej
    if (Multiset_itemExists(item)) {
        int index = Multiset_find(item);

            if (counts[index] > 0) {
                counts[index] -= 1;

                // ak jeho počet je menší ako 1 tak nastav hodnotu počtu na NULL
                if (counts[index] == 0) {
                    counts[index] = NULL;
                    items[index] = NULL;
                }
            }



    } else {
        std::cout << "Provided item : " << item << " does not exist in multiset" <<  std::endl;
    }


}

// vymaž priestor ktorý bol alokovaný pre multiset
void Multiset_destroy() {
    std::free(items);
    std::free(counts);
}




