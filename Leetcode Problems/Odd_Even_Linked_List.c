struct ListNode* oddEvenList(struct ListNode* head) {
    if(head==NULL || head->next == NULL){
        return head;
    }else{
        struct ListNode *prev=head;
        struct ListNode *curr=head->next;
        struct ListNode *head1=curr;
        while(curr!=NULL && curr-> next !=NULL){
            prev->next=curr->next;
            prev=prev->next;
            curr->next=prev->next;
            curr=curr->next;
        }
        prev->next =head1;
        return head;
    }
}
