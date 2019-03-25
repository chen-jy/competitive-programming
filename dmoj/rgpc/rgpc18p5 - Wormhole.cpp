// An accepted solution to P6 - Wormhole
// O(X*Y^2*Z^2*W^2) - complete (RuAr)
#include <bits/stdc++.h>
#define XX (X<<1)
#define YY (Y<<1)
#define ZZ (Z<<1)
#define WW (W<<1)
#define LIM XX*YY*ZZ*WW
using namespace std;

int numPeople, X, Y, Z, W;
// Stores tax estimates
// Dimensions are doubled in order to simulate torus
long long people[22][43][43][43], maxSum = LLONG_MIN;


int main(){
    scanf("%d%d%d%d", &X, &Y, &Z, &W);
    for(int a = 1; a <= W; a++) for(int b = 1; b <= Z; b++)
        for(int c = 1; c <= Y; c++) for(int d = 1; d <= X; d++){
            scanf("%lld", &people[a][b][c][d]);
            // Loop through all possible "subsequences" of 3 "bits"
            // to duplicate the tensor to a total of 8.
            // We don't have to duplicate along the 4th dimension.
            for(int addZ = 0; addZ <= 1; addZ++)
                for(int addY = 0; addY <= 1; addY++)
                    for(int addX = 0; addX <= 1; addX++)
                        people[a][b + addZ*Z][c + addY*Y][d + addX*X] = people[a][b][c][d];
        }

    // Construct the 3D prefix sum array along 3 dimensions,
    // for each cell in the hyperrectangle
    for(int a = 1; a <= W; a++) for(int b = 1; b <= ZZ; b++)
        for(int c = 1; c <= YY; c++) for(int d = 1; d <= XX; d++){
            people[a][b][c][d] += people[a][b-1][c][d] + people[a][b][c-1][d] + people[a][b][c][d-1] -
                                 (people[a][b-1][c-1][d] + people[a][b][c-1][d-1] + people[a][b-1][c][d-1]) +
                                 people[a][b-1][c-1][d-1];
        }

    // The 6 for loops establish a 3D subtensor that is then swept through the 4th dimension
    for(int a1 = 1; a1 <= Z; a1++) for(int a2 = a1; a2 < a1 + Z; a2++)
        for(int b1 = 1; b1 <= Y; b1++) for(int b2 = b1; b2 < b1 + Y; b2++)
            for(int c1 = 1; c1 <= X; c1++) for(int c2 = c1; c2 < c1 + X; c2++){
                long long total, curmin, curmax, colmax, colmin;
                total = curmin = colmin = curmax = colmax = people[1][a2][b2][c2] -
                                                                (people[1][a1-1][b2][c2] + people[1][a2][b1-1][c2] + people[1][a2][b2][c1-1]) +
                                                                (people[1][a1-1][b1-1][c2] + people[1][a1-1][b2][c1-1] + people[1][a2][b1-1][c1-1]) -
                                                                people[1][a1-1][b1-1][c1-1];
                int stmintemp, edmintemp, stmaxtemp, edmaxtemp, stminfinal, edminfinal, stmaxfinal, edmaxfinal;
                stmintemp = edmintemp = stmaxtemp = edmaxtemp = stminfinal = edminfinal = stmaxfinal = edmaxfinal = 1;
                // Subtensor sweep down the longest dimension
                for(int d = 2; d <= W; d++){
                    long long row = people[d][a2][b2][c2] -
                                (people[d][a1-1][b2][c2] + people[d][a2][b1-1][c2] + people[d][a2][b2][c1-1]) +
                                (people[d][a1-1][b1-1][c2] + people[d][a1-1][b2][c1-1] + people[d][a2][b1-1][c1-1]) -
                                people[d][a1-1][b1-1][c1-1];
                    total += row;

                    if(curmax + row > row){
                        curmax += row;
                        edmaxtemp++;
                    }
                    else {
                        curmax = row;
                        stmaxtemp = edmaxtemp = d;
                    }

                    if(curmax > colmax || (colmax == curmax && edmaxtemp - stmaxtemp > edmaxfinal - stmaxfinal)){
                        edmaxfinal = edmaxtemp;
                        stmaxfinal = stmaxtemp;
                        colmax = curmax;
                    }

                    if(curmin + row < row){
                        curmin += row;
                        edmintemp++;
                    }
                    // Restart
                    else {
                        curmin = row;
                        stmintemp = edmintemp = d;
                    }

                    if(curmin < colmin || (colmin == curmin && edmintemp - stmintemp > edminfinal - stminfinal)){
                        edminfinal = edmintemp;
                        stminfinal = stmintemp;
                        colmin = curmin;
                    }
                }

                // Number of people is the volume of subtensor
                int numtotal = W  , nummin = edminfinal - stminfinal + 1, nummax = edmaxfinal - stmaxfinal + 1;

                if(numtotal == nummin){
                    if(colmax > maxSum){
                        maxSum = colmax;
                        numPeople = (a2-a1+1)*(b2-b1+1)*(c2-c1+1)*nummax;
                    }
                    else if(colmax == maxSum)
                        numPeople = max(numPeople, (a2-a1+1)*(b2-b1+1)*(c2-c1+1)*nummax);
                }
                else{
                    // Better to wrap around
                    if(total-colmin > colmax || (total-colmin == colmax && numtotal - nummin > nummax)){
                        if(total-colmin > maxSum){
                            maxSum = total-colmin;
                            numPeople = (a2-a1+1)*(b2-b1+1)*(c2-c1+1)*(numtotal-nummin);
                        }
                        else if(total-colmin == maxSum)
                            numPeople = max(numPeople, (a2-a1+1)*(b2-b1+1)*(c2-c1+1)*(numtotal-nummin));
                    }
                    else{
                        if(colmax > maxSum){
                            maxSum = colmax;
                            numPeople = (a2-a1+1)*(b2-b1+1)*(c2-c1+1)*nummax;
                        }
                        else if(colmax == maxSum)
                            numPeople = max(numPeople, (a2-a1+1)*(b2-b1+1)*(c2-c1+1)*nummax);
                    }
                }
            }
    // Rounded down average payment
    printf("%lld", maxSum/numPeople);
    return 0;
}
