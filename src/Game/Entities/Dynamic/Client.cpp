#include "Client.h"

int Client::lives = 10;


Client::Client(int x, int y, int width, int height, ofImage sprite, Burger* burger): Entity(x, y, width, height, sprite){
    this->burger = burger;
}

Client::~Client(){
    delete burger;
}

void Client::render(){
    burger->render();
    ofSetColor(255, 255, 255);
    patienceColor++;
    ofSetColor(255, 255 - patienceColor / 10, 255 - patienceColor / 10);
    sprite.draw(x, y, width, height);
    ofSetColor(255, 255, 255);
    if (nextClient != nullptr){
        nextClient->render();
    }
}

void Client::tick(){
    patience--;
    burger->setY(y);
    if(patience == 0){
        Client::lives--;
        isLeaving = true;
    }
    if (nextClient != nullptr){
        nextClient->tick();
    }
}

int Client::serve(Burger *burger, std::map<std::string, int> Prices){
    if(this->nextClient == nullptr){
        return 0;
    }
    if (this->burger->equals(burger)){                                                                
        std::vector<Item *> Ingredients = burger->GetCopyOfVector(); 
        for (int i = 0; i < (int)Ingredients.size(); i++){
            total += Prices[Ingredients[i]->getName()];
        }
        isLeaving = true;
        return total;
    }
    if(this->nextClient == nullptr){
        return 0;
    }
    return nextClient->serve(burger, Prices);
}
