/* Turn based battle system */

#include <iostream> 
#include <stdlib.h> 
#include <stdio.h> 
int hp = 20, mp = 20, ehp = 35, move;

void lose (void) 
{ 
	std::cout << "You lose." << std::endl; 
	hp = 20; 
	mp = 20; 
	ehp = 20; 
	} 

void win (void) 
{ 
	std::cout << "You win." << std::endl; 
	hp = 20; 
	mp = 20; 
	ehp = 20;
}


int main() 
{   
label:
std::cout << "ehp: " << ehp << std::endl << "hp: " << hp << std::endl << "mp: " << mp << std::endl << "(1) Attack" << std::endl << "(2) Magic Missle" << std::endl << "(3) Summon" << std::endl; 
	std::cin >> move;
	std::cout << "Status:" << std::endl;

	if (move == 1) 
	{
		std::cout << "You sliced the enemy with your sword." << std::endl; 
		ehp -= 1;  
		if (ehp <= 0) 
{ 
	win();  
	return 0;
} 

if (hp <= 0) 
{ 
	lose();  
	return 0;
}
	std::cout << "The enemy cast a Magic Missle." << std::endl << std::endl; 
hp -= 2; 
	} 

	if (move == 2) 
	{ 
	std::cout << "You cast a devistating Magic Missle." << std::endl; 
		ehp -= 2; 
		mp -= 1; 
		if (ehp <= 0) 
{ 
	win();  
	return 0;
} 

if (hp <= 0) 
{ 
	lose();  
	return 0;
}
	std::cout << "The enemy used his sword." << std::endl << std::endl; 
hp -= 1; 
	}   

	if (move == 3) 
	{ 
	std::cout << "You summoned Ultima!" << std::endl; 
		ehp -= 10; 
		mp -= 15;  
		hp -= 1;
		if (ehp <= 0) 
{ 
	win();  
	return 0;
} 

if (hp <= 0) 
{ 
	lose();  
	return 0;
}
	std::cout << "The enemy used his sword." << std::endl << std::endl; 
hp -= 1; 
	}  
	
	goto label;
}