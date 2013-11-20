/*
 * File:   main.cpp
 * Author: TaeYoun Kim
 *
 * Created on October 14, 2013, 11:08 AM
 * programming tools
 * 1.0.10.14 - 1.3.10.17 //Netbean on Windows
 * 1.4.10.18 - 1.5.10.18 //Qt Creator on Windows
 * 1.5.10.20 - 3.5.10.25 //Xcode on OSX
 * source -
 * http://patorjk.com/software/taag - ASCII code text generator
 * http://cent84.tistory.com/122 - string to int
 * http://www.retrojunkie.com/asciiart/sports/cards.htm - card images
 */

/*
 * PATCH NOTE
 * 1.0.10.14 - visualized title and add setup function
 * 1.1.10.14 - added blank function, started building mod-select functions
 * 1.2.10.16 - Visualized Card Deck
 * 1.3.10.17 - Setting Part done
 * 1.4.10.18 - Shuffling Cards
 * 1.5.10.18 - Display Cards
 * 1.6.10.20 - Improved System
 * 1.7.10.21 - Fixed Card Image Bugs
 * 1.8.10.21 - Minor Bug-fixes
 * 2.0.10.22 - Prototype version complete
 * 2.1.10.22 - Fixed Critical Error > Incorrect Card Amount Calculation
 * 2.2.10.22 - Added Restarting Game
 * 2.3.10.22 - Fixed Critical Bugs - Overdrawing cards
 * 2.4.10.23 - Fixed Critical BUgs - Always Read A as 11
 * 2.5.10.23 - Improved deck cycling system
 * 2.6.10.23 - Added earn/lose money on the status bar
 * 2.7.10.23 - Temporary Disabled 'Load Game' Option
 * 2.8.10.23 - Added Exit Game instead of Load Game
 * 3.0.10.23 - Upgraded to Alpha Version
 * 3.1.10.23 - Added Five Card Charley Rules
 * 3.2.10.23 - Some Minor Bug-Fixes
 * 3.3.10.23 - Fixed Five Card Charley Bugs
 * 3.4.10.23 - Fixed Player cannot End the Game when Game is Over
 * 3.5.10.25 - Fixed minor bugs and delected some outputs for debugging
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <math.h>
#include <ctime>
using namespace std;

//Global Constants
const string VERSION="3.5.10.25.Ap";
const int BWIDTH=65;

//function Prototypes
//int batting(int, int [], int, string, string, string);
bool DealerPhase(int[]);
bool PlayerPhase(string);
void gameresult(int,int &,int &,int,int);
bool nextgame(string, string);
bool gameover(string, string);
void cardcount(int,int [], bool &, bool &, string);
int batting(int, string);
int IsAce(int,int);
int cardcalculator(int, int, int, int, int);
bool readStr4Int(string, int &);
string displaymoney(int);
void spreadcard2(int [], int &, string, string, string, bool, bool,int [], int[],string &);
//void spreadcard(int [], int &, string, string, string, bool,int,int,string &);
void displaycards(int,int,int,int,int,int,int,int,int,int,string &);
int card2int(int);
void num2card(char &, int &, int);
int gamemode();
void gamesetting(int &, int &, bool &, bool &, bool &);
int gs_money();
int gs_cshuffle(int);
void gs_vu(bool m, bool c, bool f, bool h, bool d, int vm, int vc, int vf, int vh, int vd);
int gs_half(int money, int cshuffle, bool fcc);
int gs_fcc(int money, int cshuffle);
int gs_confirm(int, int, bool, bool);
string gsc_money(int);
string gsc_cshuffle(int);
string gsc_bool(int);
void title();
void setup();
void blank(char shape,int width,int height,bool);
int Intselect(string str);
string IntToString(int n);
string Cards(char,int,int,bool);



int main(int argc, char** argv) {
    /*
    int n;char c;string stri;
    for (int i=0; i<52; i++) {
        num2card(c, n, i);
        for (int k=1; k<10; k++) {
            stri=Cards(c, n, k, true);
            cout<<" :"<<stri.length()<<endl;
        }
        cout<<endl;
    }
    */
    //Declare Random Number
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    bool endgame=false,restart=true;
    
    //title
    title();
    //menu
    setup();
    do{
        
        //Declare Variables
        int mod, cshuffle, num,rate=1, gamecount=1, money, dmoney=1000, bat=0, ccount,pcount,dcount;
        bool fcc,half,dlimit,pwin=false,dwin=false;
        int card[80]={0};
        string msg, dstat, pstat, display;
        
        mod=gamemode();
        if(mod==1){gamesetting(money, cshuffle, fcc, half, dlimit);}
        if(mod==2){break;restart=false;}
        int deck=cshuffle;
        if (half==true){rate=2;}
        //Game Start
        do{
            int phase[10]={10,10,10,10,10,10,10,10,10,10};
            int cdnum[10];
            dstat=" [GAME ";dstat+=displaymoney(gamecount);dstat+="] Dealer $";dstat+=displaymoney(dmoney);
            pstat=" Player $";pstat+=displaymoney(money);pstat+=" // Bat $";pstat+=displaymoney(bat);
            //Shuffle
            msg="!! Bat Your Money !! ";
            if(deck>=cshuffle){
                deck=0;
                for (int i=0; i<51; i++) {
                    card[i]=0;
                    for (bool b=false; b==false;) {
                        card[i]=rand()%52;
                        int k=0;
                        bool f=false;
                        do{
                            if(card[k]==card[i]&&k!=i){f=true;}
                            else{if(k==i&&card[i]!=0){b=true;f=true;}}
                            k++;
                        }while (k<=i&&f==false);
                    }
                }
                for (int j=52; j<80; j++) {
                    card[j]=card[j-52];
                }
                //for (int l=0; l<70; l++) {
                //    cout<<"card["<<l<<"] = "<<card[l]<<endl;
                //}
                num=0;
                msg+="!! Card Shuffled !! ";
            }
            //Batting
            //phase[0]=1;phase[1]=2;phase[2]=10;phase[3]=10;phase[4]=10;phase[5]=3;phase[6]=4;phase[7]=10;phase[8]=10;phase[9]=10;
            spreadcard2(card, num, msg, dstat, pstat, true,true,phase,cdnum, display);
            bat=batting(money, display);
            money-=bat;
            
            //Begin
            dstat=" [GAME ";dstat+=displaymoney(gamecount);dstat+="] Dealer $";dstat+=displaymoney(dmoney);
            pstat=" Player $";pstat+=displaymoney(money);pstat+=" // Bat $";pstat+=displaymoney(bat);
            msg="!! Dealer sets cards !!";
            
            //check BLACKJACK
            phase[0]=0;phase[1]=1;phase[5]=2;phase[6]=3;ccount=4;pcount=7;dcount=2;
            spreadcard2(card, num, msg, dstat, pstat, false,true,phase,cdnum, display);
            cardcount(1,cdnum,pwin,dwin,display);
            if(pwin==true){
                if(dwin==true){
                    msg="!! Push - Both dealer and player are BLACK JACK !!";
                    gameresult(2,money,dmoney,bat,rate);
                    spreadcard2(card, num, msg, dstat, pstat, false,false,phase,cdnum, display);
                }else{
                    msg="!! Player Win - BLACK JACK // You earned $";msg+=IntToString(bat*rate);msg+=" !!";
                    gameresult(3,money,dmoney,bat,rate);
                    spreadcard2(card, num, msg, dstat, pstat, false,false,phase,cdnum, display);
                }
            }else if(dwin==true){
                msg="!! Dealer Win - BLACK JACK // You lost $";msg+=IntToString(bat*rate);msg+=" !!";
                gameresult(4,money,dmoney,bat,rate);
                spreadcard2(card, num, msg, dstat, pstat, false,false,phase,cdnum, display);
            }else{
                //Player Phase
                for (bool pt=true; pt==true;) {
                    if(pt==true){pt=PlayerPhase(display);}
                    if(pt==true){
                        phase[pcount]=ccount;pcount++;ccount++;
                        spreadcard2(card, num, msg, dstat, pstat, false,true,phase,cdnum, display);
                        cardcount(2,cdnum,pwin,dwin,display);
                    }
                    if(dwin==true){
                        msg="!! Dealer Win - Player Burst // You lost $";msg+=IntToString(bat);msg+=" !!";
                        gameresult(1,money,dmoney,bat,rate);
                        spreadcard2(card, num, msg, dstat, pstat, false,true,phase,cdnum, display);
                        pt=false;
                    }else if(pcount>=10){
                        pwin=true;
                        msg="!! Player Win - Five Card Chaley // You earned $";msg+=IntToString(bat);msg+=" !!";
                        gameresult(0, money, dmoney, bat,rate);
                        spreadcard2(card, num, msg, dstat, pstat, false,true,phase,cdnum, display);
                        pt=false;
                    }
                }
                //Dealer Phase
                if(pwin==false&&dwin==false){
                    for (bool dt=true; dt==true; ) {
                        spreadcard2(card, num, msg, dstat, pstat, false,false,phase,cdnum, display);
                        if(dt==true){dt=DealerPhase(cdnum);}
                        if(dt==true){
                            phase[dcount]=ccount;dcount++;ccount++;
                            spreadcard2(card, num, msg, dstat, pstat, false,false,phase,cdnum, display);
                            cardcount(3,cdnum,pwin,dwin,display);
                        }
                        if(pwin==true){
                            msg="!! Player Win - Dealer Burst // You earned $";msg+=IntToString(bat);msg+=" !!";
                            gameresult(0,money,dmoney,bat,rate);
                            spreadcard2(card, num, msg, dstat, pstat, false,false,phase,cdnum, display);
                            dt=false;
                        }else if(dcount>=5){
                            pwin=true;
                            msg="!! Player Win - Five Card Chaley // You earned $";msg+=IntToString(bat);msg+=" !!";
                            gameresult(0, money, dmoney, bat,rate);
                            spreadcard2(card, num, msg, dstat, pstat, false,false,phase,cdnum, display);
                            dt=false;
                        }
                    }
                }
                //Result
                if(pwin==false&&dwin==false){
                    cardcount(4,cdnum,pwin,dwin,display);
                    if(pwin==true){
                        if(dwin==true){
                            msg="!! Push - Both dealer and player have same number !!";
                            gameresult(2,money,dmoney,bat,rate);
                            spreadcard2(card, num, msg, dstat, pstat, false,false,phase,cdnum, display);
                        }else{
                            msg="!! Player Win - Higher Number // You earned $";msg+=IntToString(bat);msg+=" !!";
                            gameresult(0,money,dmoney,bat,rate);
                            spreadcard2(card, num, msg, dstat, pstat, false,false,phase,cdnum, display);
                        }
                    }else if(dwin==true){
                        msg="!! Dealer Win - Higher Number // You lost $";msg+=IntToString(bat);msg+=" !!";
                        gameresult(1,money,dmoney,bat,rate);
                        spreadcard2(card, num, msg, dstat, pstat, false,false,phase,cdnum, display);
                    }
                }
            }
            bat=0;
            pwin=false;dwin=false;
            dstat=" [GAME ";dstat+=displaymoney(gamecount);dstat+="] Dealer $";dstat+=displaymoney(dmoney);
            pstat=" Player $";pstat+=displaymoney(money);pstat+=" // Bat $";pstat+=displaymoney(bat);
            if(money<=0){
                msg="You have no money - GAME OVER -";
                spreadcard2(card, num, msg, dstat, pstat, false,false,phase,cdnum, display);
                restart=gameover(msg,display);
                endgame=restart;
            }else if(dmoney<=0){
                msg="Dealer lost all money - YOU WIN -";
                spreadcard2(card, num, msg, dstat, pstat, false,false,phase,cdnum, display);
                restart=gameover(msg,display);
                endgame=restart;
            }else{
                //msg+="(1.Continue 2.Stop)";
                spreadcard2(card, num, msg, dstat, pstat, false,false,phase,cdnum, display);
                endgame=nextgame(msg,display);
            }
            num+=ccount;
            if(num>=55){num-=52;}
            deck++;
            gamecount++;
        }while(endgame==false&&restart==true);
    }while (restart==true);
    return 0;
}

