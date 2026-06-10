class LRUCache {
public:
    // Creating a node 
    class node{
        public:
        int key;
        int val;
        node* next;
        node* prev;
        node(int k,int v)
        {
            key=k;
            val=v;
        }
    };
    node* head=new node(-1,-1);
    node* tail=new node(-1,-1);
    int cap;
    unordered_map<int,node*> mpp;

    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    void addnode(node* newnode)
    {
        node* temp=head->next;
        newnode->next=temp;
        newnode->prev=head;
        temp->prev=newnode;
        head->next=newnode;
    }
    void deletenode(node* delnode)
    {
        node* delprev=delnode->prev;
        node* delnext=delnode->next;
        delprev->next=delnext;
        delnext->prev=delprev;
    }
    int get(int key) {
        if(mpp.find(key)!=mpp.end())
        {
            node* resnode=mpp[key];
            int res=resnode->val;
            mpp.erase(key);
            deletenode(resnode);
            addnode(resnode);
            mpp[key]=head->next;
            return res;
        }
        else
        {
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(mpp.find(key)!=mpp.end())
        {
            node* alreadynode=mpp[key];
            mpp.erase(key);
            deletenode(alreadynode);
        }
        else if(mpp.size()==cap)
        {
            mpp.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        node* newnode = new node(key,value);
        addnode(newnode);
        mpp[key]=newnode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */


// Time Complexity:
// get()  -> O(1)
// put()  -> O(1)


// Space Complexity:
// O(capacity)


/*
Algorithm:

1. Use a Doubly Linked List to maintain order:
      - Head side  -> Most Recently Used
      - Tail side  -> Least Recently Used

2. Use an unordered_map:
      key -> node address

3. For get(key):
      - If key exists:
          * Get node from map
          * Remove it from current position
          * Move it to front
          * Return value
      - Otherwise return -1


4. For put(key,value):
      - If key exists:
          * Delete old node
          * Insert updated node at front

      - If capacity is full:
          * Remove tail->prev (LRU node)

      - Insert new node at front


Example:

capacity = 2

put(1,1)
Cache: {1}

put(2,2)
Cache: {2,1}

get(1)
Return 1
Cache: {1,2}

put(3,3)
Remove 2 (LRU)

Cache: {3,1}


Answer:
get(2) -> -1
get(3) -> 3
*/