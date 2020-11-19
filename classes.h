#include <SFML/Graphics.hpp>
#include <iostream>

#define LOOKING_RIGHT 1                             // will be used when attacking. When a wrestler attacks an invisible sprite show up in front of him as a hitbox. This hitbox will take the attacking wrestler's position and will be moved slightly towards the direction the player's looking with the help of these
#define LOOKING_LEFT -1

#define AI       0                                  // self-explanatory i guess?
#define PLAYER_1 1
#define PLAYER_2 2

#define IDLE_STATE   0                              // rassler states
#define ATTACK_STATE 1
#define HURT_STATE   2
#define DOWNED_STATE 3

#define MENU     0                                  // game states
#define IN_GAME  1
#define END_GAME 2

class wrestler{
private:
    sf::Texture tex_idle_right;
    sf::Texture tex_idle_left;
    sf::Texture tex_attack_right;
    sf::Texture tex_attack_left;
    sf::Texture tex_damage_right;
    sf::Texture tex_damage_left;
    sf::Sprite spr;
    int health;
    int direction;
    int id;
    int state;
public:
    int time;
    wrestler(int i);
    // void load_texture(std::string& filename);
    // void set_texture();
    // sf::Texture get_texture();
    sf::Sprite get_sprite();
    int get_health() const;
    void change_health(int amount);
    void logic(wrestler& opp);
    void attack(wrestler& opp);
    int get_direction() const;
    int get_state() const;
    void receive_hit();
    void load_textures();
};

// What do I want the game class to do?
// 1. I want it to have three states (main menu, game, end-game)
// 2. main menu will have the option of 2 players or player vs AI
// 3. The game state is where all the punchy punchy happens. At some point, have the game class handle two health bars and a timere
// 4. end-game will play an animation of the player who won while th other player is laying down. After some time, you can return to the main menu after pressing any key

class game{
private:
    int state;
public:
    game();
    
};
