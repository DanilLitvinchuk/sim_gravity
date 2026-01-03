#include <SFML/Graphics.hpp>
#include <cmath>


int main(){
    sf::RenderWindow window(sf::VideoMode(800, 600), "Gravity");
    window.setFramerateLimit(180);
    
    float circle1_x = 400;
    float circle1_y = 300;
    float circle1_mass = 1000;
    float vel_circle1_x = 0;
    float vel_circle1_y = 0;
    
    float circle2_x = 200;
    float circle2_y = 200;
    float circle2_mass = 1;
    float vel_circle2_x = 1.5;
    float vel_circle2_y = -1.5;
    
    sf::CircleShape circle1(10); 
    circle1.setFillColor(sf::Color::Yellow);
    circle1.setPosition(circle1_x, circle1_y);
    
    sf::CircleShape circle2(5);
    circle2.setFillColor(sf::Color::Blue);
    circle2.setPosition(circle2_x, circle2_y);
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        // logic
        float distance = sqrt(pow((circle2_x - circle1_x), 2) + pow((circle2_y - circle1_y), 2)); // R
        float F = (circle1_mass*circle2_mass) / pow(distance, 2);
        float a1 = F / circle1_mass;
        float a2 = F / circle2_mass;
        float dx = (circle2_x + 5) - (circle1_x + 5);
        float dy = (circle2_y + 5) - (circle1_y + 5);
        float ax1 = a1*(dx/distance);
        float ay1 = a1*(dy/distance);
        float ax2 = a2*(dx/distance);
        float ay2 = a2*(dy/distance);

        vel_circle1_x += ax1; 
        vel_circle1_y += ay1;

        vel_circle2_x -= ax2; 
        vel_circle2_y -= ay2;

        // move
        circle1_x += vel_circle1_x;
        circle1_y += vel_circle1_y;

        circle2_x += vel_circle2_x;
        circle2_y += vel_circle2_y;


        // update
        circle1.setPosition(circle1_x, circle1_y);
        circle2.setPosition(circle2_x, circle2_y);
        
        window.clear(sf::Color::Black);
        window.draw(circle1);
        window.draw(circle2);
        window.display();
        
    }
    
    return 0;
}