#include "Counselor.h"

// constructor
Counselor::Counselor() {}

Counselor::Counselor(string u, string p, string n, string e)
    : username(u), password(p), nama(n), email(e) {}

// getter
string Counselor::getUsername() const { return username; }
string Counselor::getPassword() const { return password; }
string Counselor::getNama() const { return nama; }
string Counselor::getEmail() const { return email; }

// setter
void Counselor::setUsername(const string& u) { username = u; }
void Counselor::setPassword(const string& p) { password = p; }
void Counselor::setNama(const string& n) { nama = n; }
void Counselor::setEmail(const string& e) { email = e; }
