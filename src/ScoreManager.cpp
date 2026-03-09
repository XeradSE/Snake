#include "./../include/ScoreManager.hpp"
#include <fstream>
#include <stdexcept>
#include <string>

void ScoreManager::saveHighScore(int score) {
    std::ofstream file("./../data/high_score.txt");
    if (!file.is_open()) throw std::runtime_error("Error saving the high score.");
    file << score;
}

int ScoreManager::loadHighScore() {
    std::ifstream file;
    file.open("./../data/high_score.txt");
    if (!file.is_open()) {
        return 0;
    }
    std::string score;
    file >> score;
    return std::stoi(score);
}