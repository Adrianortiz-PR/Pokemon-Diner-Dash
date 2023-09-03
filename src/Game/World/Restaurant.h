//
// Created by joshu on 11/3/2020.
//
#pragma once

#include "StoveCounter.h"
#include "BaseCounter.h"
#include "EntityManager.h"
#include "Player.h"
#include "ofMain.h"

class Restaurant {
    private:
        Player* player;
        EntityManager* entityManager;
        ofImage Lives;
        int ticks=0;
        std::vector<ofImage> people;
    public:
        static int money;
        Restaurant();
        Player* getPlayer();
        void setPlayer(Player *player);
        Item* cheese;
        Item* lettuce;
        Item* tomato;
        Item* burger;
        Item* botBread;
        Item* topBread;
        ofImage floor,dec1,dec2,dec3,dec4;
        std::map<std::string ,int> Prices ={
            {"cheese" , 3},{"lettuce" , 2},{"tomato" , 2},{"patty" , 4},{"bottomBun" , 1},{"topBun", 1}
            };
        void initItems();
        void initCounters();
        void initClients();
        void generateClient();
        void serveClient();
        void tick();
        void render();
        void keyPressed(int key);
        BaseCounter *getBaseActiveCounter();
        StoveCounter *getStoveActiveCounter();
};
