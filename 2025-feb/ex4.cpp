#include <iostream>
#include <vector>

using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
    int n1 = nums1.size();
    int n2 = nums2.size();

    if(n2>n1){ findMedianSortedArrays(nums2, nums1); }
    
    int n = n1 + n2;
    int left = (n1 + n2 + 1) / 2; // Calculate the left partition size
    int low = 0, high = n1;
        
    while (low <= high){
        int mid1 = (low + high) >> 1; // Calculate mid index for nums1
        int mid2 = left - mid1; // Calculate mid index for nums2
        
        int l1 = 0, l2 = 0, r1 = 1000, r2 = 1000;
        
        // Determine values of l1, l2, r1, and r2
        if(mid1 < n1){ r1 = nums1[mid1]; } 
        if(mid2 < n2){r2 = nums2[mid2];}
        if(mid1 - 1 >= 0){l1 = nums1[mid1 - 1];}
        if(mid2 - 1 >= 0){l2 = nums2[mid2 - 1];}
        
        if(l1 <= r2 && l2 <= r1){
            if(n % 2 == 1){return max(l1, l2);}
            else {return ((double)(max(l1, l2) + min(r1, r2))) / 2.0;}
        }
        else if(l1 > r2){ high = mid1 - 1; }
        else{ low = mid1 + 1;}
    }
        
    return 0; 
}

int main(){

    return 0;
}
