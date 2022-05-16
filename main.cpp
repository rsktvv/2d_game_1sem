#include <SFML/Graphics.hpp>
#include "circle.hpp";
#include "stop.hpp";
#include "stop2.hpp";
#include <thread>
#include <chrono>
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>

using namespace std::chrono_literals;

int main()
{
    int dlina = 1920;
    int shirina = 1080;
    int R = 20;
    int a = 360 - 45;
    double t = 0;
    int Vx = 8;
    int Vy = 8;
    int Xs = dlina - 50;
    int Ys = shirina / 2;
    int Xc = dlina / 2;
    int Xs2 = 50;
    int Ys2 = 50;
    int Yc = rand() % shirina / 2 + 1;
    int S = 0;

	bool flag = true;


    srand(time(0));

    float a_rad = (a) / 180 * acos(-1);


    sf::RenderWindow window(sf::VideoMode(dlina, shirina), L"ИТОГОВАЯ!");


    std::vector<ps::square*> square;
    square.push_back(new ps::square(Xs,Ys));

    std::vector<ps::circle*> circle;
    circle.push_back(new ps::circle(Xc, Yc, R, a_rad, Vx, Vy));

    std::vector<ps::stop2*> square2;
    square2.push_back(new ps::stop2(Xs2, Ys2));
    
   
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        
        
        for (const auto& square : square)
            window.draw(*square->Get());
        for (const auto& circle : circle)
            window.draw(*circle->Get());
        for (const auto& square2 : square2)
            window.draw(*square2->Get());

        for (const auto& square : square)
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)&&square->GetY()>0) { square->SetYU(); }   
        for (const auto& square : square)
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)&&square->GetY()<shirina-200) { square->SetYD(); }


        for (const auto& circle : circle)
            circle->circleMove( dlina, shirina);


        for (const auto& square2 : square2)
        {
            for (const auto& circle : circle)
            {
                if (square2->GetY2() + 100 < circle->getY())
                {
                    square2->SetY21();
                }
            }
        }

        for (const auto& square2 : square2)
        {
            for (const auto& circle : circle)
            {
                if (square2->GetY2() + 100 > circle->getY())
                {
                    square2->SetY22();
                }
            }
        }

        
        for (const auto& circle : circle)
        {
            for (const auto& square : square)
            {
				if ((square->GetX() <= (circle->getX() + R)))
				{
					Vx = -Vx;
					circle->SetVx(Vx);
				}
			
            }

			for (const auto& square2 : square2)
			{
				if (((circle->getX() - R) <= square2->GetX2()))
				{
					if (((circle->getX() + R) > (dlina && Vx > 0)) || ((circle->getX() + R) && (Vx < 0)))
					{
						Vx = -Vx;
					}

				}
			}
        }
       


     
     
        window.display();

        std::this_thread::sleep_for(40ms);
    }

    return 0;
}