#pragma once 
#include <SFML/Graphics.hpp>

namespace ps
{

    class stop2
    {
    public:
        stop2(int x, int y)
        {
            p_x = x;
            p_y = y;

            p_square2 = new sf::RectangleShape(sf::Vector2f(10, 200));

            p_square2->setFillColor(sf::Color::Red);
            p_square2->setPosition(p_x, p_y);

        }
        ~stop2()
        {
            delete p_square2;
        }
        sf::RectangleShape* Get() { return p_square2; }



        int GetY2() { return p_y; }
        int GetX2() { return p_x; }

        void SetY21()
        {
            p_y += 3;
            p_square2->setPosition(p_x, p_y);
        }
        void SetY22()
        {
            p_y -= 3;
            p_square2->setPosition(p_x, p_y);
        }


        

    private:
        int p_x, p_y;
        sf::RectangleShape* p_square2;
    };
}