#include <iostream>
#include "ADMIN2.h"
#include <string>
#include <cstring>
using namespace std;
#ifndef ManageProductCatalogue

class ProductCatalogue
{

private:
    // int ArrayOfMeatQ[];
    // int ArrayOfDaiyQ[];
    // int ArrayOfFruitQ[];
    // int ArrayOfVegetableQ[];
    // int ArrayOfSnacksQ[];
    // int ArrayOfSpicesQ[];
    // int ArrayOfGrainsQ[];

    // char MainCategory[][];
    int ***MainCategoryFood;
    int **PerishableGOODS;
    int *Meat;
    int *Dairy;
    int *fruit;
    int *veges;
    int **NONPerishableGOODS;
    int *Snacks;
    int *Spices;
    int *Grains;
    int *Cereal;
    int **MainCategoryPersonalHygiene;
    int *Shampoo;
    int *Soap;
    int *Sanitizer;

    int **MainCategoryHouseHold;
    int *Detergent;
    int *DishSoap;
    int *WashroomCleaner;

    int FOODCONSISTS;
    int PerishConsists;
    int NONperishConsists;
    int MeatConsists;
    int DairyConsists;
    int FruitConsists;
    int VegetableConsists;
    int SnacksConsists;
    int SpicesConsists;
    int GrainConsists;
    int CerealConsists;
    int PHC;
    int HHC;
    int ShampooConsists;
    int SanitizerConsists;
    int DetergentConsists;
    int DishConsists;
    int WashCleanerConsists;
    int SoapConsists;
    string MainCategory1, MainCategory2, MainCategory3;
    string subcat11, subcat12;
    string subsubcat111, subsubcat112, subsubcat113, subsubcat114;
    string subsubcat121, subsubcat122, subsubcat123, subsubcat124;
    // Strings For Each SubCategories
    string subcat21, subcat22, subcat23;
    string subcat31, subcat32, subcat33;
    int AllMainCategories;
    int AddOneToSubFood;
    int PersonalHygieneSubCategories;
    string NEW[3];
    string *ArrayOfMainCategories;
    string *SubCategoryFoodArray;
    string *SubCategoryPHarray;
    char mychoiceofexpansion;

public:
    static int counter;
    void initalizeDefaultCatelogue()
    {
        // BY DEFAULT INITALIZE A CATALOGUE
        AllMainCategories = 3;            // refers to maincategories
        AddOneToSubFood = 2;              // refers to perishable and non perishable
        PersonalHygieneSubCategories = 3; // subcategories of maincategory personal hygiene
        ArrayOfMainCategories = new string[AllMainCategories];
        SubCategoryFoodArray = new string[AddOneToSubFood];
        SubCategoryPHarray = new string[PersonalHygieneSubCategories];
        ArrayOfMainCategories[0] = "FOOD";
        ArrayOfMainCategories[1] = "PERSONAL HYGIENE";
        ArrayOfMainCategories[2] = "HOUSEHOLDCLEANING";

        SubCategoryFoodArray[0] = "Perishable";
        SubCategoryFoodArray[1] = "NON-PERISHABLE";

        SubCategoryPHarray[0] = "SHAMPOO";
        SubCategoryPHarray[1] = "SOAP";
        SubCategoryPHarray[2] = "Sanitizer";

        // char ShowNEW[AllMainCategories][100];
        MainCategory1 = "FOOD";
        MainCategory2 = "PersonalHygiene";
        MainCategory3 = "HouseHold";
        subcat11 = "PerishableGoods";
        subcat12 = "NON-PerishAbleGoods";
        subsubcat111 = "MEAT";
        subsubcat112 = "DAIRY";
        subsubcat113 = "Fruit";

        subsubcat121 = "Snacks";
        subsubcat122 = "Spices";
        subsubcat123 = "Grains";

        subcat21 = "Shampoo's";
        subcat22 = "Soaps";
        subcat23 = "Sanitizers";

        subcat31 = "Detergents";
        subcat32 = "DishSoaps";
        subcat33 = "WashroomCleaners";
    }
    void ShowDefaultMenu() // CATELOGUE MANAGEMENT SYSTEM
    {
        cout << "WELCOME TO CMS, ADMIN. Explore Your Options : " << endl;

        cout << "1 | Display The Standard Catalogue\n";
        cout << "2 | Make Changes To The Exisiting Catalogue\n";
        // EITHER MAKE CHANGES OR DISPLAY NORMAL
        int temp;
        cin >> temp;
        if (temp == 1)
        {
            initalizeDefaultCatelogue(); // FILLS THE STRING DOWN BELOW
            cout << MainCategory1 << endl;
            cout << "  " << subcat11 << endl;
            cout << "     " << subsubcat111 << endl;
            cout << "     " << subsubcat112 << endl;
            cout << "     " << subsubcat113 << endl;
            cout << "     " << subsubcat114 << endl;

            cout << " " << subcat12 << endl;
            cout << "     " << subsubcat121 << endl;
            cout << "     " << subsubcat122 << endl;
            cout << "     " << subsubcat123 << endl;
            cout << "     " << subsubcat124 << endl;
            cout << " " << MainCategory2 << endl;
            cout << "     " << subcat21 << endl;
            cout << "     " << subcat22 << endl;
            cout << "     " << subcat23 << endl;

            cout << " " << MainCategory3 << endl;
            cout << "     " << subcat31 << endl;
            cout << "     " << subcat32 << endl;
            cout << "     " << subcat33 << endl;
        }
        if (temp == 2)
        {
            CategoryManipulation();
        }
    }
    ProductCatalogue()
    {
        FOODCONSISTS = 2;

        PerishConsists = 4;
        MeatConsists = 4;
        DairyConsists = 4;
        FruitConsists = 4;
        VegetableConsists = 4;
        NONperishConsists = 4;
        SnacksConsists = 3;
        SpicesConsists = 1;
        GrainConsists = 4;
        CerealConsists = 1;
        ShampooConsists = 1;
        SanitizerConsists = 1;
        DetergentConsists = 1;
        DishConsists = 1;
        WashCleanerConsists = 1;
        SoapConsists = 1;

        PHC = 3;
        HHC = 3;

        for (int i = 0; i <= FOODCONSISTS; i++)
        {
            MainCategoryFood = new int **[i];
        }
        for (int i = 0; i <= PerishConsists; i++)
        {
            PerishableGOODS = new int *[i];
        }
        for (int i = 0; i <= PHC; i++)
        {
            MainCategoryPersonalHygiene = new int *[i];
        }
        for (int i = 0; i <= PHC; i++)
        {
            MainCategoryHouseHold = new int *[i];
        }

        Meat = new int[MeatConsists];
        Dairy = new int[DairyConsists];
        fruit = new int[FruitConsists];
        veges = new int[VegetableConsists];
        Snacks = new int[SnacksConsists];
        Spices = new int[SpicesConsists];
        Grains = new int[GrainConsists];
        Cereal = new int[CerealConsists];
        Shampoo = new int[ShampooConsists];
        Soap = new int[SoapConsists];
        Sanitizer = new int[SanitizerConsists];
        Detergent = new int[DetergentConsists];
        DishSoap = new int[DishConsists];
        WashroomCleaner = new int[WashCleanerConsists];

        MainCategoryFood[0] = PerishableGOODS;
        PerishableGOODS[0] = Meat;
        PerishableGOODS[1] = Dairy;
        PerishableGOODS[2] = fruit;
        PerishableGOODS[3] = veges;
    }
    string *AddNewMainCategory() // LOGIC: Add new main category by allocating a new array of size+1
    {                            // and then new category is input as new arrays last index

        string tempp;
        AllMainCategories = AllMainCategories + 1;
        string *temparray = new string[AllMainCategories];

        for (int i = 0; i < AllMainCategories; i++)
        {
            temparray[i] = ArrayOfMainCategories[i];
        }

        ArrayOfMainCategories = new string[AllMainCategories];
        for (int i = 0; i < AllMainCategories; i++)
        {
            ArrayOfMainCategories[i] = temparray[i];
        }

        cout << "Name this main category : " << endl;
        cin >> temparray[AllMainCategories - 1];
        for (int i = 0; i < AllMainCategories; i++)
        {
            ArrayOfMainCategories[i] = temparray[i];
        }
        for (int i = 0; i < AllMainCategories; i++)
        {
            cout << ArrayOfMainCategories[i] << endl;
        }

        counter++;

        return temparray;
    }

