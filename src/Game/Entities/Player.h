#pragma once
#include "Animation.h"
#include "Burger.h"
#include "EntityManager.h"
#include "BaseCounter.h"
#include "StoveCounter.h"
class Player: public Entity{

    private:
        int speed = 5;
        string facing = "right";
        Animation *chefAnim;
        Burger *burger;
        EntityManager* entityManager;
        bool timerStarted = false;
        ofSoundPlayer song;
    

        
    public:
        static bool Konami_mode;
        static bool Konami_song;
        int startedTime;
        Player();
        Player(int x, int y, int width, int height, ofImage sprite, EntityManager* em);
        void tick();
        void render();
        void keyPressed(int);
        void keyReleased(int);
        void mousePressed(int, int, int);
        void setFacing(string);
        BaseCounter* getBaseActiveCounter();
        StoveCounter* getStoveActiveCounter();
        Burger* getBurger(){ return burger;};    
        void Clear_Konami();
        std::vector<char> Konami_code= {'c','i','i','c','4','0','1','0'};
        std::vector<char> User_Konami_code;
        
};