#include <gtest/gtest.h>
#include <sstream>
#include <string>
#include <memory> // Necessario per shared_ptr e make_shared
#include "../UserManager.h"
#include "../User.h"

TEST(UserManagerTest, AddAndGetUserById) {
    UserManager um;
    // Usiamo std::make_shared invece di new
    auto u = std::make_shared<User>("Luca", "luca123", "luca@example.com", 42);
    um.addUser(u);

    // getUserById ora restituisce uno shared_ptr
    std::shared_ptr<User> found = um.getUserById(42);

    ASSERT_NE(found, nullptr);
    EXPECT_EQ(found, u); // Verifica che puntino allo stesso oggetto
    EXPECT_EQ(found->getName(), "Luca");
}

TEST(UserManagerTest, RemoveUserLeavesOthersIntact) {
    UserManager um;
    auto u1 = std::make_shared<User>("Alice", "alice", "a@e.com", 1);
    auto u2 = std::make_shared<User>("Bob", "bob", "b@e.com", 2);

    um.addUser(u1);
    um.addUser(u2);

    // Rimuovo u1
    um.removeUser(u1);

    EXPECT_EQ(um.getUserById(1), nullptr);

    auto found2 = um.getUserById(2);
    ASSERT_NE(found2, nullptr);
    EXPECT_EQ(found2, u2);

    // Niente delete! Gli oggetti si distruggono da soli quando um va fuori scope
}

TEST(UserManagerTest, GetUserByIdNotFoundReturnsNullptr) {
    UserManager um;
    EXPECT_EQ(um.getUserById(999), nullptr);
}

TEST(UserManagerTest, PrintUsersOutputsIdAndName) {
    UserManager um;
    auto u = std::make_shared<User>("Marco", "marco", "m@e.com", 7);
    um.addUser(u);

    std::ostringstream oss;
    auto* oldbuf = std::cout.rdbuf(oss.rdbuf());
    um.printUsers();
    std::cout.rdbuf(oldbuf);

    std::string out = oss.str();
    EXPECT_NE(out.find("User ID: 7"), std::string::npos);
    EXPECT_NE(out.find("Marco"), std::string::npos);
}