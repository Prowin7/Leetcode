class Solution {
    int popcount(int num){
        int cnt=0;
        while(num){
            num&=(num-1);
            cnt++;
        }
        return cnt;
    }
    bool isSet(int &x,int bit){
        return (x&(1<<bit));
    }
    int set(int &x,int bit){
        return (x|(1<<bit));
    }
    int unSet(int &x,int bit){
        return (x&(~(1<<bit)));
    }
public:
    int minimizeXor(int num1, int num2) {
        int required=popcount(num2);
        int current=popcount(num1);
        int x=num1;
        int bit=0;
        if(current<required){
            while(current<required){
                if(!isSet(x,bit)){
                    x |= (1 << bit); // set
                    current++;
                }
                bit++;
            }
        }
        else if(required<current){
            while(required<current){
                if(isSet(x,bit)){
                    x &= ~(1 << bit); //unSet
                    current--; 
                }
                bit++;
            }
        }
        return x;
    }
};