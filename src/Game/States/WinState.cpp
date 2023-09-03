#include "State.h"
#include "WinState.h"


WinState::WinState(){
    string text="Back to menu.";
    ToMenu=new Button((ofGetWidth()/2 - text.length()*8), ofGetHeight() - 300, text.length()*16, 50, text);
	img1.load("images/WIN.png");
}

void WinState::tick(){
    ToMenu->tick();
	if(ToMenu->wasPressed()){
		setNextState("Menu");
		setFinished(true);
	}
}

void WinState::render(){
	ofSetColor(255);
	img1.draw(0,0);
	ToMenu->render();
}

void WinState::keyPressed(int key){
}

void WinState::mousePressed(int x, int y, int button){
	ToMenu->mousePressed(x, y);
}

void WinState::reset(){
	setFinished(false);
	setNextState("");
	ToMenu->reset();
}