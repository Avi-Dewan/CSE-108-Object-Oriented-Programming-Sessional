#include <iostream>
#include <cstring>

using namespace std;

namespace infrastructure {
    class pool {
        int height, width, depth;
        char painted_color[10];
    public:
        void set_properties(int h, int w, int d, char *pc) {
            height = h;
            width = w;
            depth = d;
            strcpy(painted_color, pc);
        }
        void show() {
            cout << "Dimention: " << height*width*depth << endl;
            cout << "Color: " << painted_color << endl;
        }
    };
}

namespace sports {
    class pool {
        char table_ingredient[20];
        char table_color[10];
    public:
        void set_properties(char *ti, char* tc) {
            strcpy(table_ingredient, ti);
            strcpy(table_color, tc);
        }
        void show() {
            cout << "Table ingredient: " << table_ingredient << endl;
            cout << "Table color: " << table_color;
        }
    };
}

int main()
{
    infrastructure::pool inPool;
    sports::pool spPool;

    inPool.set_properties(1, 2, 3, "Blue");
    spPool.set_properties("Board", "Gray");

    inPool.show();
    spPool.show();
    return 0;
}
