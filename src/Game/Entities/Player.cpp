#include "Player.h"

bool Player::Konami_mode=false;


Player::Player(int x, int y, int width, int height, ofImage sprite, EntityManager *em) : Entity(x, y, width, height, sprite){
    vector<ofImage> chefAnimframes;
    ofImage temp;
    this->burger = new Burger(ofGetWidth() - 110, 100, 100, 50);
    temp=sprite;
    chefAnimframes.push_back(temp);
    this->chefAnim = new Animation(50, chefAnimframes);
    this->entityManager = em;
}
void Player::Clear_Konami(){
    if(User_Konami_code.size() > Konami_code.size()){
        timerStarted=false;
        User_Konami_code.clear();
    }
}
void Player::tick(){
    chefAnim->tick();
    Clear_Konami();

    if (timerStarted) {
        float elapsedTime = ofGetElapsedTimef() - startedTime;
        if (5 < elapsedTime && User_Konami_code == Konami_code) {
            Player::Konami_mode = true;
        }
        if(5 == elapsedTime){
            timerStarted = false;
            User_Konami_code.clear();
        } 
    }
}

void Player::render(){
    BaseCounter *bac = getBaseActiveCounter();
    if (bac != nullptr){
        bac->BaseCounter::showItem();
    }
    StoveCounter *sac = getStoveActiveCounter();
    if (sac != nullptr){
        sac->StoveCounter::showItem();
    }
    ofSetColor(256, 256, 256);
    ofImage currentFrame = chefAnim->getCurrentFrame();
    if (facing == "left"){
        currentFrame.mirror(false, true);
    }
    currentFrame.draw(x, y, width, height);
    burger->render();
}

void Player::keyPressed(int key){
    if (key == OF_KEY_UP || key == 'w'){
        BaseCounter *bac = getBaseActiveCounter();
        StoveCounter *sac = getStoveActiveCounter();
        if (sac != nullptr){
            if(StoveCounter::cooked){
                Item *item = sac->StoveCounter::getItem();
                if (item != nullptr){
                    burger->addIngredient(item); // money added
                }
            }
        }
        else if (bac != nullptr){
            Item *item = bac->BaseCounter::getItem();
            if (item != nullptr){
                burger->addIngredient(item);
            }
        }
    }
    if (key == 'u'){
        BaseCounter *bac = getBaseActiveCounter();
        if (bac != nullptr){
            Item *item = bac->BaseCounter::getItem();
            if (item != nullptr){
                burger->RemoveIngredient();
            }
        }
    }
    if (key == OF_KEY_LEFT || key == 'a'){
        facing = "left";
        if(x > 0){
        x-=speed + 20;
        }
    }
    if (key == OF_KEY_RIGHT || key == 'd'){
        facing = "right";
        if(x + width < ofGetWidth()){
        x+=speed + 20;
        }
    }
    switch (key) {
    case 'c':
        if (!timerStarted){
            timerStarted = !timerStarted;
            startedTime = ofGetElapsedTimef();
          }
        User_Konami_code.push_back(key);
        break;

    case 'x':
        if (Player::Konami_mode){
            User_Konami_code.clear();
            Player::Konami_mode = false;
        }
        else {
            User_Konami_code.push_back(key);
        }
        break;

    default:
        User_Konami_code.push_back(key);
    }
}

BaseCounter *Player::getBaseActiveCounter(){
    for (Entity *e : entityManager->entities){
        BaseCounter *c = dynamic_cast<BaseCounter *>(e);
        if (x + e->getWidth() / 2 >= e->getX() && x + e->getWidth() / 2 < e->getX() + e->getWidth()){
            return c;
        }
    }
    return nullptr;
}
StoveCounter *Player::getStoveActiveCounter(){
    for (Entity *e : entityManager->entities){
        StoveCounter *c = dynamic_cast<StoveCounter *>(e);
        if (x + e->getWidth() / 2 >= e->getX() && x + e->getWidth() / 2 < e->getX() + e->getWidth()){
            return c;
        }
    }
    return nullptr;
}


void Player::keyReleased(int key){
}

void Player::mousePressed(int x, int y, int button){
}

void Player::setFacing(string facing) { this->facing = facing; }