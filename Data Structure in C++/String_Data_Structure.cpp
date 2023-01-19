#include<iostream>
using namespace std;

int LENGTH(char s[])
{
    int cnt=0;
    while(s[cnt]!='\0')
    cnt++;
    return cnt;
}

char* SUBSTRING(char* s, int position, int length)
{
    if(position+length-1>LENGTH(s))
    {
        cout<<"LENGTH is too long\n";
        return NULL;
    }
    char *sub= new char[length+1];
    int i, j=0;
    for(i=position-1; i<position+length; i++)
    sub[j++]=s[i];
    sub[j++]='\0';
    return sub;
}

char* CONCAT (char *s1, char *s2)
{
    char *con= new char[LENGTH(s1)+LENGTH(s2)-1];
    int i, j=0;
    for(i=0; i<LENGTH(s1); i++)
    con[i]=s1[i];
    cout<<i<<"\n";
    for(i; i<LENGTH(s1)+LENGTH(s2); i++)
    con[i]=s2[j++];
    con[i]='\0';
    return con;
}

char* INSERT(char *s, int position, char *ns)
{
    int i=0, j=0, l=LENGTH(s), nl=(LENGTH(ns));
    if(position>l)
    {
        cout<<"Sourece STRING is too short\n";
        return NULL;
    }
    char *is= new char[l+nl-1];
    while(i<position)
    is[i++]=s[j++];
    j=0;
    while(j<nl)
    is[i++]=ns[j++];
    j=position;
    while(j<l)
    is[i++]=s[j++];
    is[i]='\0';
    return is; 
}

char* DELETE(char* s, int position, int length)
{
    int l=LENGTH(s);
    if(position+length>l)
    {
        cout<<"STRING is too short\n";
        return NULL;
    }
    char* ds= new char[l-length];
    int i=0, j=0;
    for(i=0; i<l; i++)
    {
        if(i>=position-1 && i<position+length-1) continue;
        ds[j++]=s[i];
    }
    return ds;
}
int main()
{
    char s[]="Ridowan Nadia";
    char s1[]="Khalid";
    char s2[]=" Kazi";
    cout<<LENGTH(s)<<'\n';
    cout<<SUBSTRING(s, 9, 5)<<'\n';
    cout<<CONCAT(s1, s2)<<'\n';
    cout<<INSERT(s1, 3, s2)<<'\n';
    cout<<DELETE(s, 8, 2)<<"\n";
    return 0;
}