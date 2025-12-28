#include "gtest/gtest.h"
#include "../Item.h"

class ItemTest : public ::testing::Test {
protected:
    Category* salumi;
    Category* igiene;
    void SetUp() override {
        salumi = new Category("Salumi");
        igiene = new Category("Igiene");
    }
    void TearDown() override {
        delete salumi;
        delete igiene;
    }

};
//Test per getter
TEST_F(ItemTest, TestGetters) {
    Item item("Mortadella", salumi, false);
    EXPECT_EQ(item.getCategory()->getName(), "Mortadella");
    EXPECT_EQ(item.getQuantity(), 1);
    EXPECT_EQ(item.isPurchased(), false);
}

//Test per setter
TEST_F(ItemTest, TestSetters) {

    Item item("Mortadella", salumi, false);
    item.setCategory(igiene);
    item.setQuantity(2);
    item.setPurchased(true);
    EXPECT_EQ(item.getCategory(), igiene);
    EXPECT_EQ(item.getQuantity(), 2);
    EXPECT_EQ(item.isPurchased(), true);

}
//Test per setQuantity con valori negativi
TEST_F(ItemTest, TestSetQuantityNegative) {
    Item item("Mortadella", salumi, false);

    // Verifica che il setter della quantità accetti valori positivi
    item.setQuantity(5);
    EXPECT_EQ(item.getQuantity(), 5);

    // Verifica che venga lanciata un'eccezione se si imposta una quantità negativa
    EXPECT_THROW(item.setQuantity(-3), std::invalid_argument);
}