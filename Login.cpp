#include "Login.h"

void Login::registrasiUser() {
    User user;
    cin.ignore();
    cout << "--- Registrasi Mahasiswa ---\n";
    cout << "Nama: "; getline(cin, user.nama);
    cout << "NIM: "; getline(cin, user.nim);
    cout << "Username: "; getline(cin, user.username);
    cout << "Password: "; getline(cin, user.password);
    cout << "Email: "; getline(cin, user.email);
    cout << "No HP: "; getline(cin, user.noHP);

    daftarUser.push_back(user);
    cout << "Registrasi Mahasiswa Berhasil!\n\n";
}

void Login::registrasiCounselor() {
    Counselor c;
    cin.ignore();
    cout << "--- Registrasi Konselor ---\n";
    cout << "Nama: "; getline(cin, c.nama);
    cout << "Username: "; getline(cin, c.username);
    cout << "Password: "; getline(cin, c.password);
    cout << "Email: "; getline(cin, c.email);

    daftarCounselor.push_back(c);
    cout << "Registrasi Konselor Berhasil!\n\n";
}

User* Login::loginUser() {
    string u, p;
    cin.ignore();
    cout << "--- Login Mahasiswa ---\n";
    cout << "Username: "; getline(cin, u);
    cout << "Password: "; getline(cin, p);

    for (auto &user : daftarUser) {
        if (user.username == u && user.password == p) {
            cout << "Login berhasil!\n\n";
            return &user;
        }
    }
    cout << "Login gagal! Username atau password salah.\n\n";
    return nullptr;
}

Counselor* Login::loginCounselor() {
    string u, p;
    cin.ignore();
    cout << "--- Login Konselor ---\n";
    cout << "Username: "; getline(cin, u);
    cout << "Password: "; getline(cin, p);

    for (auto &c : daftarCounselor) {
        if (c.username == u && c.password == p) {
            cout << "Login berhasil!\n\n";
            return &c;
        }
    }
    cout << "Login gagal! Username atau password salah.\n\n";
    return nullptr;
}
