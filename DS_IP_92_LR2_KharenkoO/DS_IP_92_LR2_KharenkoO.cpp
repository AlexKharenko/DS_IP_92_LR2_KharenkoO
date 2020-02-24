#include <fstream>
#include <iostream>

using namespace std;


int main()
{
    ifstream in("not_orient.txt");
    if (in.is_open()) {
        int count = 0, temp, count_space = 0;
        char symb;
        while (!in.eof()) {
            in >> temp;
           
            count++;
        }
        in.seekg(0, ios::beg);
        in.clear();
        while (!in.eof()) {
            
            in.get(symb);
            if (symb == ' ') {
                count_space++;
            }
            if (symb == '\n') {
                break;
            }
            
        }
        in.seekg(0, ios::beg);
        in.clear();
        int l1 = count / (count_space + 1);
        int l2 = count_space + 1;
        int** a = new int* [l1];
        for (int i = 0; i < l1; i++) {
            a[i] = new int[l2];
        }
        for (int i = 0; i < l1; i++) {
            for (int j = 0; j < l2; j++) {
                in >> a[i][j];
            }
        }
        for (int i = 0; i < l1; i++) {
            for (int j = 0; j < l2; j++) {
                cout << a[i][j]<<" ";
            }
            cout << endl;
        }
        cout << endl;
    }
    else {
        cout << "File isn't opened!" << endl;
    }
}


