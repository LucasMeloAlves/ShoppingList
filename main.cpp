#include <iostream>
#include <vector>
#include <memory>
#include "User.h"
#include "ShoppingList.h"
#include "Item.h"
#include "UserManager.h" // Aggiunto

int main() {
    UserManager userManager;

    Category categoria1("Generi Alimentari");
    Category categoria2("Elettronica");

    auto alice = std::make_shared<User>("Alice", "alice123", "alice@email.com", 1);
    auto bob = std::make_shared<User>("Bob", "bob456", "bob@email.com", 2);

    //Aggiunta utenti al manager
    userManager.addUser(alice);
    userManager.addUser(bob);

    //Creazione liste (shared_ptr) e aggiunta item
    auto lista1 = std::make_shared<ShoppingList>("Spesa Settimanale");
    lista1->addItem(Item("Pane", &categoria1, 2));
    lista1->addItem(Item("Latte", &categoria1, 4));

    auto lista2 = std::make_shared<ShoppingList>("Spesa Mensile");
    lista2->addItem(Item("Pasta", &categoria1, 1));
    lista2->addItem(Item("Smartphone", &categoria2, 1));

    //Assegna liste agli utenti
    alice->addShoppingList(lista1);
    alice->addShoppingList(lista2);
    bob->addShoppingList(lista2);

    //Interazione con l'utente
    std::cout << "--- Sistema Gestione Spesa ---\n";
    userManager.printUsers(); // Usiamo il metodo del manager

    std::cout << "\nInserisci l'ID dell'utente da visualizzare: ";
    int idCercato;
    std::cin >> idCercato;

    // Usiamo il nuovo metodo che restituisce shared_ptr
    std::shared_ptr<User> utenteSelezionato = userManager.getUserById(idCercato);

    if (utenteSelezionato) {
        std::cout << "\nUtente selezionato: " << utenteSelezionato->getName() << "\n";

        const auto& liste = utenteSelezionato->getShoppingLists();

        if (liste.empty()) {
            std::cout << "Questo utente non ha liste.\n";
        } else {
            std::cout << "Liste disponibili:\n";
            for (size_t j = 0; j < liste.size(); ++j) {
                std::cout << j << ") " << liste[j]->getName() << "\n";
            }

            std::cout << "Seleziona l'indice della lista: ";
            size_t indiceLista;
            std::cin >> indiceLista;

            if (indiceLista < liste.size()) {
                auto listaSelezionata = liste[indiceLista];
                std::cout << "\nContenuto di '" << listaSelezionata->getName() << "':\n";
                listaSelezionata->printItems();
            } else {
                std::cout << "Indice lista non valido.\n";
            }
        }
    } else {
        std::cout << "Utente con ID " << idCercato << " non trovato.\n";
    }

    return 0;
}