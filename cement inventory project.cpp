/* Cement Inventry System (Project) */

//header files used
#include<dos.h>
#include <fstream.h>
#include <string.h>
#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include<iostream.h>
#include<iomanip.h>

//global var.
int choice,y_n=1;
int c; int R_opt;char ch,a;
char as= NULL; int ans;
 //to show the initial help
 void help()
   {
	 gotoxy(33,1);
	 cout<<"W E L C O M E";
	 gotoxy(33,2);
	 cout<<"*************";
	 gotoxy(10,4);
	 cout<<"############################################################";
	 gotoxy(10,6);
	 cout<<" This project can keep record of daily cement transiction.";
	 gotoxy(10,7);
	 cout<<" This program is capable of holding any no. daily profile.";
	 gotoxy(10,8);
	 cout<<" In first option you can open cement inward entry form.";
	 gotoxy(10,9);
	 cout<<" In second option you can open cement outward entry form.";
	 gotoxy(10,10);
	 cout<<" In third option you can see status report";
	 gotoxy(10,12);

cout<<"############################################################

";
	 cout<<"a			
Press any key to continue.........";
	 getch();
   }

 //to show the main menu
 void show_menu()
   {
	 clrscr();
	 gotoxy(60,1);
	 cout<<"Date :"<<__DATE__;       //  to show the system date
	 gotoxy(32,3);
	 cout<<"M A I N - M E N U";
	 gotoxy(32,4);
	 cout<<"-----------------";
	 gotoxy(2,5);

cout<<"***************************************************************";
	 gotoxy(15,6);
	 cout<<"1. Cement Inward Entry";
	 gotoxy(15,8);
	 cout<<"2. Cement Outward Entry";
	 gotoxy(15,10);
	 cout<<"3. Cement Status Report";
	 gotoxy(15,12);
	 cout<<"4. Exit";
	 gotoxy(2,13);

cout<<"***************************************************************";
	}


// class contain the data of  cement stock
 class cement
 {
	protected:
	   struct info
	 {
	   char flage;
	   long int R_challan;
	   int dd1,mm1,yy1;
	   char truck_no[15];
	   int dd2,mm2,yy2;
	   int qtt;

	 }f;
	   fstream file;              //creating object of fstream class
};

//class for inward cement data
 class cement_in:public cement
	{
	   public:
	   cement_in();
	   void get_inward()    ;// to get the inward cement information
	   void inward_report() ;// to get inward cement report
	   int stock_in();
	   void stock_date();
	};                             //class cement_in close


//class for outward cement data
 class cement_out:public cement
	{
	public:
	cement_out();
	void del_data();           //to get the data about delivery
	void outward_report();     //to get the outward cement report
	int stock_out();           //to get the total cement out
	 };

//function to get the inward cement entry
 void cement_in :: get_inward()
	{
	file.seekp(0L,ios::end);
	do
	 {
	clrscr();
	gotoxy(25,3);
	cout<<"C E M E N T - I N W O R D - E N T R Y";
	gotoxy(2,5);

cout<<"===============================================================";
	gotoxy(5,8);
	cout<<"Receipt Challan No.: ";
	gotoxy(5,10);
	cout<<"Challan Date:";
	gotoxy(5,12);
	cout<<"Truck No.:";
	gotoxy(5,14);
	cout<<"Receipt Date:";
	gotoxy(5,16);
	cout<<"Quantity:";
	gotoxy(22,16);
	cout<<"M.T";
	gotoxy(2,19);

cout<<"===============================================================";
	gotoxy(2,22) ;
	cout<<"Enter the recieve challan no................";
	turn:gotoxy(28,8);
	cin>>f.R_challan;
	if(f.R_challan>999999)
	  {
	gotoxy(28,8);
	cout<<"                         ";
	gotoxy(2,22);
	cout<<"aChallan no. should not greater then 6 dig.";
	goto turn;
	  }
	gotoxy(2,22);
	cout<<"Enter the challan date.......................";
	  turn1:gotoxy(20,10);
	cin>>f.dd1;
	gotoxy(22,10);
	cout<<"-";
	gotoxy(23,10);
	cin>>f.mm1;
	gotoxy(25,10);
	cout<<"-";
	gotoxy(26,10);
	cin>>f.yy1;
	if(f.dd1>31||f.mm1>12||f.yy1>99)
	  {
	   gotoxy(20,10);
	   cout<<"                            ";
	   gotoxy(2,22);
	   cout<<"aEnter the valid date........................";
	   goto turn1;
	  }
	gotoxy(2,22);
	cout<<"Enter the truck no. ........................";
	gotoxy(17,12);
	cin>>f.truck_no;
	gotoxy(2,22);
	cout<<"Enter the recieving date......................";
	//  for putting recieving date
	  turn2:gotoxy(22,14);
	cin>>f.dd2;
	gotoxy(24,14);
	cout<<"-";
	gotoxy(25,14);
	cin>>f.mm2;
	gotoxy(27,14);
	cout<<"-";
	gotoxy(28,14);
	cin>>f.yy2;
	if(f.dd2>31||f.mm2>12||f.yy2>99)
	   {
	gotoxy(22,14);
	cout<<"                         ";
	gotoxy(2,22);
	cout<<"aPlease enter the valid date .................";
	goto turn2;
	   }
	// quantity of cement
	gotoxy(2,22);
	cout<<"Enter the cement quantity..";
	gotoxy(15,16);
	cin>>f.qtt;
	f.flage=NULL;
	file.write((char*)&f,sizeof(f));
	gotoxy(2,22);
	cout<<"Enter another .......................yes-1/no-0  :";
	cin>>ans;
	   } while(ans==1);

  }

