//
// Created by joshu on 11/3/2020.
//
#include "Restaurant.h"

Player *Restaurant::getPlayer() { return player; }
void Restaurant::setPlayer(Player *player) { this->player = player; }
int Restaurant::money=0;   
int StoveCounter::cookingTime = 90;
int StoveCounter::cookingTick = 0;
bool StoveCounter::cooking = false;
bool StoveCounter::cooked = false;

Restaurant::Restaurant(){
    floor.load("images/inside.png");
    entityManager = new EntityManager();
    ofImage chefPlayerImage;
    chefPlayerImage.load("images/DetectivePikachu.png");
    this->player = new Player(0, 600, 64, 64, chefPlayerImage, entityManager);
    initItems();
    initCounters();
    initClients();
    generateClient();
}

void Restaurant::initItems(){
    ofImage burgerSpriteSheet, cheeseImg, lettuceImg, tomatoImg, burgerImg, botBreadImg, topBreadImg, plateImg;
    burgerSpriteSheet.load("images/Ingredients.png");
    topBreadImg.cropFrom(burgerSpriteSheet, 130, 0, 110, 66);   // top bun
    burgerImg.cropFrom(burgerSpriteSheet, 2, 78, 106, 54);    // patty
    cheeseImg.cropFrom(burgerSpriteSheet, 132, 76, 106, 58);   // cheese
    tomatoImg.cropFrom(burgerSpriteSheet, 2, 2, 106, 54);   // tomato
    lettuceImg.cropFrom(burgerSpriteSheet, 132, 152, 106, 56);   // lettuce
    botBreadImg.cropFrom(burgerSpriteSheet, 0,152, 110, 60); // bottom bun
    // plateImg.cropFrom(burgerSpriteSheet, 575, 263, 131, 51);    // plate
    cheese = new Item(cheeseImg, "cheese");
    lettuce = new Item(lettuceImg, "lettuce");
    tomato = new Item(tomatoImg, "tomato");
    burger = new Item(burgerImg, "patty");
    botBread = new Item(botBreadImg, "bottomBun");
    topBread = new Item(topBreadImg, "topBun");
}

void Restaurant::initCounters(){
    int counterWidth = 96;
    int yOffset = 500;
    ofImage counterSheet, plateCounterImg, cheeseCounterImg, stoveCounterImg, lettuceCounterImg, emptyCounterImg, tomatoCounterImg, breadCounterImg;
    counterSheet.load("images/kitchen_cabinets_by_ayene_chan.png");
    stoveCounterImg.cropFrom(counterSheet, 224, 12, 32, 43);  // stoveTop
    lettuceCounterImg.cropFrom(counterSheet, 96, 76, 32, 43); // Vegetables
    emptyCounterImg.cropFrom(counterSheet, 0, 245, 30, 43);   // Empty
    tomatoCounterImg.cropFrom(counterSheet, 96, 200, 32, 48); // fruit basket
    cheeseCounterImg.cropFrom(counterSheet, 64, 73, 32, 46);  // cheese
    plateCounterImg.cropFrom(counterSheet, 0, 133, 32, 50);   // plates
    breadCounterImg.cropFrom(counterSheet, 0, 63, 34, 56);    // buns
    entityManager->addEntity(new BaseCounter(0, yOffset - 16, counterWidth, 117, nullptr, plateCounterImg));
    entityManager->addEntity(new BaseCounter(counterWidth, yOffset - 7, counterWidth, 108, cheese, cheeseCounterImg));
    entityManager->addEntity(new StoveCounter(counterWidth * 2, yOffset, counterWidth, 102, burger, stoveCounterImg));
    entityManager->addEntity(new BaseCounter(counterWidth * 3, yOffset, counterWidth, 102, lettuce, lettuceCounterImg));
    entityManager->addEntity(new BaseCounter(counterWidth * 4, yOffset, counterWidth, 102, nullptr, emptyCounterImg));
    entityManager->addEntity(new BaseCounter(counterWidth * 5, yOffset - 10, counterWidth, 113, tomato, tomatoCounterImg));
    entityManager->addEntity(new BaseCounter(counterWidth * 6, yOffset - 32, counterWidth, 133, botBread, breadCounterImg));
    entityManager->addEntity(new BaseCounter(counterWidth * 7, yOffset - 32, counterWidth, 133, topBread, breadCounterImg));
}

