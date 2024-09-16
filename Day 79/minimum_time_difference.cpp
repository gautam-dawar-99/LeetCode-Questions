// problem link : https://leetcode.com/problems/minimum-time-difference/
class Solution {
public:
    int timeInMins(string s){
        int n=s.size();
        int time=stoi(s.substr(0,2))*60+stoi(s.substr(3,2));
        return time;
    }
    int diff(int a,int b){
        //cout<<a<<" "<<b<<endl;
        if(a>=b)
            return a-b;
        return  24*60-b+a;
    }
    int findMinDifference(vector<string>& timePoints) {
        vector<int> temp;
        for(auto e:timePoints){
            temp.push_back(timeInMins(e));
        }
        int n=temp.size();
        sort(temp.begin(),temp.end());
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            ans=min({ans,diff(temp[i],temp[(i+1)%n]),diff(temp[i],temp[(i-1+n)%n])});
        }
        return ans;
    }
};