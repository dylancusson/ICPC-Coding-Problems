#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
/*  A culvert is a drain or pipe that allows water to flow under a barrier such as a road. Your job is to find
 *  the diameter of the pipe needed to carry the discharge from rain on a specified area.
 *  Here are the empirical formulas to use:
 *  Q = R × M × c × (S/M)^0.25
 *  and
 *  Q = 3.10 × D^2.31 × H^0.5
 *  Where:
 *  Q is the discharge in cubic feet per second,
 *  R is the maximum rainfall intensity in inches per hour (0.01 ≤ R ≤ 12),
 *  M is the area in acres (0.01 ≤ M ≤ 105),
 *  c is the drainage coefficient of the area (for example: 0.25 for a farming area, 0.75 for a built up business
 *  area with paved streets) (0.2 ≤ c ≤ 0.8),
 *  S is the average slope of the area in feet per 1000 feet (0.1 ≤ S ≤ 1000),
 *  D is the diameter of the pipe in feet, and
 *  H is the minimum head differential of water in feet. That is, the difference in the height of the water
 *  above the inlet of the pipe to the height above the outlet. (0.1 ≤ H ≤ 25)
 *  Culvert pipes come in standard diameters of 12, 15, 18, 21, 24, 30, 36, 42, 48, 54, 60, 66, 72, 75, and 84
 *  inches. There are 12 inches in a foot.
 *  The input is a series of 1 to 25 lines terminated by end of file. Each line has the data for one test case
 *  in this order:
 *  R M c S H
 *  The numbers are separated by spaces. All values are greater than zero.
 *  For each test case, print a line with the diameter in inches of the smallest sized standard culvert pipe
 *  that will carry the flow. Should the flow exactly match the maximum flow of a pipe, use the next highest
 *  size. Should the flow exceed what an 84 inch pipe can carry, print a line containing only the string nonstandard.
*/
void CheckSizes(double D) {
    double const diameter = D;
    vector<int> const sizes = {12, 15, 18, 21, 24, 30, 36, 42,
                         48, 54, 60, 66, 72, 75, 84};
    for (double size : sizes)
    {
        if (diameter < size) {
            cout << size << endl;
            return;
        }
    }
    cout << "non-standard" << endl;
}
int main() {
    // Declare and get variables
    double Q, R, M, c, S, D, H;
    
    while (cin >> R >> M >> c >> S >> H)
    {
        // Calculate Q
        Q = R * M * c * pow((S / M), 0.25);

        // Calculate D in feet

        D = pow(Q / (3.10 * pow(H, 0.5)), 1.0 / 2.31);

        // Convert to inches

        D *= 12.0;

        // Check against size vector
        CheckSizes(D);
    }
}
