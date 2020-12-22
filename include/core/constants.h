//
// Created by Bryan Ge on 11/29/20.
//

#pragma once

#include <string>

// game step labels
const std::string kGameStepGetPlayerName = "get player name";
const std::string kGameStepGameIntro = "game intro";
const std::string kGameStepChooseProduct = "choose product";
const std::string kGameStepFinal = "final";
const std::string kGameStepGameEnd = "game end";

// introduction messages
const std::string kWelcomePlayer = "Welcome to your vanity! It's been "
    + std::string("a long day and now it's time to get through your skincare")
    + " routine. First off, what is your name? ";
const std::string kGameExplanationStart = "Hello ";
const std::string kGameExplanationEnd = "! The objective of this"
    + std::string(" game is to select the best products at ")
    + "each step of your skincare routine.\n"
    + "Each product is worth a certain number of points. "
    + "Try to get as many points as possible!\n"
    + "At each step of the game, type out the routine or product "
    + "std::string(""you would like to choose."
    + "Good luck and have fun!\n\n";

// routine messages
const std::string kInvalidRoutine = "The routine you typed is invalid. Please "
    + std::string("try again.\n\n");
const std::string kRoutineIntro = "Here are the skincare routines you can "
    + std::string("choose from:\n");
const std::string kPromptForRoutine = "Select which routine you would like to "
    + std::string("do tonight: ");
const std::string kNiceRoutine = "Nice choice! Let's do the ";

// product messages
const std::string kEarnedStart = "You have earned ";
const std::string kEarnedEnd = " points.\n\n";
const std::string kCurrentScoreIntro = "CURRENT SCORE: ";
const std::string kProductIntroStart = "Here are the ";
const std::string kProductIntroEnd = "s available for you:\n";
const std::string kPromptForProducts = "\nSelect which product you would like "
    + std::string("to use: ");
const std::string kInvalidProduct = "The product you selected is invalid. "
    + std::string("Please try again.\n\n");

// product selection responses
const std::string kGoodProduct = "good product";
const std::string kBadProduct = "bad product";
const std::string kNoSelection = "no selection";

// game end messages
const std::string kOutroStart = "Nice, you have finished selecting your "
    + std::string("products! Your final score is ");
const std::string kOutroEnd = "!\nThanks for playing! See you next time.\n";

// audio labels
const std::string kAudioGameLose = "game lose audio";
const std::string kAudioGameWin = "game win audio";