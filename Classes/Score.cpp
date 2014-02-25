//
//  Score.cpp
//  SimpleGameRev
//
//  Created by osabe on 2014/02/25.
//
//

#include "Score.h"
#include "cocos2d.h"

USING_NS_CC;

//int Score::calculateHighScore(int score) {
//    
//    int prevHighScore = getHighScore();
//    if (score > prevHighScore) {
//        return score;
//    } else {
//        return prevHighScore;
//    }
//}

void Score::saveScore(int score) {
    saveNumber(SCORE, score);
}

void Score::saveHighScore(int highScore) {
    saveNumber(HIGH_SCORE, highScore);
}

int Score::getScore() {
    return getNumber(SCORE);
}

int Score::getHighScore() {
    return getNumber(HIGH_SCORE);
}

// private methods implementation
void Score::saveNumber(const char * pKey, int number) {
    CCUserDefault* userDefault = CCUserDefault::sharedUserDefault();
    userDefault->setIntegerForKey(pKey, number);
    userDefault->flush();
    
}
int Score::getNumber(const char* pKey) {
    CCUserDefault* userDefault = CCUserDefault::sharedUserDefault();
    int number = userDefault->getIntegerForKey(pKey, 0);
    return number;
}
