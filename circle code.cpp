#include <iostream>
#include <vector>

void drawCircle(double x, double y, int radius) {
    // Draw a circle
    std::vector <int> circleX;
    std::vector <int> circleY;
    for (int i = 0; i <= 360; i += 1) {
        double radians = i * 3.1415926535 / 180.0;
        circleX.push_back(static_cast<int>(x + radius * std::cos(radians)));
        circleY.push_back(static_cast<int>(y + radius * std::sin(radians)));
    }

    std::vector <std::vector<int>> pairs;
    pairs.push_back(circleX);
    pairs.push_back(circleY);

    for (int i = 0; i <= 100; i++) {
        for (int j = 0; j <= 100; j++) {
            int n = 0;
            for (int k = 0; k < circleX.size(); k++) {
                if (pairs[0][k] == j && pairs[1][k] == i && n == 0){
                    std::cout << "*";
                    n = 1;
                }
            }
            if (n == 0) {
                std::cout << " ";
            }
        }
        std::cout << "\n";
    }
}


int main(int argc, const char * argv[]) {
    std::system("clear");
    double x = 20;
    double y = 20;
    double z = 5;
    drawCircle(x, y, z);
    return 0; //computer screen is 204 pixels wide
}
