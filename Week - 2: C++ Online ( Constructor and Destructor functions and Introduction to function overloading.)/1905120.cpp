#include<iostream>
#include <cstdio>

using namespace std;

class Random{

        int **mat = NULL;
        int mini, maxi, row, col;

    public:
        Random(int r, int c, int mx, int mn );

        void print();
        void randomize();


        int get(int i, int j) {
            return mat[i][j];
        }

        void add(int n) {
              for(int i = 0; i < row; i++) {
                for(int j = 0; j < col; j++) {
                    mat[i][j] += n;
                }
            }
        }

        int add() {
            int sum = 0;
            for(int i = 0; i < row; i++) {
                for(int j = 0; j < col; j++) {
                    sum += mat[i][j];
                }
            }

            return sum;
        }

        ~Random() {
            for(int i = 0; i < row; i++){
                free(mat[i]);
            }

            free(mat);
        }


};

Random::Random(int r, int c, int mn, int mx) {
    row = r;
    col = c;
    maxi = mx;
    mini = mn;

    mat = (int**) malloc(r*sizeof(int*));

    for(int i = 0; i < r; i++) {
        mat[i] = (int*)malloc(col*sizeof(int));
    }

}

void Random::print() {
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            cout << mat[i][j] << " ";
        }

    cout<< endl;
    }
}

void Random::randomize() {
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                mat[i][j] = mini + rand() % (maxi - mini);
            }
        }
}


int main()
{
    cout<<"Hello World"<<'\n';

    Random m(3,3,100,200);

    m.randomize();
    m.print();

    cout<<m.get(0,0)<<'\n';

    m.add(100);
    m.print();

    cout<<m.add()<<'\n';

    return 0;
}

