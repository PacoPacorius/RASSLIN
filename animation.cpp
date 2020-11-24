// #include "Animation.h"
// #include "classes.h"
//
// // animation::animation(){
// //     progress = totalLength = 0.0;
// // }
//
// animation::animation(sf::Sprite &target) : target(target){
//     progress = totalLength = 0.0;
// }
//
// void animation::bind_sprite(sf::Sprite& target){
//     this->target = target;
// }
//
// void animation::addFrame(Frame&& frame){
//     totalLength += frame.duration;
//     frames.push_back(std::move(frame));
// }
//
// void animation::update(double elapsed){
//     progress += elapsed;
//     double p = progress;
//     for(int i = 0; i < frames.size(); i++){
//         p -= frames[i].duration;
//
//         if(p <= 0.0 || &(frames[i]) == &frames.back()){
//             target.setTextureRect(frames[i].rect);
//             break;
//         }
//     }
// }
