#ifndef SCORE_H
#define SCORE_H

#include <iostream>
#include <string>
#include <fstream>

class Score
{
    public:
    // Constructor and Destructor not need
    Score();
    ~Score();
    // Var that contain the score saved in 'saving/saving1.data'
    int numberSeeds;
    int numberWheat;
    int numberMoney;
    // Save the score in 'saving/saving1.data'
    void save();
    // Load the score from 'saving/saving1.data'
    void load();
};

#endif