bool DealerPhase(int num[]){
    int i = cardcalculator(num[0], num[1], num[2], num[3], num[4]);
    if(i<17&&i!=0){
        return true;
    }else{
        return false;
    }
}

bool nextgame(string msg, string op){
    string choice;
    cout<<"--Next game?(1.Continue 0.Stop): ";
    for(bool b=false;b==false;){
        cin>>choice;
        if(choice=="0"){return true;}
        if(choice=="1"){return false;}
        cout<<op;
        msg="!!WARNING!! Please type correct key-";
        cout<<msg<<endl;
        cout<<"--Next game?(1.Continue 0.Stop): ";
    }
    return false;
}

bool gameover(string msg, string op){
    string choice;
    cout<<"--PLAY AGAIN?(Y/N): ";
    for(bool b=false;b==false;){
        cin>>choice;
        if(choice=="Y"||choice=="y"){return true;}
        if(choice=="N"||choice=="n"){return false;}
        cout<<op;
        msg="!!WARNING!! Please type correct key-";
        cout<<msg<<endl;
        cout<<"--PLAY AGAIN?(Y/N): ";
    }
    return false;
}

bool PlayerPhase(string op){
    string choice;
    string msg;
    cout<<op;
    msg="** Select Your Action- (1. Hit) (2.Stay)";
    cout<<msg<<endl;
    cout<<"--Action: ";
    for(bool b=false;b==false;){
        cin>>choice;
        if(choice=="1"){return true;}
        if(choice=="2"){return false;}
        cout<<op;
        msg="!!WARNING!! Please type correct key- (1. Hit) (2.Stay)";
        cout<<msg<<endl;
        //spreadcard(card, num, msg, dealer, player, true);
        cout<<"--Action: ";
    }
    return false;
}

//winner: 0-player, 1-dealer, 2-push, 3-BJplayer, 4-BJdealer
void gameresult(int winner, int &pm, int &dm, int bat, int rate){
    if(winner==0){
        pm+=bat*2;
        dm-=bat;
    }else if(winner==1){
        dm+=bat;
    }else if(winner==2){
        pm+=bat;
    }else if(winner==3){
        pm+=bat*(rate+1);
        dm-=bat*rate;
    }else if(winner==4){
        pm+=bat;
        pm-=bat*rate;
        dm+=bat*rate;
    }
}

//BlackJack =1,Player Burst=2, Dealer Burst=3, High Number=4
void cardcount(int n, int num[], bool &player_bj, bool &dealer_bj, string op){
    if(n==1){
        if(cardcalculator(num[0], num[1], num[2], num[3], num[4])==21){dealer_bj=true;}
        if(cardcalculator(num[5], num[6], num[7], num[8], num[9])==21){player_bj=true;}
    }else if(n==2){
        if(cardcalculator(num[5], num[6], num[7], num[8], num[9])==0){dealer_bj=true;}
    }else if(n==3){
        if(cardcalculator(num[0], num[1], num[2], num[3], num[4])==0){player_bj=true;}
    }else if(n==4){
        int d=cardcalculator(num[0], num[1], num[2], num[3], num[4]);
        int p=cardcalculator(num[5], num[6], num[7], num[8], num[9]);
        if(d==p){player_bj=true;dealer_bj=true;}
        else if(d>p){dealer_bj=true;}
        else{player_bj=true;}
    }
}

int cardcalculator(int first, int second, int third, int fourth, int fifth){
    int amount;
    amount=IsAce(first,0)+IsAce(second,0)+IsAce(third,0)+IsAce(fourth,0)+IsAce(fifth,0);
    if(amount>21){
        if(IsAce(first, 1)==1){amount-=10;}
        if(IsAce(second, 1)==1&&amount>21){amount-=10;}
        if(IsAce(third, 1)==1&&amount>21){amount-=10;}
        if(IsAce(fourth, 1)==1&&amount>21){amount-=10;}
        if(IsAce(fifth, 1)==1&&amount>21){amount-=10;}
        if(amount>21) {
            amount=0;
        }
    };
    return amount;
}

int IsAce(int cn, int cv){
    int n;
    n=card2int(cn);
    //if cv=1, change it as 1, otherwise, change it as 11
    if(n==1){
        if(cv==1){
            cn=1;
        }else{
            cn=11;
        }
    }else{
        if(n>10){n=10;}
        cn=n;
    }
    return cn;
}


//int batting(int m, int card[],int num, string msg, string dealer, string player){
int batting(int m, string op){
    string money;
    string msg;
    int n=0;
    //spreadcard(card, num, msg, dealer, player, true,op);
    
    cout<<"--Your Batting?(5~50): $";
    for(bool b=false;b==false;){
        cin>>money;
        if(readStr4Int(money, n)==true){
            return n;
        }
        cout<<op;
        msg="!!WARNING!! You've entered incorrect amount";
        cout<<msg<<endl;
        //spreadcard(card, num, msg, dealer, player, true);
        cout<<"--Your Batting?(5~50): $";
    }
    return 0;
}

