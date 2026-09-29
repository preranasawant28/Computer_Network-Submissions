#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

 int main()
 {
 	int n,i;
 	int delay;
 	int frame[n];
 	int time=0;
 	int timeout=5;
 	srand(time=0);
	 cout<<"enter the frame"<<endl;
 	 cin>>n;
 	for(i=0;i<n;i++)
 	{
 		cout<<"enter"<<i<<"frame"<<endl;
 		cin>>frame[n];
 		delay=rand()%10;
 		if(timeout<delay)
 		{
 			cout<<"acknoledgment of frame "<<i<<" received"<<endl;
		 }
		 else
		 {
		 	cout<<"waiting"<<endl;
		 }
	 }
	 return 0;
}

