/*The method multiplies 
two  linked lists l1 and l2
and returns their product*/

Note: The output could be large take modulo 109+7.
  
long long  multiplyTwoLists (Node* l1, Node* l2)
{
    long long num1=0;
    long long num2=0;
    
    int M = 1000000007;
    
    while(l1!=NULL || l2!=NULL)
    {
        if(l1!=NULL)
        {
            num1 = ((num1%M*10%M)%M + l1->data%M)%M;
            l1=l1->next;
        }
        
        if(l2!=NULL)
        {
            num2 = ((num2%M*10%M)%M + l2->data%M)%M;
            l2=l2->next;
        }
    }
    
    return ((num1%M)*(num2%M))%M;
}
