#include <fstream>
#include <algorithm>
#include <string>
#include <random>
#include <vector>
#include <iterator>

struct Point
{
    int x;
    int y;
};

std::istream& operator>>(std::istream& stream, Point& point)
{
    stream >> point.x >> point.y;
    return stream;
}

int main()
{
    const std::string inFileName = "inFile";
    const std::string outFileName = "outFile";
    const bool generateInFile = true;
    const int screenSize = 20;

    if (generateInFile)
    {
        const int countPoint = static_cast<int>(screenSize * screenSize / 1.8);

        std::ofstream prepareDataFile(inFileName);

        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, screenSize - 1);

        std::generate_n(std::ostream_iterator<int>(prepareDataFile, " "), countPoint * 2, [&dis, &gen]()
            {   return dis(gen); });
    }

    std::ifstream inFile(inFileName);
    std::ofstream outFile(outFileName);
    if (!inFile || !outFile)
    {
        return -1;
    }
    std::vector<Point> inFileData = { std::istream_iterator<Point>(inFile), std::istream_iterator<Point>() };
    std::vector<std::string> screen{ screenSize, std::string(screenSize, ' ') };
    for (const auto& point : inFileData)
    {
        screen[point.x][point.y] = '*';
    }
    std::copy(screen.begin(), screen.end(), std::ostream_iterator<std::string>(outFile, "\n"));
    return 0;
}