#include <iostream>
#include <string>
#include <map>
#include <iomanip>
#include <conio.h>

using namespace std;

class Person {
protected:
    string name;
    int age;
    bool gender; // true for male, false for female

public:
    Person() : name(""), age(0), gender(true) {}
    Person(string n, int a, bool g) : name(n), age(a), gender(g) {}

    void setName()
     { string x;
       cout << "Patient Name: ";
       getline(cin, x);
       name = x; 
     }
    void setAge() 
    {int a; 
    cout << "\nAge: ";
    cin>>a;
    a = age; }
    void setGender()
    { bool g;
      cout << "\nGender: \nPress: 1) Male 0) Female \nChoose: ";
      cin>>g;
      gender=g;
    }

    string getName() const { return name; }
    int getAge() const { return age; }
    bool getGender() const { return gender; }

    virtual void display() const {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Gender: " << (gender ? "Male" : "Female") << endl;
    }
};

class Patient : public Person {
public:
    Patient() : Person() {}
    Patient(string n, int a, bool g) : Person(n, a, g) {}

    void display() const override {
        cout << "Patient Details:" << endl;
        Person::display();
    }
};

class Appointment {
private:
    Patient patient;
    string date;
    string doctorName;

public:
    Appointment() : date(""), doctorName("") {}
    Appointment(Patient p, string d, string dn) : patient(p), date(d), doctorName(dn) {}

    void setPatient(const Patient& p) { patient = p; }
    void setDate(const string& d) { date = d; }
    void setDoctorName(const string& dn) { doctorName = dn; }

    Patient getPatient() const { return patient; }
    string getDate() const { return date; }
    string getDoctorName() const { return doctorName; }

    void display() const {
        cout << "Appointment Details:" << endl;
        patient.display();
        cout << "Date: " << date << endl;
        cout << "Doctor: " << doctorName << endl;
    }
};

map<int, Appointment> patient_appointment_data = {
    {1, Appointment(Patient("John Mety", 34, true), "2024-06-10", "Dr. Smith")},
    {2, Appointment(Patient("Kim Lee", 56, false), "2024-06-15", "Dr. Johnson")},
    {3, Appointment(Patient("Doren Maj", 95, true), "2024-06-20", "Dr. Brown")},
    {4, Appointment(Patient("Alice", 25, false), "2024-06-25", "Dr. Anderson")},
    {5, Appointment(Patient("Bob", 30, true), "2024-06-30", "Dr. Martinez")},
    {6, Appointment(Patient("Charlie", 40, true), "2024-07-05", "Dr. Wilson")}
};

class System {
public:
    void main_menu();
    void patients_menu();
    void appointments_menu();
    void addPatient();
    void removePatient();
    void viewAllPatients();
    void searchPatient();
    void addAppointment();
    void removeAppointment();
    void viewAppointments();
    void editAppointment();
};

void System::main_menu() {
    string input;
    char choice;
    bool validInput = false;

    system("cls");
    cout << "----------------------------------------------" << endl;
    cout << "        Health Care Management System\n";
    cout << "----------------------------------------------" << endl << endl;
    cout << "          |        Admin Menu        |\n\n\n\n";

    cout << "1) Patients" << endl;
    cout << "2) Appointments" << endl;
    cout << "3) Logout" << endl;

    while (!validInput) {
        cout << "\nChoose: ";
        cin >> input;
        system("cls");

        if (input.length() == 1 && isdigit(input[0])) {
            choice = input[0];
            validInput = true;
        } else {
            cout << "**Invalid Input**\n\n";
            system("pause");
            main_menu();
            cin.ignore();
        }
    }

    switch (choice) {
        case '1':
            patients_menu();
            break;

        case '2':
            appointments_menu();
            break;

        case '3':
            cout << "----------------------------------------------" << endl;
            cout << "        Health Care Management System\n";
            cout << "----------------------------------------------" << endl << endl;
            cout << "          |       System Closed      |\n\n\n\n";
            cout << "                    Logged Out      \n\n\n\n\n";
            exit(0);

        default:
            system("cls");
            cout << "**Invalid Input**\n\n";
            system("pause");
            main_menu();
    }
}

