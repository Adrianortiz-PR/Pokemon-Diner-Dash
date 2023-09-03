#include "State.h"
#include "LoseState.h"


LoseState::LoseState(){
	playAgainButtom = new Button(96,546,204,126," ");
	toMenu = new Button(516,546,204,126," ");
	img1.load("images/DefLose.png");
}

void LoseState::tick(){
	playAgainButtom->tick();
	if(playAgainButtom->wasPressed()){
		setNextState("Game");
		setFinished(true);
	}
	toMenu->tick();
	if(toMenu->wasPressed()){
		setNextState("Menu");
		setFinished(true);
	}
}

void LoseState::render(){
	ofSetColor(255);
	img1.draw(0,0);
	ofSetColor(0);
	ofDrawBitmapString("Wanna play again?", 136, 609);
	ofDrawBitmapString("Go to menu", 576, 609);
	playAgainButtom->render();
	toMenu->render();

}

void LoseState::keyPressed(int key){
}

void LoseState::mousePressed(int x, int y, int button){
	playAgainButtom->mousePressed(x, y);
	toMenu->mousePressed(x, y);
}

void LoseState::reset(){
	setFinished(false);
	setNextState("");
	playAgainButtom->reset();
	toMenu->reset();
}