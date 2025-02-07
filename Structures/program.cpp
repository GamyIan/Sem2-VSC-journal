#include <iostream>
#include <string>

using namespace std;

struct Rectangle
{
    int width, height, area;
    Rectangle(int w, int h)
    {
        width =w;
        height = h;
    }
    void areaOfRectangle()
    {
        area=width*height;
    }
};

int main()
{
    struct Rectangle rec=Rectangle(4,6);
    rec.areaOfRectangle();
    cout << "Area: " << rec.area << endl;
    return 0;
}
