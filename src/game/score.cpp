#include "score.h"

void Score::save()
{
    std::ofstream file("saving/saving1.data");
    file << "numberSeeds: " << numberSeeds << std::endl;
    file << "numberWheat: " << numberWheat << std::endl;
    file.close();
}

void Score::load()
{
    std::ifstream file("saving/saving1.data");
    std::string line;
    int valueList[2];
    int lineNumber = 0;
    while(std::getline(file, line))
    {
        if(line == "")
            continue;
        
        int pos = line.find(": ");
        std::string strValue = line.substr(pos+2);
        int value = std::stoi(strValue);
        valueList[lineNumber] = value;
        lineNumber++;
    }
    numberSeeds = valueList[0];
    numberWheat = valueList[1];
}