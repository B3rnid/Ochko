#pragma once

class Ochko
{
public:
	Ochko();
	
	void deck_fill();
	void deck_print();
	void last_to_top();
	void bank_money();
	void player_money();
	void gameplay();
	void print_info();
	void sum_of_deck();
	void set_bet();
	void loss();

	~Ochko();

private:
	std::vector<std::string> deck;
	std::vector<std::string> player_deck;
	std::vector<std::string> bank_deck;
	int bank_cash, player_cash, player_score, bet;
};

Ochko::Ochko()
{
	deck.resize(36);

	player_money();
	bank_money();

	system("CLS");
	deck_fill();

	player_deck.push_back(deck[0]);
	deck.erase(deck.begin());
	bank_deck.push_back(deck[0]);
	deck.erase(deck.begin());

	last_to_top();
}

void Ochko::print_info()
{
	std::cout << "cash in the bank: " << bank_cash;
	std::cout << "\nyour cash: " << player_cash;

	std::cout << "\n\ncard on top of the deck: " << deck[0];
	std::cout << "\nyour deck: ";
	for (std::string i : player_deck)
	{
		std::cout << i << " ";
	}
	sum_of_deck();
}

void Ochko::deck_fill()
{
	int card, count1 = 0, count2 = 0, count3 = 0, count4 = 0, count5 = 0, count6 = 0, count7 = 0, count8 = 0, count9 = 0;

	for (int i = 0; i < 36; i++)
	{
		card = rand() % 9 + 1;

		while (true)
		{
			if (card == 1 && count1 >= 4)
			{
				card = rand() % 9 + 1;
				continue;
			}
			if (card == 2 && count2 >= 4)
			{
				card = rand() % 9 + 1;
				continue;
			}
			if (card == 3 && count3 >= 4)
			{
				card = rand() % 9 + 1;
				continue;
			}
			if (card == 4 && count4 >= 4)
			{
				card = rand() % 9 + 1;
				continue;
			}
			if (card == 5 && count5 >= 4)
			{
				card = rand() % 9 + 1;
				continue;
			}
			if (card == 6 && count6 >= 4)
			{
				card = rand() % 9 + 1;
				continue;
			}
			if (card == 7 && count7 >= 4)
			{
				card = rand() % 9 + 1;
				continue;
			}
			if (card == 8 && count8 >= 4)
			{
				card = rand() % 9 + 1;
				continue;
			}
			if (card == 9 && count9 >= 4)
			{
				card = rand() % 9 + 1;
				continue;
			}
			else break;
		}

		switch (card)
		{
		case 1:
			count1++;
			if (count1 <= 4)
			{
				deck[i] = "A";
			}
			break;
		case 2:
			count2++;
			if (count2 <= 4)
			{
				deck[i] = "K";
			}
			break;
		case 3:
			count3++;
			if (count3 <= 4)
			{
				deck[i] = "Q";
			}
			break;
		case 4:
			count4++;
			if (count4 <= 4)
			{
				deck[i] = "J";
			}
			break;
		case 5:
			count5++;
			if (count5 <= 4)
			{
				deck[i] = "10";
			}
			break;
		case 6:
			count6++;
			if (count6 <= 4)
			{
				deck[i] = "9";
			}
			break;
		case 7:
			count7++;
			if (count7 <= 4)
			{
				deck[i] = "8";
			}
			break;
		case 8:
			count8++;
			if (count8 <= 4)
			{
				deck[i] = "7";
			}
			break;
		case 9:
			count9++;
			if (count9 <= 4)
			{
				deck[i] = "6";
			}
			break;
		}
	}
}

void Ochko::deck_print()
{
	for (int i = 0; i < 36; i++)
	{
		std::cout << deck[i] << ' ';
	}
	std::cout << '\n';
}

void Ochko::last_to_top()
{
	std::string last_card = deck.back();
	deck.pop_back();
	deck.insert(deck.begin(), last_card);
}

void Ochko::bank_money()
{
	std::cout << "Enter amount of cash in the bank: ";
	std::cin >> bank_cash;
}

void Ochko::player_money()
{
	std::cout << "Enter amount of your cash: ";
	std::cin >> player_cash;
}

void Ochko::gameplay()
{
	std::string key_word = "";

	for (int i = 0; key_word != "stop"; i++)
	{
		system("CLS");

		player_deck.push_back(deck.back());
		deck.pop_back();

		print_info();

		if (player_score > 21)
		{
			loss();
			break;
		}

		std::cout << "\n\nenter \"more\" if you need more cards";
		std::cout << "\nenter \"stop\" if you don't need more cards\n";
		std::cin >> key_word;

		if (key_word != "more" && key_word != "stop")
		{
			do
			{
				std::cout << "\nincorrect value";
				std::cout << "\nenter \"more\" if you need more cards";
				std::cout << "\nenter \"stop\" if you don't need more cards\n";
				std::cin >> key_word;

			} while (key_word != "more" && key_word != "stop");
		}
	}

	if (player_score <= 21)
	{

	}
}

void Ochko::sum_of_deck()
{
	player_score = 0;

	for (std::string i : player_deck)
	{
		if (i == "A")
		{
			player_score += 11;
		}
		if (i == "K")
		{
			player_score += 4;
		}
		if (i == "Q")
		{
			player_score += 3;
		}
		if (i == "J")
		{
			player_score += 2;
		}
		if (i == "10")
		{
			player_score += 10;
		}
		if (i == "9")
		{
			player_score += 9;
		}
		if (i == "8")
		{
			player_score += 8;
		}
		if (i == "7")
		{
			player_score += 7;
		}
		if (i == "6")
		{
			player_score += 6;
		}
	}

	std::cout << "(" << player_score << ")";
}

void Ochko::set_bet()
{
	std::cout << "\n\nenter your bet: ";
	std::cin >> bet;
}

void Ochko::loss()
{
	player_cash -= bet;
	bank_cash += bet;

	system("CLS");
	print_info();

	std::cout << "\n\nyou have lost your bet";
}

Ochko::~Ochko()
{
}