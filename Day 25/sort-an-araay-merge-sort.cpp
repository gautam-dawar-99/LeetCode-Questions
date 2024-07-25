// problem link : https://leetcode.com/problems/sort-an-array/
class Solution {
public:
    void merge(vector<int>& arr,int start,int mid,int end){
        int n=mid-start+1;
        int m=end-mid;
        vector<int> b(n), c(m);
        for(int i=0;i<n;i++){
            b[i]=arr[start+i];
        }
        for(int j=0;j<m;j++){
            c[j] = arr[mid+1+j];
        }

        int i=0,j=0,k=start;
        while(i<n&&j<m){
            if(b[i]<c[j]){
                arr[k]=b[i];
                i++;
                k++;
            }
            else{
                arr[k]=c[j];
                j++;
                k++;
            }
        }
        while(i<n){
            arr[k]=b[i];
            i++;
            k++;
        }
        while(j<m){
            arr[k]=c[j];
            j++;
            k++;
        }
    }
    void mergeSort(vector<int> &arr,int start ,int end){
        if(start>=end) return;
        int mid=(start+end)/2;
        mergeSort(arr,start,mid);
        mergeSort(arr,mid+1,end);
        merge(arr,start,mid,end);

    }
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums,0,nums.size()-1);
        return nums;
    }
};