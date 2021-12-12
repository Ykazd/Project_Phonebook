#include <iostream>
#include <fstream>
#include <string>
#include "kontak.h"

using namespace std;

int main()
{
    // Deklarasi object dari class
    kontak person[100];

    // Load variabel nama yang sudah ada dari file 'nama.txt'
    ifstream input_file;
    string temp;

    input_file.open("nama.txt");
    if (!input_file.is_open())
    { // Mengecek jika file tidak bisa dibuka
        cout << "Failed to open the file 'nama.txt'\n Creating file...\n";
        ofstream create_file;
        create_file.open("nama.txt");
        create_file.close();
        input_file.open("nama.txt");
    }
    for (int i = 0; i < 100; i++)
    {
        getline(input_file, temp);
        if (temp.size() != 0)
        {
            person[i].import_nama(temp);
        }
    }
    input_file.close();

    // Load variabel nomor yang sudah ada dari file 'nomor.txt'
    input_file.open("nomor.txt");
    if (!input_file.is_open())
    { // Mengecek jika file tidak bisa dibuka
        cout << "Failed to open the file 'nomor.txt'\n Creating file...\n";
        ofstream create_file;
        create_file.open("nomor.txt");
        create_file.close();
        input_file.open("nomor.txt");
    }

    for (int i = 0; i < 100; i++)
    {
        getline(input_file, temp);
        if (temp.size() != 0)
        {
            person[i].import_nomor(temp);
        }
    }
    input_file.close();

    // Memulai program
    int pilihan, pilihan_delete, pilihan_edit, konfirmasi;

    do
    {
        cout << "\n========================================";
        cout << "\n\tPilih Opsi: " << endl << endl
             << "[1] Show Contact" << endl
             << "[2] Add Contact" << endl
             << "[3] Edit Contact" << endl
             << "[4] Delete Contact" << endl << endl
             << "Tekan tombol lainnya untuk keluar" << endl;
        cout << "----------------------------------------\n";
        cout << ">> ";
        cin >> pilihan;

        // User memasukkan input untuk memilih opsi
        switch (pilihan)
        {
        case 1: // Case 1: Melihat semua kontak
            cout << "--------------------" << endl
                 << "Lihat Kontak" << endl
                 << "--------------------" << endl
                 << endl;
            cout << "No\tNama\t\t\t\tNomor" << endl;
            for (int i = 0; i < 100; i++)
            { // loop person[0] sampai person[99]
                if (person[i].check_contact())
                {                          // memanggil fungsi check_contact (jika variabel nama dan nomor memiliki isi)
                    cout << i + 1 << "\t"; // maka cout person tersebut
                    cout << person[i].show_contact() << endl;
                }
            }
            break;

        case 2: // Case 2: Menambah kontak
            cout << "--------------------" << endl
                 << "Tambah Kontak" << endl
                 << "--------------------" << endl
                 << endl;
            for (int i = 0; i < 100; i++)
            { // loop person[0] sampai person[99]
                if (!person[i].check_contact())
                {                            // memanggil fungsi check_contact (jika variabel nama dan nomor tidak memiliki isi)
                    person[i].add_contact(); // maka memasukkan nama dan nomor
                    break;
                }
            }
            cout << "Kontak dibuat!" << endl;
            break;

        case 3: // Case 3: Mengedit kontak
            cout << "--------------------" << endl
                 << "Edit Kontak" << endl
                 << "--------------------" << endl
                 << endl;
            cout << "No\tNama\t\t\t\tNomor" << endl;
            for (int i = 0; i < 100; i++)
            { // Melihat semua kontak untuk meminta masukan person[] yang ingin di-edit
                if (person[i].check_contact())
                {
                    cout << i + 1 << "\t";
                    cout << person[i].show_contact() << endl;
                }
            }
            cout << "\n\nPilih kontak yang ingin diperbarui (tekan 0 untuk batal): " << endl;
            cout << ">> ";
            cin >> pilihan_edit;

            if (pilihan_edit != 0)
            {
                pilihan_edit -= 1;
                cout << "\nNama\t\t\t\tNomor" << endl
                     << person[pilihan_edit].show_contact() << endl;
                person[pilihan_edit].edit_contact(); // Memanggil fungsi edit_contact
                cout << "Kontak diperbarui!" << endl;
            }
            break;

        case 4: // Case 4: Menghapus kontak
            cout << "--------------------" << endl
                 << "Hapus Kontak" << endl
                 << "--------------------" << endl
                 << endl;
            cout << "No\tNama\t\t\t\tNomor" << endl;
            for (int i = 0; i < 100; i++)
            { // Melihat semua kontak untuk meminta masukan person[] yang ingin di-hapus
                if (person[i].check_contact())
                {
                    cout << i + 1 << "\t";
                    cout << person[i].show_contact() << endl;
                }
            }
            cout << "\nPilih kontak yang ingin dihapus (Tekan 0 untuk batal): " << endl; // Meminta input
            cout << ">> ";
            cin >> pilihan_delete;
            if (pilihan_delete != 0)
            {
                pilihan_delete -= 1;
                cout << "\nNama\t\t\t\tNomor" << endl
                     << person[pilihan_delete].show_contact() << endl;
                cout << "\nApakah anda ingin menghapus kontak ini? (tekan 1 untuk ya, 0 untuk batal)" << endl;
                cout << ">> ";
                cin >> konfirmasi;
                if (konfirmasi == 1)
                {
                    for (int i = pilihan_delete; i < 100; i++)
                    { // Menghapus dengan menggeser array person[]
                        if (i == 99)
                        {
                            person[i].delete_contact();
                            continue;
                        }
                        person[i] = person[i + 1];
                    }
                    cout << "Kontak dihapus!" << endl;
                }
            }
            break;

        default: // Default: Quit
            break;
        }

    } while (pilihan == 1 or pilihan == 2 or pilihan == 3 or pilihan == 4);

    // Mengakhiri program dengan menyimpan perubahan yang telah dilakukan oleh user
    cout << "Saving...";

    // Menyimpan di 'nama.txt' dan 'nomor.txt'
    ofstream output_file;
    output_file.open("nama.txt");

    for (int i = 0; i < 100; i++)
    {
        if (person[i].check_contact())
        {
            output_file << person[i].export_nama() << endl;
        }
    }
    output_file.close();

    output_file.open("nomor.txt");

    for (int i = 0; i < 100; i++)
    {
        if (person[i].check_contact())
        {
            output_file << person[i].export_nomor() << endl;
        }
    }
    output_file.close();

    return 0;
}

