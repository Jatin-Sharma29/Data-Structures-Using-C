int timeRequiredToBuy(int* tickets, int ticketsSize, int k) {
    int count=0;
    while(tickets[k]!=0){
        for(int i=0;i<ticketsSize;i++){
            if(tickets[i]!=0){
                tickets[i]-=1;
                count++;
            }
        
        if(tickets[k]==0)
        break;
        }
    }
    return count;
}
