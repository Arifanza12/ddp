#include <iostream>
using namespace std;

// Fungsi untuk menampilkan papan permainan
void tampilkanPapan(char papan[3][3]) {
    cout << "-------------" << endl;
    for (int i = 0; i < 3; ++i) {
        cout << "| ";
        for (int j = 0; j < 3; ++j) {
            cout << papan[i][j] << " | ";
        }
        cout << endl;
        cout << "-------------" << endl;
    }
}

// Fungsi untuk mengecek apakah ada pemenang
char cekPemenang(char papan[3][3]) {
    // Cek baris dan kolom
    for (int i = 0; i < 3; ++i) {
        if (papan[i][0] == papan[i][1] && papan[i][1] == papan[i][2] && papan[i][0] != ' ')
            return papan[i][0];
        if (papan[0][i] == papan[1][i] && papan[1][i] == papan[2][i] && papan[0][i] != ' ')
            return papan[0][i];
    }

    // Cek diagonal
    if (papan[0][0] == papan[1][1] && papan[1][1] == papan[2][2] && papan[0][0] != ' ')
        return papan[0][0];
    if (papan[0][2] == papan[1][1] && papan[1][1] == papan[2][0] && papan[0][2] != ' ')
        return papan[0][2];

    // Tidak ada pemenang
    return ' ';
}

// Fungsi untuk mengecek apakah papan penuh
bool cekPapanPenuh(char papan[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (papan[i][j] == ' ')
                return false;
        }
    }
    return true;
}

// Fungsi untuk mengambil input pemain
void ambilInputPemain(char papan[3][3], char &pemain, int &baris, int &kolom) {
    do {
        cout << "Giliran pemain " << pemain << endl;
        cout << "Masukkan baris (0,1,2): ";
        cin >> baris;
        cout << "Masukkan kolom (0,1,2): ";
        cin >> kolom;
    } while (papan[baris][kolom] != ' ');
}

int main() {
    char papan[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    int baris, kolom;
    char pemainSekarang = 'X';

    do {
        // Tampilkan papan permainan
        tampilkanPapan(papan);

        // Input pemain
        ambilInputPemain(papan, pemainSekarang, baris, kolom);

        // Periksa apakah kotak sudah terisi
        if (papan[baris][kolom] == ' ') {
            papan[baris][kolom] = pemainSekarang;

            // Cek pemenang
            char pemenang = cekPemenang(papan);
            if (pemenang != ' ') {
                tampilkanPapan(papan);
                cout << " Horeee Pemain " << pemenang << " menang!" << endl;
                break;
            }

            // Cek papan penuh
            
            if (cekPapanPenuh(papan)) {
                tampilkanPapan(papan);
                cout << "Permainan seri!" << endl;
                break;
            }

            // Ganti giliran pemain
            pemainSekarang = (pemainSekarang == 'X') ? 'O' : 'X';
        } else {
            cout << "Kotak sudah terisi. Coba lagi." << endl;
        }

    } while (true);

    return 0;
}

