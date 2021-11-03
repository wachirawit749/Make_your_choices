#ifndef CHAPTER_H_INCLUDED
#define CHAPTER_H_INCLUDED

void bed(int x, int y, int z)
{
    int i,j;
    for(i = y; i<y+z-1; i++)
    {
        frame[i][x-1]='|';
        frame[i][x+z]='|';
        for(j=x; j<x+z; j++)
        {
            frame[i][j]='/';
            frame[y-1][j]='=';
            frame[y-1][j+1]='=';
            frame[y-1][j-1]='=';
        }
    }
}

void bookshelf(int x,int y,int z)
{

    int i ;
    for(i=y; i<y+z; i++)
    {
        frame[i][x] = '|';
        frame[i][x+1] = '|';
    }
    frame[y-1][x] = '-';
    frame[y-1][x+1] = '-';
    frame[y+z][x] = '-';
    frame[y+z][x+1] = '-';
}

void car(int x)
{
    int i, j ;
    for(i=x+7; i<x+15; i++)
    {
        if(i==x+7||i==x+8||i==x+13||i==x+14)
        {
            for(j=5; j<7; j++)
            {
                frame[j][i]='|';
            }
        }
    }
    for(i=x+4; i<x+20; i++)
    {
        frame[4][i]='-';
        frame[7][i]='-';
        if(i==x+4||i==x+19)
        {
            for(j=5; j<7; j++)
            {
                frame[j][i]='|';
            }

        }
        if((i>x+8&&i<x+13))
        {
            frame[6][i]=  '_';

        }
    }
}

void desk(int x,int y,int z)
{
    int i;
    frame[y][x]= '|';
    frame[y][x+z+1]= '|';
    for(i=x; i<x+z; i++)
    {
        frame[y-1][i+1]= '-';
        frame[y+1][i+1]= '-';
    }
}

void flower(int x,int y )
{
    frame[y][x]='+';
    frame[y][x+1]=')';
    frame[y][x-1]='(';
}

void vault(int x,int y,int z )
{
    int i,j;
    for(i=x; i<x+z; i++)
    {
        if(frame[y-1][x] != '*')
        {
            frame[y-2][i] = '-';
        }
        frame[y][i] = '-';
        if(i==x)
            frame[y-1][x] = '|';
        frame[y-1][x+z-1] = '|';
    }
    j=(z)/2;
    frame[y-1][x+j] = 'V';
}

void table(int x,int y,int z,int t)
{
    int i ;
    for(i = y; i<y+z; i++)
    {
        frame[i][x-1] = '(';
        frame[i][x] = '/';
        frame[i][x+1] = '|';
        frame[i][x+2] = ' ';
        frame[i][x+3] = '|';
        if(t==1)
        {
            frame[i][x+4] = '/';
            frame[i][x+5] = ')';
        }
    }
    if(i==y+z)
    {
        frame[i-1][x+2] = '-';
    }
}

void box(int x )
{
    int i;
    for(i=x+1; i<x+10; i++)
    {
        frame[13][i]='/';
        frame[12][i+1]='-';
        frame[13][i+1]='|';
    }
    frame[12][x+1]='-';
    frame[13][x+1]='|';
    frame[13][x+3]='L';
    frame[13][x+4]='0';
    frame[13][x+5]='C';
    frame[13][x+6]='K';
    frame[13][x+7]='E';
    frame[13][x+8]='R';
}

void shelf(int x )
{
    int i  ;
    for(i=x+1; i<x+10; i++)
        frame[1][i]='=';
    frame[1][x+10]='|';
    frame[1][x+1]='|';
}

