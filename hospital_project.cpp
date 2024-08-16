#include<iostream>
using namespace std;

string spec[21][6];
int statspec[21][6];
int numspec[21]{ 0 };

void shift_right(int s) {
    int lenght = numspec[s];
    for (int i = lenght - 1; i >= 0; i--) {
        spec[s][i + 1] = spec[s][i];
        statspec[s][i + 1] = statspec[s][i];
    }

}

void shift_left(int s) {
    for (int i = 1; i < numspec[s]; i++) {
        spec[s][i - 1] = spec[s][i];
        statspec[s][i - 1] = statspec[s][i];
    }
}
bool Add() {
    int s;
    string name;
    int st;
    cout << "ENter spec ,name,stat:\n";
    cin >> s >> name >> st;
    int lenght = numspec[s];
    if (numspec[s] < 5) {
        if (st == 0) {
            //regular
            spec[s][lenght] = name;
            statspec[s][lenght] = st;
            numspec[s]++;

        }
        else {
            //urgent
            shift_right(s);
            spec[s][0] = name;
            statspec[s][0] = st;
            numspec[s]++;
        }
        return true;
    }
    else {
        cout << "Sorry i cant accept you\n";
        return false;
    }

}


void print() {
    for (int i = 0; i < 20; i++) {
        if (numspec[i]) {//if there is at least a 1 patient in spec num i

            cout << "There are " << numspec[i] << " patients in specilization num " << i << "\n";
            for (int j = 0; j < numspec[i]; j++) {  //print patient info
                cout << spec[i][j] << " ";//names
                if (statspec[i][j] == 1)cout << "uregent\n";//stats
                else cout << "regular\n";

            }
            cout << "\n";
            cout << "************************\n";

        }
    }
}
void get_patient()
{
    int s;
    cout << "pleas enter specilization \n";
    cin >> s;
    if (numspec[s] == 0) {
        cout << "No patient at moment Rest Dr\n";
        cout << "************\n";
        return;
    }
    else {
        cout << spec[s][0] << "pleas go with DR\n";

        shift_left(s);
        numspec[s]--;

    }

}

int main() {
    while (true) {
        int choice;
        cout << "1) Add new patient\n";
        cout << "2)print all patient\n";
        cout << "3)Get next patient\n";
        cout << "4)Exit\n";
        cout << "************\n";

        cout << "Enter choice\n";
        cin >> choice;


        if (choice == 1) {
            Add();
        }
        else if (choice == 2) {
            print();
        }
        else if (choice == 3) {
            get_patient();
        }
        else return 0;
    }

    return 0;
}