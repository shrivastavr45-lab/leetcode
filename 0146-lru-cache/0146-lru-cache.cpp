#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;
class LRUCache {
private:
    int capacity;
    list<pair<int,int>>dll;
    unordered_map<int,list<pair<int,int>>::iterator>map;
public:
    LRUCache(int capacity) {
        this->capacity=capacity;
    }
    
    int get(int key) {
        if(map.find(key)==map.end())
            return -1;
        auto it=map[key];
        int value=it->second;
        dll.erase(it);
        dll.push_front({key,value});
        map[key]=dll.begin();
        return value;
    }
    
    void put(int key, int value) {
        if(map.find(key)!=map.end()){
            dll.erase(map[key]);
        }else if(dll.size()==capacity){
            int oldKey=dll.back().first;
            dll.pop_back();
            map.erase(oldKey);
        }
        dll.push_front({key,value});
        map[key]=dll.begin();
    }
};




/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */