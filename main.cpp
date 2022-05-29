#include <iostream>
#include <fstream>
#include <string.h>
#include <cctype>
#include <cstdlib>
#include <ctime>

using namespace std;
int RS_menu [] = {25,15,34,22,45,50,30,42,20,56,76,45,87,58,50,66,70,45,16,20,15,15,22,12,20,17,12,20,40,30,10,15,33,35,32,20};
string menu_of_order [36] = {"Fattouch","Green Salad","Caesar Salad","Greek Salad","Rocca Salad","Quinoa Salad","Tabbouleh","macaroni salad","chickpea salad","Meat Shank","Chef Lamb","Meat Biryani","Chicken Biryani","Chicken Pasta","Vegetable Pasta","Meat Lasagna","Broasted","Saj Shrimp","Orange Juice","Cocktail Juice","Lemon juice","avocado juice","Apple juice","Mango juice","beet juice","soft juice","peach juice","Cookies","Chocolate cake","Strawberry cheesecake","Apple pie","Waffle","Lotus cheesecake","Molten Cake","Lava cake","Donut"};

// Here is the structures for this project

// 1
struct customer
{
   char cus_first_name[10];
   char cus_last_name[10];
   char cus_neighborhood[20];
   string cus_email;
   string cus_nmber;
    
}customer_info;

// 2
struct wifi
{
    int number_1;
    int number_2;
    int total;
    
}process;

// Here is the prototypes of the functions used
void cus_info(customer &);
void display_menu();
int quantity( int &);
void The_Bill(int [] , int , int);
void calculate_bill(int [] , int , int , int *);
string Employee_Name();
void wifi_function(wifi [] , int);

