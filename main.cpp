//***************************************************
//*************PROJECT ON FEE MANAGEMENT*************
//***************************************************
//*************HEADER FILES ARE INCLUDED*************

#include<conio.h>
#include<process.h>
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<fstream.h>
#include<dos.h>
#include<iomanip.h>


void draw_box(int s_row,int s_col,int e_row,int e_col);

//*******************************************************
//**************CLASS TO DRAW LINES**********************
//*******************************************************

class DRAW
{
	public :
		void LINE_HOR(int, int, int, char);
		void LINE_VER(int, int, int, char);
};
void DRAW :: LINE_HOR(int column1,int column2, int row, char c)
{
	for(column1; column1<=column2;column1++)
	{
		gotoxy(column1,row);	//places the ptr. at the specified coordinates
		cout<<c;
	}
}
void DRAW :: LINE_VER(int row1, int row2, int column, char c)
{
	for(row1; row1<=row2;row1++)
	{
		gotoxy(column,row1);
		cout<<c;
	}
}

//*****************************************************************
//***********************FUNCTION TO DRAW BOX**********************
//*****************************************************************
void draw_box(int s_row,int s_col,int e_row,int e_col)
{
	int i;
	for(i=s_col;i<=e_col;i++)
	{
		gotoxy(i,s_row);
		cout<<"*";
		gotoxy(i,e_row);
		cout<<"*";
	}
	for(i=s_row;i<=e_row;i++)
	{
		gotoxy(s_col,i);
		cout<<"*";
		gotoxy(e_col,i);
		cout<<"*";
	}
}


//*****************************************************************
//*********CLASS TO MANAGE FEE COLLECTION AND GENERATION***********
//*****************************************************************

class sfee
{

		char paid;
		int adm;
	public:
	int cl,term;
		void gfee(int a,int d,int t)
		{
			adm=a;
			cl=d;
			term=t;
			paid='N';
		}

		int chfee(int t,int a)
		{
			if(adm==a&&term==t)
				return 1;
			else
				return 0;
		}
		void upfee()
		{
			paid='Y';
		}
		int retad()
		{
			return adm;
		}
		int retterm()
		{
			return term;
		}
		char retpaid()
		{
			return paid;
		}
}sf;


//***************FUNCTIONS MANAGING STUDENT INFO***************

void add();
void del();
void modify();


//*************************************************************
//*****************CLASS TO MANAGE STUDENT INFO****************
//*************************************************************

class student
{
	public:
		char name[20],address[30],ph[30],fathername[30],mothername[30];
		char sec;
		int admno,cls;
		void enter()
		{
			cout<<"\n\t\t Enter the admission number   :   ";
			cin>>admno;
			cout<<"\n\t\t Enter the Name               :   ";
			gets(name);
			cout<<"\n\t\t Enter Father\'s name         :   ";
			gets(fathername);
			cout<<"\n\t\t Enter Mother\'s name         :   ";
			gets(mothername);
			cout<<"\n\t\t Enter Address                :   ";
			gets(address);
			cout<<"\n\t\t Enter phone no               :   ";
			gets(ph);
			cout<<"\n\t\t Enter the class             :   ";
			cin>>sec;
			sec=toupper(sec);
		}
		void display()
		{
			cout<<"\n\t\t Admno is   	:  ";
			cout<<admno;
			cout<<"\n\t\t Name is    	:  ";
			puts(name);
			cout<<"\n\t\t Class is   	:  "<<cls;
			cout<<"\n\t\t Sectionn is	:  "<<sec;
		}

		int retno()
		{
			return admno;
		}
		int clcheck(int c,char se);
}s;

int student::clcheck(int c,char se)
{
	if((cls==c)&&(sec==se))
		return 1;
	else
		return 0;
}

//************* FUNCTIONS TO CONTROL FEE INFO **************
void ADDITION();
void MODIFICATION();
void DELETE();


//**********************************************************
//***************CLASS TO MANAGE FEE INFO*******************
//**********************************************************

class fee
{
		float tution,pta,science,pupil,supw;
	public:
		fee()
		{
			tution  = 0.0;
			pta     = 0.0;
			science  = 0.0;
			pupil   = 0.0;
			supw    = 0.0;
		}
		void enterd();
		void displayd()
		{
			clrscr();
			cout<<"\n\n\t TUTION FEE    :  "<<tution;
			cout<<"\n\n\t P.T.A. FUND   :  "<<pta;
			cout<<"\n\n\t SCIENCE FEE   :  "<<science;
			cout<<"\n\n\t PUPIL FUND    :  "<<pupil;
			cout<<"\n\n\t S.U.P.W FEE   :  "<<supw;
			cout<<"\n\t\7 Press any key to continue ..........";
		}
		int retad();
		float rettution();
		float retpta();
		float retscience();
		float retpupil();
		float retsupw();
}f;
float fee::rettution()
{
	return tution;
}
float fee::retpta()
{
	return pta;
}
float fee::retpupil()
{
	return pupil;
}
float fee::retscience()
{
	return science;
}

