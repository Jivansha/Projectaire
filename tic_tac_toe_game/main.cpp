#include <iostream>
#include<stdlib.h>

void board();
int test();

char square[9]={'1','2','3','4','5','6','7','8','9'};
using namespace std;

int main()
{
    char mark;
    int player=1,choice,win;
    do{
    board();
    cout<<"\nEnter square number - ";
    cin>>choice;
    if(choice>9 || choice<1){
        continue;
    }
    player=(player%2)?1:2;
    if(player==1){ mark='o'; }
    else {mark='x';}
    if(square[choice-1]!='x' && square[choice-1]!='o'){
    square[choice-1]=mark;}
    else
    {
        player--;
    }
    win=test();
    player++;
    }while(win==-1);
    player--;
    if(win==0)
        cout<<"\n:| Game Draw :|";
    else
        cout<<"\n:) Congratulations Player "<<player<<" win :)";

    return 0;
}
/* To print board */
void board()
{
    system("cls");
    cout<<"\n\t\t\tWELCOME TO TIC-TAC-TOE\n";
    cout<<"\n********************************************************************\n\n";
    cout<<"Player-1 (o) Player-2 (x)\n";
    cout<<"    |    |    "<<endl;
    cout<<" "<<square[0]<<"  | "<<square[1]<<"  | "<<square[2]<<endl;
    cout<<"____|____|____"<<endl;
    cout<<"    |    |    "<<endl;
    cout<<" "<<square[3]<<"  | "<<square[4]<<"  | "<<square[5]<<endl;
    cout<<"____|____|____"<<endl;
    cout<<"    |    |    "<<endl;
    cout<<" "<<square[6]<<"  | "<<square[7]<<"  | "<<square[8]<<endl;
    cout<<"    |    |    "<<endl;
}
//to test if player won(1), game draw(0) or game is in progress(-1)
int test()
{
    if((square[0]==square[1]) && (square[1]==square[2])) return(1);
    else if((square[3]==square[4]) && (square[4]==square[5])) return(1);
    else if((square[6]==square[7]) && (square[7]==square[8])) return(1);
    else if((square[0]==square[3]) && (square[3]==square[6])) return(1);
    else if((square[1]==square[4]) && (square[4]==square[7])) return(1);
    else if((square[2]==square[5]) && (square[5]==square[8])) return(1);
    else if((square[0]==square[4]) && (square[4]==square[8])) return(1);
    else if((square[2]==square[4]) && (square[4]==square[6])) return(1);
    else if(square[0]!='1' && square[1]!='2' && square[2]!='3' && square[3]!='4' && square[4]!='5' && square[5]!='6' && square[6]!='7' && square[7]!='8' && square[8]!='9')
    return(0);
    else return(-1);
}

