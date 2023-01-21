#pragma once
#include <iostream>
#include "CUSTOMER.h"
using namespace std;

#ifndef PAYMENTMETHODS_H
// IN THIS FILE THREE TYPES OF PAYMENT SYSTEMS, EACH ARE POLYMORPHICALLY ACCESSED 

class EASYPAISA : public Customer
{
private:
    int StartingBalance;    // STARTING BALANCE OF EACH ACCOUNT 
    int PaymentRequired;    //HOW MUCH PAYMENT IS NEEDED TO BE DEDUCTED
    int storeRevenue;       //FROM WALLET TO STORE REVENUE
    bool TransactionFailed; //FLAG FOR FAILURE

public:
    EASYPAISA()
    {
        StartingBalance = 8200;
    }
    void setPaymentRequired(int A)
    {
        this->PaymentRequired;
    }

    void PaymentGatewaySystem(int a)
    {
        int Final_Payment = StartingBalance - PaymentRequired;
        if ((Final_Payment) > 0)
        {
            cout << "Your Transaction Has Been Succesfully Made Through EasyPaisa!" << endl;
            cout << "Expect Your Goods To Arrive IN Due Working Time!" << endl;
            StartingBalance = Final_Payment;
            storeRevenue = storeRevenue + PaymentRequired;
            TransactionFailed = 0;
        }
        else
        {
            cout << "Your Transaction Has Failed #ERROR-42" << endl;
            cout << "Insufficient Funds" << endl;
            TransactionFailed = 1;
        }
    }

protected:
};

class JAZZCASH : public Customer
{
private:
    int StartingBalance;
    int PaymentRequired;
    int storeRevenue;
    bool TransactionFailed;

public:
    JAZZCASH()
    {
        StartingBalance = 8200;
    }
    void setPaymentRequired(int A)
    {
        this->PaymentRequired;
    }

    void PaymentGatewaySystem(int a)
    {
        int Final_Payment = StartingBalance - PaymentRequired;
        if ((Final_Payment) > 0)
        {
            cout << "Your Transaction Has Been Succesfully Made Through Jazzcash!" << endl;
            cout << "Expect Your Goods To Arrive IN Due Working Time!" << endl;
            StartingBalance = Final_Payment;
            storeRevenue = storeRevenue + PaymentRequired;
            TransactionFailed = 0;
        }
        else
        {
            cout << "Your Transaction Has Failed #ERROR-42" << endl;
            cout << "Insufficient Funds" << endl;
            TransactionFailed = 1;
        }
    }

protected:
};

class CreditCardSystem : public Customer
{
private:
    int StartingBalance;
    int PaymentRequired;
    bool TransactionFailed;
    int storeRevenue;

public:
    CreditCardSystem()
    {
        StartingBalance = 50000;
    }
    void setPaymentRequired(int A)
    {
        this->PaymentRequired;
    }

    void PaymentGatewaySystem(int a)
    {
        int Final_Payment = StartingBalance = PaymentRequired;
        if ((Final_Payment) > 0)
        {
            cout << "Your Transaction Has Been Succesfully Made By Credit Card!" << endl;
            storeRevenue = storeRevenue + PaymentRequired;
            TransactionFailed = 0;
        }
        else
        {

            cout << "Your Transaction Has Failed #ERROR-12" << endl;
            cout << "SERVER RUNTIME ERROR #404#" << endl;
        }
    }
};

#endif
