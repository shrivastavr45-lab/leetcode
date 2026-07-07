class Solution {
public:
    bool isVowel(char c){
        c=tolower(c);
        return c=='a'|| c=='e' || c=='i' || c=='o' || c=='u';
    }
    string sortVowels(string s) {
        vector<char>vs;
        for(char c:s){
            if(isVowel(c)){
                vs.push_back(c);
            }
        }
        sort(vs.begin(),vs.end());
        int j=0;
        for(char &c:s){
            if(isVowel(c)){
                c=vs[j++];
            }
        }
        return s;
    }
};