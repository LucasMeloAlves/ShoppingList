#include <gtest/gtest.h>
#include "../User.h"
#include "../ShoppingList.h" // Assicurati di includerlo

class UserTest : public ::testing::Test {
protected:
    User* user;
    void SetUp() override {
        user = new User("Luca", "password", "luca@example.com", 1);
    }
    void TearDown() override {
        delete user;
    }
};

// Test Base
TEST_F(UserTest, BasicGettersAndSetters) {
    user->setName("Marco");
    EXPECT_EQ(user->getName(), "Marco");
    EXPECT_EQ(user->getEmail(), "luca@example.com");
}

// Test Aggiunta lista reale
TEST_F(UserTest, AddRealShoppingList) {
    auto list = std::make_shared<ShoppingList>("Spesa Settimanale");

    user->addShoppingList(list);

    EXPECT_EQ(user->getShoppingLists().size(), 1u);
    EXPECT_EQ(user->getShoppingLists().at(0)->getName(), "Spesa Settimanale");
}

// Test nullptr
TEST_F(UserTest, HandleNullptrGracefully) {
    size_t before = user->getShoppingLists().size();

    // Se la tua classe DEVE lanciare errore:
    // EXPECT_THROW(user->addShoppingList(nullptr), std::invalid_argument);

    // Se invece deve solo ignorarlo:
    user->addShoppingList(nullptr);
    EXPECT_EQ(user->getShoppingLists().size(), before);
}

//Test Rimozione
TEST_F(UserTest, RemoveList) {
    auto list = std::make_shared<ShoppingList>("test");
    user->addShoppingList(list);
    ASSERT_EQ(user->getShoppingLists().size(), 1); // ASSERT ferma il test se fallisce

    user->removeShoppingList(list);
    EXPECT_EQ(user->getShoppingLists().size(), 0);
}