void Restaurant::initClients(){
    ofImage temp;
    temp.load("images/People/Car_Designer3Female.png");
    people.push_back(temp);
    temp.load("images/People/Freedom_Fighter2Male.png");
    people.push_back(temp);
    temp.load("images/People/Hipster.png");
    people.push_back(temp);
    temp.load("images/People/Lawyer2Male.png");
    people.push_back(temp);
    temp.load("images/People/Mad_Scientist3Female.png");
    people.push_back(temp);
    temp.load("images/People/Programmer2Male.png");
    people.push_back(temp);
    temp.load("images/People/Songwriter3Male.png");
    people.push_back(temp);
    temp.load("images/People/Weather_Reporter2Female.png");
    people.push_back(temp);
}

void Restaurant::tick(){
    ticks++;
    if (ticks % 400 == 0){
        generateClient();
    }
    if(StoveCounter::cooking){
        if(StoveCounter::cookingTick >= StoveCounter::cookingTime){
            StoveCounter::cooked=true;
        }
        StoveCounter::cookingTick++;
    }
    player->tick();
    entityManager->tick();
}

void Restaurant::generateClient(){
    Burger *b = new Burger(72, 100, 50, 25);
    std::vector<Item *> options = {cheese, tomato, lettuce, burger};
    b->addIngredient(botBread);
    for (int i = 0; i < ofRandom(0, 3); i++){
        b->addIngredient(options[ofRandom(0, 4)]);
    }

    b->addIngredient(topBread);
    entityManager->addClient(new Client(0, 50, 64, 72, people[ofRandom(8)], b));
}

void Restaurant::render(){
    dec1.load("images/Decorations/UmbreonDec.png"); //dec1 shiny unbreon paiting
    dec2.load("images/Decorations/Table.png"); //dec2 tables
    dec3.load("images/Decorations/chair1.png"); //dec3 left chairs
    dec4.load("images/Decorations/chair2.png"); //dec4 right chairs
    Lives.load("images/Decorations/GreatBall.png"); //dec5 tells how many lives the player has left
    floor.draw(0, 0);
    dec1.draw(ofGetWidth() - 150, 25);

    dec2.draw(272, 175);
    dec2.draw(490, 175);
    dec2.draw(272, 325);
    dec2.draw(490, 325);

    dec3.draw(222, 185);
    dec3.draw(440, 185);
    dec3.draw(222, 335);
    dec3.draw(440, 335);

    dec4.draw(334, 185);
    dec4.draw(552, 185);
    dec4.draw(334, 335);
    dec4.draw(552, 335);
    for(int i=0;i<10;i++){
        ofSetColor(0);
        Lives.draw(ofGetWidth()-51,49+(40*i),38,38);
    }
    for(int i=0;i<Client::lives;i++){
        ofSetColor(255);
        Lives.draw(ofGetWidth()-50,50+(40*i));
    }

    
    player->render();
    entityManager->render();
    ofSetColor(255);
    ofDrawBitmapString("Money: " + to_string(Restaurant::money), ofGetWidth()/2, 20);
    if(StoveCounter::cooking){
        ofDrawRectRounded(190,450,94,-20,10);
        ofSetColor(0,255,0);
        if(StoveCounter::cooked){
            ofDrawRectRounded(192,448,StoveCounter::cookingTime,-16,10);
        }else{
        ofDrawRectRounded(192,448,StoveCounter::cookingTick,-16,10);
        }
    }
    ofSetColor(255);
    
}

void Restaurant::serveClient(){
    if(entityManager->firstClient!= nullptr){
        if(Player::Konami_mode){
            Restaurant::money += 3*(entityManager->firstClient->serve(player->getBurger(),Prices));
        }else{
            Restaurant::money += entityManager->firstClient->serve(player->getBurger(),Prices);
        }
    }
}

void Restaurant::keyPressed(int key){
    player->keyPressed(key);
    if (key == 's' || key == OF_KEY_DOWN){
       if(!player->getBurger()->GetCopyOfVector().empty()){//empty burger causes segmentation
        serveClient();
        player->getBurger()->clear();
       }
    }
    if (key == 'w' || key == OF_KEY_UP){
        BaseCounter *bac = player->getBaseActiveCounter();
        StoveCounter *sac = player->getStoveActiveCounter();
        if (sac != nullptr){
            if(StoveCounter::cooked){
                Item *item = sac->StoveCounter::getItem();
                if (item != nullptr){
                    Restaurant::money -= 1; // money added
                }
                StoveCounter::cookingTick=0;
                StoveCounter::cooking=false;
                StoveCounter::cooked=false;
            }else if(!StoveCounter::cooking && StoveCounter::cookingTick==0){
                StoveCounter::cooking=true;
            }
        }
        else if (bac != nullptr && !(sac != nullptr)){
            Item *item = bac->BaseCounter::getItem();
            if (item != nullptr){
                Restaurant::money -= 1; // money added
            }
        }
        
    }
}
