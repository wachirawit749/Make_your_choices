#ifndef MAINSCREEN_H_INCLUDED
#define MAINSCREEN_H_INCLUDED

void gameover()
{
    cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
    textcolor(WHITE,0 );
    cout<<"\t\t     llll   l     lll  11    11 1111             1111  1  1    1  11    11 111   11" <<endl ;
    cout<<"\t\t     lll  lll lll  lll 11   1   1               111  111 11    11   1      11     1"<<endl;
    textcolor(GRAY,0 );
    cout<<"\t\t     lll      lll    l 11   111 111             1 1  111 11       111      11   11" <<endl ;
    cout<<"\t\t     lll ll   lll    l    11 11 111    1        111    1 11    11 1    111 1    " <<endl ;
    textcolor(DARKGRAY,0 );
    cout<<"\t\t     lll   ll lll  lll 11    1  111             111  111  1   1   111      1    1"  <<endl;
    cout<<"\t\t     ll   lll lll  lll 11     1 1     11        11     1          1      1       1 " <<endl ;


    delay(1);
    system("cls");



    cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
    textcolor(WHITE,0 );
    cout<<"\t\t     llllllll llllllll 11    11 11111111        11111111 11    11 11111111 11111111" <<endl ;
    cout<<"\t\t     lll  lll lll  lll 111  111 111             111  111 11    11 111      11    11"<<endl;
    textcolor(GRAY,0 );
    cout<<"\t\t     lll      lll  lll 11111111 111             111  111 11    11 111      11   11" <<endl ;
    cout<<"\t\t     lll llll lll11lll 11 11 11 11111111        111  111 11    11 11111111 11 11" <<endl ;
    textcolor(DARKGRAY,0 );
    cout<<"\t\t     lll   ll lll  lll 11    11 111             111  111  11  11  111      11  11"  <<endl;
    cout<<"\t\t     llllllll lll  lll 11    11 11111111        11111111    11    11111111 11    11" <<endl ;
    system("PAUSE>NUL");
    system("cls");

    cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
    textcolor(WHITE,0 );
    cout<<"\t\t     ll     l     l    11    11                 1     1  1    1  11    11   1   11" <<endl ;
    cout<<"\t\t     l      l l l  lll 11   1   1               111  111 11    11   1      11     1"<<endl;
    textcolor(GRAY,0 );
    cout<<"\t\t     lll      lll    l 11   111 111             1 1  111 11       111      11   11" <<endl ;
    cout<<"\t\t     lll ll   lll    l    11 11 111    1        111    1 11    11 1    111 1    " <<endl ;
    textcolor(DARKGRAY,0 );
    cout<<"\t\t     lll   ll lll  lll 11    1  111             111  111  1   1   111      1    1"  <<endl;
    cout<<"\t\t     ll   lll lll  lll 11     1 1     11        11     1          1      1       1 " <<endl ;
    delay(0.1);
    system("cls");
    cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
    textcolor(WHITE,0 );
    cout<<"\t\t            l     l    1                              1       1             1   1 " <<endl ;
    cout<<"\t\t     l      l   l  l   1    1   1                        11    11   1      11     1"<<endl;
    textcolor(GRAY,0 );
    cout<<"\t\t     l               l 11                       1 1                 1      11   11" <<endl ;
    cout<<"\t\t     l l ll     l    l    11 11 111    1        111    1 11    11 1    111 1    " <<endl ;
    textcolor(DARKGRAY,0 );
    cout<<"\t\t           ll l     ll 11    1  111                  11   1   1                 "  <<endl;
    cout<<"\t\t     ll   lll lll  lll 11     1 1     11        11     1          1      1       1 " <<endl ;
    delay(0.1);
    system("cls");
    cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
    cout<<"\t\t\t\t\t\t  You have been arrested";
    system("PAUSE>NUL");
    system("cls");
}

