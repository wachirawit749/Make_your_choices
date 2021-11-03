#include <iostream>
#include <cstdlib>
#include <time.h>
#include <iomanip>
#include <conio.h>
#include<windows.h>
#include<string.h>

using namespace std;
char frame[15][54];
#include "color.h"
#include "Timefunc.h"
#include "minigame.h"
#include "item.h"
#include "Node.h"
#include "Character.h"
#include "interface.h"
#include "Object.h"
#include "download.h"
#include "Chapter.h"
#include "Mainscreen.h"


int main()
{
    home();
    system("PAUSE>NUL");
    PlaySound(TEXT("sound\\conan1.wav"),NULL,SND_LOOP|SND_ASYNC);
    delay(0.5);
    int sel=1;
    mainsc(sel);

    while(1)
    {
        system("cls");
        if(kbhit())
        {
            char dum=getch();
            clearKeyboardBuffer();
            try
            {
                if((dum=='w'||dum=='W'))
                {
                    if(sel>1)
                    {
                        sel-=1;
                    }
                    else
                    {
                        sel=4;
                    }
                }
                else if((dum=='s'||dum=='S'))
                {
                    if(sel<4)
                    {
                        sel+=1;
                    }
                    else
                    {
                        sel=1;
                    }
                }
                else if(dum==' ')
                {
                    selected(sel);
                }
                else
                {
                    throw dum;
                }
            }
            catch(char dum)
            {
                textcolor(DARKRED,YELLOW);
                cout<<"\t\t\t\t\t "<< dum<<"? PLEASE READ HOW TO PLAY FIRST\t\t\t\t\t\t"<<endl;
                resetcolor();
            }
        }
        mainsc(sel);
        delay(0.3);
    }
    return 0;
}
