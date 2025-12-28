#include "gtest/gtest.h"
#include "../Category.h"

TEST(CategoryTest, ConstructorAndGetters) {
    Category cat("Salumi");
    EXPECT_EQ(cat.getName(), "Salumi");
}

TEST(CategoryTest, SetName) {
    Category cat("Iniziale");
    cat.setName("Modificato");
    EXPECT_EQ(cat.getName(), "Modificato");
}