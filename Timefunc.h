#ifndef TIMEFUNC_H_INCLUDED
#define TIMEFUNC_H_INCLUDED

void delay(float sec)
{
    float ms=1000*sec;
    clock_t st=clock();
    while(clock()<st+ms);
}

void clearKeyboardBuffer()
{
    while (_kbhit())
    {
        _getch();
    }
}

void reading150plus(char text[],int len,float t)
{
    cout<<endl<<endl<<endl;
    int i;
    for(i=0; i<len; i++)
    {
        cout<<text[i];
        delay(t);
    }
}


#endif // TIMEFUNC_H_INCLUDED