//function for returning the total stock in store
int cement_in::stock_in()
  {
	int temp=0;
	file.seekg(0L,ios::beg);
	while(file.read((char*)&f,sizeof(f)))
	{
	if(f.flage!='*')
	temp=temp+f.qtt;
	}
	file.clear();
	return(temp);
  }

     /* function which gives the info of cement status
  at the particular date */

 void cement_in::stock_date()
  {
	clrscr();
	gotoxy(25,4);
	cout<<"R E C I E V E D - S T O C K";
	gotoxy(25,5);
	cout<<"***************************";
	int dd,mm,yy;
	gotoxy(4,10);
	cout<<"Please enter the date: ";
	gotoxy(30,10);
	cin>>dd;
	gotoxy(32,10);
	cout<<"-";
	gotoxy(33,10);
	cin>>mm;
	gotoxy(35,10);
	cout<<"-";
	gotoxy(36,10);
	cin>>yy;
	file.seekg(0L,ios::beg);
	while(file.read((char*)&f,sizeof(f)))
	{
	  if(dd==f.dd1&&mm==f.mm1&&yy==f.yy1)
	  {
	  gotoxy(20,12);
	  cout<<"************************************";
	  gotoxy(20,14);
	  cout<<"aTotal recieved cement :"<<f.qtt<<"    M.T";
	  gotoxy(20,15);
	  cout<<"aChallan No. :  "<<f.R_challan;
	  gotoxy(20,16);
	  cout<<"aTruck No.   :  "<<f.truck_no;
	  gotoxy(20,17);
	  cout<<"Challan date  :  "<<f.dd1<<"-"<<f.mm1<<"-"<<f.yy1;
	  gotoxy(20,19);
	  cout<<"*******************************";
	  }
	   }

  }

      //function for inward cement report
 void  cement_in::inward_report()
  {

	  gotoxy(28,2);
	  cout<<"I N W A R D - R E P O R T ";
	  gotoxy(28,3);
	  cout<<"-------------------------";
	  gotoxy(3,5);

cout<<"*****************************************************";
	  gotoxy(3,6);
	  cout<<"Challan No.   Challan-Date   Truck-No.  Date of Receiv  Quantity";
	  gotoxy(3,7);

cout<<"********************************************************";
	  file.seekg(0L,ios::beg);
	  while(file.read((char*)&f,sizeof(f)))
	  {
	 if(f.flage!='*')

cout<<"
"<<setw(10)<<f.R_challan<<setw(13)<<f.dd1<<"/"<<f.mm1<<"/"<<f.yy1
<<setw(12)<<f.truck_no<<setw(10)<<f.dd2<<"/"<<f.mm2<<"/"<<f.yy2<<setw(10)<
<f.qtt; delay(200);
	  }
cout<<"
 ****************************************************";
	  file.clear();
 }

/* costructor of cement_in class which initialise the opening file cement.dat  */
 cement_in::cement_in()
 {
	 file.open("cement.dat",ios::binary|ios::in|ios::out);
	 if(!file)
	 {
	  cout<<"ERROR" ;
	  getch();
	 }
 }

 // function of class delivery data , to get the entries of outward 
