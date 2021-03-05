#include <iostream>
#include "menu.h"
#include "read.hpp"
#include <sstream>
#define menudb 7

using namespace std;

bool check(int a) { return a >= 0 && a <= menudb; }

void Menu::run() {
    int v;
    do {
        v = getMenuPoint();
        switch(v) {
            case 1:
                push();
                write();
                break;
            case 2:
                pop();
                write();
                break;
            case 3:
                peek();
                write();
                break;
            case 4:
                isFull();
                write();
                break;
            case 5:
                isEmpty();
                write();
                break;
            case 6:
                write();
                break;
            case 7:
                test();
                break;
            default:
                cout << "\nViszontlatasra!\n";
                break;
        }
    } while(v != 0);
}

int Menu::getMenuPoint() {
    int v;
    cout << "\n****************************************\n";
    cout << "0. Kilepes\n";
    cout << "1. Verembe berak\n";
    cout << "2. Verembol kivesz\n";
    cout << "3. Legfelso elem lekerdezese\n";
    cout << "4. Teli-e a verem\n";
    cout << "5. Ures-e a verem\n";
    cout << "6. Vermet kiir\n";
    cout << "7. Terheles teszt (mennyi elemet tudunk a sorba tenni)\n";
    cout << "****************************************\n";
    //hiba üzenet rugalmas előállítása
    ostringstream s;
    s << "0 es " << menudb << " kozotti egesz szam legyen!";
    string errmsg = s.str();
    //beolvasás read.hpp segítségével
    v=read<int>("Valasztas:", errmsg, check);

    return v;
}

void Menu::push() {
    try {
        int x;
        cout << "Mit tegyunk be? ";
        cin >> x;
        st.push(x);
    } catch (Stack::Exception err) {
        if (err == Stack::FULL_STACK)
            cerr << "A beteves nem sikerult! A verem tele van";
        else
            cerr << "Ismeretlen hiba!";
    }
}

void Menu::pop() {
    int x;
    bool error = false;
    try {
        x = st.pop();
    } catch (Stack::Exception err) {
        if (err == Stack::EMPTY_STACK)
            cerr << "A kiveves nem sikerult! A verem ures!" << endl;
        else
            cerr << "Ismeretlen hiba!";
    }
    if (!error)
        cout << "Kivett elem: " << x << endl;
}

void Menu::peek() {
    int x;
    bool error = false;
    try {
        x = st.pop();
    } catch (Stack::Exception err) {
        if (err == Stack::EMPTY_STACK)
            cerr << "A lekerdezes nem sikerult! A verem ures!" << endl;
        else
            cerr << "Ismeretlen hiba!";
    }
    if (!error)
        cout << "A legfelso elem: " << x << endl;
}

void Menu::isFull() {
    if (st.isFull())
        cout << "A verem tele van." << endl;
    else
        cout << "A verem nincs tele." << endl;
}

void Menu::isEmpty() {
    if (st.isEmpty())
        cout << "A verem ures." << endl;
    else
        cout << "A verem nem ures." << endl;
}

void Menu::test() {
    const int n = 10000;
    Stack st = Stack(100);
    cout << "A verem pillanatnyi elemszamat kovetheti:\n";
    try {
        for(int i = 1; i < n; ++i){
            if (i % 100 == 0) cout << i << endl;
            st.push(i);
        }
    } catch(Stack::Exception) {
        cerr << "Nincs tobb szabad hely a veremben!\n";
    }
}

void Menu::write() {
    cout << st;
}