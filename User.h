#ifndef USER_H
#define USER_H

#include <string>
#include <vector>

enum class Role { Mahasiswa, Konselor };

struct UserData {
    std::string username;
    std::string password;
    std::string email;
    std::string nim;
    Role role;
};

class User {
private:
    std::vector<UserData> users;
    int loggedInIndex = -1;

public:
    bool registerUser(const std::string& username, const std::string& password,
                      const std::string& email, const std::string& nim, Role role);
    bool login(const std::string& username, const std::string& password);
    std::string getUsername();
    Role getRole();
    bool isLoggedIn() { return loggedInIndex != -1; }
};

#endif
