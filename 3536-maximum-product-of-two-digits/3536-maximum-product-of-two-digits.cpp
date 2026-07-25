class Solution {
public:
    int maxProduct(int n) {
        int f_max = 0;
        int s_max = 0;
        while(n > 0){
            int digit = n % 10;
            n = n / 10;
            if(digit >= f_max){
                s_max = f_max;
                f_max = digit;
            }else if(digit >= s_max){
                s_max = digit;
            }
        }
        return f_max * s_max;
    }
};