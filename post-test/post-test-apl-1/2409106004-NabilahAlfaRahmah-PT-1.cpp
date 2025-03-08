#include <iostream>
using namespace std;

int main() {
    char ulang_program;

    do {
        string nama, nim;
        string username = "Nabilah Alfa Rahmah";
        string password = "2409106004";
        bool login_berhasil = false;

        for (int i = 0; i < 3; i++) {
            cin.ignore();
            cout << "Masukkan nama sebagai username: ";
            getline(cin, nama);
            cout << "Masukkan nim sebagai password: ";
            getline(cin, nim);

            if (nama == username && nim == password) {
                login_berhasil = true;
                cout << "Berhasil Login!\n";
                break;
            } else {
                cout << "Login gagal, silakan coba lagi." << endl;
            }
        }

        if (!login_berhasil) {
            cout << "Maaf Anda telah gagal login 3 kali. Program berhenti." << endl;
            return 0;
        }

        while (true) {
            int pilihan;
            cout << "\nMENU KONVERSI\n";
            cout << "1. Meter ke (Centimeter, Mile, Foot)\n";
            cout << "2. Centimeter ke (Meter, Mile, Foot)\n";
            cout << "3. Mile ke (Meter, Centimeter, Foot)\n";
            cout << "4. Foot ke (Meter, Centimeter, Mile)\n";
            cout << "5. Keluar\n";
            cout << "Pilih menu (1-5): ";
            cin >> pilihan;

            if (pilihan == 1) {
                double meter;
                cout << "Masukkan panjang dalam meter: ";
                cin >> meter;
                cout << "Centimeter: " << meter * 100 << " cm" << endl;
                cout << "Mile: " << meter * 0.000621371 << " mile" << endl;
                cout << "Foot: " << meter * 3.28084 << " ft" << endl;
            } else if (pilihan == 2) {
                double cm;
                cout << "Masukkan panjang dalam centimeter: ";
                cin >> cm;
                cout << "Meter: " << cm / 100 << " m" << endl;
                cout << "Mile: " << cm * 0.00000621371 << " mile" << endl;
                cout << "Foot: " << cm * 0.0328084 << " ft" << endl;
            } else if (pilihan == 3) {
                double mile;
                cout << "Masukkan panjang dalam mile: ";
                cin >> mile;
                cout << "Meter: " << mile / 0.000621371 << " m" << endl;
                cout << "Centimeter: " << mile / 0.00000621371 << " cm" << endl;
                cout << "Foot: " << mile * 5280 << " ft" << endl;
            } else if (pilihan == 4) {
                double foot;
                cout << "Masukkan panjang dalam foot: ";
                cin >> foot;
                cout << "Meter: " << foot / 3.28084 << " m" << endl;
                cout << "Centimeter: " << foot / 0.0328084 << " cm" << endl;
                cout << "Mile: " << foot / 5280 << " mile" << endl;
            } else if (pilihan == 5) {
                cout << "Anda telah keluar.\n";
                break;
            }
        }

        cout << "\nApakah Anda ingin mengulang program? (y/n): ";
        cin >> ulang_program;
    } while (ulang_program == 'y' || ulang_program == 'Y'); 
    
    cout << "Terima kasih!" << endl;
    return 0;
}