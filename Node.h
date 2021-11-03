#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED


typedef struct inventory
{
    inventory *before;
    item name;
    inventory *next;
} Inventory;

Inventory *head=NULL;

Inventory* settotail()
{
    Inventory *ptr=head;

    if(ptr)
    {
        for(; ptr->next; ptr=ptr->next) {}
    }
    return ptr;
}

void add(Inventory **cptr,string n,int d)
{
    *cptr=settotail();
    int check=0;

    Inventory *newy = new Inventory,*nextcptr;

    if(newy)
    {
        newy->before = NULL;
        newy->next = NULL;

        newy->name.additemdata(n,d);

        if(*cptr == NULL)
        {
            *cptr = newy;
            head = *cptr;
        }
        else
        {
            while(*cptr)
            {
                if((*cptr)->name.sendname()==n)
                {
                    (*cptr)->name.additemdata(n,d+(*cptr)->name.senddurability());
                    check=1;
                    delete newy;
                    break;
                }
                if(n<(*cptr)->name.sendname())
                {
                    break;
                }
                nextcptr=*cptr;
                *cptr = (*cptr)->before;
            }

            if(check!=1)
            {
                if(!*cptr)
                {
                    newy->next = nextcptr;
                    nextcptr->before = newy;
                    head = newy;
                }
                else if(!(*cptr)->next)
                {
                    (*cptr)->next=newy;
                    newy->before=*cptr;
                }
                else
                {
                    newy->before = *cptr;
                    nextcptr->before = newy;
                    newy->next = nextcptr;
                    (*cptr)->next = newy;
                }
            }
        }
    }
    else
        cout<<"Out of memory";
}

void deletednode(Inventory **cptr)
{
    Inventory *ptr=*cptr;
    if(head == *cptr)
    {
        head = (*cptr)->next;
        if((*cptr)->next!=NULL)
            (*cptr)->next->before = NULL;
        *cptr = head;
    }
    else
    {
        if((*cptr)->next==NULL)
        {
            ptr->before->next = NULL;
        }
        else
        {
            (*cptr)->next->before = ptr->before;
            ptr->before->next = (*cptr)->next;
        }
        (*cptr)=ptr->before;
        ptr->before = NULL;
        ptr->next = NULL;
    }
    delete ptr;
}

void deleteall()
{
    Inventory *ptr ;
    while(head)
    {
        ptr = head;
        head=head->next;
        delete ptr;
    }
}

void useitem(Inventory **ptr)
{
    --(*ptr)->name;
    if((*ptr)->name.senddurability()==0)
    {
        deletednode(ptr);
    }
}

int finditem(Inventory **cptr,string n)
{
    Inventory *ptr=head;
    for(; ptr; ptr=ptr->next)
    {
        if(n == (ptr->name).sendname())
        {
            *cptr = ptr;
            return 1;
        }
    }
    return 0;
}

void showinventory()
{
    Inventory *ptr=head;
    cout<<"\t\t\t\t  -Inventory- "<<endl;
    for(; ptr; ptr=(ptr)->next)
    {
        cout <<"\t\t\t\t   "<< ptr->name.sendname()<<" "<< ptr->name.senddurability()<<endl;
    }
}



#endif // NODE_H_INCLUDED