void System::patients_menu() {
    string input;
    char choice;
    bool validInput = false;

    system("cls");
    cout << "----------------------------------------------" << endl;
    cout << "        Health Care Management System\n";
    cout << "----------------------------------------------" << endl << endl;
    cout << "          |         Patients         |\n\n\n\n";
    cout << "1) Add Patient" << endl;
    cout << "2) Remove Patient" << endl;
    cout << "3) View All Patients" << endl;
    cout << "4) Search Patient" << endl;
    cout << "5) Main Menu" << endl;
    cout << endl;

    while (!validInput) {
        cout << "Choose: ";
        cin >> input;
        system("cls");

        if (input.length() == 1 && isdigit(input[0])) {
            choice = input[0];
            validInput = true;
        } else {
            cout << "Invalid Input...\n\n" << endl;
            system("pause");
            patients_menu();
            cin.ignore();
        }
    }

    switch (choice) {
        case '1':
            addPatient();
            break;

        case '2':
            removePatient();
            break;

        case '3':
            viewAllPatients();
            break;

        case '4':
            searchPatient();
            break;

        case '5':
            main_menu();
            break;

        default:
            system("cls");
            cout << "Invalid Input...\n\n";
            system("pause");
            patients_menu();
    }
}

void System::addPatient() {
    Patient tmp_patient;
    system("cls");
    cout << "----------------------------------------------" << endl;
    cout << "        Health Care Management System\n";
    cout << "----------------------------------------------" << endl << endl;
    cout << "          |    New Patient Record    |\n\n\n\n";
    cin.ignore();
    
    tmp_patient.setName();

    tmp_patient.setAge();
    
    tmp_patient.setGender();

    int id = patient_appointment_data.size() + 1;
    patient_appointment_data[id] = Appointment(tmp_patient, "", "");
    cout << endl;
    cout << "Patient Added..." << endl;
    system("pause");
    patients_menu();
    cout << endl;
}

void System::removePatient() {
    int id;
    cout << "Enter patient ID to remove: ";
    cin >> id;
    auto it = patient_appointment_data.find(id);

    if (it != patient_appointment_data.end()) {
        patient_appointment_data.erase(it);
        cout << "Patient Removed..." << endl;
    } else {
        cout << "No Patient Found with ID: " << id << endl;
    }
    system("pause");
    patients_menu();
}

void System::viewAllPatients() {
    system("cls");
    cout << "----------------------------------------------" << endl;
    cout << "        Health Care Management System\n";
    cout << "----------------------------------------------" << endl << endl;
    cout << "          |     Patients Records     |\n\n\n";

    cout << setw(4) << left << "ID"
         << setw(15) << left << "Name"
         << setw(10) << left << "Gender"
         << setw(4) << left << "Age" << endl;
    cout << "-------------------------------------" << endl;
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
    for (auto &i : patient_appointment_data)
        {
            cout << setw(4) << left << i.first
                 << setw(15) << left << i.second.getPatient().getName();
            if (i.second.getPatient().getGender() == 1 )
            {
                cout << setw(10) << left << "Male";
            }
            else
            {
                cout << setw(10) << left << "Female";
            }
            cout << setw(4) << left << i.second.getPatient().getAge() << endl;
        }
        cout << endl;
        cout << endl;

//----------------------------------------------------------------------------
//----------------------------------------------------------------------------

    system("pause");
    patients_menu();
}

void System::searchPatient() {
    int id;
    cout << "Enter patient ID to search: ";
    cin >> id;
    auto it = patient_appointment_data.find(id);

    if (it != patient_appointment_data.end()) {
        it->second.getPatient().display();
    } else {
        cout << "No Patient Found with ID: " << id << endl;
    }
    system("pause");
    patients_menu();
}

