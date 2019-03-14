#include <iostream>
#include<ctime>
#include<cstdlib>
#include<cstring>

using namespace std;
int letterfill(char ch,string word,string &unkn);

int main()
{
    char ch,op;
    string word;
    string words[]={ "india",
                    "canada",
                    "austrailia",
                    "china",
                    "nepal",
                    "pakistan",
                    "russia",
                    "bhutan",
                    "bangladesh",
                    "mexico"};
    cout<<"\n\t\t\tWelcome to Hangman";
    cout<<"\n*****************************************************************\n";
    cout<<"\n(Guess the country name in 5 lives and win)\n";
    cout<<"\n*****************************************************************\n";
    cout<<"Start the game.\n";
    do{
    int guess=5;
    srand(time(NULL));
    int n=rand()%10;
    word=words[n];
    cout<<"\nGuess the country\n\n";
    int len= word.length();
    string unknown(len,'*');
    while(guess>0){
       cout<<"\n"<<unknown;
       cout<<"\nEnter your guess - ";
       cin>>ch;
       if(letterfill(ch,word,unknown)==0)
       {
           cout<<"\n:( Sorry, wrong guess :(\nGuesses left - "<<--guess;
       }
       else
       {
           cout<<"\n:) Congratulations, right guess :)\nGuesses left - "<<guess;
       }

       if(unknown==word)
       {
           cout<<"\n:) Congratulations you won :)\n";
           break;
       }
    }
    cout<<"\nThe name was "<<word;
    cout<<"\nWant to take another name?(y/n) - ";
    cin>>op;
    }while(op=='Y' || op=='y');

    return 0;
}
int letterfill(char ch,string word,string &unkn)
{
    int k=0;
    for(int i=0;i<word.length()+1;i++)
    {
        if(word[i]==ch){    unkn[i]=ch; k=1;}
    }

    return(k);
}
