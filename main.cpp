//TODO: animations for combat, end of game, start menu, maybe add a second attack?, maybe add a healthbar and a counter?, implement game class and game states, tidy up everything
//TODO2: assert that the loading of textures is succesful also debug mode?
#include "classes.h"

int main(){
    sf::RenderWindow Win(sf::VideoMode(800, 600), "", sf::Style::None);
    Win.setPosition(sf::Vector2i(10, 50));
    Win.setFramerateLimit(50);

    wrestler rassler(PLAYER_1);
    wrestler rassler2(PLAYER_2);

    // sf::RectangleShape rectangle(sf::Vector2f(50.f, 50.f));
    // rectangle.setFillColor(sf::Color::White);


    sf::Texture tex_ring;                    //load the ring texture
    tex_ring.loadFromFile("ring.png");


    sf::Texture tex_ring_ropes;              //load the ring ropes texture
    tex_ring_ropes.loadFromFile("ringropes.png");


    sf::Sprite ring;
    ring.setTexture(tex_ring);
    ring.setPosition(sf::Vector2f(150.f, 90.f));

    sf::Sprite ring_ropes;
    ring_ropes.setTexture(tex_ring_ropes);
    ring_ropes.setPosition(sf::Vector2f(156.f, 360.f));

    while(Win.isOpen()){

        sf::Event event;

        while(Win.pollEvent(event)){
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt) && sf::Keyboard::isKeyPressed(sf::Keyboard::F4))  //close window with Alt+F4
            Win.close();
        }

        rassler.logic(rassler2);
        rassler2.logic(rassler);

        std::cout<<"RASSLER 1: "<<rassler.get_health()<<std::endl;
        std::cout<<"RASSLER 2: "<<rassler2.get_health()<<std::endl;

        Win.clear();

        Win.draw(ring);

        // Win.draw(rectangle);

        Win.draw(rassler.get_sprite());
        Win.draw(rassler2.get_sprite());

        Win.draw(ring_ropes);

        Win.display();
    }
    return 0;
}
