#include <iostream>
#include <bitset>
#include <vector>
#include <windows.h>
#include <algorithm>
using namespace std;

class student {
    int id;
    string name;
    int age, phonenumber;
    double gpa;
public:
    student(int Id, string nam, int Age, int phone, double Gpa) {
        id = Id;
        name = nam;
        age = Age;
        phonenumber = phone;
        gpa = Gpa;
    }
    string getname() {
        return name;
    }
    int getphone() {
        return phonenumber;
    }
    int getid() {
        return id;
    }
    double getgpa() {
        return gpa;
    }
    int getage() {
        return age;
    }
    void setid(int idd) {
        id = idd;
    }
    void setname(string namee) {
        name = namee;
    }
    void setage(int agee) {
        age = agee;
    }
};

void interfaces() {
    cout << "---+---+---+---+---+---+---+" << endl;
    cout << "    Student Management        " << endl;
    cout << "---+---+---+---+---+---+---+" << endl;
    cout << "1.Add New Student" << endl;
    cout << "2.Display All Student" << endl;
    cout << "3.Search Student" << endl;
    cout << "4.Update Student" << endl;
    cout << "5.Delete Student" << endl;
    cout << "6.Exit " << endl;
}

class studentmangment {
    vector<student> students;

    // Sort students by id for binary search
    void sort_students_by_id() {
        sort(students.begin(), students.end(), [](student a, student b) {
            return a.getid() < b.getid();
        });
    }

public:
    void getinfo() {
        string name;
        int id, age, phone;
        double gpa;
        cout << "Enter your Name:";
        cin >> name;
        cout << "Enter your Id:";
        cin >> id;
        for (int i = 0; i < students.size(); i++) {
            if (students[i].getid() == id) {
                cout << "Student already exists!!" << endl;
                return;
            }
        }
        cout << "Enter your Phone number:";
        cin >> phone;
        cout << "Enter your Age:";
        cin >> age;
        cout << "Enter your Gpa:";
        cin >> gpa;
        student st(id, name, age, phone, gpa);
        students.push_back(st);
        sort_students_by_id();  // Ensure the vector is sorted after adding a new student
        cout << "Student added successfully..." << endl;
    }

    void displaystudents() {
        if (students.size() == 0)
            cout << "There aren't any Students!!" << endl;
        else {
            for (int i = 0; i < students.size(); i++) {
                cout << students[i].getname() << endl;
            }
        }
    }

    void search(int id) {
        sort_students_by_id();
        int left = 0, right = students.size() - 1;
        bool found = false;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (students[mid].getid() == id) {
                found = true;
                cout << "Name: " << students[mid].getname() << endl;
                cout << "Age: " << students[mid].getage() << endl;
                cout << "Phone number: " << students[mid].getphone() << endl;
                cout << "ID: " << students[mid].getid() << endl;
                cout << "GPA: " << students[mid].getgpa() << endl;
                break;
            }
            else if (students[mid].getid() < id) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        if (found)
            cout << "Student found!!" << endl;
        else
            cout << "Student isn't found..." << endl;
    }
    void deletes(int id) {
        for (int i = 0; i < students.size(); i++) {
            if (students[i].getid() == id) {
                students.erase(students.begin() + i);
                cout << "User removed successfully..." << endl;
                break;
            }
        }
    }

    void updaterecord() {
        bool check = 0;
        int id;
        int choice;
        cout << "Enter Id to update record:";
        cin >> id;
        for (int i = 0; i < students.size(); i++) {
            if (students[i].getid() == id) {
                check = 1;
                cout << "---Student found---" << endl;
                cout << "1.Update Id " << endl;
                cout << "2.Update Name " << endl;
                cout << "3.Update Age " << endl;
                cout << "Enter your choice:";
                cin >> choice;
                switch (choice) {
                    case 1: {
                        int Id;
                        cout << "Enter New Id:";
                        cin >> Id;
                        students[i].setid(Id);
                        sort_students_by_id();  // Re-sort after ID change
                        cout << "Record Updated Successfully..." << endl;
                        break;
                    }
                    case 2: {
                        string name;
                        cout << "Enter New Name:";
                        cin >> name;
                        students[i].setname(name);
                        cout << "Record Updated Successfully..." << endl;
                        break;
                    }
                    case 3: {
                        int age;
                        cout << "Enter New Age:";
                        cin >> age;
                        students[i].setage(age);
                        cout << "Record Updated Successfully..." << endl;
                        break;
                    }
                    default:
                        cout << "Invalid number.." << endl;
                }
                break;
            }
        }
        if (!check) cout << "Student not found..." << endl;
    }
};

int main() {
    int choice;
    studentmangment st;
    do {
        system("cls");
        interfaces();
        cout << "Enter your choice :";
        cin >> choice;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(512, '\n');
        }
        switch (choice) {
            case 1: {
                st.getinfo();
                Sleep(1000);
                break;
            }
            case 2:
                st.displaystudents();
                Sleep(2000);
                break;
            case 3: {
                int id;
                cout << "Enter your Id:";
                cin >> id;
                st.search(id);
                Sleep(2000);
                break;
            }
            case 4: {
                st.updaterecord();
                Sleep(2000);
                break;
            }
            case 5: {
                int id;
                cout << "Enter your Id:";
                cin >> id;
                st.deletes(id);
                Sleep(1000);
                break;
            }
        }
    } while (choice != 6);
}
