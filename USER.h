#pragma once
#pragma once

#include <iostream>
#include <fstream>
#include <cmath>

#ifndef USER_H

using namespace std;

class User // database parent class
{
private:
    // string Usernames[1000];
    // string Passwords[1000];
    string Usernames[1000];
    string NamesOfCustomers[1000];
    char CNIC[20];
    char UName[20];
    char Pass[20];
    char NameCus[20];
    char CustomerNum[20];
    string ManagerNames[1000];
    string ManagerLocations[1000];
    string ManagerUnames[1000];
    string ManagerPhoneNums[1000];
    string ManagerPwords[1000];
    string ManagerGenders[1000];
    long long int ManagerCNICs[1000];
    string Passwords[1000];
    long long int CNICs[1000];
    string GenderCustomers[1000];
    long long int PhoneNumbers[1000];
    string AdminUNPredefined;
    string AdminPWPredefined;
    char Whichuser;
    char whichlogic;
    static int Managernumber;
    // logic : 1 function, that is void showmenu is there for user admin and manager, base pointer method
protected:
    string Password;
    string Username;
    int loggedinornotUSER;

    void SetAdminUsernameAndPassword()
    {
        this->AdminUNPredefined = "Admin";
        this->AdminPWPredefined = "Admin123";
        
        ofstream mywritingfile("AdminHAHAHAH.bin", ios::binary);
        User obj;
       

        mywritingfile.write((char *)&obj, sizeof(obj));

        mywritingfile.close();
    }
    void ValidateLogin() // For C, A, M This functions works differently
    {
        string INTBACKGROUND("\033[31;43m");
        cout << INTBACKGROUND;
        // cout << "LOGIC BEING WORKED IS : " << whichlogic << endl;

        // cout << "THEN WHY DOES THIS WORK?" << endl;

        if (Whichuser == 'C')
        {

            if (AccountRepititionCheck(Username, Password) == 1) // If account is not repeated logg in
            {
                string Green("\033[0;32m");
                cout << Green << "LOGGED IN SUCCESFULLY!" << endl;
                loggedinornotUSER = 1;
            }
            else
            {
                cout << "COULD NOT FIND AN ACCOUNT" << endl;
                cout << "Try again? (Y|N)" << endl;
                char temp222;
                cin >> temp222;
                while (temp222 != 'Y' && temp222 != 'N')
                {
                    cout << "\033[1;31mPlease Select Only From The Given Options!\033[0m\n";
                    cin >> temp222;
                }
                if (temp222 == 'Y')
                {
                    cin >> Username;
                    cin >> Password;
                    ValidateLogin();
                }
            }
        }
        else if (Whichuser == 'A')
        {
            if (AccountRepititionCheck(Username, Password) == 1)
            {
                cout << "LOGGED IN SUCCESFULLY!" << endl;
                loggedinornotUSER = 1;
            }
            else
            {
                cout << "COULD NOT FIND AN ACCOUNT" << endl;
                cout << "Try again? (Y|N)" << endl;
                char temp;
                cin >> temp;
                while (temp != 'Y' && temp != 'N')
                {
                    cout << "\033[1;31mPlease Select Only From The Given Options!\033[0m\n";
                    cin >> temp;
                }
                if (temp == 'Y')
                {
                    cin >> Username;
                    cin >> Password;
                    ValidateLogin();
                }
            }
        }
        else if (Whichuser == 'M')
        {

            if (AccountRepititionCheck(Username, Password) == 1)
            {
                cout << "LOGGED IN SUCCESFULLY!" << endl;
                loggedinornotUSER = 1;
            }
            else
            {
                cout << "COULD NOT FIND AN ACCOUNT" << endl;
                cout << "Try again? (Y|N)" << endl;
                char temp;
                cin >> temp;
                if (temp == 'Y')
                {
                    cin >> Username;
                    cin >> Password;
                    ValidateLogin();
                }
            }
        }
    }
    static int CustomerNumber;
    void GetterDisplay()
    {
        DataBaseDisplay();
    }
    bool AccountRepititionCheck(string Username, string Password)
    { // Boolean Function Checks If account Has been Repeated or Not
        string INTBACKGROUND("\033[31;43m");
        cout << INTBACKGROUND;

        string ineed;
        string ineed2;
        int a = CustomerNumber - 1;

        ineed = Usernames[a];
        ineed2 = Usernames[a];

        if (Whichuser == 'C')
        {

            // cout << "Enters here definitely" << endl;

            for (int i = 0; i < 1000; i++)
            {
                if (Password.compare(Passwords[i]) == 0)
                {
                    cout << "Password has been found" << endl;
                    if (Username.compare(Usernames[i]) == 0)
                    {
                        cout << "username has been found" << endl;
                        return 1;
                    }
                }
                else
                {
                    continue;
                }
            }
            return 0;
        }

        else if (Whichuser == 'A') // For ADMIN PREDEFINED
        {
            while (Username != AdminUNPredefined || Password != AdminPWPredefined)
            {
                // cout << "" << endl;
                cout << "\033[1;31mYou cannot procede, these are wrong admin credentials\033[0m\n";
                return 0;
            }
            return 1;
        }

        else if (Whichuser == 'M')
        {
            for (int i = 0; i < 1000; i++)
            {
                // cout << "UN"
                //   << " " << ManagerUnames[i] << endl;
            }
            for (int i = 0; i < 1000; i++)
            {
                if (Password.compare(ManagerPwords[i]) == 0 && Username.compare(ManagerUnames[i]) == 0)
                {

                    // cout << "You are already registered within the system!" << endl;
                    return 1;
                }
                else
                {
                    continue;
                }
            }
            return 0;
        }

        return 0;
    }
    bool AccountRepititionCheck2(long long int CNICREVC) // Another checker function based on CNIC
    {                                                    // for manager , user and customer
        if (Whichuser == 'C')
        {

            for (int i = 0; i < 1000; i++)
            {
                if (CNICREVC == CNICs[i])
                {
                    cout << "You are already registered within the system!" << endl;
                    return 1;
                }
                else
                {
                    // CustomerNumber++;
                    return 0;
                }
            }
        }
        else if (Whichuser == 'M')
        {
            for (int i = 0; i < 1000; i++)
            {
                if (CNICREVC == ManagerCNICs[i])
                {
                    cout << "You are already registered within the system!" << endl;
                    return 1;
                }
                else
                {
                    // CustomerNumber++;
                    return 0;
                }
            }
        }
        return 0;
    }