cement
 void  cement_out::del_data()

	 {
	file.seekp(0L,ios::end);
	do
	{
	   clrscr();
	   gotoxy(28,5);
	   cout<<"* O U T W A R D - E N T R Y *";
	   gotoxy(28,6);
	   cout<<"------------------------------";
	   gotoxy(3,8);

cout<<"*********************************************************";
	   gotoxy(3,9) ;
	   cout<<"Delivery Challan No.:";
	   gotoxy(3,11);
	   cout<<"Challan Date:";
	   gotoxy(3,13);
	   cout<<"Dlivery Truck No.:";
	   gotoxy(3,15);
	   cout<<"Date of Dispatch:";
	   gotoxy(3,17);
	   cout<<"Quantity:";
	   gotoxy(26,17);
	   cout<<"M.T.";
	   gotoxy(3,18);

cout<<"*********************************************************";
	   gotoxy(2,22);
	   cout<<"Enter the delivery challan no......";
	  turn:gotoxy(25,9);
	   cin>>f.R_challan;
	   if(f.R_challan>999999)
	   {
	 gotoxy(25,9);
	 cout<<"                         ";//to clear this line
	 gotoxy(2,22);
	 cout<<"aChallan no. should not greater then 6 dig.";
	 goto turn;
	   }
	   gotoxy(2,22);
	   cout<<"Enter the delivery challan date....";
	turn1: gotoxy(25,11);
	   cin>>f.dd1;           //date of challan
	   gotoxy(27,11)  ;
	   cout<<"-";
	   gotoxy(28,11);
	   cin>>f.mm1;
	   gotoxy(30,11);
	   cout<<"-";
	   gotoxy(31,11);
	   cin>>f.yy1;
	   if(f.dd1>31||f.mm1>12||f.yy1>99)
	{
	 gotoxy(25,11);
	 cout<<"                                       ";
	 gotoxy(2,22);
	 cout<<"aEnter the valid date........................";
	 goto turn1;
	}
	   gotoxy(2,22);
	   cout<<"Enter the delivery truck no. .....";
	   gotoxy(25,13);
	   cin>>f.truck_no;
	   gotoxy(2,22);
	   cout<<"Enter the cement delivery date....";
	turn2: gotoxy(25,15);
	   cin>>f.dd2;                  //for date of deliver
	   gotoxy(27,15)  ;
	   cout<<"-";
	   gotoxy(28,15);
	   cin>>f.mm2;
	   gotoxy(30,15);
	   cout<<"-";
	   gotoxy(31,15);
	   cin>>f.yy2;
	   if(f.dd2>31||f.mm2>12||f.yy2>99)
	{
	 gotoxy(25,15);
	 cout<<"                                       ";
	 gotoxy(2,22);
	 cout<<"aEnter the valid date........................";
	 goto turn2;  //cursor again reset
	}

	   gotoxy(2,22);
	   cout<<"Enter the delivard cement.Qtt.......";
	   gotoxy(20,17);
	   cin>>f.qtt;
	   f.flage=NULL;
	   file.write((char*)&f,sizeof(f));
	   gotoxy(2,22);
	   cout<<"aAdd more? Y/N..................";
	   cin>>a;
	   }while(a=='y'||a=='Y');
	}  //end of function

// function for outward cement menu display

 void report_menu(void)
	{
	  clrscr();
	  gotoxy(31,3);
	  cout<<" REPORT-MENU " ;
	  gotoxy(31,4);
	  cout<<"__________";
	  gotoxy(4,7);

cout<<"*********************************************************";
	  gotoxy(10,9);
	  cout<<"1.Daily Inward Cement Report.";
	  gotoxy(10,11);
	  cout<<"2.Daily Outward Cement Report.";
	  gotoxy(10,13);
	  cout<<"3.Stock.";
	  gotoxy(10,15);
	  cout<<"4.Exit.";
	  gotoxy(4,17);

cout<<"********************************************************
";
	}

