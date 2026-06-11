class LFUCache {
public:

    // Creating a node
    class node {
    public:
        int key;
        int val;
        int cnt = 1;
        node* next;
        node* prev;

        node(int k, int v) {
            key = k;
            val = v;
            cnt = 1;
            next = NULL;
            prev = NULL;
        }
    };


    // Doubly Linked List for each frequency
    struct list {
        int size;
        node* head;
        node* tail;

        list() {
            head = new node(0,0);
            tail = new node(0,0);

            head->next = tail;
            tail->prev = head;

            size = 0;
        }

        void addnode(node* newnode) {

            node* temp = head->next;

            newnode->next = temp;
            newnode->prev = head;

            head->next = newnode;
            temp->prev = newnode;

            size++;
        }


        void deletenode(node* delnode) {

            node* delprev = delnode->prev;
            node* delnext = delnode->next;

            delprev->next = delnext;
            delnext->prev = delprev;

            size--;
        }
    };


    // frequency -> list
    unordered_map<int, list*> frqmap;

    // key -> node address
    unordered_map<int, node*> keynode;


    int maxsize;
    int minfreq;
    int cursize;


    LFUCache(int capacity) {

        maxsize = capacity;
        minfreq = 0;
        cursize = 0;
    }


    void updateFreq(node* curr) {

        int oldfreq = curr->cnt;

        frqmap[oldfreq]->deletenode(curr);


        if(oldfreq == minfreq && frqmap[oldfreq]->size == 0) {
            minfreq++;
        }


        curr->cnt++;


        if(frqmap.find(curr->cnt) == frqmap.end()) {
            frqmap[curr->cnt] = new list();
        }


        frqmap[curr->cnt]->addnode(curr);
    }



    int get(int key) {

        if(keynode.find(key) == keynode.end())
            return -1;


        node* curr = keynode[key];

        int ans = curr->val;

        updateFreq(curr);

        return ans;
    }



    void put(int key, int value) {

        if(maxsize == 0)
            return;


        // key already exists
        if(keynode.find(key) != keynode.end()) {

            node* curr = keynode[key];

            curr->val = value;

            updateFreq(curr);

            return;
        }


        // cache is full
        if(cursize == maxsize) {

            list* temp = frqmap[minfreq];

            node* removeNode = temp->tail->prev;


            keynode.erase(removeNode->key);

            temp->deletenode(removeNode);

            cursize--;
        }



        // insert new node
        cursize++;

        minfreq = 1;


        if(frqmap.find(1) == frqmap.end()) {
            frqmap[1] = new list();
        }


        node* newnode = new node(key,value);

        frqmap[1]->addnode(newnode);

        keynode[key] = newnode;
    }
};


// Time Complexity:
// get() -> O(1)
// put() -> O(1)


// Space Complexity:
// O(capacity)



/*
Algorithm:

1. Use Doubly Linked List:
      - Each frequency has its own list
      - Front = Most Recently Used
      - Back = Least Recently Used


2. Use unordered_map:
      key -> node address

3. Use another unordered_map:
      frequency -> linked list


4. For get(key):
      - Check if key exists
      - Increase frequency count
      - Move node to new frequency list
      - Return value


5. For put(key,value):
      - If key exists:
          * Update value
          * Increase frequency

      - If cache is full:
          * Remove node from minimum frequency list
          * Remove LRU node

      - Insert new node with frequency 1


Example:

capacity = 2

put(1,1)
Cache: {1}

put(2,2)
Cache: {2,1}

get(1)
Return 1
Frequency of 1 increases

put(3,3)
Remove key 2 because it has minimum frequency


Answer:
get(2) -> -1
get(3) -> 3
*/


/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
