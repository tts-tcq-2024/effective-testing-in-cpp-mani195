#include <iostream>
#include <vector>
#include <assert.h>

const std::vector<std::string> majorColors = {"White", "Red", "Black", "Yellow", "Violet"};
const std::vector<std::string> minorColors = {"Blue", "Orange", "Green", "Brown", "Slate"};

std::pair<std::string, std::string> testNumberToPair(int pairNumber, const std::vector<std::string> majorColors, const std::vector<std::string> minorColors)
{
    int zeroBasedPairNumber = pairNumber - 1;
    return {majorColors.at(zeroBasedPairNumber / minorColors.size()), minorColors.at(zeroBasedPairNumber %  minorColors.size())};
}

std::string getColorCodePair(int pairNumber, const std::vector<std::string> majorColors, const std::vector<std::string> minorColors)
{
     std::pair<std::string, std::string> colorPair = testNumberToPair(pairNumber, majorColors, minorColors);
     std::string colorCodePair = std::to_string(pairNumber) + " | ";
     colorCodePair += colorPair.first + " | ";
     colorCodePair += colorPair.second;
     return colorCodePair;
}

void printColorMap()
{
    for(int i = 1; i <= 25; i++) 
    {
        std::cout << getColorCodePair(i, majorColors, minorColors) << '\n';
    }
}

int main() 
{
    printColorMap();
    assert(getColorCodePair(7, majorColors, minorColors) == "7 | Red | Orange");
    assert(getColorCodePair(16, majorColors, minorColors) == "16 | Yellow | Blue");
    assert(getColorCodePair(24, majorColors, minorColors) == "24 | Violet | Slate");
    std::cout << "All is well (maybe!)\n";
    return 0;
}
