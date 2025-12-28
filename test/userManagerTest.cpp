#include "../UserManager.h"// cpp
#include <gtest/gtest.h>
#include <sstream>
#include <string>
#include "../UserManager.h"
#include "../User.h"

TEST(UserManagerTest, AddAndGetUserById) {
    UserManager um;
    User* u = new User("Luca", "luca123", "luca@example.com", 42); // adattare se necessario
    um.addUser(u);

    User* found = um.getUserById(42);
    EXPECT_EQ(found, u);

    um.removeUser(u);
    delete u;
}

TEST(UserManagerTest, RemoveUserLeavesOthersIntact) {
    UserManager um;
    User* u1 = new User("Alice", "alice", "a@e.com", 1);
    User* u2 = new User("Bob", "bob", "b@e.com", 2);
    um.addUser(u1);
    um.addUser(u2);

    // rimuovo u1
    um.removeUser(u1);
    EXPECT_EQ(um.getUserById(1), nullptr);
    EXPECT_EQ(um.getUserById(2), u2);

    um.removeUser(u2);
    delete u1;
    delete u2;
}

TEST(UserManagerTest, GetUserByIdNotFoundReturnsNullptr) {
    UserManager um;
    EXPECT_EQ(um.getUserById(999), nullptr);
}

TEST(UserManagerTest, PrintUsersOutputsIdAndName) {
    UserManager um;
    User* u = new User("Marco", "marco", "m@e.com", 7);
    um.addUser(u);

    std::ostringstream oss;
    auto* oldbuf = std::cout.rdbuf(oss.rdbuf());
    um.printUsers();
    std::cout.rdbuf(oldbuf);

    std::string out = oss.str();
    EXPECT_NE(out.find("User ID: 7"), std::string::npos);
    EXPECT_NE(out.find("Marco"), std::string::npos);

    um.removeUser(u);
    delete u;
}