// this is Employee data managment system devloped by DEEPAK RAJ


#include<iostream>
#include<fstream>
#include<iomanip>
#include <windows.h>
using namespace std;
void addrecord();
void modify();
void viewrecord();
void alert();
void about();
class empl
{
	int emp_id;
	char ename[30];
	char eadd[50];
	int sallary;
	public:
		void getdata()
		{
			char str1[50]={'e','n','t','e','r',' ','t','h','e',' ','f','o','u','r',' ','d','i','g','i','t',
			' ','e','m','p','l','o','y','e','e','_','c','o','d','e'};
			for(int i=0;str1[i]!='\0';i++)
	        {cout<<str1[i];
	        Sleep(100);}
			cout<<"\n";
			cin>>emp_id;
			char str2[50]={'e','n','t','e','r',' ','t','h','e',' ','n','a','m','e',' ','o','f',' ','e','m','p',
			'l','o','y','e','e'};
			for(int i=0;str2[i]!='\0';i++)
	        {cout<<str2[i];
	        Sleep(100);}
			cout<<"\n";
			cin>>ename;
			char str3[50]={'e','n','t','e','r',' ','t','h','e',' ','a','d','d','r','e','s','s',' ','o','f'};
			for(int i=0;str3[i]!='\0';i++)
	        {cout<<str3[i];
	        Sleep(100);}
	        cout<<" "<<ename;
			cout<<"\n";
			cin>>eadd;
			char str4[50]={'e','n','t','e','r',' ','t','h','e',' ','s','a','l','l','a','r','y',' ','o','f'};
			for(int i=0;str4[i]!='\0';i++)
	        {cout<<str4[i];
	        Sleep(100);}
	        cout<<" "<<ename;
			cout<<"\n";
			cin>>sallary;
		}
		void putdata(int sl)
		{
			cout<<setfill(' ');
			cout.setf(ios::left);
			cout<<sl<<"\t\t\t"<<setw(5)<<emp_id<<"\t\t\t"<<setw(10)<<ename<<"\t\t\t"<<setw(10)<<eadd<<"\t\t\t"<<setw(10)
			<<sallary<<endl;
		}
};
main()
{
	char str[500]={'\t','\t','T','H','I','S',' ','I','S',' ','E','M','P','L','O','Y','E','E',' ','D','A','T','A',' ',
	'M','A','N','A','G','M','E','N','T',' ','S','Y','S','T','E','M','\n','\t','\t','\t',' ','D','E','V','E','L','O',
	'P','E','D',' ','B','Y',':','-',' ','D','E','E','P','A','K',' ','R','A','J','\n','\n','\n'};
		for(int i=0;str[i]!='\0';i++)
	        {cout<<str[i];
	        Sleep(100);}
			cout<<"\n";
	Sleep(1000);
	system("cls");
	while(1)
	{
	cout<<"***************************************\n";
	char str5[50]={'W','E','L','C','O','M','E',' ','T','O',' ','T','H','E',' ','M','A','I','N',' ','M','E','N','U'};
	for(int i=0;str5[i]!='\0';i++)
	        {cout<<str5[i];
	        Sleep(100);}
			cout<<"\n";
	cout<<"***************************************\n\n\n";
	cout<<"press 1 to enter the record to employee\n";
	cout<<"press 2 to view the details of employee\n";
	cout<<"press 3 to modify the record\n";
	cout<<"press 4 to about us\n";
	cout<<"press 0 to terminate the programm\n\n";
	int choice;
	char str4[50]={'p','l','e','a','s','e',' ','e','n','t','e','r',' ','y','o','u','r',' ','c','h','o','i','c','e'};
		for(int i=0;str4[i]!='\0';i++)
	        {cout<<str4[i];
	        Sleep(100);}
			cout<<"\n";
	cin>>choice;
	Beep(1100,200);
	switch(choice)
	{
		case 1: addrecord();break;
		case 2: viewrecord();break;
		case 3: modify();break;
		case 4: about();break;
		case 0: return 0;
		default: alert();cout<<"you have entered wrong input please enter the valid choice\n";Sleep(1000);
	}
	system("cls");
}
}
void addrecord()
{
	empl ob;
	ob.getdata();
	ofstream wfile("employee_details.dpk",ios::binary|ios::app);
	wfile.write((char*)&ob,sizeof(ob));
	wfile.close();
	cout<<"\nrecord added successfully\n\n\n";
	system("pause");
}
void viewrecord()
{
	int sl=0;
	ifstream rfile;
	rfile.open("employee_details.dpk",ios_base::in|ios::binary);
	empl ob;
	rfile.seekg(0);
	cout<<"SL.NO:\t\t    EMPLOYEE_ID\t\t        EMPLOYEE_NAME\t\t    EMPLOYEE_ADDRESS\t\t    EMPLOYEE_SALLARY\n\n";
	while(rfile.read((char*)&ob,sizeof(ob)))
	{
		sl++;
		Beep(540,100);
		ob.putdata(sl);
		Sleep(200);
	}
	system("pause");
}
void modify()
{
	
	empl ob;
	fstream mfile;
	mfile.open("employee_details.dpk",ios_base::in|ios_base::out|ios::ate);
	int totalbyte=mfile.tellp();
	int totalrec=totalbyte/sizeof(ob);
	cout<<"you have only "<<totalrec<<" employees \n";
	cout<<"enter the serial number of employee to be updated\n";
	int srl;
	cin>>srl;
	long modifybyte=((srl-1)*sizeof(ob));
	mfile.seekp(modifybyte);
	ob.getdata();
	mfile.write((char*)&ob,sizeof(ob));
	cout<<"\n\nrecord successfully updated";
	Sleep(2000);
}
void alert()
{
	for(int i=0;i<4;i++)
	{
	   Beep(400,200);
	}
}
void about()
{
	cout<<"\n\ndeveloped and desined by:-...  ";
	Sleep(3000);
	char str[50]={'D','E','E','P','A','K',' ','Y','A','D','A','V','\n','\t','\t','\t','\t','J','E','H','A','N','A',
	'B','A','D','\n','\t','\t','\t','\t',' ',' ','(','B','I','H','A','R',')'};
	for(int i=0;str[i]!='\0';i++)
	        {cout<<str[i];
	        Sleep(100);}
			cout<<"\n\n";
	cout<<"All credit  goes to:-...";
			Sleep(3000);
	char str1[50]={'A','J','A','Y',' ','S','I','R',' ','(','A','E','R','O','N','S','P','I','R','E',')','\n',
	'\t','\t','\t','\t','D','H','A','N','B','A','D'};
		for(int i=0;str1[i]!='\0';i++)
	        {cout<<str1[i];
	        Sleep(100);}
			cout<<"\n\n\n\n\n";
			cout<<"               copyright 2017 Aeronspire.all right reserved.\n                             ";
	char str3[30]={'P','o','w','e','r','e','d',' ','b','y',':','-','D','E','E','P','A','K',' ','R','A','J'};		
	for(int i=0;str3[i]!='\0';i++)
	        {cout<<str3[i];
	        Sleep(200);}
	        cout<<"\n\n\n\n\n";
	cout<<"                            ";
	char str2[30]={'T','H','A','N','K','S',' ','F','O','R',' ','B','E',' ','H','E','R','E'};
		for(int i=0;str2[i]!='\0';i++)
	        {cout<<str2[i];
	        Sleep(100);}
			cout<<"\n";		
			system("pause");
}
