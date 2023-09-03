#include "ofApp.h"

bool Player::Konami_song=false;

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetWindowTitle("Magi Burger");
	//States
	menuState = new MenuState();
	gameState = new GameState();
	loseState = new LoseState();
	winState = new WinState();

	// Initial State
	currentState = menuState;

	// Sound
	sound.load("GameSong.wav");
	sound.setLoop(true);
	sound.play();

}

//--------------------------------------------------------------
void ofApp::update(){
	if(Player::Konami_mode && !Player::Konami_song){
		sound.load("KonamiSong.wav");
		sound.setLoop(true);
		sound.play();
		Player::Konami_song=true;
	}else if((!Player::Konami_mode && Player::Konami_song) || (currentState != loseState && !sound.isPlaying())){
		sound.load("GameSong.wav");
		sound.setLoop(true);
		sound.play();
		Player::Konami_song=false;
	}else if(currentState == loseState && !loseLoaded){
		sound.load("LoseSound.wav");
		sound.setLoop(false);
		sound.play();
		loseLoaded=true;
	}

	if (currentState != nullptr){
		currentState->tick();
		if(currentState->hasFinished()){
			if(currentState->getNextState() == "Menu"){
				menuState = new MenuState();
				currentState = menuState;
			}else if(currentState->getNextState() == "Game"){
				gameState = new GameState();
				currentState = gameState;
			}else if(currentState->getNextState() == "Lose"){
				loseState = new LoseState();
				currentState = loseState;
			}else if(currentState->getNextState() == "Win"){
				winState = new WinState();
				currentState = winState;
			}
			currentState->reset();
		}
	}		
}

//--------------------------------------------------------------
void ofApp::draw(){
	if (currentState != nullptr)
		currentState->render();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (currentState != nullptr)
		currentState->keyPressed(key);

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	if (currentState != nullptr)
			currentState->keyReleased(key);
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
	if (currentState != nullptr)
		currentState->mouseMoved(x, y);
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	if (currentState != nullptr)
		currentState->mouseDragged(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	if (currentState != nullptr)
		currentState->mousePressed(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	if (currentState != nullptr)
		currentState->mouseReleased(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
	if (currentState != nullptr)
			currentState->mouseEntered(x, y);
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
	if (currentState != nullptr)
		currentState->mouseExited(x, y);
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
	if (currentState != nullptr)
			currentState->windowResized(w, h);
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
	if (currentState != nullptr)
		currentState->gotMessage(msg);
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 
	if (currentState != nullptr)
		currentState->dragEvent(dragInfo);
}
