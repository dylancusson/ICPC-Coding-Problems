/*  @author[Dylan Cusson](https://github.com/dylancusson)
    @brief Problem 10, "Xylophone", from SoCal Regional ICPC 2022
    @details
    A xylophone is a musical instrument made of wooden bars, each of which makes a specific pitch when
    struck with a mallet. The wooden bars must have contiguous integer lengths from the longest to the shortest,
    without duplicates. In other words, every bar except for the rightmost one must have a length exactly 1
    longer than the one immediately to its right. For example, a xylophone may have bars of lengths [7, 6, 5, 4]
    or [10, 9, 8], but not [7, 5, 4] nor [3, 3, 2, 1].

    You already have 3 wooden bars of different lengths, and want to create a xylophone using all of them.
    You may not cut the bars or alter them in any way, but you may buy additional wooden bars as necessary.
    The cost of buying a wooden bar is equal to its length. Find the minimum cost to build a xylophone.

    The input contains a single line with three space-separated integers, denoting the lengths of the wooden
    bars you already have. Each integer is between 1 and 5000, inclusive. You are guaranteed that the three
    integers are distinct.

    Your program must output a single integer that represents the minimum cost to make a xylophone using
    all three given wooden bars.
    */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    //Get our bar lengths
    int b1, b2, b3;
    cin >> b1 >> b2 >> b3;

    //Put them in a vector and sort it
    vector<int> bars = { b1, b2, b3 };
    sort(bars.begin(), bars.end());

    //Find our costs for the inbetween bars
    int cost = 0;

    for (int i = bars.at(0) + 1; i < bars.at(2); ++i) {
        if (i != bars.at(1) && i != bars.at(2)) {
            cost += i;
        }
    }

    cout << cost;

}