void endgame()
{
    system("cls");
    PlaySound(TEXT("sound\\endgame.wav"),NULL,SND_LOOP|SND_ASYNC);
    char endt[] ="          You will be able to steal things, but after you detect that you are infected with covid-19";
    char endt1[]="          and you have a serious condition causing 1 month after you die";
    char endt2[]="                                                                                 thank you for playing";
    textcolor(CYAN,0 );
    reading150plus(endt,strlen(endt),0.06);
    reading150plus(endt1,strlen(endt1),0.06);

    cout<<endl<<endl<<endl<<endl<<endl;
    cout<<"\t\t\t\t\t11111111 11    11 11111111      11111111 111   11 11111      "<<endl;
    cout<<"\t\t\t\t\t   11    11    11 11            11       1111  11 11   11    "<<endl;
    textcolor(BLUE,0 );
    cout<<"\t\t\t\t\t   11    11    11 11            11       11 11 11 11    11   "<<endl;
    cout<<"\t\t\t\t\t   11    11111111 11111111      11111111 11  1111 11    11   "<<endl;
    textcolor(DARKBLUE,0 );
    cout<<"\t\t\t\t\t   11    11    11 11            11       11   111 11   11    "<<endl;
    cout<<"\t\t\t\t\t   11    11    11 11111111      11111111 11    11 11111      "<<endl;
    textcolor(RED,0 );
    cout<<endl<<endl<<endl;
    reading150plus(endt2,strlen(endt2),0.06);
    system("PAUSE>NUL");
    system("cls");

}
void home()
{
    PlaySound(TEXT("sound\\home.wav"),NULL,SND_LOOP|SND_ASYNC);
    cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
    textcolor(DARKRED,0 );
    cout<<"\t\t11    11 llllllll 111   11 11111111      11    11 11111111 11    11 11111111    " <<endl ;
    cout<<"\t\t111  111 lll  lll 111  11  111           11    11 111  111 11    11 11    11    "<<endl;
    textcolor(RED,0 );
    cout<<"\t\t11111111 lll  lll 111 11   111           11    11 111  111 11    11 11   11     " <<endl ;
    cout<<"\t\t11 11 11 lll11lll 11111    11111111       111111  111  111 11    11 11 11       " <<endl ;
    textcolor(YELLOW,0 );
    cout<<"\t\tll    ll lll  lll 111  11  111              11    111  111 11    11 11  11      "  <<endl;
    cout<<"\t\tll    ll lll  lll 111   11 11111111         11    11111111 11111111 11    11    " <<endl<<endl <<endl  ;
    textcolor(GREEN,0 );
    cout<<"\t\t\t\t   11111111 11    11 11111111 11111111 11111111 11111111  "<<endl ;
    cout<<"\t\t\t\t   11       11    11 11    11    11    11       111       "<<endl;
    textcolor(CYAN,0 );
    cout<<"\t\t\t\t   11       11    11 11    11    11    11       111       "<<endl ;
    cout<<"\t\t\t\t   11       11111111 11    11    11    11       11111111  "<<endl ;
    textcolor(DARKBLUE,0 );
    cout<<"\t\t\t\t   11       11    11 11    11    11    11       111       "<<endl;
    textcolor(VIOLET,0 );
    cout<<"\t\t\t\t   11111111 11    11 11111111 11111111 11111111 11111111    0  0  0  0 " <<endl ;
}
void howtoplay()
{
    textcolor(DARKRED,0 );
    cout<<" ___  ___  ________  ___       __           _________  ________          ________  ___       ________      ___    ___ "<<endl;
    textcolor(RED,0 );
    cout<<"|\\  \\|\\  \\|\\   __  \\|\\  \\     |\\  \\        |\\___   ___\\\\   __  \\        |\\   __  \\|\\  \\     |\\   __  \\    |\\  \\  /  /|"<<endl;
    textcolor(YELLOW,0 );
    cout<<"\\ \\  \\\\\\  \\ \\  \\|\\  \\ \\  \\    \\ \\  \\       \\|___ \\  \\_\\ \\  \\|\\  \\       \\ \\  \\|\\  \\ \\  \\    \\ \\  \\|\\  \\   \\ \\  \\/  / /"<<endl;
    textcolor(GREEN,0 );
    cout<<" \\ \\   __  \\ \\  \\\\\\  \\ \\  \\  __\\ \\  \\           \\ \\  \\ \\ \\  \\\\\\  \\       \\ \\   ____\\ \\  \\    \\ \\   __  \\   \\ \\    / / "<<endl;
    textcolor(CYAN,0 );
    cout<<"  \\ \\  \\ \\  \\ \\  \\\\\\  \\ \\  \\|\\__\\_\\  \\           \\ \\  \\ \\ \\  \\\\\\  \\       \\ \\  \\___|\\ \\  \\____\\ \\  \\ \\  \\   \\/   / /  "<<endl;
    textcolor(DARKBLUE,0 );
    cout<<"   \\ \\__\\ \\__\\ \\_______\\ \\____________\\           \\ \\__\\ \\ \\_______\\       \\ \\__\\    \\ \\_______\\ \\__\\ \\__\\  /   / /    "<<endl;
    textcolor(VIOLET,0 );
    cout<<"    \\|__|\\|__|\\|_______|\\|____________|            \\|__|  \\|_______|        \\|__|     \\|_______|\\|__|\\|__|\ /__ / /   "<<endl;
    cout<<"                                                                                                          |____|/      "<<endl<<endl<<endl<<endl;
    delay(0.8);
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
    cout<<"    'spacebar'                  to interact or  select "<<endl<<endl<<endl;
    textcolor(DARKRED,0 );
    cout<<"\t\t\t    - Bringing things internally on each side to be used to survive -"<<endl<<endl<<endl<<endl;
    cout<<"\t\t\t\t\t\t     - Warning -"<<endl<<endl;
    textcolor(BLUE,0 );
    cout<<"\t\t\t\t        Set the language to English when playing "<<endl<<endl;
    cout<<"\t\t\t\t\t   Do not press the button repeatedly "<<endl<<endl;
    cout<<"\t\t\t\t\t     Set the layout screen 120 x 30 "<<endl;
    system("PAUSE>NUL");

    setframe(15,53);
    car(25);
    box(0);
    shelf(2);
    bookshelf(2,4,5);
    table(15,1,3,1);
    bed(13,10,5);
    flower(25,13);
    vault(25,10,5);
    desk(35,12,5);
    frame[10][38] ='1';
    frame[3][36] ='2';
    frame[12][25] ='3';
    frame[11][27] ='4';
    frame[8][15] ='5';
    frame[11][6] ='6';
    frame[6][5] ='7';
    frame[2][7] ='7';
    frame[4][17] ='8';


    showframe(15,53);
    textcolor(AQUA,0 );
    cout<<endl;
    cout<<"\t\t\t\t\t   1.Fishtank            5.Bed"<<endl;
    cout<<"\t\t\t\t\t   2.Car                 6.Locker"<<endl;
    cout<<"\t\t\t\t\t   3.Flower              7.Shelf"<<endl;
    cout<<"\t\t\t\t\t   4.Vault               8.Table"<<endl;


}

