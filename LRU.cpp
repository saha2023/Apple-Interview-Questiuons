// 1st Approach this is the most non optimised slution T- n*n
class LRUCache {
public:
    list<int> dll; //it contains the key
    unordered_map<int, pair<list<int>::iterator, int>> cache; //key->(list_node, value)
    int capacity;
    
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    void makeMostRecentlyUsed(int key) {
        dll.erase(cache[key].first);
        dll.push_front(key);
        cache[key].first = dll.begin();
    }
    
    int get(int key) {
        if(!cache.count(key))
            return -1;
        
        makeMostRecentlyUsed(key); //O(n)
        return cache[key].second;
    }
    
    void put(int key, int value) {
        if(cache.count(key)) {
            cache[key].second = value;
            makeMostRecentlyUsed(key); //O(n)
        } else {
            dll.push_front(key);
            cache[key] = {dll.begin(), value};
            capacity--;
        }
        
        if(capacity < 0) {
            cache.erase(dll.back());
            dll.pop_back();
            capacity++;
        }
    }
};


//2nd Approach T-nlog(n)
class LRUCache {
int cap;
    unordered_map<int,pair<int,int>>mp;
    set<pair<int,int>>st;
    int seq = 0;
public:
    //T -> n(total no of get/put operation)  nlog(n)     //S-> total number of different keys
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(mp.count(key)){
            st.erase({mp[key].second, key}); // logn
            st.insert({++seq,key}); //logn
            mp[key].second = seq;
            return mp[key].first;
        }
        return -1;
    }
    
    void put(int key, int val) {
        if(mp.count(key)){
            st.erase({mp[key].second, key}); //logn
            st.insert({++seq,key}); //logn
            mp[key] = {val,seq};
        }
        else{
            if(st.size() == cap){
                auto it = st.begin();
                mp.erase(it->second);
                st.erase({it->first, it->second});
            }
            mp[key]={val,++seq};
            st.insert({seq,key});
        }
    }
};


// this is the most optimised time complexity solution O(n)  using doubly linked list
class DLL{
public:
    int key,value;
    DLL *right,*left;
    DLL(int key,int value){
        this->key=key;
        this->value=value;
        this->left=NULL;
        this->right=NULL;
    }
};
class LRUCache {
public:
    DLL *head, *tail;
    int capacity,size;
    unordered_map<int, DLL*> m;
    LRUCache(int capacity) {
        this->capacity=capacity;
        this->size=0;
        this->head=NULL;
        this->tail=NULL;
        
    }
    void delete_node(DLL *p){
        if(p->left!=NULL){
            p->left->right=p->right;
        }
        else{
            head=p->right;
        }
        if(p->right!=NULL){
            p->right->left=p->left;
            
        }
        else{
            tail=p->left;
        }
        p->left=NULL;
        p->right=NULL;
    }
    
    void insert(DLL *q){
        if (head == NULL) {
            head = tail = q;
        }
        else{
            tail->right = q;
            q->left = tail;
            tail = q;
        }

    }
    
    int get(int key) {
        if (m.find(key)==m.end())
            return -1;
        DLL *x=m[key];
        delete_node(x); //O(1)
        insert(x); //0(1)
        
        return x->value;
    }
    
    void put(int key, int value) {
        DLL *y = new DLL(key,value);
        if(m.find(key)!=m.end()){
            m[key]->value=value;
            delete_node(m[key]);//O(1)
            insert(m[key]); //O(1)
        }
        else{
            m[key]=y;
            if(size==capacity){
                m.erase(head->key);//remove the least recently used value from map
                delete_node(head);
                insert(y);
            }
            else{
                size+=1;//size of window increase
                insert(y);
            }
        }
    }
};