bool readStr4Int(string str, int &m){
    string s=str.substr(0,1);
    bool b=false;
    if(s=="1"||s=="2"||s=="3"||s=="4"){
        string s2=str.substr(1,1);
        if(s2=="1"||s2=="2"||s2=="3"||s2=="4"||s2=="5"||s2=="6"||s2=="7"||s2=="8"||s2=="9"||s2=="0"){
            if(str.length()==2){b=true;m=(Intselect(str.substr(0,1))*10)+Intselect(str.substr(1,1));}
        }
    }else if(s=="5"||s=="6"||s=="7"||s=="8"||s=="9"){
        if(str.length()==1){b=true;m=Intselect(str);}
        else{
            if(s=="5"){
                string s3=str.substr(1,1);
                if(s3=="0"){
                    if(str.length()==2){b=true;m=(Intselect(str.substr(0,1))*10)+Intselect(str.substr(1,1));}
                }
            }
        }
    }
    return b;
}

string displaymoney(int money){
    string str;
    if(money<10){str="   ";str+=IntToString(money);}
    else if(money<100){str="  ";str+=IntToString(money);}
    else if(money<1000){str=" ";str+=IntToString(money);}
    else{str=IntToString(money);}
    return str;
}

void spreadcard2(int card[],int &num, string msg, string dealer, string player, bool hide, bool dhide, int p[],int phase[], string &op){
    int i[10];
    op="#################################################################\n";
    op+="##";op+=dealer;op+="  //                                ##\n";
    //blank('#',BWIDTH,1,true);
    //cout<<"##"<<dealer<<"  //                                ##"<<endl;
    cout<<op;
    for (int k=0; k<10; k++) {
        i[k]=card[k+num];
        phase[k]=p[k];
    }
    for (int k=0; k<10; k++) {
        if(phase[k]==10){phase[k]=52;}
        else{phase[k]=i[phase[k]];}
    }
    if (hide==true) {
        displaycards(52, 52, 52, 52, 52, 52, 52,52,52,52,op);
    }else{
        if (dhide==true) {
            displaycards(phase[0],53,phase[2],phase[3],phase[4],phase[5],phase[6],phase[7],phase[8],phase[9],op);
        }else{
            displaycards(phase[0],phase[1],phase[2],phase[3],phase[4],phase[5],phase[6],phase[7],phase[8],phase[9],op);
        }
    }
    cout<<"##"<<player<<"                                   ##"<<endl;
    blank('#',BWIDTH,1,true);
    op+="##";op+=player;op+="                                   ##\n";
    op+="#################################################################\n";
    cout<<msg<<endl;
}

void spreadcard(int card[],int &num, string msg, string dealer, string player, bool hide, int playerturn, int dealerturn, string &op){
    int i[10];
    op="#################################################################\n";
    op+="##";op+=dealer;op+="  //                                ##\n";
    //blank('#',BWIDTH,1,true);
    //cout<<"##"<<dealer<<"  //                                ##"<<endl;
    cout<<op;
    for (int k=0; k<10; k++) {
        i[k]=card[k+num];
    }
    if (hide==true) {
        displaycards(52, 52, 52, 52, 52, 52, 52,52,52,52,op);
    }else{
        if(playerturn==2){
            displaycards(i[0], i[1],52,52,52, i[2], i[3],52,52,52,op);
        }
    }
    cout<<"##"<<player<<"                                   ##"<<endl;
    blank('#',BWIDTH,1,true);
    op+="##";op+=player;op+="                                   ##\n";
    op+="#################################################################\n";
    cout<<msg<<endl;
}

void displaycards(int dfp, int dsp, int dtp, int dnp, int dlp, int fp, int sp, int tp, int np, int lp,string &op){
    string output;
    char cd[10];
    int nb[10];
    
    num2card(cd[0], nb[0], dfp);
    num2card(cd[1], nb[1], dsp);
    num2card(cd[2], nb[2], fp);
    num2card(cd[3], nb[3], sp);
    num2card(cd[4], nb[4], tp);
    num2card(cd[5], nb[5], np);
    num2card(cd[6], nb[6], lp);
    num2card(cd[7], nb[7], dtp);
    num2card(cd[8], nb[8], dnp);
    num2card(cd[9], nb[9], dlp);
    for (int k=1; k<10; k++) {
        int j=0;
        for (bool b=false; b==false||j<10;) {
            output="##";
            output+=Cards(cd[0], nb[0], k,false);
            output+=Cards(cd[1], nb[1], k,false);
            output+=Cards(cd[7], nb[7], k,false);
            output+=Cards(cd[8], nb[8], k,false);
            output+=Cards(cd[9], nb[9], k,false);
            output+=" ##";
            if (output.length()==65) {
                b=true;
            }
            j++;
        }
        op+=output;
        op+="\n";
        cout<<output<<endl;
    }
    output="##\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/";
    output+="\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\##\n";
    op+=output;
    cout<<output;
    for (int i=1; i<10; i++) {
        int j=0;
        for (bool b=false; b==false||j<10;) {
            output="##";
            output+=Cards(cd[2], nb[2], i,false);
            output+=Cards(cd[3], nb[3], i,false);
            output+=Cards(cd[4], nb[4], i,false);
            output+=Cards(cd[5], nb[5], i,false);
            output+=Cards(cd[6], nb[6], i,false);
            output+=" ##";
            if (output.length()==65) {
                b=true;
            }
            j++;
        }
        op+=output;
        op+="\n";
        cout<<output<<endl;
    }
}

int card2int(int i){
    //0~12 - spades, 13~25 - clubs, 26~38 - diamonds, 39~51 - hearts
    int n;
    if (i<13){n=i+1;}
    else if(i<26){n=i-12;}
    else if(i<39){n=i-25;}
    else if(i<52){n=i-38;}
    else {n=0;}
    return n;
}

void num2card(char &c, int &n, int i){
    //0~12 - spades, 13~25 - clubs, 26~38 - diamonds, 39~51 - hearts
    if (i<13) {
        c='s';
        n=i+1;
    }else if(i<26){
        c='c';
        n=i-12;
    }else if(i<39){
        c='d';
        n=i-25;
    }else if(i<52){
        c='h';
        n=i-38;
    }else if(i==52){c='c';n=14;}
    else if(i==53){c='c';n=0;}
}

void gamesetting(int &m, int &c, bool &fcc, bool &half, bool &dlimit){
    for(bool b=false;b==false;){
        m=gs_money();
        c=gs_cshuffle(m);
        /*
        if(gs_fcc(m,c)==1){
            fcc=true;
        }else{
            fcc=false;
        }
        */
        fcc=true;
        if(gs_half(m,c,fcc)==1){
            half=true;
        }else{
            half=false;
        }
        if(gs_confirm(m, c, fcc, half)==1){
            dlimit=true;
            if(m==1){m=50;}
            else if(m==2){m=150;}
            else if(m==3){m=300;}
            else if(m==4){m=1000;}
            if(c==1){c=30;}
            else if(c==2){c=20;}
            else if(c==3){c=10;}
            else if(c==4){c=5;}
            b=true;
        }
    }
}

void gs_vu(bool m, bool c, bool f, bool h, bool d, int vm, int vc, int vf, int vh, int vd){
    cout<<"#################################################################"<<endl;
    cout<<"##       _     _  _ _____      __   ___   _   __  __ ___       ##"<<endl;
    cout<<"##      / |   | \\| | __\\ \\    / /  / __| /_\\ |  \\/  | __|      ##"<<endl;
    cout<<"##      | |_  | .` | _| \\ \\/\\/ /  | (_ |/ _ \\| |\\/| | _|       ##"<<endl;
    cout<<"##      |_(_) |_|\\_|___| \\_/\\_/    \\___/_/ \\_\\_|__|_|___|      ##"<<endl;
    cout<<"##                                                             ##"<<endl;
    cout<<"##                                                             ##"<<endl;
    if(m==false){
        cout<<"##      Starting money:                                        ##"<<endl;
    }else{
        cout<<"##      Starting money: $"<<gsc_money(vm)<<"                                  ##"<<endl;
    }
    if(c==false){
        cout<<"##      Card shuffle:                                          ##"<<endl;
    }else{
        cout<<"##      Card shuffle: shuffling per "<<gsc_cshuffle(vc)<<" games                   ##"<<endl;
    }
    if(f==false){
        cout<<"##      Five Card Chaley: On                                   ##"<<endl;
    }else{
        cout<<"##      Five Card Chaley: On                                   ##"<<endl;
        //cout<<"##      Five Card Chaley: "<<gsc_bool(vf)<<"                                  ##"<<endl;
    }
    if(h==false){
        cout<<"##      2x for BlackJack:                                      ##"<<endl;
    }else{
        cout<<"##      2x for BlackJack: "<<gsc_bool(vh)<<"                                  ##"<<endl;
    }
    if(d==false){
        cout<<"##      Dealer Limit:       16                                 ##"<<endl;
    }else{
        cout<<"##      Dealer Limit:       16                                 ##"<<endl;
    }
    cout<<"##                                                             ##"<<endl;
}

