// от чего будет отталкиваться 
#pragma once 
#include <SFML/Graphics.hpp>

namespace ps
{

    class square
    {
    public:
        square(int x, int y)
        {
            p_x = x;
            p_y = y;
         
            p_square = new sf::RectangleShape(sf::Vector2f(10, 200));

            p_square->setFillColor(sf::Color::Blue);
            p_square->setPosition(p_x, p_y);

        }
        ~square()
        {
            delete p_square;
        }
        sf::RectangleShape* Get() { return p_square; }
        
        

        int GetY() { return p_y; }
        int GetX() { return p_x; }

        void SetYU()
        {
            p_y -=7;
            p_square->setPosition(p_x, p_y);
        }

        void SetYD()
        {
            p_y +=7;
            p_square->setPosition(p_x, p_y);
        }

    private:
        int p_x, p_y;
        sf::RectangleShape* p_square;
    };
}