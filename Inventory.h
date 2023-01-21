
//#pragma once
#include <iostream>
#include "CUSTOMER.h"
using namespace std;

#ifndef  INVENTORY_H
//LOGIC : AFTER BUYER BUYS ITEMS A FUNCTION RECIEVES THE AMOUNT OF ITEMS THEY HAVE
//BOUGHT AND THEN SUBSTRACTS THEM FROM THE INVENTORY
class Inventory
{
private:
    int KarachiInventory[3];
    int LahoreInventory[3];
    bool warningKarachi;


    protected:

    void accessKI()
    {

    }

    void accessLHR()
    {

    }
    void InventoryRefresh(int a , int amount  , char which)
    {
        if(which == 'K')
        {

        
        KarachiInventory[a] = KarachiInventory[a] - amount;
        if(KarachiInventory[a]<0)
        {
            bool warningKarachi = 1;
        }
        }
        else if(which == 'L')
        {

        
        LahoreInventory[a] = LahoreInventory[a] - amount;
         if(KarachiInventory[a]<0)
        {
            bool warningLahore = 1;
        }  
        }     
    }


public:
   
   
};


#endif // MACRO