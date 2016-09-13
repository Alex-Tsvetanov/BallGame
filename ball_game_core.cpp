#include <iostream>
#include <gtkmm.h>
#include <set>
#include <vector>
#include <stdlib.h>
#include <stdio.h>

using namespace std;
#include "structures.hpp"
game_core game;
#include "AI/ball_game_AI_example.hpp"
#include "AI/stasi1.hpp"

int main (int argc, char *argv[])
{
	Gtk::Main app(argc, argv);
	vector <range> allowed_ranges = 
	{
		range (1, 2),
		range (2, 4)
	};
	game.set_ranges (allowed_ranges).set_balls (5);
	AI_return_1 player1;
	AI_return_1 player2;
	//AI_stasi1 player2;
	player1.choice (game.get_rules ());
	player2.choice (game.get_rules ());
	while (true)
	{
		int player1_turn = player1.turn (game.get_rules ());
		game.doTurn (1, player1_turn, player1.my_range);
		int player2_turn = player2.turn (game.get_rules ());
		game.doTurn (2, player2_turn, player2.my_range);
	}
}
