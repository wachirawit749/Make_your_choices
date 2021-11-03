#ifndef CHARACTER_H_INCLUDED
#define CHARACTER_H_INCLUDED

typedef struct
{
    int x;
    int y;
    char picture;
} NPC;

int checkblock(int x,int y)
{
    if(frame[x][y]==' '||frame[x][y]=='_'||frame[x][y]=='I'||frame[x][y]=='/'||frame[x][y]=='0')
        return 1;
    else
        return 0;
}

int see(int x,int y,int x2,int y2)
{
    int i,j;
    int t=6;

    if(x==x2&&y!=y2)
    {
        t = 6;
        if(y>y2)
        {
            for(i=-2; i<3; i++)
            {
                if(frame[y+2][x+i]=='.')
                    frame[y+2][x+i]=' ';
            }
        }
        else
        {
            for(i=-2; i<3; i++)
            {
                if(frame[y-2][x+i]=='.')
                    frame[y-2][x+i]=' ';
            }
        }
    }
    else if(y==y2&&x!=x2)
    {
        t = 1;
        if(x>x2)
        {
            for(i=-2; i<3; i++)
            {
                if(frame[y+i][x+2]=='.')
                    frame[y+i][x+2]=' ';
            }
        }
        else
        {
            for(i=-2; i<3; i++)
            {
                if(frame[y+i][x-2]=='.')
                    frame[y+i][x-2]=' ';
            }
        }
    }

    for(i=x2-2; i<x2+3; i++)
    {
        for(j=y2-2; j<y2+3; j++)
        {
            if(i>0&&j>0&&i<54&&j<16)
            {
                if(frame[j][i]==' ')
                {
                    frame[j][i]='.';
                }
                else if(frame[j][i]=='O')
                {
                    return 0;
                }
            }
        }
    }
    return t;
}

#endif // CHARACTER_H_INCLUDED
