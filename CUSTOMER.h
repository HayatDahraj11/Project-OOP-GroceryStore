#pragma once

#include <iostream>
#include <string.h>
#include "USER.h"
#include "Inventory.h"
using namespace std;

#ifndef CUSTOMER_H
// LOGIC : CART COUNTER INCREMENTS, CART IS SHOWN , DIFFERENT COLOUR FOR EVERY MENU

class Customer : public User, public Inventory // user parent class
{
private:
	long long int CNIC;
	string GENDER;

	string Name;
	bool othercity;
	long long int phoneNum;
	float customer_total;
	int category1Inventory; // Substract from Category 1 Inventory if items bought
	int category2Inventory; // Substract from Category 2 Inventory if items bought
	int category3Inventory; // Substract from Category 3 Inventory if items bought
	char city;
	int payment_type;
	bool feedback_bool;
	string Cart[40]; // FOR CART
	string otherlocation;
	string *feedbackarray;
	static int cartcounter;

protected:
public:
	string *ReturnFeedBackArray()
	{
		return feedbackarray;
	}
	void feedbackstars() // Here FeedBack happens
	{
		feedbackarray = new string[100];
		int choicetemp;
		cout << "would you like to give a written feedback?" << endl;
		cout << "1 | YES" << endl;
		cout << "2 | NO" << endl;
		cin >> choicetemp;
		while(choicetemp!=1 && choicetemp!=2)
		{
			cout << "Sorry, wrong input!" << endl;
			cin >> choicetemp;
		}

		if (choicetemp == 1)
		{
			static int cnter = 0;
			string string;
			cout << "Please Enter Your FeedBack!" << endl;
			cin.ignore();
			getline(cin, string);
			feedbackarray[cnter] = string;
			cnter++;
		}
	}
	int getcustomertotal()
	{
		return customer_total;
	}

	virtual void PaymentGatewaySystem(int a) // VIRTUAL FUNCTION FOR POLYMORPHISM
	{
	}
	int ReturnPaymentType()
	{
		return payment_type;
	}
	void CartClear() // CLEAR CART AFTER EVERY USER
	{
		for (int i = 0; i <= cartcounter; i++)
		{

			Cart[i] = " ";
		}
		cartcounter = 0;
		customer_total = 0;
	}
	void checkout() // CHECKOUT FUNCTION
	{
		cout << "SELECT YOUR MODE OF PAYMENT" << endl;
		cout << "1 | EASYPAISA" << endl;
		cout << "2 | CREDITCARD" << endl;
		cout << "3 | JAZZCASH" << endl;
		cout << "4 | COD" << endl;

		int temp;
		cin >> temp;
		while (temp != 1 && temp != 2 && temp != 3 && temp != 4)
		{
			cout << "\033[1;31mPlease Select Only From The Given Options!\033[0m\n";
			cin >> temp;
		}
		if (temp == 1)
		{
			payment_type = 1;
		}
		if (temp == 2)
		{
			payment_type = 2;
		}
		if (temp == 3)
		{
			payment_type = 3;
		}
		if (temp == 4)
		{
			if (othercity == 1)
			{

				cout << "\033[1;31mYour Nearest Store Is Not Within Your Vicinity!,  50 RPS EXTRA WILL BE CHARGED\033[0m\n";
			}

			payment_type = 4;
		}
	}
	Customer()
	{
		this->CNIC = 0;
		this->GENDER = " ";
		this->Name = " ";
		this->phoneNum = 0;
		WhichUserSetter('C');
		customer_total = 0;
	}
	Customer(long long int a, string b, string c, long long int d)
	{
		this->CNIC = a;
		this->GENDER = b;
		this->Name = c;
		this->phoneNum = d;
	}

	void CART_TOTAL(int total) // Show Cart + Updation
	{
		string Cart2("\033[46;34m");
		cout << Cart2;
		customer_total += total;
		cout << "Total Bill: " << customer_total << endl;
		cout << "CART CONTENTS: " << endl;
		// string reset("\033[0m");
		// cout << reset;
		for (int i = 0; i <= cartcounter; i++)
		{
			// string Blue("\033[0;34m");
			// string red("\033[0;31m");
			cout << Cart2;
			cout << Cart[i] << endl;
		}
		string PINKBACKGROUND("\033[34;45m");
		cout << PINKBACKGROUND << endl;
	}

