#include <iostream>
using namespace std;
void CART_TOTAL(int total)
{
    static int customer_total;
    customer_total += total;
    cout << "customer total is now : " << customer_total << endl;
}

int main()
{

    char initatemenuagaintemp;
    do
    {

        int mainchoice;
        char tempppppp;
        int temp1;
        int temp2;
        int anothertemp;
        cout << "1 | FOOD\n";
        cout << "2 | HOUSEHOLDCLEANING\n";
        cout << "3 | PERSONAL HYGIENE\n";
        cin >> mainchoice;
        switch (mainchoice)
        {
        case 1:
            cout << "1 | PERISHABLE" << endl;
            cout << "2 | NON-PERISHABLE" << endl;

            cin >> temp1;
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
                switch (temp2)
                {

                case 1:
                    cout << "1 | CHICKEN 600/Kg" << endl;
                    cout << "2 | BEEF    500/kg" << endl;
                    cout << "3 | MUTTON  1700/kg" << endl;
                    cout << "4 | FISH    1000/kg" << endl;

                    do
                    {
                        cout << "Which Type Of Meat Would You Like to Add To Cart?" << endl;
                        int selection;
                        cin >> selection;
                        if (selection == 1)
                        {
                            CART_TOTAL(600);
                        }
                        else if (selection == 2)
                        {
                            CART_TOTAL(500);
                        }
                        else if (selection == 3)
                        {
                            CART_TOTAL(1700);
                        }
                        else if (selection == 4)
                        {
                            CART_TOTAL(1000);
                        }
                        cout << "Add more Meat Into Cart? Y|N" << endl;
                        cin >> tempppppp;
                    } while (tempppppp == 'Y');
                    break;

                case 2:
                    cout << "1 | MILK    600/PCKT" << endl;
                    cout << "2 |EGGS    240/DZN" << endl;
                    cout << "3 |YOGURT  100/PCKT" << endl;
                    cout << "4 |CHEESE  1000/PCKT" << endl;
                    do
                    {
                        cout << "Which Type Of DAIRY ITEMS Would You Like to Add To Cart?" << endl;
                        int selection;
                        cin >> selection;
                        if (selection == 1)
                        {
                            CART_TOTAL(600);
                        }
                        else if (selection == 2)
                        {
                            CART_TOTAL(240);
                        }
                        else if (selection == 3)
                        {
                            CART_TOTAL(100);
                        }
                        else if (selection == 4)
                        {
                            CART_TOTAL(1000);
                        }
                        cout << "Add more DAIRY ITEMS Into Cart? Y|N" << endl;
                        cin >> tempppppp;
                    } while (tempppppp == 'Y');
                    break;

                case 3:
                    cout << "1 | APPLES   400/KG" << endl;
                    cout << "2 | BANANA   250DZN" << endl;
                    cout << "3 | MANGO    500/KG" << endl;
                    cout << "4 | ORANGE   1000/PCKT" << endl;
                    do
                    {
                        cout << "Which Type Of FRUIT Would You Like to Add To Cart?" << endl;
                        int selection;
                        if (selection == 1)
                        {
                            CART_TOTAL(400);
                        }
                        else if (selection == 2)
                        {
                            CART_TOTAL(250);
                        }
                        else if (selection == 3)
                        {
                            CART_TOTAL(500);
                        }
                        else if (selection == 4)
                        {
                            CART_TOTAL(1000);
                        }
                        cout << "Add more FRUIT Into Cart? Y|N" << endl;
                        cin >> tempppppp;
                    } while (tempppppp == 'Y');
                    break;

                case 4:

                    cout << "1 | TOMATOES   400RS/KG" << endl;
                    cout << "2 | ONION      250RS/DZN" << endl;
                    cout << "3 | CUCUMBER   500RS/KG" << endl;
                    cout << "4 |POTATOES    1000RS/PCKT" << endl;

                    do
                    {
                        cout << "Which Type Of VEGES Would You Like to Add To Cart?" << endl;
                        int selection;
                        if (selection == 1)
                        {
                            CART_TOTAL(400);
                        }
                        else if (selection == 2)
                        {
                            CART_TOTAL(250);
                        }
                        else if (selection == 3)
                        {
                            CART_TOTAL(500);
                        }
                        else if (selection == 4)
                        {
                            CART_TOTAL(1000);
                        }
                        cout << "Add more VEGES Into Cart? Y|N" << endl;
                        cin >> tempppppp;
                    } while (tempppppp == 'Y');
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
                    {
                        if (tempSNACKS == 1)
                        {
                            cout << "1 | DAIRY MILK 110RS" << endl;
                            cout << "2 | KITKAT     220RS" << endl;
                            cout << "3 | HERSHEYS   445RS" << endl;
                            cin >> tempCHOC;
                            switch (tempCHOC)
                            {
                            case 1:
                                CART_TOTAL(110);
                                break;
                            case 2:
                                CART_TOTAL(220);
                                break;
                            case 3:
                                CART_TOTAL(445);
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
                            switch (tempCHOC)
                            {
                            case 1:
                                CART_TOTAL(110);
                                break;
                            case 2:
                                CART_TOTAL(20);
                                break;
                            case 3:
                                CART_TOTAL(70);
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
                            switch (tempCHOC)
                            {
                            case 1:
                                CART_TOTAL(110);
                                break;
                            case 2:
                                CART_TOTAL(20);
                                break;
                            case 3:
                                CART_TOTAL(70);
                                break;

                            default:
                                break;
                            }
                        }
                        cout << "Add more snacks? Y|N";
                        cin >> menusnacks;
                    } while (menusnacks == 'Y');
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
                        if (tempmasala == 1)
                        {
                            CART_TOTAL(110);
                        }
                        if (tempmasala == 2)
                        {
                            CART_TOTAL(210);
                        }
                        if (tempmasala == 3)
                        {
                            CART_TOTAL(310);
                        }
                        if (tempmasala == 4)
                        {
                            CART_TOTAL(410);
                        }

                        cout << "Want to add more SPICES? Y|N" << endl;
                        cin >> YESNO;
                    } while (YESNO == 'Y');
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
                            CART_TOTAL(110);
                        }
                        if (tempmasala == 2)
                        {
                            CART_TOTAL(210);
                        }
                        if (tempmasala == 3)
                        {
                            CART_TOTAL(310);
                        }
                        if (tempmasala == 4)
                        {
                            CART_TOTAL(410);
                        }

                        cout << "Want to add more GRAINS? Y|N" << endl;
                        cin >> YESNO2;
                    } while (YESNO2 == 'Y');
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
                        CART_TOTAL(110);
                    }
                    if (shampootemp == 2)
                    {
                        CART_TOTAL(170);
                    }
                    if (shampootemp == 3)
                    {
                        CART_TOTAL(400);
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
                        CART_TOTAL(110);
                    }
                    if (shampootemp == 2)
                    {
                        CART_TOTAL(170);
                    }
                    if (shampootemp == 3)
                    {
                        CART_TOTAL(400);
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
                        CART_TOTAL(110);
                    }
                    if (shampootemp == 2)
                    {
                        CART_TOTAL(140);
                    }
                    if (shampootemp == 3)
                    {
                        CART_TOTAL(430);
                    }
                }
                cout << "Want to add more items from this category? Y|N" << endl;
                cin >> YESNOTEMP3;
                // system("clear");
            } while (YESNOTEMP3 == 'Y');
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

                if (hygienetemp4 == 1)
                {
                    cout << "1 | NORMAL DET\t 		110RS " << endl;
                    cout << "2 | MEDIUM DET			170RS " << endl;
                    cout << "3 | HIGHLEVEL DET		400RS " << endl;
                    int shampootemp;
                    cin >> shampootemp;
                    if (shampootemp == 1)
                    {
                        CART_TOTAL(110);
                    }
                    if (shampootemp == 2)
                    {
                        CART_TOTAL(170);
                    }
                    if (shampootemp == 3)
                    {
                        CART_TOTAL(400);
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
                        CART_TOTAL(110);
                    }
                    if (shampootemp == 2)
                    {
                        CART_TOTAL(170);
                    }
                    if (shampootemp == 3)
                    {
                        CART_TOTAL(400);
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
                        CART_TOTAL(110);
                    }
                    if (shampootemp == 2)
                    {
                        CART_TOTAL(140);
                    }
                    if (shampootemp == 3)
                    {
                        CART_TOTAL(430);
                    }
                }
                cout << "Want to add more items from this category? Y|N" << endl;
                cin >> YESNOTEMP;
            } while (YESNOTEMP == 'Y');
            break;
        }

        cout << "Initiate Menu Again?" << endl;
        cin >> initatemenuagaintemp;
        system("clear");

    } while (initatemenuagaintemp == 'Y');
}
