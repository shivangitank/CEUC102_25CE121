#include<iostream>
using namespace std;

class rectangle
{
    double length;
    double width;
    double calcarea;
    double calcperimeter;

public:
    void input();
    double area();
    double perimeter();
    void display();
};

void rectangle::input()
{
    cout<<"Enter length of rectangle: ";
    cin>>length;

    cout<<"Enter width of rectangle: ";
    cin>>width;
}

double rectangle::area()
{
    calcarea = length * width;
    return calcarea;
}

double rectangle::perimeter()
{
    calcperimeter = 2 * (length + width);
    return calcperimeter;
}

void rectangle::display()
{
    cout<<"Area: "<<calcarea<<endl;
    cout<<"Perimeter: "<<calcperimeter<<endl;
}

int main()
{
    int n;

    cout<<"How many rectangles? ";
    cin>>n;

    rectangle rect[n];

    for(int i=0;i<n;i++)
    {
        cout<<"\nRectangle "<<i+1<<endl;
        rect[i].input();
        rect[i].area();
        rect[i].perimeter();
        rect[i].display();
    }

    return 0;
}