	void showmenu() override // Show Menu, in line with admins shiw menu and managers showmenu
	{
		string PINKBACKGROUND("\033[34;45m");
		cout << PINKBACKGROUND << endl;
		// karachiInventory = &I1;
		cout << "WELCOME CUSTOMER!" << endl;

		cout << "Kindly Select your City\n 1 | KARACHI \n 2 | LAHORE \n 3 | OTHER (SPECIFY)";
		int citytemp;
		cin >> citytemp;
		while (citytemp != 1 && citytemp != 2 && citytemp != 3)
		{
			cout << "\033[1;31mPlease Select Only From The Given Options!\033[0m\n";

			cin >> citytemp;
		}

		cout << "LOCATING YOUR NEAREST BRANCH....." << endl;
		if (citytemp == 1)
		{
			city = 'K';
		}
		else if (citytemp == 2)
		{
			city = 'L';
		}
		else if (citytemp == 3)
		{
			cin.ignore();
			cout << "Which City?" << endl;
			getline(cin, otherlocation);
			city = 'L';
			othercity = 1;
		}

		cout << "1 | Shop Online" << endl;
		int temp1;
		cin >> temp1;
		while (temp1 != 1)
		{
			cout << "\033[1;31mPlease Select Only From The Given Options!\033[0m\n";

			cin >> temp1;
		}
		if (temp1 == 1)
		{
			OnlineShoppingExperience();
		}

		// implement payment gateways here
	}
	void OnlineShoppingExperience() // CUSTOMER CAN BUY, FROM MULTIPLE CATEGORIES HERE
	{
		int initatemenuagaintemp;
		do
		{
			string PINKBACKGROUND("\033[34;45m");
			cout << PINKBACKGROUND << endl;
			int mainchoice;
			char tempppppp;
			int temp1;
			int temp2;
			int anothertemp;
			cout << "1 | FOOD\n";
			cout << "2 | HOUSEHOLDCLEANING\n";
			cout << "3 | PERSONAL HYGIENE\n";
			cin >> mainchoice;
			while (mainchoice != 1 && mainchoice != 2 && mainchoice != 3)
			{
				cout << "\033[1;31mPlease Select Only From The Given Options!\033[0m\n";

				cin >> mainchoice;
			}
			// string PINKBACKGROUND("\033[34;45m");
			cout << PINKBACKGROUND << endl;

			switch (mainchoice)
			{
			case 1:
				cout << "1 | PERISHABLE" << endl;
				cout << "2 | NON-PERISHABLE" << endl;

				cin >> temp1;
				while (temp1 != 1 && temp1 != 2)
				{
					cout << "\033[1;31mPlease Select Only From The Given Options!\033[0m\n";

					cout << PINKBACKGROUND << endl;
					cin >> temp1;
				}

				switch (temp1)
				{
				case 1:
				{
					// perishable starts
					cout << "1 | MEAT" << endl;
					cout << "2 | DAIRY" << endl;
					cout << "3 | FRUIT" << endl;
					cout << "4 | VEGES" << endl;
					cin >> temp2;
					while (temp2 != 1 && temp2 != 2 && temp2 != 3 && temp2 != 4)
					{
						cout << "\033[1;31mPlease Select Only From The Given Options!\033[0m\n";

						cin >> temp2;
						cout << PINKBACKGROUND << endl;
					}
					switch (temp2)
					{

					case 1:

						do
						{
							system("clear");
							cout << "1 | CHICKEN 600/Kg" << endl;
							cout << "2 | BEEF    500/kg" << endl;
							cout << "3 | MUTTON  1700/kg" << endl;
							cout << "4 | FISH    1000/kg" << endl;
							cout << "Which Type Of Meat Would You Like to Add To Cart?" << endl;
							int selection;
							cin >> selection;
							while (selection != 1 && selection != 2 && selection != 3 && selection != 4)
							{
								cout << "\033[1;31mPlease Select Only From The Given Options!\033[0m\n";
								cout << PINKBACKGROUND << endl;
								cin >> selection;
							}
							if (selection == 1)
							{
								Cart[cartcounter] = "Chicken";
								CART_TOTAL(600);

								category1Inventory++;
							}
							else if (selection == 2)
							{
								Cart[cartcounter] = "BEEF";
								CART_TOTAL(500);

								category1Inventory++;
							}
							else if (selection == 3)
							{
								Cart[cartcounter] = "MUTTOn";
								CART_TOTAL(1700);

								category1Inventory++;
							}
							else if (selection == 4)
							{
								Cart[cartcounter] = "FISH";
								CART_TOTAL(1000);

								category1Inventory++;
							}
							cout << "Add more Meat Into Cart? Y|N" << endl;
							cin >> tempppppp;

							while (tempppppp != 'Y' && tempppppp != 'N')
							{
								cout << "\033[1;31mPlease Select Only From The Given Options!\033[0m\n";
								cout << PINKBACKGROUND << endl;
								cin >> tempppppp;
							}
							cartcounter++;
						} while (tempppppp == 'Y');

						InventoryRefresh(1, category1Inventory, city);
						break;

					case 2:
						cout << "1 | MILK    600/PCKT" << endl;
						cout << "2 |EGGS    240/DZN" << endl;
						cout << "3 |YOGURT  100/PCKT" << endl;
						cout << "4 |CHEESE  1000/PCKT" << endl;
						do
						{
							system("clear");
							cout << "1 | MILK    600/PCKT" << endl;
							cout << "2 |EGGS    240/DZN" << endl;
							cout << "3 |YOGURT  100/PCKT" << endl;
							cout << "4 |CHEESE  1000/PCKT" << endl;
							cout << "Which Type Of DAIRY ITEMS Would You Like to Add To Cart?" << endl;
							int selection;
							cin >> selection;
							while (selection != 1 && selection != 2 && selection != 3 && selection != 4)
							{
								cout << "\033[1;31mPlease Select Only From The Given Options!\033[0m\n";
								cout << PINKBACKGROUND << endl;
								cin >> selection;
							}
							if (selection == 1)
							{
								Cart[cartcounter] = "MILK";
								CART_TOTAL(600);

								category1Inventory++;
							}
							else if (selection == 2)
							{
								Cart[cartcounter] = "EGGS";
								CART_TOTAL(240);

								category1Inventory++;
							}
							else if (selection == 3)
							{
								Cart[cartcounter] = "YOGURT";
								CART_TOTAL(100);

								category1Inventory++;
							}
							else if (selection == 4)
							{
								Cart[cartcounter] = "CHEESE";
								CART_TOTAL(1000);

								category1Inventory++;
							}
							cout << "Add more DAIRY ITEMS Into Cart? Y|N" << endl;
							cin >> tempppppp;
							while (tempppppp != 'Y' && tempppppp != 'N')
							{
								cout << "\033[1;31mPlease Select Only From The Given Options!\033[0m\n";
								cout << PINKBACKGROUND << endl;
								cin >> tempppppp;
							}
							cartcounter++;
						} while (tempppppp == 'Y');

						InventoryRefresh(1, category1Inventory, city);
						break;

					case 3:
						cout << "1 | APPLES   400/KG" << endl;
						cout << "2 | BANANA   250DZN" << endl;
						cout << "3 | MANGO    500/KG" << endl;
						cout << "4 | ORANGE   1000/PCKT" << endl;
						do
						{
							system("clear");
							cout << "1 | APPLES   400/KG" << endl;
							cout << "2 | BANANA   250DZN" << endl;
							cout << "3 | MANGO    500/KG" << endl;
							cout << "4 | ORANGE   1000/PCKT" << endl;
							cout << "Which Type Of FRUIT Would You Like to Add To Cart?" << endl;
							int selection;
							while (selection != 1 && selection != 2 && selection != 3 && selection != 4)
							{
								cout << "\033[1;31mPlease Select Only From The Given Options!\033[0m\n";
								cout << PINKBACKGROUND << endl;
								cin >> selection;
							}
							if (selection == 1)
							{
								Cart[cartcounter] = "APPLES";
								CART_TOTAL(400);

								category1Inventory++;
							}
							else if (selection == 2)
							{
								Cart[cartcounter] = "BANANAS";
								CART_TOTAL(250);

								category1Inventory++;
							}
							else if (selection == 3)
							{
								Cart[cartcounter] = "MANGOS";
								CART_TOTAL(500);

								category1Inventory++;
							}
							else if (selection == 4)
							{
								Cart[cartcounter] = "ORANGE";
								CART_TOTAL(1000);

								category1Inventory++;
							}
							cout << "Add more FRUIT Into Cart? Y|N" << endl;
							cin >> tempppppp;
							while (tempppppp != 'Y' && tempppppp != 'N')
							{
								cout << "\033[1;31mPlease Select Only From The Given Options!\033[0m\n";
								cout << PINKBACKGROUND << endl;
								cin >> tempppppp;
							}
						} while (tempppppp == 'Y');
						cartcounter++;
						InventoryRefresh(1, category1Inventory, city);

						break;

					case 4:

						cout << "1 | TOMATOES   400RS/KG" << endl;
						cout << "2 | ONION      250RS/DZN" << endl;
						cout << "3 | CUCUMBER   500RS/KG" << endl;
						cout << "4 |POTATOES    1000RS/PCKT" << endl;

						do
						{
							system("clear");
							cout << "1 | TOMATOES   400RS/KG" << endl;
							cout << "2 | ONION      250RS/DZN" << endl;
							cout << "3 | CUCUMBER   500RS/KG" << endl;
							cout << "4 |POTATOES    1000RS/PCKT" << endl;
							cout << "Which Type Of VEGES Would You Like to Add To Cart?" << endl;
							int selection;
							while (selection != 1 && selection != 2 && selection != 3 && selection != 4)
							{
								cout << "\033[1;31mPlease Select Only From The Given Options!\033[0m\n";
								cout << PINKBACKGROUND << endl;
								cin >> selection;
							}
							if (selection == 1)
							{
								Cart[cartcounter] = "TOMATOES";
								CART_TOTAL(400);

								category1Inventory++;
							}
							else if (selection == 2)
							{
								Cart[cartcounter] = "ONIONS";
								CART_TOTAL(250);

								category1Inventory++;
							}
							else if (selection == 3)
							{
								Cart[cartcounter] = "CUCUMBER";
								CART_TOTAL(500);

								category1Inventory++;
							}
							else if (selection == 4)
							{
								Cart[cartcounter] = "POTATOES";
								CART_TOTAL(1000);

								category1Inventory++;
							}
							cout << "Add more VEGES Into Cart? Y|N" << endl;
							cin >> tempppppp;
							while (tempppppp != 'Y' && tempppppp != 'N')
							{
								cout << "\033[1;31mPlease Select Only From The Given Options!\033[0m\n";
								cout << PINKBACKGROUND << endl;
								cin >> tempppppp;
							}
						} while (tempppppp == 'Y');
						cartcounter++;
						InventoryRefresh(1, category1Inventory, city);

						break;
					}

					break;
					// perishable ends
				}
				case 2:
				{
					// non perishable starts
					cout << "1 | SNACKS" << endl;
					cout << "2 | SPICES" << endl;
					cout << "3 | GRAINS" << endl;
					cout << "4 | CEREAL" << endl;
					cin >> anothertemp;
					switch (anothertemp)
					{
					case 1:
						cout << "1 | CHOCOLATES" << endl;
						cout << "2 | CHIPS" << endl;
						cout << "3 | BISCUITS" << endl;
						int tempSNACKS;
						int tempCHOC;
						char menusnacks;
						cin >> tempSNACKS;
						do
						{ // system("clear");
							if (tempSNACKS == 1)
							{
								cout << "1 | DAIRY MILK 110RS" << endl;
								cout << "2 | KITKAT     220RS" << endl;
								cout << "3 | HERSHEYS   445RS" << endl;
								cin >> tempCHOC;
								while (tempCHOC != 1 && tempCHOC != 2 && tempCHOC != 3)
								{
									cout << "\033[1;31mPlease Select Only From The Given Options!\033[0m\n";

									cin >> tempCHOC;
								}
								switch (tempCHOC)
								{
								case 1:
									Cart[cartcounter] = "DAIRY MILK";
									CART_TOTAL(110);

									category1Inventory++;
									break;
								case 2:
									Cart[cartcounter] = "KITKAT";
									CART_TOTAL(220);

									category1Inventory++;
									break;
								case 3:
									Cart[cartcounter] = "HERSHEYS";
									CART_TOTAL(445);

									category1Inventory++;
									break;

								default:
									break;
								}
							}
							else if (tempSNACKS == 2)
							{
								cout << "1 | LAYS 		110RS" << endl;
								cout << "2 | KURLEEZ    20RS" << endl;
								cout << "3 | PRINGLES   70RS" << endl;
								cin >> tempCHOC;
								while (tempCHOC != 1 && tempCHOC != 2 && tempCHOC != 3)
								{
									cout << "\033[1;31mPlease Select Only From The Given Options!\033[0m\n";

									cin >> tempCHOC;
								}
								switch (tempCHOC)
								{
								case 1:
									Cart[cartcounter] = "LAYS";
									CART_TOTAL(110);

									category1Inventory++;
									break;
								case 2:
									Cart[cartcounter] = "KURLEEZ";
									CART_TOTAL(20);

									category1Inventory++;
									break;
								case 3:
									Cart[cartcounter] = "PRINGLES";
									CART_TOTAL(70);

									category1Inventory++;
									break;

								default:
									break;
								}
							}
							else if (tempSNACKS == 3)
							{
								cout << "1 | TUC		110RS" << endl;
								cout << "2 | CANDY      20RS" << endl;
								cout << "3 | SUPER      70RS" << endl;
								cin >> tempCHOC;
								while (tempCHOC != 1 && tempCHOC != 2 && tempCHOC != 3)
								{
									cout << "\033[1;31mPlease Select Only From The Given Options!\033[0m\n";
									cout << PINKBACKGROUND << endl;
									cin >> tempCHOC;
								}
								switch (tempCHOC)
								{
								case 1:
									Cart[cartcounter] = "TUC";
									CART_TOTAL(110);

									category1Inventory++;
									break;
								case 2:
									Cart[cartcounter] = "CANDY";
									CART_TOTAL(20);

									category1Inventory++;
									break;
								case 3:
									Cart[cartcounter] = "SUPER";
									CART_TOTAL(70);

									category1Inventory++;
									break;

								default:
									break;
								}
							}
							cout << "Add more snacks? Y|N";
							cin >> menusnacks;
							while (menusnacks != 'Y' && menusnacks != 'N')
							{
								cout << "\033[1;31mPlease Select Only From The Given Options!\033[0m\n";
								cout << PINKBACKGROUND << endl;
								cin >> menusnacks;
							}
							cartcounter++;
						} while (menusnacks == 'Y');

						InventoryRefresh(1, category1Inventory, city);
						break;
					case 2:
						cout << "RED SPICE 			110" << endl;
						cout << "GREEN SPICE		220" << endl;
						cout << "ORANGE SPICE		330" << endl;
						cout << "EXTRA RED SPICE    440" << endl;
						int tempmasala;
						char YESNO;
						do
						{
							cout << "Which type of SPICE?" << endl;
							cin >> tempmasala;
							while (tempmasala != 1 && tempmasala != 2 && tempmasala != 3)
							{
								cout << "\033[1;31mPlease Select Only From The Given Options!\033[0m\n";
								cout << PINKBACKGROUND << endl;
								cin >> tempmasala;
							}
							if (tempmasala == 1)
							{
								Cart[cartcounter] = "RED SPICE";
								CART_TOTAL(110);

								category1Inventory++;
							}
							if (tempmasala == 2)
							{
								Cart[cartcounter] = "GREEN SPICE";
								CART_TOTAL(210);

								category1Inventory++;
							}
							if (tempmasala == 3)
							{
								Cart[cartcounter] = "ORANGE SPICE";
								CART_TOTAL(310);

								category1Inventory++;
							}
							if (tempmasala == 4)
							{
								Cart[cartcounter] = "EXTRA RED SPICE";
								CART_TOTAL(410);

								category1Inventory++;
							}

							cout << "Want to add more SPICES? Y|N" << endl;
							cin >> YESNO;
							while (YESNO != 'Y' && YESNO != 'N')
							{
								cout << "\033[1;31mPlease Select Only From The Given Options!\033[0m\n";
								cout << PINKBACKGROUND << endl;
								cin >> YESNO;
							}
							cartcounter++;
						} while (YESNO == 'Y');

						InventoryRefresh(1, category1Inventory, city);
						break;

					case 3:
						cout << "GRAIN1------------	110" << endl;
						cout << "GRAIN2------------ 220" << endl;
						cout << "GRAIN3------------ 330" << endl;
						cout << "GRAIN4 ----------- 440" << endl;

						char YESNO2;
						do
						{
							cout << "Which type of GRAIN?" << endl;
							cin >> tempmasala;
							if (tempmasala == 1)
							{
								Cart[cartcounter] = "GRAIN 1";
								CART_TOTAL(110);

								category1Inventory++;
							}
							if (tempmasala == 2)
							{
								Cart[cartcounter] = "GRAIN 2";
								CART_TOTAL(210);

								category1Inventory++;
							}
							if (tempmasala == 3)
							{
								Cart[cartcounter] = "GRAIN 3";
								CART_TOTAL(310);

								category1Inventory++;
							}
							if (tempmasala == 4)
							{
								Cart[cartcounter] = "GRAIN 4";
								CART_TOTAL(410);

								category1Inventory++;
							}

							cout << "Want to add more GRAINS? Y|N" << endl;
							cin >> YESNO2;
							while (YESNO2 != 'Y' && YESNO2 != 'N')
							{
								cout << "\033[1;31mPlease Select Only From The Given Options!\033[0m\n";
								cout << PINKBACKGROUND << endl;
								cin >> YESNO2;
							}
							cartcounter++;
						} while (YESNO2 == 'Y');

						InventoryRefresh(1, category1Inventory, city);

						break;

					} // switch ends of non perish
					break;
				}
				break;
				}

				break;
			case 2:
				cout << "1 | SHAMPOO" << endl;
				cout << "2 | SOAP" << endl;
				cout << "3 | HAND SANITIZER" << endl;
				int hygienetemp;
				cin >> hygienetemp;
				char YESNOTEMP3;
				do
				{
					/* code */

					if (hygienetemp == 1)
					{
						cout << "1 | HEAD AND SHOULDERS 110RS " << endl;
						cout << "2 | NIVEA				170RS " << endl;
						cout << "3 | SUNSILK			400RS " << endl;
						int shampootemp;
						cin >> shampootemp;
						if (shampootemp == 1)
						{
							Cart[cartcounter] = "HEAD AND SHOULDERS";
							CART_TOTAL(110);

							category2Inventory++;
						}
						if (shampootemp == 2)
						{
							Cart[cartcounter] = "NIVEA";
							CART_TOTAL(170);

							category2Inventory++;
						}
						if (shampootemp == 3)
						{
							Cart[cartcounter] = "SUNSILK";
							CART_TOTAL(400);

							category2Inventory++;
						}
					}
					if (hygienetemp == 2)
					{
						cout << "1 | DETTOL             110RS " << endl;
						cout << "2 | LIFEGUARD			170RS " << endl;
						cout << "3 | J&J's		        400RS " << endl;
						int shampootemp;
						cin >> shampootemp;
						if (shampootemp == 1)
						{
							Cart[cartcounter] = "DETTOL";
							CART_TOTAL(110);

							category2Inventory++;
						}
						if (shampootemp == 2)
						{
							Cart[cartcounter] = "LIFEGUARD";
							CART_TOTAL(170);

							category2Inventory++;
						}
						if (shampootemp == 3)
						{
							Cart[cartcounter] = "J&J's";
							CART_TOTAL(400);

							category2Inventory++;
						}
					}
					if (hygienetemp == 3)
					{
						cout << "1 | DETTOL             110RS " << endl;
						cout << "2 | LIFEGUARD			140RS " << endl;
						cout << "3 | J&B's		        430RS " << endl;
						int shampootemp;
						cin >> shampootemp;
						if (shampootemp == 1)
						{
							Cart[cartcounter] = "DETTOL";
							CART_TOTAL(110);

							category2Inventory++;
						}
						if (shampootemp == 2)
						{
							Cart[cartcounter] = "LIFEGUARD";
							CART_TOTAL(140);

							category2Inventory++;
						}
						if (shampootemp == 3)
						{
							Cart[cartcounter] = "J&B's";
							CART_TOTAL(430);

							category2Inventory++;
						}
					}
					cout << "Want to add more items from this category? Y|N" << endl;
					cin >> YESNOTEMP3;

					while (YESNOTEMP3 != 'Y' && YESNOTEMP3 != 'N')
					{
						cout << "\033[1;31mPlease Select Only From The Given Options!\033[0m\n";
						cout << PINKBACKGROUND << endl;
						cin >> YESNOTEMP3;
					}
					cartcounter++;
					// system("clear");
				} while (YESNOTEMP3 == 'Y');
				InventoryRefresh(2, category2Inventory, city);

				break;

			case 3:

				cout << "1 | DETERGENT" << endl;
				cout << "2 | DISHSOAP" << endl;
				cout << "3 | WASHROOM CLEANER" << endl;
				int hygienetemp4;
				char YESNOTEMP;
				cin >> hygienetemp4;
				do
				{
					/* code */
					cout << "here couter is : " << cartcounter << endl;

					if (hygienetemp4 == 1)
					{
						cout << "1 | NORMAL DET\t 		110RS " << endl;
						cout << "2 | MEDIUM DET			170RS " << endl;
						cout << "3 | HIGHLEVEL DET		400RS " << endl;
						int shampootemp;
						cin >> shampootemp;
						if (shampootemp == 1)
						{
							Cart[cartcounter] = "NORMAL DET";
							CART_TOTAL(110);

							category3Inventory++;
						}
						if (shampootemp == 2)
						{
							Cart[cartcounter] = "MEDIUM DET";
							CART_TOTAL(170);

							category3Inventory++;
						}
						if (shampootemp == 3)
						{
							Cart[cartcounter] = "HIGHLEVEL DET";
							CART_TOTAL(400);

							category3Inventory++;
						}
					}
					if (hygienetemp4 == 2)
					{
						cout << "1 | VIM\t\t\t        110RS " << endl;
						cout << "2 | VIM2			170RS " << endl;
						cout << "3 | VIM3\t	        400RS " << endl;
						int shampootemp;
						cin >> shampootemp;
						if (shampootemp == 1)
						{
							Cart[cartcounter] = "VIM";
							CART_TOTAL(110);

							category3Inventory++;
						}
						if (shampootemp == 2)
						{
							Cart[cartcounter] = "VIM2";
							CART_TOTAL(170);

							category3Inventory++;
						}
						if (shampootemp == 3)
						{
							Cart[cartcounter] = "VIM3";
							CART_TOTAL(400);

							category3Inventory++;
						}
					}
					if (hygienetemp4 == 3)
					{
						cout << "1 | ACID\t\t        110RS " << endl;
						cout << "2 | ACID2			140RS " << endl;
						cout << "3 | ACID3		        430RS " << endl;
						int shampootemp;
						cin >> shampootemp;
						if (shampootemp == 1)
						{
							Cart[cartcounter] = "ACIDFLEXER";
							CART_TOTAL(110);

							category3Inventory++;
						}
						if (shampootemp == 2)
						{
							Cart[cartcounter] = "HARPIC";
							CART_TOTAL(140);

							category3Inventory++;
						}
						if (shampootemp == 3)
						{
							Cart[cartcounter] = "DETONIC";
							CART_TOTAL(430);

							category3Inventory++;
						}
					}
					cout << "Want to add more items from this category? Y|N" << endl;
					cin >> YESNOTEMP;
					while (YESNOTEMP != 'Y' && YESNOTEMP != 'N')
					{
						cout << "\033[1;31mPlease Select Only From The Given Options!\033[0m\n";
						cout << PINKBACKGROUND << endl;
						cin >> YESNOTEMP;
					}
					cartcounter++;
				} while (YESNOTEMP == 'Y');
				InventoryRefresh(3, category3Inventory, city);

				break;
			}
			cout << PINKBACKGROUND << endl;
			cout << "1 | INITIATE MENU AGAIN" << endl;
			cout << "2 | PROCEDE TO CHECKOUT" << endl;

			cin >> initatemenuagaintemp;
			while (initatemenuagaintemp != 1 && initatemenuagaintemp != 2)
			{
				cout << "\033[1;31mPlease Select Only From The Given Options!\033[0m\n";
				cout << PINKBACKGROUND << endl;

				cin >> initatemenuagaintemp;
			}
			system("clear");
			cartcounter++;
		} while (initatemenuagaintemp == 1);

		checkout(); // checkout simply after buying
	}
};
int Customer ::cartcounter = 0;

#endif
