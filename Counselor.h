#ifndef COUNSELOR_H
#define COUNSELOR_H

#include <string>
using namespace std;

class Counselor {
private:
    string username;
    string password;
    string nama;
    string email;

public:
    Counselor();
    Counselor(string u, string p, string n, string e);

    // getter
    string getUsername() const;
    string getPassword() const;
    string getNama() const;
    string getEmail() const;

    // setter
    void setUsername(const string& u);
    void setPassword(const string& p);
    void setNama(const string& n);
    void setEmail(const string& e);
};

#endif