void mainsc(int sel)
{

    textcolor(DARKYELLOW,0);
    cout<<"\n\n\t\t\t\t      ****                                ****\n";
    textcolor(YELLOW,0);
    cout<<"\t\t\t\t      **                                    **\n";
    cout<<"\t\t\t\t      *                                      *\n";
    resetcolor();
    cout<<"\t\t\t\t                      ";
    if(sel == 1)
    {
        textcolor(RED,0);
        cout<<">New Game<\n\n";
        resetcolor();
    }

    else
        printf(" New Game \n\n");

    cout<<"\t\t\t\t                     ";
    if(sel == 2)
    {
        textcolor(RED,0);
        cout<<">How to Play<\n\n" ;
        resetcolor();
    }

    else
        cout<<" How to Play \n\n" ;

    cout<<" \t\t\t\t                       ";
    if(sel == 3)
    {
        textcolor(RED,0);
        cout<<">Credit<\n\n";
        resetcolor();
    }
    else
        cout<<" Credit \n\n";

    cout<<"\t\t\t\t                        ";
    if(sel == 4)
    {
        textcolor(RED,0);
        cout<<">Quit<\n\n";
        resetcolor();
    }
    else
        cout<<" Quit \n\n";

    cout<<"\t\t\t\t       (Press W/S to move Spacebar to select) \n\n";
    textcolor(YELLOW,0);
    cout<<"\t\t\t\t      *                                      *\n";
    cout<<"\t\t\t\t      **                                    **\n";
    textcolor(DARKYELLOW,0);
    cout<<"\t\t\t\t      ****                                ****\n";
    resetcolor();
}