float fee::retsupw()
{
	return supw;
}

//********************FUNCTION TO ENTER FEE STRUCTURE*****************

void fee::enterd()
{
	clrscr();

	cout<<"\n\t Enter Class              :   ";
	cin>>s.cls;

	cout<<"\n\t Enter the Tution fee     :   ";
	cin>>tution;
	cout<<"\n\t Enter the pta fee        :   ";
	cin>>pta;
	cout<<"\n\t Enter the Science fee    :   ";
	cin>>science;
	cout<<"\n\t Enter the Pupil fund     :   ";
	cin>>pupil;
	cout<<"\n\t Enter the S.U.P.W fund   :   ";
	cin>>supw;
	cout<<"\n\t Enter the term           :   ";
	cin>>sf.term;
}

//*****************FUNCTION TO ADD STUDENT STRUCTURE********************

void add()
{
	clrscr();
	char chh;
	fstream fin("student.dat",ios::app|ios::binary);
	do
	{
		s.enter();
		fin.write((char *)&s,sizeof(s));
		cout<<"\n\t Do U want to enter more records ? ";
		cin>>chh;
	}while(chh=='y'||chh=='Y');
	cout<<"\n Data has been added on the file";
	cout<<"\n\t\7 Press any key to continue..........";
	getch();
	fin.close();
}

//***************FUNCTION TO DELETE STUDENT STRUCTURE****************

void del()
{
	clrscr();
	fstream fin("student.dat",ios::in|ios::binary);
	fstream fout("temp.dat",ios::out|ios::binary);
	int r;
	cout<<"\n Enter the Admno of the Student whose record is to be deleted : ";
	cin>>r;
	int flag=0;
	while(fin.read((char *)&s,sizeof(s)))
	{
		if(r!=s.retno())
		{
			fout.write((char *)&s,sizeof(s));
		}
		else
			flag=1;
	}
	if(flag==1)
	cout<<"\n\t Data has been Deleted";
	else
		cout<<"\n\t No such record..............";
		cout<<"\n\t\7 Press ay key to continue........";
	getch();
	fin.close();
	fout.close();
	remove("student.dat");
	rename("temp.dat","student.dat");
}

//****************FUNCTION TO MODIFY STUDENT STRUCTURE***************

void modify()
{
	clrscr();
	fstream fin("student.dat",ios::in|ios::out|ios::binary);
	int t;
	cout<<"\n Enter the Admno of the student whose record is to be modified ";
	cin>>t;
	long offset=0;
	while (fin.read((char *)&s,sizeof(s)))
	{
		if(t==s.retno())
		{
			s.enter();
			fin.seekp(offset,ios::beg);
			fin.write((char *)&s,sizeof(s));
		}
		offset+=sizeof(s);
	}
	fin.close();
}

//*************FUNCTION TO ADD FEE STRUCTURE*****************

void ADDITION()
{
	clrscr();
	fstream file;
	file.open("fee.dat",ios::app|ios::binary);
	char rep;
	do
	{
		f.enterd();
		file.write((char *)&f, sizeof(f));
		cout<<"\n\t Want to add data for more classes  ";
		cin>>rep;
	}while(rep=='y'||rep=='Y');
	cout<<"\n Data has been added on the file ";
	file.close();
}

//******************FUNCTION TO MODIFY FEE STRUCTURE****************

void MODIFICATION()
{
	clrscr();
	fstream fin("fee.dat",ios::in|ios::out|ios::binary);
	int clw;
	cout<<"\n Enter the Classes whose Fee Structure is to be Modified ";
	cin>>clw;
	long offset=0;
	while(fin.read((char *)&f,sizeof(f)))
	{
		if(s.cls==clw)
		{
			f.enterd();
			fin.seekp(offset,ios::beg);
			fin.write((char *)&f,sizeof(f));
		}
		offset+=sizeof(f);
	}
	fin.close();
	cout<<"\n\n\t Modified data   :   ";
	f.displayd();
	getch();
}

//******************FUNCTION TO DELETE FEE STRUCTURE********************

void DELETE()
{
	clrscr();
	fstream fin("fee.dat",ios::in|ios::binary);
	fstream fout("temp.dat",ios::out|ios::binary);
	int clw;
	cout<<"\n Enter the Class of the student whose Fee structure is to be Deleted : ";
	cin>>clw;
	while(fin.read((char *)&f,sizeof(f)))
	{
		if(clw!=s.cls)
		{
			fout.write((char *)&f,sizeof(f));
		}
	}
	fin.close();
	fout.close();
	cout<<"\n\n\t Data deleted " ;
	cout<<"\n\t\7 Press any key to continue";
	remove("fee.dat");
	rename("temp.dat","fee.dat");
	}

