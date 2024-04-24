/* Turn based battle system */

#include <iostream> 
#include <stdlib.h> 
#include <stdio.h> 
#include <random>
int hp = 20, mp = 20, ehp = 35, move;

int randomNumber (int min, int max)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dist(min, max);
	return dist(gen);
}

void lose () 
{ 
	std::cout << "You were cut in half by the enemy and left to bleed out alone." << std::endl;
	std::cout << "Game Over: You Lose!" << std::endl;
	hp = 20; 
	mp = 20; 
	ehp = 35; 
} 

void win () 
{ 
	std::cout << "The enemy falls to their knees. You approach them and deliver the finishing blow which makes you victorious." << std::endl;
	std::cout << "Game Over: You Win!" << std::endl;
	hp = 20; 
	mp = 20; 
	ehp = 35;
}

std::string enemy_attack (int damage_taken)
{
	int enemy_action = randomNumber(1, 6);
	// attack
	if (enemy_action >= 1 && enemy_action <= 4) {
		std::cout << "The enemy uses his sword." << std::endl
				  << std::endl;
		hp -= 2;
	}
	// doge
	else if (enemy_action == 5)
	{
		std::cout << "The enemy dodged your attack." << std::endl
				  << std::endl;
		ehp += damage_taken;
	}
	// heal
	else 
	{
		ehp += 5;
		if (ehp > 35)
		{
			std::cout << "The enemy tried to healed some health back, but is already at full health." << std::endl
					  << std::endl;
			ehp = 35;
		}
		else 
		{
			std::cout << "The enemy healed some health back." << std::endl
					  << std::endl;
		}
	}

	if (hp <= 0)
	{
		lose();
		return "dead";
	} else {
		return "alive";
	}
}

int main() 
{
	label:
	int player_damage = 0;
	if (mp == 0)
	{
		std::cout << "Enemy Health: " << ehp << std::endl << "Your Health: " << hp << std::endl << "Mana: " << mp << std::endl << "(1) Attack" << std::endl;
	}
	else if (mp < 15)
	{
		std::cout << "Enemy Health: " << ehp << std::endl << "Your Health: " << hp << std::endl << "Mana: " << mp << std::endl << "(1) Attack" << std::endl << "(2) Magic Missile" << std::endl;
	}
	else
	{
		std::cout << "Enemy Health: " << ehp << std::endl << "Your Health: " << hp << std::endl << "Mana: " << mp << std::endl << "(1) Attack" << std::endl << "(2) Magic Missile" << std::endl << "(3) Summon" << std::endl;
	}
	std::cin >> move;
	std::cout << "Log:" << std::endl;

	if (move == 1) 
	{
		std::cout << "You sliced the enemy with your sword." << std::endl; 
		ehp -= 2;
		player_damage = 2;
		if (ehp <= 0) 
		{ 
			win();  
			return 0;
		} 
	} 

	else if (move == 2) 
	{ 
		if (mp < 1)
		{
			std::cout << "You don`t have enough Mana" << std::endl;
		} else
		{
			std::cout << "You cast a devastating Magic Missile." << std::endl; 
			ehp -= 5; 
			mp -= 1;
			player_damage = 5;
			if (ehp <= 0) 
			{ 
				win();  
				return 0;
			}
		}
	}   

	else if (move == 3) 
	{ 
		if (mp < 15)
		{
			std::cout << "You don`t have enough Mana" << std::endl;
		} else
		{
			std::cout << "You summoned Ultima!" << std::endl;
			hp -= 1;
			if (hp <= 0)
			{
				lose();
				return 0;
			}
			ehp -= 15; 
			mp -= 15;  
			player_damage = 15;
			if (ehp <= 0) 
			{ 
				win();  
				return 0;
			}
		}
	}

	std::string is_player_dead = enemy_attack(player_damage);
	if (is_player_dead == "dead")
	{
		return 0;
	}

	if (mp <= 0) {
		mp = 0;
	}

	goto label;
}