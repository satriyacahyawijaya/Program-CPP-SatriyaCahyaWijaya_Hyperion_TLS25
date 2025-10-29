#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool isVowel(char c) {
    c = tolower(c);
    return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u');
}

string balikString(string s) {
    string hasil = "";
    for (int i = s.length() - 1; i >= 0; i--) {
        hasil += s[i];
    }
    return hasil;
}

string hapusVokal(string s) {
    string hasil = "";
    for (int i = 0; i < s.length(); i++) {
        if (!isVowel(s[i])) hasil += s[i];
    }
    return hasil;
}

string buatSandi(string kata) {
    if (kata.empty()) return "";
    char hurufAwal = kata[0];

    string tanpaVokal = hapusVokal(kata);

    string dibalik = balikString(tanpaVokal);

    int kode = (int)hurufAwal;
    string kodeStr = to_string(kode);

    int posisi = (dibalik.length() + 1) / 2;
    string sandi = dibalik.substr(0, posisi) + kodeStr + dibalik.substr(posisi);

    return sandi;
}

void tebakKata(string sandi) {
    string angka = "";
    int posAwal = -1, posAkhir = -1;

    for (int i = 0; i < sandi.length(); i++) {
        if (isdigit(sandi[i])) {
            if (posAwal == -1) posAwal = i;
            posAkhir = i;
            angka += sandi[i];
        }
    }

    if (angka.empty()) {
        cout << "Tidak ditemukan kode ASCII di sandi.\n";
        return;
    }

    int kode = stoi(angka);
    char hurufAwal = (char)kode;

    string sisa = sandi.substr(0, posAwal) + sandi.substr(posAkhir + 1);

    string hasil = balikString(sisa);

    cout << "Huruf awal kemungkinan: " << hurufAwal << endl;
    cout << "Kerangka konsonan: " << hasil << endl;
    cout << "Kemungkinan kata asli (contoh):\n";
    cout << "- " << hurufAwal << hasil << endl;
    cout << "- " << hurufAwal << "a" << hasil << endl;
    cout << "- " << hurufAwal << hasil << "a" << endl;
    cout << "(Perlu tebakan vokal, jadi hasil bisa banyak)\n";
}

int main() {
    int pilih;
    string input;

    cout << "=== Mesin Misterius ===\n";
    cout << "1. Buat sandi\n";
    cout << "2. Tebak dari sandi\n";
    cout << "0. Keluar\n";

    do {
        cout << "\nPilih menu: ";
        cin >> pilih;
        cin.ignore();

        if (pilih == 1) {
            cout << "Masukkan kata: ";
            getline(cin, input);
            cout << "Hasil sandi: " << buatSandi(input) << endl;
        }
        else if (pilih == 2) {
            cout << "Masukkan sandi: ";
            getline(cin, input);
            tebakKata(input);
        }
        else if (pilih == 0) {
            cout << "Keluar dari program.\n";
        }
        else {
            cout << "Pilihan tidak dikenal.\n";
        }

    } while (pilih != 0);

    return 0;
}
