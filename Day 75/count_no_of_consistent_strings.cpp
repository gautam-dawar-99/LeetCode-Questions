class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_map<char,int> umm;
        for(auto it:allowed){
            umm[it]++;
        }
        // for(auto it : umm){
        //     cout<<it.first<<" "<<it.second<<endl;
        // }
        int cnt=0;
        for(auto it : words){
            int sz=it.size();
            bool flag = false;
            // cout<<sz<<" ";
            for(int i=0;i<sz;i++){
                if(umm.count(it[i])){
                    flag=true;
                }else{
                    flag=false;
                    break;
                }
            }
            if(flag==true){
                cnt++;
            }
        }
        return cnt;
    }
};