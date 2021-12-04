// Travis Schauer
// 9/25/20 revised on 9/28/20
// Kramer 3700
// This program uses a Point class and Faction class to determine if people are 
// safe from cops/robbers

#include <iostream>
#include <vector>
#include "fraction.h"
#include "point.h"

using namespace std;

Fraction doesTurn(Point a, Point b, Point c){
    Fraction d;
    // left if d>0, d<0 then right, collinerar if d = 0 

    /*
    cout << "a; " << a << endl;
    cout << "b; " << b << endl;
    cout << "c: " << c << endl;
    cout << "b-a: " << b-a << endl;
    cout << "c-a: " << c-a << endl;
    */

    d = (b-a)*(c-a);
    
    //cout << "d: " << d << endl;

    return d;
}

void bubbleSort(Point array[], int size){
    for (int i = 0; i < size - 1; i++){
        for (int j = size - 1; j > 0; j--){
            if (array[j] < array[j - 1]){

                //cout << "in bubbleSort" << endl;
                
                Point temp = array[j - 1];
                array[j - 1] = array[j];
                array[j] = temp;
            }
        }
    }
}


void findHull(Point array[], int k, Point hull[], int &nHull){
    Point lower[100], upper[100];
    int t, u;

    //cout << "in findHull" << endl;

    bubbleSort(array, k);

    lower[0] = array[0];
    t = 0;

    for (int i = 1; i <= k - 1; i++){
        while (t > 0 && doesTurn(lower[t - 1], lower[t], array[i]) <= 0){
            t = t - 1;
            //cout << "first not left" << endl;
        }

        t = t + 1;
        lower[t] = array[i];
    }

    upper[0] = array[k - 1];
    u = 0;

    for (int i = k - 2; i >= 0; i--){
        while ( u > 0 && doesTurn(upper[u - 1], upper[u], array[i]) <= 0){
            u = u - 1;
            //cout << "second not left" << endl;
        }

        u = u + 1;
        upper[u] = array[i];
    }

    nHull = 0;
    for (int i=0; i<t; i++){
        hull[nHull] = lower[i];
        nHull++;
    }
    for (int i=0; i<u; i++){
        hull[nHull] = upper[i];
        nHull++;
    }
}

bool isInsideHull(Point P, Point Hull[], int k){
    //cout << "is inside" << endl;

    for(int i = 0; i <= k - 1; i++){
        int j = (i + 1)%(k);

        if (doesTurn(P, Hull[i], Hull[j]) < 0){
            return false;
        }
    }

    return true;
}

int main() {
    int c, r, o, oSafe = 0, oRobbed = 0, oDanger = 0;
    int copHullSize, robHullSize;
    Point temp;
    Point cArray[100], rArray[100], oArray[100];
    Point copHull[100], robHull[100];

    // input
    // determine cop (c), robber (r), and number of people (o)
    cout << "Enter # of cops, robbers, then people." << endl;
    cin >> c >> r >> o;

    // 3 <= c <= 100, 3 <= r <= 100 and o >= 1

    if (o < 1){
        cout << "Enter # of people >= 1: " << endl;
        cin >> o;
    } else if (c < 3 || c > 100){
        cout << "Enter # of cops >=3 but <= 100: " << endl;
        cin >> c;
    } else if (r < 3 || r > 100){
        cout << "Enter # robbers >=3 but <= 100: "<< endl;
        cin >> r;
    }

    // number of lines per type
    // cops
    cout << "\nEnter points for cops:" << endl;
    for (int i=0; i < c; i++){
        cin >> temp;
        cArray[i] = temp;
    }

    // robbers
    cout << "\nEnter points for robbers:" << endl;
    for (int i=0; i < r; i++){
        cin >> temp;
        rArray[i] = temp;
    }

    // people
    cout << "\nEnter points for people:" << endl;
    for (int i=0; i < o; i++){
        cin >> temp;
        oArray[i] = temp;
    }

    // find hulls
    findHull(cArray, c, copHull, copHullSize);
    findHull(rArray, r, robHull, robHullSize);

    /*
    // hulls output
    cout << "\n Cop Hull:" << endl;
    for (int i=0; i<copHullSize; i++){
        Point p;
        p = copHull[i];
        cout << p << " ";
    }

    cout << "\n Robber Hull:" << endl;
    for (int i=0; i<robHullSize; i++){
        Point p;
        p = robHull[i];
        cout << p << " ";
    }
    */

    // safety
    for (int i=0; i<o; i++){
        Point person;
        person = oArray[i];

        if (isInsideHull(person, copHull, copHullSize) == 1){
            oSafe++;
        } else if (isInsideHull(person, robHull, robHullSize) == 1){
            oRobbed++;
        } else {
            oDanger++;
        }
    }

    // output
    // safe people (s)
    cout << "\nSafe: " << oSafe << endl;
    
    // robbed people (t), 
    cout << "Robbed: " << oRobbed << endl;

    // danger people (d)
    cout << "In danger: " << oDanger << endl;

    return 0;
}
