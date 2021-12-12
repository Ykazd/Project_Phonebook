
#ifndef _KONTAK_H
#define _KONTAK_H
#include <string>
using namespace std;

class kontak
{
private:
    string nama;
    // variable to store the name of the contact
    string nomor;
    // variable to store the number of the contacts
public:
    kontak();
    // default constructor

    bool check_contact();
    // function to check if the contact is empty
    // return true if empty, false if not empty

    string show_contact();
    // function to show the contact
    // postcondition: return the nama and nomor of the contact

    void add_contact();
    // function to add the contact
    // postcondition: add nama and nomor to the contact

    void edit_contact();
    // function edit the contact
    // postcondition: edit nama and nomor to the contact

    void delete_contact();
    // function to delete the contact
    // postcondition: delete nama and nomor to the contact

    void import_nama(string temp);
    // function to import the name
    // postcondition: store the variable temp to the variable nama

    void import_nomor(string temp);
    // function to  import the number
    // postcondition: store the variable temp to the variable nomor

    string export_nama();
    // function to export the name

    string export_nomor();
    // function to export the number
};

#endif //_KONTAK_H
