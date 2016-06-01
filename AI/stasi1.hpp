struct AI_stasi1
{
	range my_range;
	void choice (game_rules rules)
	{
		my_range = *rules.all_ranges.begin ();
	}
	int turn (game_rules rules)
	{
	    int n=rules.number_of_balls-1;
	    int a=my_range.from;
	    int b=my_range.to;
	    if(n%(a+b)>=a)
        {
            return n%(a+b)-a+1;
        }
        return a;
	}
};
