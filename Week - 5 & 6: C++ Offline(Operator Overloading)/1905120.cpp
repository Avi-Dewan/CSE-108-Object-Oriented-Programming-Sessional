#include<iostream>
#include<cstring>
using namespace std;

class Vector
{
    char *name;
    int x,y,z;
public:
    Vector(char *n)
    {
        int l = strlen(n);
        name = new char[l+1];
        strcpy(name,n);
        x=0;
        y=0;
        z=0;
    }
    Vector(char *n, int a, int b, int c)
    {
        int l = strlen(n);
        name = new char[l+1];
        strcpy(name,n);
        x=a;
        y=b;
        z=c;
    }

    Vector(const Vector &n) {
        int l = strlen(n.name);
        name = new char[l+1];
        strcpy(name, n.name);
        x = n.x;
        y = n.y;
        z = n.z;
    }

    int setX(int a){x=a;}
    int setY(int b){y=b;}
    int setZ(int c){z=c;}

    void setName(char *n)
    {
        int l = strlen(n);
        name = new char[l+1];
        strcpy(name,n);
    }

    int getX(){return x;}
    int getY(){return y;}
    int getZ(){return z;}

    char *getName(){return name;}

    ~Vector()
    {
        delete []name;
    }

    void print() {
        cout << name << ": " << x << "x";
        if(y >= 0) cout << "+";
        cout << y << "y";
        if(z >= 0) cout << "+";
        cout << z << "z" << endl;
    }

    Vector operator^(Vector v2);
    int operator==(Vector v2);
    Vector &operator=(Vector v2);
    Vector operator*(int m);
    Vector operator*(Vector v2);
    friend Vector operator*(int m, Vector v2);
};

    Vector Vector::operator^(Vector v2) {
        Vector temp("");
        temp.x = y*v2.z - z*v2.y;
        temp.y = z*v2.x - x*v2.z;
        temp.z = x*v2.y - y*v2.x;

        return temp;
    }

    int Vector::operator==(Vector v2) {
        if(x == v2.x && y == v2.y && z == v2.z)
            return 1;

        return 0;
    }

    Vector &Vector::operator=(Vector v2) {

        x = v2.x;
        y = v2.y;
        z = v2.z;

        return *this;
    }

    Vector Vector::operator*(int m) {
        Vector temp("");

        temp.x = x*m;
        temp.y = y*m;
        temp.z = z*m;

        return temp;
    }

    Vector Vector::operator*(Vector v2) {
        Vector temp("");
        temp.x = x*v2.x;
        temp.y = y*v2.y;
        temp.z = z*v2.z;

        return temp;
    }


    Vector operator*(int m, Vector v2) {
        Vector temp("");

        temp.x = m*v2.x;
        temp.y = m*v2.y;
        temp.z = m*v2.z;

        return temp;
    }



int main()
{
    Vector v1("v1", 1,2,3), v2("v2", 4, 5, -6), v3("Result1"),v4("Result2",-27,18,-3);

    v1.print();     ///Print the components of vector v1
    v2.print();     ///Print the components of vector v2

    v3=v1^v2;       ///Calculate the cross product of vector v1 and vector v2 (Consider ^ as cross product for this assignment)
    v3.print();     ///Print the modified components of vector v3 (Name: Result1)

    if(v3==v4)      ///Check for equality; if two vectors contain equal component values (x, y, z), then they are equal.
        cout<<"Vectors are equal"<<endl;
    else
        cout<<"Vectors are not equal"<<endl;

    v1= v1*2;       ///Multiply each component of vector v1 with the given value
    v1.print();     ///Print the modified components of vector v1

    v2=2*v2;        ///Multiply each component of vector v2 with the given value
    v2.print();     ///Print the modified components of vector v2

    v3=v1*v2;       ///Multiply each component of vector v1 with the corresponding component of vector v2.
    v3.print();     ///Print the modified components of vector v3 (Name: Result1)

    if(v3==v4)      ///Check for equality; if two vectors contain equal component values (x, y, z), then they are equal.
        cout<<"Vectors are equal"<<endl;
    else
        cout<<"Vectors are not equal"<<endl;

    return 0;
}
