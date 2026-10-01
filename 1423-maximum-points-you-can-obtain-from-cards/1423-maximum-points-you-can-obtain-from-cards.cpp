class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int maxsum=0,maxleft=0,rightsum=0;
        for(int i=0;i<k;i++){
            maxleft+=cardPoints[i];
            maxsum=maxleft;
        }
        int n=cardPoints.size()-1;
        int rightind=n;
        for(int i=k-1;i>=0;i--){
            maxleft=maxleft-cardPoints[i];
            rightsum=rightsum+cardPoints[rightind];
            rightind=rightind-1;
            maxsum=max(maxsum,maxleft+rightsum);
        }
        return maxsum;

    }
};