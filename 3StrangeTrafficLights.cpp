#include <iostream>
#include <string>
using namespace std;

string warna (long long t) {
  const int hijau = 20, kuning = 3, merah = 80;
  const int total = hijau + kuning + merah;
  const long long t0 = 25;
  long long p = ((t - t0) % total + total) % total;
  const int batas[3] = {hijau, hijau + kuning, total};
  const string nama[3] = {"Hijau", "Kuning", "Merah"};
  for (int i = 0; i < 3; i++)
      if (p < batas[i]) return nama[i];
  return "Merah";
}

int main() {
  long long t;
  cout << "Masukkan detik: ";
  cin >> t;
  cout << "Warna lampu pada detik ke-" << t << " adalah " << warna(t) << endl;
  return 0;
}
