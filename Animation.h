// #include <SFML/Graphics.hpp>
// #include <iostream>
//
// struct Frame{
//     sf::IntRect rect;       // this specifies which part of the spritesheet to actually draw
//     double duration;        // this displays how long this specific frame will last in the animation in seconds
// };
//
// class animation{
// private:
//     std::vector<Frame> frames;      // the total frames in the animation
//     double totalLength;             // total length of the animation
//     double progress;                // which point in the animation we're currently in?
//     sf::Sprite target;             // reference to a sprite provided externally through the constructor
// public:
//     // animation();
//     animation(sf::Sprite &target);
//     void bind_sprite(sf::Sprite &target);
//     // virtual ~animation();           // dont know why this is here or if it's necessary (I think it isn't tbh)
//     void addFrame(Frame &&frame);   // why a reference to a reference?
//     void update(double elapsed);
//     const double getLength() const{ // idk might be useful
//         return totalLength;
//     }
// };
