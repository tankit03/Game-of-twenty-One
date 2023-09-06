/****************************************************************************************
Program: Athree.cpp 

Author: Tanish Hupare

Description: This program is based of the game 21 or blackjack. In the game the player is
supposed to bet against the dealer that he will get 21 or get closer to 21 than the dealer.
The player thats closests to the 21 wins the game and wins the bet. This game has about 4 players.

Input: player money for 1,2,3,4. player bet for 1,2,3,4. player to able to call more random numbers
for player 1,2,3,4.

Output: The code outputs. players points, the running total of points, the amount of money they have 
after each play for player 1,2,3,4.
******************************************************************************************/

#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

    
    
    // this funtion is to introduce the game and its title. then it prompts the user to input the amount of players of 1-4.

     void introduction(){
        int numplayer;
        cout << "Welcome to the game of Twenty One !!" << endl;
        cout << endl;
        cout << "how many players do you want to play with ? type from from (1-4): ";
        }
    
    int main(){
    // srand outputs all the random points to help get close to 21. 
    srand(time(NULL));
    // these are all the inputs for the entire code below.
    
    // these inputs are for being able to play the game again and the number of players the user needs. 

    int playagain;
    int numplayer;
   
    // These input and outputs all the money related infromation for player 1,2,3,4.
    int player1mon;
    int player2mon;
    int player3mon;
    int player4mon;

    // These inputs and outputs the all the players bet for players 1,2,3,4.
    int player1bet;
    int player2bet;
    int player3bet;
    int player4bet;

   // This code is to help save infromation for how the points the user gets after each call of random number.
    int player2total = 0;
    int player3total = 0;
    int player4total = 0;

    // This code is to help save infromation for how the points the dealer gets after each call of random number.

    int dealer1total = 0;
    int dealer2total = 0;
    int dealer3total = 0;
    int dealer4total = 0;

    // this is for the user to call random numbers to get close to 21.
    int callnum = 1;
    int call2num = 1;
    int call3num = 1;
    int call4num = 1;

   //int randnum;
    int randnum2;
    int dealrandnum;
        
  // this is the start of the code after all the variables have been defined.

    introduction();
    cin >> numplayer;

    while(numplayer > 4 || numplayer < 1){
        cout << endl;
        cout << "This is an invalid amount of players, please input a number from 1-4: ";
        cin >> numplayer;
    }

    cout << endl;
    
    //banking system this is where the code gets the input from the user for how much money they want to put into the game before playing the game.

        if( numplayer == 1){  // banking for user 1
                
                cout << "you choose 1 player !!" << endl;
                cout << endl;
                cout << "Player 1 how much money are you starting with? ";
                cin >> player1mon;
                cout << endl;
                
                while (player1mon < 0){
                cout << "Player 1, Please input a valuable amount thats larger than 1: ";
                cin >> player1mon;
                cout << endl;
                }
                
        }if(numplayer == 2){ // banking for user 2
                cout << "you choose 2 player !!" << endl;
                cout << endl;

                cout << "Player 1 how much money are you starting with? ";
                cin >> player1mon;
                cout << endl;

                while(player1mon < 1){
                cout << "Player 1, Please input a valuable amount thats larger than 1: ";
                cin >> player1mon;
                cout << endl;
                }

                cout << "Player 2 how much money are you starting with? ";
                cin >> player2mon;
                cout << endl;

                while (player2mon < 1){
                cout << "Player 2, Please input a valuable amount thats larger than 1: ";
                cin >> player2mon;
                cout << endl;
                }

        }if (numplayer == 3){ // banking for user 3

                 cout << "you choose 3 player !!" << endl;

                cout << "Player 1 how much money are you starting with? ";
                cin >> player1mon;
                cout << endl;
                
                while (player1mon < 1){
                    cout << "Please input a valuable amount thats larger than 1";
                    cout << endl;
                }

                cout << "Player 2 how much money are you starting with? ";
                cin >> player2mon;
                cout << endl;
                
                while (player2mon < 1){
                    cout << "Please input a valuable amount thats larger than 1";
                    cout << endl;
                }
                
                cout << "Player 3 how much money are you starting with? ";
                cin >> player3mon;
                cout << endl;
                
                while (player3mon < 1){
                    cout << "Please input a valuable amount thats larger than 1";
                    cout << endl;
                }

            
        }if (numplayer == 4){ // banking for user 4

            cout << "you choose 4 player !!" << endl;
                
                cout << "Player 1 how much money are you starting with? ";
                cin >> player1mon;
                cout << endl;
                
                while (player1mon < 1){
                    cout << "Please input a valuable amount thats larger than 1";
                    cout << endl;
                }

                cout << "Player 2 how much money are you starting with? ";
                cin >> player2mon;
                cout << endl;
                
                while (player2mon < 1){
                    cout << "Please input a valuable amount thats larger than 1";
                    cout << endl;
                }
                
                cout << "Player 3 how much money are you starting with? ";
                cin >> player3mon;
                cout << endl;
                
                while (player3mon < 1){
                    cout << "Please input a valuable amount thats larger than 1";
                    cout << endl;
                }

                cout << "Player 4 how much money are you starting with? ";
                cin >> player4mon;
                cout << endl;

        }

// this is where the code goes into the the case based on what the user picked form number of players.

           switch(numplayer){

            case 1: // 1 player
            
                do{ //this do while helps the player decide if they want to cash or play again.
                    
                    
                    
                    if(player1mon>0){ // if the player has money less than 1 the game says no money

                        cout << "You have this much in the bank: " << player1mon << endl;
                        cout << endl;


                        cout << "Player 1, how much do you bet you can beat the dealer: "; // the user inputs the bet here
                        cin >> player1bet;
                        cout << endl;

                        while((player1bet > player1mon)||(player1bet < 1)){ // error handling for bets
                            cout << endl;
                            cout << "Player 1, this is not a good amount to bet, bet less or equal than how much you put in the bank & bet than more 1: ";
                            cin >> player1bet;
                            cout << endl;
                            break;
                        }   

                        // reminds the user how much they have and bet.
                        cout << "You have this much in the bank: " << player1mon << endl;
                        cout << "you have this much in the bet: "<< player1bet << endl;
                        cout << endl;

                        // below is where the user starts to play the game of 21 

                        callnum = 1;
                        int player1total = 0;
                        int player1point = 21-player1total;
                        int deal1points = 21-dealer1total;
                        
                        
                        for( int i = 0; i = callnum;){ // this code helps call random number multiple times.
                            int randnum;
                            randnum = rand() % 11 + 1;
                            player1total += randnum;
                            cout << "Player 1, you got a " << randnum << " . Your running total is: " << player1total << endl; // the points they get and gets added up.
                            

                            if(player1total == 21){ // the user wins
                                
                                cout << endl;
                                cout << "You win" << endl;
                                player1mon += player1bet;
                                cout << endl;
                                cout << "Player 1 has $ " << player1mon << " in the bank" << endl;
                                break;
                                
                                
                            }
                            else if( player1total > 21){ // the user busts, loses.
                                
                                cout << endl;
                                cout << "You bust. You lose!" << endl;
                                player1mon -= player1bet;
                                cout << endl;
                                cout << "Player 1 has $ " << player1mon << " in the bank" << endl;

                                if(player1mon < 0){
                                    cout << "You have no money" << endl;
                                    break;
                                }
                                break;
                                

                            }
                            else if(player1total < 21){ // this is whee the user decides if they want to get closer to 21.

                                cout << "Do you want another (0-no or 1-yes) "; // user inputs the call
                                cin >> callnum;

                                while( callnum != 1 && callnum != 0){ // error handling for the call
                                    cout << "this is not the right input, please type 1-yes or 0-no: ";
                                    cin >> callnum;
                                }

                                while(callnum == 0){ // the user lets the dealer play
                                cout << "your total points are: " << player1total << endl;
                                cout << endl;
                                

                                    cout << "----------------------------" << endl;
                                    cout << endl;
                                    cout << "The dealer will play now" << endl;
                                    cout << endl;

                                    cout << "pick from diffuculity from 1-3, 1 being the eastiest and 3 being the hardest: "; // the user can pick the levels of how hard the game can be 
                                    int levels;
                                    cin >> levels;
                                    cout << endl;

                                    if (levels == 1){
                                        for(int i = 0; i < 2; i++){
                                        
                                        dealrandnum = rand() % 15 + 1;
                                        dealer1total += dealrandnum;
                                        cout << "The dealer gets a(n) " << dealrandnum << ",the running total is " << dealer1total << endl; // the random number generates 2 times for the dealer.
                                        
                                        }   
                                    }

                                    if (levels == 2){
                                        for(int i = 0; i < 2; i++){
                                        
                                        dealrandnum = rand() % 12 + 1;
                                        dealer1total += dealrandnum;

                                        cout << "The dealer gets a(n) " << dealrandnum << ",the running total is " << dealer1total << endl; // the random number generates 2 times for the dealer.
                                        
                                        }   
                                    }

                                    if (levels == 3){
                                        for(int i = 0; i < 2; i++){
                                        
                                        dealrandnum = rand() % 2 + 19;
                                        dealer1total += dealrandnum;

                                        cout << "The dealer gets a(n) " << dealrandnum << ",the running total is " << dealer1total << endl; // the random number generates 2 times for the dealer.
                                        
                                        }   
                                    }
                                        // gives the dealer final points.
                                        cout << endl;
                                        cout << "The dealers total points are: " << dealer1total <<endl;
                                        cout << endl;

                                    // dealers rules.

                                    if(dealer1total == 21){
                                        cout << "The dealer wins!! you lost the bet" << endl; // the dealer wins.
                                        player1mon -= player1bet;
                                    }
                                    if(dealer1total > 21){
                                        cout << "The dealer busts over 21, you win the bet" << endl; // the dealer busts, you win
                                        player1mon += player1bet; 
                                    }

                                    if (dealer1total < 21){ // the dealer is under 21 so it code decides who is close to 21 by the if statments below

                                        int player1points = 21-player1total;
                                        int deal1points = 21-dealer1total;
                                        if(deal1points == player1points){
                                            cout << "The dealer has tied! the tie is at: " << dealer1total << endl;
                                            
                                        }
                                        if(deal1points > player1points){
                                            cout << "The dealer was further, You won! you win the bet and has been put into your bank" << endl;
                                            player1mon += player1bet;

                                        }if(deal1points < player1points){
                                            cout << "The dealer was closer, You lost the bet money has been taken from your bank" << endl;
                                            player1mon -= player1bet;
                                        }

                                    }
                                    // this tells the users final money amount they lose or win from the bet
                                    cout << endl;
                                    cout << "Player 1 has $ " << player1mon << " in the bank.";
                                    cout << endl;
                                    break;
                                }
                            }            

                        }
                        // the user can go again with the money won last time and keep on again
                        cout << endl;
                        cout << "Do you want to play again or cash out? 1-yes or 0-cash out: ";
                        cin >> playagain;
                        cout << endl;

                        if(playagain == 0){
                            cout << "player 1 ends with $" << player1mon << endl; // the user ends the game.
                            cout << endl;
                        }

                        while(playagain > 1 || playagain < 0){
                            
                            cout << "please input 1 or 0 to play or leave the game: "; // error handling for play again
                            cin >> playagain;
                            cout << endl;
                            break;
                        }
                    }
                    else if (player1mon<1){
                    cout << "You have no money"<<endl; // if user has no money they get showed this.
                    break;
                    }
            
                }while(playagain == 1);
   
        break;
        case 2: // 1 player


            do{ 

                    if(player1mon>0){ 

                        cout << "------------------------------------------" << endl;
                        cout << endl;
                        cout << "PLayer 1, You have this much in the bank: " << player1mon << endl; 
                        cout << endl; 
                            

                        cout << "Player 1, how much do you bet you can beat the dealer: ";
                        cin >> player1bet;
                        cout << endl;

                        while((player1bet > player1mon)||(player1bet < 1)){ 
                            cout << endl;
                            cout << "Player 1, this is not a good amount to bet, bet less or equal than how much you put in the bank & bet than more 1: ";
                            cin >> player1bet;
                            cout << endl;
                            break;
                        }
                        
                        cout << "You have this much in the bank: " << player1mon << endl;
                        cout << "your bet is: "<< player1bet << endl;
                        cout << endl;


                        
                        
                        callnum = 1;
                        int player1total = 0;
                        int player1point = 21-player1total;
                        int deal1points = 21-dealer1total;
                        
                        

                        
                        for( int i = 0; i = callnum;){ 
                            int randnum;
                            randnum = rand() % 11 + 1;
                            player1total += randnum;
                            cout << "Player 1, you got a " << randnum << " . Your running total is: " << player1total << endl;

                            if(player1total == 21){ 
                                 
                                cout << "You win" << endl;
                                player1mon += player1bet;
                                cout << endl;
                                cout << "Player 1 has $ " << player1mon << " in the bank" << endl;
                                break;
                                
                                
                            }
                            else if( player1total > 21){  
                                
                                cout << "You bust. You lose!" << endl;
                                player1mon -= player1bet;
                                cout << endl;
                                cout << "Player 1 has $ " << player1mon << " in the bank" << endl;
                                break;
                                

                            }
                            else if(player1total < 21){ 

                                cout << "Do you want another (0-no or 1-yes) "; 
                                cin >> callnum;

                                while( callnum != 1 && callnum != 0){ 
                                    cout << "this is not the right input, please type 1-yes or 0-no";
                                    cin >> callnum;
                                }

                                while(callnum == 0){ 
                                cout << "your total points are: " << player1total << endl;
                                

                                    cout << "----------------------------" << endl;
                                    cout << "The dealer will play now" << endl;
                                    cout << endl;

                                    cout << "pick from diffuculity from 1-3, 1 being the eastiest and 3 being the hardest: "; 
                                    int levels;
                                    cin >> levels;
                                    cout << endl;

                                    if (levels == 1){
                                        for(int i = 0; i < 2; i++){
                                        
                                        dealrandnum = rand() % 15 + 1;
                                        dealer1total += dealrandnum;
                                        cout << "The dealer gets a(n) " << dealrandnum << ",the running total is " << dealer1total << endl; 
                                        
                                        }   
                                    }

                                    if (levels == 2){
                                        for(int i = 0; i < 2; i++){
                                        
                                        dealrandnum = rand() % 12 + 1;
                                        dealer1total += dealrandnum;

                                        cout << "The dealer gets a(n) " << dealrandnum << ",the running total is " << dealer1total << endl; 
                                        
                                        }   
                                    }
                                    

                                    if (levels == 3){
                                        for(int i = 0; i < 2; i++){
                                        
                                        dealrandnum = rand() % 2 + 19;
                                        dealer1total += dealrandnum;

                                        cout << "The dealer gets a(n) " << dealrandnum << ",the running total is " << dealer1total << endl; 
                                        
                                        }   
                                    }

                                        cout << endl;
                                        cout << "The dealers total points are: " << dealer1total <<endl;
                                        cout << endl;

                                        

                                    if(dealer1total == 21){
                                        cout << "The dealer wins!! you lost the bet" << endl; 
                                        player1mon -= player1bet;
                                    }
                                    if(dealer1total > 21){
                                        cout << "The dealer busts over 21, you win the bet" << endl; 
                                        player1mon += player1bet; 
                                    }

                                    if (dealer1total < 21){ 

                                        int player1points = 21-player1total;
                                        int deal1points = 21-dealer1total;
                                        if(deal1points == player1points){
                                            cout << "The dealer has tied! the tie is at: " << dealer1total << endl;
                                            
                                        }
                                        if(deal1points > player1points){
                                            cout << "The dealer was further, You won! you win the bet and has been put into your bank" << endl;
                                            player1mon += player1bet;

                                        }if(deal1points < player1points){
                                            cout << "The dealer was closer, You lost the bet money has been taken from your bank" << endl;
                                            player1mon -= player1bet;
                                        }

                                    } 
                                    cout << endl;
                                    cout << "Player 1 has $ " << player1mon << " in the bank" << endl;
                                    cout << endl;
                                    break;
                                }
                            }               
                        }
                    }

                        

                        if(player2mon > 0){ 

                            cout << "------------------------------------------" << endl;
                            cout << endl; 
                            cout << "Player 2, you have this much in the bank: " << player2mon << endl; 
                            cout << endl;

                            cout << "Player 2, how much do you bet you can beat the dealer: ";
                            cin >> player2bet;
                            cout << endl;

                            while((player2bet > player2mon)||(player2bet < 1)){
                                cout << endl;
                                cout << "Player 2, this is not a good amount to bet, bet less or equal than how much you put in the bank & bet than more 1: ";
                                cin >> player2bet;
                                cout << endl;
                                break;
                            }

                            cout << "You have this much in the bank: " << player2mon << endl;
                            cout << "you have this much in the bet: "<< player2bet << endl;
                            cout << endl;


                          
                            
                            call2num = 1;
                            int player2total = 0;
                            int player2point = 21-player2total;
                            int deal2points = 21-dealer2total;
                            
                            

                            
                            for( int i = 0; i = call2num;){
                                int randnum;
                                randnum = rand() % 11 + 1;
                                player2total += randnum;
                                cout << "Player 2, you got a " << randnum << " . Your running total is: " << player2total << endl;

                                if(player2total == 21){
                                    //callnum--; 
                                    cout << "You win" << endl;
                                    player2mon += player2bet;
                                    cout << endl;
                                    cout << "Player 2 has $ " << player2mon << " in the bank" << endl;
                                    break;
                                    
                                    
                                }
                                else if( player2total > 21){
                                    //callnum--;
                                    cout << "You bust. You lose!" << endl;
                                    player2mon -= player2bet;
                                    cout << endl;
                                    cout << "Player 2 has $ " << player2mon << " in the bank" << endl;
                                    break;
                                    

                                }
                                else if(player2total < 21){

                                    cout << "Do you want another (0-no or 1-yes) ";
                                    cin >> call2num;

                                    while( call2num != 1 && call2num != 0){
                                        cout << "this is not the right input, please type 1-yes or 0-no";
                                        cin >> call2num;
                                    }

                                    while(call2num == 0){
                                    cout << "your total points are: " << player2total << endl;
                                    

                                        cout << "----------------------------" << endl;
                                        cout << "The dealer will play now" << endl;
                                        cout << endl;

                                        cout << "pick from diffuculity from 1-3, 1 being the eastiest and 3 being the hardest: ";
                                        int levels;
                                        cin >> levels;
                                        cout << endl;

                                        if (levels == 1){
                                            for(int i = 0; i < 2; i++){
                                            
                                            dealrandnum = rand() % 15 + 1;
                                            dealer2total += dealrandnum;
                                            cout << "The dealer gets a(n) " << dealrandnum << ",the running total is " << dealer2total << endl;
                                            
                                            }   
                                        }

                                        if (levels == 2){
                                            for(int i = 0; i < 2; i++){
                                            
                                            dealrandnum = rand() % 12 + 1;
                                            dealer2total += dealrandnum;

                                            cout << "The dealer gets a(n) " << dealrandnum << ",the running total is " << dealer2total << endl;
                                            
                                            }   
                                        }

                                        if (levels == 3){
                                            for(int i = 0; i < 2; i++){
                                            
                                            dealrandnum = rand() % 2 + 19;
                                            dealer2total += dealrandnum;

                                            cout << "The dealer gets a(n) " << dealrandnum << ",the running total is " << dealer2total << endl;
                                            
                                            }   
                                        }

                                            cout << endl;
                                            cout << "The dealers total points are: " << dealer2total <<endl;
                                            cout << endl;

                                       

                                        if(dealer2total == 21){
                                            cout << "The dealer wins!! you lost the bet" << endl;
                                            player2mon -= player2bet;
                                        }
                                        if(dealer2total > 21){
                                            cout << "The dealer busts over 21, you win the bet" << endl;
                                            player2mon += player2bet; 
                                        }

                                        if (dealer2total < 21){

                                            int player2points = 21-player2total;
                                            int deal2points = 21-dealer2total;
                                            if(deal2points == player2points){
                                                cout << "The dealer has tied! the tie is at: " << dealer2total << endl;
                                                
                                            }
                                            if(deal2points > player2points){
                                                cout << "The dealer was further, You won! you win the bet and has been put into your bank" << endl;
                                                player2mon += player2bet;

                                            }if(deal2points < player2points){
                                                cout << "The dealer was closer, You lost the bet money has been taken from your bank" << endl;
                                                player1mon -= player1bet;
                                            }

                                        }
                                        cout << endl;
                                        cout << "Player 2 has $ " << player2mon << " in the bank" << endl;
                                        
                                        break;
                                    }
                                }            
                            }
                        }
                        cout << endl;
                        cout << "Do you want to play again or cash out? 1-yes or 0-cash out";
                        cin >> playagain;

                        if(playagain == 0){
                            cout << "player 1 ends with $" << player1mon << endl;
                            cout << "player 2 ends with $" << player2mon << endl;
                            cout << endl;
                        } 

                        while(playagain > 1 || playagain < 0){
                            cout << "please input 1 or 0 to play or leave the game: ";
                            cin >> playagain;
                            cout << endl;
                            break;
                        }
                    
                    if (player1mon<1){
                    cout << "You have no money you are escorted out"<<endl;
                    break;
                    }             
       
            }while(playagain == 1);
        
        break;
        case 3: // this is form three players 
                // this is the same code as for player 1 for the game regarding the game for user and the dealer

                do{

                    if(player1mon>0){

                        cout << "------------------------------------------" << endl;
                        cout << endl;
                        cout << "PLayer 1, You have this much in the bank: " << player1mon << endl;
                        cout << endl; 
                            

                        cout << "Player 1, how much do you bet you can beat the dealer: ";
                        cin >> player1bet;
                        cout << endl;

                        while((player1bet > player1mon)||(player1bet < 1)){
                            cout << endl;
                            cout << "Player 1, this is not a good amount to bet, bet less or equal than how much you put in the bank & bet than more 1: ";
                            cin >> player1bet;
                            cout << endl;
                            break;
                        }

                        cout << "You have this much in the bank: " << player1mon << endl;
                        cout << "your bet is: "<< player1bet << endl;
                        cout << endl;


                      
                        
                        callnum = 1;
                        int player1total = 0;
                        int player1point = 21-player1total;
                        int deal1points = 21-dealer1total;
                        
                        

                        
                        for( int i = 0; i = callnum;){
                            int randnum;
                            randnum = rand() % 11 + 1;
                            player1total += randnum;
                            cout << "Player 1, you got a " << randnum << " . Your running total is: " << player1total << endl;

                            if(player1total == 21){
                                
                                cout << "You win" << endl;
                                player1mon += player1bet;
                                cout << endl;
                                cout << "Player 1 has $ " << player1mon << " in the bank" << endl;
                                break;
                                
                                
                            }
                            else if( player1total > 21){
                              
                                cout << "You bust. You lose!" << endl;
                                player1mon -= player1bet;
                                cout << endl;
                                cout << "Player 1 has $ " << player1mon << " in the bank" << endl;
                                break;
                                

                            }
                            else if(player1total < 21){

                                cout << "Do you want another (0-no or 1-yes) ";
                                cin >> callnum;

                                while( callnum != 1 && callnum != 0){
                                    cout << "this is not the right input, please type 1-yes or 0-no";
                                    cin >> callnum;
                                }

                                while(callnum == 0){
                                cout << "your total points are: " << player1total << endl;
                                

                                    cout << "----------------------------" << endl;
                                    cout << "The dealer will play now" << endl;
                                    cout << endl;

                                    cout << "pick from diffuculity from 1-3, 1 being the eastiest and 3 being the hardest: ";
                                    int levels;
                                    cin >> levels;
                                    cout << endl;

                                    if (levels == 1){
                                        for(int i = 0; i < 2; i++){
                                        
                                        dealrandnum = rand() % 15 + 1;
                                        dealer1total += dealrandnum;
                                        cout << "The dealer gets a(n) " << dealrandnum << ",the running total is " << dealer1total << endl;
                                        
                                        }   
                                    }

                                    if (levels == 2){
                                        for(int i = 0; i < 2; i++){
                                        
                                        dealrandnum = rand() % 12 + 1;
                                        dealer1total += dealrandnum;

                                        cout << "The dealer gets a(n) " << dealrandnum << ",the running total is " << dealer1total << endl;
                                        
                                        }   
                                    }

                                    if (levels == 3){
                                        for(int i = 0; i < 2; i++){
                                        
                                        dealrandnum = rand() % 2 + 19;
                                        dealer1total += dealrandnum;

                                        cout << "The dealer gets a(n) " << dealrandnum << ",the running total is " << dealer1total << endl;
                                        
                                        }   
                                    }

                                        cout << endl;
                                        cout << "The dealers total points are: " << dealer1total <<endl;
                                        cout << endl;

                                        

                                    if(dealer1total == 21){
                                        cout << "The dealer wins!! you lost the bet" << endl;
                                        player1mon -= player1bet;
                                    }
                                    if(dealer1total > 21){
                                        cout << "The dealer busts over 21, you win the bet" << endl;
                                        player1mon += player1bet; 
                                    }

                                    if (dealer1total < 21){

                                        int player1points = 21-player1total;
                                        int deal1points = 21-dealer1total;
                                        if(deal1points == player1points){
                                            cout << "The dealer has tied! the tie is at: " << dealer1total << endl;
                                            
                                        }
                                        if(deal1points > player1points){
                                            cout << "The dealer was further, You won! you win the bet and has been put into your bank" << endl;
                                            player1mon += player1bet;

                                        }if(deal1points < player1points){
                                            cout << "The dealer was closer, You lost the bet money has been taken from your bank" << endl;
                                            player1mon -= player1bet;
                                        }

                                    }
                                    cout << endl;
                                    cout << "Player 1 has $ " << player1mon << " in the bank" << endl;
                                    cout << endl;
                                    break;
                                }
                            }               
                        }
                    }
                        if(player2mon > 0){ 

                            cout << "------------------------------------------" << endl;
                            cout << endl; 
                            cout << "Player 2, you have this much in the bank: " << player2mon << endl; 
                            cout << endl;

                            cout << "Player 2, how much do you bet you can beat the dealer: ";
                            cin >> player2bet;
                            cout << endl;

                            while((player2bet > player2mon)||(player2bet < 1)){
                                cout << endl;
                                cout << "Player 2, this is not a good amount to bet, bet less or equal than how much you put in the bank & bet than more 1: ";
                                cin >> player2bet;
                                cout << endl;
                                break;
                            }

                            cout << "You have this much in the bank: " << player2mon << endl;
                            cout << "you have this much in the bet: "<< player2bet << endl;
                            cout << endl;


                            
                            
                            call2num = 1;
                            int player2total = 0;
                            int player2point = 21-player2total;
                            int deal2points = 21-dealer2total;
                            
                            

                            
                            for( int i = 0; i = call2num;){
                                int randnum;
                                randnum = rand() % 11 + 1;
                                player2total += randnum;
                                cout << "Player 2, you got a " << randnum << " . Your running total is: " << player2total << endl;

                                if(player2total == 21){
                                    
                                    cout << "You win" << endl;
                                    player2mon += player2bet;
                                    cout << endl;
                                    cout << "Player 2 has $ " << player2mon << " in the bank" << endl;
                                    break;
                                    
                                    
                                }
                                else if( player2total > 21){
                                    
                                    cout << "You bust. You lose!" << endl;
                                    player2mon -= player2bet;
                                    cout << endl;
                                    cout << "Player 2 has $ " << player2mon << " in the bank" << endl;
                                    break;
                                    

                                }
                                else if(player2total < 21){

                                    cout << "Do you want another (0-no or 1-yes) ";
                                    cin >> call2num;

                                    while( call2num != 1 && call2num != 0){
                                        cout << "this is not the right input, please type 1-yes or 0-no";
                                        cin >> call2num;
                                    }

                                    while(call2num == 0){
                                    cout << "your total points are: " << player2total << endl;
                                    

                                        cout << "----------------------------" << endl;
                                        cout << "The dealer will play now" << endl;
                                        cout << endl;

                                        cout << "pick from diffuculity from 1-3, 1 being the eastiest and 3 being the hardest: ";
                                        int levels;
                                        cin >> levels;
                                        cout << endl;

                                        if (levels == 1){
                                            for(int i = 0; i < 2; i++){
                                            
                                            dealrandnum = rand() % 15 + 1;
                                            dealer2total += dealrandnum;
                                            cout << "The dealer gets a(n) " << dealrandnum << ",the running total is " << dealer2total << endl;
                                            
                                            }   
                                        }

                                        if (levels == 2){
                                            for(int i = 0; i < 2; i++){
                                            
                                            dealrandnum = rand() % 12 + 1;
                                            dealer2total += dealrandnum;

                                            cout << "The dealer gets a(n) " << dealrandnum << ",the running total is " << dealer2total << endl;
                                            
                                            }   
                                        }

                                        if (levels == 3){
                                            for(int i = 0; i < 2; i++){
                                            
                                            dealrandnum = rand() % 2 + 19;
                                            dealer2total += dealrandnum;

                                            cout << "The dealer gets a(n) " << dealrandnum << ",the running total is " << dealer2total << endl;
                                            
                                            }   
                                        }

                                            cout << endl;
                                            cout << "The dealers total points are: " << dealer2total <<endl;
                                            cout << endl;

                                            

                                        if(dealer2total == 21){
                                            cout << "The dealer wins!! you lost the bet" << endl;
                                            player2mon -= player2bet;
                                        }
                                        if(dealer2total > 21){
                                            cout << "The dealer busts over 21, you win the bet" << endl;
                                            player2mon += player2bet; 
                                        }

                                        if (dealer2total < 21){

                                            int player2points = 21-player2total;
                                            int deal2points = 21-dealer2total;
                                            if(deal2points == player2points){
                                                cout << "The dealer has tied! the tie is at: " << dealer2total << endl;
                                                
                                            }
                                            if(deal2points > player2points){
                                                cout << "The dealer was further, You won! you win the bet and has been put into your bank" << endl;
                                                player2mon += player2bet;

                                            }if(deal2points < player2points){
                                                cout << "The dealer was closer, You lost the bet money has been taken from your bank" << endl;
                                                player1mon -= player1bet;
                                            }

                                        }
                                        cout << endl;
                                        cout << "Player 2 has $ " << player2mon << " in the bank" << endl;
                                        
                                        break;
                                    }
                                }            
                            }
                        }

                        if(player3mon > 0){ 

                            cout << "------------------------------------------" << endl;
                            cout << endl; 
                            cout << "Player 3, you have this much in the bank: " << player3mon << endl; 
                            cout << endl;

                            cout << "Player 3, how much do you bet you can beat the dealer: ";
                            cin >> player3bet;
                            cout << endl;

                            while((player3bet > player3mon)||(player3bet < 1)){
                                cout << endl;
                                cout << "Player 3, this is not a good amount to bet, bet less or equal than how much you put in the bank & bet than more 1: ";
                                cin >> player3bet;
                                cout << endl;
                                break;
                            }

                            cout << "You have this much in the bank: " << player3mon << endl;
                            cout << "you have this much in the bet: "<< player3bet << endl;
                            cout << endl;


                    
                            
                            call3num = 1;
                            int player3total = 0;
                            int player3point = 21-player3total;
                            int deal3points = 21-dealer3total;
                            
                            

                            
                            for( int i = 0; i = call3num;){
                                int randnum;
                                randnum = rand() % 11 + 1;
                                player3total += randnum;
                                cout << "Player 3, you got a " << randnum << " . Your running total is: " << player3total << endl;

                                if(player3total == 21){
                                   
                                    cout << "You win" << endl;
                                    player3mon += player3bet;
                                    cout << endl;
                                    cout << "Player 3 has $ " << player3mon << " in the bank" << endl;
                                    break;
                                    
                                    
                                }
                                else if( player3total > 21){
                                    
                                    cout << "You bust. You lose!" << endl;
                                    player3mon -= player3bet;
                                    cout << endl;
                                    cout << "Player 3 has $ " << player3mon << " in the bank" << endl;
                                    break;
                                    

                                }
                                else if(player3total < 21){

                                    cout << "Do you want another (0-no or 1-yes) ";
                                    cin >> call3num;

                                    while( call3num != 1 && call3num != 0){
                                        cout << "this is not the right input, please type 1-yes or 0-no";
                                        cin >> call3num;
                                    }

                                    while(call3num == 0){
                                    cout << "your total points are: " << player3total << endl;
                                    

                                        cout << "----------------------------" << endl;
                                        cout << "The dealer will play now" << endl;
                                        cout << endl;

                                        cout << "pick from diffuculity from 1-3, 1 being the eastiest and 3 being the hardest: ";
                                        int levels;
                                        cin >> levels;
                                        cout << endl;

                                        if (levels == 1){
                                            for(int i = 0; i < 2; i++){
                                            
                                            dealrandnum = rand() % 15 + 1;
                                            dealer3total += dealrandnum;
                                            cout << "The dealer gets a(n) " << dealrandnum << ",the running total is " << dealer3total << endl;
                                            
                                            }   
                                        }

                                        if (levels == 2){
                                            for(int i = 0; i < 2; i++){
                                            
                                            dealrandnum = rand() % 12 + 1;
                                            dealer3total += dealrandnum;

                                            cout << "The dealer gets a(n) " << dealrandnum << ",the running total is " << dealer3total << endl;
                                            
                                            }   
                                        }

                                        if (levels == 3){
                                            for(int i = 0; i < 2; i++){
                                            
                                            dealrandnum = rand() % 2 + 19;
                                            dealer3total += dealrandnum;

                                            cout << "The dealer gets a(n) " << dealrandnum << ",the running total is " << dealer3total << endl;
                                            
                                            }   
                                        }

                                            cout << endl;
                                            cout << "The dealers total points are: " << dealer3total <<endl;
                                            cout << endl;

                                            

                                        if(dealer3total == 21){
                                            cout << "The dealer wins!! you lost the bet" << endl;
                                            player3mon -= player3bet;
                                        }
                                        if(dealer3total > 21){
                                            cout << "The dealer busts over 21, you win the bet" << endl;
                                            player3mon += player3bet; 
                                        }

                                        if (dealer3total < 21){

                                            int player3points = 21-player3total;
                                            int deal3points = 21-dealer3total;
                                            if(deal3points == player3points){
                                                cout << "The dealer has tied! the tie is at: " << dealer3total << endl;
                                                
                                            }
                                            if(deal3points > player3points){
                                                cout << "The dealer was further, You won! you win the bet and has been put into your bank" << endl;
                                                player3mon += player3bet;

                                            }if(deal3points < player3points){
                                                cout << "The dealer was closer, You lost the bet money has been taken from your bank" << endl;
                                                player3mon -= player3bet;
                                            }

                                        }
                                        cout << endl;
                                        cout << "Player 3 has $ " << player3mon << " in the bank" << endl;
                                        
                                        break;
                                    }
                                }            
                            }
                        }
                        cout << endl;
                        cout << "Do you want to play again or cash out? 1-yes or 0-cash out";
                        cin >> playagain;

                        if(playagain == 0){
                            cout << "player 1 ends with $" << player1mon << endl;
                            cout << "player 2 ends with $" << player2mon << endl;
                            cout << "player 3 ends with $" << player3mon << endl;
                            cout << endl;
                        }
                        
                        if((player1mon == 0) && (player2mon == 0) && (player3mon == 0)){
                            cout << "all of the players don't have money" << endl;
                            break;
                            
                        }

                        if(player1mon == 0){
                            cout << "player 1 skipped" << endl;
                        }
                        if(player2mon == 0){
                            cout << "player 2 skipped" << endl;
                        }
                        if(player3mon == 0){
                            cout << "player 3 skipped" <<endl;
                        }


                        while(playagain > 1 || playagain < 0){
                            cout << "please input 1 or 0 to play or leave the game: ";
                            cin >> playagain;
                            cout << endl;
                            break;
                        }
                                 
            }while(playagain == 1);
        
        break;
        case 4: // this is form four players 
                // this is the same code as for player 1 for the game regarding the game for user and the dealer

                do{

                    if(player1mon>0){

                        cout << "------------------------------------------" << endl;
                        cout << endl;
                        cout << "PLayer 1, You have this much in the bank: " << player1mon << endl;
                        cout << endl; 
                            

                        cout << "Player 1, how much do you bet you can beat the dealer: ";
                        cin >> player1bet;
                        cout << endl;

                        while((player1bet > player1mon)||(player1bet < 1)){
                            cout << endl;
                            cout << "Player 1, this is not a good amount to bet, bet less or equal than how much you put in the bank & bet than more 1: ";
                            cin >> player1bet;
                            cout << endl;
                            break;
                        }

                        cout << "You have this much in the bank: " << player1mon << endl;
                        cout << "your bet is: "<< player1bet << endl;
                        cout << endl;


                        
                        
                        callnum = 1;
                        int player1total = 0;
                        int player1point = 21-player1total;
                        int deal1points = 21-dealer1total;
                        
                        

                        
                        for( int i = 0; i = callnum;){
                            int randnum;
                            randnum = rand() % 11 + 1;
                            player1total += randnum;
                            cout << "Player 1, you got a " << randnum << " . Your running total is: " << player1total << endl;

                            if(player1total == 21){
                              
                                cout << "You win" << endl;
                                player1mon += player1bet;
                                cout << endl;
                                cout << "Player 1 has $ " << player1mon << " in the bank" << endl;
                                break;
                                
                                
                            }
                            else if( player1total > 21){
                             
                                cout << "You bust. You lose!" << endl;
                                player1mon -= player1bet;
                                cout << endl;
                                cout << "Player 1 has $ " << player1mon << " in the bank" << endl;
                                break;
                                

                            }
                            else if(player1total < 21){

                                cout << "Do you want another (0-no or 1-yes) ";
                                cin >> callnum;

                                while( callnum != 1 && callnum != 0){
                                    cout << "this is not the right input, please type 1-yes or 0-no";
                                    cin >> callnum;
                                }

                                while(callnum == 0){
                                cout << "your total points are: " << player1total << endl;
                                

                                    cout << "----------------------------" << endl;
                                    cout << "The dealer will play now" << endl;
                                    cout << endl;

                                    cout << "pick from diffuculity from 1-3, 1 being the eastiest and 3 being the hardest: ";
                                    int levels;
                                    cin >> levels;
                                    cout << endl;

                                    if (levels == 1){
                                        for(int i = 0; i < 2; i++){
                                        
                                        dealrandnum = rand() % 15 + 1;
                                        dealer1total += dealrandnum;
                                        cout << "The dealer gets a(n) " << dealrandnum << ",the running total is " << dealer1total << endl;
                                        
                                        }   
                                    }

                                    if (levels == 2){
                                        for(int i = 0; i < 2; i++){
                                        
                                        dealrandnum = rand() % 12 + 1;
                                        dealer1total += dealrandnum;

                                        cout << "The dealer gets a(n) " << dealrandnum << ",the running total is " << dealer1total << endl;
                                        
                                        }   
                                    }

                                    if (levels == 3){
                                        for(int i = 0; i < 2; i++){
                                        
                                        dealrandnum = rand() % 2 + 19;
                                        dealer1total += dealrandnum;

                                        cout << "The dealer gets a(n) " << dealrandnum << ",the running total is " << dealer1total << endl;
                                        
                                        }   
                                    }

                                        cout << endl;
                                        cout << "The dealers total points are: " << dealer1total <<endl;
                                        cout << endl;

                                       

                                    if(dealer1total == 21){
                                        cout << "The dealer wins!! you lost the bet" << endl;
                                        player1mon -= player1bet;
                                    }
                                    if(dealer1total > 21){
                                        cout << "The dealer busts over 21, you win the bet" << endl;
                                        player1mon += player1bet; 
                                    }

                                    if (dealer1total < 21){

                                        int player1points = 21-player1total;
                                        int deal1points = 21-dealer1total;
                                        if(deal1points == player1points){
                                            cout << "The dealer has tied! the tie is at: " << dealer1total << endl;
                                            
                                        }
                                        if(deal1points > player1points){
                                            cout << "The dealer was further, You won! you win the bet and has been put into your bank" << endl;
                                            player1mon += player1bet;

                                        }if(deal1points < player1points){
                                            cout << "The dealer was closer, You lost the bet money has been taken from your bank" << endl;
                                            player1mon -= player1bet;
                                        }

                                    }
                                    cout << endl;
                                    cout << "Player 1 has $ " << player1mon << " in the bank" << endl;
                                    cout << endl;
                                    break;
                                }
                            }               
                        }
                    }
                        if(player2mon > 0){ 

                            cout << "------------------------------------------" << endl;
                            cout << endl; 
                            cout << "Player 2, you have this much in the bank: " << player2mon << endl; 
                            cout << endl;

                            cout << "Player 2, how much do you bet you can beat the dealer: ";
                            cin >> player2bet;
                            cout << endl;

                            while((player2bet > player2mon)||(player2bet < 1)){
                                cout << endl;
                                cout << "Player 2, this is not a good amount to bet, bet less or equal than how much you put in the bank & bet than more 1: ";
                                cin >> player2bet;
                                cout << endl;
                                break;
                            }

                            cout << "You have this much in the bank: " << player2mon << endl;
                            cout << "you have this much in the bet: "<< player2bet << endl;
                            cout << endl;


                       
                            
                            call2num = 1;
                            int player2total = 0;
                            int player2point = 21-player2total;
                            int deal2points = 21-dealer2total;
                            
                            

                            
                            for( int i = 0; i = call2num;){
                                int randnum;
                                randnum = rand() % 11 + 1;
                                player2total += randnum;
                                cout << "Player 2, you got a " << randnum << " . Your running total is: " << player2total << endl;

                                if(player2total == 21){
                                    
                                    cout << "You win" << endl;
                                    player2mon += player2bet;
                                    cout << endl;
                                    cout << "Player 2 has $ " << player2mon << " in the bank" << endl;
                                    break;
                                    
                                    
                                }
                                else if( player2total > 21){
                                 
                                    cout << "You bust. You lose!" << endl;
                                    player2mon -= player2bet;
                                    cout << endl;
                                    cout << "Player 2 has $ " << player2mon << " in the bank" << endl;
                                    break;
                                    

                                }
                                else if(player2total < 21){

                                    cout << "Do you want another (0-no or 1-yes) ";
                                    cin >> call2num;

                                    while( call2num != 1 && call2num != 0){
                                        cout << "this is not the right input, please type 1-yes or 0-no";
                                        cin >> call2num;
                                    }

                                    while(call2num == 0){
                                    cout << "your total points are: " << player2total << endl;
                                    

                                        cout << "----------------------------" << endl;
                                        cout << "The dealer will play now" << endl;
                                        cout << endl;

                                        cout << "pick from diffuculity from 1-3, 1 being the eastiest and 3 being the hardest: ";
                                        int levels;
                                        cin >> levels;
                                        cout << endl;

                                        if (levels == 1){
                                            for(int i = 0; i < 2; i++){
                                            
                                            dealrandnum = rand() % 15 + 1;
                                            dealer2total += dealrandnum;
                                            cout << "The dealer gets a(n) " << dealrandnum << ",the running total is " << dealer2total << endl;
                                            
                                            }   
                                        }

                                        if (levels == 2){
                                            for(int i = 0; i < 2; i++){
                                            
                                            dealrandnum = rand() % 12 + 1;
                                            dealer2total += dealrandnum;

                                            cout << "The dealer gets a(n) " << dealrandnum << ",the running total is " << dealer2total << endl;
                                            
                                            }   
                                        }

                                        if (levels == 3){
                                            for(int i = 0; i < 2; i++){
                                            
                                            dealrandnum = rand() % 2 + 19;
                                            dealer2total += dealrandnum;

                                            cout << "The dealer gets a(n) " << dealrandnum << ",the running total is " << dealer2total << endl;
                                            
                                            }   
                                        }

                                            cout << endl;
                                            cout << "The dealers total points are: " << dealer2total <<endl;
                                            cout << endl;

                                          

                                        if(dealer2total == 21){
                                            cout << "The dealer wins!! you lost the bet" << endl;
                                            player2mon -= player2bet;
                                        }
                                        if(dealer2total > 21){
                                            cout << "The dealer busts over 21, you win the bet" << endl;
                                            player2mon += player2bet; 
                                        }

                                        if (dealer2total < 21){

                                            int player2points = 21-player2total;
                                            int deal2points = 21-dealer2total;
                                            if(deal2points == player2points){
                                                cout << "The dealer has tied! the tie is at: " << dealer2total << endl;
                                                
                                            }
                                            if(deal2points > player2points){
                                                cout << "The dealer was further, You won! you win the bet and has been put into your bank" << endl;
                                                player2mon += player2bet;

                                            }if(deal2points < player2points){
                                                cout << "The dealer was closer, You lost the bet money has been taken from your bank" << endl;
                                                player1mon -= player1bet;
                                            }

                                        }
                                        cout << endl;
                                        cout << "Player 2 has $ " << player2mon << " in the bank" << endl;
                                        
                                        break;
                                    }
                                }            
                            }
                        }

                        if(player3mon > 0){ 

                            cout << "------------------------------------------" << endl;
                            cout << endl; 
                            cout << "Player 3, you have this much in the bank: " << player3mon << endl; 
                            cout << endl;

                            cout << "Player 3, how much do you bet you can beat the dealer: ";
                            cin >> player3bet;
                            cout << endl;

                            while((player3bet > player3mon)||(player3bet < 1)){
                                cout << endl;
                                cout << "Player 3, this is not a good amount to bet, bet less or equal than how much you put in the bank & bet than more 1: ";
                                cin >> player3bet;
                                cout << endl;
                                break;
                            }

                            cout << "You have this much in the bank: " << player3mon << endl;
                            cout << "you have this much in the bet: "<< player3bet << endl;
                            cout << endl;


                           
                            
                            call3num = 1;
                            int player3total = 0;
                            int player3point = 21-player3total;
                            int deal3points = 21-dealer3total;
                            
                            

                            
                            for( int i = 0; i = call3num;){
                                int randnum;
                                randnum = rand() % 11 + 1;
                                player3total += randnum;
                                cout << "Player 3, you got a " << randnum << " . Your running total is: " << player3total << endl;

                                if(player3total == 21){
                                 
                                    cout << "You win" << endl;
                                    player3mon += player3bet;
                                    cout << endl;
                                    cout << "Player 3 has $ " << player3mon << " in the bank" << endl;
                                    break;
                                    
                                    
                                }
                                else if( player3total > 21){
                                 
                                    cout << "You bust. You lose!" << endl;
                                    player3mon -= player3bet;
                                    cout << endl;
                                    cout << "Player 3 has $ " << player3mon << " in the bank" << endl;
                                    break;
                                    

                                }
                                else if(player3total < 21){

                                    cout << "Do you want another (0-no or 1-yes) ";
                                    cin >> call3num;

                                    while( call3num != 1 && call3num != 0){
                                        cout << "this is not the right input, please type 1-yes or 0-no";
                                        cin >> call3num;
                                    }

                                    while(call3num == 0){
                                    cout << "your total points are: " << player3total << endl;
                                    

                                        cout << "----------------------------" << endl;
                                        cout << "The dealer will play now" << endl;
                                        cout << endl;

                                        cout << "pick from diffuculity from 1-3, 1 being the eastiest and 3 being the hardest: ";
                                        int levels;
                                        cin >> levels;
                                        cout << endl;

                                        if (levels == 1){
                                            for(int i = 0; i < 2; i++){
                                            
                                            dealrandnum = rand() % 15 + 1;
                                            dealer3total += dealrandnum;
                                            cout << "The dealer gets a(n) " << dealrandnum << ",the running total is " << dealer3total << endl;
                                            
                                            }   
                                        }

                                        if (levels == 2){
                                            for(int i = 0; i < 2; i++){
                                            
                                            dealrandnum = rand() % 12 + 1;
                                            dealer3total += dealrandnum;

                                            cout << "The dealer gets a(n) " << dealrandnum << ",the running total is " << dealer3total << endl;
                                            
                                            }   
                                        }

                                        if (levels == 3){
                                            for(int i = 0; i < 2; i++){
                                            
                                            dealrandnum = rand() % 2 + 19;
                                            dealer3total += dealrandnum;

                                            cout << "The dealer gets a(n) " << dealrandnum << ",the running total is " << dealer3total << endl;
                                            
                                            }   
                                        }

                                            cout << endl;
                                            cout << "The dealers total points are: " << dealer3total <<endl;
                                            cout << endl;

                                           
                                        if(dealer3total == 21){
                                            cout << "The dealer wins!! you lost the bet" << endl;
                                            player3mon -= player3bet;
                                        }
                                        if(dealer3total > 21){
                                            cout << "The dealer busts over 21, you win the bet" << endl;
                                            player3mon += player3bet; 
                                        }

                                        if (dealer3total < 21){

                                            int player3points = 21-player3total;
                                            int deal3points = 21-dealer3total;
                                            if(deal3points == player3points){
                                                cout << "The dealer has tied! the tie is at: " << dealer3total << endl;
                                                
                                            }
                                            if(deal3points > player3points){
                                                cout << "The dealer was further, You won! you win the bet and has been put into your bank" << endl;
                                                player3mon += player3bet;

                                            }if(deal3points < player3points){
                                                cout << "The dealer was closer, You lost the bet money has been taken from your bank" << endl;
                                                player3mon -= player3bet;
                                            }

                                        }
                                        cout << endl;
                                        cout << "Player 3 has $ " << player3mon << " in the bank" << endl;
                                        
                                        break;
                                    }
                                }            
                            }
                        }

                        if(player4mon > 0){ 

                            cout << "------------------------------------------" << endl;
                            cout << endl; 
                            cout << "Player 4, you have this much in the bank: " << player4mon << endl; 
                            cout << endl;

                            cout << "Player 4, how much do you bet you can beat the dealer: ";
                            cin >> player4bet;
                            cout << endl;

                            while((player4bet > player4mon)||(player4bet < 1)){
                                cout << endl;
                                cout << "Player 4, this is not a good amount to bet, bet less or equal than how much you put in the bank & bet than more 1: ";
                                cin >> player4bet;
                                cout << endl;
                                break;
                            }

                            cout << "You have this much in the bank: " << player4mon << endl;
                            cout << "you have this much in the bet: "<< player4bet << endl;
                            cout << endl;


                            
                            call4num = 1;
                            int player4total = 0;
                            int player4point = 21-player4total;
                            int deal4points = 21-dealer4total;
                            
                            

                            
                            for( int i = 0; i = call4num;){
                                int randnum;
                                randnum = rand() % 11 + 1;
                                player4total += randnum;
                                cout << "Player 4, you got a " << randnum << " . Your running total is: " << player4total << endl;

                                if(player4total == 21){
                                    
                                    cout << "You win" << endl;
                                    player4mon += player4bet;
                                    cout << endl;
                                    cout << "Player 4 has $ " << player4mon << " in the bank" << endl;
                                    break;
                                    
                                    
                                }
                                else if( player4total > 21){
                                    
                                    cout << "You bust. You lose!" << endl;
                                    player4mon -= player4bet;
                                    cout << endl;
                                    cout << "Player 4 has $ " << player4mon << " in the bank" << endl;
                                    break;
                                    

                                }
                                else if(player4total < 21){

                                    cout << "Do you want another (0-no or 1-yes) ";
                                    cin >> call4num;

                                    while( call4num != 1 && call4num != 0){
                                        cout << "this is not the right input, please type 1-yes or 0-no";
                                        cin >> call4num;
                                    }

                                    while(call4num == 0){
                                    cout << "your total points are: " << player4total << endl;
                                    

                                        cout << "----------------------------" << endl;
                                        cout << "The dealer will play now" << endl;
                                        cout << endl;

                                        cout << "pick from diffuculity from 1-3, 1 being the eastiest and 3 being the hardest: ";
                                        int levels;
                                        cin >> levels;
                                        cout << endl;

                                        if (levels == 1){
                                            for(int i = 0; i < 2; i++){
                                            
                                            dealrandnum = rand() % 15 + 1;
                                            dealer4total += dealrandnum;
                                            cout << "The dealer gets a(n) " << dealrandnum << ",the running total is " << dealer4total << endl;
                                            
                                            }   
                                        }

                                        if (levels == 2){
                                            for(int i = 0; i < 2; i++){
                                            
                                            dealrandnum = rand() % 12 + 1;
                                            dealer4total += dealrandnum;

                                            cout << "The dealer gets a(n) " << dealrandnum << ",the running total is " << dealer4total << endl;
                                            
                                            }   
                                        }

                                        if (levels == 3){
                                            for(int i = 0; i < 2; i++){
                                            
                                            dealrandnum = rand() % 2 + 19;
                                            dealer4total += dealrandnum;

                                            cout << "The dealer gets a(n) " << dealrandnum << ",the running total is " << dealer4total << endl;
                                            
                                            }   
                                        }

                                            cout << endl;
                                            cout << "The dealers total points are: " << dealer4total <<endl;
                                            cout << endl;

                                         

                                        if(dealer4total == 21){
                                            cout << "The dealer wins!! you lost the bet" << endl;
                                            player4mon -= player4bet;
                                        }
                                        if(dealer4total > 21){
                                            cout << "The dealer busts over 21, you win the bet" << endl;
                                            player4mon += player4bet; 
                                        }

                                        if (dealer4total < 21){

                                            int player4points = 21-player4total;
                                            int deal4points = 21-dealer4total;
                                            if(deal4points == player4points){
                                                cout << "The dealer has tied! the tie is at: " << dealer4total << endl;
                                                
                                            }
                                            if(deal4points > player4points){
                                                cout << "The dealer was further, You won! you win the bet and has been put into your bank" << endl;
                                                player4mon += player4bet;

                                            }if(deal4points < player4points){
                                                cout << "The dealer was closer, You lost the bet money has been taken from your bank" << endl;
                                                player4mon -= player4bet;
                                            }

                                        }
                                        cout << endl;
                                        cout << "Player 4 has $ " << player4mon << " in the bank" << endl;
                                        
                                        break;
                                    }
                                }            
                            }
                        }
                        
                        cout << endl;
                        cout << "Do you want to play again or cash out? 1-yes or 0-cash out ";
                        cin >> playagain;
                        
                        if(playagain == 0){
                            cout << "player 1 ends with $" << player1mon << endl;
                            cout << "player 2 ends with $" << player2mon << endl;
                            cout << "player 3 ends with $" << player3mon << endl;
                            cout << "player 4 ends with $" << player4mon << endl;
                            cout << endl;
                        }
            
                        
                        if((player1mon == 0) && (player2mon == 0) && (player3mon == 0) && (player4mon == 0)){
                            cout << "all of the players don't have money" << endl;
                            break;
                            
                        }

                        if(player1mon == 0){
                            cout << "player 1 skipped" << endl;
                        }
                        if(player2mon == 0){
                            cout << "player 2 skipped" << endl;
                        }
                        if(player3mon == 0){
                            cout << "player 3 skipped" << endl;
                        }

                        if(player4mon == 0){
                            cout << "player 4 skipped" << endl;
                        }


                        while(playagain > 1 || playagain < 0){
                            cout << "please input 1 or 0 to play or leave the game: ";
                            cin >> playagain;
                            cout << endl;
                            break;
                        }
                                 
            }while(playagain == 1);

        }

    return 0;
    }