//function for outward cement report
 void cement_out::outward_report()
	{
	gotoxy(30,3);
	cout<<"O U T W A R D - R E P O R T";
	gotoxy(3,6);

cout<<"**********************************************************";
	gotoxy(3,7);
	cout<<"Challan    Chl_date    Truck_no    Dispatch_date   Quantity  ";
	gotoxy(3,8);

cout<<"*********************************************";
	file.seekg(0L,ios::beg);
	while(file.read((char*)&f,sizeof(f)))
	  {
	if(f.flage!='*')

cout<<endl<<setw(5)<<f.R_challan<<setw(10)<<f.dd1<<"/"<<f.mm1<<"/"<<f.yy1<<setw(10);
cout<<f.truck_no<<setw(10)<<f.dd2<<"/"<<f.mm2<<"/"<<f.yy2<<setw(10)<<f.qtt<<setw(12);
delay(200);

}

cout<<"
 ********************************************************";
	file.clear();
	cout<<endl<<"Press any key to continue......";
	getch();
	}




/*constructor of class cement_out which initialise the opening file
 ocem.dat*/
 cement_out::cement_out()
 {
	 file.open("ocem.dat",ios::binary|ios::in|ios::out);
	 if(!file)
	 {
	  cout<<"ERROR" ;
	  getch();
	 }
 }

//function which returns the total qautity of outward cement
 int cement_out::stock_out()
  {
	  int temp=0;
	  gotoxy(28,1);
	  cout<<"T O T A L - S T O C K";
	  gotoxy(28,2);
	  cout<<"*********************";
	  file.seekg(0L,ios::beg);
	  while(file.read((char*)&f,sizeof(f)))
	   {
	 if(f.flage!='*')
	 temp=temp+f.qtt;
	   }
	  file.clear();
	  return(temp);
  }
 void stock_menu()
  {
	 gotoxy(28,4);
	 cout<<"S T O C K - S T A T U S ";
	 gotoxy(28,5);
	 cout<<"***********************";
	 gotoxy(17,7);
	 cout<<"****************************************";
	 gotoxy(24,8);
	 cout<<"1.Stock Today.";
	 gotoxy(24,10);
	 cout<<"2.Stock At Recieve Date.";
	 gotoxy(17,11);
	 cout<<"***************************************";

  }

  void main()
   {     for(int s=1000;s>100;s+50)
	 {
	 sound(s);
	 delay(50);
	 }
	 nosound();



	 textcolor(5);
	 clrscr();
	 long int passu;
	 gotoxy(20,10);
	 cout<<"Enter the password : ";
	 cin>>passu  ;
	 if(passu==654321)
	  {
	   clrscr();
	   help();
	   do
	{
	 cement_in  obj1;     //class objects
	 cement_out obj2;
	 clrscr();
	 show_menu();
	 cout<<endl<<"Enter your choice:";
	 cin>>choice;
	 switch(choice)                       //  main choice
	 {
	//for inward cement entry
	case 1:
	   clrscr();
	   obj1.get_inward();
	break;

	// for outward cement entry
	case 2:
	   clrscr();
	   obj2.del_data();
	break;

	//for cement outward & inward report
	case 3:
	   clrscr();
	   report_menu();
	   gotoxy(35,45);
	   cout<<"Enter the choice:";
	   gotoxy(36,35);
	   cin>>R_opt;
	   switch(R_opt)
	 {
	   //  for showing the inward cement report
	   case 1:
	   clrscr();
	   obj1.inward_report();
	   break;
	   // for showing outward cement report
	   case 2:
	   clrscr();
	   obj2.outward_report();
	   break;
	   // for stock status
	   case 3:
	   clrscr();
	   stock_menu();
	   cout<<endl<<"Enter your choice:";
	   cin>>c;
	   switch(c)
	 {
	case 1:
	clrscr();
	int p= obj1.stock_in();
	int q=obj2.stock_out();
	gotoxy(50,5);
	cout<<"Date:"<<__DATE__;
	gotoxy(4,8);
	cout<<"
aTotal present stock today :"<<p-q<<" M.T. ";
	getch();
	break;

	case 2:
	clrscr();
	obj1.stock_date();
	getch();
	break;

	 }
	  }   //internal switch closed


	 }          //top switch closed

	 cout<<endl<<"	aDo you want to quit:-";
	 cin>>ch;
	 }while(ch!='y'&&ch!='Y');
	 textcolor(6);

	   }
	   /*if password is not correct*/
	   else
	   {
	gotoxy(20,12);
	cout<<"a Password is not correct" ;
	gotoxy(20,13);
	cout<<"a You are not authorised person";
	getch();

   }
   }
