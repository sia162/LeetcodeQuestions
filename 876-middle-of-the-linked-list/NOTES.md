//brute force approch
ListNode* temp;
temp = head;
int count = 1;
while(temp->next != NULL){
count++;
temp = temp->next;
}
// cout<<count<<" ";
if(count%2==0) count = count/2 + 1;
else count = (count+1)/2;
temp = head;
while(count!=1){
count--;
temp = temp->next;
}
return temp;