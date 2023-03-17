#include <iostream>
#include<cstring>
#include<cmath>
#include "Book.cpp"

using namespace std;

class Exp{
    char x[22];
    int s;
    public:

        void setX(char* x) {
            strcpy(this->x, x);
        }
};

int main()
{
    Exp a;


    return 0;
}
