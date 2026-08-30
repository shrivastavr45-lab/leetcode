class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>freq(26,0);
        for(char c:tasks){
            freq[c-'A']++;
        }
        int maxFreq=*max_element(freq.begin(),freq.end());
        int maxcount=count(freq.begin(),freq.end(),maxFreq);
        int required=(maxFreq-1)*(n+1)+maxcount;
        return max((int)tasks.size(),required);
    }
};