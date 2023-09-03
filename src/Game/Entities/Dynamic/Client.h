#pragma once

#include "Entity.h"
#include "Burger.h"

class Client: public Entity{
    private:
        Burger* burger;
        int patience=2000;
        int total = 0;
        int patienceColor=0;
    public:
	    static int lives;
        Client(int, int, int, int, ofImage, Burger*);
        virtual ~Client();
        void tick();
        void render();
        int serve(Burger*, std::map<std::string ,int>);
        Client* nextClient=nullptr;
        bool isLeaving=false;
        Burger* getBurger(){ return burger;}
};