int main()
{
    string ask , ask1 , ask2;
    string The_order [1000];
    double sum(0);
    int  count1(0) , count2(0) , count3(0);
    int order , nofood;
    int Bill [1000];
    int SA [1000];
    int x = 1 , z = 3 , a;
    wifi array[z];
    ofstream outfile_Bill;
    double Bill_ = 0.0;
    double Bill_Tax = 0.0;
    
    // Here we will call the menu function
    display_menu();
    
    do{
        cout<<"\nDo you want to order ? Yes/No ";
        cin>>ask;
        
        // for loop to convert all letters of (ask) to lowercase
        for (int i=0 ; i<3 ; i++)
        {
            ask[i]=tolower(ask[i]);
        }
        
        if(ask == "yes")
            // Here I will let him/her choose the dishes
        {
            cout<<"Please Enter The Order Number: ";
            cin>>order;
            
            //To check the order if it is in the correct range or not
            if(order < 1 || order > 36)
            {
                cout<<"\nSorry, this number is not in the menu\n";
                cout<<"Please Enter The Order Number: ";
                cin>>order;
            }
            
            //Array To add orders
            The_order [count1] = menu_of_order [order - 1];
            count1++;
            
            //asking about the quantity
            a = quantity(nofood);
            
            // Function To calculate how much each order costs
            calculate_bill(Bill , count2 , order , &nofood);
            count2++;
            
            // Function To add prices for selected orders
            The_Bill( SA , count3 , order);
            count3++;
            
            
            do{
                
            // This is to ask the customer if he/she wants to choose something else
            cout<<"\nDo you want to order anything else? Yes/No ";
            cin>>ask1;
            
            // for loop to convert all letters of (ask1) to lowercase
            for (int i=0 ; i<3 ; i++)
            {
            ask1[i]=tolower(ask1[i]);
            }
            
            if(ask1 == "yes")
            {
                cout<<"Please Enter The Order Number: ";
                cin>>order;
                
                //To check the order if it is in the correct range or not
                if(order < 1 || order > 36)
                {
                    cout<<"\nSorry, this number is not in the menu\n";
                    cout<<"Please Enter The Order Number: ";
                    cin>>order;
                }
                
                //Array To add orders
                The_order [count1] = menu_of_order [order - 1];
                count1++;
                
                //asking about the quantity
                a = quantity(nofood);
                
                
                // Function To calculate how much each order costs
                calculate_bill(Bill , count2 , order , &nofood);
                count2++;
                
                // function To add prices for selected orders
                The_Bill( SA , count3 , order);
                count3++;
            }
            
            if(ask1 == "no")
            {
                // for loop to display the order
                cout<<"\n\n  ::::::::::::::::::::::::::::::::::";
                cout<<"\n  :      This is your order        :\n";
                cout<<"  ::::::::::::::::::::::::::::::::::\n\n";
                for(int i = 0 ; i < count1 ; i++)
                {cout<<x<<". "<<The_order[i]<<"      "<<SA[i]<<" RS"<<endl;
                    x++;}
                
                // for loop to calculate the bill
                for(int i = 0 ; i < count2 ; i++)
                {sum += Bill [i];}
                Bill_ = sum;
                Bill_Tax = (sum * 0.15) + sum;
                cout<<"\nYour Total Bill is: "<<sum<<" RS\n"<<endl;
                cout<<"Your bill after adding tax (15%) is "<<(sum * 0.15) + sum<<" RS"<<endl;
                
                // Here we used the search method for discount offers
                for(int i = 0 ; i < count1 ; i++)
                {
                    if(The_order[i] == menu_of_order [11] || The_order[i] == menu_of_order [12])
                    {
                        for(int i = 0 ; i < count1 ; i++)
                        {
                            if(The_order[i] == menu_of_order [22])
                            {
                                Bill_ = sum - 22;
                                Bill_Tax = (Bill_ * 0.15) + Bill_;
                                cout<<"\nCongratulations, you will get a discount (free apple juice)\n";
                                cout<<"\nYour New Bill is: "<<Bill_<<" RS\n"<<endl;
                                cout<<"\nYour bill after adding tax (15%) is "<<Bill_Tax;
                            }
                            
                        }
                    }
                }
                
                // Here we used the search method for discount offers
                for(int i = 0 ; i < count1 ; i++)
                {
                    if(The_order[i] == menu_of_order [28] || The_order[i] == menu_of_order [33])
                    {
                        for(int i = 0 ; i < count1 ; i++)
                        {
                            if(The_order[i] == menu_of_order [30])
                            {
                                Bill_ = sum - 10;
                                Bill_Tax = (Bill_ * 0.15) + Bill_;
                                cout<<"\nCongratulations, you will get a discount (free apple pie)\n";
                                cout<<"\nYour New Bill is: "<<Bill_<<" RS\n"<<endl;
                                cout<<"\nYour bill after adding tax (15%) is "<<Bill_Tax;
                            }
                            
                       }
                    }
                 }
              }
           }while(ask1 != "no");
            break;
        }
        
        else if(ask == "no")
        {
            cout<<"\nThank you for visiting us .. hope to see you again !\n\n";
            break;
        }
        
        else
        {
            cout<<"Invalid entry, try again\n";
            cout<<"\nDo you want to order ? Yse/No ";
            cin>>ask;
            
            // for loop to convert all letters of (ask) to lowercase
            for (int i=0;i<3;i++)
            {
            ask[i]=tolower(ask[i]);
            }
        }
        
    }while(ask != "no");
    
    // Here the customer will choose if he/she wants to cancel the order or not
    cout<<"\nIf you want to cancel the order, please choose Yes or No ";
    cin>>ask2;
    if(ask2 == "yes")
    {cout<<"\nYour order has been successfully canceled. Thank you for visiting us\n\n";}
    
    else if(ask2 == "no")
    { cout<<"\nWe will now prepare the order. Thank you for waiting\n ";
    
        //call of wifi_function function
        wifi_function(array , z);
        
        //call of cus_info function
       cus_info(customer_info);
    }
    
    // Here we will open a file and save the information
    outfile_Bill.open("Afile.txt");
    if(outfile_Bill.is_open())
    {
        outfile_Bill<<"The first name is "<<customer_info.cus_first_name<<endl<<endl;
        outfile_Bill<<"The last name is "<<customer_info.cus_last_name<<endl<<endl;
        outfile_Bill<<"The Neighborhood is "<<customer_info.cus_neighborhood<<endl<<endl;
        outfile_Bill<<"The email is "<<customer_info.cus_email<<endl<<endl;
        outfile_Bill<<"The phone Number is "<<customer_info.cus_nmber<<endl<<endl;
        outfile_Bill<<"The order is: \n";
        for(int i = 0 ; i < count1 ; i++)
        {outfile_Bill<<x<<". "<<The_order[i]<<"      "<<SA[i]<<" RS"<<endl;
            x++;}
        outfile_Bill<<"\nThe Total Bill is "<<Bill_<<endl;
        outfile_Bill<<"\nYour bill after adding tax (15%) is "<<Bill_Tax<<endl;
    }
    // After storing the information, we will close the file
    outfile_Bill.close();
    
    
    
    
    
    
}

