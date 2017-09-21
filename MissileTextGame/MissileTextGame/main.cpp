/// <summary>
/// @Author Martin Farrell
/// Date: 29-09-2017
/// No. of hrs: 1
///---------------------------------------------------
/// Missile text game
///---------------------------------------------------
/// No known bugs
#include<iostream>
#include<stdlib.h>
#include<time.h>
#include"missile.h"

int main()
{
	srand((unsigned)time(NULL));//used to generate random numbers

	//Declare variables
	enum WarHead{EXPLOSIVE, NUCLEAR};//enum for payload
	int ammoType = 0;//used for selection of warhead
	WarHead payload;//used for selection of warhead
	int randNum = rand() % 100;//generates a random number between 0 and 99 using the time
	int launchCode = 0;//use to check for correct launch code
	int userCoord = 0;//used to store users selected co-ordinates
	int hit = rand() % 2 + 1;//used to see if missile hits
	bool armed = false;

	//opening text, prompt user for ammo type
	std::cout << "Good evening Mr.President. A Korean ship has been picked up on our radar" << std::endl
		<< "Would you like to use an explosive round or nuke them?" << std::endl;
	std::system("pause");
	std::system("cls");//clear screen

	while (ammoType < 1 || ammoType > 2)//continues to take input until a correct number is specified
	{
		std::cout << "Enter 1 for an explosive round or 2 for a nuke";
		std::cin >> ammoType;
	}

	if (ammoType == 1)
	{
		payload = EXPLOSIVE;//sets to explosive
		std::cout << "You have selected explosive" << std::endl;
	}
	else
	{
		payload = NUCLEAR;//sets to nuclear
		std::cout << "You have selected nuclear" << std::endl;
	}

	std::system("pause");
	std::system("cls");

	std::cout << "The enemy ship was last spotted between sector " << randNum << " and sector " << randNum + 10 << " sir." << std::endl
		<< "Your launch code is 2017, please memorise it and then burn this piece of paper" << std::endl << "Where would you like to send the warhead, sir?"
		<< std::endl;
	std::cin >> userCoord;//stores users co-ords
	while (userCoord <randNum || userCoord > randNum + 10)//if it's outside the range ask again
	{
		std::cout<<"That's outside the sector the ship was spotted sir, please try again." << std::endl;
		std::cin >> userCoord;
	}

	std::system("pause");
	std::system("cls");

	while(launchCode != 2017)//if launch code incorrect
	{
		std::cout << "Please enter launch code to arm missiles: ";
		std::cin >> launchCode;
		armed = true;
	}

	std::cout << "Missile armed and prepared for launch" <<std::endl;

	std::system("pause");
	std::system("cls");

	//countdown
	std::cout << "T-minus 3 seconds to launch." << std::endl << "Three." << std::endl << "Two." << std::endl << "One."
		<< std::endl << "Thunderbirds are go." << std::endl;

	std::system("pause");
	std::system("cls");

	if (armed == true && hit == 1 || payload == NUCLEAR)//win the game
	{
		std::cout << "We have a hit, the ship is destroyed" << std::endl << "Well done Mr.President.";
	}
	else//game over
	{
		std::cout << "We missed our target, they got away sir..it's over...god save us all" << std::endl;
		std::cout << "I guess we should disarm our warhead, even though world war 3 is on the horizon. " << std::endl;
		std::system("pause");
		std::system("cls");
		std::cout << "GAME OVER: You failed to prevent world war 3, guess you were just a meme president " <<std::endl;
		armed = false;
	}

	std::system("pause");
}