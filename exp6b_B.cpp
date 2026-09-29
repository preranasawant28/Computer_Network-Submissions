#include<iostream>
#include<string>
using namespace std;
//Receiver side 

int main()
{
	string codeword,divisor;
	
	cout<<"Enter received codeword bits:";
	cin>>codeword;
	
	cout<<"Enter divisor bits:";
	cin>>divisor;
	
	int n=codeword.length();
	int m=divisor.length();
	
	string temp=codeword;
	
	for(int i=0;i<=n-m;i++)
	{
		if (temp[i]=='1')
		{
			for(int j=0;j<m;j++)
			{
				temp[i+j]=(temp[i+j]==divisor[j])?'0':'1';
			}
		}
	}
	
	string crc=temp.substr(n-m+1,m-1);
	
	cout<<"\n Received codeword:"<<codeword<<endl;
	cout<<"Divisor:             "<<divisor<<endl;
	cout<<"CRC Remainder:       "<<crc<<endl;
	
	if(crc.find('1')==string::npos)
	{
		cout<<"No Error in Received Data"<<endl;
	}
	else
	{
		cout<<"Error Detected in Received Data"<<endl;
	}
	return 0;
}


