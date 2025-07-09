class Solution {
public:
    int countDigitOne(int num) {
//         EG-PG QUESTION:
       if(num<=0) return 0; if(num<10) return 1;
        std::string str_num = std::to_string(num);
        int len=str_num.length();
        int base=pow(10,len-1);
        int firstDigit=num/base;
        int rem=num % base;
        int One_Base=firstDigit==1 ? num-base+1 : base; 
        return countDigitOne(rem)  +    One_Base  +  firstDigit * countDigitOne(base-1);
    }
};