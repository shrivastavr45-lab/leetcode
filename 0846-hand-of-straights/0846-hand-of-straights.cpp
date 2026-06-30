class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        if(n%groupSize!=0){
            return false;
        }
        map<int,int>mp;
        for(int card:hand){
            mp[card]++;
        }
        for(auto &[card,freq]:mp){
            while(mp[card]>0){
                for(int i=0;i<groupSize;i++){
                    int curr=card+i;
                    if(mp[curr]==0){
                        return false;
                    }
                    mp[curr]--;
                }
            }
        }
        return true;
    }
};