int map1()
{
    download(1);
    int i;
    setframe(15,53);
    PlaySound(TEXT("sound\\conan2.wav"),NULL,SND_LOOP|SND_ASYNC);
    for(i=3; i<12; i++)
    {
        frame[i][52]='I';
    }
    car(0);
    car(25);
    box(0);
    box(10);
    shelf(0);
    shelf(10);
    shelf(20);

    NPC Me;
    Me.x = 51;
    Me.y = 13;
    Me.picture = 'O';
    char dummy = ' ';

    Inventory *cptr = NULL;
    add(&cptr,"LockPick",1);

    OBJ Locker1("Locker",5,11,"LockPick",1);
    OBJ Locker2("Locker",15,11);
    OBJ Shelf1("Shelf",6,2);
    OBJ Shelf2("Shelf",16,2);
    OBJ Shelf3("Shelf",26,2,"Crowbar",2);
    OBJ Car("Car",11,8);
    Car.getlock(1);
    Locker1.getlock(1);

    /*cout<<"..";
    system("PAUSE");*/

    while(1)
    {
        frame[Me.y][Me.x]=Me.picture;

        system("cls");
        showframe(15,53);

        delay(0.075);

        if((Me.x==Locker1.sendx()&&Me.y==Locker1.sendy())||(Me.x==Locker2.sendx()&&Me.y==Locker2.sendy()))
            cout<<endl<<"\t\t\t\t\t\t\t"<<Locker1.sendname()<<endl;
        if((Me.x==Shelf1.sendx()&&Me.y==Shelf1.sendy())||(Me.x==Shelf2.sendx()&&Me.y==Shelf2.sendy())||(Me.x==Shelf3.sendx()&&Me.y==Shelf3.sendy()))
            cout<<endl<<"\t\t\t\t\t\t\t"<<Shelf1.sendname()<<endl;
        if((Me.x==11||Me.x==36)&&Me.y==8)
            cout<<endl<<"\t\t\t\t\t\t\tCar"<<endl;

        delay(0.10);

        clearKeyboardBuffer();
        char dum = tolower(getch());

        switch(dum)
        {
        case 'w'    :
            if(checkblock(Me.y-1,Me.x))
            {
                frame[Me.y][Me.x] = dummy;
                Me.y -=1;
                dummy = frame[Me.y][Me.x];
            }
            break;
        case 's'    :
            if(checkblock(Me.y+1,Me.x))
            {
                frame[Me.y][Me.x] = dummy;
                Me.y +=1;
                dummy = frame[Me.y][Me.x];
            }
            break;
        case 'a'    :
            if(checkblock(Me.y,Me.x-1))
            {
                frame[Me.y][Me.x] = dummy;
                Me.x -=1;
                dummy = frame[Me.y][Me.x];
            }
            break;
        case 'd'    :
            if(checkblock(Me.y,Me.x+1))
            {
                frame[Me.y][Me.x] = dummy;
                Me.x +=1;
                dummy = frame[Me.y][Me.x];
            }
            break;
        case 'i'    :
            cout<<endl;
            showinventory();
            getch();

            break;
        case ' '    :
            if(checkobj(Me,Locker1,&cptr))
                break;
            if(checkobj(Me,Locker2,&cptr))
                break;
            if(checkobj(Me,Shelf1,&cptr))
                break;
            if(checkobj(Me,Shelf2,&cptr))
                break;
            if(checkobj(Me,Shelf3,&cptr))
                break;

            if((Me.x==11||Me.x==36)&&Me.y==8)
            {
                if(Car.sendlock()==1)
                {
                    cout<<"\t\t\t\t    "<<Car.sendname()<<" has locked"<<endl;
                    if(finditem(&cptr,"Crowbar"))
                    {
                        cout<<"\t\t\t\t    Use Crowbar?(Y/N)"<<endl;
                        if(tolower(getch())=='y')
                        {
                            useitem(&cptr);
                            Car.getlock(0);
                        }
                    }
                    else
                    {
                        cout<<"\t\t\t\t    Needs something to unlock"<<endl;
                        getch();

                        break;
                    }
                }
                if(Car.sendlock()==0)
                {
                    PlaySound(TEXT("sound\\beep.wav"),NULL,SND_LOOP|SND_ASYNC);
                    cout<<"\n\t\t\t\t\t\t   Beep";
                    delay(0.3);
                    cout<<" Beep";
                    delay(0.3);
                    cout<<" Beep";
                    delay(0.4);
                    cout<<'.';
                    delay(0.4);
                    cout<<'.';
                    delay(0.4);
                    cout<<'.';
                    getch();

                    return 0;
                }
            }

            if(dummy=='I')
            {
                cout<<"\n\t\t\t\t\t\tWanna to leave?(Y/N)"<<endl;
                if(tolower(getch())=='y')
                {
                    return 1;
                }
                break;
            }
            break;
        default :
            cout<<endl<<endl<<endl;
            textcolor(DARKRED,YELLOW);
            cout<<"\t\t\t\t\t    PLEASE READ HOW TO PLAY FIRST\t\t\t\t\t\t        "<<endl;
            resetcolor();

            cout<<"\t\t\t\t\t    PRESS H to show to how to play"<<endl<<endl;

            if(tolower(getch())=='h')
            {
                textcolor(DARKYELLOW,0 );
                cout<<"\t\t\t\tPRESS";
                textcolor(AQUA,0 );
                cout<<"    'w' 'a' 's' 'd'             to move   "<<endl<<endl;
                textcolor(DARKYELLOW,0 );
                cout<<"\t\t\t\tPRESS";
                textcolor(AQUA,0 );
                cout<<"    'i'                         to check your inventory  "<<endl<<endl;
                textcolor(DARKYELLOW,0 );
                cout<<"\t\t\t\tPRESS";
                textcolor(AQUA,0 );
                cout<<"    'spacebar'                  to interact or  select "<<endl;
                resetcolor();
                system("PAUSE>NUL");
            }

        }
    }
}

