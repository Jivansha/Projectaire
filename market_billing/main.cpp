#include <iostream>
#include<fstream>
#include<iomanip>
#include<ctime>
#include<stdlib.h>

using namespace std;
int const tax=0.053;
class product
{
    int code,qty;
    char name[15];
    float price,discount,amount;
public:
    void get_data();
    float cal_amount();
    void display();
};
void product::get_data()
{
    cout<<"Enter details-\n";
    cout<<"Product code- ";  cin>>code;
    cout<<"Product quantity- ";  cin>>qty;
    cout<<"Product name- ";  cin>>name;
    cout<<"Product price- ";  cin>>price;
    cout<<"Product discount- ";  cin>>discount;
}
float product::cal_amount()
{
    amount=((1-discount*.01)*price)+price*tax;
    return(amount);
}
void product::display()
{
    cout<<"\n"<<setw(5)<<code<<setw(10)<<name<<setw(12)<<setprecision(2)<<price<<setw(8)<<amount;
}
int main()
{
    fstream data;
    data.open("sale_data.txt",ios::in | ios::out | ios::ate |ios::binary);

    float total=0;
    int no;
    cout<<"\nEnter total number of items- ";
    cin>>no;
    cout.setf(ios::fixed);
    product *itemp=new product[no];
    for(int i=0;i<no;i++)
    {
        (itemp+i)->get_data();
        data.write((char*)(itemp+i),sizeof(itemp+i));
    }
    for(int i=0;i<no;i++)
    {
       total=total+((itemp+i)->cal_amount());
    }
    system("cls");

    cout<<"\n\t\tWelcome to ABC Super Store";
    cout<<"\n-----------------------------------------------------------\n";
    cout<<"\t\t\tInvoice";
    cout<<"\n-----------------------------------------------------------\n";
    time_t now=time(0);                    //current date and time based on current system
    char* dt=ctime(&now);                   //convert now to string form
    cout<<"Date & Time - "<<dt<<"\n";
    cout<<setw(5)<<"Code"<<setw(10)<<"Name"<<setw(12)<<"Price"<<setw(8)<<"Total";
    for(int i=0;i<no;i++)
    {
        (itemp+i)->display();
    }
    cout<<"\n"<<setw(29)<<"Payment Amount-"<<total;
    cout<<"\n\t\tThank You For Shopping.";
    data.close();
    delete []itemp;
    return 0;
}
