#include <iostream>
#include <vector>
#include <memory>
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
    auto lista1 = std::make_shared<ShoppingList>("Spesa Settimanale");
    lista1->addItem(Item("Pane", &categoria1, 2));
    lista1->addItem(Item("Latte", &categoria2, 4));

    auto lista2 = std::make_shared<ShoppingList>("Spesa Mensile");
    lista2->addItem(Item("Pasta", &categoria1, 1));
    lista2->addItem(Item("Riso", &categoria2, 55));
    // Assegna liste agli utenti

    utente1.addShoppingList(lista1);
    utente1.addShoppingList(lista2);
    utente2.addShoppingList(lista2);
    //utente 1 setta un item purchased

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
            std::shared_ptr<ShoppingList> listaSelezionata = liste[indiceLista];
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
