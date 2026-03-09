#include "./../include/ScoreManager.hpp"
#include <fstream>
#include <stdexcept>
#include <string>
#include <filesystem>

void ScoreManager::saveHighScore(int score) {
    std::filesystem::path dirPath("./../data");
    if (!std::filesystem::exists(dirPath)) {
        std::filesystem::create_directories(dirPath);
    } 
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