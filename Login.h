#ifndef LOGIN_H
#define LOGIN_H

#include "User.h"
#include "Counselor.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Login {
private:
    vector<User>& daftarUser;
    vector<Counselor>& daftarCounselor;
public:
    Login(vector<User>& u, vector<Counselor>& c)
        : daftarUser(u), daftarCounselor(c) {}
    void registrasiUser();
    void registrasiCounselor();
    User* loginUser();
    Counselor* loginCounselor();
};

#endif
