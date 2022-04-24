# CS50 Final Project - BANKING SOFTWARE
#### Video Demo: https://youtu.be/DehysFlOAgU
#### Description:

This is a banking software written in c programming language and hence command driven.

The application is meant for the use by banking professionals to create different types
of accounts for the customers, record their deposit or withdrawl transactions , close their accounts,
update their details.

Technologies used:

- C programming language
- Included header files

## How the application works?

The password for login screen is : bank1234

The main menu of the software has 7 options for the user to select as detailed below:

- Open a new account
- Update existing account details
- Transactions(Deposit/Withdrawl)
- Account enquiry
- Close existing account
- Customer details (Complete list)
- Exit

## What does each menu item do ?

## 1.Open a new account :

      Creates a new banking account. The types of account allowed are savings,current,
      fixed deposits of various tenures. If the user tries to open an existing account number, the system will throw
      an error.

## 2.Update existing account details :

      Updates the existing bank account details.But here, the cash balances of the
      customer are not updated. Indeed, their personal and other info are updated.

## 3.Transactions(Deposit/Withdrawl) :

     To deposit or withdraw from an account.There is no limit on amount of
     deposits. But, however , to withdraw there needs to be sufficient funds in the account. Moreover, a customer
     cannot withdraw from Fixed deposit accounts.

## 4.Account enquiry :

     To enquire the account details. Wrongly entered account number would fetch an error message.
     The enquiry details will show the deposit amount, type of deposit and interest rates also.

## 5.Close existing account:

     Closes the selected bank account. The closed account details cannot be retrieved.

## 6.Customer details (Complete list):

     Lists the full details of all the customers. However, the account balances
     of the customers are not displayed in this screen.

## 7.Exit :

    Exits the application.

## How to launch application ?

    The files included are bank.c.
    Check that you are working in linux shell environment.
    Type 'make bank' to compile bank.c to an object file named 'bank'.
    Finally, execute the bank  using ./bank command.

## Possible improvements

    More validation checks to be done while accepting different inputs from the user.
    The user should not be given any opportunity to crash the software.







