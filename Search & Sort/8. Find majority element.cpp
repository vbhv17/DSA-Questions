https://practice.geeksforgeeks.org/problems/majority-element-1587115620/1#
https://www.youtube.com/watch?v=AoX3BPWNnoE&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=16&ab_channel=takeUforward


Naive Approach: Check count of every element in array
                If no majority element is found return -1
class Solution {
public:
    // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int a[], int size)
    {
        int ans;
        for (int i = 0; i < size; i++) {

            int count = 1;
            ans = -1;
            for (int j = i + 1; j < size; j++) {
                if (a[i] == a[j]) {
                    count++;
                    if (count > size / 2) {
                        ans = a[j];
                        return ans;
                    }
                }
            }
        }
        return ans;
    }
};
TC: O(N^2)
  
Approach 2: Hashing
Store frequency of each element in a hashmap(unordered_map)
  
  class Solution {
public:
    // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int a[], int size)
    {
        unordered_map<int, int> mp;
        for (int i = 0; i < size; i++) {
            mp[a[i]]++;
        }

        for (auto i : mp) {
            if (i.second > size / 2) {
                return i.first;
            }
        }
        return -1;
    }
};

TC: O(N)
SC: O(N)
  
Approach 3: MOORES VOTING ALGORITHM

class Solution{
  public:
     //finding a possible candidate which appears more than n/2 times
    int majorityElement(int a[], int size)
    {
        int count=0;
        int candidate=0;
        
        for(int i=0;i<size;i++){
            if(count==0){
                candidate = a[i];
            }
            
            if(candidate == a[i]){
                count++;
            }
            
            else{
                count--;
            }
        }
        
         //just checking if candidate really appears n/2 times, if not return -1
        count=0;
        for(int i=0;i<size;i++){
            
            if(a[i]==candidate){
                count++;
            }
        }
        
        if(count>size/2){
            return candidate;
        }
        
        else return -1;
    }
};

TC: O(N)
SC :O(1)
