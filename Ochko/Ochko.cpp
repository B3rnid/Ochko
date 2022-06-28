#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
#include "classes.h"

    //T(11), K(4), Q(3), J(2), 10, 9, 8, 7, 6 x4
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
    srand(time(NULL));

    Ochko obj;
    system("CLS");
    obj.deck_fill();
    std::cout << "cash in the bank: " << obj.bank_cash;
    std::cout << "\nyour cash: " << obj.player_cash;
    std::cout << "\n\ncard on top of the deck: ";
    obj.last_to_top();
    std::cout << obj.deck[0];
    std::cout << "\n\nyour deck: ";
    obj.get_card();
    for (std::string i : obj.player_deck)
    {
        std::cout << i;
    }

}