void selected(int sel)
{
    if(sel==4)
    {
        exit(EXIT_SUCCESS);
    }
    if(sel==3)
    {
        PlaySound(TEXT("sound\\credit.wav"),NULL,SND_LOOP|SND_ASYNC);
        cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
        textcolor(CYAN,0);
        cout<<" \t\t\t\t Creator:" ;
        textcolor(DARKYELLOW,0);
        cout<<"         Wachirawit  EGCO   6213145"<<endl<<endl;
        cout<<" \t\t\t\t                  Winn        EGCO   6213146"<<endl<<endl;
        textcolor(CYAN,0);
        cout<<"\t\t\t\t Credit music:";
        textcolor(RED,0);
        cout<<"    https://www.youtube.com/watch?v=VPib0K2AuO8"<<endl<<endl;
        cout<<"\t\t\t\t                  https://www.youtube.com/watch?v=ytfBg1PlkQs"<<endl<<endl;
        cout<<"\t\t\t\t                  https://www.youtube.com/watch?v=bXlKzZum4mg"<<endl<<endl;
        cout<<"\t\t\t\t                  https://www.youtube.com/watch?v=JRSO7sLrUbk"<<endl<<endl;
        cout<<"\t\t\t\t                  https://www.youtube.com/watch?v=uV87gEweaxI"<<endl<<endl;
        cout<<"\t\t\t\t                  https://www.youtube.com/watch?v=qxvzL8JGNYA"<<endl<<endl;
        cout<<"\t\t\t\t                  https://www.youtube.com/watch?v=xwiT4D26vME"<<endl<<endl<<endl<<endl;
        getch();
        int i;
        textcolor(GREEN,0);
        cout<<"\t\t\t\t Loading";
        for(i=0; i<6; i++)
        {
            cout<<'.';
            delay(0.25);
        }
        PlaySound(TEXT("sound\\conan1.wav"),NULL,SND_LOOP|SND_ASYNC);
    }
    if(sel==2)
    {
        PlaySound(TEXT("sound\\credit.wav"),NULL,SND_LOOP|SND_ASYNC);
        howtoplay();
        system("PAUSE>NUL");
        PlaySound(TEXT("sound\\conan1.wav"),NULL,SND_LOOP|SND_ASYNC);
    }
    if(sel==1)
    {
        head = NULL;
        int over = 1;
        if(over!=0)
        {
            over = map1();

        }
        if(over!=0)
        {
            over = map2();
        }
        if(over!=0)
        {
            over = map3();
            if(over==1)
            {
                over = map4();
            }
            else if(over==2)
            {
                over=1;
            }
        }
        deleteall();


        if(over==0)
        {
            system("cls");
            PlaySound(TEXT("sound\\conanend.wav"),NULL,SND_LOOP|SND_ASYNC);
            delay(1.5);
            gameover();
            PlaySound(TEXT("sound\\conan1.wav"),NULL,SND_LOOP|SND_ASYNC);
        }
        else
        {
            endgame();
            PlaySound(TEXT("sound\\conan1.wav"),NULL,SND_LOOP|SND_ASYNC);
        }

    }
    system("cls");
}
#endif // MAINSCREEN_H_INCLUDED
