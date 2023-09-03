//
// Created by joshu on 11/3/2020.
//

#include "BaseCounter.h"

BaseCounter::BaseCounter(int x, int y, int width, int height,Item* item, ofImage sprite) : Entity(x, y, width, height, sprite){
    b_item = item;
}

Item* BaseCounter::getItem(){
    return b_item;
}

void BaseCounter::showItem(){
    if (b_item != nullptr){
        b_item->sprite.draw(x+width/2 -25, y-30, 50, 30);
    }
}
