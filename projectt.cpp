#include<iostream>
#include<fstream>
using namespace std;

//A base class named Product
class Product {
protected:
    int pcode;
    float price;
    string pname;
    string typeproduct;

public:
void list() {
        cout << "\n\n|___________________________________________________________\n";
        cout << "ProNo\t\tName\t\tPrice\t\tType\n";
        cout << "\n\n|___________________________________________________________\n";
        cout << pcode << "\t\t" << pname << "\t\t" << price << "\t\t" << typeproduct << "\n";
    }
};

//Derived class shopping from base class Product
class shopping : public Product
{
	private:
		int pcode;
		float price;
		string pname;
		string typeproduct;
		
	public:
    void menu();
    void administrator();
    void buyer();
    void add();
    void edit();
    void rem();
    void list();
    void payment(float total);
    void receipt(); 
	void creditCardPayment(float total);
};

void shopping :: menu()
{
	m:
	int choice;
	int ch;
	string email;
	string password;
        // Displaying the main menu
cout << "\t\t\t\t______________________________________\n";
    cout << "\t\t\t\t                                      \n";
    cout << "\t\t\t\t          Supermarket Main Menu       \n";
    cout << "\t\t\t\t                                      \n";
    cout << "\t\t\t\t______________________________________\n";
    cout << "\t\t\t\t| 1) Admin             |\n";
    cout << "\t\t\t\t|                      |\n";
    cout << "\t\t\t\t| 2) Customer          |\n";
    cout << "\t\t\t\t|                      |\n";
    cout << "\t\t\t\t| 3) Exit              |\n";
    cout << "\t\t\t\t|______________________|\n";
	cout<<"\n\t\t\t Please select!";
	cin>>choice;
	
	switch(choice)
	{
		case 1:
			start:
            // Admin login section
			cout<<"\t\t\t Please enter your Login credentials \n";
			cout<<"\t\t\t Enter your email address  \n";
			cin>>email;
			cout<<"\t\t\t Enter your Password       \n";
			cin>>password;
			if(email=="aryanguragain@gmail.com" && password=="aryan123")
			{
				administrator();
			}
			else
			{
				cout<<"Invalid email/password.Please Try again\n";
				goto start;
			}
			break;
	
	
	case 2:
		{
			buyer();
			
		}
		break;
	
	case 3:
		{
			exit(0);
		}
		break;
		
		default :
			{
				cout<< "Please select from the given options";
				
			}
			
	
}
goto m;
}

void shopping:: administrator()
{
	m:
	int choice;
	cout<<"\n\n\n\t\t\t Administrator menu";
	cout << "\n\n\n\t\t\t   Administrator Menu";
	cout << "\n\t\t\t**************************";
	cout << "\n\t\t\t| 1) Add a new product   |";
	cout << "\n\t\t\t| 2) Edit a product  	 |";
	cout << "\n\t\t\t| 3) Delete a product    |";
	cout << "\n\t\t\t| 4) Back to main menu   |";
	cout << "\n\t\t\t**************************";
    
    cout<<"\n\n\t Please enter your choice ";
    cin>>choice;
    
    switch(choice)
    {
    	case 1:
    		add();
    		break;
    		
    	case 2:
    		edit();
    		break;
    		
    	case 3:
    		rem();
    		break;
    		
    	case 4:
    		menu();
    		break;
    		
    	default :
    		cout<<"Invalid choice!";
    		
	}
	goto m;
}

void shopping:: buyer()
{
	m:
    //Customer buying section
	int choice;
	cout<<"\t\t\t  Buyer \n";
	cout<<"\t\t\t_____________  \n";
	cout<<"                     \n";
	cout<<"\t\t\t1) Buy product \n";
	cout<<"                     \n";
	cout<<"\t\t\t2) Go back     \n";
	cout<<"\t\t\t Enter your choice : ";
	
	cin>>choice;
	
	switch(choice)
	{
		case 1:
			receipt();
			break;
			
		case 2:
			menu();
			
		default :
			
			cout<<"invalid choice";
			
	}
	
	goto m;
	
	
}

