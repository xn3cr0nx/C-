#include <iostream>
#include <fstream>

using namespace std;

struct book
{
    string title;
    string author;
    string editor;
    int page;
    int year;
    float price;
};

int main()
{
    book enter;

    ofstream f("/home/patrick/Scrivania/BookDatabase", ios::app);
    if(!f){return -1;}

    cout << "Adding Read Book" << endl;
    cout << "Insert Title: "; getline(cin, enter.title);
    cout << "Insert Author: "; getline(cin, enter.author);
    cout << "Insert Editor: "; getline(cin, enter.editor);
    cout << "Insert Page: "; cin >> enter.page;
    cout << "Insert Year: "; cin >> enter.year;
    cout << "Insert Price: "; cin >> enter.price;

    f << enter.title << "     -     " << enter.author << "     -     " << enter.editor << "     -     " << enter.page << "     -     " << enter.year << "     -     " << enter.price << "€";

    f.close();
    return 0;
}
