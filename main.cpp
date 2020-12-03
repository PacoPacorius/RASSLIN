// TODO: start menu, winning animation, color and detail wrestler sprites
// TODO2: assert that the loading of textures is succesful also debug mode?
// IDEAS: add a second attack or a block?, maybe add a healthbar and a counter?, ai

// USING ONE SPRITE AND REBINDING TEXTURES TO IT ALL THE TIME IMPACTS PERFORMANCE NEGATIVELY! It is better to have more sprites
#include "Animation.h"
#include "classes.h"

int main(){
    sf::RenderWindow Win(sf::VideoMode(800, 600), "", sf::Style::None);
    Win.setPosition(sf::Vector2i(10, 50));
    Win.setFramerateLimit(50);

    int state = MENU;

    // game geim();

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

        Win.clear();

        // Win.draw(ring);


        if(state == MENU){                      // this will prove useful later when I make a main menu
            state = IN_GAME;
        }

        if(state == IN_GAME){                   // where all the punchy punchy happens
            rassler.logic(rassler2);
            rassler2.logic(rassler);

            std::cout<<"RASSLER 1: "<<rassler.get_health()<<std::endl;
            std::cout<<"RASSLER 2: "<<rassler2.get_health()<<std::endl<<std::endl;

            if(rassler.get_state() == DOWNED_STATE || rassler2.get_state() == DOWNED_STATE)
                state = END_GAME;

            // Win.clear();

            // Win.draw(rectangle);

            // Win.draw(rassler.get_sprite());
            // Win.draw(rassler2.get_sprite());


            // Win.display();
            // state = END_GAME;
        }
        else if(state == END_GAME){             // will display a winning animation
            rassler.get_state() == DOWNED_STATE ? std::cout<<"Player 2 WINS!"<<std::endl<<std::endl : std::cout<<"Player 1 WINS!"<<std::endl<<std::endl;
            std::cout<<"yass"<<std::endl;
            if(rassler.get_state() == DOWNED_STATE){
                std::cout<<"Player 2 WINS!"<<std::endl<<std::endl;
                rassler2.time = 0;
                rassler2.get_sprite_celebrate().setPosition(sf::Vector2f(rassler2.get_sprite().getPosition()));
                rassler2.animate_celebration();
                rassler.get_sprite().setTexture(rassler.get_downed_texture());

                // Win.draw(rassler2.get_sprite_celebrate());
                // Win.draw(rassler.get_sprite());
            }
            else{
                std::cout<<"Player 1 WINS!"<<std::endl<<std::endl;
                rassler.time = 0;
                rassler.get_sprite_celebrate().setPosition(rassler.get_sprite().getPosition());
                rassler.animate_celebration();
                rassler2.get_sprite().setTexture(rassler2.get_downed_texture());

                // Win.draw(rassler.get_sprite_celebrate());
                // Win.draw(rassler2.get_sprite());
            }

            Win.draw(ring);

            // Win.draw(rectangle);

            Win.draw(rassler.get_sprite());
            Win.draw(rassler2.get_sprite());

            Win.draw(ring_ropes);

            Win.display();

            // Win.close();
        }
    }
    return 0;
}