void System::appointments_menu() {
    string input;
    char choice;
    bool validInput = false;

    system("cls");
    cout << "----------------------------------------------" << endl;
    cout << "        Health Care Management System\n";
    cout << "----------------------------------------------" << endl << endl;
    cout << "          |      Appointments        |\n\n\n\n";
    cout << "1) Add Appointment" << endl;
    cout << "2) Remove Appointment" << endl;
    cout << "3) View Appointments" << endl;
    cout << "4) Edit Appointment" << endl;
    cout << "5) Main Menu" << endl;
    cout << endl;

    while (!validInput) {
        cout << "Choose: ";
        cin >> input;
        system("cls");

        if (input.length() == 1 && isdigit(input[0])) {
            choice = input[0];
            validInput = true;
        } else {
            cout << "Invalid Input...\n\n" << endl;
            system("pause");
            appointments_menu();
            cin.ignore();
        }
    }

    switch (choice) {
        case '1':
            addAppointment();
            break;

        case '2':
            removeAppointment();
            break;

        case '3':
            viewAppointments();
            break;

        case '4':
            editAppointment();
            break;

        case '5':
            main_menu();
            break;

        default:
            system("cls");
            cout << "Invalid Input...\n\n";
            system("pause");
            appointments_menu();
    }
}

void System::addAppointment() {
    int id;
    string date, doctorName;
    Patient tmp_patient;

    cout << "Enter patient ID: ";
    cin >> id;
    auto it = patient_appointment_data.find(id);

    if (it != patient_appointment_data.end()) {
        tmp_patient = it->second.getPatient();
    } else {
        cout << "No Patient Found with ID: " << id << endl;
        return;
    }

    cout << "Enter appointment date (YYYY-MM-DD): ";
    cin >> date;
    cout << "Enter doctor name: ";
    cin.ignore();
    getline(cin, doctorName);

    patient_appointment_data[id] = Appointment(tmp_patient, date, doctorName);
    cout << "Appointment Added..." << endl;
    system("pause");
    appointments_menu();
}

void System::removeAppointment() {
    int id;
    cout << "Enter patient ID to remove appointment: ";
    cin >> id;
    auto it = patient_appointment_data.find(id);

    if (it != patient_appointment_data.end()) {
        it->second.setDate("");
        it->second.setDoctorName("");
        cout << "Appointment Removed..." << endl;
    } else {
        cout << "No Appointment Found with ID: " << id << endl;
    }
    system("pause");
    appointments_menu();
}

void System::viewAppointments() {
    system("cls");
    cout << "----------------------------------------------" << endl;
    cout << "        Health Care Management System\n";
    cout << "----------------------------------------------" << endl << endl;
    cout << "          |   Appointments Records   |\n\n\n";

    cout << setw(4) << left << "ID"
         << setw(15) << left << "Patient Name"
         << setw(8) << left << "Gender"
         << setw(5) << left << "Age"
         << setw(15) << left << "Doctor"
         << setw(12) << left << "Date" << endl;
    cout << "-----------------------------------------------------------" << endl;
    for (const auto& i : patient_appointment_data) {

        cout << setw(4) << left << i.first
             << setw(15) << left << i.second.getPatient().getName();
             if (i.second.getPatient().getGender() == 1 )
            {
                cout << setw(8) << left << "Male";
            }
            else
            {
                cout << setw(8) << left << "Female";
            }
        cout << setw(5) << left << i.second.getPatient().getAge()
             << setw(15) << left << i.second.getDoctorName()
             << setw(12) << left << i.second.getDate()<<endl;
    }
    cout<<endl;
    system("pause");
    appointments_menu();
}

void System::editAppointment() {
    int id;
    string date, doctorName;

    cout << "Enter patient ID to edit appointment: ";
    cin >> id;
    auto it = patient_appointment_data.find(id);

    if (it != patient_appointment_data.end()) {
        cout << "Enter new appointment date (YYYY-MM-DD): ";
        cin >> date;
        cout << "Enter new doctor name: ";
        cin.ignore();
        getline(cin, doctorName);

        it->second.setDate(date);
        it->second.setDoctorName(doctorName);

        cout << "Appointment Updated..." << endl;
    } else {
        cout << "No Appointment Found with ID: " << id << endl;
    }
    system("pause");
    appointments_menu();
}

int main() {
    System system;
    system.main_menu();
    return 0;
}
