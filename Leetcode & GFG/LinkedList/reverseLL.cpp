struct Node
{
    int data;
    Node * next;
    
    Node (int x)
    {
        data=x;
        next=nullptr;
       
    }
        
};
Node* reverseLL(Node* head){
    // Node* prev = NULL;
    Node* curr = head;
    Node* prev = nullptr;

    while(curr != nullptr){
        Node* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }

    return prev;
}