int map2()
{
    download(2);
    int i,j;
    setframe(15,53);
    PlaySound(TEXT("sound\\conan2.wav"),NULL,SND_LOOP|SND_ASYNC);
    Inventory *cptr = settotail();

    for(i=1; i<4; i++)
    {
        flower(18,i);
        flower(34,i);
    }

    flower(40,1);
    flower(50,1);
    flower(17,5);
    flower(17,13);
    flower(36,5);
    box(4);
    vault(43,3,5);
    table(6,1,3,1);
    desk(40,12,9);
    bookshelf(16,8,3);
    bookshelf(1,10,3);
    bookshelf(21,8,3);
    bookshelf(22,8,3);
    bookshelf(28,8,3);
    bookshelf(29,8,3);
    bookshelf(34,8,3);
    for(i=24; i<28; i++)
    {
        frame[0][i]= '_';
    }
    for(j=0; j<53; j++)
    {
        if(j<16||j>37)
            frame[8][j]= '*';
        if(j>6&&j<11)
        {
            frame[8][j]= '_';

        }
        if(j>43&&j<48)
        {
            frame[8][j]= '_';

        }
    }
    for(i=0; i<15; i++)
    {
        frame[i][15]= '*';
        if(i<8)
            frame[i][38]= '*';
        if(i==6)
        {

            frame[i][15]= 'I';
        }
    }
    for(j=15; j<38; j++)
    {
        frame[4][j]= '*';
        if(j>23&&j<28)
        {
            frame[4][j]= '_';
        }
    }
    for(i=1; i<6; i++)
    {
        frame[i][1] =  '/'  ;
        frame[6][1] =  '='  ;
        frame[6][2] =  '='  ;
        frame[i][2] =  '|'  ;
    }

    NPC Me;
    Me.x = 26;
    Me.y = 1;
    Me.picture = 'O';
    char dummy = ' ';

    int key = 0;

    OBJ Locker1("Locker",9,11,"LockPick",2);
    OBJ Book1("Bookshelf",18,9);
    OBJ Book2("Bookshelf",20,9,"10 Dollar",5);
    OBJ Book3("Bookshelf",24,9);
    OBJ Book4("Bookshelf",27,9,"10 Dollar",7);
    OBJ Book5("Bookshelf",31,9);
    OBJ Book6("Bookshelf",33,9);
    OBJ Book7("Bookshelf",36,9);
    OBJ Shelf("Shelf",3,11);
    OBJ Vault("Vault",45,4,"10 Dollar",50);
    OBJ Larder1("Larder",3,1);
    OBJ Larder2("Larder",3,2);
    OBJ Larder3("Larder",3,3);
    OBJ Larder4("Larder",3,4);
    OBJ Larder5("Larder",3,5);
    Vault.getlock(1);
    Locker1.getlock(1);

    while(1)
    {
        frame[Me.y][Me.x]=Me.picture;

        system("cls");
        showframe(15,53);

        delay(0.075);

        if(Me.x==Locker1.sendx()&&Me.y==Locker1.sendy())
            cout<<endl<<"\t\t\t\t\t\t\t"<<Locker1.sendname()<<endl;
        if(Me.y==Book1.sendy()&&(Me.x==Book1.sendx()||Me.x==Book6.sendx()||Me.x==Book5.sendx()||Me.x==Book4.sendx()||Me.x==Book3.sendx()||Me.x==Book2.sendx()))
            cout<<endl<<"\t\t\t\t\t\t\t"<<Book1.sendname()<<endl;
        if(Me.x==Shelf.sendx()&&Me.y==Shelf.sendy())
            cout<<endl<<"\t\t\t\t\t\t\t"<<Shelf.sendname()<<endl;
        if(Me.x==45&&Me.y==10)
            cout<<endl<<"\t\t\t\t\t\t\tFishtank"<<endl;
        if(Me.x==Vault.sendx()&&Me.y==Vault.sendy())
            cout<<endl<<"\t\t\t\t\t\t\t"<<Vault.sendname()<<endl;
        if((Me.y == Larder1.sendy()||Me.y == Larder2.sendy()||Me.y == Larder3.sendy()||Me.y == Larder4.sendy()||Me.y == Larder5.sendy())&&Me.x == Larder1.sendx())
            cout<<endl<<"\t\t\t\t\t\t\t"<<Larder1.sendname()<<endl;

        delay(0.10);

        char dum = tolower(getch());
        clearKeyboardBuffer();

        switch(dum)
        {
        case 'w'    :
            if(checkblock(Me.y-1,Me.x))
            {
                frame[Me.y][Me.x] = dummy;
                Me.y -=1;
                dummy = frame[Me.y][Me.x];
            }
            break;
        case 's'    :
            if(checkblock(Me.y+1,Me.x))
            {
                frame[Me.y][Me.x] = dummy;
                Me.y +=1;
                dummy = frame[Me.y][Me.x];
            }
            break;
        case 'a'    :
            if(checkblock(Me.y,Me.x-1))
            {
                if(frame[Me.y][Me.x-1]=='I'&&key==0)
                {
                    PlaySound(TEXT("sound\\conan.wav"),NULL,SND_LOOP|SND_ASYNC);
                    cout<<endl<<"\t\t\t\t\t\t       Needs a key"<<endl;
                    getch();

                }
                else
                {
                    frame[Me.y][Me.x] = dummy;
                    Me.x -=1;
                    dummy = frame[Me.y][Me.x];
                }

            }
            break;
        case 'd'    :
            if(checkblock(Me.y,Me.x+1))
            {
                frame[Me.y][Me.x] = dummy;
                Me.x +=1;
                dummy = frame[Me.y][Me.x];
            }
            break;
        case 'i'    :
            cout<<endl;
            showinventory();
            getch();

            break;
        case ' '    :
            if(checkobj(Me,Book1,&cptr))
                break;
            if(checkobj(Me,Book2,&cptr))
                break;
            if(checkobj(Me,Book3,&cptr))
                break;
            if(checkobj(Me,Book4,&cptr))
                break;
            if(checkobj(Me,Book5,&cptr))
                break;
            if(checkobj(Me,Book6,&cptr))
                break;
            if(checkobj(Me,Book7,&cptr))
                break;
            if(checkobj(Me,Vault,&cptr))
                break;
            if(checkobj(Me,Shelf,&cptr))
                break;
            if(checkobj(Me,Locker1,&cptr))
                break;
            if(checkobj(Me,Larder1,&cptr))
                break;
            if(checkobj(Me,Larder2,&cptr))
                break;
            if(checkobj(Me,Larder3,&cptr))
                break;
            if(checkobj(Me,Larder4,&cptr))
                break;
            if(checkobj(Me,Larder5,&cptr))
                break;

            if(Me.y==0&&dummy=='_')
            {
                cout<<"\n\t\t\t\t\t\tWanna to leave?(Y/N)"<<endl;
                if(tolower(getch())=='y')
                {
                    return 1;
                }
                break;
            }
            if(Me.x == 20 && Me.y == 3)
            {
                if(key == 0)
                {
                    cout <<endl << "\t\t\t\t\t\t        You get a key" << endl;
                    PlaySound(TEXT("sound\\conan2.wav"),NULL,SND_LOOP|SND_ASYNC);
                    key = 1;
                    getch();
                }
                break;
            }
            if(Me.x==45&&Me.y==10)
            {
                cout<<"\t\t\t         You are bitten by a fish! ahhhhhhhhhhhhhhhhhhhhhhhh "<<endl;
                getch();
                return 0;
            }
            break;
        default :
            cout<<endl<<endl<<endl;
            textcolor(DARKRED,YELLOW);
            cout<<"\t\t\t\t\t    PLEASE READ HOW TO PLAY FIRST\t\t\t\t\t\t        "<<endl;
            resetcolor();
            cout<<"\t\t\t\t\t    PRESS H to show to how to play"<<endl<<endl;

            if(tolower(getch())=='h')
            {
                textcolor(DARKYELLOW,0 );
                cout<<"\t\t\t\tPRESS";
                textcolor(AQUA,0 );
                cout<<"    'w' 'a' 's' 'd'             to move   "<<endl<<endl;
                textcolor(DARKYELLOW,0 );
                cout<<"\t\t\t\tPRESS";
                textcolor(AQUA,0 );
                cout<<"    'i'                         to check your inventory  "<<endl<<endl;
                textcolor(DARKYELLOW,0 );
                cout<<"\t\t\t\tPRESS";
                textcolor(AQUA,0 );
                cout<<"    'spacebar'                  to interact or  select "<<endl;
                resetcolor();
                system("PAUSE>NUL");
            }
        }
    }
    return 0;
}

