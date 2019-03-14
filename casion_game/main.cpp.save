#include <iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

int main()
{
   int no,input_no;
   char ch;
   float ini_amount,bet_amount;
   cout<<"\n\t\t\tWelcome To Royal Casino\n";
   cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
   cout<<"Start the game.\n";
   cout<<"\n(If you win you get twice the betting amount and \nif you lose you lose the betting money. )\n";
   cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
   cout<<"Enter total amount to bet-$ ";
   cin>>ini_amount;
   if(ini_amount>0)
   {
   do
   {
    cout<<"\nEnter amount to bet-$ ";
    cin>>bet_amount;
    if(ini_amount-bet_amount>=0){
    srand(time(NULL));
    no=rand()%10+1;
    cout<<"Enter betting number between 1 to 10 - ";
    cin>>input_no;
    if(input_no==no)
    {
        cout<<"\n$ Congratulations You Won $";
        ini_amount=ini_amount+2*bet_amount;
    }
    else{

        cout<<"\n:( Sorry You Lost :(\nThe number was- "<<no;
        ini_amount=ini_amount-bet_amount;
    }}
    else
        cout<<"\nBet amount exceding.\n";
    cout<<"\nBalance Remaining -  $"<<ini_amount;
    cout<<"\nWant to play another bet(y/n)-";
    cin>>ch;
   }while((ch=='y' || ch=='Y') && ini_amount!=0);
   }
   cout<<"Your balance is -  $"<<ini_amount<<endl;
    return 0;
}
