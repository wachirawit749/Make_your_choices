#ifndef item_h
#define item_h

class item
{
	private : 	int durability;
				string name;
	public  : 	~item();//create pointer only
				item(string="Nothing",int=0);
				void additemdata(string,int=1);
				int senddurability();
				void operator--();
				virtual string sendname();
};
string item::sendname()
{
    return name;
}
void item::operator--()
{
    durability-=1;
}

item::item(string n,int d)
{
	name = n;
	durability = d;
}





void item::additemdata(string n,int d)
{
	name = n;
	durability = d;
}

item::~item()
{
	//cout<<name<<" has broken"<<endl;
}


int item::senddurability()
{
    return durability;
}





#endif //item_h

