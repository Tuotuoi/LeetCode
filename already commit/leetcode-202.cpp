/*************************************************************************
	> File Name: leetcode-202.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月26日 星期三 16时11分41秒
    }***********************************************************************/

int init(int n) {
        int sum = 0;
        while(n > 0)
        {
            int bit = n % 10;
            sum += bit * bit;
            n = n / 10;
        }
        return sum;
    }
    
    bool isHappy(int n) {
        int s = n, f = n;
        do{
            s = init(s);
            f = init(f);
            f = init(f);
        }while(s != f);
        
        return s == 1;
    }
