#include "App.h"
#include <iostream>
#include <string>
#include <limits>

using namespace std;

void App::run() {
    int choice;
    do {
        showMainMenu();
        cin >> choice;
        switch(choice) {
            case 1: registerMenu(); break;
            case 2: loginMenu(); break;
            case 0: cout << "Keluar program.\n"; break;
            default: cout << "Pilihan tidak valid.\n"; break;
        }
    } while(choice != 0);
}

void App::showMainMenu() {
    cout << "\n=== Consult ===\n";
    cout << "1. Registrasi\n";
    cout << "2. Login\n";
    cout << "0. Keluar\n";
    cout << "Pilih menu: ";
}

void App::registerMenu() {
    cin.ignore();
    string username, password, email, nim;
    int roleInput;
    cout << "Masukkan username: "; getline(cin, username);
    cout << "Masukkan password: "; getline(cin, password);
    cout << "Masukkan email: "; getline(cin, email);
    cout << "Masukkan NIM (bisa '-' untuk konselor): "; getline(cin, nim);
    cout << "Pilih role (1 = Mahasiswa, 2 = Konselor): "; cin >> roleInput;
    Role role = (roleInput == 2) ? Role::Konselor : Role::Mahasiswa;

    if(users.registerUser(username, password, email, nim, role))
        cout << "Registrasi berhasil!\n";
    else
        cout << "Username sudah terpakai.\n";
}

void App::loginMenu() {
    cin.ignore();
    string username, password;
    cout << "Masukkan username: "; getline(cin, username);
    cout << "Masukkan password: "; getline(cin, password);

    if(users.login(username, password)) {
        cout << "Login berhasil. Selamat datang, " << username << "!\n";
        if(users.getRole() == Role::Mahasiswa)
            mahasiswaMenu();
        else
            konselorMenu();
    } else {
        cout << "Login gagal. Periksa username/password.\n";
    }
}

// ===== Menu Mahasiswa =====
void App::mahasiswaMenu() {
    int choice;
    do {
        cout << "\n=== Menu Mahasiswa ===\n";
        cout << "1. Mulai Konsultasi\n";
        cout << "2. Riwayat Konsultasi\n";
        cout << "3. Rating & Penilaian\n";
        cout << "4. Lapor Pelanggaran\n";
        cout << "0. Logout\n";
        cout << "Pilih menu: "; cin >> choice;

        switch(choice) {
            case 1: chatMenu(); break;
            case 2: riwayatChatMahasiswa(); break;
            case 3: feedbackMenu(); ratingMenu(); break;
            case 4: reportMenu(); break;
            case 0: cout << "Logout berhasil.\n"; break;
            default: cout << "Pilihan tidak valid.\n"; break;
        }
    } while(choice != 0);
}

void App::chatMenu() {
    cin.ignore();
    string msg;
    cout << "Ketik pesan untuk konselor: "; getline(cin, msg);
    chats.push_back({users.getUsername(), msg, ""});
    cout << "Pesan terkirim (konselor akan segera membalas).\n";
}

void App::riwayatChatMahasiswa() {
    cout << "\n=== Riwayat Konsultasi ===\n";
    for(auto &c : chats) {
        if(c.mahasiswaUsername == users.getUsername()) {
            cout << "Anda: " << c.message << "\n";
            if(c.reply != "")
                cout << "  Konselor: " << c.reply << "\n";
        }
    }
}

void App::feedbackMenu() {
    cin.ignore();
    string msg;
    cout << "Masukkan feedback: "; getline(cin, msg);
    feedbacks.push_back({users.getUsername(), msg});
}

void App::ratingMenu() {
    int score;
    cout << "Masukkan rating (1-5): "; cin >> score;
    if(score<1) score=1;
    if(score>5) score=5;
    ratings.push_back({users.getUsername(), score});
}

void App::reportMenu() {
    cin.ignore();
    string msg;
    cout << "Masukkan laporan pelanggaran: "; getline(cin, msg);
    reports.push_back({users.getUsername(), msg});
}

// ===== Menu Konselor =====
void App::konselorMenu() {
    int choice;
    do {
        cout << "\n=== Menu Konselor ===\n";
        cout << "1. Lihat & Balas Chat Mahasiswa\n";
        cout << "2. Riwayat Chat\n";
        cout << "0. Logout\n";
        cout << "Pilih menu: "; cin >> choice;

        switch(choice) {
            case 1: balasChatMenu(); break;
            case 2:
                cout << "\n=== Riwayat Chat Semua Mahasiswa ===\n";
                for(auto &c : chats) {
                    cout << "- " << c.mahasiswaUsername << ": " << c.message;
                    if(c.reply != "")
                        cout << " | Balasan: " << c.reply;
                    cout << "\n";
                }
                break;
            case 0: cout << "Logout berhasil.\n"; break;
            default: cout << "Pilihan tidak valid.\n"; break;
        }
    } while(choice != 0);
}

void App::balasChatMenu() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "\n=== Daftar Chat Mahasiswa ===\n";
    int index = 1;
    for(auto &c : chats) {
        cout << index << ". " << c.mahasiswaUsername << ": " << c.message;
        if(c.reply != "") 
            cout << " | Balasan: " << c.reply;
        cout << "\n";
        index++;
    }

    int pilih;
    cout << "Pilih nomor chat untuk dibalas: ";
    cin >> pilih;

    if(pilih < 1 || pilih > chats.size()) {
        cout << "Pilihan salah.\n";
        return;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string balasan;
    cout << "Ketik balasan: ";
    getline(cin, balasan);

    chats[pilih - 1].reply = balasan;
    cout << "Balasan terkirim.\n";
}
