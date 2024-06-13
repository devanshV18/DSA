//Node is not defiend logic op


// class Solution{
//   public:
//     //Function to insert a node at the beginning of the linked list.
//     Node *insertAtBegining(Node *head, int x) {
        
//     Node* newNode = new Node(x);
    
//        if(head == NULL){
//            //returning the node in case of an emplty LL
//            return newNode;
//        }
       
       
//        newNode -> next = head;
       
//        //returning the new head of LL incase of insertion at beginning
//        return newNode;
//     }
    
    
//     //Function to insert a node at the end of the linked list.
//     Node *insertAtEnd(Node *head, int x)  {
//        Node* newNode = new Node(x);
       
//        if(head == NULL){
//            return newNode;
//        }
       
//        else{
//            Node* temp = head;
       
//            while(temp->next!=NULL){
//                temp=temp->next;
//            }
//            temp->next = newNode;
//            newNode->next = NULL;
//        }
       
//        //returning the head of LL after insertion at end.
//        return head;
//     }
// };
