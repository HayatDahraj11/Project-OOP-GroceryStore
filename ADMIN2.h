#pragma once
#include <iostream>
#include "USER.h"
#include "ManageProductCatalogue.h"
#include "MANAGER.h"
//#include "ManageProductCatalogue.h"
using namespace std;
#ifndef ADMIN_H

class Admin : public User, public Manager, public ProductCatalogue
{
private:
	// Admin Details
	string AdminName;
	string AdminUN;
	string AdminPW;

	Manager *ManagerExists2;
	int whatdidyouchoose; // Needed to return to main
	int loggedinornot;
	static int WhichCount;

protected:
	Manager Manager1;
	Manager Manager2;
	Manager Manager3;
	// 2 Managers Can Be Created using composition by the Manager
	void RegisterManagerintoSystem()
	{
	}

public:
bool FeedbackCheck(string* b) {
	string b1 = "shit";
	if (b[0]==b1) {
		return true;
		}
		return false;
	}
	void CheckCustomerFeedback(string *b)
	{
		string BLUEBACKGROUND("\033[34;46m"); //  for Admin
		cout << BLUEBACKGROUND;

		//cout << "WHAT IS AT:" << b[0] << endl;
		// Finds Bad words in FEEDBACK AND then deletes that feedback

		

		if (FeedbackCheck(b) == 1)
		{

			cout << "\033[1;31mTHE FEEDBACK IS DELETED BY ADMIN DUE TO BEING AGAINST THE COMMUNITY GUIDELINES!\033[0m\n";
		}
		else
		{
			cout << "FEEDBACK SUBMITTED!" << endl;
		}

		// 
	}
	Manager function(Admin &a)
	{
		string BLUEBACKGROUND("\033[34;46m"); //  for Admin
		cout << BLUEBACKGROUND;
		if (WhichCount == 0)
		{
			a.Manager1.setManagerLocation();
			WhichCount++;
			return Manager1;
		}
		else
		{
			cout << "You are currently setting location for manager 2" << endl;
			a.Manager2.setManagerLocation();
			while (a.Manager2.check() == a.Manager1.check())
			{
				cout << "This location is set for another manager!" << endl;
				a.Manager2.setManagerLocation();
			}
			return Manager2;
		}
	}
	void AssignManagerLocation() // Assigns Manager Location
	{
		string BLUEBACKGROUND("\033[34;46m"); //  for Admin
		cout << BLUEBACKGROUND;
		while (loggedinornotUSER != 1)
		{
			cout << "hmm, avoid breaching the system. I know my encapsulation well :p" << endl;
			cin.get();
		}
		// assign manager here
	}
	void CreateManager() // Creates Manager
	{
		while (loggedinornotUSER != 1) // MAIN BREACH PROTOCOL
		{
			cout << "hmm, avoid breaching the system. I know my encapsulation well :p" << endl;
			cin.get();
		}
		if (WhichCount == 0)
		{
			new Manager(Manager1); // Dynamically Allocate new Manager
			Manager1.SetUsername(ReturnMostRecentUN());
			Manager1.SetPassword(ReturnMostRecentPW());
		}
		if (WhichCount == 1)
		{
			new Manager(Manager2);
			Manager1.SetUsername(ReturnMostRecentUN());
			Manager1.SetPassword(ReturnMostRecentPW());
		}

		if (WhichCount == 2)
		{
			Manager1.SetUsername(ReturnMostRecentUN());
			Manager1.SetPassword(ReturnMostRecentPW());
			new Manager(Manager3);
		}
		// string INTBACKGROUND("\033[31;43m");
		cout << "A manager position has been succesfully created!" << endl;

		cout << "You Are Now Being Redirected to Manager-Console" << endl;
		WhichUserSetter('M');
		Register();
		Login();
		if (WhichCount == 0)
		{

			Manager1.SetUsername(ReturnMostRecentUN());
			Manager1.SetPassword(ReturnMostRecentPW());
		}
		if (WhichCount == 1)
		{

			Manager2.SetUsername(ReturnMostRecentUN());
			Manager2.SetPassword(ReturnMostRecentPW());
		}
	}

	// i want the managers creation in admins hand
	// he should not be able to make hismlf an accnt
	// thats called composiyion i think?

	void setChoice(int a)
	{
		this->whatdidyouchoose = a;
	}
	int getChoice()
	{
		return whatdidyouchoose;
	}
	Admin()
	{
		WhichUserSetter('A');
		SetAdminUsernameAndPassword();
		whichlogicsetter('2');
	}
	void showmenu() override // Virtual Polymorphism used to show menu of ADMIN
	{
		string BLUEBACKGROUND("\033[34;46m"); //  for Admin
		cout << BLUEBACKGROUND;
		int temp;
		cout << "GOOD DAY, ADMIN. PROCEDE WITH THE FOLLOWING OPTIONS" << endl;
		cout << "1 | Manipulate Manager Settings? " << endl;
		cout << "2 | Open Catalogue Management System (CMS)" << endl;

		cin >> temp;
		while (temp != 1 && temp != 2)
		{
			cout << "\033[1;31mPlease Select Only From The Given Options!\033[0m\n";
			cin >> temp;
			// string BLUEBACKGROUND("\033[34;46m"); //  for Admin
			cout << BLUEBACKGROUND;
		}
		if (temp == 1)
		{
			int temp2;
			cout << "Press 1 to create a manager" << endl;
			cout << "Press 2 to Assign an existing manager a location" << endl;

			cin >> temp2;
			while (temp2 != 1 && temp2 != 2)
			{
				cout << "\033[1;31mPlease Select Only From The Given Options!\033[0m\n";
				cin >> temp2;
				string BLUEBACKGROUND("\033[34;46m"); //  for Admin
				cout << BLUEBACKGROUND;
			}
			setChoice(temp2);
		}
		else if (temp == 2)
		{
			setChoice(3);
		}
	}
};
int Admin ::WhichCount = 0;

#endif