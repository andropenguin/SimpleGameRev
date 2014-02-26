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
// define the keys of the preference.
#define SCORE "score"
#define HIGH_SCORE "highScore"
    // save the max of scores in playing this game from tapping the start button
    // until tapping the return button.
    static void saveScore(int score);
    
    // save the high score which means to be the max of the scores from installing
    // and palying this application.
    static void saveHighScore(int score);
    
    // get the score.
    static int getScore();
    
    // get the high score.
    static int getHighScore();
    
private:
    // save the number by the key of which pointer is pKey to the preference.
    static void saveNumber(const char * pKey, int number);
    
    // get the number by the key of which pointer is pKey from the preference.
    static int getNumber(const char* pKey);
};

#endif /* defined(__SimpleGameRev__Score__) */
