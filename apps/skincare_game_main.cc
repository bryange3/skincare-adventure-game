#include "../include/core/game.h"

int main() {
  skincare::Game game("../src/resources/skincare_products.json");
  game.Play();
}