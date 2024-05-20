#include <iostream>
#include <cmath>
using namespace std;
class Circle {
private:
    double x; // координата x центра окружности
    double y; // координата y центра окружности
    double radius; // радиус окружности
    double PI = 3.14;

public:
    Circle(double center_x, double center_y, double r) : x(center_x), y(center_y), radius(r) {
        if (radius <= 0) {
            cerr << "Error: Radius must be greater than zero." << endl;
            exit(1);
        }
    }

    double getArea() {
        return PI * radius * radius;
    }

    double getCircumference() {
        return 2 * PI * radius;
    }

    double getX() {
        return x;
    }

    double getY() {
        return y;
    }

    double getRadius() {
        return radius;
    }
};

int main() {
    const int NUM_CIRCLES = 3;
    Circle circles[NUM_CIRCLES] = {
        Circle(0, 0, 5),
        Circle(2, 2, 3),
        Circle(-1, -1, 4)
    };

    // a) Группы окружностей, центры которых лежат на одной прямой
    for (int i = 0; i < NUM_CIRCLES; ++i) {
        for (int j = i + 1; j < NUM_CIRCLES; ++j) {
            if (circles[i].getX() == circles[j].getX() && circles[i].getY() == circles[j].getY()) {
                cout << "Circles with centers on the same line: (" << circles[i].getX() << ", " << circles[i].getY() << ")" << endl;
            }
        }
    }

    // b) Наибольший и наименьший по площади объект
    double maxArea = 0;
    double minArea = numeric_limits<double>::max();
    Circle maxAreaCircle = circles[0];
    Circle minAreaCircle = circles[0];

    for (int i = 0; i < NUM_CIRCLES; ++i) {
        double area = circles[i].getArea();
        if (area > maxArea) {
            maxArea = area;
            maxAreaCircle = circles[i];
        }
        if (area < minArea) {
            minArea = area;
            minAreaCircle = circles[i];
        }
    }

    cout << "Circle with the largest area: Center(" << maxAreaCircle.getX() << ", " << maxAreaCircle.getY() << "), Radius: " << maxAreaCircle.getRadius() << endl;
    cout << "Circle with the smallest area: Center(" << minAreaCircle.getX() << ", " << minAreaCircle.getY() << "), Radius: " << minAreaCircle.getRadius() << endl;

    return 0;
}
