#include <iostream>  
#include <iomanip>  
using namespace std; 

const int UkuranMatriks = 4; // konstanta utk mendefinisikan ukuran matriks 4 baris dan 4 kolom 


// function menampilkan matriks
void tampilMatriks(int *matriks) { // parameter pointer ke array 2 dimensi
    for (int i = 0; i < UkuranMatriks; i++) { // perulangan utk setiap baris
        cout << "+"; // garis pemanis
        for (int j = 0; j < UkuranMatriks; j++) cout << "---+"; // garis pembatas antar kolom
        cout << endl << "|"; //pindah baris baru dan mulai garis vertikal

        for (int j = 0; j < UkuranMatriks; j++) { // perulangan utk setiap kolom
            int value = *((matriks + i * UkuranMatriks) + j); // mengambil nilai elemen matriks menggunakan pointer
            if (value < 10) cout << " " << value << " |"; // jika elemen matriksnya 1 digit maka tambahkan depan nya spasi agar rapi
            else cout << value << " |"; // jika elemen matriksnya 2 digit, tampilkan langsung
        }
        cout << endl; 
    }
    // garis pembatas akhir matriks
    cout << "+";
    for (int j = 0; j < UkuranMatriks; j++) cout << "---+"; // garis pembatas antar kolom
    cout << endl; 
}

// function utk merotasi matriks searah jarum jam sesuai soal
void rotasi90Derajat(int *matriks, int *result) { // parameter pointer ke matriks input dan matriks hasil rotasi
    for (int i = 0; i < UkuranMatriks; i++) { // perulangan baris matriks asal
        for (int j = 0; j < UkuranMatriks; j++) { // perulangan kolom matriks asal

            // utk merotasi 90 derajat: posisi [i][j] menjadi [j][UkuranMatriks - 1 - i]
            *((result + j * UkuranMatriks) + (UkuranMatriks - 1 - i)) = *((matriks + i * UkuranMatriks) + j); 
        }
    }
}

int main() {
    int matriks[UkuranMatriks][UkuranMatriks]; // deklarasikan matriks 4x4 utk inputan user
    int result[UkuranMatriks][UkuranMatriks]; // deklarasikan  matriks 4x4 utk hasil rotasi

    cout << "|------------------------------------------------------|\n";
    cout << "|         INPUT ELEMEN MATRIKS 4X4 DI BAWAH INI        |\n";
    cout << "|------------------------------------------------------|\n\n";

    // nested loop utk meminta inputan elemen matriks dari user
    for (int i = 0; i < UkuranMatriks; i++) { // perulangan utk baris
        for (int j = 0; j < UkuranMatriks; j++) { // perulangan utk kolom
            cout << "Matriks[" << i << "][" << j << "] = "; 
            cin >> *(*(matriks + i) + j); // menyimpan inputan user ke matriks menggunakan pointer
        }
    }

    // menampilkn matriks awal sebelum diputar
    cout << "\nOutput matriks sebelum diputar:\n";
    tampilMatriks((int *)matriks); // memanggil function tampilMatriks utk menampilkan matriks hasil inputan user

    // proses rotasi matriks 90 derajat
    rotasi90Derajat((int *)matriks, (int *)result); // memanggil function rotasi

    // menampilkan matriks akhir setelah diputar 90 derajat
    cout << "\nOutput matriks setelah diputar 90 derajat searah jarum jam:\n";
    tampilMatriks((int *)result); // memanggil function tampilMatriks utk menampilkan matriks akhir yg telah diproses function rotasi

    cout << endl; // Baris kosong terakhir sebagai penutup
    return 0; // Akhiri program
}