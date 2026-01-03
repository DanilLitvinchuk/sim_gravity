#include <SFML/Graphics.hpp>
#include <cmath>


int main(){
    sf::RenderWindow window(sf::VideoMode(800, 600), "Gravity");
    window.setFramerateLimit(60);
    
    float circle1_x = 400;
    float circle1_y = 300;
    float circle1_mass = 10.0;
    float vel_circle1_x = 0; // circle 1 start velocity x 
    float vel_circle1_y = 0; // circle 1 start velocity y
    
    float circle2_x = 300;
    float circle2_y = 200;
    float circle2_mass = 5.0;
    float vel_circle2_x = 0; // circle 2 start velocity x
    float vel_circle2_y = 0; // circle 2 start velocity y

    float circle3_x = 500;
    float circle3_y = 300;
    float circle3_mass = 10.0;
    float vel_circle3_x = 0; // circle 3 start velocity x 
    float vel_circle3_y = 0; // circle 3 start velocity y
    
    sf::CircleShape circle1(4); 
    circle1.setFillColor(sf::Color::Yellow);
    circle1.setPosition(circle1_x, circle1_y);
    
    sf::CircleShape circle2(2);
    circle2.setFillColor(sf::Color::Blue);
    circle2.setPosition(circle2_x, circle2_y);

    sf::CircleShape circle3(4);
    circle3.setFillColor(sf::Color::Green);
    circle3.setPosition(circle3_x, circle3_y);

    sf::RectangleShape fadeRect;
    fadeRect.setSize(sf::Vector2f(800, 600));
    fadeRect.setFillColor(sf::Color(0, 0, 0, 10)); // train
    fadeRect.setPosition(0, 0);
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        // logic
        
        float accX1 = 0, accY1 = 0;
        float accX2 = 0, accY2 = 0;
        float accX3 = 0, accY3 = 0;

        float dx12 = (circle2_x + 2) - (circle1_x + 4);
        float dy12 = (circle2_y + 2) - (circle1_y + 4);
        float dist12 = sqrt(dx12 * dx12 + dy12 * dy12);
        if (dist12 < 10.0f) dist12 = 10.0f;

        float F12 = (circle1_mass * circle2_mass) / (dist12 * dist12);
        float a12 = F12 / circle1_mass;
        float a21 = F12 / circle2_mass;

        accX1 += a12 * (dx12 / dist12);
        accY1 += a12 * (dy12 / dist12);
        accX2 -= a21 * (dx12 / dist12);
        accY2 -= a21 * (dy12 / dist12);

        float dx13 = (circle3_x + 4) - (circle1_x + 4);
        float dy13 = (circle3_y + 4) - (circle1_y + 4);
        float dist13 = sqrt(dx13 * dx13 + dy13 * dy13);
        if (dist13 < 10.0f) dist13 = 10.0f;

        float F13 = (circle1_mass * circle3_mass) / (dist13 * dist13);
        float a13 = F13 / circle1_mass;
        float a31 = F13 / circle3_mass;

        accX1 += a13 * (dx13 / dist13);
        accY1 += a13 * (dy13 / dist13);
        accX3 -= a31 * (dx13 / dist13);
        accY3 -= a31 * (dy13 / dist13);

        float dx23 = (circle3_x + 4) - (circle2_x + 2);
        float dy23 = (circle3_y + 4) - (circle2_y + 2);
        float dist23 = sqrt(dx23 * dx23 + dy23 * dy23);
        if (dist23 < 10.0f) dist23 = 10.0f;

        float F23 = (circle2_mass * circle3_mass) / (dist23 * dist23);
        float a23 = F23 / circle2_mass;
        float a32 = F23 / circle3_mass;

        accX2 += a23 * (dx23 / dist23);
        accY2 += a23 * (dy23 / dist23);
        accX3 -= a32 * (dx23 / dist23);
        accY3 -= a32 * (dy23 / dist23);
        
        vel_circle1_x += accX1; 
        vel_circle1_y += accY1;

        vel_circle2_x += accX2; 
        vel_circle2_y += accY2;

        vel_circle3_x += accX3; 
        vel_circle3_y += accY3;


        // move
        circle1_x += vel_circle1_x;
        circle1_y += vel_circle1_y;

        circle2_x += vel_circle2_x;
        circle2_y += vel_circle2_y;

        circle3_x += vel_circle3_x;
        circle3_y += vel_circle3_y;


        // update
        circle1.setPosition(circle1_x, circle1_y);
        circle2.setPosition(circle2_x, circle2_y);
        circle3.setPosition(circle3_x, circle3_y);
        
        window.draw(fadeRect);
        window.draw(circle1);
        window.draw(circle2);
        window.draw(circle3);
        window.display();
        
    }
    
    return 0;
}