int gs_money(){
    string money;
    gs_vu(false, false, false, false, false, 0, 0, 0, 0, 0);
    cout<<"##      Select your Starting Money                             ##"<<endl;
    cout<<"##      1. $50                                                 ##"<<endl;
    cout<<"##      2. $150                                                ##"<<endl;
    cout<<"##      3. $300                                                ##"<<endl;
    cout<<"##      4. $1000                                               ##"<<endl;
    cout<<"##                                                             ##"<<endl;
    cout<<"#################################################################"<<endl;
    blank(' ',BWIDTH,4,true);
    cout<<"--Select Your Starting Money: ";
    for(bool b=false;b==false;){
        cin>>money;
        if(money=="1"||money=="2"||money=="3"||money=="4"){
            return Intselect(money);
        }
        gs_vu(false, false, false, false, false, 0, 0, 0, 0, 0);
        cout<<"##      Select your Starting Money                             ##"<<endl;
        cout<<"##      1. $50                                                 ##"<<endl;
        cout<<"##      2. $150                                                ##"<<endl;
        cout<<"##      3. $300                                                ##"<<endl;
        cout<<"##      4. $1000                                               ##"<<endl;
        cout<<"##                                                             ##"<<endl;
        cout<<"#################################################################"<<endl;
        blank(' ',BWIDTH,3,true);
        cout<<"!!WARNING!! You've selected wrong selection"<<endl;
        cout<<"--Select Your Starting Money: ";
    }
    return 0;
}

string gsc_money(int money){
    if(money==1)return "50  ";
    if(money==2)return "150 ";
    if(money==3)return "300 ";
    return "1000";
}

int gs_cshuffle(int money){
    string cshuffle;
    gs_vu(true, false, false, false, false, money, 0, 0, 0, 0);
    cout<<"##      Select Shuffle Option                                  ##"<<endl;
    cout<<"##      1. shuffle cards per 30 games                          ##"<<endl;
    cout<<"##      2. shuffle cards per 20 games                          ##"<<endl;
    cout<<"##      3. shuffle cards per 10 games                          ##"<<endl;
    cout<<"##      4. shuffle cards per 5  games                          ##"<<endl;
    cout<<"##                                                             ##"<<endl;
    cout<<"#################################################################"<<endl;
    blank(' ',BWIDTH,4,true);
    cout<<"--Select Shuffling Option: ";
    for(bool b=false;b==false;){
        cin>>cshuffle;
        if(cshuffle=="1"||cshuffle=="2"||cshuffle=="3"||cshuffle=="4"){
            return Intselect(cshuffle);
        }
        gs_vu(true, false, false, false, false, money, 0, 0, 0, 0);
        cout<<"##      Select Shuffle Option                                  ##"<<endl;
        cout<<"##      1. shuffle cards per 30 games                          ##"<<endl;
        cout<<"##      2. shuffle cards per 20 games                          ##"<<endl;
        cout<<"##      3. shuffle cards per 10 games                          ##"<<endl;
        cout<<"##      4. shuffle cards per 5  games                          ##"<<endl;
        cout<<"##                                                             ##"<<endl;
        cout<<"#################################################################"<<endl;
        blank(' ',BWIDTH,3,true);
        cout<<"!!WARNING!! You've selected wrong selection"<<endl;
        cout<<"--Select Shuffling Option: ";
    }
    return 0;
}

string gsc_cshuffle(int csuffle){
    if(csuffle==1)return "30";
    if(csuffle==2)return "20";
    if(csuffle==3)return "10";
    return " 5";
}
int gs_fcc(int money, int cshuffle){
    string fcc;
    gs_vu(true, true, false, false, false, money, cshuffle, 0, 0, 0);
    cout<<"##      Do you want to play with Five Card Charley rule?       ##"<<endl;
    cout<<"##      1. Yes(On)                                             ##"<<endl;
    cout<<"##      2. No (Off)                                            ##"<<endl;
    cout<<"##                                                             ##"<<endl;
    cout<<"##                                                             ##"<<endl;
    cout<<"##                                                             ##"<<endl;
    cout<<"#################################################################"<<endl;
    blank(' ',BWIDTH,4,true);
    cout<<"--Select Your Option: ";
    for(bool b=false;b==false;){
        cin>>fcc;
        if(fcc=="1"||fcc=="2"){
            return Intselect(fcc);
        }
        gs_vu(true, true, false, false, false, money, cshuffle, 0, 0, 0);
        cout<<"##      Do you want to play with Five Card Charley rule?       ##"<<endl;
        cout<<"##      1. Yes(On)                                             ##"<<endl;
        cout<<"##      2. No (Off)                                            ##"<<endl;
        cout<<"##                                                             ##"<<endl;
        cout<<"##                                                             ##"<<endl;
        cout<<"##                                                             ##"<<endl;
        cout<<"#################################################################"<<endl;
        blank(' ',BWIDTH,3,true);
        cout<<"!!WARNING!! You've selected wrong selection"<<endl;
        cout<<"--Select Your Option: ";
    }
    return 0;
}

string gsc_bool(int csuffle){
    if(csuffle==1)return "On ";
    return "Off";
}

int gs_half(int money, int cshuffle, bool fcc){
    string half;
    gs_vu(true, true, true, false, false, money, cshuffle, fcc, 0, 0);
    cout<<"##      Do you want 2x rate when winner has BlackJack?         ##"<<endl;
    cout<<"##      1. Yes(On)                                             ##"<<endl;
    cout<<"##      2. No (Off)                                            ##"<<endl;
    cout<<"##                                                             ##"<<endl;
    cout<<"##                                                             ##"<<endl;
    cout<<"##                                                             ##"<<endl;
    cout<<"#################################################################"<<endl;
    blank(' ',BWIDTH,4,true);
    cout<<"--Select Your Option: ";
    for(bool b=false;b==false;){
        cin>>half;
        if(half=="1"||half=="2"){
            return Intselect(half);
        }
        gs_vu(true, true, true, false, false, money, cshuffle, fcc, 0, 0);
        cout<<"##      Do you want 2x rate when winner has BlackJack?         ##"<<endl;
        cout<<"##      1. Yes(On)                                             ##"<<endl;
        cout<<"##      2. No (Off)                                            ##"<<endl;
        cout<<"##                                                             ##"<<endl;
        cout<<"##                                                             ##"<<endl;
        cout<<"##                                                             ##"<<endl;
        cout<<"#################################################################"<<endl;
        blank(' ',BWIDTH,3,true);
        cout<<"!!WARNING!! You've selected wrong selection"<<endl;
        cout<<"--Select Your Option: ";
    }
    return 0;
}

int gs_confirm(int money, int cshuffle, bool fcc, bool half){
    string con;
    gs_vu(true, true, true, true, false, money, cshuffle, fcc, half, 0);
    cout<<"##      Is it correct?                                         ##"<<endl;
    cout<<"##      1. Yes                                                 ##"<<endl;
    cout<<"##      2. No                                                  ##"<<endl;
    cout<<"##                                                             ##"<<endl;
    cout<<"##                                                             ##"<<endl;
    cout<<"##                                                             ##"<<endl;
    cout<<"#################################################################"<<endl;
    blank(' ',BWIDTH,4,true);
    cout<<"--Is it correct?: ";
    for(bool b=false;b==false;){
        cin>>con;
        if(con=="1"||con=="2"){
            return Intselect(con);
        }
        gs_vu(true, true, true, true, false, money, cshuffle, fcc, half, 0);
        cout<<"##      Is it correct?                                         ##"<<endl;
        cout<<"##      1. Yes                                                 ##"<<endl;
        cout<<"##      2. No                                                  ##"<<endl;
        cout<<"##                                                             ##"<<endl;
        cout<<"##                                                             ##"<<endl;
        cout<<"##                                                             ##"<<endl;
        cout<<"#################################################################"<<endl;
        blank(' ',BWIDTH,3,true);
        cout<<"!!WARNING!! You've selected wrong selection"<<endl;
        cout<<"--Is it correct?: ";
    }
    return 0;
    
}

