int countNodes(struct ListNode* head){
      struct ListNode* ptr=head;
      int count=0;
      while(ptr!=NULL){
        ptr=ptr->next;
        count++;
      }
      return count;
 }

struct ListNode* deleteMiddle(struct ListNode* head) {
    int size = countNodes(head);
    int middle_node=size/2;
    if(middle_node==0){
        return NULL;
    }
    else{
    struct ListNode*temp=head;
    int i=0;
    while(i<middle_node-1 ){
        temp=temp->next;
        i++;
    }if(temp->next!=NULL ){
    struct ListNode*p=temp->next;
    temp->next=temp->next->next;
    free(p);
    }
    }
    return head;
}
