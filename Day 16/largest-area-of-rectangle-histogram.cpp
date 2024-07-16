// problem link : https://leetcode.com/problems/largest-rectangle-in-histogram/submissions/1322522510/
class Solution {
public:
    vector<int> nsl(vector<int> &heights){
        int n=heights.size();
        vector<int> ans(n);
        stack<int> st;
        ans[0]=-1;
        st.push(0);

        for(int i=1;i<n;i++){
        while(!st.empty() && heights[st.top()]>=heights[i]){
            st.pop();
        }
        ans[i]=st.empty()?-1:st.top();

        st.push(i);
        }
        return ans;
    }

    vector<int> nsr(vector<int> &heights){
        int n=heights.size();
        vector<int> ans(n);
        stack<int> st;
        ans[n-1]=n;
        st.push(n-1);

        for(int i=n-2;i>=0;i--){
        while(!st.empty() && heights[st.top()]>=heights[i]){
            st.pop();
        }
        ans[i]=st.empty()?n:st.top();

        st.push(i);
        }
        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
    int ans=0;
    vector<int> idx_nsl=nsl(heights);
    vector<int> idx_nsr=nsr(heights);

    for(int i=0;i<n;i++){
      int height=heights[i];
      int width=(idx_nsr[i]-idx_nsl[i])-1;

      int area=height*width;

      if(area>ans){
          ans=area;
      }
    }
  return ans;
    }
};

