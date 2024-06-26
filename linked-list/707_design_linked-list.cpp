class MyLinkedList {
public:
    struct node{
        int val;
        node* next;
        node(int value){
            val = value;
            next = nullptr;
        }
    };

    node* head;
    int lst_size;

    MyLinkedList() {
        //the head doesn't have content
        head = new node(0);
        lst_size = 0;
    }
    
    int get(int index) {
        if(index >= lst_size || index < 0) return -1;
        node* cur = head->next;
        
        for(int i = 0; i<index;i++){
            cur = cur->next;
        }
        return cur->val;
    }
    
    void addAtHead(int val) {
        node* n = new node(val);
        n->next = head->next;
        head->next = n;
        lst_size++;
    }
    
    void addAtTail(int val) {
        node* n = new node(val);
        node* tail = head;
        while(tail->next){
            tail = tail->next;
        }
        tail->next = n;
        lst_size ++;
        
    }
    
    void addAtIndex(int index, int val) {
        if(index > lst_size || index < 0) return;
        
        node* n = new node(val);
        node* pre = head;
        if(index == lst_size) addAtTail(val);
        else{
            for(int i = 0;i < index;i++){
                pre = pre->next;
            }
            if(!pre->next)pre->next = n;
            else{
                n->next = pre->next;
                pre->next = n;
            }
            lst_size++;
        }
        
    }
    
    void deleteAtIndex(int index) {
        if(index >= lst_size || index < 0) return;

        node* pre = head;
        for(int i = 0;i<index;i++){
            pre = pre->next;
        }
        node* toDelete = pre->next;
        pre->next = toDelete->next;
        toDelete->next = nullptr;
        delete toDelete;
        lst_size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */