#include<simran.h>

class Solution {
public:
    int search(vector<int>& arr, int target) {
        int low = 0;
        int hi = arr.size()-1;
        while(hi>=low) {
            int mid = (hi+low)/2;
            
            if (arr[mid] == target) return mid;
            
            if (arr[mid] >= arr[low]) {
                if(target<arr[mid] && target>= arr[low]){
                    hi = mid-1;
                }
                else {
                    low = mid+1;
                }
            }
            else {
                if (target>arr[mid] && target<=arr[hi]) {
                    low = mid+1;
                }
                else {
                    hi = mid-1;
                }
            }
        }
        return -1;
    }
};