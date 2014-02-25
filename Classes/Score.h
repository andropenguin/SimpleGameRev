//
//  Score.h
//  SimpleGameRev
//
//  Created by osabe on 2014/02/25.
//
//

#ifndef __SimpleGameRev__Score__
#define __SimpleGameRev__Score__

#include <string>

class Score {
public:
#define SCORE "score"
#define HIGH_SCORE "highScore"
    
//    static int calculateHighScore(int score);
    static void saveScore(int score);
    static void saveHighScore(int score);
    static int getScore();
    static int getHighScore();
    
private:
    static void saveNumber(const char * pKey, int number);
    static int getNumber(const char* pKey);
};

#endif /* defined(__SimpleGameRev__Score__) */
