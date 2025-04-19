#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

#define MAX_DRAKOR 100
#define MAX_LOGIN 3
#define MAX_USER 10

struct User {
    string nama;
    string nim;
};

struct Drakor {
    string judul;
    string genre;
    int tahun;
    float rating;
};

struct Data {
    User users[MAX_USER];
    int jumlah_user = 0;
    Drakor daftar_drakor[MAX_DRAKOR];
    int jumlah_drakor = 0;
};

// Address-of
void tambah_drakor (Data &dt, string judul, string genre, int tahun, float rating) {
    dt.daftar_drakor[dt.jumlah_drakor++] = {judul, genre, tahun, rating};
    cout << "Drakor berhasil ditambahkan!\n";
}

// Dereference
void tambah_drakor(Data *dt) {
    string judul, genre;
    int tahun;
    float rating;

    cout << "Masukkan Judul: ";
    getline(cin, judul);
    cout << "Masukkan Genre: ";
    getline(cin, genre);
    cout << "Masukkan Tahun Rilis: ";
    cin >> tahun;
    cout << "Masukkan Rating: ";
    cin >> rating;
    cin.ignore();

    tambah_drakor(*dt, judul, genre, tahun, rating);
}

// Dereference
void tampilkan_drakor(Drakor *drakors, int index, int total) {
    if (index >= total) return;
    cout << left << setw(5) << index + 1
         << setw(30) << drakors[index].judul
         << setw(25) << drakors[index].genre
         << setw(10) << drakors[index].tahun
         << setw(10) << drakors[index].rating << endl;
    tampilkan_drakor(drakors, index + 1, total);
}

// Address-of
void perbarui_drakor(Data &dt) {
    if (dt.jumlah_drakor == 0) {
        cout << "Daftar kosong!" << endl;
    } else {
        cout << fixed << setprecision(1);
        cout << "\nDaftar Drama Korea:\n";
        cout << left << setw(5) << "No"
             << setw(30) << "Judul"
             << setw(25) << "Genre"
             << setw(10) << "Tahun"
             << setw(10) << "Rating" << endl;
        cout << string(78, '-') << endl;
        tampilkan_drakor(dt.daftar_drakor, 0, dt.jumlah_drakor);

        int index;
        cout << "Masukkan nomor drakor yang ingin diperbarui: ";
        cin >> index;
        if (index < 1 || index > dt.jumlah_drakor) {
            cout << "Nomor tidak valid!" << endl;
        } else {
            cin.ignore();
            cout << "Masukkan Judul Baru: ";
            getline(cin, dt.daftar_drakor[index - 1].judul);
            cout << "Masukkan Genre Baru: ";
            getline(cin, dt.daftar_drakor[index - 1].genre);
            cout << "Masukkan Tahun Rilis Baru: ";
            cin >> dt.daftar_drakor[index - 1].tahun;
            cout << "Masukkan Rating Baru: ";
            cin >> dt.daftar_drakor[index - 1].rating;
            cin.ignore();
            cout << "Drakor berhasil diperbarui!\n";
        }
    }
}

// Dereference
void hapus_drakor(Data *dt) {
    if (dt->jumlah_drakor == 0) {
        cout << "Daftar kosong!" << endl;
    } else {
        cout << fixed << setprecision(1);
        cout << "\nDaftar Drama Korea:\n";
        cout << left << setw(5) << "No"
             << setw(30) << "Judul"
             << setw(25) << "Genre"
             << setw(10) << "Tahun"
             << setw(10) << "Rating" << endl;
        cout << string(78, '-') << endl;
        tampilkan_drakor(dt->daftar_drakor, 0, dt->jumlah_drakor);

        int index;
        cout << "Masukkan nomor drakor yang ingin dihapus: ";
        cin >> index;
        cin.ignore();
        if (index < 1 || index > dt->jumlah_drakor) {
            cout << "Nomor tidak valid!" << endl;
        } else {
            for (int i = index - 1; i < dt->jumlah_drakor - 1; i++) {
                dt->daftar_drakor[i] = dt->daftar_drakor[i + 1];
            }
            dt->jumlah_drakor--;
            cout << "Drakor berhasil dihapus!\n";
        }
    }
}

