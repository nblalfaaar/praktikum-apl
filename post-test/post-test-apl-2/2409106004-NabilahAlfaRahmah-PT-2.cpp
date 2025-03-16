#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

#define MAX_DRAKOR 100
#define MAX_LOGIN 3

string judul[MAX_DRAKOR];
string genre [MAX_DRAKOR];
int tahun [MAX_DRAKOR];
float rating [MAX_DRAKOR];

string data_drakor[MAX_DRAKOR][4];
int jumlah = 0;

int main() {
    char ulang;
    do {
        cout << "=============\n";
        cout << "|| SIGN IN ||\n";
        cout << "=============\n";
        string username = "Nabilah Alfa Rahmah";
        string password = "2409106004";
        string nama, nim;
        int login = 0;

        while (login < MAX_LOGIN) {
            cout << "Masukkan nama sebagai username: ";
            getline(cin, nama);
            cout << "Masukkan nim sebagai password: ";
            getline(cin, nim);

            if (nama == username && nim == password) {
                break;
            } else {
                login++;
                cout << "Nama atau NIM salah! Percobaan " << login << " dari 3.\n";
            }
        }

        if(login == MAX_LOGIN) {
            cout << "Anda telah salah login 3 kali. Program berhenti.\n";
            return 0;
        }

        int pilihan;
        do {
            cout << "\n==============================\n";
            cout << "             MENU            \n";
            cout << "==============================\n";
            cout << "1. Tambah Drakor\n";
            cout << "2. Tampilkan Daftar Drakor\n";
            cout << "3. Perbarui Drakor\n";
            cout << "4. Hapus Drakor\n";
            cout << "5. Keluar\n";
            cout << "------------------------------\n";
            cout << "Pilihan (1-5): ";
            cin >> pilihan;

            switch (pilihan) {
                case 1:
                    if (jumlah >= MAX_DRAKOR) {
                        cout << "Daftar sudah penuh!" << endl;
                    } else {
                        cout << "Masukkan Judul: ";
                        cin.ignore();
                        getline(cin, judul[jumlah]);
                        data_drakor[jumlah][0] = judul[jumlah];

                        cout << "Masukkan Genre: ";
                        getline(cin, genre[jumlah]);
                        data_drakor[jumlah][1] = genre[jumlah];

                        cout << "Masukkan Tahun Rilis: ";
                        cin >> tahun[jumlah];
                        data_drakor[jumlah][2] = to_string(tahun[jumlah]);
                        
                        cout << "Masukkan Rating: ";
                        cin >> rating[jumlah];
                        data_drakor[jumlah][3] = to_string(rating[jumlah]);
                        jumlah++;
                        cout << "Drakor berhasil ditambahkan!\n";
                    }
                    break;

                case 2:
                    if (jumlah == 0) {
                        cout << "Daftar kosong!" << endl;
                    } else {
                        cout << fixed << setprecision(1);
                        cout << "\nDaftar Drama Korea:\n";
                        cout << left << setw(5) << "No"
                            << setw(25) << "Judul"
                            << setw(15) << "Genre"
                            << setw(10) << "Tahun"
                            << setw(10) << "Rating" << endl;

                        for (int i = 0; i < jumlah; i++) {
                            cout << left << setw(5) << i + 1
                                << setw(25) << data_drakor[i][0]
                                << setw(15) << data_drakor[i][1]
                                << setw(10) << data_drakor[i][2]
                                << setw(10) << stof(data_drakor[i][3]) << endl;
                        }
                    }
                    break;
            
                case 3:
                    if (jumlah == 0) {
                        cout << "Daftar kosong!" << endl;
                    } else {
                        cout << fixed << setprecision(1);
                        cout << "\nDaftar Drama Korea Sebelum Diperbarui:\n";
                        cout << left << setw(5) << "No"
                            << setw(25) << "Judul"
                            << setw(15) << "Genre"
                            << setw(10) << "Tahun"
                            << setw(10) << "Rating" << endl;

                        for (int i = 0; i < jumlah; i++) {
                            cout << left << setw(5) << i + 1
                                << setw(25) << data_drakor[i][0]
                                << setw(15) << data_drakor[i][1]
                                << setw(10) << data_drakor[i][2]
                                << setw(10) << stof(data_drakor[i][3]) << endl;
                        }

                        int index;
                        cout << "Masukkan nomor drakor yang ingin diperbarui: ";
                        cin >> index;
                        if (index < 1 || index > jumlah) {
                            cout << "Nomor tidak valid!" << endl;
                        } else {
                            index--;
                            cout << "Masukkan Judul Baru: ";
                            cin.ignore();
                            getline(cin, judul[index]);
                            data_drakor[index][0] = judul[index];

                            cout << "Masukkan Genre Baru: ";
                            getline(cin, genre[index]);
                            data_drakor[index][1] = genre[index];

                            cout << "Masukkan Tahun Rilis Baru: ";
                            cin >> tahun[index];
                            data_drakor[index][2] = to_string(tahun[index]);

                            cout << "Masukkan Rating Baru: ";
                            cin >> rating[index];
                            data_drakor[index][3] = to_string(rating[index]);
                            cout << "Drakor berhasil diperbarui!\n";
                        }
                    }
                    break;
            
                case 4:
                    if (jumlah == 0) {
                        cout << "Daftar kosong!" << endl;
                    } else {
                        cout << fixed << setprecision(1);
                        cout << "\nDaftar Drama Korea Sebelum Dihapus:\n";
                        cout << left << setw(5) << "No"
                            << setw(25) << "Judul"
                            << setw(15) << "Genre"
                            << setw(10) << "Tahun"
                            << setw(10) << "Rating" << endl;

                        for (int i = 0; i < jumlah; i++) {
                            cout << left << setw(5) << i + 1
                                << setw(25) << data_drakor[i][0]
                                << setw(15) << data_drakor[i][1]
                                << setw(10) << data_drakor[i][2]
                                << setw(10) << stof(data_drakor[i][3]) << endl;
                        }

                        int index;
                        cout << "Masukkan nomor drakor yang ingin dihapus: ";
                        cin >> index;
                        if (index < 1 || index > jumlah) {
                            cout << "Nomor tidak valid!" << endl;
                        } else {
                            index--;
                            for (int i = index; i < jumlah -1; i++) {
                                judul[i] = judul[i + 1];
                                genre[i] = genre[i + 1];
                                tahun[i] = tahun[i + 1];
                                rating[i] = rating[i + 1];

                                for (int j = 0; j < 4; j++) {
                                    data_drakor[i][j] = data_drakor[i + 1][j];
                                }
                            }
                            jumlah--;
                            cout << "Drakor berhasil dihapus!\n";
                        }
                    }
                    break;

                case 5:
                    cout << "Keluar dari program...\n";
                    break;

                default:
                    cout << "Pilihan tidak valid!\n";
            }
        } while (pilihan != 5);

        cout << "Apakah Anda ingin mengulang program? (y/n): ";
        cin >> ulang;
        cin.ignore();
    } while (ulang == 'y' || ulang == 'Y');

    cout << "========================================\n";
    cout << "         TERIMA KASIH! BYE!           \n";
    cout << "========================================\n";
    return 0;
}