class MedianFinder {
public:
    priority_queue<int>leftheap;
    priority_queue<int,vector<int>,greater<int>>rightheap;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        leftheap.push(num);
        rightheap.push(leftheap.top());
        leftheap.pop();
        if(leftheap.size()<rightheap.size()){
            leftheap.push(rightheap.top());
            rightheap.pop();
        }    

    }
    
    double findMedian() {
        if(leftheap.size()>rightheap.size()){
            return leftheap.top();
        }
        return (leftheap.top()+rightheap.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */