// LC 29: Divide Two Integers -> create a function that does modulo operation on integers
//Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.
// The integer division should truncate toward zero, which means losing its fractional part. For example, 8.345 would be truncated to 8, and -2.7335 would be truncated to -2.
// Return the quotient after dividing dividend by divisor.
// Note: Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−231, 231 − 1]. For this problem, if the quotient is strictly greater than 231 - 1, then return 231 - 1, and if the quotient is strictly less than -231, then return -231.

// Constrains: 
// -231 <= dividend, divisor <= 231 - 1
// divisor != 0
 

#include<iostream>
using namespace std;

int divide(int dividend, int divisor) {
        
        // Edge cases
        if(dividend == INT_MIN && divisor == -1) return INT_MAX; //if INT_MIN is given negative sign it becomes INT_MAX+1 which is overflow condition

        // capture negative sign
        bool sign = false;
        if((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0)) sign = true;

        //take absolute value 
        long longDividend = abs((long long)dividend);
        long longDivisor = abs((long long)divisor);

        if(longDividend < longDivisor) return 0; // if bigger number divides a smaller number and as per questions condition we need to truncate the answer to absolute value, in this case the answer will always be 0

        long quotient = 0;

        while(longDividend >= longDivisor){

            long tempDivisor = longDivisor;

            long multiple = 1;

            while(longDividend >= (tempDivisor << 1)){
                tempDivisor = tempDivisor << 1; //left shift divisor -> temp_divisor × 2
                multiple = multiple << 1; // multiple x 2
            }

            longDividend = longDividend  - tempDivisor;
            quotient = quotient + multiple;

        }

        if(sign){
            quotient = -quotient;
        }

        // Handle integer bounds
        if(quotient > INT_MAX) return INT_MAX;
        if(quotient < INT_MIN) return INT_MIN;

        return (int)quotient;
    }