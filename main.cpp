#include <iostream>
#include <vector>
#include "User.h"
#include "ShoppingList.h"
#include "Item.h"

int main() {
    // Creazione utenti
    User utente1("Alice", "alice123", "alice@email.com", 1);
    User utente2("Bob", "bob456", "bob@email.com", 2);
    //creaziione categorie
    Category categoria1("Generi Alimentari");
    Category categoria2("Elettronica");
    // Creazione liste
    ShoppingList lista1("Spesa Settimanale");
    lista1.addItem(Item("Pane", &categoria1, 2));
    lista1.addItem(Item("Latte", &categoria2, 4));

    ShoppingList lista2("Spesa Mensile");
    lista2.addItem(Item("Pasta", &categoria1, 1));
    lista2.addItem(Item("Riso", &categoria2, 55));

    // Assegna liste agli utenti
    utente1.addShoppingList(&lista1);
    utente2.addShoppingList(&lista2);

    // Vettore utenti
    std::vector<User*> utenti = {&utente1, &utente2};

    // Stampa utenti con indice
    std::cout << "Utenti disponibili:\n";
    for (size_t i = 0; i < utenti.size(); ++i) {
        std::cout << i << ") " << utenti[i]->getName() << "\n";
    }

    std::cout << "Seleziona l'indice utente: ";
    size_t indiceUtente;
    std::cin >> indiceUtente;

    if (indiceUtente < utenti.size()) {
        User* utenteSelezionato = utenti[indiceUtente];
        const auto& liste = utenteSelezionato->getShoppingLists();

        std::cout << "Liste disponibili per " << utenteSelezionato->getName() << ":\n";
        for (size_t j = 0; j < liste.size(); ++j) {
            std::cout << j << ") " << liste[j]->getName() << "\n";
        }

        std::cout << "Seleziona l'indice lista: ";
        size_t indiceLista;
        std::cin >> indiceLista;

        if (indiceLista < liste.size()) {
            ShoppingList* listaSelezionata = liste[indiceLista];
            std::cout << "Item nella lista " << listaSelezionata->getName() << ":\n";
            listaSelezionata->printItems();
        } else {
            std::cout << "Indice lista non valido.\n";
        }
    } else {
        std::cout << "Indice utente non valido.\n";
    }

    return 0;
}