    void JoinUpdatedPointers() // NOT USED
    {
    }
    void ShowCategory() // SHOW ALL MAIN CATEGORIES
    {
        cout << "This this following category for all the Stores\n";

        for (int i = 0; i < AllMainCategories; i++)
        {
            cout << ArrayOfMainCategories[i] << endl;
        }
    }
    void ShowUpdatedCategory(string *newww) // SHOW NEWEST UPDATIONS
    {
        for (int i = 0; i < AllMainCategories; i++)
        {
            cout << newww[i] << endl;
        }
    }

    void CategoryManipulation() // ACCESSED IF USER WANTS TO UPDATE
    {
        int temp;
        int counter = 1;
        initalizeDefaultCatelogue();
        cout << "Take a look at the Catalogue before editing : " << endl;
        cout << "Procede appropriately to make changes : " << endl;
        cin.get();
        ShowCategory();
        cout << "1 | Update the Main Category \n";
        cout << "2 | Update the Sub-Category Of Any Main-Category\n";
        // cout << "TBD\n"; // design a catalogue from scratch
        // cout << "TBD\n"; //
        int temp2;
        int SubCategoryIsChosen;
        mychoiceofexpansion = 'J';
        cin >> temp2;
        while (temp2 == 1)
        {

            string *RECVV = AddNewMainCategory(); // Recieving pointer adds new main category by receing a new poiner
            cout << "THE UPDATED MAIN CATALOGUE IS : " << endl;
            ShowUpdatedCategory(RECVV); // that is passed into this function and shows by updation
            cout << "1 | MAKE ADDITIONAL MAIN CATEGORIES " << endl;
            cout << "2 | EXIT" << endl;
            cin >> temp2;
            while (temp2 != 1 && temp2 != 2)
            {
                cout << "Wrong Choice! Re-enter" << endl;
            }
        }

        // a loop starts here
        int which;
        int arraywhich[100];
        // User can now update any subcategory
        cout << "Select A main category to exapand on : " << endl;
        int somehowanothertempvariable;
        cin >> somehowanothertempvariable;
        cout << "You Are Currently Expanding On MainCategory : " << ArrayOfMainCategories[somehowanothertempvariable] << endl;

        if (mychoiceofexpansion == 'J')
        {
            cout << "Add suitable sub-categories here for " << ArrayOfMainCategories[0] << endl;

            if (counter == 1)
            {
                string *RECVV2 = AddNewSUBCategory(); // subcategory for food
            }
            counter++;
            cout << "You must enter atleast one initial content of this subcategory, procede :  " << endl;
            if (counter == 2)
            {
                string *RECVV3 = AddNewSUBCategory(); // things in this subcategory
                mychoiceofexpansion = 'K';
            }
        }
        void showcompleteMENU(); // Shows complete menu
    }

