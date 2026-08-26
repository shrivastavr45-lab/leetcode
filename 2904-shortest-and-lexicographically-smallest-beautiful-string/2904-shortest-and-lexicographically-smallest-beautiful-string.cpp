class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int left=0;
        int count=0;
        string ans="";
        for(int right=0;right<s.size();right++){
            if(s[right]=='1'){
                count++;
            }
            while(count==k){
                string curr=s.substr(left,right-left+1);
                if(ans=="" || curr.size()<ans.size() || (curr.size()==ans.size() && curr<ans)){
                    ans=curr;
                }
                if(s[left]=='1'){
                    count--;
                }
                left++;
            }
        
        }
        return ans;
    }
};