    void setUsernameAndPasword(string UN, string PW)
    {
        // Setter For UserName And Password
        Username = UN;
        Password = PW;
    }

public:
    void WhichUserSetter(char I)
    {
        this->Whichuser = I;
    }
    virtual void showmenu() // Show Menu Used Here TOO. ACCESSED POLYMORPHICALLY
    {
        cout << "Base" << endl;
    }

    void DataBaseDisplay() // INCASE DATABASE IS NEEDED TO DISPLAY
    {
        if (Whichuser == 'C')
        {
            cout << "HMM" << UName << endl;

            // for (int i = 0; i < CustomerNumber; i++)
            //     cout << "Customer NO: " << i << "    "
            //          << "Username:"
            //          << "  " << Usernames[i] << "Passwords : " << Passwords[i] << endl;
        }
        else if (Whichuser == 'M')
        {
            for (int i = 0; i < Managernumber; i++)
                cout << "Manager NO: " << i << "    "
                     << "Username:"
                     << "  " << ManagerUnames[i] << "Passwords : " << ManagerPwords[i] << endl;
        }
    }

public:
    void CheckForFile()
    {
        cout << "Customer Username: " << CustomerNum << endl;
        cout << "Customer Password : " << NameCus << endl;
    }
    void whichlogicsetter(char a)
    {
        this->whichlogic = a;
    }
    User(User &a)
    {
        for (int i = 0; i < 1000; i++)
        {
            Usernames[i] = a.Usernames[i];
            Passwords[i] = a.Passwords[i];
            CNICs[i] = a.CNICs[i];
        }
        this->Password = a.Password;
        this->Username = a.Username;
    }
    User()
    {
    }
    void tempblock(string &Name, string &Gender, string &UN, string &PW, long long int &CNIC, long long int &PN, int &tempint)
    { // A function with validation that enters data for Users
        string INTBACKGROUND("\033[31;43m");
        cout << INTBACKGROUND;
        cout << "Enter your Phonenumber:" << endl;
        cin >> PN;
        while ((floor(log10(PN)) + 1) < 10)
        {
            cout << "PHONE NUMBER IS TOO SMALL!" << endl;
            cin >> PN;
            cout << INTBACKGROUND;
        }
        cout << "Enter Your First Name Only " << endl;
        cin >> Name;
        while (Name.length() <= 2)
        {
            cout << "Name is too small, re-enter!" << endl;
            cin >> Name;
            cout << INTBACKGROUND;
        }
        cout << "Enter Your CNIC (Without Hypens):" << endl;
        cin >> CNIC;
        while (floor(log10(CNIC) + 1) < 12)
        {
            cout << "CNIC MUST BE GREATER THAN 12 digits";
            cin >> CNIC;
            cout << INTBACKGROUND;
        }

        cout << "Are you a : " << endl;
        cout << "\t 1.Male\n\t 2.Female\n\t 3.Other\n";
        cin >> tempint;
        while (tempint != 1 && tempint != 2 && tempint != 3)
        {
            cout << "Wrong Option, Re enter!" << endl;
            cin >> tempint;
            cout << INTBACKGROUND;
        }

        if (tempint == 1)
        {
            Gender = "Male";
        }
        else if (tempint == 2)
        {

            Gender = "Female";
        }
        else
        {
            Gender = "Other";
        }
        cout << "Enter your preffered User name" << endl;
        cin >> UN;
        while (UN.length() < 4)
        {
            cout << "Username is too small" << endl;
            cin >> UN;
            cout << INTBACKGROUND;
        }
        cout << "Enter your password" << endl;
        cin >> PW;
        while (PW.length() < 6)
        {
            cout << "Password is too small" << endl;
            cin >> PW;
            cout << INTBACKGROUND;
        }
    }

