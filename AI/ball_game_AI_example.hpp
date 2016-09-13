struct AI_return_1
{
	range my_range;
	void choice (game_rules rules)
	{
		my_range = *rules.all_ranges.begin ();
	}
	int turn (game_rules rules)
	{
		int a;
		std::cin >> a;
		return a;
	}
};
