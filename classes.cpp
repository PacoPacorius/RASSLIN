#include "classes.h"

// WRESTLER WRESTLER WRESTLER WRESTLER WRESTLER WRESTLER WRESTLER WRESTLER WRESTLER WRESTLER WRESTLER WRESTLER WRESTLER WRESTLER WRESTLER WRESTLER WRESTLER WRESTLER WRESTLER WRESTLER WRESTLER WRESTLER WRESTLER WRESTLER

wrestler::wrestler(int i){
    id = i;
    health = 100;
    state = IDLE_STATE;

    load_textures();

    if(id == PLAYER_1){
        spr.setTexture(tex_idle_right);
        spr.setPosition(sf::Vector2f(200.f, 150.f));
        direction = LOOKING_RIGHT;
    }
    else{
        spr.setTexture(tex_idle_left);
        spr.setPosition(sf::Vector2f(400.f, 250.f));
        direction = LOOKING_LEFT;
    }


    time = 0;
}

// sf::Texture wrestler::get_texture(){
//     return tex;
// }

sf::Sprite wrestler::get_sprite(){
    return spr;
}

int wrestler::get_health() const{
    return health;
}

void wrestler::change_health(int amount){
    health += amount;
}

void wrestler::logic(wrestler& opp){
    if(state == IDLE_STATE){
        if(id == PLAYER_1){
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && spr.getPosition().x > 185.f){       //move only on keypress and only if within boundaries
                if(direction == LOOKING_RIGHT){
                    spr.setTexture(tex_idle_left);
                    direction = LOOKING_LEFT;
                }
                spr.move(sf::Vector2f(-5.f, 0.f));
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && spr.getPosition().x < 580.f){
                if(direction == LOOKING_LEFT){
                    spr.setTexture(tex_idle_right);
                    direction = LOOKING_RIGHT;
                }
                spr.move(sf::Vector2f(5.f, 0.f));
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && spr.getPosition().y > 100.f){
                spr.move(sf::Vector2f(0.f, -5.f));
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && spr.getPosition().y < 320.f){
                spr.move(sf::Vector2f(0.f, 5.f));
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::P))
                attack(opp);
        }
        else if(id == PLAYER_2){
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) && spr.getPosition().x > 185.f){       //move only on keypress and only if within boundaries
                if(direction == LOOKING_RIGHT){
                    spr.setTexture(tex_idle_left);
                    direction = LOOKING_LEFT;
                }
                spr.move(sf::Vector2f(-5.f, 0.f));
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) && spr.getPosition().x < 580.f){
                if(direction == LOOKING_LEFT){
                    spr.setTexture(tex_idle_right);
                    direction = LOOKING_RIGHT;
                }
                spr.move(sf::Vector2f(5.f, 0.f));
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) && spr.getPosition().y > 100.f){
                spr.move(sf::Vector2f(0.f, -5.f));
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) && spr.getPosition().y < 320.f){
                spr.move(sf::Vector2f(0.f, 5.f));
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
                attack(opp);
            }
        }
    }

    if(state == ATTACK_STATE && time == 35){
        state = IDLE_STATE;
        direction == LOOKING_LEFT ? spr.setTexture(tex_idle_left) : spr.setTexture(tex_idle_right);
        time = 0;
    }
    else if(state == ATTACK_STATE && time < 35)
        time++;

    if(state == HURT_STATE && time == 25){
        state = IDLE_STATE;
        direction == LOOKING_LEFT ? spr.setTexture(tex_idle_left) : spr.setTexture(tex_idle_right);
        time = 0;
    }
    else if(state == HURT_STATE && time < 25){
        time++;
    }

    if(health < 1){
        state = DOWNED_STATE;
        // std::cout<<"PLAYER "<<id<<" LOSES!"<<std::endl;
    }
}

void wrestler::attack(wrestler& opp){
    if(state == IDLE_STATE){
        state = ATTACK_STATE;
        // std::cout<<"ATTACK"<<std::endl;

        direction == LOOKING_LEFT ? spr.setTexture(tex_attack_left) : spr.setTexture(tex_attack_right);

        time = 0;
        sf::RectangleShape collision(sf::Vector2f(50.f, 30.f));
        collision.setPosition(sf::Vector2f(spr.getPosition().x + (direction)*15.f, spr.getPosition().y + 20.f));
        sf::FloatRect boundingbox = collision.getGlobalBounds();
        sf::FloatRect boundingbox2 = opp.get_sprite().getGlobalBounds();

        if(boundingbox.intersects(boundingbox2)){
            opp.receive_hit();
            // std::cout<<"*****"<<std::endl;
            // std::cout<<"*HIT*"<<std::endl;
            // std::cout<<"*****"<<std::endl;
        }
    }
}

int wrestler::get_direction() const{
    return direction;
}

int wrestler::get_state() const{
    return state;
}

void wrestler::receive_hit(){
    health -= 10;
    state = HURT_STATE;
    direction == LOOKING_LEFT ? spr.setTexture(tex_damage_left) : spr.setTexture(tex_damage_right);
    time = 0;
}

void wrestler::load_textures(){
    tex_idle_right.loadFromFile("rassler_right.png");
    tex_idle_left.loadFromFile("rassler_left.png");
    tex_attack_right.loadFromFile("punch_right.png");
    tex_attack_left.loadFromFile("punch_left.png");
    tex_damage_right.loadFromFile("damage_right.png");
    tex_damage_left.loadFromFile("damage_left.png");
}

void wrestler::set_id(int id){
    this->id = id;
}

// GAME GAME GAME GAME GAME GAME GAME GAME GAME GAME GAME GAME GAME GAME GAME GAME GAME GAME GAME GAME GAME GAME GAME GAME GAME GAME GAME GAME GAME GAME GAME GAME GAME GAME GAME GAME GAME GAME GAME GAME

// game::game(){
//     state = MENU;
// }
//
// int game::get_state() const{
//     return state;
// }