    void tempblock2(string &Name, string &Gender, string &UN, string &PW, long long int &CNIC, long long int &PN, int &tempint)
    { // A function that enters data for managers
        string INTBACKGROUND("\033[31;43m");
        cout << INTBACKGROUND;
        cout << "Enter Managers Phonenumber:" << endl;
        cin >> PN;
        while ((floor(log10(PN)) + 1) < 10)
        {
            cout << "PHONE NUMBER IS TOO SMALL" << endl;
            cin >> PN;
            cout << INTBACKGROUND;
        }
        cout << "Enter Manager's Name:" << endl;
        cin >> Name;
        while (Name.length() <= 2)
        {
            cout << "Name is too small, re-enter:" << endl;
            cin >> Name;
            cout << INTBACKGROUND;
        }
        cout << "Enter their CNIC (Without Hypens):" << endl;
        cin >> CNIC;
        while (floor(log10(CNIC) + 1) < 12)
        {
            cout << "CNIC MUST BE GREATER THAN 12 digits";
            cin >> CNIC;
            cout << INTBACKGROUND;
        }
        cout << " Gender? : " << endl;
        cout << "\t 1.Male\n\t 2.Female\n\t 3.Other\n";
        cin >> tempint;
        cout << INTBACKGROUND;
        if (tempint == 1)
        {
            Gender = "Male";
            cout << INTBACKGROUND;
        }
        else if (tempint == 2)
        {

            Gender = "Female";
            cout << INTBACKGROUND;
        }
        else
        {
            Gender = "Other";
            cout << INTBACKGROUND;
        }
        cout << "ASSIGN A USERNAME to Manager:" << endl;
        cin >> UN;
        while (UN.length() < 4)
        {
            cout << "Username is too small!" << endl;
            cin >> UN;
            cout << INTBACKGROUND;
        }
        cout << "Assign A PASSWORD to Manager:" << endl;
        cin >> PW;
        while (PW.length() < 6)
        {
            cout << "Password is too small!" << endl;
            cin >> PW;
            cout << INTBACKGROUND;
        }
    }