int map3()
{
    download(3);
    int i,j ;
    setframe(15,53);
    PlaySound(TEXT("sound\\conan2.wav"),NULL,SND_LOOP|SND_ASYNC);
    for(j=18; j<45; j++)
    {
        frame[9][j]= '*';
        if(j>31&&j<36)
            frame[9][j]= '_';
    }

    for(i=1; i<15; i++)
    {
        if(i==4||i==5||i==6)
        {
            frame[3][28]='-';
            frame[7][28]='-';
            frame[i][19]='|';
            frame[i][20]='|';
            frame[i][28]='/';
            frame[i][29]=')';
        }
        if(i<8)
        {
            frame[i][49]='|';
            frame[i][50]='/';
            frame[i][51]='/';
        }
        else if(i==8)
        {
            frame[i][49]='=';
            frame[i][50]='=';
            frame[i][51]='=';
        }
        frame[i][45] = '*';
        if(i==5||i==4||i==11||i==12)
        {
            frame[i][45] = 'I';
        }
        if(i==10||i==13)
        {
            frame[i][22] = '*';
        }
        if(i==11||i==12)
        {
            frame[i][22] = 'I';
        }
        if(i<9)
        {
            frame[i][18] = '*';
        }
    }
    for(j=32; j<36; j++)
    {
        frame[14][j] = '_';
    }
    bed(6,2,4);
    box(1);
    vault(13,3,5);
    shelf(18);
    shelf(28);
    table(49,10,3,0);
    frame[10][52]='*';
    frame[11][52]='*';
    frame[12][52]='*';
    bookshelf(1,2,3);
    bookshelf(1,7,3);
    flower(24,13);
    flower(24,10);
    flower(43,10);
    flower(43,13);

    NPC Me;
    Me.x = 33;
    Me.y = 13;
    Me.picture = 'O';
    char dummy = ' ';

    NPC enemy1;
    enemy1.x = 5;
    enemy1.y = 5;
    enemy1.picture = 'X';
    int countenemy1=0,dumenemy1 = 1;
    char dummyenemy1 = ' ';
    int wayx[]= {6,6,6,6,6,6, 6, 7, 8, 9,10,11,12,13,14,14,15,16,17,18,19,20,21,22,23,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,47,47,47,47,47,47,48};
    int wayy[]= {4,5,6,7,8,9,10,10,10,10,10,10,10,10,10,11,11,11,11,11,11,11,11,11,11,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,11,10, 9, 8, 7, 6, 6};
    int wayx2[]= {6,7,8,8,8,9,10,11,12,13,14,14,14,14,14,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,32,32,32,31,30,29,28,27,27,27,27,28,28,28,28,28,28,28,28,28,28,28,28};
    int wayy2[]= {4,4,4,5,6,6, 6, 6, 6, 6, 6, 7, 8, 9,10,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,10, 9, 8, 8, 8, 8, 8, 8, 7, 6, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5};
    int doorlock = 1,waytype = 1;

    OBJ Book1("Bookshelf",3,3,"10 Dollar",10);
    OBJ Shelf1("Shelf",3,8);
    OBJ Locker1("Locker",6,11,"Crowbar",2);
    Locker1.getlock(1);
    OBJ Vault1("Vault",15,4,"Mask",2);
    Vault1.getlock(1);
    OBJ Shelf2("Shelf",24,2);
    OBJ Book2("Bookshelf",34,2);
    OBJ Larder1("Larder",48,1);
    OBJ Larder2("Larder",48,2);
    OBJ Larder3("Larder",48,3);
    OBJ Larder4("Larder",48,4);
    OBJ Larder5("Larder",48,5);
    OBJ Larder6("Larder",48,6);
    OBJ Larder7("Larder",48,7);


    Inventory *cptr = settotail();
    clock_t st=clock();
    clock_t ct=clock();
    int timer = 6;

    while(1)
    {
        frame[Me.y][Me.x]=Me.picture;

        ct=clock();

        frame[enemy1.y][enemy1.x] = dummyenemy1;
        if((ct-st)/1000%(rand()%timer+1)==0)
        {
            if(dumenemy1==1)
            {
                if(countenemy1==57)
                    dumenemy1*=-1;
                else
                {
                    if(waytype == 1)
                    {
                        timer = see(enemy1.x, enemy1.y,wayx[countenemy1],wayy[countenemy1]);
                        enemy1.x = wayx[countenemy1];
                        enemy1.y = wayy[countenemy1];
                    }
                    else
                    {
                        timer = see(enemy1.x, enemy1.y,wayx2[countenemy1],wayy2[countenemy1]);
                        enemy1.x = wayx2[countenemy1];
                        enemy1.y = wayy2[countenemy1];
                    }
                    if(!timer)
                        return 0;
                    dummyenemy1 = frame[enemy1.y][enemy1.x];
                    countenemy1++;
                }
            }
            else
            {
                countenemy1--;
                if(waytype == 1)
                {
                    timer = see(enemy1.x, enemy1.y,wayx[countenemy1],wayy[countenemy1]);
                    enemy1.x = wayx[countenemy1];
                    enemy1.y = wayy[countenemy1];
                }
                else
                {
                    timer = see(enemy1.x, enemy1.y,wayx2[countenemy1],wayy2[countenemy1]);
                    enemy1.x = wayx2[countenemy1];
                    enemy1.y = wayy2[countenemy1];
                }
                if(!timer)
                    return 0;
                dummyenemy1 = frame[enemy1.y][enemy1.x];
                if(countenemy1==0)
                {
                    dumenemy1*=-1;
                    waytype *= -1;
                }
            }
        }
        frame[enemy1.y][enemy1.x] = enemy1.picture;

        if((enemy1.y == 12||enemy1.y == 11)&&enemy1.x == 22)
            doorlock *= -1;

        system("cls");
        showframe(15,53);


        if((Me.x==Locker1.sendx()&&Me.y==Locker1.sendy()))
            cout<<endl<<"\t\t\t\t\t\t\t"<<Locker1.sendname()<<endl;
        if((Me.x==Shelf1.sendx()&&Me.y==Shelf1.sendy())||(Me.x==Shelf2.sendx()&&Me.y==Shelf2.sendy()))
            cout<<endl<<"\t\t\t\t\t\t\t"<<Shelf1.sendname()<<endl;
        if((Me.x==Book1.sendx()&&Me.y==Book1.sendy())||(Me.x==Book2.sendx()&&Me.y==Book2.sendy()))
            cout<<endl<<"\t\t\t\t\t\t\t"<<Book1.sendname()<<endl;
        if((Me.x==Vault1.sendx()&&Me.y==Vault1.sendy()))
            cout<<endl<<"\t\t\t\t\t\t\t"<<Vault1.sendname()<<endl;
        if(Me.x==Larder1.sendx()&&(Me.y==Larder1.sendy()||Me.y==Larder2.sendy()||Me.y==Larder3.sendy()||Me.y==Larder4.sendy()||Me.y==Larder5.sendy()||Me.y==Larder6.sendy()||Me.y==Larder7.sendy()))
            cout<<endl<<"\t\t\t\t\t\t\t"<<Larder1.sendname()<<endl;

        delay(0.2);

        if(kbhit())
        {
            char dum = tolower(getch());
            clearKeyboardBuffer();

            switch(dum)
            {
            case 'w'    :
                if(checkblock(Me.y-1,Me.x))
                {
                    frame[Me.y][Me.x] = dummy;
                    Me.y -=1;
                    dummy = frame[Me.y][Me.x];
                }
                break;
            case 's'    :
                if(checkblock(Me.y+1,Me.x))
                {
                    frame[Me.y][Me.x] = dummy;
                    Me.y +=1;
                    dummy = frame[Me.y][Me.x];
                }
                break;
            case 'a'    :
                if(checkblock(Me.y,Me.x-1))
                {
                    if(frame[Me.y][Me.x-1]=='I'&&doorlock==1&&Me.x-1==22)
                    {
                        PlaySound(TEXT("sound\\conan.wav"),NULL,SND_LOOP|SND_ASYNC);
                        cout<<endl<<"\t\t\t\t\t\t       Needs a key"<<endl;
                        getch();

                    }
                    else
                    {
                        frame[Me.y][Me.x] = dummy;
                        Me.x -=1;
                        dummy = frame[Me.y][Me.x];
                    }
                    break;
                }
            case 'd'    :
                if(checkblock(Me.y,Me.x+1))
                {
                    frame[Me.y][Me.x] = dummy;
                    Me.x +=1;
                    dummy = frame[Me.y][Me.x];
                }
                break;
            case 'i'    :
                cout<<endl;
                showinventory();
                getch();

                break;
            case ' '    :
                if(dummy=='_'&&Me.y==14)
                {
                    cout<<"\n\t\t\t\t\t\tWanna to leave?(Y/N)"<<endl;

                    if(tolower(getch())=='y')
                    {
                        if(finditem(&cptr,"Mask"))
                        {
                            return 1;
                        }
                        else
                            return 2;
                    }
                    break;
                }
                if(checkobj(Me,Book1,&cptr))
                    break;
                if(checkobj(Me,Book2,&cptr))
                    break;
                if(checkobj(Me,Shelf1,&cptr))
                    break;
                if(checkobj(Me,Shelf2,&cptr))
                    break;
                if(checkobj(Me,Vault1,&cptr))
                    break;
                if(checkobj(Me,Locker1,&cptr))
                    break;
                if(checkobj(Me,Larder1,&cptr))
                    break;
                if(checkobj(Me,Larder2,&cptr))
                    break;
                if(checkobj(Me,Larder3,&cptr))
                    break;
                if(checkobj(Me,Larder4,&cptr))
                    break;
                if(checkobj(Me,Larder5,&cptr))
                    break;
                if(checkobj(Me,Larder6,&cptr))
                    break;
                if(checkobj(Me,Larder7,&cptr))
                    break;
              break;

            default :
                cout<<endl<<endl<<endl;
                textcolor(DARKRED,YELLOW);
                cout<<"\t\t\t\t\t    PLEASE READ HOW TO PLAY FIRST\t\t\t\t\t\t        "<<endl;
                resetcolor();

                cout<<"\t\t\t\t\t    PRESS H to show to how to play"<<endl<<endl;

                if(tolower(getch())=='h')
                {
                    textcolor(DARKYELLOW,0 );
                    cout<<"\t\t\t\tPRESS";
                    textcolor(AQUA,0 );
                    cout<<"    'w' 'a' 's' 'd'             to move   "<<endl<<endl;
                    textcolor(DARKYELLOW,0 );
                    cout<<"\t\t\t\tPRESS";
                    textcolor(AQUA,0 );
                    cout<<"    'i'                         to check your inventory  "<<endl<<endl;
                    textcolor(DARKYELLOW,0 );
                    cout<<"\t\t\t\tPRESS";
                    textcolor(AQUA,0 );
                    cout<<"    'spacebar'                  to interact or  select "<<endl;
                    resetcolor();
                    system("PAUSE>NUL");
                }
            }
        }
    }
}

