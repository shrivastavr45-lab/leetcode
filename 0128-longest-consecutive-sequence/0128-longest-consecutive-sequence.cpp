class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st(nums.begin(),nums.end());
        int longest=0;
        for(int num:st){
            if(st.find(num-1)==st.end()){
                int lenght=1;
                int current=num;
                while(st.find(current+1)!=st.end()){
                    lenght++;
                    current++;
                }
                longest=max(longest,lenght);
            }
        }
        return longest;
    }
};