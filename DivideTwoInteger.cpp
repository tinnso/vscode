#include <limits.h>
#include <stdlib.h>
#include <stdio.h>


int divide(int dividend, int divisor) {
    if (dividend == INT_MIN) {
        if (divisor == 1) {
            return dividend;
        } 
        // this will overflow
        if (divisor == -1) {
            return INT_MAX;
        }
    }

    if (divisor == INT_MIN) {
        if (dividend == INT_MIN)
            return 1;
        else
            return 0;
    } 

    bool revert = false;
    if (dividend > 0) {
        dividend = -dividend;
        revert = !revert;
    }

    if (divisor > 0) {
        divisor = -divisor;
        revert = !revert;
    }

    // when x * z < y, return false
    // when x * z >= y, return true
    auto quickAdd = [](int x, int z, int y) {
        // x, y is negtive
        // need to confirm x * z >= y is true or not
        // if x * z >= y, this means z is too small, becuase x and y are negative

        int result = 0;
        int add = x;
        while (z){

            // odd case, include 1
            if (z & 1) {

                // shoud keep result + add >= y
                if (result < y - add)
                    return false;

                result = add + result; 
            }

            if (z != 1) {

                // should keep add + add >= y
                if (add < y - add)
                    return false;

                add = add + add;
            }

             z = z >> 1;

        }

        return true;
    };

    int left = 1, right = INT_MAX;
    int mid = 0;
    int ans = 0;
    while (left <= right) {
        mid = left + ((right - left) >> 1);
        bool check = quickAdd(divisor, mid, dividend);

        if (check) {
            ans = mid;

            if (mid == INT_MAX)
                break;

            left = mid + 1;
        } else {
            right = mid - 1;
        }

    }

    return revert ? -ans : ans;
    

}

int main() {

    int ret = divide(100, 5);

    printf("ret is %d\n", ret);

    getchar();

    return 0;
}