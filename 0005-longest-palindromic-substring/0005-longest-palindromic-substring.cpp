class Solution {
public:
    string palindrome(string s,int left,int right){
        while(left>=0 && right<s.size() && s[left]==s[right]){
            left--;
            right++;
        }
        return s.substr(left+1,right-left-1);
    }
    string longestPalindrome(string s) {
        string ans="";
        for(int i=0;i<s.size();i++){
            string s1=palindrome(s,i,i);
            string s2=palindrome(s,i,i+1);
            if(s1.size()>ans.size()){
                ans=s1;
            }
            if(s2.size()>ans.size()){
                ans=s2;
            }
        }
        return ans;
    }
};