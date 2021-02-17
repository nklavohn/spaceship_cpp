#include "GameScreen.h"

GameScreen::GameScreen(int w, int h) : Screen(w, h) {
	color = Color::RED;
}

GameScreen::~GameScreen() {

}

void GameScreen::Update() {
	
}

void GameScreen::Render() {
	BeginRender();

	EndRender();
}

Screen* GameScreen::Clone() {
	return new GameScreen(*this);
}