// Address-of
void registrasi(Data &dt) {
    if (dt.jumlah_user >= MAX_USER) {
        cout << "Pengguna sudah penuh!" << endl;
    } else {
        cout << "Masukkan nama lengkap sebagai username: ";
        getline(cin, dt.users[dt.jumlah_user].nama);
        cout << "Masukkan NIM lengkap sebagai password: ";
        getline(cin, dt.users[dt.jumlah_user].nim);
        dt.jumlah_user++;
        cout << "Registrasi berhasil! Silakan login\n";
    }
}

// Dereference & Address-of
bool login_user(Data *dt, string &user_sekarang) {
    string nama, nim;
    int login = 0;
    while (login < MAX_LOGIN) {
        cout << "Username: ";
        getline(cin, nama);
        cout << "Password: ";
        getline(cin, nim);

        bool valid = false;
        for (int i = 0; i < dt->jumlah_user; i++) {
            if (dt->users[i].nama == nama && dt->users[i].nim == nim) {
                user_sekarang = nama;
                valid = true;
                break;
            }
        }
        if (valid) {
            cout << "Berhasil Login!" << endl;
            return true;
        } else {
            login++;
            cout << "Username atau password salah! Percobaan " << login << " dari 3.\n";
        }
    }
    
    cout << "Anda telah aggal login 3 kali. Program berhenti.\n";
    return false;
}

// Address-of
void menu_manajemen(Data &dt) {
    int pilihan;
    do {
        cout << "\n==============================\n";
        cout << "        MENU MANAJEMEN        \n";
        cout << "==============================\n";
        cout << "1. Tambah Drakor\n";
        cout << "2. Tampilkan Daftar Drakor\n";
        cout << "3. Perbarui Drakor\n";
        cout << "4. Hapus Drakor\n";
        cout << "5. Keluar\n";
        cout << "------------------------------\n";
        cout << "Pilihan (1-5): ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1:
                if (dt.jumlah_drakor >= MAX_DRAKOR) {
                    cout << "Daftar sudah penuh!" << endl;
                } else {
                    tambah_drakor(&dt);
                }
                break;

            case 2:
                if (dt.jumlah_drakor == 0) {
                    cout << "Daftar kosong!" << endl;
                } else {
                    cout << fixed << setprecision(1);
                    cout << "\nDaftar Drama Korea:\n";
                    cout << left << setw(5) << "No"
                         << setw(30) << "Judul"
                         << setw(25) << "Genre"
                         << setw(10) << "Tahun"
                         << setw(10) << "Rating" << endl;
                    cout << string(78, '-') << endl;
                    tampilkan_drakor(dt.daftar_drakor, 0, dt.jumlah_drakor);
                }
                break;

            case 3:
                perbarui_drakor(dt);
                break;

            case 4:
                hapus_drakor(&dt);
                break;

            case 5:
                cout << "Keluar dari program...\n";
                break;

            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 5);
}

int main() {
    Data dt;
    char ulang;
    do {
        cout << "=============================================\n";
        cout << "|| MANAJEMEN DAFTAR DRAMA KOREA DI NETFLIX ||\n";
        cout << "=============================================\n";
        int pilihan;
        string user_sekarang;

        do {
            cout << "\n==============================\n";
            cout << "         MENU UTAMA          \n";
            cout << "==============================\n";
            cout << "1. Register\n";
            cout << "2. Login\n";
            cout << "3. Keluar\n";
            cout << "Pilih (1-3): ";
            cin >> pilihan;
            cin.ignore();

            if (pilihan == 1) {
                registrasi(dt);
            } else if (pilihan == 2) {
                if (login_user(&dt, user_sekarang)) {
                    menu_manajemen(dt);
                } else {
                    return 0;
                }
            } else if (pilihan == 3) {
                cout << "Anda telah keluar dari program." << endl;
                return 0;
            } else {
                cout << "Pilihan tidak valid!\n";
            }
        } while (pilihan != 2);

        do {
            cout << "Apakah Anda ingin mengulang program? (y/n): ";
            cin >> ulang;
            cin.ignore();
            if (ulang != 'y' && ulang != 'Y' && ulang != 'n' && ulang != 'N') {
                cout << "Input tidal valid! Masukkan 'y' untuk ya atau 'n' untuk tidak.\n";
            }
        } while (ulang != 'y' && ulang != 'Y' && ulang != 'n' && ulang != 'N');
    } while (ulang == 'y' || ulang == 'Y');

    cout << "========================================\n";
    cout << "         TERIMA KASIH! BYE!           \n";
    cout << "========================================\n";
    return 0;
}