void shopping::add()
{
    m:
    fstream data;
    int c;
    int token = 0;
    float p;
    string n;
    string t;
    // Adding a new product to the supermarket inventory
    cout << "\n\n\t\t\t Add new product";
    cout << "\n\n\t Product code of the product ";
    cin >> pcode;
    cout << "\n\n\t Name of the product ";
    cin >> pname;
    cout << "\n\n\t Price of the product";
    cin >> price;
    cout << "\n\n\t Type of the Product";
    cin >> typeproduct;
    data.open("database.txt", ios::in);

    if (!data)
    {
        data.open("database.txt", ios::app | ios::out);
        data << " " << pcode << " " << pname << " " << price << " " << typeproduct << "\n";
        data.close();
    }
    else
    {
        data >> c >> n >> p >> t;

        while (!data.eof())
        {
            if (c == pcode)
            {
                token++;
            }
            data >> c >> n >> p >> t;
        }
        data.close();

        if (token == 1)
            goto m;
        else
        {
            data.open("database.txt", ios::app | ios::out);
            data << " " << pcode << " " << pname << " " << price << " " << typeproduct << "\n";
            data.close();
        }
    }
    cout << "\n\n\t\t Record inserted !";
}


void shopping::edit()
{
    fstream data, data1;
    int pkey;
    int token = 0;
    int c;
    float p;
    string n;
    string t;
    // Modifying an existing product in the supermarket inventory
    cout << "\n\t\t\t Modify the record";
    cout << "\n\t\t\t Product code :";
    cin >> pkey;

    data.open("database.txt", ios::in);
    if (!data)
    {
        cout << "\n\nFile doesn't exist! ";
    }
    else
    {
        data1.open("database1.txt", ios::app | ios::out);

        data >> pcode >> pname >> price >> typeproduct;
        while (!data.eof())
        {
            if (pkey == pcode)
            {
                cout << "\n\t\t Product new code :";
                cin >> c;
                cout << "\n\t\t Name of the product :";
                cin >> n;
                cout << "\n\t\t Price :";
                cin >> p;
                cout << "\n\t\t Product Type:";
                cin >> t;
                data1 << " " << c << " " << n << " " << p << " " << t << "\n";
                cout << "\n\n\t\t Record edited ";
                token++;
            }
            else
            {
                data1 << " " << pcode << " " << pname << " " << price << " " << typeproduct << "\n";
            }
            data >> pcode >> pname >> price >> typeproduct;
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt", "database.txt");

        if (token == 0)
        {
            cout << "\n\n Record not found sorry!";
        }
    }
}

void shopping::rem()
{
    fstream data, data1;
    int pkey;
    int token = 0;
    // Deleting a product from the supermarket inventory
    cout << "\n\n\t Delete product";
    cout << "\n\n\t Product code :";
    cin >> pkey;
    data.open("database.txt", ios::in);
    if (!data)
    {
        cout << "File doesn't exist";
    }
    else
    {
        data1.open("database1.txt", ios::app | ios::out);
        data >> pcode >> pname >> price >> typeproduct;
        while (!data.eof())
        {
            if (pcode == pkey)
            {
                cout << "\n\n\t Product deleted successfully";
                token++;
            }
            else
            {
                data1 << " " << pcode << " " << pname << " " << price << " " << typeproduct << "\n";
            }
            data >> pcode >> pname >> price >> typeproduct;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt", "database.txt");

        if (token == 0)
        {
            cout << "\n\n Record not found";
        }
    }
}

void shopping::list()
{
   fstream data;
    data.open("database.txt", ios::in);
	cout<<"WELCOME TO ARYAN'S SUPERMARKET AND ELECTRONICS\n";
	cout<<"Choose the items you wish to buy\n";
    cout << "\n\n|___________________________________________________________\n";
    cout << "ProNo\t\tName\t\tPrice\t\tType\n";
    cout << "\n\n|___________________________________________________________\n";
    data >> pcode >> pname >> price >> typeproduct;
    while (!data.eof())
    {
        cout << pcode << "\t\t" << pname << "\t\t" << price << "\t\t" << typeproduct << "\n";
        data >> pcode >> pname >> price >> typeproduct;
    }
    data.close();
}


void shopping::creditCardPayment(float total)
{
    string cardNumber;
    string expirationDate;
    string cvv;

    cout << "\n\n Enter Credit Card Number: ";
    cin >> cardNumber;
	while (cardNumber.length() != 16 ) {
        cout << " Invalid credit card number. Please enter a valid 16-digit card number: ";
        cin >> cardNumber;
    }

    cout << " Enter Expiration Date (MM/YY): ";
    cin >> expirationDate;

    cout << " Enter CVV: ";
    cin >> cvv;
	if (cvv.length() != 4) {
        cout << " Invalid CVV. Please enter a valid 3 or 4-digit CVV: ";
        cin >> cvv;
    }

    // You may want to add more validation for credit card information

    cout << "\n\n Processing credit card payment...";
    cout << "\n Payment successful! Thank you for shopping!";
}

void shopping::payment(float total)
{
    char paymentChoice;
    cout << "\n\n Would you like to pay with cash (c) or credit card (d)? ";
    cin >> paymentChoice;

    if (paymentChoice == 'c' || paymentChoice == 'C')
    {
        float paid, change;
        cout << "\n Enter the amount of money provided: ";
        cin >> paid;

        if (paid >= total)
        {
            change = paid - total;
            cout << "\n Payment successful!";
            cout << "\n Change to return: " << change;
        }
        else
        {
            cout << "\n Insufficient amount provided. Payment failed!";
        }
    }
    else if (paymentChoice == 'd' || paymentChoice == 'D')
    {
        creditCardPayment(total);
    }
    else
    {
        cout << "\n Invalid payment option. Payment cancelled.";
    }
}

void shopping::receipt()
{
    system("cls");
    fstream data;

    int arrc[100], arrq[100];
    char choice;
    int c = 0;
    float amount = 0;
    float dis = 0;
    float total = 0;
    cout << "\n\n\t\t\t Receipt \n";
    data.open("database.txt", ios::in);
    if (!data)
    {
        cout << "\n\n Empty database";
    }
    else
    {
        data.close();
        list();
        cout << "\n____________________________\n";
        cout << "\n|                            |";
        cout << "\n|    Please place the order  |";
        cout << "\n|____________________________|\n";
        do
        {
            m:
            cout << "\n\n Product Code : ";
            cin >> arrc[c];
            cout << "\n Product Quantity : ";
            cin >> arrq[c];
            for (int i = 0; i < c; i++)
            {
                if (arrc[c] == arrc[i])
                {
                    cout << "\n\n Duplicate Product Code. Please try again!";
                    goto m;
                }
            }
            c++;
            cout << "\n\n Want to buy another product? Press y for yes and n for no : ";
            cin >> choice;
        }

        while (choice == 'y');
        system("cls");

        cout << "\n\n\t\t\t__________**Your Receipt**______________\n";
    cout << "\nProduct Num.\tProduct Name\tProduct Type.\tQuantity \tPrice\t\tAmount";

        for (int i = 0; i < c; i++)
        {
            data.open("database.txt", ios::in);
            data >> pcode >> pname >> price >> typeproduct;
            while (!data.eof())
            {
                if (pcode == arrc[i])
                {
                    amount = price * arrq[i];

                    total += amount;
                    cout << "\n" << pcode << "\t\t" << pname << "\t\t" << typeproduct << "\t\t" << arrq[i] << "\t\t" << price << "\t\t" << amount;
                }
                data >> pcode >> pname >> price >> typeproduct;
            }
            data.close();
        }
        cout << "\n\n----------------------------------------";
        cout << "\n Total Amount : " << total;
        payment(total);
    }
}
int main()
{
    
	shopping s;
    	s.menu();
}

