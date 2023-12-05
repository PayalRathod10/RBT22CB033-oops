#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include<conio.h>

using namespace std;

class User {
public:

    string buff;
    string name;
    string dob;
    string address;
    string caste;
    string cat;
    string a;
    string age;
    float ten;
    float tw;
    double fees;
    string username;
    string password;

    void buffer() 
    {
        getline(cin, buff);
    }

    void PersonalInfo() 
    {
        int ch;
        cout<<"Enter your name: "; getline(cin, name);
        cout<<endl<<"Enter your Date of Birth: "; getline(cin, dob);
        cout<<endl<<"Enter your Address: "; getline(cin, address);
        cout<<endl<<"Enter your Age: "; getline(cin, age);
        cout<<endl<<"Enter your Caste: "; getline(cin, caste);
        cout<<endl<<"Enter Category: "; getline(cin, cat);
        cout<<endl<<"Enter any Government Id:"<<endl<<"1)Aadhaar Card"<<endl<<"2)PAN Card"<<endl<<"3)Driving Licence"<<endl;
        cout<<"ENTER CHOICE: "; cin>>ch; cout<<endl;
        switch(ch)
        {
            case 1: 
            //int ad;
            cout<<"Enter Aadhar Card Number: "; cin>>a;
            cout<<"Aadhar Card Uploaded"<<endl<<endl; 
            break;
            case 2: 
            //int pn;
            cout<<"Enter PAN Card ID: "; cin>>a;
            cout<<"PAN card Uploaded"<<endl<<endl; 
            break;
            case 3:
            //int dl;
            cout<<"Enter Driving Licence ID: "; cin>>a;
            cout<<"PAN card Uploaded"<<endl<<endl; 
            break;
            default: cout<<"WRONG CHOICE"; break;
        }
   }

    void Qualifications() 
    {
        cout << "Enter your 10th Marks: "; cin>>ten;
        cout << "Enter your 12th Marks: "; cin>>tw; cout<<endl;
    }

    void Fees() 
    {
        do 
        {
            cout << "Enter exam fees (2000 rupees): ₹";
            cin >> fees;

            if (fees != 2000) 
            {
                cout << "Invalid amount. Please pay 2000 rupees.\n";
            }
        } 
        while (fees != 2000);
        cout<<"FEES UPLOADED!"<<endl;
    }

    void Credentials() 
    {
        cout << "Enter username (email): ";
        cin.ignore(); // to clear the newline character left in the buffer
        getline(cin, username);

        cout << "Enter password: ";
        getline(cin, password);
        cout<<endl;
    }

    void display() 
    {
        cout << "\n\nPersonal Information:\n";
        cout << "Name: " << name << endl;
        cout<<"Date of Birth: "<<dob<<endl;
        cout<<"Address: "<<address<<endl;
        cout<<"Age: "<< age<<endl;
        cout<<"Caste: "<< caste<<endl;
        cout<<"Category: "<<cat<<endl;
        cout << "Government ID: " << a << endl;
        cout << "\nQUALIFICATIONS::\n\n";
        cout << "10th Marks: " << ten << endl;
        cout << "12th Marks: " << tw << endl;
    }
};

void registerUser(User &newUser) 
//if no & --> call by value --> copy of the object is created and information is stored in it.
//but we want to store the information in the main object (i.e a in main function) so we put '&'
//& --> call by reference --> Address is passed.
//newUser stores the address of the main object a.
{

    cout << endl << "**** Registration ****\n"<<endl;

    newUser.buffer();
    cout<<"**PERSONAL INFORMATION**"<<endl;
    newUser.PersonalInfo(); //PersonalInfo is a member function
    cout<<"**QUALIFICATIONS** "<<endl;
    newUser.Qualifications();
    cout<<"**FEES**"<<endl;
    newUser.Fees();
    cout<<endl<<"**CREDENTIALS**"<<endl;
    newUser.Credentials();

    ofstream File("user.txt");//ofstream -->for creating and opening the file

    File << newUser.username << "\n";
    File << newUser.password << "\n";

    File.close();

    cout << "Registration successful!\n"<<endl;
}

// Function to login
void loginUser(User &a1) 
{
    string username, password;

    cout << endl << "**** Login ****\n\n";
    cout << "Enter username (email): ";
    cin.ignore(); 
    getline(cin, username);

    char ch;
    cout << "Enter password: ";
    while (true) {
        ch = _getch(); 
        if (ch == 13) 
            break;
        cout << '*';
        password.push_back(ch);
    }

    ifstream F("user.txt");//FOR READING IN FILE  

    string storedUsername, storedPassword;

    //ENTER USERNAME AND PASSWORD IS CHECKED WITH STORED USERNAME AND PASSWORD
    while (getline(F, storedUsername) && getline(F, storedPassword)) {
        if (storedUsername == username && storedPassword == password) {
            cout << "Login successful!\n";
            a1.display();
            return;
        }
    }
    F.close();

    cout <<endl<< "Login failed. Incorrect username or password.\n"<<endl;
}


int main() 
{
    User a;
    int choice;  

    do 
    {
        cout << "***** Exam System ******\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:

                registerUser(a);
                break;

            case 2:

                loginUser(a);
                break;

            case 3:

                cout << "Exit\n";
                break;

            default:

                cout << "Invalid choice. Please try again.\n";

        }
    } 
    
    while (choice != 3);

    return 0;
}