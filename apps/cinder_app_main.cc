//
// Created by Bryan Ge on 11/14/20.
//

#include <visualizer/skincare_game_app.h>

using skincare::visualizer::SkincareGameApp;

void prepareSettings(SkincareGameApp::Settings *settings) {
  settings->setResizable(false);
  settings->setTitle("Choose Your Skincare!");
}

CINDER_APP(SkincareGameApp, ci::app::RendererGl, prepareSettings);