#ifndef DOWNLOAD_H_INCLUDED
#define DOWNLOAD_H_INCLUDED
void download(int chap)
{
    PlaySound(TEXT("sound\\download.wav"),NULL,SND_LOOP|SND_ASYNC);
    char text1[]="          During a crisis, Covid-19 experienced difficulties";
    char text2[]="          From a shortage of masks, famine and leaders who are unable to help the people thoroughly";
    char text3[]="          So we have to find a mask to prevent Covid-19";
    char text4[]="          Don't have enough time";
    char text5[]="          Let's find the mask";
    char text6[]="          Some one tell me \"This building have mask machine\"";
    char text7[]="          This is the last way to give me survive";

    system("cls");
    cout<<endl;
    cout<<endl;

    if(chap == 1)
    {
        reading150plus(text1,strlen(text1),0.06);
        reading150plus(text2,strlen(text2),0.06);
        reading150plus(text3,strlen(text3),0.06);
    }
    else if(chap == 2)
    {
        cout<<endl<<endl<<endl;
        cout<<endl<<endl<<endl;
        cout<<endl<<endl<<endl;
    }
    else if(chap == 3)
    {
        reading150plus(text4,strlen(text4),0.06);
        reading150plus(text5,strlen(text5),0.06);
        cout<<endl<<endl<<endl;
    }
    else if(chap == 4)
    {
        reading150plus(text6,strlen(text6),0.06);
        reading150plus(text7,strlen(text7),0.06);
        cout<<endl<<endl<<endl;
    }

    char text[]="                                              Loading...                                             ";
    int i,j,k,h=0;
    i = strlen(text);
    for(j=0; j<i-1; j++)
    {
        system("cls");
        cout<<endl;
        cout<<endl;
        if(chap == 1)
        {
            reading150plus(text1,strlen(text1),0);
            reading150plus(text2,strlen(text2),0);
            reading150plus(text3,strlen(text3),0);
        }
        else if(chap == 2)
        {
            cout<<endl<<endl<<endl;
            cout<<endl<<endl<<endl;
            cout<<endl<<endl<<endl;
        }
        else if(chap == 3)
        {
            reading150plus(text4,strlen(text4),0);
            reading150plus(text5,strlen(text5),0);
            cout<<endl<<endl<<endl;
        }
        else if(chap == 4)
        {
            reading150plus(text6,strlen(text6),0);
            reading150plus(text7,strlen(text7),0);
            cout<<endl<<endl<<endl;
        }

        cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<"\t  ";
        textcolor(0,10);
        for(k=0; k<i-1; k++)
        {
            if(k>h)
            {
                textcolor(15,0);
            }
            if(text[k]=='.' && k<=h && h<i-4)
            {
                if((k+j)%4==1)
                    cout<<' ';
                else
                    cout<<text[k];
            }
            else
                cout<<text[k];
        }
        h++;
        delay(0.09);
    }
    system("PAUSE>NUL");
    resetcolor();
}


#endif // DOWNLOAD_H_INCLUDED
