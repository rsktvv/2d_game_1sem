#pragma once 
#include <SFML/Graphics.hpp>

namespace ps
{
    class circle
    {
    public:
        circle(int x, int y, int r, float angle, int Vx, int Vy)
        {
            p_x = x;
            p_y = y;
            p_r = r;
            p_angle = angle;
            p_Vx = Vx;
            p_Vy = Vy;
           
            
            p_circle = new sf::CircleShape(p_r);

            p_circle->setFillColor(sf::Color::Green);
            p_circle->setOrigin(p_r, p_r);
            p_circle->setPosition(p_x, p_y);

        }
        ~circle()
        {
            delete p_circle;
        }

        sf::CircleShape* Get() { return p_circle; }
        
        int getX() { return p_x; }
        int getY() { return p_y; }

        void circleMove( int dlina, int shirina)
        {
            p_x += p_Vx;
            p_y += p_Vy;

            if ((p_x + p_r > dlina) && (p_Vx > 0) || ((p_x - p_r < 0) && (p_Vx < 0)))
            {
                p_Vx = -p_Vx;
            }

            if ((p_y + p_r > shirina) && (p_Vy > 0) || ((p_y - p_r < 0) && (p_Vy < 0)))
            {
                p_Vy = -p_Vy;
            }

            p_circle->setPosition(p_x, p_y);
        }

        void circleMoveStop()
        {
            p_Vy = -p_Vy;
            p_circle->setPosition(p_x, p_y);
        }

		void SetVx(int Vx)
		{
			p_Vx = Vx;
		}

       
      

        void SetX(int x)
        {
            p_x = x;
            p_circle->setPosition(p_x, p_y);
        }


        


    private:
        int p_x, p_y, p_r, p_Vx,p_Vy;
        float p_angle;

        sf::CircleShape* p_circle;
    };
}