int gamemode()
{
    string mod;
    cout<<"#################################################################"<<endl;
    cout<<"##       _     _  _ _____      __   ___   _   __  __ ___       ##"<<endl;
    cout<<"##      / |   | \\| | __\\ \\    / /  / __| /_\\ |  \\/  | __|      ##"<<endl;
    cout<<"##      | |_  | .` | _| \\ \\/\\/ /  | (_ |/ _ \\| |\\/| | _|       ##"<<endl;
    cout<<"##      |_(_) |_|\\_|___| \\_/\\_/    \\___/_/ \\_\\_|__|_|___|      ##"<<endl;
    cout<<"##       ___   _____  _____ _____    ___   _   __  __ ___      ##"<<endl;
    cout<<"##      |_  ) | __\\ \\/ /_ _|_   _|  / __| /_\\ |  \\/  | __|     ##"<<endl;
    cout<<"##       / / _| _| >  < | |  | |   | (_ |/ _ \\| |\\/| | _|      ##"<<endl;
    cout<<"##      /___(_)___/_/\\_\\___| |_|    \\___/_/ \\_\\_|  |_|___|     ##"<<endl;
    cout<<"##                                                             ##"<<endl;
    cout<<"#################################################################"<<endl;
    blank(' ',BWIDTH,13,true);
    cout<<"--Which one you want to play?: ";
    for(bool b=false;b==false;){
        cin>>mod;
        if(mod=="1"||mod=="2"){
            return Intselect(mod);
        }
        cout<<"#################################################################"<<endl;
        cout<<"##       _     _  _ _____      __   ___   _   __  __ ___       ##"<<endl;
        cout<<"##      / |   | \\| | __\\ \\    / /  / __| /_\\ |  \\/  | __|      ##"<<endl;
        cout<<"##      | |_  | .` | _| \\ \\/\\/ /  | (_ |/ _ \\| |\\/| | _|       ##"<<endl;
        cout<<"##      |_(_) |_|\\_|___| \\_/\\_/    \\___/_/ \\_\\_|__|_|___|      ##"<<endl;
        cout<<"##       ___   _____  _____ _____    ___   _   __  __ ___      ##"<<endl;
        cout<<"##      |_  ) | __\\ \\/ /_ _|_   _|  / __| /_\\ |  \\/  | __|     ##"<<endl;
        cout<<"##       / / _| _| >  < | |  | |   | (_ |/ _ \\| |\\/| | _|      ##"<<endl;
        cout<<"##      /___(_)___/_/\\_\\___| |_|    \\___/_/ \\_\\_|  |_|___|     ##"<<endl;
        cout<<"##                                                             ##"<<endl;
        cout<<"#################################################################"<<endl;
        blank(' ',BWIDTH,12,true);
        cout<<"!!WARNING!! You've selected wrong selection"<<endl;
        cout<<"--Which one you want to play?: ";
    }
    return 0;
}

/*
int gamemode()
{
    string mod;
    cout<<"#################################################################"<<endl;
    cout<<"##       _     _  _ _____      __   ___   _   __  __ ___       ##"<<endl;
    cout<<"##      / |   | \\| | __\\ \\    / /  / __| /_\\ |  \\/  | __|      ##"<<endl;
    cout<<"##      | |_  | .` | _| \\ \\/\\/ /  | (_ |/ _ \\| |\\/| | _|       ##"<<endl;
    cout<<"##      |_(_) |_|\\_|___| \\_/\\_/    \\___/_/ \\_\\_|__|_|___|      ##"<<endl;
    cout<<"##       ___   _    ___   _   ___     ___   _   __  __ ___     ##"<<endl;
    cout<<"##      |_  ) | |  / _ \\ /_\\ |   \\   / __| /_\\ |  \\/  | __|    ##"<<endl;
    cout<<"##       / / _| |_| (_) / _ \\| |) | | (_ |/ _ \\| |\\/| | _|     ##"<<endl;
    cout<<"##      /___(_)____\\___/_/ \\_\\___/   \\___/_/ \\_\\_|  |_|___|    ##"<<endl;
    cout<<"##                                                             ##"<<endl;
    cout<<"#################################################################"<<endl;
    blank(' ',BWIDTH,13,true);
    cout<<"--Which one you want to play?: ";
    for(bool b=false;b==false;){
        cin>>mod;
        if(mod=="1"||mod=="2"){
            return Intselect(mod);
        }
        cout<<"#################################################################"<<endl;
        cout<<"##       _     _  _ _____      __   ___   _   __  __ ___       ##"<<endl;
        cout<<"##      / |   | \\| | __\\ \\    / /  / __| /_\\ |  \\/  | __|      ##"<<endl;
        cout<<"##      | |_  | .` | _| \\ \\/\\/ /  | (_ |/ _ \\| |\\/| | _|       ##"<<endl;
        cout<<"##      |_(_) |_|\\_|___| \\_/\\_/    \\___/_/ \\_\\_|__|_|___|      ##"<<endl;
        cout<<"##       ___   _    ___   _   ___     ___   _   __  __ ___     ##"<<endl;
        cout<<"##      |_  ) | |  / _ \\ /_\\ |   \\   / __| /_\\ |  \\/  | __|    ##"<<endl;
        cout<<"##       / / _| |_| (_) / _ \\| |) | | (_ |/ _ \\| |\\/| | _|     ##"<<endl;
        cout<<"##      /___(_)____\\___/_/ \\_\\___/   \\___/_/ \\_\\_|  |_|___|    ##"<<endl;
        cout<<"##                                                             ##"<<endl;
        cout<<"#################################################################"<<endl;
        blank(' ',BWIDTH,12,true);
        cout<<"!!WARNING!! You've selected wrong selection"<<endl;
        cout<<"--Which one you want to play?: ";
    }
    return 0;
}
*/

void title()
{
    cout<<"#################################################################"<<endl;
    cout<<"##    ______   _        _______  _______  _                    ##"<<endl;
    cout<<"##   (  ___ \\ ( \\      (  ___  )(  ____ \\| \\    /\\             ##"<<endl;
    cout<<"##   | (   ) )| (      | (   ) || (    \\/|  \\  / /             ##"<<endl;
    cout<<"##   | (__/ / | |      | (___) || |      |  (_/ /              ##"<<endl;
    cout<<"##   |  __ (  | |      |  ___  || |      |   _ (               ##"<<endl;
    cout<<"##   | (  \\ \\ | |      | (   ) || |      |  ( \\ \\              ##"<<endl;
    cout<<"##   | )___) )| (____/\\| )   ( || (____/\\|  /  \\ \\             ##"<<endl;
    cout<<"##   |/ \\___/ (_______/|/     \\|(_______/|_/    \\/             ##"<<endl;
    cout<<"##                       _________ _______  _______  _         ##"<<endl;
    cout<<"##                       \\__    _/(  ___  )(  ____ \\| \\    /\\  ##"<<endl;
    cout<<"##                          )  (  | (   ) || (    \\/|  \\  / /  ##"<<endl;
    cout<<"##                          |  |  | (___) || |      |  (_/ /   ##"<<endl;
    cout<<"##                          |  |  |  ___  || |      |   _ (    ##"<<endl;
    cout<<"##                          |  |  | (   ) || |      |  ( \\ \\   ##"<<endl;
    cout<<"##                       |\\_)  )  | )   ( || (____/\\|  /  \\ \\  ##"<<endl;
    cout<<"##                       (____/   |/     \\|(_______/|_/    \\/  ##"<<endl;
    cout<<"#################################################################"<<endl;
    cout<<"\n\nVERSION "<<VERSION<<endl;
    return;
}


