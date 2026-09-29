#include<iostream>
using namespace std;

int main()
{
	int a,b,c,d;
	
	cout<<"Enter the number of a=";
	cin>>a;                                                 
	cout<<"Enter the number of b=";
	cin>>b;
	cout<<"Enter the number of c=";
	cin>>c;
	cout<<"Enter the number of d=";
	cin>>d;
	
	cout<<"\n IP address:"<<a<<"."<<b<<"."<<c<<"."<<d<<"."<<endl;
	
	if(a<0||a>255||b<0||b>255||c<0||c>255||d<0||d>255)
	{
		cout<<"Invalid IP address\n";
		cout<<"Each part of IP address must be between 0 and 255\n";
	}
	else if(a>=0&&a<=127)
	{
		cout<<"Class A"<<endl;
		cout<<"Range:0-127"<<endl;
		cout<<"network mask:255.0.0.0"<<endl;
		cout<<"number of addresses:16777216"<<endl;
		cout<<"first address:"<<a<<".0.0.0"<<endl;
		cout<<"last address:"<<a<<".255.255.255"<<endl;
	}
	else if(a>=128&&a<=191)
	{
		cout<<"Class B"<<endl;
		cout<<"Range:128-191"<<endl;
		cout<<"network mask:255.255.0.0"<<endl;
		cout<<"number of addresses:65536"<<endl;
		cout<<"first addresss:"<<a<<".0.0"<<endl;
		cout<<"last address:"<<a<<".255.255"<<endl;
	}
	else if(a>=192&&a<=223)
	{
		cout<<"Class C"<<endl;
		cout<<"Range:192-223"<<endl;
		cout<<"network mask:255.255.255.0"<<endl;
		cout<<"number of addresses:256"<<endl;
		cout<<"first address:"<<a<<".0"<<endl;
		cout<<"last address:"<<a<<".255"<<endl;
	}
	else if(a>=224&&a<=239)
	{
		cout<<"Class D"<<endl;
		cout<<"Range:224-239"<<endl;
		cout<<"network mask:not applicable"<<endl;
		cout<<"number of addressses:Multicast"<<endl;
	}
	else if(a>=240&&a<=255)
	{
		cout<<"Class E"<<endl;
		cout<<"Range:240=255"<<endl;
		cout<<"network mask:not applicable"<<endl;
		cout<<"number of addresses:reserved"<<endl;
	}
	else
	{
		cout<<"Invalid IP address"<<endl;
	}
	return 0;
}
                                                      
	

