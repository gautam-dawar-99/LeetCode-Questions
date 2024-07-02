// https://leetcode.com/problems/clumsy-factorial/description/

class Solution {
public:
    int clumsy(int n) {
        int ans=0;

        for(int i=0;i<4;i++){
            if(i==0) ans=n;
            else if(i==1) ans*=n;
            else if(i==2)   ans/=n;
            else if(i==3)  ans+=n;
            n--;
            if(n==0) return ans;
        }

        while(n>0){
            int tmp=0;
            for(int i=0;i<4;i++){
                if(i==0) tmp=-n;
                else if(i==1) tmp*=n;
                else if(i==2)   tmp/=n;
                else if(i==3)  tmp+=n;
                n--;
                if(n==0) break;
            }
            ans+=tmp;
        }
        return ans;
    }
};