int map4()
{
    download(4);
    PlaySound(TEXT("sound\\conan2.wav"),NULL,SND_LOOP|SND_ASYNC);
    int i,j;
    setframe(15,53);
    flower(44,13);
    flower(25,6);
    flower(25,2);
    flower(24,9);
    flower(10,7);
    flower(3,7);
    flower(41,4);
    flower(50,4);
    shelf(38);
    box(25);
    table(15,1,2,1);
    bookshelf(1,2,1);
    bookshelf(1,10,3);
    bed(13,10,4);
    for(j=0; j<53; j++)
    {
        frame[8][j] = '*';
        if((j>4&&j<9)||(j>19&&j<22)||(j>39&&j<42))
        {
            frame[8][j]='_';
        }
        if(j<9)
        {
            frame[4][j] = '*';
        }
        if(j>33)
        {
            frame[3][j] = '*';
            if(j>35&&j<40)
            {
                frame[3][j] = '_';
            }
        }
        if(j>46&&j<51)
        {
            frame[14][j] = '_';
        }
    }
    for(i=0; i<14; i++)
    {
        if(i>=8)
        {
            frame[i][18] = '*';
            frame[i][38] = '*';
        }
        if(i<8)
        {
            frame[i][23] = '*';
            if(i==4)
            {
                frame[i][23] = 'I';
            }
        }
        if(i<4)
        {
            frame[i][33] = '*';

        }
        if(i>3&&i<8)
        {
            frame[i][43] = '*';
            if(i==7)
            {
                frame[i][43] = 'I';
            }
        }
        if(i<5)
        {
            frame[i][8] = '*';
            if(i==2)
            {
                frame[i][8] = 'I';
            }
        }
    }
    for(i=45; i<48; i++)
    {
        frame[4][i] ='=';
    }
    frame[5][46]='0';

    NPC Me;
    Me.x = 50;
    Me.y = 13;
    Me.picture = 'O';
    char dummy = ' ';

    NPC enemy1,enemy2;
    enemy1.x = 21;
    enemy1.y = 13;
    enemy2.x = 5;
    enemy2.y = 2;
    enemy1.picture = 'X',enemy2.picture = 'X';
    int countenemy1=0,dumenemy1=1,countenemy2=0,dumenemy2=1;
    char dummyenemy1=' ',dummyenemy2=' ';
    int wayx1[]= {21,21,21,21,22,23,24,25,24,23,22,21,21,21,21,21,20,19,18,17,16,15,14,13,12,11,10, 9, 8, 7, 7, 7, 7, 7, 7, 8, 9,10,11,12,13,14,14,14,14,14,15};//47
    int wayy1[]= {13,12,11,10,10,10,10,10,10,10,10,10, 9, 8, 7, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 7, 8, 9,10,11,11,11,11,11,11,11,11,11,11,11,11,11};
    int wayx2[]= { 5, 6, 7, 8, 9,10,11,12,13,14,15,15,15,15,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,36,36,36,36,36,36,36,36,37,38,39,40,41};
    int wayy2[]= { 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 3, 2, 2, 2, 3, 4, 3, 2, 2, 2, 2, 2, 2};
    int timer1=1,timer2=1;

    OBJ Locker1("Locker",30,11,"Mask",1);
    Locker1.getlock(1);
    OBJ Book1("Bookshelf",3,11);
    OBJ Shelf1("Shelf",44,2,"LockPick",1);
    OBJ Chest1("Machine",3,2,"Mask",1);

    int key = 0,delaygen = 0;

    Inventory *cptr = settotail();
    clock_t st=clock();
    clock_t ct=clock();

    while(1)
    {
        frame[Me.y][Me.x]=Me.picture;

        ct=clock();

        if((ct-st)/1000%(20+delaygen*5)==19)
        {
            if(delaygen==0)
            {
                Chest1.additemdata("Mask",1);
                delaygen=1;
            }
            else
                delaygen = 0;

        }


        frame[enemy1.y][enemy1.x] = dummyenemy1;
        if((ct-st)/1000%(rand()%timer1+1)==0)
        {
            if(dumenemy1==1)
            {
                if(countenemy1==47)
                {
                    dumenemy1*=-1;
                }
                else
                {
                    timer1=see(enemy1.x, enemy1.y,wayx1[countenemy1],wayy1[countenemy1]);
                    if(!timer1)
                    {
                        return 0;
                    }
                    enemy1.x = wayx1[countenemy1];
                    enemy1.y = wayy1[countenemy1];
                    dummyenemy1 = frame[enemy1.y][enemy1.x];
                    countenemy1++;
                }
            }
            else
            {
                countenemy1--;
                timer1=see(enemy1.x, enemy1.y,wayx1[countenemy1],wayy1[countenemy1]);
                if(!timer1)
                {
                    return 0;
                }
                enemy1.x = wayx1[countenemy1];
                enemy1.y = wayy1[countenemy1];
                dummyenemy1 = frame[enemy1.y][enemy1.x];
                if(countenemy1==0)
                {
                    dumenemy1*=-1;
                }
            }
        }
        if(see(enemy1.x, enemy1.y,enemy1.x,enemy1.y))
            frame[enemy1.y][enemy1.x] = enemy1.picture;

        frame[enemy2.y][enemy2.x] = dummyenemy2;
        if((ct-st)/1000%(rand()%timer2+1)==0)
        {
            if(dumenemy2==1)
            {
                if(countenemy2==49)
                {
                    dumenemy2*=-1;
                }
                else
                {
                    timer2=see(enemy2.x, enemy2.y,wayx2[countenemy2],wayy2[countenemy2]);
                    if(!timer2)
                    {
                        return 0;
                    }
                    enemy2.x = wayx2[countenemy2];
                    enemy2.y = wayy2[countenemy2];
                    dummyenemy2 = frame[enemy2.y][enemy2.x];
                    countenemy2++;
                }
            }
            else
            {
                countenemy2--;
                timer2=see(enemy2.x, enemy2.y,wayx2[countenemy2],wayy2[countenemy2]);
                if(!timer2)
                {
                    return 0;
                }
                enemy2.x = wayx2[countenemy2];
                enemy2.y = wayy2[countenemy2];
                dummyenemy2 = frame[enemy2.y][enemy2.x];
                if(countenemy2==0)
                {
                    dumenemy2*=-1;
                }
            }
        }
        if(see(enemy2.x, enemy2.y,enemy2.x,enemy2.y))
            frame[enemy2.y][enemy2.x] = enemy2.picture;

        system("cls");
        showframe(15,53);

        if((Me.x==Locker1.sendx()&&Me.y==Locker1.sendy()))
            cout<<endl<<"\t\t\t\t\t\t\t"<<Locker1.sendname()<<endl;
        if((Me.x==Shelf1.sendx()&&Me.y==Shelf1.sendy()))
            cout<<endl<<"\t\t\t\t\t\t\t"<<Shelf1.sendname()<<endl;
        if((Me.x==Book1.sendx()&&Me.y==Book1.sendy()))
            cout<<endl<<"\t\t\t\t\t\t\t"<<Book1.sendname()<<endl;
        if((Me.x==Chest1.sendx()&&Me.y==Chest1.sendy()))
            cout<<endl<<"\t\t\t\t\t\t\t"<<Chest1.sendname()<<endl;

        delay(0.10);

        if(kbhit())
        {
            char dum = tolower(getch());
            clearKeyboardBuffer();

            switch(dum)
            {
            case 'w'    :
                if(checkblock(Me.y-1,Me.x))
                {
                    frame[Me.y][Me.x] = dummy;
                    Me.y -=1;
                    dummy = frame[Me.y][Me.x];
                }
                break;
            case 's'    :
                if(checkblock(Me.y+1,Me.x))
                {
                    frame[Me.y][Me.x] = dummy;
                    Me.y +=1;
                    dummy = frame[Me.y][Me.x];
                }
                break;
            case 'a'    :
                if(checkblock(Me.y,Me.x-1))
                {
                    if(frame[Me.y][Me.x-1]=='I'&&Me.y==2&&key==0)
                    {
                        PlaySound(TEXT("sound\\conan.wav"),NULL,SND_LOOP|SND_ASYNC);
                        cout<<endl<<"\t\t\t\t\t\t       Needs a key"<<endl;
                        getch();
                    }
                    else
                    {
                        frame[Me.y][Me.x] = dummy;
                        Me.x -=1;
                        dummy = frame[Me.y][Me.x];
                    }
                }
                break;
            case 'd'    :
                if(checkblock(Me.y,Me.x+1))
                {
                    frame[Me.y][Me.x] = dummy;
                    Me.x +=1;
                    dummy = frame[Me.y][Me.x];
                }
                break;
            case 'i'    :
                cout<<endl;
                showinventory();
                getch();
                break;
            case ' '    :
                if(dummy=='_'&&Me.y==14)
                {
                    cout<<"\n\t\t\t\t\t\tWanna to leave?(Y/N)";
                    if(tolower(getch())=='y')
                    {
                        return 1;
                    }
                    break;
                }
                if(checkobj(Me,Book1,&cptr))
                    break;
                if(checkobj(Me,Locker1,&cptr))
                    break;
                if(checkobj(Me,Shelf1,&cptr))
                    break;
                if(checkobj(Me,Chest1,&cptr))
                    break;
                if(Me.x==24&&Me.y==10)
                {
                    if(key == 0)
                    {
                        PlaySound(TEXT("sound\\conan2.wav"),NULL,SND_LOOP|SND_ASYNC);
                        cout <<endl << "\t\t\t\t\t\t        You get a key" << endl;
                        key = 1;
                        getch();
                    }
                    break;
                }
                break;
            default :
                cout<<endl<<endl<<endl;
                textcolor(DARKRED,YELLOW);
                cout<<"\t\t\t\t\t    PLEASE READ HOW TO PLAY FIRST\t\t\t\t\t\t        "<<endl;
                resetcolor();

                cout<<"\t\t\t\t\t    PRESS H to show to how to play"<<endl<<endl;

                if(tolower(getch())=='h')
                {
                    textcolor(DARKYELLOW,0 );
                    cout<<"\t\t\t\tPRESS";
                    textcolor(AQUA,0 );
                    cout<<"    'w' 'a' 's' 'd'             to move   "<<endl<<endl;
                    textcolor(DARKYELLOW,0 );
                    cout<<"\t\t\t\tPRESS";
                    textcolor(AQUA,0 );
                    cout<<"    'i'                         to check your inventory  "<<endl<<endl;
                    textcolor(DARKYELLOW,0 );
                    cout<<"\t\t\t\tPRESS";
                    textcolor(AQUA,0 );
                    cout<<"    'spacebar'                  to interact or  select "<<endl;
                    resetcolor();
                    system("PAUSE>NUL");
                }
            }
        }
    }

    return 0;
}



#endif // CHAPTER_H_INCLUDED
