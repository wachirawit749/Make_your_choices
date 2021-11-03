#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED


void setframe (int a,int b)
{

    int i,j;
    for(i=0; i<a; i++)
    {
        for(j=0; j<b; j++)
        {
            frame[i][j]=' ';
        }
    }
    for(i=0; i<a; i++)
    {
        frame[i][0] = '*';
        frame[i][b-1] = '*';

    }
    for(j=0; j<b; j++)
    {
        frame[0][j]='*';
        frame[a-1][j]='*';
    }
}

void showframe(int a,int b)
{
    int i,j;

    cout<<endl;
    for(i=0; i<a; i++)
    {
        cout<<"     \t\t\t\t";
        for(j=0; j<b; j++)
        {
            try
            {
                if(frame[i][j]== 'O')
                {
                    throw 15;
                }
                else if(frame[i][j]== 'X'||frame[i][j]== '.')
                {
                    throw 12;

                }

                else if(frame[i][j]== '/')
                {
                    throw 15;
                }
                else if(frame[i][j]== '*')
                {
                    throw 8;
                }
                else if(frame[i][j]== '+')
                {
                    throw 4;
                }
                else if(frame[i][j]== '('||frame[i][j]== ')')
                {
                    throw 6;
                }
                else if(frame[i][j]== 'I'||frame[i][j]== '_')
                {
                    throw 11;
                }
                else if(frame[i][j]== '|')
                {
                    throw 10;
                }
                else if(frame[i][j]== '-')
                {
                    throw 14;
                }

                else
                {
                    throw 3 ;
                }
            }
            catch(int color)
            {

               if(color==8)
               {
                    textcolor(color,color);
               }

                else if(color==12)
                {
                   textcolor(color,0);
                }
                else
                     textcolor(color,0);
            }
            cout<<frame[i][j];
        }
        resetcolor();
        cout<<endl;
    }
}
#endif // INTERFACE_H_INCLUDED