//******************FUNCTION FOR FEE COLLECTION*********************

void Fee_collect()
{
	clrscr();
	int clas,anum,t;
	char section;
	cout<<"\n\n\t Enter the Admission no           : ";
	cin>>anum;
	cout<<"\n\n\t Enter The Class Of The Student    :";
	cin>>clas;
	cout<<"\n\n\t Enter the Section Of The Student    : ";
	cin>>section;
	section=toupper(section);
	fstream file,file2,file3,file4;
	file.open("fee.dat",ios::in|ios::binary);

	int flag=0;

	while(file.read((char *)&s, sizeof(s)))
	{
		if(s.cls==clas)
		{
			flag=1;
			break;
		}
	}
		if(flag==0)
		{
			cout<<"\n\t Please check the input for class.......";
			getch();
			file.close();
			return;
		}
		file2.open("student.dat", ios::in|ios::binary);
		flag=0;
		while(file2.read((char *)&s,sizeof(s)))
		{
			if(s.retno()==anum)
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			cout<<"\n\t Please check the admission no........";
			getch();
			file.close();
			file2.close();
			return;
		}
		long offset=0;
		file3.open("sfee.dat",ios::in|ios::out|ios::binary);
		cout<<"\n\t Enter term         :  ";
		cin>>t;
		flag=0;
		while(file3.read((char *)&sf,sizeof(sf)))
		{
			if(sf.retad()==anum && sf.retterm()==t)
			{
				flag=1;
				break;
			}
			offset+=sizeof(sf);
		}
	if(flag==1)
	{
		int fine;
		char rep;
		cout<<"\n\n\t Is There A Fine ?? ";
		cin>>rep;
		if(rep=='y'||rep=='Y')
		{
			cout<<"\n\n\t Enter the fine";
			cin>>fine;
		}
		sf.upfee();
		file3.seekg(offset,ios::beg);
		file3.write((char*)&sf,sizeof(sf));
		cout<<"\n\n\t FEE PAID ..................";
		getch();
	}
	else
	{
	cout<<"\n\t please check your inputs .............";
	getch();
	}
	file.close();
	file2.close();
	file4.close();

}

//****************FUNCTION TO DEFAULTER'S LIST***************

void DEFAULTER_LIST()
{
	clrscr();
	int clas,anum,t;
	char section;
	cout<<"\n\n\t Enter The Class of the Student     :  ";
	cin>>clas;
	cout<<"\n\n\t Enter the section of the student   :  ";
	cin>>section;
	section=toupper(section);
	fstream file,file3;
	file.open("student.dat",ios::in|ios::binary);

	cout<<"\n\t Enter term            :  ";
	cin>>t;
	clrscr();
	gotoxy(20,5);
	cout<<"DEFAULTER\'S LIST ";
	gotoxy(15,2);
	cout<<"ABC MODEL SCHOOL";
	gotoxy(3,7);
	cout<<"Term    "<<t;
	gotoxy(3,8);
	cout<<"class   "<<clas;
	gotoxy(44,8);
	cout<<"section "<<section;
	gotoxy(3,9);
	cout<<"Admission no";
	gotoxy(22,9);
	cout<<"Student\'s Name";
	gotoxy(40,9);
	cout<<"Father\'s Name";
	int r=10;
	while(file.read((char *)&s, sizeof(s)))
	{
		if(s.clcheck(clas,section))
		{
		file3.open("sfee.dat",ios::in|ios::binary);
		anum=s.retno();
		while(file3.read((char *)&sf,sizeof(sf)))
		{
		if(sf.retad()==anum && sf.retterm()==t && sf.retpaid()=='N')
		{
		int admno=s.retno();
		gotoxy(3,r);
		cout<<admno;
		gotoxy(22,r);
		cout<<s.name;
		gotoxy(40,r);
		cout<<s.fathername;
		r++;
		}
		}
		}
		file3.close();
	}
	file.close();
	getch();

}

//****************FUNCTION FOR QUERY ON STUDENT*****************

void Query1()
{
	clrscr();
	char rep;
	int admno;
	fstream file2;
	do
	{	clrscr();
		file2.open("student.dat",ios::in|ios::binary);
		gotoxy(10,9);
		cout<<"eter the Admno of the Student";
		cin>>admno;
		while(file2.read((char *)&s, sizeof(s)))
		{
			if(s.retno()==admno)
			{
				s.display();
				getch();
			}
			}
		cout<<"\n\n\t Do U Want to enter more ?? ";
		cin>>rep;
		file2.close();

	}while(rep=='y'||rep=='Y');
}

