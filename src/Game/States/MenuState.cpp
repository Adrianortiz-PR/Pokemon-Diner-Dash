#include "MenuState.h"

MenuState::MenuState(){
	string text1 = "Start";
	startButton = new Button((ofGetWidth()/2 - text1.length()*8)+140, (ofGetHeight()/2 - text1.length()*11), 64, 50, text1);
}

void MenuState::tick(){
	img1.load("images/Start.png");
	startButton->tick();
	if(startButton->wasPressed()){
		setNextState("Game");
		setFinished(true);
	}
}

void MenuState::render(){
	ofSetColor(255);
	img1.draw(0,0);
	if(menuInstructions){//Draws the menu of the instructions and ways to win or lose.
		ofEnableAlphaBlending();
		ofSetColor(0,0,0,127);
		ofDrawRectRounded(37,37,336,348,10);
		ofSetColor(255);
		ofDrawBitmapString("You win if you get 100 dollars.",42,52);
		ofDrawBitmapString("You lose if 10 clients go away or get a",42,67);
		ofDrawBitmapString("debt of 50 dollars.",42,82);

		ofDrawBitmapString("Controls:",162,112);
		ofDrawBitmapString("Use 'w' or up arrow key to add",42,127);
		ofDrawBitmapString("ingredients.",42,142);
		ofDrawBitmapString("Use 'a' or left arrow key to move left.",42,157);
		ofDrawBitmapString("Use 'd' or right arrow key to move right.",42,172);
		ofDrawBitmapString("Use 's' or down arrow key to serve.",42,187);
		ofDrawBitmapString("Use 'u' to undo the last ingredient.",42,202);
		
		ofDrawBitmapString("Press 'i' to close this menu",42,380);
	}
	if(!menuInstructions){
		ofDrawBitmapString("Press 'i' for instructions",ofGetWidth()/2 + 60,ofGetHeight()/2 + 60);
	}
	startButton->render();
}

void MenuState::keyPressed(int key){
	if(key=='i'){
		menuInstructions = !menuInstructions;
	}
}

void MenuState::mousePressed(int x, int y, int button){
	startButton->mousePressed(x, y);
}

void MenuState::reset(){
	setFinished(false);
	setNextState("");
	startButton->reset();
}