#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
#include "classes.h"

    //A(11), K(4), Q(3), J(2), 10, 9, 8, 7, 6 x4
    //по 1 карте
    //набрать 21 или больше чем у соперника
    //банкир выдаёт карты
    //снизу кладётся карта наверх
    //банкир играет с игроками по очереди
    //игрок делает ставку и просит карту
    //нельзя набирать больше 21
    //если игрок набрал 21, он выигрывает
    //банкир выигрывает в том случае, если набрал больше или столько же как и игрок
    //банкир останавливается после того как набирает 16

int main()
{
    std::string next_round;

    srand(time(NULL));

    Ochko obj;

    obj.bank_money();
    obj.player_money();

    do //начало раунда
    {
        obj.deck_fill();
        obj.get_first_card();
        obj.last_to_top();
        obj.print_info();
        obj.set_bet();
        obj.gameplay();

        if (obj.player_cash == 0) //остановка игры в случае потери всех своих денег
        {
            std::cout << "\n\nyou lost all your money";
            std::cout << "\nyou can't continue";
            break;
        }

        if (obj.bank_cash == 0) //остановка игры в случае потери всех денег банком
        {
            std::cout << "\n\nyou left the bank without any money";
            std::cout << "\nyou can't continue";
            break;
        }

        std::cout << "\n\nenter \"next\" if you want to continue";
        std::cout << "\nenter \"stop\" if you want to stop playing\n";
        std::cin >> next_round;

        if (next_round != "next" && next_round != "stop")
        {
            do
            {
                std::cout << "\nincorrect value";
                std::cout << "\nenter \"next\" if you want to continue";
                std::cout << "\nenter \"stop\" if you want to stop playing\n";
                std::cin >> next_round;

            } while (next_round != "next" && next_round != "stop");
        }
    } while (next_round == "next"); 
}