kontak::kontak()
{
    nama = "";
    nomor = "";
}

string kontak::show_contact()
{
    return nama + "\t\t\t\t" + nomor;
}

void kontak::add_contact()
{
    cout << "Masukkan nama: ";
    cin >> nama;
    cout << "Masukkan nomor: ";
    cin >> nomor;
}

void kontak::edit_contact()
{
    string nama_baru, nomor_baru;
    cout << "--------------------" << endl
         << "Masukkan nama baru (Tekan $ untuk skip)" << endl
         << "--------------------" << endl;
    cout << ">> ";
    cin >> nama_baru;
    if (nama_baru != "$")
    {
        nama = nama_baru;
    }

    cout << "--------------------" << endl;
    cout << "Masukkan nomor baru (Tekan $ untuk skip)" << endl;
    cout << "--------------------" << endl;
    cout << ">> ";
    cin >> nomor_baru;
    if (nomor_baru != "$")
    {
        nomor = nomor_baru;
    }
}

void kontak::delete_contact()
{
    nama = "";
    nomor = "";
}

bool kontak::check_contact()
{
    if (!nama.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

void kontak::import_nama(string temp)
{
    nama = temp;
}

void kontak::import_nomor(string temp)
{
    nomor = temp;
}

string kontak::export_nama()
{
    return nama;
}

string kontak::export_nomor()
{
    return nomor;
}