// cpp
#include <gtest/gtest.h>
#include <memory>
#include "../ShoppingList.h"
#include "../Category.h"
#include "../Item.h"

class ShoppingListTest : public ::testing::Test {
protected:
    std::unique_ptr<ShoppingList> list;
    Category* alimentari;
    Category* latticini;

    void SetUp() override {
        list = std::make_unique<ShoppingList>("ListaProva");
        alimentari = new Category("Alimentari");
        latticini = new Category("Latticini");

        list->addItem(Item("Pane", alimentari));
        list->addItem(Item("Latte", latticini));
        list->addItem(Item("Uova", alimentari));
    }

    void TearDown() override {
        delete alimentari;
        delete latticini;
    }
};
// Test Aggiunta Item
TEST_F(ShoppingListTest, AddItemIncreasesSize) {
    EXPECT_EQ(list->getSize(), 3);
    list->addItem(Item("Formaggio", latticini));
    EXPECT_EQ(list->getSize(), 4);
}
// Test Recupero Item
TEST_F(ShoppingListTest, GetItemReturnsCorrectItem){
    Item item = list->getItem(0);
    EXPECT_EQ(item.getName(), "Pane");
    ASSERT_NE(item.getCategory(), nullptr);
    EXPECT_EQ(item.getCategory()->getName(), "Alimentari");
    EXPECT_FALSE(item.isPurchased());
}
// Test Rimozione Item
TEST_F(ShoppingListTest, RemoveItemDecreasesSize) {
    EXPECT_EQ(list->getSize(), 3);
    list->removeItem(0);
    EXPECT_EQ(list->getSize(), 2);
}
// Test Imposta Acquistato
TEST_F(ShoppingListTest, SetItemPurchasedUpdatesStatus) {
    list->setItemPurchased(list->getItem(0), true);
    EXPECT_TRUE(list->getItem(0).isPurchased());
    list->setItemPurchased(list->getItem(0), false);
    EXPECT_FALSE(list->getItem(0).isPurchased());
}
// Test Conta Acquistati
TEST_F(ShoppingListTest, GetPurchasedCountReturnsCorrect) {
    list->setItemPurchased(list->getItem(0), true);
    list->setItemPurchased(list->getItem(1), true);
    EXPECT_EQ(list->getPurchasedCount(), 2);
}
// Test Imposta Quantità
TEST_F(ShoppingListTest, InvalidIndexThrowsException) {
    EXPECT_THROW(list->getItem(10), std::out_of_range);
    EXPECT_THROW(list->removeItem(10), std::out_of_range);
}
// Test Clear Lista
TEST_F(ShoppingListTest, ClearRemovesAllItems) {
    list->clear();
    EXPECT_EQ(list->getSize(), 0);
}
// Test Operazioni su Lista Vuota
TEST_F(ShoppingListTest, EmptyListOperations) {
    ShoppingList emptyList;
    EXPECT_EQ(emptyList.getSize(), 0);
}