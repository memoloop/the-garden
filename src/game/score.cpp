#include "score.h"

Score::Score() 
{

}

Score::~Score()
{

}

// Save the scores in 'saving/saving1.data'
void Score::save()
{
    std::ofstream file("saving/saving1.data");
    file << "numberSeeds: " << numberSeeds << std::endl;
    file << "numberWheat: " << numberWheat << std::endl;
    file << "numberMoney: " << numberMoney << std::endl;
    file.close();
}

// Load the saving from 'saving/saving1.data'
void Score::load()
{
    // Open file
    std::ifstream file("saving/saving1.data");
    std::string line;
    // List of value (there are 3 value)
    int valueList[3];
    int lineNumber = 0;
    // Read line in opened file
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
    // For each value in valueList into public var accessible in the class
    numberSeeds = valueList[0];
    numberWheat = valueList[1];
    numberMoney = valueList[2];
}