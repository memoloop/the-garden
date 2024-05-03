#ifndef SCORE_H
#define SCORE_H

#include <iostream>
#include <string>
#include <fstream>

class Score
{
    public:
    int numberSeeds;
    int numberWheat;
    void save();
    void load();
};

#endif