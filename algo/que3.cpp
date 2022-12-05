#include <cmath>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::pow;


long Multiply(int x, int y, int n){
    /*
    n : size of the number
    */
    //base condition
    if (n == 1) {
        return x*y;

    }
    int a1 = x / int(pow(10, n/2)); // first half
    int a2 = x % int(pow(10, n/2)); // remaining

    int b1 = y / int(pow(10, n/2)); // first half
    int b2 = y % int(pow(10, n/2)); // remaining

    long A = Multiply(a1, b1, n/2);
    long B = Multiply(a2, b2, n/2);
    long C = Multiply(a1+a2, b1+b2, n/2);

    //derived formula using divide and conquer
    return (a1*b1)*pow(10,n) + (C-A-B)*int(pow(10,n/2)) + B;
}

int size(int x){
    if (x == 0)
    {
        return 1;
    }
    int count = 0;
    while (x!=0){
        count++;
        x = x/10;
    }

    return count;
}

int main ()
{
    int x, y, s;

    cout << "Number 1 : " << endl;
    cin >> x;
    cout << "Number 2 : " << endl;
    cin >> y;

    s = (x>y)?size(x):size(y); // Choose the biggest number to find the size

    cout << Multiply(x, y, s) << endl;

    return 0;
}
