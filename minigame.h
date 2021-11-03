#ifndef MINIGAME_H_INCLUDED
#define MINIGAME_H_INCLUDED

int minigame()
{
    char pic[7][25];
    int i,j;

    for(i=0; i<7; i++)
    {
        for(j=0; j<25; j++)
        {
            if(i==3||j==3||j==4||j==12||j==13)
            {
                if(i==0||((j==12||j==13)&&(i==1||i==2)))
                    pic[i][j]='X';
                else if(i==6||j==24)
                    pic[i][j]='*';
                else
                    pic[i][j]=' ';
            }
            else
                pic[i][j]='*';
        }
    }

    int Me=0;
    int enemy1=1,enemy2=3,enemy3=4;
    int help1=1,help2=1,help3=1;

    pic[enemy3][20] = 'X';
    pic[enemy3+1][20] = 'X';
    pic[enemy3-1][21] = 'X';
    pic[enemy3][21] = 'X';
    pic[enemy3+1][21] = 'X';

    pic[enemy1][3] = 'X';
    pic[enemy1][4] = 'X';

    pic[enemy2][12] = 'X';
    pic[enemy2][13] = 'X';
    pic[3][Me] = 'O';

    clock_t st=clock();
    clock_t ct;

    while(1)
    {
        ct = clock();

        if(pic[3][24]=='O')
        {
            cout<<endl<<"\t\t\t\t\t\t\t   Click";
            getch();

            return 1;
        }

        if(kbhit())
        {
            char dum = tolower(getch());;
            clearKeyboardBuffer();
            if(dum=='d')
                Me+=1;
            if(pic[3][Me]=='X')
            {
                cout<<endl<<"\t\t\t\t\t\t\t  Clang";
                getch();

                return 0;
            }
            if(dum=='a')
            {
                if(Me>0)
                {
                    pic[3][Me] = ' ';
                    Me-=1;
                }
                if(Me==19&&enemy3==-1)
                {
                    enemy3=3;
                }
            }
        }
        pic[3][Me] = 'O';

        if((((ct-st))/500%4 == 0||((ct-st))/500%4 == 2)&&enemy1!=-1)
        {
            //cout << " Active1 ";
            if(enemy1==5||enemy1==0)
                help1 *= -1;
            if(help1==1)
            {
                enemy1+=help1;
                if(pic[enemy1][3]=='O')
                    enemy1=-1;
                else
                {
                    pic[enemy1][3] = 'X';
                    pic[enemy1][4] = 'X';
                }
            }
            else
            {
                pic[enemy1][3] = ' ';
                pic[enemy1][4] = ' ';
                enemy1+=help1;
            }
        }

        if(((ct-st)/1000)%2 == 0&&enemy2!=-1)
        {
            //cout << " Active2 ";
            if(enemy2==5||enemy2==2)
                help2 *= -1;
            if(help2==1)
            {
                enemy2+=help2;
                if(pic[enemy2][12]=='O')
                    enemy2=-1;
                else
                {
                    pic[enemy2][12] = 'X';
                    pic[enemy2][13] = 'X';
                }
            }
            else
            {
                pic[enemy2][12] = ' ';
                pic[enemy2][13] = ' ';
                enemy2+=help2;
            }
        }

        if(((ct-st)/1000)%2 == 0&&enemy3!=-1)
        {
            if(enemy3==5||enemy3==3)
                help3 *= -1;
            if(help3==1)
            {
                enemy3-=help3;
                if(pic[enemy3][20]=='O'||pic[enemy3-1][21]=='O')
                    enemy3=-1;
                else
                {
                    pic[enemy3-1][21] = 'X';
                    pic[enemy3][20] = 'X';
                }
            }
            else
            {
                pic[enemy3][20] = ' ';
                pic[enemy3-1][21] = ' ';
                enemy3-=help3;
            }
        }

        delay(0.5);
        system("cls");
        cout<<endl<<endl<<endl;
        cout<<"\t\t\t\t\t\t";
        textcolor(8,8);
        cout<<"                         "<<endl;
        resetcolor();


        for(i=0; i<7; i++)
        {

            cout<<"\t\t\t\t\t\t";
            for(j=0; j<25; j++)
            {
                try
                {
                    if(pic[i][j]== 'O')
                    {
                        throw 10;
                    }
                    else if(pic[i][j]== 'X')
                    {
                        throw 12;
                    }
                    else if(i==3&&j==24)
                    {
                        throw 1;
                    }
                    else if(pic[i][j]== '*')
                    {
                        throw 8;
                    }
                    else
                    {
                        throw 7;
                    }
                }
                catch(int color)
                {
                    textcolor(color,color);
                }
                cout<<pic[i][j];
            }
            resetcolor();
            cout<<endl;
        }
    }
}

#endif // MINIGAME_H_INCLUDED