void setup()
{
    //Local variable
    bool su_done=false;
    string ck;
    string ck2;
    //Setup Start
    do{
        cout<<"Before starting game, you have to set your display as right size"<<endl;
        cout<<"It helps you have the best game condition"<<endl;
        cout<<"For more information about setup, please check the manual"<<endl;
        
        for(bool b1=false;b1==false;){
            cout<<"If you are ready, Please enter 'y' to start configuration: ";
            cin>>ck;
            if(ck=="y"||ck=="Y"){
                blank('#',BWIDTH,23,true);
                cout<<"It must excludes any blanks except last two lanes have texts"<<endl;
                for(bool b=false;b==false;){
                    cout<<"Is your configuration done correctly?(y/n): ";
                    cin>>ck2;
                    if(ck2=="y"||ck2=="Y"){
                        cout<<"Setup is done, Thank you for your participation."<<endl;
                        b=true;
                        su_done=true;
                    }else if(ck2=="n"||ck2=="N"){
                        blank('#',BWIDTH,23,true);
                        cout<<"It must excludes any blanks except last two lanes have texts"<<endl;
                    }else{
                        blank('#',BWIDTH,23,true);
                        cout<<"You've typed wrong key."<<endl;
                    }
                }
                b1=true;
            }else{
                cout<<"You've typed wrong key."<<endl;
            }
        }
    }while(su_done==false);
}

void blank(char shape,int width,int height,bool lend)
{
    for(int i=0;i<height;i++){
        for(int k=0;k<width;k++){
            cout<<shape;
        }
        if(lend==true){cout<<endl;}
    }
}

int Intselect(string str)
{
    int i;
    if(str=="1"){
        i=1;
    }else if(str=="2"){
        i=2;
    }else if(str=="3"){
        i=3;
    }else if(str=="4"){
        i=4;
    }else if(str=="5"){
        i=5;
    }else if(str=="6"){
        i=6;
    }else if(str=="7"){
        i=7;
    }else if(str=="8"){
        i=8;
    }else if(str=="9"){
        i=9;
    }else{
        i=0;
    }
    return i;
}

string IntToString(int n)
{
    std::stringstream ss;
    ss << n;
    return ss.str();
}
string Cards(char c, int n, int l,bool display){
    //s - spades, c - clubs, d - diamonds, h - hearts
    //1 - ace, 11 - J, 12 - Q, 13 - K
    //Lines counts as 9
    string str;
    char r;
    if(c=='s'){r='@';}
    else if(c=='c'){r='+';}
    else if(c=='d'){r='O';}
    else if(c=='h'){r='#';}
    switch (l) {
        case 1:
            str="  _________ ";
            break;
        case 2:
            if(n==0){str=" |         |";}
            if(n==1){str=" |A        |";}
            else if(n==2||n==3||n==4||n==5||n==6||n==7){str=" |";str+=IntToString(n);str+="        |";}
            else if(n==8||n==9){str=" |";str+=IntToString(n);str+=" ";str+=r;str+="   ";str+=r;str+="  |";}
            else if(n==10){str=" |10";str+=r;str+="   ";str+=r;str+="  |";}
            else if(n==11){str=" |J /~~|_  |";}
            else if(n==12){str=" |Q |~~~|  |";}
            else if(n==13){str=" |K |/|\\|  |";}
            break;
        case 3:
            if(n==0){str=" |         |";}
            if(n==1){
                if(c=='s'){str=" |@   *    |";}
                else if(c=='c'){str=" |+   *    |";}
                else if(c=='d'){str=" |O  /~\\   |";}
                else if(c=='h'){str=" |# _   _  |";}
            }else if(n==2||n==4||n==5||n==9||n==8){str=" |";str+=r;str+="        |";}
            else if(n==3||n==10){str=" |";str+=r;str+="   ";str+=r;str+="    |";}
            else if(n==6||n==7){str=" |";str+=r;str+=" ";str+=r;str+="   ";str+=r;str+="  |";}
            else if(n==11){
                if(c=='s'){str=" |@ ! -\\   |";}
                else if(c=='c'){str=" |+ | o`,  |";}
                else if(c=='d'){str=" |O ( o\\   |";}
                else if(c=='h'){str=" |# % *`.  |";}
            }else if(n==12){
                if(c=='s'){str=" |@ \\- -/  |";}
                else if(c=='c'){str=" |+ /o,o\\  |";}
                else if(c=='d'){str=" |O |o.o|  |";}
                else if(c=='h'){str=" |# %*,*%  |";}
            }else if(n==13){
                if(c=='s'){str=" |@ \\- -/  |";}
                else if(c=='c'){str=" |+ /o,o\\  |";}
                else if(c=='d'){str=" |O |o.o|  |";}
                else if(c=='h'){str=" |# %*,*%  |";}
            }
            break;
        case 4:
            if(n==0){str=" |         |";}
            if(n==1){
                if(c=='s'){str=" |   / \\   |";}
                else if(c=='c'){str=" |    !    |";}
                else if(c=='d'){str=" |  / ^ \\  |";}
                else if(c=='h'){str=" | / ~V~ \\ |";}
            }else if(n==2||n==7){str=" |    ";str+=r;str+="    |";}
            else if(n==3||n==6){str=" |         |";}
            else if(n==4||n==5||n==8||n==9||n==10){str=" |  ";str+=r;str+="   ";str+=r;str+="  |";}
            else if(n==11){
                if(c=='s'){str=" |  \\ -!   |";}
                else if(c=='c'){str=" |  | -|   |";}
                else if(c=='d'){str=" |  ! \\l   |";}
                else if(c=='h'){str=" |  % <~   |";}
            }else if(n==12){
                if(c=='s'){str=" | o |-|   |";}
                else if(c=='c'){str=" |  \\_-_/  |";}
                else if(c=='d'){str=" |   \\v/   |";}
                else if(c=='h'){str=" |  \\_o_/  |";}
            }else if(n==13){
                if(c=='s'){str=" | ! |-|   |";}
                else if(c=='c'){str=" |  \\_-_/  |";}
                else if(c=='d'){str=" |   \\v/   |";}
                else if(c=='h'){str=" |  \\_o_/  |";}
            }
            break;
        case 5:
            if(n==0){str=" |         |";}
            if(n==1){
                if(c=='s'){str=" |  /_@_\\  |";}
                else if(c=='c'){str=" |  *-+-*  |";}
                else if(c=='d'){str=" | ( <O> ) |";}
                else if(c=='h'){str=" | \\ Bej / |";}
            }else if(n==2||n==4||n==8||n==10){str=" |         |";}
            else if(n==3||n==9||n==5){str=" |    ";str+=r;str+="    |";}
            else if(n==6||n==7){str=" |  ";str+=r;str+="   ";str+=r;str+="  |";}
            else if(n==11){
                if(c=='s'){str=" |  ',\\',  |";}
                else if(c=='c'){str=" | =~)+(_= |";}
                else if(c=='d'){str=" | ^^^Xvvv |";}
                else if(c=='h'){str=" | %% / %% |";}
            }else if(n==12){
                if(c=='s'){str=" |  I % I  |";}
                else if(c=='c'){str=" | _-~+_-~ |";}
                else if(c=='d'){str=" |  XXOXX  |";}
                else if(c=='h'){str=" | -=<*>=- |";}
            }else if(n==13){
                if(c=='s'){str=" |  % I %  |";}
                else if(c=='c'){str=" | ~-_-~-_ |";}
                else if(c=='d'){str=" |  XXXXX  |";}
                else if(c=='h'){str=" | #>-=-<# |";}
            }
            break;
        case 6:
            if(n==0){str=" |         |";}
            if(n==1){
                if(c=='s'){str=" |    !    |";}
                else if(c=='c'){str=" |    |    |";}
                else if(c=='d'){str=" |  \\ v /  |";}
                else if(c=='h'){str=" |  \\ # /  |";}
            }else if(n==2){str=" |    ";str+=r;str+="    |";}
            else if(n==3||n==6||n==7){str=" |         |";}
            else if(n==4||n==5||n==8||n==9||n==10){str=" |  ";str+=r;str+="   ";str+=r;str+="  |";}
            else if(n==11){
                if(c=='s'){str=" |  \\ -!   |";}
                else if(c=='c'){str=" |  | -|   |";}
                else if(c=='d'){str=" |  ! \\l   |";}
                else if(c=='h'){str=" |  % <~   |";}
            }else if(n==12){
                if(c=='s'){str=" |   |-| o |";}
                else if(c=='c'){str=" |  /~-~\\  |";}
                else if(c=='d'){str=" |   /^\\   |";}
                else if(c=='h'){str=" |  /~o~\\  |";}
            }else if(n==13){
                if(c=='s'){str=" |   |-| ! |";}
                else if(c=='c'){str=" |  /~-~\\  |";}
                else if(c=='d'){str=" |   /^\\   |";}
                else if(c=='h'){str=" |  /~o~\\  |";}
            }
            break;
        case 7:
            if(n==0){str=" |         |";}
            if(n==1){
                if(c=='s'){str=" |   ~ ~  @|";}
                else if(c=='c'){str=" |   ~~~  +|";}
                else if(c=='d'){str=" |   \\_/  O|";}
                else if(c=='h'){str=" |   `.'  #|";}
            }else if(n==2||n==4||n==5||n==8||n==9){str=" |        ";str+=r;str+="|";}
            else if(n==3||n==10){str=" |    ";str+=r;str+="   ";str+=r;str+="|";}
            else if(n==6||n==7){str=" |  ";str+=r;str+="   ";str+=r;str+=" ";str+=r;str+="|";}
            else if(n==11){
                if(c=='s'){str=" |   \\- I @|";}
                else if(c=='c'){str=" |  `.o | +|";}
                else if(c=='d'){str=" |   \\o ) O|";}
                else if(c=='h'){str=" |  `,* % #|";}
            }else if(n==12){
                if(c=='s'){str=" |  /- -\\ @|";}
                else if(c=='c'){str=" |  \\o`o/ +|";}
                else if(c=='d'){str=" |  |o'o| O|";}
                else if(c=='h'){str=" |  %*'*% #|";}
            }else if(n==13){
                if(c=='s'){str=" |  /- -\\ @|";}
                else if(c=='c'){str=" |  \\o`o/ +|";}
                else if(c=='d'){str=" |  |o'o| O|";}
                else if(c=='h'){str=" |  %*'*% #|";}
            }
            break;
        case 8:
            if(n==0){str=" |         |";}
            if(n==1){str=" |        V|";}
            else if(n==2){str=" |        Z|";}
            else if(n==3){str=" |        E|";}
            else if(n==4){str=" |        b|";}
            else if(n==5){str=" |        S|";}
            else if(n==6){str=" |        9|";}
            else if(n==7){str=" |        L|";}
            else if(n==8){str=" |  ";str+=r;str+="   ";str+=r;str+=" 8|";}
            else if(n==9){str=" |  ";str+=r;str+="   ";str+=r;str+=" 6|";}
            else if(n==10){str=" |  ";str+=r;str+="   ";str+=r;str+="0l|";}
            else if(n==11){str=" |  ~|__/ P|";}
            else if(n==12){str=" |  |___| Q|";}
            else if(n==13){str=" |  |\\|/| X|";}
            break;
        case 9:
            str="  ~~~~~~~~~ ";
            break;
        default:
            break;
    }
    if (n==14) {str="            ";}
    if (display==true) {cout<<str;}
    return str;
}

