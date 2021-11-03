#ifndef OBJECT_H_INCLUDED
#define OBJECT_H_INCLUDED

class OBJ : public item
{
private :
    int x;
    int y;
    string Objname;
    int lock;
public :
    OBJ(string,int,int,string="Nothing",int=0);
    void getlock(int);
    string sendname();
    int sendx();
    int sendy();
    int sendlock();
};
OBJ::OBJ(string Objn,int p1,int p2,string n,int d):item(n,d)
{
    Objname = Objn;
    x = p1;
    y = p2;
    lock = 0;
}

string OBJ::sendname()
{
    return Objname;
}

void OBJ::getlock(int l)
{
    lock = l;
}

int OBJ::sendlock()
{
    return lock;
}

int OBJ::sendx()
{
    return x;
}

int OBJ::sendy()
{
    return y;
}


int checkobj(NPC Me,OBJ &Object,Inventory **cptr)
{
    if(Me.x==Object.sendx()&&Me.y==Object.sendy())
    {
        if(Object.sendlock()==1)
        {
            cout<<"\t\t\t\t    "<<Object.sendname()<<" has locked"<<endl;

            if(Object.sendname()=="Locker"||Object.sendname()=="Vault")
            {
                if(finditem(cptr,"LockPick"))
                {
                    cout<<"\t\t\t\t    Use LockPick?(Y/N)"<<endl;
                    if(tolower(getch())=='y')
                    {
                        useitem(cptr);
                        if(Object.sendname()=="Vault")
                        {
                            if(minigame())
                                Object.getlock(0);
                            system("cls");
                            showframe(15,53);
                            cout<<endl;
                        }
                        else
                            Object.getlock(0);
                    }
                }
                if(Object.sendname()=="Locker"&&Object.sendlock()==1)
                {
                    if(finditem(cptr,"Crowbar"))
                    {
                        cout<<"\t\t\t\t    Use Crowbar?(Y/N)"<<endl;
                        if(tolower(getch())=='y')
                        {
                            useitem(cptr);
                            Object.getlock(0);
                        }
                    }
                }
            }
            if(Object.sendlock()==1)
            {
                cout<<"\t\t\t\t    Needs something to unlock";
                getch();

            }
        }
        if(Object.sendlock()==0)
        {
            cout<<"\t\t\t\t    You get "<<Object.item::sendname();
            if(Object.senddurability()!=0)
                cout <<"  "<<Object.senddurability()<<" EA";
            cout<<endl;
            if(Object.item::sendname()!="Nothing")
            {
                add(cptr,Object.item::sendname(),Object.senddurability());
                Object.additemdata("Nothing",0);
            }
            getch();

        }
        return 1;
    }
    else
        return 0;
}



#endif // OBJECT_H_INCLUDED