//*****************FUNCTION FOR QUERY ON FEE********************

void Query2()
{
	clrscr();
	int clas;
	char rep;
	do
	{
		clrscr();
		gotoxy(10,8);
		cout<<"enter the class of the student";
		cin>>clas;
		fstream file("fee.dat",ios::in|ios::binary);
		while(file.read((char *)&f,sizeof(f)))
		{
			if(sf.cl==clas)
			{
				f.displayd();
			}
		}
		cout<<"\n\n\t Do you Want to Enter more ??";
		cin>>rep;
		file.close();
	}while(rep=='y'||rep=='Y');
}

//*******************************************************************
//*****************FUNCTION FOR SUB MENU OF STUDENT*******************
//*******************************************************************

void stud_menu()
{
	int ch1;
	do
	{
		clrscr();
		draw_box(4,19,25,70);
		gotoxy(30,7);
		cout<<"1.Add a Student Information";
		gotoxy(30,10);
		cout<<"2.Delete a Student Information";
		gotoxy(30,13);
		cout<<"3.Modify a student Information";
		gotoxy(30,16);
		cout<<"4.Quit to main menu";
		gotoxy(30,20);
		cout<<" Enter Ur Choice";
		cin>>ch1;
		switch(ch1)
		{
		case 1:  add();
			break;
		case 2:  del();
			break;
		case 3:  modify();
			break;
		case 4:  return;
		default: cout<<"\n\n\t\t@#! WRONG CHOICE ENTERED ! # @ ";
		}
	}while(ch1!=5);
}

//***********************************************************************
//*********************FUNCTION FOR SUB MENU OF FEE**********************
//***********************************************************************

void fee_menu()
{
	int ch2;
	do
	{
	clrscr();
	draw_box(4,19,25,70);
	gotoxy(30,7);
	cout<<" 1. Add Fee Structure ";
	gotoxy(30,10);
	cout<<"2. Delete Fee Structure ";
	gotoxy(30,13);
	cout<<"3. Modify Fee Structure ";
	gotoxy(30,16);
	cout<<"4. Return to Main Menu";
	gotoxy(30,20);
	cout<<" Enter Ur choice";
	cin>>ch2;
	switch(ch2)
	{
	case 1:  ADDITION();
		break;
	case 2: DELETE();
		break;
	case 3: MODIFICATION();
		break;
	case 4: return;
	default: cout<<"\n\n\t\t @#!WRONG CHOICE ENTERED !#@";
	}
	}while(ch2!=5);
}

//*****************************************************************
//**************FUNCTION FOR SUB MENU OF QUERY*********************
//*****************************************************************

void query_menu()
{
	int ch3;
	do
	{
		clrscr();
		draw_box(7,8,30,55);
		gotoxy(10,15);
		cout<<"1. Query on Student Information";
		gotoxy(10,17);
		cout<<"2. Query on FEE structure";
		gotoxy(10,19);
		cout<<" 3. return to Main Menu";
		gotoxy(10,25);
		cout<<"Enter your Choice";
		cin>>ch3;
		switch(ch3)
		{
			case 1: Query1();
				break;
			case 2: Query2();
				break;
			case 3: return;
			default: exit(0);
		}
	}while(ch3!=4);
}

//**********************************************************************
//****************************MAIN FUNCTION*****************************
//**********************************************************************

void main()

{
	textbackground(BLACK);
	textcolor(GREEN);
	clrscr();
	int ch;
	char c;
	do
	{
		clrscr();
		draw_box(2,10,24,71);
		gotoxy(25,4);
		cout<<"************* MAIN MENU ****************";
		gotoxy(15,6);
		cout<<"1. Student Maintainance";
		gotoxy(15,8);
		cout<<"2. Fee Structure Mgmt ";
		gotoxy(15,10);
		cout<<"3. Fee Collection ";
		gotoxy(15,12);
		cout<<"4. Defaulters List";
		gotoxy(15,14);
		cout<<"5. Query";
		gotoxy(15,16);
		cout<<"6. Quit";
		gotoxy(15,18);
		cout<<"Enter ur choice ";
		cin>>ch;
		switch(ch)
		{
			case 1:		stud_menu();
				break;
			case 2:		fee_menu();
				break;
			case 3:		 Fee_collect();
				break;
			case 4:		DEFAULTER_LIST();
				break;
			case 5:		query_menu();
				break;
			case 6:		exit(0);

			default:	cout<<"\n\n\t !@# WRONG CHOICE ENTERED #@!";
		}
		clrscr();
		cout<<"\n\7 Do You Wish To Continue (Y/N):";
		cin>>c;
	}while(c=='y'||c=='Y');
	getch();
}