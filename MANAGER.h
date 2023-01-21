#pragma once
#include <iostream>
//#include "Inventory.h"
using namespace std;

#ifndef  MANAGER_H


class Manager
{
private:
	string ManagerLocation;
	string Managername;
	string Username;
	string Password;
	char Location;




public:
	void setManagerLocation()
	{
			cout << "There are 2 stores, Karachi and Lahore. Assign this manager to?" << endl;
			cout << "1 | Karachi" << endl;
			cout << "2 | Lahore" << endl;
			int temp;
			cin >> temp;
			if(temp==1)
			{
					Location = 'K';
			}
			else
			{
				    Location  = 'L';
			}
			
	}
	
	char check()
	{
		return Location;
	}

	void SetUsername(string a )
	{
		this->Username = a;
	}
	void SetPassword(string b)
	{
		this -> Password = b;
	}


protected:



};
#endif // ! MANAGER_H
