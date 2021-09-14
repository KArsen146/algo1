#include <iostream>
using namespace std;
float a = 1.84;
float b = -0.15;
float c = -1.98;
float d = 2.58;

float x(float t)
{
    return t*t*t - a *t;
}

float y(float t)
{
    return b * t * t * t + c * t * t + d * t;
}
int main() {
    float t1, t2, t3;
    t1 = 0.783156;
    t2 = 5.009324;
    t3 = 0.9079999;
    cout <<'(' << x(t1) << ';'<<y(t1) << ')' <<endl;
    cout << '('<<x(-t1) <<' '<< y(-t1)<< ')' << endl;
    cout <<'('<< x(float(-66)/15 +t2) <<';'<< y(float(-66)/15 +t2)<< ')' << endl;
    cout <<'('<< x(float(-66)/15 -t2) <<';'<< y(float(-66)/15 -t2) << ')'<< endl;
    cout << '('<<x(float(32)/55 +t3) << ';'<<y(float(32)/55 +t3) << ')'<< endl;
    cout <<'('<< x(float(32)/55 -t3) <<';'<< y(float(32)/55 -t3) << ')' << endl;
    return 0;
}