/*
string Cards(char c, int n, int l,bool display){
    //s - spades, c - clubs, d - diamonds, h - hearts
    //1 - ace, 11 - J, 12 - Q, 13 - K
    //Lines counts as 9
    string str;
    char r;
    if(c=='s'){r='@';}
    else if(c=='c'){r='+';}
    else if(c=='d'){r='O';}
    else if(c=='h'){r='#';}
    if(l==1||l==9){
        if(l==1){str="  _________ ";}else{str="  ~~~~~~~~~ ";}
    }else{
        if(l==2){
            if(n==1){str=" |A        |";}
            else if(n==2||n==3||n==4||n==5||n==6||n==7){str=" |";str+=IntToString(n);str+="        |";}
            else if(n==8||n==9){str=" |";str+=IntToString(n);str+=" ";str+=r;str+="   ";str+=r;str+="  |";}
            else if(n==10){str=" |10";str+=r;str+="   ";str+=r;str+="  |";}
            else if(n==11){str=" |J /~~|_  |";}
            else if(n==12){str=" |Q |~~~|  |";}
            else if(n==13){str=" |K |/|\\|  |";}
        }else if(l==3){
            if(n==1){
                if(c=='s'){str=" |@   *    |";}
                else if(c=='c'){str=" |+   *    |";}
                else if(c=='d'){str=" |O  /~\\   |";}
                else if(c=='h'){str=" |# _   _  |";}
            }else if(n==2||n==4||n==5||n==9||n==8){str=" |";str+=r;str+="        |";}
            else if(n==3||n==10){str=" |";str+=r;str+="   ";str+=r;str+="    |";}
            else if(n==6||n==7){str=" |";str+=r;str+=" ";str+=r;str+="   ";str+=r;str+="  |";}
            else if(n==11){
                if(c=='s'){str=" |@ ! -\\   |";}
                else if(c=='c'){str=" |+ | o`,  |";}
                else if(c=='d'){str=" |O ( o\\   |";}
                else if(c=='h'){str=" |# % *`.  |";}
            }else if(n==12){
                if(c=='s'){str=" |@ \\- -/  |";}
                else if(c=='c'){str=" |+ /o,o\\  |";}
                else if(c=='d'){str=" |O |o.o|  |";}
                else if(c=='h'){str=" |# %*,*%  |";}
            }else if(n==13){
                if(c=='s'){str=" |@ \\- -/  |";}
                else if(c=='c'){str=" |+ /o,o\\  |";}
                else if(c=='d'){str=" |O |o.o|  |";}
                else if(c=='h'){str=" |# %*,*%  |";}
            }
        }else if(l==4){
            if(n==1){
                if(c=='s'){str=" |   / \\   |";}
                else if(c=='c'){str=" |    !    |";}
                else if(c=='d'){str=" |  / ^ \\  |";}
                else if(c=='h'){str=" | / ~V~ \\ |";}
            }else if(n==2||n==7){str=" |    ";str+=r;str+="    |";}
            else if(n==3||n==6){str=" |         |";}
            else if(n==4||n==5||n==8||n==9||n==10){str=" |  ";str+=r;str+="   ";str+=r;str+="  |";}
            else if(n==11){
                if(c=='s'){str=" |  \\ -!   |";}
                else if(c=='c'){str=" |  | -|   |";}
                else if(c=='d'){str=" |  ! \\l   |";}
                else if(c=='h'){str=" |  % <~   |";}
            }else if(n==12){
                if(c=='s'){str=" | o |-|   |";}
                else if(c=='c'){str=" |  \\_-_/  |";}
                else if(c=='d'){str=" |   \v/   |";}
                else if(c=='h'){str=" |  \\_o_/  |";}
            }else if(n==13){
                if(c=='s'){str=" | ! |-|   |";}
                else if(c=='c'){str=" |  \\_-_/  |";}
                else if(c=='d'){str=" |   \v/   |";}
                else if(c=='h'){str=" |  \\_o_/  |";}
            }
        }else if(l==5){
            if(n==1){
                if(c=='s'){str=" |  /_@_\\  |";}
                else if(c=='c'){str=" |  *-+-*  |";}
                else if(c=='d'){str=" | ( <O> ) |";}
                else if(c=='h'){str=" | \\ Bej / |";}
            }else if(n==2||n==4||n==8||n==10){str=" |         |";}
            else if(n==3||n==9){str=" |    ";str+=r;str+="    |";}
            else if(n==6||n==7){str=" |  ";str+=r;str+="   ";str+=r;str+="  |";}
            else if(n==11){
                if(c=='s'){str=" |  ',\',  |";}
                else if(c=='c'){str=" | =~)+(_= |";}
                else if(c=='d'){str=" | ^^^Xvvv |";}
                else if(c=='h'){str=" | %% / %% |";}
            }else if(n==12){
                if(c=='s'){str=" |  I % I  |";}
                else if(c=='c'){str=" | _-~+_-~ |";}
                else if(c=='d'){str=" |  XXOXX  |";}
                else if(c=='h'){str=" | -=<*>=- |";}
            }else if(n==13){
                if(c=='s'){str=" |  % I %  |";}
                else if(c=='c'){str=" | ~-_-~-_ |";}
                else if(c=='d'){str=" |  XXXXX  |";}
                else if(c=='h'){str=" | #>-=-<# |";}
            }
        }else if(l==6){
            if(n==1){
                if(c=='s'){str=" |    !    |";}
                else if(c=='c'){str=" |    |    |";}
                else if(c=='d'){str=" |  \\ v /  |";}
                else if(c=='h'){str=" |  \\ # /  |";}
            }else if(n==2){str=" |    ";str+=r;str+="    |";}
            else if(n==3||n==6||n==7){str=" |         |";}
            else if(n==4||n==5||n==8||n==9||n==10){str=" |  ";str+=r;str+="   ";str+=r;str+="  |";}
            else if(n==11){
                if(c=='s'){str=" |  \\ -!   |";}
                else if(c=='c'){str=" |  | -|   |";}
                else if(c=='d'){str=" |  ! \\l   |";}
                else if(c=='h'){str=" |  % <~   |";}
            }else if(n==12){
                if(c=='s'){str=" |   |-| o |";}
                else if(c=='c'){str=" |  /~-~\\  |";}
                else if(c=='d'){str=" |   /^\\   |";}
                else if(c=='h'){str=" |  /~o~\\  |";}
            }else if(n==13){
                if(c=='s'){str=" |   |-| ! |";}
                else if(c=='c'){str=" |  /~-~\\  |";}
                else if(c=='d'){str=" |   /^\\   |";}
                else if(c=='h'){str=" |  /~o~\\  |";}
            }
        }else if(l==7){
            if(n==1){
                if(c=='s'){str=" |   ~ ~  @|";}
                else if(c=='c'){str=" |   ~~~  +|";}
                else if(c=='d'){str=" |   \\_/  O|";}
                else if(c=='h'){str=" |   `.'  #|";}
            }else if(n==2||n==4||n==5||n==8||n==9){str=" |        ";str+=r;str+="|";}
            else if(n==3||n==10){str=" |    ";str+=r;str+="   ";str+=r;str+="|";}
            else if(n==6||n==7){str=" |  ";str+=r;str+="   ";str+=r;str+=" ";str+=r;str+="|";}
            else if(n==11){
                if(c=='s'){str=" |   \\- I @|";}
                else if(c=='c'){str=" |  `.o | +|";}
                else if(c=='d'){str=" |   \\o ) O|";}
                else if(c=='h'){str=" |  `,* % #|";}
            }else if(n==12){
                if(c=='s'){str=" |  /- -\\ @|";}
                else if(c=='c'){str=" |  \\o`o/ +|";}
                else if(c=='d'){str=" |  |o'o| O|";}
                else if(c=='h'){str=" |  %*'*% #|";}
            }else if(n==13){
                if(c=='s'){str=" |  /- -\\ @|";}
                else if(c=='c'){str=" |  \\o`o/ +|";}
                else if(c=='d'){str=" |  |o'o| O|";}
                else if(c=='h'){str=" |  %*'*% #|";}
            }
        }else if(l==8){
            if(n==1){str=" |        V|";}
            else if(n==2){str=" |        Z|";}
            else if(n==3){str=" |        E|";}
            else if(n==4){str=" |        b|";}
            else if(n==5){str=" |        S|";}
            else if(n==6){str=" |        9|";}
            else if(n==7){str=" |        L|";}
            else if(n==8){str=" |  ";str+=r;str+="   ";str+=r;str+=" 8|";}
            else if(n==9){str=" |  ";str+=r;str+="   ";str+=r;str+=" 6|";}
            else if(n==10){str=" |  ";str+=r;str+="   ";str+=r;str+="0l|";}
            else if(n==11){str=" |  ~|__/ P|";}
            else if(n==12){str=" |  |___| Q|";}
            else if(n==13){str=" |  |\\|/| X|";}
        }
    }
    if (display==true) {cout<<str;}
    return str;
}
*/
/*
  _________
 |A        |
 |+   *    |
 |    !    |
 |  *-+-*  |
 |    |    |
 |   ~~~  +|
 |        V|
  ~~~~~~~~~
 
 _________
 |K |/|\|  |
 |+ /o,o\  |
 |  \_-_/  |
 | ~-_-~-_ |
 |  /~-~\  |
 |  \o`o/ +|
 |  |\|/| X|
 ~~~~~~~~~
 
 _________
 |Q |~~~|  |
 |+ /o,o\  ||+ /o,o\  |
 |  \_-_/  |
 | _-~+_-~ |
 |  /~-~\  |
 |  \o`o/ +|
 |  |___| Q|
 ~~~~~~~~~
 
 _________
 |J /~~|_  |
 |+ | o`,  | |+ /o,o\  ||+ /o,o\  |
 |  | -|   |
 | =~)+(_= |
 |   |- |  |
 |  `.o | +|
 |  ~|__/ P|
 ~~~~~~~~~
 
 
 _________
 |10+   +  |
 |+   +    |
 |  +   +  |
 |         |
 |  +   +  |
 |    +   +|
 |  +   +0l|
 ~~~~~~~~~
 
 
 _________
 |9 +   +  |
 |+        |
 |  +   +  |
 |    +    |
 |  +   +  |
 |        +|
 |  +   + 6|
 ~~~~~~~~~
 
 
 _________
 |8 +   +  |
 |+        |
 |  +   +  |
 |         |
 |  +   +  |
 |        +|
 |  +   + 8|
 ~~~~~~~~~
 
 
 _________
 |7        |
 |+ +   +  |
 |    +    |
 |  +   +  |
 |         |
 |  +   + +|
 |        L|
 ~~~~~~~~~
 
 _________
 |6        |
 |+ +   +  |
 |         |
 |  +   +  |
 |         |
 |  +   + +|
 |        9|
 ~~~~~~~~~
 
 _________
 |5        |
 |+        |
 |  +   +  |
 |    +    |
 |  +   +  |
 |        +|
 |        S|
 ~~~~~~~~~
 
 _________
 |4        |
 |+        |
 |  +   +  |
 |         |
 |  +   +  |
 |        +|
 |        b|
 ~~~~~~~~~
 
 _________
 |3        |
 |+   +    |
 |         |
 |    +    |
 |         |
 |    +   +|
 |        E|
 ~~~~~~~~~
 
 _________
 |2        |
 |+        |
 |    +    |
 |         |
 |    +    |
 |        +|
 |        Z|
 ~~~~~~~~~
 
 _________
 |A        |
 |O  /~\   |
 |  / ^ \  |
 | ( <O> ) |
 |  \ v /  |
 |   \_/  O|
 |        V|
 ~~~~~~~~~
 
 _________
 |K |/|\|  |
 |O |o.o|  |
 |   \v/   |
 |  XXXXX  |
 |   /^\   |
 |  |o'o| O|
 |  |\|/| X|
 ~~~~~~~~~
 
 _________
 |Q |~~~|  | |K |/|\|  |
 |O |o.o|  |
 |   \v/   |
 |  XXOXX  |
 |   /^\   |
 |  |o'o| O|
 |  |___| Q|
 ~~~~~~~~~
 
 _________
 |J /~~|_  | |Q |~~~|  | |K |/|\|  |
 |O ( o\   |
 |  ! \l   |
 | ^^^Xvvv |
 |   l\ I  |
 |   \o ) O|
 |  ~|__/ P|
 ~~~~~~~~~
 
 
 _________
 |A        |
 |# _   _  |
 | / ~V~ \ |
 | \ Bej / |
 |  \ # /  |
 |   `.'  #|
 |        V|
 ~~~~~~~~~
 
 _________
 |K |/|\|  |
 |# %*,*%  |
 |  \_o_/  |
 | #>-=-<# |
 |  /~o~\  |
 |  %*'*% #|
 |  |\|/| X|
 ~~~~~~~~~
 
 _________
 |Q |~~~|  | |K |/|\|  |
 |# %*,*%  |
 |  \_o_/  |
 | -=<*>=- |
 |  /~o~\  |
 |  %*'*% #|
 |  |___| Q|
 ~~~~~~~~~
 
 _________
 |J /~~|_  | |Q |~~~|  | |K |/|\|  |
 |# % *`.  |
 |  % <~   |
 | %% / %% |
 |   _> %  |
 |  `,* % #|
 |  ~|__/ P|
 ~~~~~~~~~
 
 _________
 |A        |
 |@   *    |
 |   / \   |
 |  /_@_\  |
 |    !    |
 |   ~ ~  @|
 |        V|
 ~~~~~~~~~
 
 _________
 |K |/|\|  |
 |@ \- -/  |
 | ! |-|   |
 |  % I %  |
 |   |-| ! |
 |  /- -\ @|
 |  |\|/| X|
 ~~~~~~~~~
 
 _________
 |Q |~~~|  |
 |@ \- -/  |
 | o |-|   |
 |  I % I  |
 |   |-| o |
 |  /- -\ @|
 |  |___| Q|
 ~~~~~~~~~
 
 _________
 |J /~~|_  |
 |@ ! -\   |
 |  \ -!   |
 |  ',\',  |
 |   I- \  |
 |   \- I @|
 |  ~|__/ P|
 ~~~~~~~~~
 
 

*/

