struct range
{
	int from, to;
	range () {}
	range (int f, int t) : from (f), to (t)
	{}
};

bool operator > (range a, range b)
{
	return ((a.from == b.from)?(a.to > b.to):(a.from > b.from));
}

bool operator < (range a, range b)
{
	return ((a.from == b.from)?(a.to < b.to):(a.from < b.from));
}

struct game_rules
{
	int number_of_balls;
	std::set <range> all_ranges;
	vector < int > history;
};

struct game_core : private game_rules
{
public:
	template<typename T>
	game_core& set_ranges (T x)
	{
		all_ranges = std::set <range> (std::begin (x), std::end (x));
		return *this;
	}
	game_core& set_balls (int x)
	{
		number_of_balls = x;
		return *this;
	}
	bool valid (int get, range r) const 
	{
		return !(r.from <= get and get <= r.to);
	}

	void doTurn (int player, int get, range r)
	{
		if (valid (get, r))
		{
			text ("Player %d lose!", player);
			text ("Invalid turn. It get %d!", get);
			exit (0);
		}
		number_of_balls -= get;
		if (number_of_balls < 0)
		{
			text ("Player %d lose!", player);
			text ("Invalid turn. It get %d! On avaible ", get, number_of_balls);
			text ("Player %d win!", 3 - player);
			exit (0);
		}
		text ("Valid turn. Player %d get %d!", player, get);
		if (number_of_balls == 0)
		{
			text ("Player %d lose!", player);
			text ("Player %d win!", 3 - player);
			exit (0);
		}
		history.push_back (get);
	}
	void text (std::string pattern, int player, int turn = (((unsigned int)(-1)) << 1)) const
	{
		char* buffer = new char [2 * pattern.size ()];
		std::size_t n;
		n = sprintf (buffer, pattern.c_str (), player, turn);
		std::string ans (buffer, buffer + n);
		cout << ans << "\n ----------------------------------- \n";
		//Gtk::MessageDialog msg (ans.c_str ());
		//msg.run();

		return ;
	}
	game_rules get_rules () const
	{
		game_rules a;
		a.number_of_balls = number_of_balls;
		a.history = history;
		a.all_ranges = all_ranges;
		return a;
	}
};

