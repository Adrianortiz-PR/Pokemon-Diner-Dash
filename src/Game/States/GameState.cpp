#include "GameState.h"

GameState::GameState(){
    this->restaurant = new Restaurant();
}
void GameState::tick(){
	if(Client::lives==0 || Restaurant::money<=-50){
		setNextState("Lose");
		setFinished(true);
		Player::Konami_song=false;
		Player::Konami_mode=false;
		Client::lives = 10;
		Restaurant::money = 0;
		StoveCounter::cookingTime = 90;
		StoveCounter::cookingTick = 0;
		StoveCounter::cooking = false;
		StoveCounter::cooked = false;
	}
	if(Restaurant::money >= 100){
		setNextState("Win");
		setFinished(true);
		Player::Konami_song=false;
		Player::Konami_mode=false;
		Client::lives = 10;
		Restaurant::money = 0;
		StoveCounter::cookingTime = 90;
		StoveCounter::cookingTick = 0;
		StoveCounter::cooking = false;
		StoveCounter::cooked = false;

	}
	restaurant->tick();
}
void GameState::render(){
	restaurant->render();
}

void GameState::keyPressed(int key){
	restaurant->keyPressed(key);
}

void GameState::mousePressed(int x, int y, int button){
}

void GameState::keyReleased(int key){
}

void GameState::reset(){
	setFinished(false);
	setNextState("");
}