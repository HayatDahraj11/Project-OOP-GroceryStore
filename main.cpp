//#pragma once
//All the relevant Headers are Placed
#include <iostream>
#include "CUSTOMER.h"
#include "USER.h"
#include <fstream>
#include "PAYMENT.h"
#include <stdlib.h>
#include "ADMIN2.h"
//#include "Manager.h"
//#include "ADMIN.h"

//Files Made ->DetailsOfCustomers
//			 ->DataPopulation
//			 ->AdminData
//The following are Ansi Codes For Compiler, adds aesthatics to menu
		string red("\033[0;31m");
		string Green("\033[0;32m");
      string Yellow("\033[0;33m");
       string Blue("\033[0;34m");
       string PINK("\033[0;35m");
       string PINKBACKGROUND("\033[34;45m"); // for customer  
	   string WHITEBG("\033[34;47m"); //for main menu
	   string BLUEBACKGROUND("\033[34;46m"); //  for Admin
       string SKYBLUE("\033[0;36m");
void Write(string, Customer &);
void Read(string, Customer &);
void ReadforAdmin(string, Admin &);
void DataPopulationForCustomers();
void AdminPredefinedFiles();
using namespace std;
int main()
{
	
	  //Flow Of this section : Customer Register Or Logins, Buys then logouts
	  //multiple registrations can happen which are saved in file 
	  string reset("\033[0m");
	
	char CHOICE;
	Customer C1;
	// Customer Object;
	do
	{
		/* code */

		Manager M1; //manager object
		Customer C2;//Customer Object
		//C2.showmenu();
		int help;
		Admin A2;
		User U1;
		User *MenuPTRBASE = &U1;
		int choice = 0;
		int registerORlogin = 0;
		char hello;
		cout << WHITEBG<< endl;
							cout << red << "\t\t\t\t\tNEW AGE GROCERY STORE" << endl;
							cout << reset ;
							cout << WHITEBG<< endl;
		cout << "1 |  Customer Panel" << endl;
		cout << "2 |  Admin Panel" << endl;

		

		cin >> choice;

		while(choice!=1 && choice!=2)
			{
				cout << red << "WRONG CHOICE! RE-ENTER" << reset << endl;
				cin >> choice;
			}
		switch (choice)
		{
		case 1:
		{
			// jkop
			// ereere

			
			cout << "1 | Register " << endl;
			cout << "2 | Login" << endl;
			cin >> registerORlogin;
			while(registerORlogin!=1 && registerORlogin!=2)
			{
				cout << red << "WRONG CHOICE! RE-ENTER" << reset << endl;
				cin >> registerORlogin;
			}
			switch (registerORlogin)
			{
			case 1:
			{

				C1.Register();
				C2 = C1;
				//Register then assign C2 data, write C2 into a file and then access
				//it while logging in
				Write("DetailsOfCustomers.bin", C2);

				
				help = 2;
			}

			case 2: //Customer Decides Ro Log In directly
			{
				if (help == 2)
				{
					// help refers to if customer is already toppled down from registration to login
					// otherwise just  read from file then login
					Customer Object;

					Read("DetailsOfCustomers.bin", Object);
					User *MenuPTRDERIVED4 = &Object;
					Object.Login();
					cout << "Welcome Customer! Press Enter To Procede" << endl;
					cin.ignore();
					cin.get();
					Object.showmenu();
					Object.getcustomertotal();
					EASYPAISA E11;
					CreditCardSystem CCS2;
					JAZZCASH J2;
					Customer *Baseptr = &Object;
					Customer *DerivedPtr = &E11;
					Customer *DerivedPtr2 = &CCS2;
					Customer *DerivedPtr3 = &J2;
					
					//Polymorphically Implemented Payment gateway types 
					//Base pointer of class Customer, points to derived child classes
					//virtual fnctio used
					if (Object.ReturnPaymentType() == 1)
					{
						DerivedPtr->PaymentGatewaySystem(Object.getcustomertotal());
						Object.CartClear();
					}
					else if (Object.ReturnPaymentType() == 2)
					{
						DerivedPtr2->PaymentGatewaySystem(Object.getcustomertotal());
						Object.CartClear();
					}
					else if (Object.ReturnPaymentType() == 3)
					{
						DerivedPtr3->PaymentGatewaySystem(Object.getcustomertotal());
						Object.CartClear();
					}
					else if (Object.ReturnPaymentType() == 4)
					{
						cout << "Your Goods Will Arrive within 2-4 Working Days!" << endl;
						Object.CartClear();
					}
					cout << "Will you like to leave a feedback on this purchase?" << endl;
					char feedbacktemp;
					cin >> feedbacktemp;
					while (feedbacktemp != 'Y' && feedbacktemp != 'N')
					{
						cout << "Wrong Choice, Re-Enter" << endl;
						cin >> feedbacktemp;
					}
					if (feedbacktemp == 'Y')
					{
						Object.feedbackstars();
						cout << "Please Wait, Your Feedback Is Being Submitted In the Server For Profanity Checking...." << endl;
						A2.CheckCustomerFeedback(Object.ReturnFeedBackArray());
						cout << "GOOD DAY! PRESS ENTER TO LOGOUT" << endl;
						cin.get();
					}
					else
					{
						cout << "GOOD DAY! PRESS ENTER TO LOGOUT" << endl;
						cin.get();
					}
					char tempji;
					do
					{
						int tempforhere;

						cout << " Now , Do you want to?" << endl;
						cout << "1 | Register As Another User?" << endl;
						cout << "2 | Login Again & Make A Purchase?";
						cin >> tempforhere;
						while(tempforhere!=1 && tempforhere!=2)
						{
							cout << red << "WRONG CHOICE! RE-ENTER" << reset << endl;
							cin >> tempforhere;
						}
						if (tempforhere == 1)
						{
							Object.Register();
						}
						else
						{
							Object.Login();
							cout << "Welcome Customer! Press Enter To Procede" << endl;
					cin.ignore();
					cin.get();
					Object.showmenu();
					Object.getcustomertotal();
					

					if (Object.ReturnPaymentType() == 1)
					{
						DerivedPtr->PaymentGatewaySystem(Object.getcustomertotal());
					}
					else if (Object.ReturnPaymentType() == 2)
					{
						DerivedPtr2->PaymentGatewaySystem(Object.getcustomertotal());
					}
					else if (Object.ReturnPaymentType() == 3)
					{
						DerivedPtr3->PaymentGatewaySystem(Object.getcustomertotal());
					}
					else if (Object.ReturnPaymentType() == 4)
					{
						cout << "Your Goods Will Arrive within 2-4 Working Days!" << endl;
					}
					cout << "Will you like to leave a feedback on this purchase?" << endl;
					char feedbacktemp;
					cin >> feedbacktemp;
					while (feedbacktemp != 'Y' && feedbacktemp != 'N')
					{
						cout << "Wrong Choice, Re-Enter" << endl;
						cin >> feedbacktemp;
					}
					if (feedbacktemp == 'Y')//Ask For FeedBack, Delete if inappropriate
					{
						Object.feedbackstars();
						cout << "Please Wait, Your Feedback Is Being Submitted In the Server For Profanity Checking...." << endl;
						A2.CheckCustomerFeedback(Object.ReturnFeedBackArray());
						cout << "GOOD DAY! PRESS ENTER TO LOGOUT" << endl;
						cin.get();
					}
					else
					{
						cout << "GOOD DAY! PRESS ENTER TO LOGOUT" << endl;
						cin.get();
					}









						}
						cout << "Press Y to initiate Customer Menu Again " << endl;
						cin >> tempji;

					} while (tempji == 'Y');
				}
				else // if user decides to login then populate Data 
				{
					DataPopulationForCustomers();
					Customer C4;
					// User* MenuPTRDERIVED3 = &C4;
					User &MenuPTRBASEDerived = C4;
					Read("DATAPOPULATION.bin", C4);
					C4.Login();
				
					cin.ignore();
					cin.get();

					//same polymorphic gateway system
					C4.showmenu();
					C4.getcustomertotal();
					EASYPAISA E1;
					CreditCardSystem CCS1;
					JAZZCASH J1;
					Customer *Baseptr = &C4;
					Customer *DerivedPtr = &E1;
					Customer *DerivedPtr2 = &CCS1;
					Customer *DerivedPtr3 = &J1;

					if (C4.ReturnPaymentType() == 1)
					{
						DerivedPtr->PaymentGatewaySystem(C4.getcustomertotal());
						C4.CartClear();
					}
					else if (C4.ReturnPaymentType() == 2)
					{
						DerivedPtr2->PaymentGatewaySystem(C4.getcustomertotal());
						C4.CartClear();
						
					}
					else if (C4.ReturnPaymentType() == 3)
					{
						DerivedPtr3->PaymentGatewaySystem(C4.getcustomertotal());
						C4.CartClear();
					}
					else if (C4.ReturnPaymentType() == 4)
					{
						cout << "Your Goods Will Arrive within 2-4 Working Days!" << endl;
						C4.CartClear();
					}
					cout << "Will you like to leave a feedback on this purchase?" << endl;
					char feedbacktemp;
					cin >> feedbacktemp;
					while (feedbacktemp != 'Y' && feedbacktemp != 'N')
					{
						cout << "Wrong Choice, Re-Enter" << endl;
						cin >> feedbacktemp;
					}
					if (feedbacktemp == 'Y')
					{
						C4.feedbackstars();
						cout << "Please Wait, Your Feedback Is Being Submitted In the Server For Profanity Checking...." << endl;
						A2.CheckCustomerFeedback(C4.ReturnFeedBackArray());
						cout << "GOOD DAY! PRESS ENTER TO LOGOUT" << endl;
						cin.get();
					}
					else
					{
						cout << "GOOD DAY! PRESS ENTER TO LOGOUT" << endl;
						cin.get();
					}

					char tempji;
					do
					{
						int tempforhere;

						cout << " Now , Do you want to?" << endl;
						cout << "1 | Register As Another User?" << endl;
						cout << "2 | Login Again & Make A Purchase?";
						cin >> tempforhere;
						while(tempforhere!=1 && tempforhere!=2)
						{
							cout << red << "WRONG CHOICE! RE-ENTER" << reset << endl;
							cin >> tempforhere;
						}
						if (tempforhere == 1)
						{
							C4.Register();
						}
						else
						{
							C4.Login();
							C4.showmenu();
							if (C4.ReturnPaymentType() == 1)
					{
						DerivedPtr->PaymentGatewaySystem(C4.getcustomertotal());
						C4.CartClear();
					}
					else if (C4.ReturnPaymentType() == 2)
					{
						DerivedPtr2->PaymentGatewaySystem(C4.getcustomertotal());
						C4.CartClear();
					}
					else if (C4.ReturnPaymentType() == 3)
					{
						DerivedPtr3->PaymentGatewaySystem(C4.getcustomertotal());
						C4.CartClear(); //ClearCartForOtherUSer
					}
					else if (C4.ReturnPaymentType() == 4)
					{
						cout << "Your Goods Will Arrive within 2-4 Working Days!" << endl;
						C4.CartClear();
					}
					cout << "Will you like to leave a feedback on this purchase?" << endl;
					char feedbacktemp;
					cin >> feedbacktemp;
					while (feedbacktemp != 'Y' && feedbacktemp != 'N')
					{
						cout << "Wrong Choice, Re-Enter" << endl;
						cin >> feedbacktemp;
					}
					if (feedbacktemp == 'Y')
					{
						C4.feedbackstars();
						cout << "Please Wait, Your Feedback Is Being Submitted In the Server For Profanity Checking...." << endl;
						A2.CheckCustomerFeedback(C4.ReturnFeedBackArray());
						cout << "GOOD DAY! PRESS ENTER TO LOGOUT" << endl;
						cin.get();
					}
					else
					{
						cout << "GOOD DAY! PRESS ENTER TO LOGOUT" << endl;
						cin.get();
					}
						}
						cout << "Press Y to initiate Customer Menu Again " << endl;
						cin >> tempji;

					} while (tempji == 'Y');


					
				}

				break;
			}
			break;
			case 3:
			{
			}
			}
			break;
		}
		case 2: //InCase Of Admin, Program Flow : 
		{
			cout << "1 | LOGIN" << endl;
			int temp;
			cin >> temp;
			switch (temp)
			{
			case 1:
			{
				AdminPredefinedFiles(); //Contains Admins Files For Pre-Populaton
				Admin A1; // derived

				User *MenuPTRDERIVED = &A1;
				// Manager M2 = A1.function(A1);
				ReadforAdmin("ADMINDATA.bin", A1);
				A1.Login();
				cout << Green << "You have been succesfully logged IN!" << endl;
				cout << reset;
				cout << "Press enter to access your custom dashboard and explore your options!" << endl;
				cin.ignore();
				cin.get();
				char temp1, temp2, temp3; //temps needed for 
				A1.showmenu();
				if (A1.getChoice() == 1)
				{
					A1.CreateManager(); //Admin's Method Function returns a Manager Object, in composition
					Manager M2 = A1.function(A1);
					cout << "Wish to create another manager? Y | N" << endl;
					//If another Manager is needed or Want to be made by Admin
					char temppp;
					cin >> temppp;
					if (temppp == 'Y')
					{
						A1.CreateManager();
						Manager M3 = A1.function(A1);
					}
				}
				else if (A1.getChoice() == 2)
				{
					// read a file and then login
				}
				else if (A1.getChoice() == 3)
				{
					A1.ShowDefaultMenu();
				}

				// cout << "2 | "
				// switch();
			}
			}
		}
		}
		//cout << "SwitchCaseEXITED" << endl;
		cout << "initiate program again? Y | N" << endl;
		cin >> CHOICE;
		while(CHOICE!='Y' && CHOICE!= 'N')
		{
			cout << red << "Please Choose Y OR N" << endl;
			cin >> CHOICE;
		}
	} while (CHOICE == 'Y');

	// Customer temp;
}
void Write(string FileName, Customer &OBJ) //Write File For General Purpose
{
	ofstream fout(FileName, ios::binary | ios::app);
	fout.write((char *)&OBJ, sizeof(OBJ));
	// OBJ.DataBaseDisplay();
}
void Read(string Filename, Customer &Object) //ReadFileForGeneralPurpose
{

	ifstream Reading(Filename, ios::binary);
	Reading.read((char *)&Object, sizeof(Object));
	// Object.Login();
	//	Object.DataBaseDisplay();
}
void ReadforAdmin(string Filename, Admin &Object) //Read File For Admin
{

	ifstream Reading(Filename, ios::binary);
	Reading.read((char *)&Object, sizeof(Object));
	cout << "\033[1;33mSUCCESFULL!\033[0m\n" << endl;
	// Object.Login();
	//	Object.DataBaseDisplay();
}
void DataPopulationForCustomers() //DataPopulation function, writes an object for customer
{
	Customer C3;
	C3.DataPopulation();
	ofstream DATA("DATAPOPULATION.bin", ios::binary | ios::app);
	DATA.write((char *)&C3, sizeof(C3));
}
void AdminPredefinedFiles() //Creates an admin file, with admin data, no arguments required
{
	Admin A2;
	cout << red << "ATETEMPING TO CREATE AND READ ADMIN PRE_DEFINED FILES......." << endl;

	ofstream DATADMIN("ADMINDATA.bin", ios::binary | ios::app);
	DATADMIN.write((char *)&A2, sizeof(A2));
	
	
}