class RecentCounter {
public:
    queue<int> container;
    
    RecentCounter() {   
    }
    
    int ping(int t) {
        container.push(t);
        
        while(container.front() < t-3000)
            container.pop();
        
        return container.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */