#pragma once

#include "Item.h"
#include "Entity.h"
#include "BaseCounter.h"

class StoveCounter: public BaseCounter {
    private:
        Item *s_item;

    public:
        StoveCounter(int x, int y, int width, int height, Item* item, ofImage sprite);
        Item* getItem();
        void showItem();
        static int cookingTime;
        static int cookingTick;
        static bool cooked;
        static bool cooking;


};
