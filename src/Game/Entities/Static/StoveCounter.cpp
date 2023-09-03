#include "StoveCounter.h"

StoveCounter::StoveCounter(int x, int y, int width, int height,Item* item, ofImage sprite) : BaseCounter(x, y, width, height, item, sprite) {
    s_item = item;
}

Item* StoveCounter::getItem(){
    return s_item;
}

void StoveCounter::showItem(){
    if (s_item != nullptr){
        s_item->sprite.draw(x+width/2 -25, y-30, 50, 30);
    }
}
