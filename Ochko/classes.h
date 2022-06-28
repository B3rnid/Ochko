#pragma once

class Ochko
{
public:
	std::vector<std::string> deck;
	std::vector<std::string> player_deck;
	int bank_cash, player_cash;

	Ochko();

	void deck_fill();
	void deck_print();
	void last_to_top();
	void bank_money();
	void player_money();
	void gameplay();
	void get_card();

	~Ochko();

private:

};

Ochko::Ochko()
{
	deck.resize(36);

	player_money();
	bank_money();
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
				deck[i] = 'T';
			}
			break;
		case 2:
			count2++;
			if (count2 <= 4)
			{
				deck[i] = 'K';
			}
			break;
		case 3:
			count3++;
			if (count3 <= 4)
			{
				deck[i] = 'Q';
			}
			break;
		case 4:
			count4++;
			if (count4 <= 4)
			{
				deck[i] = 'J';
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
				deck[i] = '9';
			}
			break;
		case 7:
			count7++;
			if (count7 <= 4)
			{
				deck[i] = '8';
			}
			break;
		case 8:
			count8++;
			if (count8 <= 4)
			{
				deck[i] = '7';
			}
			break;
		case 9:
			count9++;
			if (count9 <= 4)
			{
				deck[i] = '6';
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
	std::string card = deck[35];
	deck.pop_back();
	deck.insert(deck.begin(), card);
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

}

void Ochko::get_card()
{
	auto card = deck.cend();
	player_deck.push_back(*card);
	deck.pop_back();
}

Ochko::~Ochko()
{
}