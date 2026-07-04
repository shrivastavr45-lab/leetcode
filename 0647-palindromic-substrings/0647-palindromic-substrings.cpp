class Solution {
public:
    int palindrome(string s,int left,int right){
        int count=0;
        while(left>=0 && right<s.size() && s[left]==s[right]){
            right++;
            left--;
            count++;
        }
        return count;
    }
    int countSubstrings(string s) {
        int ans=0;
        for(int i=0;i<s.size();i++){
            ans+=palindrome(s,i,i);
            ans+=palindrome(s,i,i+1);
        
        }
        return ans;

    }
}; 