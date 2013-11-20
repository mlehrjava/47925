/* 
 * File:   main.cpp
 * Author: Oscar Martinez 
 * Created on October 10, 2013, 7:37 PM
 * Purpose: Tic-Tac-Toe Project 
 */

//Libraries 
#include <iostream>
using namespace std;

//Global constants -> none 

//Function prototypes -> none 

//Execution begins here
int main(int argc, char** argv) {
    //Declare variables here
    char place1, place2, place3, place4, place5, place6, 
         place7, place8, place9,   //Tic-Tac-Toe squares
         choice,                   //Player's move
         crntply,                  //Current Player
         user1, user2,             //Player one and player two 
         winner,                   //Winner of game
         again;                    //Choice to play again
    

    do{ 
        //Assign numbers to each box
        place1 = '1', place2 = '2', place3 = '3', place4 = '4', place5 = '5', 
        place6 = '6', place7 = '7', place8 = '8', place9 = '9'; 

        //Heading 
        cout << "*****TIC-TAC-TOE*****" <<endl <<endl;

        //Ask the user if they want to be X's or O's 
        cout << "Player 1, do you want to be X or O: ";
        cin >> user1; 
        
        //Displays each player with their corresponding letter (X or O)
        if(user1 == 'X' || user1 == 'x'){ 
            user2 = 'O'; 
            cout << "Player 1 is X's" <<endl
                 << "Player 2 is O's" <<endl; 
        }
        else{ 
            user2 = 'X';
            cout << "Player 1 is O's" <<endl
                 << "Player 2 is X's" <<endl; 
        }
        //Sets user1 to the current player 
        crntply = user1; 

        //Display board
        cout << "     |     |     "  << endl
             << "  " <<place1 <<"  |  " <<place2 <<"  |  " <<place3 <<endl
             << "     |     |     "  << endl
             << "-----------------"  << endl
             << "     |     |     "  << endl
             << "  " <<place4 <<"  |  " <<place5 <<"  |  " <<place6 <<endl
             << "     |     |     "  << endl
             << "-----------------"  << endl
             << "     |     |     "  << endl
             << "  " <<place7 <<"  |  " <<place8 <<"  |  " <<place9 <<endl
             << "     |     |     "  << endl;
        
        //Prompts user for a move and validates 
        //Keeps switching between players and asking for a play while there is no winner 
        do{
            //Checks that the move made by user is one of the choices on the grid 
            do{ 
                cout << "Enter a number: "; 
                cin >> choice; 
            }while(choice < '0' || choice > '9'); 
            //Changes the number on the grid to the current player's letter
            switch(choice){
                case '1':{
                    //Checks to see if the move made by current user is valid
                    //meaning there is no X or O
                    if(place1 == 'X' || place1 == 'O'){ 
                        cout << "Invalid move!!" <<endl; 
                        //If the move is invalid, the current player is changed 
                        //so that the same player can go again 
                        if(crntply == user1){
                            crntply = user2; 
                        }
                        else{
                            crntply = user1; 
                        }
                    }
                    //If the move is valid, the number chosen by player changes 
                    //to X or O
                    else{ 
                        place1 = crntply;
                    }
                    break;
                }
                case '2':{
                    //Checks to see if the move made by current user is valid
                    //meaning there is no X or O
                    if(place2 == 'X' || place2 == 'O'){ 
                        cout << "Invalid move!!" <<endl; 
                        //If the move is invalid, the current player is changed 
                        //so that the same player can go again 
                        if(crntply == user1){
                            crntply = user2; 
                        }
                        else{
                            crntply = user1; 
                        }
                    }
                    else{ 
                        place2 = crntply;
                    }
                    break;
                }
                case '3':{
                    //Checks to see if the move made by current user is valid
                    //meaning there is no X or O
                    if(place3 == 'X' || place3 == 'O'){ 
                        cout << "Invalid move!!" <<endl; 
                        if(crntply == user1){
                            crntply = user2; 
                        }
                        else{
                            crntply = user1; 
                        }
                    }
                    else{ 
                        place3 = crntply;
                    }
                    break; 
                }
                case '4':{
                    //Checks to see if the move made by current user is valid
                    //meaning there is no X or O
                    if(place4 == 'X' || place4 == 'O'){ 
                        cout << "Invalid move!!" <<endl; 
                        //If the move is invalid, the current player is changed 
                        //so that the same player can go again 
                        if(crntply == user1){
                            crntply = user2; 
                        }
                        else{
                            crntply = user1; 
                        }
                    }
                    else{ 
                        place4 = crntply;
                    }
                    break;
                }
                case '5':{
                    //Checks to see if the move made by current user is valid
                    //meaning there is no X or O
                    if(place5 == 'X' || place5 == 'O'){ 
                        cout << "Invalid move!!" <<endl; 
                        //If the move is invalid, the current player is changed 
                        //so that the same player can go again 
                        if(crntply == user1){
                            crntply = user2; 
                        }
                        else{
                            crntply = user1; 
                        }
                    }
                    else{ 
                        place5 = crntply;
                    }
                    break;
                }
                case '6':{
                    //Checks to see if the move made by current user is valid
                    //meaning there is no X or O
                    if(place6 == 'X' || place6 == 'O'){ 
                        cout << "Invalid move!!" <<endl; 
                        //If the move is invalid, the current player is changed 
                        //so that the same player can go again 
                        if(crntply == user1){
                            crntply = user2; 
                        }
                        else{
                            crntply = user1; 
                        }
                    }
                    else{ 
                        place6 = crntply;
                    }
                    break;
                }
                case '7':{
                    //Checks to see if the move made by current user is valid
                    //meaning there is no X or O
                    if(place7 == 'X' || place7 == 'O'){ 
                        cout << "Invalid move!!" <<endl; 
                        //If the move is invalid, the current player is changed 
                        //so that the same player can go again 
                        if(crntply == user1){
                            crntply = user2; 
                        }
                        else{
                            crntply = user1; 
                        }
                    }
                    else{ 
                        place7 = crntply;
                    }
                    break;
                }
                case '8':{
                    //Checks to see if the move made by current user is valid
                    //meaning there is no X or O
                    if(place8 == 'X' || place8 == 'O'){ 
                        cout << "Invalid move!!" <<endl; 
                        //If the move is invalid, the current player is changed 
                        //so that the same player can go again 
                        if(crntply == user1){
                            crntply = user2; 
                        }
                        else{
                            crntply = user1; 
                        }
                    }
                    else{ 
                        place8 = crntply;
                    }
                    break;
                }
                case '9':{
                    //Checks to see if the move made by current user is valid
                    //meaning there is no X or O
                    if(place9 == 'X' || place9 == 'O'){ 
                        cout << "Invalid move!!" <<endl; 
                        //If the move is invalid, the current player is changed 
                        //so that the same player can go again 
                        if(crntply == user1){
                            crntply = user2; 
                        }
                        else{
                            crntply = user1; 
                        }
                    }
                    else{ 
                        place9 = crntply;
                    }
                    break;
                }
            }

            //Display board
            cout << "     |     |     "  << endl
                 << "  " <<place1 <<"  |  " <<place2 <<"  |  " <<place3 <<endl
                 << "     |     |     "  << endl
                 << "-----------------"  << endl
                 << "     |     |     "  << endl
                 << "  " <<place4 <<"  |  " <<place5 <<"  |  " <<place6 <<endl
                 << "     |     |     "  << endl
                 << "-----------------"  << endl
                 << "     |     |     "  << endl
                 << "  " <<place7 <<"  |  " <<place8 <<"  |  " <<place9 <<endl
                 << "     |     |     "  << endl;    

            //Checks to see if the current player won
            //Checks if the rows, columns or diagonals are the same 
            if(place1 == place2 && place2 == place3 || 
               place4 == place5 && place5 == place6 || 
               place7 == place8 && place8 == place9 || 
               place1 == place4 && place4 == place7 || 
               place2 == place5 && place5 == place8 || 
               place3 == place6 && place6 == place9 ||
               place1 == place5 && place5 == place9 || 
               place3 == place5 && place5 == place7){ 
                //If a row, diagonal, or column is the same the player that 
                //just went is the winner 
                winner = crntply; 
                //Displays the winner 
                cout << winner <<"'s Win!!" <<endl;
            }
            //If all the boxes have either an O or X, and no one won, 
            //the game is tied 
            else if( place1 != '1' &&
                     place2 != '2' &&
                     place3 != '3' &&
                     place4 != '4' &&
                     place5 != '5' &&
                     place6 != '6' &&
                     place7 != '7' &&
                     place8 != '8' &&
                     place9 != '9'){
                //Displays tie game message 
                cout << "It's a tie game!!" <<endl;    
                //Sets winner to 1 so that it can exit the loop and stop asking for moves 
                winner = '1'; 
            }
            //There is no winner 
            else{ 
                //Sets winner to 0 so it can keep asking for moves 
                winner = '0';
                //Switches players 
                if(crntply == user1){ 
                    crntply = user2;
                }
                else{ 
                    crntply = user1; 
                }
            }
        }while(winner == '0'); 
        //Prompts the user if they want to play again
        cout << "Do you want to play again? "; 
        cin >> again; 
    }while(again == 'Y' || again == 'y');
    return 0;
}