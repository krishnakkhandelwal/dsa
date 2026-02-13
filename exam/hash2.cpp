#include <iostream>
#include <iomanip>
using namespace std;

class record {
public:
    int rollno, marks;
    char name[20];
};

class hashing {
public:
    int rollno, pos;
    hashing() {
        rollno = -1;
        pos = -1;
    }
};

class student {
    record rec;
    hashing h[10];
    record matrix[10]; // Memory-based storage
    int relt;
public:
    student();
    void create_wor();
    void create_wr();
    void display();
    void display_all();
    void display_hash_table();
};

student::student() {
    relt = 0;
    for (int i = 0; i < 10; i++) {
        h[i].rollno = -1;
        h[i].pos = -1;
        matrix[i].rollno = -1;
    }
}

void student::create_wr() {
    char ans;
    hashing temp;
    int loc, nloc;

    do {
        cout << "\nEnter the details:\n";
        cout << "Roll no.: ";
        cin >> rec.rollno;
        cout << "Name:\t";
        cin >> rec.name;
        cout << "Marks:\t";
        cin >> rec.marks;

        loc = rec.rollno % 10;

        if (h[loc].rollno == -1) {
            h[loc].rollno = rec.rollno;
            h[loc].pos = loc;
            matrix[loc] = rec;
        } else {
            temp.rollno = h[loc].rollno;
            temp.pos = h[loc].pos;

            h[loc].rollno = rec.rollno;
            h[loc].pos = loc;
            matrix[loc] = rec;

            // Place displaced record to next available slot
            nloc = (loc + 1) % 10;
            while (h[nloc].rollno != -1) {
                nloc = (nloc + 1) % 10;
                if (nloc == loc) {
                    cout << "\nHash table is full! Cannot insert record.\n";
                    return;
                }
            }

            h[nloc].rollno = temp.rollno;
            h[nloc].pos = nloc;
            matrix[nloc] = matrix[temp.pos];
        }

        cout << "\nDo you want to add next student record? (y/n): ";
        cin >> ans;
    } while (ans == 'y' || ans == 'Y');
}

void student::create_wor() {
    char ans;
    int loc;

    do {
        cout << "\nEnter the details:\n";
        cout << "Roll no.: ";
        cin >> rec.rollno;
        cout << "Name:\t";
        cin >> rec.name;
        cout << "Marks:\t";
        cin >> rec.marks;

        loc = rec.rollno % 10;

        int originalLoc = loc;
        while (h[loc].rollno != -1) {
            loc = (loc + 1) % 10;
            if (loc == originalLoc) {
                cout << "\nHash table is full! Cannot insert record.\n";
                return;
            }
        }

        h[loc].rollno = rec.rollno;
        h[loc].pos = loc;
        matrix[loc] = rec;

        cout << "\nDo you want to add next student record? (y/n): ";
        cin >> ans;
    } while (ans == 'y' || ans == 'Y');
}

void student::display() {
    int roll;
    cout << "\nEnter Roll No. to search: ";
    cin >> roll;

    int loc = roll % 10;
    int originalLoc = loc;
    bool found = false;

    while (h[loc].rollno != -1) {
        if (h[loc].rollno == roll) {
            rec = matrix[loc];
            cout << "\nRecord found:\n";
            cout << "Roll No.: " << rec.rollno << "\n";
            cout << "Name: " << rec.name << "\n";
            cout << "Marks: " << rec.marks << "\n";
            found = true;
            break;
        }

        loc = (loc + 1) % 10;
        if (loc == originalLoc) {
            break;
        }
    }

    if (!found) {
        cout << "\nRecord not found!\n";
    }
}

void student::display_all() {
    cout << "\n---------------------------------------------\n";
    cout << setw(10) << left << "Roll No."
         << setw(20) << left << "Name"
         << setw(10) << left << "Marks" << "\n";
    cout << "---------------------------------------------\n";

    for (int i = 0; i < 10; i++) {
        if (matrix[i].rollno != -1) {
            cout << setw(10) << left << matrix[i].rollno
                 << setw(20) << left << matrix[i].name
                 << setw(10) << left << matrix[i].marks << "\n";
        }
    }

    cout << "---------------------------------------------\n";
}

void student::display_hash_table() {
    cout << "\n----- Hash Table -----\n";
    cout << "Index\tRoll No.\tPosition\n";
    for (int i = 0; i < 10; i++) {
        if (h[i].rollno != -1) {
            cout << i << "\t" << h[i].rollno << "\t\t" << h[i].pos << "\n";
        } else {
            cout << i << "\t" << "Empty" << "\n";
        }
    }
}

int main() {
    student s;
    int choice;

    do {
        cout << "\n -----------student database------------";
        cout << "\n1. Create with Replacement";
        cout << "\n2. Create without Replacement";
        cout << "\n3. Display Record";
        cout << "\n4. Display All Records";
        cout << "\n5. Display Hash Table";
        cout << "\n0. Exit\n";
        cin >> choice;

        switch (choice) {
            case 1: s.create_wr(); break;
            case 2: s.create_wor(); break;
            case 3: s.display(); break;
            case 4: s.display_all(); break;
            case 5: s.display_hash_table(); break;
            case 0: cout << "\nExiting...\n"; break;
            default: cout << "\nInvalid choice.\n"; break;
        }
    } while (choice != 0);

    return 0;
}
