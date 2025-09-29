struct ListNode {
    int val;
    struct ListNode *next;
 };

 int constant_value(const int *a, const int *b){
    return (*(int*)a - *(int*)b);
 }
 struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    if(listsSize == 0){
        return NULL;
    }
    int total = 0;
    for(int i = 0; i < listsSize; i++){
        struct ListNode *curr = lists[i];
        while(curr != NULL){
            total++;
            curr = curr->next;
        }
    }
    int temp = 0;
    for(int i = 0; i < listSize; i++){
        struct ListNode *curr = lists[i];
        while(curr != NULL){
            temp[total++] = curr->val;
            curr = curr->next;
        }
    }
    qsort(total,temp,sizeof,constant_value);


 }