    void showcompletemenu()
    {
        cout << "Preview Menu After Changes? Y|N " << endl;
        char temP;
        cin >> temP;
        if (temP == 'y' || temP == 'Y')
        {
            cout << "MainCategories  :  " << endl;
            for (int i = 0; i < sizeof(ArrayOfMainCategories); i++)
            {
                cout << ArrayOfMainCategories[i] << endl;
            }

            cout << "List of all the subcategories(Irrespective of Grouping with Main-C) : " << endl;
            for (int i = 0; i < sizeof(SubCategoryFoodArray); i++)
            {
                cout << SubCategoryFoodArray[i] << endl;
            }

            for (int i = 0; i < sizeof(SubCategoryFoodArray); i++)
            {
                cout << SubCategoryPHarray[i] << endl;
            }
        }
    }
    string *AddNewSUBCategory() // Works same as main category updation

    {
        static int counter1 = 0;
        static int counter2 = 0;
        if (mychoiceofexpansion == 'J')
        {
            string tempp;
            AddOneToSubFood = AddOneToSubFood + 1;
            string *temparray = new string[AddOneToSubFood];

            for (int i = 0; i < AddOneToSubFood; i++)
            {
                temparray[i] = SubCategoryFoodArray[i];
            }

            ArrayOfMainCategories = new string[AddOneToSubFood];
            for (int i = 0; i < AddOneToSubFood; i++)
            {
                SubCategoryFoodArray[i] = temparray[i];
            }

            if (counter1 == 0)
            {
                cout << "Write A Name For The Subcategory you'd like to add here?: " << endl;
                counter1++;
            }
            else
            {
                cout << "Write A Name For The items of this Subcategory you'd: " << endl;
            }
            cin >> temparray[AddOneToSubFood - 1];
            for (int i = 0; i < AddOneToSubFood; i++)
            {
                SubCategoryFoodArray[i] = temparray[i];
            }
            for (int i = 0; i < AddOneToSubFood; i++)
            {
                cout << "AHHAHAH" << SubCategoryFoodArray[i] << endl;
            }

            counter++;

            return temparray;
        }
    }

protected:
};
int ProductCatalogue ::counter = 1;

#endif