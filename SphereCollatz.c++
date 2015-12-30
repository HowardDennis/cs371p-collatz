#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>

using namespace std;

#define N 1000000
#ifdef N
int cache[N];
#endif

pair<int, int> collatz_read (const string& s) {
    istringstream sin(s);
    int i;
    int j;
    sin >> i >> j;
    return make_pair(i, j);}
    
int collatz_eval (int i, int j) {
    assert(i > 0 && j > 0 && i < 1000000 && j < 1000000);
    int min, max, ret = 0;
    if (i > j) {
        min = j;
        max = i;}
    else {
        min = i;
        max = j;}
    int r = (max/2) + 1;
    if (min < r) {
        min = r;}
    int n = min;
    
    while (n <= max) {
        int tmp = 1;
        #ifdef N
        if ((n < N) && (cache[n] != 0)) {
            tmp = cache[n];
        }
        #endif
        else {
            int m = n;
            while (m > 1) {
                if (m % 2 == 0) {
                    m /= 2;
                    ++tmp;}
                else {
                    m = m + (m >> 1) + 1;
                    tmp += 2;}
            }}
        #ifdef N
        if(n < N) {
            cache[n] = tmp;}
        #endif
        if (tmp > ret) {
            ret = tmp;}
        ++n;}
    assert (ret > 0);
    return ret;}
    
void collatz_print (ostream& w, int i, int j, int v) {
    w << i << " " << j << " " << v << endl;}
    
void collatz_solve (istream& r, ostream& w) {
    string s;
    while (getline(r, s)) {
        const pair<int, int> p = collatz_read(s);
        const int            i = p.first;
        const int            j = p.second;
        const int            v = collatz_eval(i, j);
        collatz_print(w, i, j, v);}}
        
int main () {
    using namespace std;
    collatz_solve(cin, cout);
    return 0;}