    void Register()
    { // Calls Temp functions, here registrations happen for almost everyone
        string INTBACKGROUND("\033[31;43m");
        // make reference function for concise code
        if (Whichuser == 'C')
        {

            cout << INTBACKGROUND;

            string DummyName;
            string DummyGender;
            string passworddummy;
            string UsernameDummy;
            long long int DummyCNIC;
            long long int DummyPhoneNum;
            int tempint;

            tempblock(DummyName, DummyGender, UsernameDummy, passworddummy,
                      DummyCNIC, DummyPhoneNum, tempint);

            ValidateRegistration(passworddummy);
            strcpy(this->Pass, passworddummy.c_str());
            strcpy(this->UName, UsernameDummy.c_str());

            if (AccountRepititionCheck2(DummyCNIC) == 0)
            {

                cout << INTBACKGROUND;
                // now write to a file this username and password
                // cout << "Customer number here is : " << CustomerNumber<< endl;
                // cout << "USERNAME I SEE HERE IS " << Usernames[CustomerNumber] << endl;
                // cout << "PASSWORD I SEE HERE IS " << Passwords[CustomerNumber] << endl;

                Usernames[CustomerNumber] = UsernameDummy;

                Passwords[CustomerNumber] = passworddummy;
                //  cout << "Customer number here is : " << CustomerNumber<< endl;
                // cout << "USERNAME I SEE HERE IS " << Usernames[CustomerNumber] << endl;
                // cout << "PASSWORD I SEE HERE IS " << Passwords[CustomerNumber] << endl;
                CNICs[CustomerNumber] = DummyCNIC;
                GenderCustomers[CustomerNumber] = DummyGender;
                PhoneNumbers[CustomerNumber] = DummyPhoneNum;
                NamesOfCustomers[CustomerNumber] = DummyName;
                CustomerNumber++;

                cout << "Congratulations! You are now registered" << endl;
            }
        }
        else if (Whichuser == 'M')
        {

            cout << INTBACKGROUND;
            string DummyName;
            string DummyGender;
            string passworddummy;
            string UsernameDummy;
            long long int DummyCNIC;
            long long int DummyPhoneNum;
            int tempint;
            tempblock2(DummyName, DummyGender, UsernameDummy, passworddummy,
                       DummyCNIC, DummyPhoneNum, tempint);
            ValidateRegistration(passworddummy);

            if (AccountRepititionCheck2(DummyCNIC) == 1)
            {
                cout << "You are already registered within the system!" << endl;
            }
            else if (AccountRepititionCheck2(DummyCNIC) == 0)
            {

                ManagerUnames[Managernumber] = UsernameDummy;
                ManagerPwords[Managernumber] = passworddummy;
                ManagerCNICs[Managernumber] = DummyCNIC;
                ManagerGenders[Managernumber] = DummyGender;
                ManagerPhoneNums[Managernumber] = DummyPhoneNum;

                Managernumber++;

                cout << "Congratulations! You are now registered" << endl;
            }
        }
    }
    void ManagerCreation()
    {
    }
    User(string Username, string Password, long long int CNIC) // Not used
    {
        string INTBACKGROUND("\033[31;43m");
        cout << INTBACKGROUND;
        if (AccountRepititionCheck2(CNIC) == 1)
        {
            cout << "You are already registered within the system!" << endl;
        }
        else if (AccountRepititionCheck2(CNIC) == 0)
        {
            Usernames[CustomerNumber] = Username;
            Passwords[CustomerNumber] = Password;
            CNICs[CustomerNumber] = CNIC;
            CustomerNumber++;

            cout << "Congratulations! You are now registered" << endl;
        }
    }
    void DataPopulation() // Data Population For If USer Wants to Login directly
    {

        Usernames[0] = "RAMEEL21";
        Usernames[1] = "AHSANJAMEEL61";
        Usernames[2] = "TAHA32";
        Usernames[3] = "REHMAN41";
        Usernames[4] = "ABDULLAHSHAH6";
        Usernames[5] = "AREEBJATOI89";
        Usernames[6] = "MinhaajSaqib2";
        Usernames[7] = "AdbullahSaqib";
        Passwords[0] = "123KMS";
        Passwords[1] = "LOL2";
        Passwords[2] = "786";
        Passwords[3] = "FIFA123";
        Passwords[4] = "NOMI123";
        Passwords[5] = "GOOGLE";
        Passwords[6] = "iateacupcake";
        Passwords[7] = "pewpewpew";

        // functions populates already present arrays
    }
    string ReturnMostRecentUN()
    {
        return Username;
    }
    string ReturnMostRecentPW()
    {
        return Password;
    }
    void Login()
    {
        string INTBACKGROUND("\033[31;43m");
        cout << INTBACKGROUND;
        if (Whichuser == 'A' || Whichuser == 'C')
        {

            cout << "Enter Your Username\n";
            cin >> Username;
            // cin >> UName;
            cout << "Enter Your Password\n";
            cin >> Password;
        }
        else if (Whichuser == 'M')
        {
            cout << "Enter Manager's Username to Login\n";
            cin >> Username;
            // cin >> UName;
            cout << "Enter Managers Password to Login\n";
            cin >> Password;
        }

        // cin >> Pass;
        ValidateLogin(); // Checks UN & PW AGAINST DATABASE
    }

    void ValidateRegistration(string B) // To enter password twice
    {
        string INTBACKGROUND("\033[31;43m");
        cout << INTBACKGROUND;
        string temp = B;
        int failcounter = 0;
        cout << "Please enter Your Password Again" << endl;

        cin >> Password;

        while (Password.compare(temp) != 0)
        {
            cout << "Passwords do not match! Enter again" << endl;
            cin >> Password;
            string INTBACKGROUND("\033[31;43m");
            cout << INTBACKGROUND;
        }
    }
};

#endif // !USER_H

int User::CustomerNumber = 0;
int User::Managernumber = 0;