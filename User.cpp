#include "User.h"

bool User::registerUser(const std::string& username, const std::string& password,
                        const std::string& email, const std::string& nim, Role role) {
    for (auto &u : users) {
        if (u.username == username) return false; // username sudah ada
    }
    users.push_back({username, password, email, nim, role});
    return true;
}

bool User::login(const std::string& username, const std::string& password) {
    for (size_t i = 0; i < users.size(); ++i) {
        if (users[i].username == username && users[i].password == password) {
            loggedInIndex = i;
            return true;
        }
    }
    return false;
}

std::string User::getUsername() {
    if (loggedInIndex >= 0) return users[loggedInIndex].username;
    return "";
}

Role User::getRole() {
    if (loggedInIndex >= 0) return users[loggedInIndex].role;
    return Role::Mahasiswa; // default
}
