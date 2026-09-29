#include<iostream>
using namespace std;

int main() 
{
int frame1[20],frame2[20];
int i,j=0,n,counter=0;

cout<<"enter the size of frame 1=";
cin>>n;

cout<<"enter the number of bit for frame 1=";
for(i=0;i<n;i++)
{
	cin>>frame1[i];
}

for(i=0;i<n;i++)
{
	if(frame1[i]==1)
	{
		counter++;
		frame2[j]=frame1[i];
		j++;
		
		if(counter==5)
		{
				frame2[j]=0;
				j++;
				counter=0;
		}
	}
	else
	{
		counter=0;
		frame2[j]=frame1[i];
		j++;
	}
}

cout<<"After bit stuffing=";
for(i=0;i<j;j++)
{
	cout<<"frame2[i]"<<"";
}
return 0;
}