// function to display the menu
void display_menu()
{
    int Number = 1;
    string menu [36] = {"Fattouch                      |","Green Salad                   |","Caesar Salad                  |","Greek Salad                   |","Rocca Salad                   |","Quinoa Salad                  |","Tabbouleh                     |","macaroni salad                |","chickpea salad                |","Meat Shank                   |","Chef Lamb                    |","Meat Biryani                 |","Chicken Biryani              |","Chicken Pasta                |","Vegetable Pasta              |","Meat Lasagna                 |","Broasted                     |","Saj Shrimp                   |","Orange Juice                 |","Cocktail Juice               |","Lemon juice                  |","avocado juice                |","Apple juice                  |","Mango juice                  |","beet juice                   |","soft juice                   |","peach juice                  |","Cookies                      |","Chocolate cake               |","Strawberry cheesecake        |","Apple pie                    |","Waffle                       |","Lotus cheesecake             |","Molten Cake                  |","Lava cake                    |","Donut                        |"};
    
    
    cout<<"\n------------------------------------------------------------Welcome to MASA Restaurant-----------------------------------------------------------\n";
    cout<<endl;
    // Here we will call the Employee_Name function
    cout<<"Hi my name is "<<Employee_Name()<<" I will serve you today, please take your time";
    cout<<endl;
    cout<<"\n-----------------------------------------------------------This is our restaurant's menu---------------------------------------------------------\n";
    cout<<"\n... All offers available at the moment ...\n";
    cout<<"* If you order chicken biryani or meat biryani, you will get Apple juice for free\n";
    cout<<"* If you order a Chocolate cake and Molten Cake, you will get Apple Pie for free\n";
    cout<<"\nAmong the famous dishes in MASA restaurant are chicken biryani, meat biryani, as well as chocolate cake and Waffle\n\n";
    cout<<"\n----------------------------------------------\n";
    cout<<"              Dishes              |   Price  |\n";
    cout<<"----------------------------------------------\n";
    
    for(int i = 0 ; i < 36 ; i++)
    {
        cout<<Number<<".  "<<menu [i]<<"  "<<RS_menu[i]<<"  RS  |"<<endl;
        cout<<"----------------------------------------------\n";
        Number++;
    }
}

//function to ask about the quantity
int quantity(int &nofood)
{
    cout<<"Please Enter Food Quantity: ";
    cin>>nofood;
    return nofood;
    
}

// A function that contains an array parameter to add the price of each order
void The_Bill(int arr[] , int size , int order)
{
    arr [size] = RS_menu [order - 1];
}

// A function that contains an array parameter and pointer to calculate the bill
void calculate_bill(int arr[] , int size , int order , int *p1)
{
    // Here we used the dynamic variable
    int *p2;
    p2 = new int;
    p2 = p1;
    arr [size] = RS_menu [order - 1] * (*p2);
}

// This function prints the name of the employee who will perform the service
string Employee_Name()
{
    int x;
    string array_name [15] = {"Emma","Ali","salem","Ava","Hajer","Rawan","Ahmad","Adam","Ibrahim","Arwa","Aseel","Asma","Amal","Jaber","Tamer"};
    // Here we will use the rand function
    srand(static_cast<int>(time(0)));
    x = 0 + rand() % (14 - 0 + 1);
    return array_name [x];
}

//Here we will use a function and pass it an array of the structure to guess the result of an arithmetic operation
void wifi_function(wifi array[] , int x)
{
    srand(static_cast<int>(time(0)));
    cout<<"\nWe will play a game If you solve the following equation, you will get free internet. Think well\n\n";
    for(int i = 0 ; i < x ; i++)
    {
        process.number_1 = 1 + rand() % (50 - 1 + 1);
        process.number_2 = 1 + rand() % (50 - 1 + 1);
        cout<<process.number_1<<" + "<<process.number_2<<" = ";
        cin>>process.total;
        if(process.total == process.number_1 + process.number_2)
        {
            cout<<"\n\nWell done, you solved the equation. This is the word for our internet \" MASA 4611 \""<<endl<<endl;
            break;
        }
        else
            cout<<"\nTry agin\n";
    }
}

// struct function to ask the customer to enter his/her informatiom
void cus_info(customer &c)
{
    cout<<"\n------------------------------------------------------------Please enter your information-----------------------------------------------------------\n";

    cout << "Enter your first Name:  ";
    cin >> c.cus_first_name;
    cout<<endl;
   
    cout << "Enter your last Name:  ";
    cin >> c.cus_last_name;
    cout<<endl;

    cout << "Enter your Neighborhood:  ";
    cin >> c.cus_neighborhood;
    cout<<endl;

    cout << "Enter your email:  ";
    cin >> c.cus_email;
    cout<<endl;

    cout << "Enter your Number:  ";
    cin >> c.cus_nmber;

// To check if the input is all digit
    for (int i=0; i<10;i++){
        if (! isdigit(c.cus_nmber[i]))
        do{
            cout<<"It must be 10 digit .. please enter Number again: ";
            cin>>c.cus_nmber;

        }while(! isdigit(c.cus_nmber[i]));

    }
    cout<<endl;
}
