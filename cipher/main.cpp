#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>

using namespace std;
ifstream fin("distribution.txt");

void letter_counter(char s[],float nr_arr[])
{

    for(int i=0;i<=25;i++)
    {
        nr_arr[i]=0;
        for(int j=0;j<strlen(s);j++)
        {
            if(s[j]=='A'+i)
                nr_arr[i]++;
        }
    }

}

void shift(char s[])
{
    for(int i=0;i<strlen(s);i++)
    {
        if(s[i]=='A')
            s[i]='Z';
        else
            if(s[i]>65 && s[i]<=90)
                s[i]--;
    }
}

void finally(char s[],float expected[],float nr_letters[])
{
    float minn=99999999,chi_sqare=0,expctd;
    char dechiphered[500];
    for(int i=0;i<=25;i++)
    {
        chi_sqare=0;
        letter_counter(s,nr_letters);
        for(int j=0;j<=25;j++)
        {
            //expctd=expected[j]*strlen(s);
            //chi_sqare+=((expctd-nr_letters[j])*(expctd-nr_letters[j]))/nr_letters[j];
            chi_sqare+=((nr_letters[j]-expected[j])*(nr_letters[j]-expected[j]))/expected[j];

        }
        if(chi_sqare<minn)
        {
            minn=chi_sqare;
            strcpy(dechiphered,s);
        }
        shift(s);
    }
    cout<<dechiphered;
}

int main()
{
    float v[27];
    float nr_arr[26]={};
    char s[500];
    for(int i=0;i<=25;i++)
    {
        fin>>v[i];
        //v[i]/=100;
    }
    cout<<"Please enter a text to decipher: \n";
    cin.get(s,500);
    cout<<'\n'<<"deciphering..."<<'\n'<<'\n';


    for(int i=0;i<strlen(s);i++)
    {
        s[i]=toupper(s[i]);
    }
    finally(s,v,nr_arr);
    return 0;
}
