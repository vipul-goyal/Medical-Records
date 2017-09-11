

//**********************************************************
//	PROJECT: MEDICAL RECORDS
//**********************************************************

//**********************************************************
//	INCLUDED HEADER FILES
//**********************************************************

#include<fstream.h>
#include<conio.h>
#include<string.h>
#include<dos.h>
#include<stdio.h>
#include<process.h>
#include<graphics.h>
#include<stdlib.h>

void pass_check();
void menu();
void pass_change();
void opening();

static int m=0,counter=0,check1=0,z=0,tp=0,fg=0;
char temp[5];


//**********************************************************
// FORM DATA STRUCTURES
//**********************************************************


struct DOB
 {
  char ye[5],mo[5],da[5];
 };


struct address
 {
   char c_add[300];
   char pin[10];
 };


struct parent
 {
   char f_name[50],m_name[50],f_occup[50],m_occup[50];
   char f_email[50],m_email[50];
   char f_mobile[11],m_mobile[11];
 };


struct medical
 {
   char g_opt,q_allergic[201],q_hospital[201],q_history[201],a_opt,h_opt,his_opt,m_opt,d_name[50],q_medication[201],dosage[100];
   int opt_his,opt_acc;
   char d_tele[10];
 };

//**********************************************************
// THIS CLASS CONTROL ALL THE FUNCTIONS RELATED TO PASSWORD
//**********************************************************


class password
 {
  char str1[11],str[11];
  public:
  void pass();
  void pass_change();
 }pass;


//****************************************************************
// THIS CLASS CONTROL ALL THE FUNCTIONS RELATED TO MEDICAL RECORDS
//****************************************************************


class child
 {
  char c_name[50],blood_g[3],transport[10],sec[5];
  char tele[10],admiss[5];
  char clas[5];
  char roll[5];
  address add;
  DOB dob;
  parent p;
  medical m;
  public:
  void show_form();
  void med_form();
  void delete_record();
  void putdata();
  void getdata();
  void check_admin();
  void modify();
  int retname(char ad[])
   {
     if(strcmpi(ad,admiss)==0)
     return 1;
     else
     return 0;
   }
 }cd,mn;


//**********************************************************
// FUNCTION TO DISPLAY THE MEDICAL RECORD OF A CHILD
//**********************************************************

void child::putdata()
 {
   gotoxy(1,1);
   cout<<"NAME : ";
   cout<<c_name;
   gotoxy(20,1);
   cout<<"ADMISSION NUMBER : ";
   cout<<admiss;
   gotoxy(1,2);
   cout<<"CLASS : ";
   cout<<clas;
   gotoxy(14,2);
   cout<<"SECTION : ";
   cout<<sec;
   gotoxy(28,2);
   cout<<"D.O.B.(d/m/y) : ";
   cout<<dob.da;
   gotoxy(46,2);
   cout<<'/';
   cout<<dob.mo;
   gotoxy(49,2);
   cout<<'/';
   cout<<dob.ye;
   gotoxy(54,2);
   cout<<"BLOOD GROUP : ";
   cout<<blood_g;
   gotoxy(1,3);
   cout<<"FATHER'S NAME : ";
   cout<<p.f_name;
   gotoxy(1,4);
   cout<<"OCCUPATION : ";
   cout<<p.f_occup;
   gotoxy(1,5);
   cout<<"MOBILE : ";
   cout<<p.f_mobile;
   gotoxy(30,5);
   cout<<"EMAIL : ";
   cout<<p.f_email;
   gotoxy(1,6);
   cout<<"MOTHER'S NAME : ";
   cout<<p.m_name;
   gotoxy(1,7);
   cout<<"OCCUPATION : ";
   cout<<p.m_occup;
   gotoxy(1,8);
   cout<<"MOBILE : ";
   cout<<p.m_mobile;
   gotoxy(30,8);
   cout<<"EMAIL : ";
   cout<<p.m_email;
   gotoxy(1,9);
   cout<<"ADDRESS : ";
   cout<<add.c_add;
   gotoxy(1,10);
   cout<<"PINCODE : ";
   cout<<add.pin;
   gotoxy(30,10);
   cout<<"TELEPHONE : ";
   cout<<tele;
   gotoxy(1,11);
   cout<<"TRANSPORT : ";
   cout<<transport;
   gotoxy(1,12);
   cout<<"Is the child allergic to anything ? (y/n) : ";
   cout<<m.a_opt;
   if(m.a_opt=='y')
    {
      cout<<endl;
      cout<<"Give brief detail : ";
      cout<<m.q_allergic;
    }
   cout<<endl;
   cout<<"Has the child ever been hospitalized ? (y/n) : ";
   cout<<m.h_opt;
   if(m.h_opt=='y')
    {
      cout<<endl;
      cout<<"give brief detail : ";
      cout<<m.q_hospital;
    }
   cout<<endl;
   cout<<"Does the child have a chronic/medical case history ? (y/n) : ";
   cout<<m.his_opt;
   if(m.his_opt=='y')
    {
      cout<<endl;
      cout<<"Give brief detail : ";
      cout<<m.q_history;
    }
   cout<<endl;
   cout<<"Name of the doctor : Dr. ";
   cout<<m.d_name;
   cout<<endl;
   cout<<"Doctor's contact no. : ";
   cout<<m.d_tele;
   cout<<endl;
   cout<<"Is the child under any kind of medication ? (y/n) : ";
   cout<<m.m_opt;
   if(m.m_opt=='y')
    {
      cout<<endl;
      cout<<"Name of the medicine (seperated by ,) : ";
      cout<<m.q_medication;
      cout<<endl;
      cout<<"Dosage prescribed : ";
      cout<<m.dosage;
    }
   cout<<endl;
   cout<<"Ward to participate in competitive games ? (y/n) : ";
   cout<<m.g_opt;
   cout<<endl;
   cout<<"In case of medical emergency involving previous history : ";
   switch(m.opt_his)
    {
      case 1:cout<<"personal physician";
	     break;
      case 2:cout<<"School's panel of doctors";
	     break;
      default:cout<<"error";
    }
   cout<<endl;
   cout<<"In case of medical emergency involving accident : ";
   switch(m.opt_acc)
    {
      case 1:cout<<" personal physician";
	     break;
      case 2:cout<<" School's panel of doctors";
	     break;
      default:cout<<"error";
    }
 }
//**********************************************************
// FUNCTION TO DELETE A CERTAIN MEDICAL RECORD
//**********************************************************

void child::delete_record()
 {
  int flag=0,i;
  fstream temp1("temp.dat",ios::out|ios::binary|ios::app);
  fstream file("stu_info.dat",ios::in|ios::binary);
  file.seekg(0);
  while(file.read((char*)&cd,sizeof(cd)))
   {
    if(strcmpi(cd.admiss,::temp)==0)
    flag=1;
    else
    temp1.write((char*)&cd,sizeof(cd));
   }
  file.close();
  temp1.close();
  remove("stu_info.dat");
  rename("temp.dat","stu_info.dat");
  cleardevice();
  rectangle(80,150,600,300);
  settextstyle(1,0,4);
  setcolor(2);
  outtextxy(340,225,"Record Successfully Deleted!");
  i=0;
  while(!kbhit())
   {
    setcolor(i);
    rectangle(80,150,600,300);
    setcolor(i+1);
    rectangle(90,160,590,290);
    setcolor(i+2);
    rectangle(100,170,580,280);
    setcolor(i+3);
    rectangle(110,180,570,270);
    delay(150);
    i++;
    if(i>10)
     {
      i=1;
     }
   }
  setcolor(15);
  menu();
 }
//**********************************************************
// FUNCTION TO CONTROL THE MODIFICATION OF A RECORD
//**********************************************************

void md()
 {
   cleardevice();
   int flag=0;
   fstream fio("stu_info.dat", ios::in|ios::out|ios::binary);
   long pos;
   flag=0;
   while(!fio.eof())
    {
      int r=0;
      pos=fio.tellg();
      fio.read((char*)&cd,sizeof(cd));
      r=cd.retname(::temp);
      if((r==1))
	{
	  flag=1;
	  fg=0;
	  cd.modify();
	  fio.seekg(pos);
	  fio.write((char*)&cd,sizeof(cd));
	  break;
	}
    }
   if(flag==1)
     {
       cleardevice();
       gotoxy(30,12);
       cout<<"---Edited Successfully---";
       getch();
       cleardevice();
       cd.putdata();
    }
   fio.close();
   getch();
 }
//**********************************************************
// FUNCTION TO MODIFY A CERTAIN RECORD
//**********************************************************

void child::modify()
 {
   char n_blood_g[3],n_transport[10],n_sec[5];
   char n_tele[10],n_admiss[5];
   char n_clas[5];
   char n_roll[5];
   int m1=0,m3=0,m4=0,m5=0,m6=0,m7=0,m8=0,sum=0;
   address n_add;
   DOB n_dob;
   parent n_p;
   medical n_m;
   char n_car_name[25];
   char op;
   int chh;
   do
    {
      cleardevice();
      fg=0;
      gotoxy(1,1);
      cout<<"1.NAME : ";
      cout<<c_name;
      cout<<endl;
      cout<<"2.CLASS : ";
      cout<<clas;
      cout<<endl;
      cout<<"3.SECTION : ";
      cout<<sec;
      cout<<endl;
      cout<<"4.D.O.B.(d/m/y) : ";
      cout<<dob.da;
      cout<<'/';
      cout<<dob.mo;
      cout<<'/';
      cout<<dob.ye;
      cout<<endl;
      cout<<"5.BLOOD GROUP : ";
      cout<<blood_g;
      cout<<endl;
      cout<<"6.FATHER'S NAME : ";
      cout<<p.f_name;
      cout<<endl;
      cout<<"7.OCCUPATION : ";
      cout<<p.f_occup;
      cout<<endl;
      cout<<"8.MOBILE : ";
      cout<<p.f_mobile;
      cout<<endl;
      cout<<"9.EMAIL : ";
      cout<<p.f_email;
      cout<<endl;
      cout<<"10.MOTHER'S NAME : ";
      cout<<p.m_name;
      cout<<endl;
      cout<<"11.OCCUPATION : ";
      cout<<p.m_occup;
      cout<<endl;
      cout<<"12.MOBILE : ";
      cout<<p.m_mobile;
      cout<<endl;
      cout<<"13.EMAIL : ";
      cout<<p.m_email;
      cout<<endl;
      cout<<"14.ADDRESS : ";
      cout<<add.c_add;
      cout<<endl;
      cout<<"15.PINCODE : ";
      cout<<add.pin;
      cout<<endl;
      cout<<"16.TELEPHONE : ";
      cout<<tele;
      cout<<endl;
      cout<<"17.TRANSPORT : ";
      cout<<transport;
      char m1,m2,m3;
      gotoxy(25,20);
      cout<<"Enter option to be modified: ";
      cin>>chh;
      switch(chh)
       {
	case 1:do
		 {
		   gotoxy(35,22);
		   cout<<" Name: ";
		   gets(n_car_name);
		 }while((strcmp(n_car_name,'\0'))==0);
	       for(int i=0;n_car_name[i]!='\0';i++)
		 {
		   m1=n_car_name[i];
		   if((m1>=65&&m1<=90)||(m1>=97&&m1<=122))
		    {}
		   else
		    {
		      gotoxy(40,22);
		      cout<<" Error in name";
		      getch();
		      gotoxy(40,22);
		      cout<<"               ";
		      i=z-1;
		      do
		       {
			 gotoxy(35,22);
			 cout<<"Name: ";
			 gets(n_car_name);
		       }while((strcmp(n_car_name,'\0'))==0);
		    }
		 }
	       strcpy(c_name,n_car_name);
	       break;
	case 2:do
		{
		  gotoxy(35,22);
		  cout<<"CLASS : ";
		  gets(n_clas);
		}while((strcmp(n_clas,'\0'))==0);
	       int m2=0;
	       for(int h=0;n_clas[h]!='\0';h++)
		{
		  m1=n_clas[0];
		  m2=n_clas[1];
		  if(h<2)
		   {
		    if(m2==0)
		     {
		      if(m1>48 && m1<=57)
		       {
		       }
		      else
		       {
			gotoxy(50,25);
			cout<<"error in class..";
			getch();
			gotoxy(50,25);
			cout<<"                             ";
			gotoxy(35,22);
			cout<<"                                ";
			do
			 {
			   gotoxy(35,22);
			   cout<<"CLASS : ";
			   gets(n_clas);
			 }while((strcmp(n_clas,'\0'))==0);
			h=z-1;
		       }
		     }
		    else if(m1==49)
		     {
		      if(m2>=48 && m2<=50)
		       {
		       }
		      else
		       {
			gotoxy(50,25);
			cout<<"error in students class..";
			getch();
			gotoxy(50,25);
			cout<<"                             ";
			gotoxy(35,22);
			cout<<"                                ";
			do
			 {
			  gotoxy(35,22);
			  cout<<"CLASS : ";
			  gets(n_clas);
			 }while((strcmp(n_clas,'\0'))==0);
			h=z-1;
		       }
		     }
		    else
		     {
		       gotoxy(50,25);
		       cout<<"error in students class..";
		       getch();
		       gotoxy(50,25);
		       cout<<"                             ";
		       gotoxy(35,22);
		       cout<<"                                ";
		       do
			{
			  gotoxy(35,22);
			  cout<<"CLASS : ";
			  gets(n_clas);
			}while((strcmp(n_clas,'\0'))==0);
		       h=z-1;
		     }
		   }
		  else
		   {
		     gotoxy(50,25);
		     cout<<"error in students class..";
		     getch();
		     gotoxy(50,25);
		     cout<<"                             ";
		     gotoxy(35,22);
		     cout<<"                                ";
		     do
		      {
		       gotoxy(35,22);
		       cout<<"CLASS : ";
		       gets(n_clas);
		      }while((strcmp(n_clas,'\0'))==0);
		     h=z-1;
		   }
		}
	       strcpy(clas,n_clas);
	       break;
	case 3:do
		{
		  gotoxy(35,22);
		  cout<<"SECTION : ";
		  gets(n_sec);
		}while((strcmp(n_sec,'\0'))==0);
	       for(i=0;n_sec[i]!='\0';i++)
		{
		  m1=n_sec[i];
		  if(((m1>=65&&m1<=90)||(m1>=97&&m1<=122))&&(i<1))
		   {
		   }
		  else
		   {
		     gotoxy(50,25);
		     cout<<"error in students section..";
		     getch();
		     gotoxy(50,25);
		     cout<<"                             ";
		     gotoxy(35,22);
		     cout<<"                                ";
		     do
		      {
			gotoxy(35,22);
			cout<<"SECTION : ";
			gets(n_sec);
		      }while((strcmp(n_sec,'\0'))==0);
		     i=z-1;
		   }
		}
	       strcpy(sec,n_sec);
	       break;
	case 4:gotoxy(35,22);
	       cout<<"D.O.B.(d/m/y) : ";
	       cin>>n_dob.da;
	       gotoxy(38,22);
	       cout<<'/';
	       cin>>n_dob.mo;
	       gotoxy(41,22);
	       cout<<'/';
	       cin>>n_dob.ye;
	       for(h=0;n_dob.da[h]!='\0';h++)
		{
		  m1=n_dob.mo[0];
		  m2=n_dob.mo[1];
		  m3=n_dob.da[0];
		  m4=n_dob.da[1];
		  m5=n_dob.ye[0];
		  m6=n_dob.ye[1];
		  m7=n_dob.ye[2];
		  m8=n_dob.ye[3];
		  if(h<2)
		   {
		     if(((m1==49)||(m1==51)||(m1==53)||(m1==55)||(m1==56)||
		       (m1==49 && m2==48)||(m1==49 && m2==50))&&
		       ((m3>=49 && m3<=50)||(m3==51 && m4<=49)))
		      {
		      }
		     else if(((m1==52)||(m1==54)||(m1==57)||(m1==49 && m2==49))
			  &&((m3>=49 && m3<=50)||(m3==51 && m4<=30)))
		      {
		      }
		     else if(m1==50)
		      {
			m5=m5-48;
			m6=m6-48;
			m7=m7-48;
			m8=m8-48;
			sum=(m5*1000)+(m6*100)+(m7*10)+m8;
			if((sum%4==0) && (m3>=49 && m3<=50))
			 {}
			else if(((sum%4!=0) && (m3==49)) || ((m3==50) && (m4>=48 && m4<=56)))
			 {}
			else
			 {
			   gotoxy(50,25);
			   cout<<"error in students DOB..";
			   getch();
			   gotoxy(50,25);
			   cout<<"                             ";
			   gotoxy(35,22);
			   cout<<"                                               ";
			   gotoxy(35,22);
			   cout<<"D.O.B.(d/m/y) : ";
			   cin>>n_dob.da;
			   gotoxy(38,22);
			   cout<<'/';
			   cin>>n_dob.mo;
			   gotoxy(41,2);
			   cout<<'/';
			   cin>>n_dob.ye;
			   h=z-1;
			 }
		      }
		   }
		  else
		   {
		     gotoxy(50,25);
		     cout<<"error in students DOB..";
		     getch();
		     gotoxy(50,25);
		     cout<<"                             ";
		     gotoxy(35,22);
		     cout<<"                                               ";
		     gotoxy(35,22);
		     cout<<"D.O.B.(d/m/y) : ";
		     cin>>n_dob.da;
		     gotoxy(38,22);
		     cout<<'/';
		     cin>>n_dob.mo;
		     gotoxy(41,22);
		     cout<<'/';
		     cin>>n_dob.ye;
		     h=z-1;
		   }
		}
	       strcpy(dob.mo,n_dob.mo);
	       strcpy(dob.ye,n_dob.ye);
	       strcpy(dob.da,n_dob.da);
	       break;
	case 5:do
		{
		  gotoxy(35,22);
		  cout<<"BLOOD GROUP : ";
		  gets(n_blood_g);
		}while((strcmp(n_blood_g,'\0'))==0);
	       for(i=0;n_blood_g[i]!='\0';i++)
		{
		 m1=n_blood_g[0];
		 m2=n_blood_g[1];
		 m3=n_blood_g[2];
		 if(((((m1>=65&&m1<=66)||(m1==79))||(m1>=97&&m1<=98)||(m1==111)) && (m2==43 || m2==45 )) &&(i<2))
		  {}
		 else if((((m1==65 & m2==66) || (m1==97&&m2==98)) && (m3==43 || m3==45)) && (i<3))
		  {}
		 else
		  {
		    gotoxy(50,25);
		    cout<<"error in students blood group..";
		    getch();
		    gotoxy(50,25);
		    cout<<"                                  ";
		    gotoxy(35,22);
		    cout<<"                                               ";
		    do
		     {
		       gotoxy(35,22);
		       cout<<"BLOOD GROUP : ";
		       cin>>n_blood_g;
		     }while((strcmp(n_blood_g,'\0'))==0);
		    i=z-1;
		  }
		}
	       strcpy(blood_g,n_blood_g);
	       break;
	case 6:do
		{
		  gotoxy(35,22);
		  cout<<"FATHER'S NAME : ";
		  gets(n_p.f_name);
		}while((strcmp(n_p.f_name,'\0'))==0);
	       for(i=0;n_p.f_name[i]!='\0';i++)
		{
		  m1=n_p.f_name[i];
		  if((m1>=65&&m1<=90)||(m1>=97&&m1<=122))
		   {}
		  else
		   {
		     gotoxy(50,25);
		     cout<<"error in father's name";
		     getch();
		     gotoxy(50,25);
		     cout<<"                             ";
		     gotoxy(35,22);
		     cout<<"                                        ";
		     do
		      {
			gotoxy(35,22);
			cout<<"FATHER'S NAME : ";
		       gets(n_p.f_name);
		      }while((strcmp(n_p.f_name,'\0'))==0);
		     i=z-1;
		   }
		}
	       strcpy(p.f_name,n_p.f_name);
	       break;
	case 7:do
		{
		  gotoxy(35,22);
		  cout<<"OCCUPATION : ";
		  gets(n_p.f_occup);
		}while((strcmp(n_p.f_occup,'\0'))==0);
	       for(i=0;n_p.f_occup[i]!='\0';i++)
		{
		  m1=n_p.f_occup[i];
		  if((m1>=65&&m1<=90)||(m1>=97&&m1<=122))
		   {}
		  else
		   {
		     gotoxy(50,25);
		     cout<<"error in father's occupation..";
		     getch();
		     gotoxy(50,25);
		     cout<<"                                 ";
		     gotoxy(35,22);
		     cout<<"                                        ";
		     do
		      {
			gotoxy(35,22);
			cout<<"OCCUPATION : ";
			gets(n_p.f_occup);
		      }while((strcmp(n_p.f_occup,'\0'))==0);
		     i=z-1;
		   }
		}
	       strcpy(p.f_occup,n_p.f_occup);
	       break;
	case 8:do
		{
		  gotoxy(35,22);
		  cout<<"MOBILE : ";
		  gets(n_p.f_mobile);
		}while((strcmp(n_p.f_mobile,'\0'))==0);
	       for(i=0;n_p.f_mobile[i]!='\0';i++)
		{
		  m1=n_p.f_mobile[0];
		  m2=n_p.f_mobile[i];
		  m3=strlen(n_p.f_mobile);
		  if(((m2>=48)&&(m2<=57))&& m1!=48&&m3==10)
		   {}
		  else
		   {
		     gotoxy(50,25);
		     cout<<"error in fathers number";
		     getch();
		     gotoxy(50,25);
		     cout<<"                                 ";
		     gotoxy(35,22);
		     cout<<"                                        ";
		     do
		      {
			gotoxy(35,22);
			cout<<"MOBILE : ";
			gets(n_p.f_mobile);
		      }while((strcmp(n_p.f_mobile,'\0'))==0);
		     i=z-1;
		   }
		}
	       strcpy(p.f_mobile,n_p.f_mobile);
	       break;
	case 9:do
		{
		  gotoxy(35,22);
		  cout<<"EMAIL : ";
		  gets(n_p.f_email);
		}while((strcmp(n_p.f_email,'\0'))==0);
	       m4=0;
	       for(m5=0;m4==0;m5++)
		{
		 m3=0;
		 for(i=0;n_p.f_email[i]!='\0';i++)
		   {
		     m1=n_p.f_email[i];
		     if(m1==64)
		      {
			m3++;
		      }
		   }
		 if(m3!=1)
		  {
		    gotoxy(50,25);
		    cout<<"error in fathers email";
		    getch();
		    gotoxy(50,25);
		    cout<<"                                 ";
		    gotoxy(35,22);
		    cout<<"                                        ";
		    do
		     {
		       gotoxy(35,22);
		       cout<<"EMAIL : ";
		       gets(n_p.f_email);
		     }while((strcmp(n_p.f_email,'\0'))==0);
		  }
		 else
		 m4=1;
		}
	       strcpy(p.f_email,n_p.f_email);
	       break;
	case 10:do
		 {
		  gotoxy(35,22);
		  cout<<"MOTHER'S NAME : ";
		  gets(n_p.m_name);
		 }while((strcmp(n_p.m_name,'\0'))==0);
		for(i=0;n_p.m_name[i]!='\0';i++)
		 {
		  m1=n_p.m_name[i];
		  if((m1>=65&&m1<=90)||(m1>=97&&m1<=122))
		   {
		   }
		  else
		   {
		     gotoxy(50,25);
		     cout<<"error in mother's name";
		     getch();
		     gotoxy(50,25);
		     cout<<"                             ";
		     gotoxy(35,22);
		     cout<<"                                        ";
		     do
		      {
			gotoxy(35,22);
			cout<<"MOTHER'S NAME : ";
			gets(n_p.m_name);
		      }while((strcmp(n_p.m_name,'\0'))==0);
		     i=z-1;
		   }
		}
	       strcpy(p.m_name,n_p.m_name);
	       break;
	case 11:do
		 {
		   gotoxy(35,22);
		   cout<<"OCCUPATION : ";
		   gets(n_p.m_occup);
		 }while((strcmp(n_p.m_occup,'\0'))==0);
		for(i=0;n_p.m_occup[i]!='\0';i++)
		 {
		   m1=n_p.m_occup[i];
		   if((m1>=65&&m1<=90)||(m1>=97&&m1<=122))
		     {}
		   else
		    {
		      gotoxy(50,25);
		      cout<<"error in mother's occupation..";
		      getch();
		      gotoxy(50,25);
		      cout<<"                                 ";
		      gotoxy(35,22);
		      cout<<"                                        ";
		      do
		       {
			 gotoxy(35,22);
			 cout<<"OCCUPATION : ";
			 gets(n_p.m_occup);
		       }while((strcmp(n_p.m_occup,'\0'))==0);
		      i=z-1;
		    }
		 }
		strcpy(p.m_occup,n_p.m_occup);
		break;
	case 12:do
		 {
		   gotoxy(35,22);
		   cout<<"MOBILE : ";
		   gets(n_p.m_mobile);
		 }while((strcmp(n_p.m_mobile,'\0'))==0);
		for(i=0;n_p.m_mobile[i]!='\0';i++)
		 {
		   m1=n_p.m_mobile[0];
		   m2=n_p.m_mobile[i];
		   m3=strlen(n_p.m_mobile);
		   if(((m2>=48)&&(m2<=57))&& m1!=48&&m3==10)
		    {}
		   else
		    {
		      gotoxy(50,25);
		      cout<<"error in mother's number";
		      getch();
		      gotoxy(50,25);
		      cout<<"                                 ";
		      gotoxy(35,22);
		      cout<<"                                        ";
		      do
		       {
			 gotoxy(35,22);
			 cout<<"MOBILE : ";
			 gets(n_p.m_mobile);
		       }while((strcmp(n_p.m_mobile,'\0'))==0);
		      i=z-1;
		    }
		 }
		strcpy(p.m_mobile,n_p.m_mobile);
		break;
	case 13:do
		 {
		   gotoxy(35,22);
		   cout<<"EMAIL : ";
		   gets(n_p.m_email);
		 }while((strcmp(n_p.m_email,'\0'))==0);
		m4=0;
		for(m5=0;m4==0;m5++)
		 {
		   m3=0;
		   for(i=0;n_p.m_email[i]!='\0';i++)
		    {
		      m1=n_p.m_email[i];
		      if(m1==64)
		      m3++;
		    }
		   if(m3!=1)
		    {
		      gotoxy(50,25);
		      cout<<"error in mother's email";
		      getch();
		      gotoxy(50,25);
		      cout<<"                                 ";
		      gotoxy(35,22);
		      cout<<"                                        ";
		      do
		       {
			 gotoxy(35,22);
			 cout<<"EMAIL : ";
			 gets(n_p.m_email);
		       }while((strcmp(n_p.m_email,'\0'))==0);
		     }
		   else
		   m4=1;
		 }
		strcpy(p.m_email,n_p.m_email);
		break;
	case 14:do
		 {
		   gotoxy(30,22);
		   cout<<"ADDRESS : ";
		   gets(add.c_add);
		 }while((strcmp(add.c_add,'\0'))==0);
	case 15:do
		 {
		   gotoxy(35,22);
		   cout<<"PINCODE : ";
		   gets(n_add.pin);
		 }while((strcmp(n_add.pin,'\0'))==0);
		for(i=0;n_add.pin[i]!='\0';i++)
		 {
		   m1=n_add.pin[i];
		   m2=n_add.pin[0];
		   m3=strlen(n_add.pin);
		   if((m2!=48)&&(m3==6)&&(m1>=48&&m1<57))
		    {}
		   else
		    {
		      gotoxy(50,25);
		      cout<<"error in pincode";
		      getch();
		      gotoxy(50,25);
		      cout<<"                                 ";
		      gotoxy(35,22);
		      cout<<"                                        ";
		      do
		       {
			 gotoxy(35,22);
			 cout<<"PINCODE : ";
			 gets(n_add.pin);
		       }while((strcmp(n_add.pin,'\0'))==0);
		      i=z-1;
		    }
		 }
		strcpy(add.pin,n_add.pin);
		break;
	case 16:do
		 {
		   gotoxy(35,22);
		   cout<<"TELEPHONE (without code) : ";
		   gets(n_tele);
		 }while((strcmp(n_tele,'\0'))==0);
		for(i=0;p.m_mobile[i]!='\0';i++)
		 {
		   m1=p.m_mobile[0];
		   m2=p.m_mobile[i];
		   m3=strlen(p.m_mobile);
		   if(((m2>=48)&&(m2<=57))&& m1!=48&&m3==8)
		    {}
		   else
		    {
		      gotoxy(50,25);
		      cout<<"error in telephone number";
		      getch();
		      gotoxy(50,25);
		      cout<<"                          ";
		      gotoxy(35,22);
		      cout<<"                                                ";
		      do
		       {
			 gotoxy(35,22);
			 cout<<"TELEPHONE (without code) : ";
			 gets(p.m_mobile);
		       }while((strcmp(p.m_mobile,'\0'))==0);
		      i=z-1;
		    }
		 }
		strcpy(tele,n_tele);
		break;
	case 17:do
		 {
		   gotoxy(35,22);
		   cout<<"TRANSPORT : ";
		   gets(n_transport);
		 }while((strcmp(n_transport,'\0'))==0);
		for(i=0;n_transport[i]!='\0';i++)
		 {
		   m1=n_transport[i];
		   if((m1>=65&&m1<=90)||(m1>=97&&m1<=122))
		    {}
		   else
		    {
		      gotoxy(50,25);
		      cout<<"error in students n_transport";
		      getch();
		      gotoxy(50,25);
		      cout<<"                               ";
		      gotoxy(35,22);
		      cout<<"                                        ";
		      do
		       {
			 gotoxy(35,22);
			 cout<<"TRANSPORT : ";
			 gets(n_transport);
		       }while((strcmp(n_transport,'\0'))==0);
		      i=z-1;
		    }
		 }
		strcpy(transport,n_transport);
		break;
	default:cout<<"error in choice";

       }
      gotoxy(28,24);
      cout<<"Want to edit more? (y/n) ";
      gotoxy(33,25);
      cout<<"Enter: ";
      cin>>op;
    }while(op=='Y'||op=='y');
  }
//**********************************************************
// FUNCTION TO DISPLAY A CERTAIN FORM
//**********************************************************

void child::show_form()
 {
   setcolor(15);
   cleardevice();
   fstream data("stu_info.dat", ios::in|ios::out|ios::binary);
   data.seekg(0);
   int flag=0;
   while(!data.eof())
    {
      data.read((char*)&mn,sizeof(mn));
      if(strcmpi(mn.admiss,::temp)==0)
       {
	  flag=1;
	  fg=0;
	  mn.putdata();
	  getch();
	  menu();
       }
    }
   menu();
   data.close();
 }

//**********************************************************
// FUNCTION TO GET INFORMATION FOR A CERTAIN RECORD
//**********************************************************

void child::getdata()
 {
   int check=1,check1=0,check2=0,check3=0;
   int m1=0,m3=0,m4=0,m5=0,m6=0,m7=0,m8=0,sum=0;
   char ch1,ch2;
   do
    {
      gotoxy(1,1);
      cout<<"NAME : ";
      gets(c_name);
     }while((strcmp(c_name,'\0'))==0);
    for(int i=0;c_name[i]!='\0';i++)
     {
	m1=c_name[i];
	if((m1>=65&&m1<=90)||(m1>=97&&m1<=122))
	  {}
	else
	 {
	   gotoxy(57,25);
	   cout<<"error in name";
	   getch();
	   cd.med_form();
	 }
     }
    do
     {
	gotoxy(25,1);
	cout<<"ADMISS. # : ";
	gets(admiss);
     }while((strcmp(admiss,'\0'))==0);
    for(int h=0;admiss[h]!='\0';h++)
     {
	m1=admiss[h];
	if(m1>=48&&m1<=57)
	 {
	 }
	else
	 {
	   gotoxy(50,25);
	   cout<<"error in admission number..";
	   getch();
	   gotoxy(50,25);
	   cout<<"                             ";
	   gotoxy(25,1);
	   cout<<"                                ";
	   do
	    {
	       gotoxy(25,1);
	       cout<<"ADMISS. # : ";
	       gets(admiss);
	    }while((strcmp(admiss,'\0'))==0);
	   h=z-1;
	 }

     }
    do
     {
       gotoxy(1,2);
       cout<<"CLASS : ";
       gets(clas);
     }while((strcmp(clas,'\0'))==0);
    int m2=0;
    for(h=0;clas[h]!='\0';h++)
     {
       m1=clas[0];
       m2=clas[1];
       if(h<2)
	{
	  if(m2==0)
	   {
	      if(m1>48 && m1<=57)
	       {}
	      else
	       {
		  gotoxy(50,25);
		  cout<<"error in class..";
		  getch();
		  gotoxy(50,25);
		  cout<<"                             ";
		  gotoxy(1,2);
		  cout<<"                                ";
		  do
		   {
		     gotoxy(1,2);
		     cout<<"CLASS : ";
		     gets(clas);
		   }while((strcmp(clas,'\0'))==0);
		  h=z-1;
	       }
	   }
	  else if(m1==49)
	   {
	     if(m2>=48 && m2<=50)
	      {}
	     else
	      {
		 gotoxy(50,25);
		 cout<<"error in students class..";
		 getch();
		 gotoxy(50,25);
		 cout<<"                             ";
		 gotoxy(1,2);
		 cout<<"                                ";
		 do
		  {
		     gotoxy(1,2);
		     cout<<"CLASS : ";
		     gets(clas);
		  }while((strcmp(clas,'\0'))==0);
		 h=z-1;
	      }
	   }
	  else
	   {
	      gotoxy(50,25);
	      cout<<"error in students class..";
	      getch();
	      gotoxy(50,25);
	      cout<<"                             ";
	      gotoxy(1,2);
	      cout<<"                                ";
	      do
	       {
		 gotoxy(1,2);
		 cout<<"CLASS : ";
		 gets(clas);
	       }while((strcmp(clas,'\0'))==0);
	      h=z-1;
	   }
	}
       else
	{
	   gotoxy(50,25);
	   cout<<"error in students class..";
	   getch();
	   gotoxy(50,25);
	   cout<<"                             ";
	   gotoxy(1,2);
	   cout<<"                                ";
	   do
	    {
	      gotoxy(1,2);
	      cout<<"CLASS : ";
	      gets(clas);
	    }while((strcmp(clas,'\0'))==0);
	   h=z-1;
	}
     }
    do
     {
       gotoxy(14,2);
       cout<<"SECTION : ";
       gets(sec);
     }while((strcmp(sec,'\0'))==0);
    for(i=0;sec[i]!='\0';i++)
     {
	m1=sec[i];
	if(((m1>=65&&m1<=90)||(m1>=97&&m1<=122))&&(i<1))
	 {}
	else
	 {
	   gotoxy(50,25);
	   cout<<"error in students section..";
	   getch();
	   gotoxy(50,25);
	   cout<<"                             ";
	   gotoxy(14,2);
	   cout<<"                                ";
	   do
	    {
	      gotoxy(14,2);
	      cout<<"SECTION : ";
	      gets(sec);
	    }while((strcmp(sec,'\0'))==0);
	   i=z-1;
	 }
     }
    gotoxy(28,2);
    cout<<"D.O.B.(d/m/y) : ";
    cin>>dob.da;
    gotoxy(46,2);
    cout<<'/';
    cin>>dob.mo;
    gotoxy(49,2);
    cout<<'/';
    cin>>dob.ye;
    for(h=0;dob.da[h]!='\0';h++)
     {
	m1=dob.mo[0];
	m2=dob.mo[1];
	m3=dob.da[0];
	m4=dob.da[1];
	m5=dob.ye[0];
	m6=dob.ye[1];
	m7=dob.ye[2];
	m8=dob.ye[3];
	if(h<2)
	 {
	   if(((m1==49)||(m1==51)||(m1==53)||(m1==55)||(m1==56)||
		(m1==49 && m2==48)||(m1==49 && m2==50))&&
		((m3>=49 && m3<=50)||(m3==51 && m4<=49)))
	    {}
	   else if(((m1==52)||(m1==54)||(m1==57)||(m1==49 && m2==49))
		&&((m3>=49 && m3<=50)||(m3==51 && m4<=30)))
	    {}
	   else if(m1==50)
	    {
	      m5=m5-48;
	      m6=m6-48;
	      m7=m7-48;
	      m8=m8-48;
	      sum=(m5*1000)+(m6*100)+(m7*10)+m8;
	      if((sum%4==0) && (m3>=49 && m3<=50))
	       {}
	      else if(((sum%4!=0) && (m3==49)) || ((m3==50) && (m4>=48 && m4<=56)))
	       {}
	      else
	       {
		  gotoxy(50,25);
		  cout<<"error in students DOB..";
		  getch();
		  gotoxy(50,25);
		  cout<<"                             ";
		  gotoxy(28,2);
		  cout<<"                                               ";
		  gotoxy(28,2);
		  cout<<"D.O.B.(d/m/y) : ";
		  cin>>dob.da;
		  gotoxy(46,2);
		  cout<<'/';
		  cin>>dob.mo;
		  gotoxy(49,2);
		  cout<<'/';
		  cin>>dob.ye;
		  h=z-1;
	       }
	    }
	 }
	else
	 {
	    gotoxy(50,25);
	    cout<<"error in students DOB..";
	    getch();
	    gotoxy(50,25);
	    cout<<"                             ";
	    gotoxy(28,2);
	    cout<<"                                               ";
	    gotoxy(28,2);
	    cout<<"D.O.B.(d/m/y) : ";
	    cin>>dob.da;
	    gotoxy(46,2);
	    cout<<'/';
	    cin>>dob.mo;
	    gotoxy(49,2);
	    cout<<'/';
	    cin>>dob.ye;
	    h=z-1;
	 }
     }
    do
     {
	gotoxy(57,2);
	cout<<"BLOOD GROUP : ";
	gets(blood_g);
     }while((strcmp(blood_g,'\0'))==0);
    for(i=0;blood_g[i]!='\0';i++)
     {
	m1=blood_g[0];
	m2=blood_g[1];
	m3=blood_g[2];
	if(((((m1>=65&&m1<=66)||(m1==79))||(m1>=97&&m1<=98)||(m1==111)) && (m2==43 || m2==45 )) &&(i<2))
	 {}
	else if((((m1==65 & m2==66) || (m1==97&&m2==98)) && (m3==43 || m3==45)) && (i<3))
	 {}
	else
	 {
	    gotoxy(50,25);
	    cout<<"error in students blood group..";
	    getch();
	    gotoxy(50,25);
	    cout<<"                                  ";
	    gotoxy(57,2);
	    cout<<"                                               ";
	    do
	     {
	       gotoxy(57,2);
	       cout<<"BLOOD GROUP : ";
	       cin>>blood_g;
	     }while((strcmp(blood_g,'\0'))==0);
	    i=z-1;
	 }
     }
    do
     {
	gotoxy(1,3);
	cout<<"FATHER'S NAME : ";
	gets(p.f_name);
     }while((strcmp(p.f_name,'\0'))==0);
    for(i=0;p.f_name[i]!='\0';i++)
     {
       m1=p.f_name[i];
       if((m1>=65&&m1<=90)||(m1>=97&&m1<=122))
	{}
       else
	{
	   gotoxy(50,25);
	   cout<<"error in father's name";
	   getch();
	   gotoxy(50,25);
	   cout<<"                             ";
	   gotoxy(1,3);
	   cout<<"                                        ";
	   do
	    {
	       gotoxy(1,3);
	       cout<<"FATHER'S NAME : ";
	       gets(p.f_name);
	    }while((strcmp(p.f_name,'\0'))==0);
	   i=z-1;
	}
     }
    do
     {
       gotoxy(1,4);
       cout<<"OCCUPATION : ";
       gets(p.f_occup);
      }while((strcmp(p.f_occup,'\0'))==0);
     for(i=0;p.f_occup[i]!='\0';i++)
      {
	m1=p.f_occup[i];
	if((m1>=65&&m1<=90)||(m1>=97&&m1<=122))
	 {}
	else
	 {
	   gotoxy(50,25);
	   cout<<"error in father's occupation..";
	   getch();
	   gotoxy(50,25);
	   cout<<"                                 ";
	   gotoxy(1,4);
	   cout<<"                                        ";
	   do
	    {
	      gotoxy(1,4);
	      cout<<"OCCUPATION : ";
	      gets(p.f_occup);
	    }while((strcmp(p.f_occup,'\0'))==0);
	   i=z-1;
	 }
      }
     do
      {
	gotoxy(1,5);
	cout<<"MOBILE : ";
	gets(p.f_mobile);
      }while((strcmp(p.f_mobile,'\0'))==0);
     for(i=0;p.f_mobile[i]!='\0';i++)
      {
	 m1=p.f_mobile[0];
	 m2=p.f_mobile[i];
	 m3=strlen(p.f_mobile);
	 if(((m2>=48)&&(m2<=57))&& m1!=48&&m3==10)
	  {}
	 else
	  {
	     gotoxy(50,25);
	     cout<<"error in fathers number";
	     getch();
	     gotoxy(50,25);
	     cout<<"                                 ";
	     gotoxy(1,5);
	     cout<<"                                        ";
	     do
	      {
		gotoxy(1,5);
		cout<<"MOBILE : ";
		gets(p.f_mobile);
	     }while((strcmp(p.f_mobile,'\0'))==0);
	    i=z-1;
	  }
      }
     do
      {
	gotoxy(30,5);
	cout<<"EMAIL : ";
	gets(p.f_email);
      }while((strcmp(p.f_email,'\0'))==0);
     m4=0;
     for(m5=0;m4==0;m5++)
      {
	m3=0;
	for(i=0;p.f_email[i]!='\0';i++)
	 {
	    m1=p.f_email[i];
	    if(m1==64)
	     {
	       m3++;
	     }
	 }
	if(m3!=1)
	 {
	    gotoxy(50,25);
	    cout<<"error in fathers email";
	    getch();
	    gotoxy(50,25);
	    cout<<"                                 ";
	    gotoxy(30,5);
	    cout<<"                                        ";
	    do
	     {
	       gotoxy(30,5);
	       cout<<"EMAIL : ";
	       gets(p.f_email);
	     }while((strcmp(p.f_email,'\0'))==0);
	 }
	else
	m4=1;
      }
     do
      {
	gotoxy(1,6);
	cout<<"MOTHER'S NAME : ";
	gets(p.m_name);
      }while((strcmp(p.m_name,'\0'))==0);
     for(i=0;p.m_name[i]!='\0';i++)
      {
	 m1=p.m_name[i];
	 if((m1>=65&&m1<=90)||(m1>=97&&m1<=122))
	  {}
	 else
	  {
	     gotoxy(50,25);
	     cout<<"error in mother's name";
	     getch();
	     gotoxy(50,25);
	     cout<<"                             ";
	     gotoxy(1,6);
	     cout<<"                                        ";
	     do
	      {
		 gotoxy(1,6);
		 cout<<"MOTHER'S NAME : ";
		 gets(p.m_name);
	      }while((strcmp(p.m_name,'\0'))==0);
	     i=z-1;
	  }
      }
     do
      {
	gotoxy(1,7);
	cout<<"OCCUPATION : ";
	gets(p.m_occup);
      }while((strcmp(p.m_occup,'\0'))==0);
     for(i=0;p.m_occup[i]!='\0';i++)
      {
	 m1=p.m_occup[i];
	 if((m1>=65&&m1<=90)||(m1>=97&&m1<=122))
	  {}
	 else
	  {
	    gotoxy(50,25);
	    cout<<"error in mother's occupation..";
	    getch();
	    gotoxy(50,25);
	    cout<<"                                 ";
	    gotoxy(1,7);
	    cout<<"                                        ";
	    do
	     {
		gotoxy(1,7);
		cout<<"OCCUPATION : ";
		 gets(p.m_occup);
	     }while((strcmp(p.m_occup,'\0'))==0);
	    i=z-1;
	  }
      }
     do
      {
	gotoxy(1,8);
	cout<<"MOBILE : ";
	gets(p.m_mobile);
      }while((strcmp(p.m_mobile,'\0'))==0);
     for(i=0;p.m_mobile[i]!='\0';i++)
      {
	 m1=p.m_mobile[0];
	 m2=p.m_mobile[i];
	 m3=strlen(p.m_mobile);
	 if(((m2>=48)&&(m2<=57))&& m1!=48&&m3==10)
	  {}
	 else
	  {
	     gotoxy(50,25);
	     cout<<"error in mother's number";
	     getch();
	     gotoxy(50,25);
	     cout<<"                                 ";
	     gotoxy(1,8);
	     cout<<"                                        ";
	     do
	      {
		gotoxy(1,8);
		cout<<"MOBILE : ";
		gets(p.m_mobile);
	      }while((strcmp(p.m_mobile,'\0'))==0);
	     i=z-1;
	  }
      }
     do
      {
	gotoxy(30,8);
	cout<<"EMAIL : ";
	gets(p.m_email);
      }while((strcmp(p.m_email,'\0'))==0);
     m4=0;
     for(m5=0;m4==0;m5++)
      {
	m3=0;
	for(i=0;p.m_email[i]!='\0';i++)
	 {
	   m1=p.m_email[i];
	   if(m1==64)
	    {
	      m3++;
	    }
	 }
	if(m3!=1)
	 {
	    gotoxy(50,25);
	    cout<<"error in mother's email";
	    getch();
	    gotoxy(50,25);
	    cout<<"                                 ";
	    gotoxy(30,8);
	    cout<<"                                        ";
	    do
	     {
		gotoxy(30,8);
		cout<<"EMAIL : ";
		gets(p.m_email);
	     }while((strcmp(p.m_email,'\0'))==0);
	 }
	else
	m4=1;
      }
     do
      {
	gotoxy(1,9);
	cout<<"ADDRESS : ";
	gets(add.c_add);
      }while((strcmp(add.c_add,'\0'))==0);
     do
      {
	gotoxy(1,10);
	cout<<"PINCODE : ";
	gets(add.pin);
      }while((strcmp(add.pin,'\0'))==0);
     for(i=0;add.pin[i]!='\0';i++)
      {
	 m1=add.pin[i];
	 m2=add.pin[0];
	 m3=strlen(add.pin);
	 if((m2!=48)&&(m3==6)&&(m1>=48&&m1<57))
	  {
	  }
	 else
	  {
	      gotoxy(50,25);
	      cout<<"error in pincode";
	      getch();
	      gotoxy(50,25);
	      cout<<"                                 ";
	      gotoxy(1,10);
	      cout<<"                                        ";
	      do
	       {
		  gotoxy(1,10);
		  cout<<"PINCODE : ";
		  gets(add.pin);
	       }while((strcmp(add.pin,'\0'))==0);
	  }
      }
     do
      {
	 gotoxy(1,11);
	 cout<<"TELEPHONE (without code) : ";
	 gets(tele);
      }while((strcmp(tele,'\0'))==0);
     for(i=0;tele[i]!='\0';i++)
      {
	 m1=tele[0];
	 m2=tele[i];
	 m3=strlen(tele);
	 if(((m2>=48)&&(m2<=57))&& m1!=48&&m3==8)
	  {}
	 else
	  {
	     gotoxy(50,25);
	     cout<<"error in telephone number";
	     getch();
	     gotoxy(50,25);
	     cout<<"                          ";
	     gotoxy(1,11);
	     cout<<"                                                ";
	     do
	      {
		gotoxy(1,11);
		cout<<"TELEPHONE (without code) : ";
		gets(p.m_mobile);
	      }while((strcmp(p.m_mobile,'\0'))==0);
	     i=z-1;
	   }
      }
     do
      {
	gotoxy(1,12);
	cout<<"TRANSPORT : ";
	gets(transport);
      }while((strcmp(transport,'\0'))==0);
     for(i=0;transport[i]!='\0';i++)
      {
	m1=transport[i];
	if((m1>=65&&m1<=90)||(m1>=97&&m1<=122))
	 {}
	else
	 {
	    gotoxy(50,25);
	    cout<<"error in students transport";
	    getch();
	    gotoxy(50,25);
	    cout<<"                               ";
	    gotoxy(1,12);
	    cout<<"                                        ";
	    do
	     {
		gotoxy(1,12);
		cout<<"TRANSPORT : ";
		gets(transport);
	     }while((strcmp(transport,'\0'))==0);
	    i=z-1;
	 }
      }
     char s;
     do
      {
	gotoxy(1,13);
	cout<<"Is the child allergic to anything ? (y/n) : ";
	s=getch();
	m.a_opt=s;
	cout<<m.a_opt;
      }while(s==13);
     for(i=0;i<1;i++)
      {
	if(m.a_opt=='y'&& i<1)
	 {
	    gotoxy(1,14);
	    cout<<"Give brief detail : ";
	    gets(m.q_allergic);
	    check=1;
	  }
	 else if(m.a_opt=='n'&& i<1)
	  {}
	 else
	  {
	     gotoxy(50,25);
	     cout<<"error in choice";
	     getch();
	     gotoxy(50,25);
	     cout<<"                               ";
	     gotoxy(1,13);
	     cout<<"                                             ";
	     do
	      {
		 gotoxy(1,13);
		 cout<<"Is the child allergic to anything ? (y/n) : " ;
		 s=getch();
		 m.a_opt=s;
		 cout<<m.a_opt;
	      }while(s==13);
	     i=z-1;
	   }
      }
     do
      {
	if(check==1)
	gotoxy(1,15);
	else
	gotoxy(1,14);
	cout<<"Has the child ever been hospitalized ? (y/n): ";
	s=getch();
	m.h_opt=s;
	cout<<m.h_opt;
      }while(s==13);
     for(i=0;i<1;i++)
      {
	if(m.h_opt=='y')
	 {
	    if(check==1)
	    gotoxy(1,16);
	    else
	    gotoxy(1,15);
	    cout<<"give brief detail : ";
	    gets(m.q_hospital);
	    check1=1;
	 }
	else if(m.h_opt=='n')
	 {}
	 else
	  {
	     gotoxy(50,25);
	     cout<<"error in choice";
	     getch();
	     gotoxy(50,25);
	     cout<<"                               ";
	     if(check==1)
	     gotoxy(1,15);
	     else
	     gotoxy(1,14);
	     cout<<"                                               ";
	     do
	      {
		 if(check==1)
		 gotoxy(1,15);
		  else
		  gotoxy(1,14);
		   cout<<"Has the child ever been hospitalized ? (y/n) :  ";
		   s=getch();
		   m.h_opt=s;
		   cout<<m.h_opt;
	      }while(s==13);
	     i=z-1;
	   }
      }
     do
      {
	if(check==1 && check1==1)
	gotoxy(1,17);
	else if(check==1 && check1==0)
	gotoxy(1,16);
	else
	gotoxy(1,15);
	cout<<"Does the child have a chronic/medical case history ? (y/n) : ";
	s=getch();
	m.his_opt=s;
	cout<<m.his_opt;
      }while(s==13);
     for(i=0;i<1;i++)
      {
	if(m.his_opt=='y')
	 {
	  if(check==1 && check1==1)
	   gotoxy(1,18);
	  else if(check==1 && check1==0)
	   gotoxy(1,17);
	  else
	   gotoxy(1,16);
	  cout<<"Give brief detail : ";
	  cin>>m.q_history;
	  check2=1;
	 }
	else if(m.his_opt=='n'&& i<1)
	 {}
	else
	 {
	  gotoxy(50,25);
	  cout<<"error in choice";
	  getch();
	  gotoxy(50,25);
	  cout<<"                               ";
	  if(check==1 && check1==1)
	   gotoxy(1,17);
	  else if(check==1 && check1==0)
	   gotoxy(1,16);
	  else
	   gotoxy(1,15);
	   cout<<"                                                                  ";
	  do
	   {
	    if(check==1 && check1==1)
	     gotoxy(1,17);
	    else if(check==1 && check1==0)
	     gotoxy(1,16);
	    else
	     gotoxy(1,15);
	    cout<<"Does the child have a chronic/medical case history ?  (y/n) :  ";
	    s=getch();
	    m.his_opt=s;
	    cout<<m.his_opt;
	   }while(s==13);
	  i=z-1;
	 }
      }
     do
      {
       if(check==1 && check1==1 && check2==1)
	gotoxy(1,19);
       else if(check==1 && check1==1 && check2==0)
	gotoxy(1,18);
       else if(check==1 && check1==0 && check2==1)
	gotoxy(1,18);
       else if(check==0 && check1==1 && check2==1)
	gotoxy(1,18);
       else if(check==1 && check1==0 && check2==0)
	gotoxy(1,17);
       else if(check==0 && check1==1 && check2==0)
	gotoxy(1,17);
       else if(check==0 && check1==0 && check2==1)
	gotoxy(1,17);
       else
	gotoxy(1,16);
       cout<<"Name of the doctor : Dr. ";
       gets(m.d_name);
      }while((strcmp(m.d_name,'\0'))==0);
     for(i=0;m.d_name[i]!='\0';i++)
      {
       m1=m.d_name[i];
       if((m1>=65&&m1<=90)||(m1>=97&&m1<=122))
	{}
       else
	{
	 gotoxy(50,25);
	 cout<<"error in doctor's name";
	 getch();
	 gotoxy(50,25);
	 cout<<"                             ";
	 if(check==1 && check1==1 && check2==1)
	  gotoxy(1,19);
	 else if(check==1 && check1==1 && check2==0)
	  gotoxy(1,18);
	 else if(check==1 && check1==0 && check2==1)
	  gotoxy(1,18);
	 else if(check==0 && check1==1 && check2==1)
	  gotoxy(1,18);
	 else if(check==1 && check1==0 && check2==0)
	  gotoxy(1,17);
	 else if(check==0 && check1==1 && check2==0)
	  gotoxy(1,17);
	 else if(check==0 && check1==0 && check2==1)
	  gotoxy(1,17);
	 else
	  gotoxy(1,16);
	 cout<<"                                                  ";
	 do
	  {
	   if(check==1 && check1==1 && check2==1)
	    gotoxy(1,19);
	   else if(check==1 && check1==1 && check2==0)
	    gotoxy(1,18);
	   else if(check==1 && check1==0 && check2==1)
	    gotoxy(1,18);
	   else if(check==0 && check1==1 && check2==1)
	    gotoxy(1,18);
	   else if(check==1 && check1==0 && check2==0)
	    gotoxy(1,17);
	   else if(check==0 && check1==1 && check2==0)
	    gotoxy(1,17);
	   else if(check==0 && check1==0 && check2==1)
	    gotoxy(1,17);
	   else
	    gotoxy(1,16);
	   cout<<"Name of the doctor : Dr. : ";
	   gets(m.d_name);
	  }while((strcmp(m.d_name,'\0'))==0);
	 i=z-1;
	}
      }
      do
       {
	if(check==1 && check1==1 && check2==1)
	 gotoxy(1,20);
	else if(check==1 && check1==1 && check2==0)
	 gotoxy(1,19);
	else if(check==1 && check1==0 && check2==1)
	 gotoxy(1,19);
	else if(check==0 && check1==1 && check2==1)
	 gotoxy(1,19);
	else if(check==1 && check1==0 && check2==0)
	 gotoxy(1,18);
	else if(check==0 && check1==1 && check2==0)
	 gotoxy(1,18);
	else if(check==0 && check1==0 && check2==1)
	 gotoxy(1,18);
	else
	 gotoxy(1,17);
	cout<<"Doctor's contact no. : ";
	gets(m.d_tele);
       }while((strcmp(m.d_tele,'\0'))==0);
      for(i=0;m.d_tele[i]!='\0';i++)
       {
	m1=m.d_tele[0];
	m2=m.d_tele[i];
	m3=strlen(m.d_tele);
	if(((m2>=48)&&(m2<=57))&& (m1!=48)&&(m3==10||m3==8))
	 {}
	else
	 {
	  gotoxy(50,25);
	  cout<<"error in doctor's number";
	  getch();
	  gotoxy(50,25);
	  cout<<"                                 ";
	  if(check==1 && check1==1 && check2==1)
	   gotoxy(1,20);
	  else if(check==1 && check1==1 && check2==0)
	   gotoxy(1,19);
	  else if(check==1 && check1==0 && check2==1)
	   gotoxy(1,19);
	  else if(check==0 && check1==1 && check2==1)
	   gotoxy(1,19);
	  else if(check==1 && check1==0 && check2==0)
	   gotoxy(1,18);
	  else if(check==0 && check1==1 && check2==0)
	   gotoxy(1,18);
	  else if(check==0 && check1==0 && check2==1)
	   gotoxy(1,18);
	  else
	   gotoxy(1,17);
	  cout<<"                                        ";
	  do
	   {
	    if(check==1 && check1==1 && check2==1)
	     gotoxy(1,20);
	    else if(check==1 && check1==1 && check2==0)
	     gotoxy(1,19);
	    else if(check==1 && check1==0 && check2==1)
	     gotoxy(1,19);
	    else if(check==0 && check1==1 && check2==1)
	     gotoxy(1,19);
	    else if(check==1 && check1==0 && check2==0)
	     gotoxy(1,18);
	    else if(check==0 && check1==1 && check2==0)
	     gotoxy(1,18);
	    else if(check==0 && check1==0 && check2==1)
	     gotoxy(1,18);
	    else
	     gotoxy(1,17);
	    cout<<"Doctor's contact no. : ";
	    gets(m.d_tele);
	   }while((strcmp(m.d_tele,'\0'))==0);
	  i=z-1;
	 }
       }
      do
       {
	if(check==1 && check1==1 && check2==1)
	 gotoxy(1,21);
	else if(check==1 && check1==1 && check2==0)
	 gotoxy(1,20);
	else if(check==1 && check1==0 && check2==1)
	 gotoxy(1,20);
	else if(check==0 && check1==1 && check2==1)
	 gotoxy(1,20);
	else if(check==1 && check1==0 && check2==0)
	 gotoxy(1,19);
	else if(check==0 && check1==1 && check2==0)
	 gotoxy(1,19);
	else if(check==0 && check1==0 && check2==1)
	 gotoxy(1,19);
	else
	 gotoxy(1,18);
	cout<<"Is the child under any kind of medication ? (y/n) : ";
	s=getch();
	m.m_opt=s;
	cout<<m.m_opt;
       }while(s==13);
      for(i=0;i<1;i++)
       {
	if(m.m_opt=='y'||m.m_opt=='Y')
	 {
	  if(check==1 && check1==1 && check2==1)
	   gotoxy(1,22);
	  else if(check==1 && check1==1 && check2==0)
	   gotoxy(1,21);
	  else if(check==1 && check1==0 && check2==1)
	   gotoxy(1,21);
	  else if(check==0 && check1==1 && check2==1)
	   gotoxy(1,21);
	  else if(check==1 && check1==0 && check2==0)
	   gotoxy(1,20);
	  else if(check==0 && check1==1 && check2==0)
	   gotoxy(1,20);
	  else if(check==0 && check1==0 && check2==1)
	   gotoxy(1,20);
	  else
	   gotoxy(1,19);
	  cout<<"Name of the medicine (seperated by ,) : ";
	  gets(m.q_medication);
	  if(check==1 && check1==1 && check2==1)
	   gotoxy(1,23);
	  else if(check==1 && check1==1 && check2==0)
	   gotoxy(1,22);
	  else if(check==1 && check1==0 && check2==1)
	   gotoxy(1,22);
	  else if(check==0 && check1==1 && check2==1)
	   gotoxy(1,22);
	  else if(check==1 && check1==0 && check2==0)
	   gotoxy(1,21);
	  else if(check==0 && check1==1 && check2==0)
	   gotoxy(1,21);
	  else if(check==0 && check1==0 && check2==1)
	   gotoxy(1,21);
	  else
	   gotoxy(1,20);
	  cout<<"Dosage prescribed : ";
	  gets(m.dosage);
	  check3=1;
	 }
	else if(m.m_opt=='n'||m.m_opt=='N')
	 {}
	else
	 {
	  gotoxy(50,25);
	  cout<<"error in choice";
	  getch();
	  gotoxy(50,25);
	  cout<<"                                 ";
	  if(check==1 && check1==1 && check2==1)
	   gotoxy(1,21);
	  else if(check==1 && check1==1 && check2==0)
	   gotoxy(1,20);
	  else if(check==1 && check1==0 && check2==1)
	   gotoxy(1,20);
	  else if(check==0 && check1==1 && check2==1)
	   gotoxy(1,20);
	  else if(check==1 && check1==0 && check2==0)
	   gotoxy(1,19);
	  else if(check==0 && check1==1 && check2==0)
	   gotoxy(1,19);
	  else if(check==0 && check1==0 && check2==1)
	   gotoxy(1,19);
	  else
	   gotoxy(1,18);
	  cout<<"                                                        ";
	  do
	   {
	    if(check==1 && check1==1 && check2==1)
	     gotoxy(1,21);
	    else if(check==1 && check1==1 && check2==0)
	     gotoxy(1,20);
	    else if(check==1 && check1==0 && check2==1)
	     gotoxy(1,20);
	    else if(check==0 && check1==1 && check2==1)
	     gotoxy(1,20);
	    else if(check==1 && check1==0 && check2==0)
	     gotoxy(1,19);
	    else if(check==0 && check1==1 && check2==0)
	     gotoxy(1,19);
	    else if(check==0 && check1==0 && check2==1)
	     gotoxy(1,19);
	    else
	     gotoxy(1,18);
	    cout<<"Is the child under any kind of medication ? (y/n) :";
	    cin>>m.m_opt;
	    s=getch();
	    m.m_opt=s;
	    cout<<m.m_opt;
	   }while(s==13);
	  i=z-1;
	 }
       }
      do
       {
	if(check==1 && check1==1 && check2==1 && check3==1)
	 gotoxy(1,24);
	else if(check==1 && check1==1 && check2==1 && check3==0)
	 gotoxy(1,22);
	else if(check==1 && check1==0 && check2==1 && check3==1)
	 gotoxy(1,23);
	else if(check==0 && check1==1 && check2==1 && check3==1)
	 gotoxy(1,23);
	else if(check==1 && check1==1 && check2==0 && check3==1)
	 gotoxy(1,23);
	else if(check==1 && check1==1 && check2==0 && check3==0)
	 gotoxy(1,21);
	else if(check==1 && check1==0 && check2==1 && check3==0)
	 gotoxy(1,21);
	else if(check==1 && check1==0 && check2==0 && check3==1)
	 gotoxy(1,22);
	else if(check==0 && check1==1 && check2==1 && check3==0)
	 gotoxy(1,21);
	else if(check==0 && check1==1 && check2==0 && check3==1)
	 gotoxy(1,22);
	else if(check==0 && check1==0 && check2==1 && check3==1)
	 gotoxy(1,22);
	else if(check==1 && check1==0 && check2==0 && check3==0)
	 gotoxy(1,20);
	else if(check==0 && check1==1 && check2==0 && check3==0)
	 gotoxy(1,20);
	else if(check==0 && check1==0 && check2==1 && check3==0)
	 gotoxy(1,20);
	else if(check==0 && check1==0 && check2==0 && check3==1)
	 gotoxy(1,21);
	else
	 gotoxy(1,19);
	cout<<"Ward to participate in competitive games ? (y/n) : ";
	s=getch();
	m.g_opt=s;
	cout<<m.g_opt;
       }while(s==13);
      while(m.g_opt!='y'&& m.g_opt!='Y'&& m.g_opt!='n'&& m.g_opt!='N')
       {
	gotoxy(50,25);
	cout<<"error in choice";
	getch();
	gotoxy(50,25);
	cout<<"                                 ";
	if(check==1 && check1==1 && check2==1 && check3==1)
	 gotoxy(1,24);
	else if(check==1 && check1==1 && check2==1 && check3==0)
	 gotoxy(1,22);
	else if(check==1 && check1==0 && check2==1 && check3==1)
	 gotoxy(1,23);
	else if(check==0 && check1==1 && check2==1 && check3==1)
	 gotoxy(1,23);
	else if(check==1 && check1==1 && check2==0 && check3==1)
	 gotoxy(1,23);
	else if(check==1 && check1==1 && check2==0 && check3==0)
	 gotoxy(1,21);
	else if(check==1 && check1==0 && check2==1 && check3==0)
	 gotoxy(1,21);
	else if(check==1 && check1==0 && check2==0 && check3==1)
	 gotoxy(1,22);
	else if(check==0 && check1==1 && check2==1 && check3==0)
	 gotoxy(1,21);
	else if(check==0 && check1==1 && check2==0 && check3==1)
	 gotoxy(1,22);
	else if(check==0 && check1==0 && check2==1 && check3==1)
	 gotoxy(1,22);
	else if(check==1 && check1==0 && check2==0 && check3==0)
	 gotoxy(1,20);
	else if(check==0 && check1==1 && check2==0 && check3==0)
	 gotoxy(1,20);
	else if(check==0 && check1==0 && check2==1 && check3==0)
	 gotoxy(1,20);
	else if(check==0 && check1==0 && check2==0 && check3==1)
	 gotoxy(1,21);
	else
	 gotoxy(1,19);
	cout<<"                                                        ";
	do
	 {
	  if(check==1 && check1==1 && check2==1 && check3==1)
	   gotoxy(1,24);
	  else if(check==1 && check1==1 && check2==1 && check3==0)
	   gotoxy(1,22);
	  else if(check==1 && check1==0 && check2==1 && check3==1)
	   gotoxy(1,23);
	  else if(check==0 && check1==1 && check2==1 && check3==1)
	   gotoxy(1,23);
	  else if(check==1 && check1==1 && check2==0 && check3==1)
	   gotoxy(1,23);
	  else if(check==1 && check1==1 && check2==0 && check3==0)
	   gotoxy(1,21);
	  else if(check==1 && check1==0 && check2==1 && check3==0)
	   gotoxy(1,21);
	  else if(check==1 && check1==0 && check2==0 && check3==1)
	   gotoxy(1,22);
	  else if(check==0 && check1==1 && check2==1 && check3==0)
	   gotoxy(1,21);
	  else if(check==0 && check1==1 && check2==0 && check3==1)
	   gotoxy(1,22);
	  else if(check==0 && check1==0 && check2==1 && check3==1)
	   gotoxy(1,22);
	  else if(check==1 && check1==0 && check2==0 && check3==0)
	   gotoxy(1,20);
	  else if(check==0 && check1==1 && check2==0 && check3==0)
	   gotoxy(1,20);
	  else if(check==0 && check1==0 && check2==1 && check3==0)
	   gotoxy(1,20);
	  else if(check==0 && check1==0 && check2==0 && check3==1)
	   gotoxy(1,21);
	  else
	   gotoxy(1,19);
	  cout<<"Ward to participate in competitive games ? (y/n) : ";
	  s=getch();
	  m.g_opt=s;
	  cout<<m.g_opt;
	 }while(s==13);
       }
      if(check==1 && check1==1 && check2==1 && check3==1)
       gotoxy(1,25);
      else if(check==1 && check1==1 && check2==1 && check3==0)
       gotoxy(1,23);
      else if(check==1 && check1==0 && check2==1 && check3==1)
       gotoxy(1,24);
      else if(check==0 && check1==1 && check2==1 && check3==1)
       gotoxy(1,24);
      else if(check==1 && check1==1 && check2==0 && check3==1)
       gotoxy(1,24);
      else if(check==1 && check1==1 && check2==0 && check3==0)
       gotoxy(1,22);
      else if(check==1 && check1==0 && check2==1 && check3==0)
       gotoxy(1,22);
      else if(check==1 && check1==0 && check2==0 && check3==1)
       gotoxy(1,23);
      else if(check==0 && check1==1 && check2==1 && check3==0)
       gotoxy(1,22);
      else if(check==0 && check1==1 && check2==0 && check3==1)
       gotoxy(1,23);
      else if(check==0 && check1==0 && check2==1 && check3==1)
       gotoxy(1,23);
      else if(check==1 && check1==0 && check2==0 && check3==0)
       gotoxy(1,21);
      else if(check==0 && check1==1 && check2==0 && check3==0)
       gotoxy(1,21);
      else if(check==0 && check1==0 && check2==1 && check3==0)
       gotoxy(1,21);
      else if(check==0 && check1==0 && check2==0 && check3==1)
       gotoxy(1,22);
      else
       gotoxy(1,20);
      cout<<"In case of medical emergency involving previous history (choose the option) : ";
      cout<<"\n1.personal physician \n2. School's panel of doctors : ";
      cin>>m.opt_his;
      switch(m.opt_his)
       {
	case 1:break;
	case 2:break;
	default : cout<<"error";
       }
      if(check==1 && check1==1 && check2==1 && check3==1)
       gotoxy(1,28);
      else if(check==1 && check1==1 && check2==1 && check3==0)
       gotoxy(1,26);
      else if(check==1 && check1==0 && check2==1 && check3==1)
       gotoxy(1,27);
      else if(check==0 && check1==1 && check2==1 && check3==1)
       gotoxy(1,27);
      else if(check==1 && check1==1 && check2==0 && check3==1)
       gotoxy(1,27);
      else if(check==1 && check1==1 && check2==0 && check3==0)
       gotoxy(1,25);
      else if(check==1 && check1==0 && check2==1 && check3==0)
       gotoxy(1,25);
      else if(check==1 && check1==0 && check2==0 && check3==1)
       gotoxy(1,26);
      else if(check==0 && check1==1 && check2==1 && check3==0)
       gotoxy(1,25);
      else if(check==0 && check1==1 && check2==0 && check3==1)
       gotoxy(1,26);
      else if(check==0 && check1==0 && check2==1 && check3==1)
       gotoxy(1,26);
      else if(check==1 && check1==0 && check2==0 && check3==0)
       gotoxy(1,24);
      else if(check==0 && check1==1 && check2==0 && check3==0)
       gotoxy(1,24);
      else if(check==0 && check1==0 && check2==1 && check3==0)
       gotoxy(1,24);
      else if(check==0 && check1==0 && check2==0 && check3==1)
       gotoxy(1,25);
      else
       gotoxy(1,23);
      cout<<"In case of medical emergency involving accident (choose the option) : ";
      cout<<"\n1.personal physician \n2. School's panel of doctors  : ";
      cin>>m.opt_acc;
      switch(m.opt_acc)
       {
	case 1:break;
	case 2:break;
	default: cout<<"error";
       }
      if(check==1 && check1==1 && check2==1 && check3==1)
       gotoxy(1,31);
      else if(check==1 && check1==1 && check2==1 && check3==0)
       gotoxy(1,29);
      else if(check==1 && check1==0 && check2==1 && check3==1)
       gotoxy(1,30);
      else if(check==0 && check1==1 && check2==1 && check3==1)
       gotoxy(1,30);
      else if(check==1 && check1==1 && check2==0 && check3==1)
       gotoxy(1,30);
      else if(check==1 && check1==1 && check2==0 && check3==0)
       gotoxy(1,28);
      else if(check==1 && check1==0 && check2==1 && check3==0)
       gotoxy(1,28);
      else if(check==1 && check1==0 && check2==0 && check3==1)
       gotoxy(1,29);
      else if(check==0 && check1==1 && check2==1 && check3==0)
       gotoxy(1,28);
      else if(check==0 && check1==1 && check2==0 && check3==1)
       gotoxy(1,29);
      else if(check==0 && check1==0 && check2==1 && check3==1)
       gotoxy(1,29);
      else if(check==1 && check1==0 && check2==0 && check3==0)
       gotoxy(1,27);
      else if(check==0 && check1==1 && check2==0 && check3==0)
       gotoxy(1,27);
      else if(check==0 && check1==0 && check2==1 && check3==0)
       gotoxy(1,27);
      else if(check==0 && check1==0 && check2==0 && check3==1)
       gotoxy(1,28);
      else
       gotoxy(1,26);
  }


void child::med_form()
 {
  cleardevice();
  fstream student("stu_info.dat",ios::out|ios::binary|ios::app);
  int check=1,check1=0,check2=0,check3=0;
  int m1=0,m3=0,m4=0,m5=0,m6=0,m7=0,m8=0,sum=0;
  char ch1,ch2,s;
  do
   {
    ch2='n';
    cleardevice();
    cd.getdata();
    cout<<"do you want to save it? (y/n) : ";
    do
     {
      s=getch();
      ch1=s;
      cout<<ch1;
     }while(s==13);
    if(ch1=='y'||ch1=='Y')
     {
      student.write((char*)&cd,sizeof(child));
      student.close();
     }
    if(check==1 && check1==1 && check2==1 && check3==1)
     gotoxy(1,32);
    else if(check==1 && check1==1 && check2==1 && check3==0)
     gotoxy(1,30);
    else if(check==1 && check1==0 && check2==1 && check3==1)
     gotoxy(1,31);
    else if(check==0 && check1==1 && check2==1 && check3==1)
     gotoxy(1,31);
    else if(check==1 && check1==1 && check2==0 && check3==1)
     gotoxy(1,31);
    else if(check==1 && check1==1 && check2==0 && check3==0)
     gotoxy(1,29);
    else if(check==1 && check1==0 && check2==1 && check3==0)
     gotoxy(1,29);
    else if(check==1 && check1==0 && check2==0 && check3==1)
     gotoxy(1,30);
    else if(check==0 && check1==1 && check2==1 && check3==0)
     gotoxy(1,29);
    else if(check==0 && check1==1 && check2==0 && check3==1)
     gotoxy(1,30);
    else if(check==0 && check1==0 && check2==1 && check3==1)
     gotoxy(1,30);
    else if(check==1 && check1==0 && check2==0 && check3==0)
     gotoxy(1,28);
    else if(check==0 && check1==1 && check2==0 && check3==0)
     gotoxy(1,28);
    else if(check==0 && check1==0 && check2==1 && check3==0)
     gotoxy(1,28);
    else if(check==0 && check1==0 && check2==0 && check3==1)
     gotoxy(1,29);
    else
     gotoxy(1,27);
    cout<<"\ndo you want to add another form? (y/n) : ";
    s=getch();
    ch2=s;
    cout<<ch2;
    if(ch2=='n'||ch2=='N')
    menu();
   }while(ch2=='y'||ch2=='Y');
 }





//**********************************************************
// FUNCTION TO DISPLAY AND CHECK PASSWORD
//**********************************************************

void password::pass()
 {
  setcolor(15);
  m++;
  char a='a',b,r;
  int i,c,m;
  cleardevice();
//Display screen
  circle(220,120,20);
  circle(280,120,20);
  circle(340,120,20);
  circle(220,180,20);
  circle(280,180,20);
  circle(340,180,20);
  circle(220,245,20);
  circle(280,245,20);
  circle(340,245,20);
  gotoxy(28,8);
  cout<<"1";
  gotoxy(28,12);
  cout<<"4";
  gotoxy(28,16);
  cout<<"7";
  gotoxy(35,8);
  cout<<"2";
  gotoxy(35,12);
  cout<<"5";
  gotoxy(35,16);
  cout<<"8";
  gotoxy(43,8);
  cout<<"3";
  gotoxy(43,12);
  cout<<"6";
  gotoxy(43,16);
  cout<<"9";
  gotoxy(50,12);
  cout<<":::ENTER THE PASSWORD:::";
  gotoxy(55,14);
  cout<<":::MAXIMUM 9:::";
//Password input
  for(i=0;a!=13;i++)
   {
    if(i<=9)
     {
       a=getch();
       m=a;
       str[i]=a;
       if(i==0)
	b=a;
       if(i==1)
	r=a;
       if(i>=2)
	{
	 b=r;
	 r=a;
	}
       switch(m)
	{
	 case 49:setfillstyle(1,1);
		 floodfill(225,125,15);
		 break;
	 case 50:setfillstyle(1,2);
		 floodfill(285,125,15);
		 break;
	 case 51:setfillstyle(1,3);
		 floodfill(345,125,15);
		 break;
	 case 52:setfillstyle(1,4);
		 floodfill(225,185,15);
		 break;
	 case 53:setfillstyle(1,5);
		 floodfill(285,185,15);
		 break;
	 case 54:setfillstyle(1,6);
		 floodfill(345,185,15);
		 break;
	 case 55:setfillstyle(1,12);
		 floodfill(225,250,15);
		 break;
	 case 56:setfillstyle(1,8);
		 floodfill(285,250,15);
		 break;
	 case 57:setfillstyle(1,9);
		 floodfill(345,250,15);
		 break;
	 case 13:break;
	 default:gotoxy(53,20);
		 cout<<"albhabets or 0 used...";
		 gotoxy(55,22);
		 cout<<"access denied";
		 gotoxy(27,24);
		 cout<<"program shutting down";
		 for(int j=0;j<4;j++)
		  {
		   delay(600);
		   cout<<".";
		  }
		 exit(0);
	}
       if(i>0)
	{
	 if((b==49 && a==50)|| (b==50 && a == 49))
	  {
	   setcolor(10);
	   rectangle(240,120,260,125);
	   if(b==49)
	    setfillstyle(2,1);
	   else
	    setfillstyle(2,2);
	   floodfill(245,123,10);
	  }
	 else if((b==49 && a==52)||(b==52 && a==49))
	  {
	   setcolor(10);
	   rectangle(218,140,223,160);
	   if(b==49)
	    setfillstyle(2,1);
	   else
	    setfillstyle(2,4);
	   floodfill(219,145,10);
	  }
	 else if((b==50 && a==51)||(b==51 && a==50))
	  {
	   setcolor(10);
	   rectangle(300,120,320,125);
	   if(b==50)
	    setfillstyle(1,2);
	    else
	     setfillstyle(1,3);
	    floodfill(315,123,10);
	   }
	  else if((b==50 && a==53)||(b==53 && a==50))
	   {
	    setcolor(10);
	    rectangle(278,140,283,160);
	    if(b==50)
	     setfillstyle(2,2);
	    else
	     setfillstyle(2,4);
	    floodfill(279,143,10);
	   }
	  else if((b==51 && a==54)||(b==54 && a==51))
	   {
	    setcolor(10);
	    rectangle(338,140,343,160);
	    if(b==51)
	     setfillstyle(2,3);
	    else
	     setfillstyle(2,6);
	    floodfill(342,143,10);
	   }
	  else if((b==52 && a==53)||(b==53 && a==52))
	   {
	    setcolor(10) ;
	    rectangle(240,180,260,185);
	    if(b==52)
	     setfillstyle(1,4);
	    else
	     setfillstyle(1,5);
	    floodfill(245,183,10);
	   }
	  else if((b==52 && a==55)||(b==55 && a==52))
	   {
	    setcolor(10);
	    rectangle(218,200,223,225);
	    if(b==52)
	     setfillstyle(2,4);
	    else
	     setfillstyle(2,12);
	    floodfill(219,220,10);
	   }
	  else if((b==53 && a==54)||(b==54 && a==53))
	   {
	    setcolor(10);
	    rectangle(300,180,320,185);
	    if(b==53)
	     setfillstyle(2,5);
	    else
	     setfillstyle(2,6);
	    floodfill(310,183,10);
	   }
	  else if((b==53 && a==56)||(b==56 && a==53))
	   {
	    setcolor(10);
	    rectangle(278,200,283,225);
	    if(b==53)
	     setfillstyle(2,5);
	    else
	     setfillstyle(2,8);
	    floodfill(279,220,10);
	   }
	  else if((b==54 && a==57)||(b==57 && a==54))
	   {
	    setcolor(10);
	    rectangle(338,200,343,225);
	    if(b==54)
	     setfillstyle(2,6);
	    else
	     setfillstyle(2,9);
	    floodfill(339,220,10);
	   }
	  else if((b==55 && a==56)||(b==56 && a==55))
	   {
	    setcolor(10);
	    rectangle(240,245,260,250);
	    if(b==55)
	     setfillstyle(2,12);
	    else
	     setfillstyle(2,8);
	    floodfill(245,247,10);
	   }
	  else if((b==56 && a==57)||(b==57 && a==56))
	   {
	    setcolor(10);
	    rectangle(300,245,320,250);
	    if(b==56)
	     setfillstyle(1,8);
	    else
	     setfillstyle(1,9);
	    floodfill(315,247,10);
	   }
	  else if((b==49 && a==53)||(b==53 && a==49))
	   {
	    setcolor(3);
	    line(215,140,268,164);
	    line(224,140,276,161);
	    line(215,140,224,140);
	    line(268,164,276,161);
	    if(b==49)
	     setfillstyle(2,1);
	    else
	     setfillstyle(2,5);
	    floodfill(250,153,3);
	   }
	  else if((b==50 && a==54)||(b==54 && a==50))
	   {
	    setcolor(3);
	    line(275,140,335,161);
	    line(284,140,350,162);
	    line(275,140,284,140);
	    line(335,161,350,162);
	    if(b==50)
	     setfillstyle(2,2);
	    else
	     setfillstyle(2,6);
	    floodfill(291,145,3);
	   }
	  else if((b==50 && a==52)||(b==52 && a==50))
	   {
	    setcolor(9);
	    line(275,140,215,161);
	    line(284,140,230,162);
	    line(275,140,284,140);
	    line(215,161,230,162);
	    if(b==50)
	     setfillstyle(2,2);
	    else
	     setfillstyle(2,4);
	    floodfill(270,145,9);
	   }
	  else if((b==51 && a==53)||(b==53 && a==51))
	   {
	    setcolor(9);
	    line(335,140,275,161);
	    line(347,140,284,161);
	    line(335,140,347,140);
	    line(275,161,284,161);
	    if(b==51)
	     setfillstyle(2,3);
	    else
	     setfillstyle(2,5);
	    floodfill(330,145,9);
	   }
	  else if((b==49 && a==54)||(b==54 && a==49))
	   {
	    setcolor(12);
	    line(212,140,335,161);
	    line(224,138,348,160);
	    line(212,140,224,138);
	    line(335,161,348,160);
	    if(b==49)
	     setfillstyle(2,1);
	    else
	     setfillstyle(2,6);
	    floodfill(227,142,12);
	   }
	  else if((b==51 && a==52)||(b==52 && a==51))
	   {
	    setcolor(11);
	    line(335,140,215,161);
	    line(347,140,228,162);
	    line(335,140,347,140);
	    line(215,161,228,162);
	    if(b==51)
	     setfillstyle(2,3);
	    else
	     setfillstyle(2,4);
	    floodfill(230,160,11);
	   }
	  else if((b==52 && a==56)||(b==56 && a==52))
	   {
	    setcolor(3);
	    line(218,200,278,225);
	    line(228,199,283,224);
	    line(218,200,228,199);
	    line(278,225,283,224);
	    if(b==52)
	     setfillstyle(2,4);
	    else
	     setfillstyle(2,8);
	    floodfill(251,213,3);
	   }
	  else if((b==54 && a==56)||(b==56 && a==54))
	   {
	    setcolor(9);
	    line(330,197,278,224);
	    line(340,200,283,225);
	    line(330,197,340,200);
	    line(278,224,283,225);
	    if(b==54)
	     setfillstyle(2,6);
	    else
	     setfillstyle(2,8);
	    floodfill(308,212,9);
	   }
	  else if((b==53 && a==55)||(b==55 && a==53))
	   {
	    setcolor(9);
	    line(218,224,278,200);
	    line(228,225,285,200);
	    line(218,224,228,225);
	    line(278,200,285,200);
	    if(b==53)
	     setfillstyle(2,6);
	    else
	     setfillstyle(2,12);
	    floodfill(250,212,9);
	   }
	  else if((b==53 && a==57)||(b==57 && a==53))
	   {
	    setcolor(3);
	    line(335,224,278,200);
	    line(347,225,285,200);
	    line(335,224,347,225);
	    line(278,200,285,200);
	    if(b==53)
	     setfillstyle(2,5);
	    else
	     setfillstyle(2,9);
	    floodfill(308,212,3);
	   }
	  else if((b==52 && a==57)||(b==57 && a==52))
	   {
	    setcolor(12);
	    line(335,224,218,200);
	    line(347,225,233,195);
	    line(335,224,347,225);
	    line(218,200,233,195);
	    if(b==52)
	     setfillstyle(2,4);
	    else
	     setfillstyle(2,9);
	    floodfill(300,215,12);
	   }
	  else if((b==54 && a==55)||(b==55 && a==54))
	   {
	    setcolor(11);
	    line(328,195,218,224);
	    line(340,200,223,226);
	    line(328,195,340,200);
	    line(218,224,223,226);
	    if(b==54)
	     setfillstyle(2,6);
	    else
	     setfillstyle(2,12);
	    floodfill(290,210,11);
	   }
	  else if((b==49 && a==51)||(b==51 && a==49))
	   {
	    setcolor(15);
	    arc(280,120,20,160,60);
	    arc(280,120,20,160,51);
	    if(b==49)
	     setfillstyle(2,1);
	    else
	     setfillstyle(2,3);
	    floodfill(290,68,15);
	   }
	  else if((b==49 && a==55)||(b==55 && a==49))
	   {
	    setcolor(15);
	    arc(220,182,108,251,60);
	    arc(220,182,105,253,51);
	    if(b==49)
	     setfillstyle(2,1);
	    else
	     setfillstyle(2,12);
	    floodfill(165,180,15);
	   }
	  else if((b==57 && a==55)||(b==55 && a==57))
	   {
	    setcolor(15);
	    arc(280,245,200,-20,60);
	    arc(280,245,200,-19,51);
	    if(b==57)
	     setfillstyle(2,9);
	    else
	     setfillstyle(2,12);
	    floodfill(280,303,15);
	   }
	  else if((b==51 && a==57)||(b==57 && a==51))
	   {
	    setcolor(15);
	    arc(340,182,-72,72,60);
	    arc(340,182,-73,73,51);
	    if(b==51)
	     setfillstyle(2,3);
	    else
	     setfillstyle(2,9);
	    floodfill(395,182,15);
	   }
	  else if((b==49 && a==56)||(b==56 && a==49))
	   {
	    setcolor(13);
	    line(217,140,279,225);
	    line(224,140,283,224);
	    line(217,140,224,140);
	    line(279,225,283,225);
	    if(b==49)
	     setfillstyle(2,1);
	    else
	     setfillstyle(2,8);
	    floodfill(234,161,13);
	   }
	  else if((b==49 && a==57)||(b==57 && a==49))
	   {
	    setcolor(4);
	    arc(300,160,-58,151,110);
	    arc(300,160,-53,143,100);
	    line(203,108,219,101);
	    line(360,239,360,251);
	    if(b==49)
	     setfillstyle(2,1);
	    else
	     setfillstyle(2,9);
	    floodfill(300,58,4);
	   }
	  else if((b==50 && a==55)||(b==55 && a==50))
	   {
	    setcolor(14);
	    line(275,140,218,224);
	    line(281,140,225,225);
	    line(275,140,281,140);
	    line(218,224,225,225);
	    if(b==50)
	     setfillstyle(2,2);
	    else
	     setfillstyle(2,12);
	    floodfill(237,200,14);
	   }
	  else if((b==50 && a==57)||(b==57 && a==50))
	   {
	    setcolor(14);
	    line(278,140,284,140);
	    line(278,140,335,224);
	    line(284,140,347,225);
	    line(335,224,347,225);
	    if(b==50)
	     setfillstyle(2,2);
	    else
	     setfillstyle(2,9);
	    floodfill(304,170,14);
	   }
	  else if((b==50 && a==56)||(b==56 && a==50))
	   {
	    setcolor(13);
	    arc(238,182,-42,42,80);
	    arc(238,182,-40,40,75);
	    line(308,140,298,130);
	    if(b==50)
	     setfillstyle(2,2);
	    else
	     setfillstyle(2,8);
	    floodfill(300,229,13);
	   }

	}
     }
    else
     {
      gotoxy(50,22);
      cout<<"more then 9";
      break;
     }
   }
  str[i-1]='\0';
  ifstream pass("password.dat",ios::in|ios::binary);
  pass.read(str1,10);
  if(strcmpi(str1,str)==0)
   {
    setcolor(2);
    settextstyle(2,HORIZ_DIR,7);
    outtextxy(195,300,"PASSWORD MATCHED");
    setcolor(15);
    outtextxy(150,350,"DIRECTING YOU TO MAIN SYSTEM");
    delay(100);
    setcolor(2);
    outtextxy(150,350,"DIRECTI");
    delay(100);
    outtextxy(230,350,"NG YO");
    delay(100);
    outtextxy(290,350,"U TO M");
    delay(100);
    outtextxy(362,350,"AIN SYSTEM");
    delay(300);
    setcolor(15);
    pass.close();
    opening();
    menu();
   }
  else
   {
    gotoxy(50,20);
    setcolor(4);
    settextstyle(2,HORIZ_DIR,7);
    outtextxy(195,300,"PASSWORD DON'T MATCH");
    getch();
    pass.close();
    pass_check();
   }
 }






//**********************************************************
// FUNCTION TO CHANGE PASSWORD
//**********************************************************

void password::pass_change()
 {
  check1++;
  setcolor(15);
  char a='a',b,r;
  int i,c,m;
  cleardevice();
//Display screen
  circle(220,120,20);
  circle(280,120,20);
  circle(340,120,20);
  circle(220,180,20);
  circle(280,180,20);
  circle(340,180,20);
  circle(220,245,20);
  circle(280,245,20);
  circle(340,245,20);
  gotoxy(28,8);
  cout<<"1";
  gotoxy(28,12);
  cout<<"4";
  gotoxy(28,16);
  cout<<"7";
  gotoxy(35,8);
  cout<<"2";
  gotoxy(35,12);
  cout<<"5";
  gotoxy(35,16);
  cout<<"8";
  gotoxy(43,8);
  cout<<"3";
  gotoxy(43,12);
  cout<<"6";
  gotoxy(43,16);
  cout<<"9";
  if(tp==1)
   {
    gotoxy(50,12);
    cout<<":::ENTER THE OLD PASSWORD:::";
   }
  gotoxy(55,14);
  cout<<":::MAXIMUM 9:::";
  if(counter==1)
   {
    gotoxy(50,12);
    cout<<"                              ";
    gotoxy(50,12);
    cout<<":::ENTER THE NEW PASSWORD:::";
   }
//Password input
  for(i=0;a!=13;i++)
   {
    if(i<=9)
     {
       a=getch();
       m=a;
       str[i]=a;
       if(i==0)
	b=a;
       if(i==1)
	r=a;
       if(i>=2)
	{
	 b=r;
	 r=a;
	}
       switch(m)
	{
	 case 49:setfillstyle(1,1);
		 floodfill(225,125,15);
		 break;
	 case 50:setfillstyle(1,2);
		 floodfill(285,125,15);
		 break;
	 case 51:setfillstyle(1,3);
		 floodfill(345,125,15);
		 break;
	 case 52:setfillstyle(1,4);
		 floodfill(225,185,15);
		 break;
	 case 53:setfillstyle(1,5);
		 floodfill(285,185,15);
		 break;
	 case 54:setfillstyle(1,6);
		 floodfill(345,185,15);
		 break;
	 case 55:setfillstyle(1,12);
		 floodfill(225,250,15);
		 break;
	 case 56:setfillstyle(1,8);
		 floodfill(285,250,15);
		 break;
	 case 57:setfillstyle(1,9);
		 floodfill(345,250,15);
		 break;
	 case 13:break;
	 default:gotoxy(53,20);
		 cout<<"albhabets or 0 used...";
		 gotoxy(55,22);
		 cout<<"access denied";
		 gotoxy(27,24);
		 cout<<"program shutting down";
		 for(int j=0;j<4;j++)
		  {
		   delay(600);
		   cout<<".";
		  }
		 exit(0);
	}
       if(i>0)
	{
	 if((b==49 && a==50)|| (b==50 && a == 49))
	  {
	   setcolor(10);
	   rectangle(240,120,260,125);
	   if(b==49)
	    setfillstyle(2,1);
	   else
	    setfillstyle(2,2);
	   floodfill(245,123,10);
	  }
	 else if((b==49 && a==52)||(b==52 && a==49))
	  {
	   setcolor(10);
	   rectangle(218,140,223,160);
	   if(b==49)
	    setfillstyle(2,1);
	   else
	    setfillstyle(2,4);
	   floodfill(219,145,10);
	  }
	 else if((b==50 && a==51)||(b==51 && a==50))
	  {
	   setcolor(10);
	   rectangle(300,120,320,125);
	   if(b==50)
	    setfillstyle(1,2);
	    else
	     setfillstyle(1,3);
	    floodfill(315,123,10);
	   }
	  else if((b==50 && a==53)||(b==53 && a==50))
	   {
	    setcolor(10);
	    rectangle(278,140,283,160);
	    if(b==50)
	     setfillstyle(2,2);
	    else
	     setfillstyle(2,4);
	    floodfill(279,143,10);
	   }
	  else if((b==51 && a==54)||(b==54 && a==51))
	   {
	    setcolor(10);
	    rectangle(338,140,343,160);
	    if(b==51)
	     setfillstyle(2,3);
	    else
	     setfillstyle(2,6);
	    floodfill(342,143,10);
	   }
	  else if((b==52 && a==53)||(b==53 && a==52))
	   {
	    setcolor(10) ;
	    rectangle(240,180,260,185);
	    if(b==52)
	     setfillstyle(1,4);
	    else
	     setfillstyle(1,5);
	    floodfill(245,183,10);
	   }
	  else if((b==52 && a==55)||(b==55 && a==52))
	   {
	    setcolor(10);
	    rectangle(218,200,223,225);
	    if(b==52)
	     setfillstyle(2,4);
	    else
	     setfillstyle(2,12);
	    floodfill(219,220,10);
	   }
	  else if((b==53 && a==54)||(b==54 && a==53))
	   {
	    setcolor(10);
	    rectangle(300,180,320,185);
	    if(b==53)
	     setfillstyle(2,5);
	    else
	     setfillstyle(2,6);
	    floodfill(310,183,10);
	   }
	  else if((b==53 && a==56)||(b==56 && a==53))
	   {
	    setcolor(10);
	    rectangle(278,200,283,225);
	    if(b==53)
	     setfillstyle(2,5);
	    else
	     setfillstyle(2,8);
	    floodfill(279,220,10);
	   }
	  else if((b==54 && a==57)||(b==57 && a==54))
	   {
	    setcolor(10);
	    rectangle(338,200,343,225);
	    if(b==54)
	     setfillstyle(2,6);
	    else
	     setfillstyle(2,9);
	    floodfill(339,220,10);
	   }
	  else if((b==55 && a==56)||(b==56 && a==55))
	   {
	    setcolor(10);
	    rectangle(240,245,260,250);
	    if(b==55)
	     setfillstyle(2,12);
	    else
	     setfillstyle(2,8);
	    floodfill(245,247,10);
	   }
	  else if((b==56 && a==57)||(b==57 && a==56))
	   {
	    setcolor(10);
	    rectangle(300,245,320,250);
	    if(b==56)
	     setfillstyle(1,8);
	    else
	     setfillstyle(1,9);
	    floodfill(315,247,10);
	   }
	  else if((b==49 && a==53)||(b==53 && a==49))
	   {
	    setcolor(3);
	    line(215,140,268,164);
	    line(224,140,276,161);
	    line(215,140,224,140);
	    line(268,164,276,161);
	    if(b==49)
	     setfillstyle(2,1);
	    else
	     setfillstyle(2,5);
	    floodfill(250,153,3);
	   }
	  else if((b==50 && a==54)||(b==54 && a==50))
	   {
	    setcolor(3);
	    line(275,140,335,161);
	    line(284,140,350,162);
	    line(275,140,284,140);
	    line(335,161,350,162);
	    if(b==50)
	     setfillstyle(2,2);
	    else
	     setfillstyle(2,6);
	    floodfill(291,145,3);
	   }
	  else if((b==50 && a==52)||(b==52 && a==50))
	   {
	    setcolor(9);
	    line(275,140,215,161);
	    line(284,140,230,162);
	    line(275,140,284,140);
	    line(215,161,230,162);
	    if(b==50)
	     setfillstyle(2,2);
	    else
	     setfillstyle(2,4);
	    floodfill(270,145,9);
	   }
	  else if((b==51 && a==53)||(b==53 && a==51))
	   {
	    setcolor(9);
	    line(335,140,275,161);
	    line(347,140,284,161);
	    line(335,140,347,140);
	    line(275,161,284,161);
	    if(b==51)
	     setfillstyle(2,3);
	    else
	     setfillstyle(2,5);
	    floodfill(330,145,9);
	   }
	  else if((b==49 && a==54)||(b==54 && a==49))
	   {
	    setcolor(12);
	    line(212,140,335,161);
	    line(224,138,348,160);
	    line(212,140,224,138);
	    line(335,161,348,160);
	    if(b==49)
	     setfillstyle(2,1);
	    else
	     setfillstyle(2,6);
	    floodfill(227,142,12);
	   }
	  else if((b==51 && a==52)||(b==52 && a==51))
	   {
	    setcolor(11);
	    line(335,140,215,161);
	    line(347,140,228,162);
	    line(335,140,347,140);
	    line(215,161,228,162);
	    if(b==51)
	     setfillstyle(2,3);
	    else
	     setfillstyle(2,4);
	    floodfill(230,160,11);
	   }
	  else if((b==52 && a==56)||(b==56 && a==52))
	   {
	    setcolor(3);
	    line(218,200,278,225);
	    line(228,199,283,224);
	    line(218,200,228,199);
	    line(278,225,283,224);
	    if(b==52)
	     setfillstyle(2,4);
	    else
	     setfillstyle(2,8);
	    floodfill(251,213,3);
	   }
	  else if((b==54 && a==56)||(b==56 && a==54))
	   {
	    setcolor(9);
	    line(330,197,278,224);
	    line(340,200,283,225);
	    line(330,197,340,200);
	    line(278,224,283,225);
	    if(b==54)
	     setfillstyle(2,6);
	    else
	     setfillstyle(2,8);
	    floodfill(308,212,9);
	   }
	  else if((b==53 && a==55)||(b==55 && a==53))
	   {
	    setcolor(9);
	    line(218,224,278,200);
	    line(228,225,285,200);
	    line(218,224,228,225);
	    line(278,200,285,200);
	    if(b==53)
	     setfillstyle(2,6);
	    else
	     setfillstyle(2,12);
	    floodfill(250,212,9);
	   }
	  else if((b==53 && a==57)||(b==57 && a==53))
	   {
	    setcolor(3);
	    line(335,224,278,200);
	    line(347,225,285,200);
	    line(335,224,347,225);
	    line(278,200,285,200);
	    if(b==53)
	     setfillstyle(2,5);
	    else
	     setfillstyle(2,9);
	    floodfill(308,212,3);
	   }
	  else if((b==52 && a==57)||(b==57 && a==52))
	   {
	    setcolor(12);
	    line(335,224,218,200);
	    line(347,225,233,195);
	    line(335,224,347,225);
	    line(218,200,233,195);
	    if(b==52)
	     setfillstyle(2,4);
	    else
	     setfillstyle(2,9);
	    floodfill(300,215,12);
	   }
	  else if((b==54 && a==55)||(b==55 && a==54))
	   {
	    setcolor(11);
	    line(328,195,218,224);
	    line(340,200,223,226);
	    line(328,195,340,200);
	    line(218,224,223,226);
	    if(b==54)
	     setfillstyle(2,6);
	    else
	     setfillstyle(2,12);
	    floodfill(290,210,11);
	   }
	  else if((b==49 && a==51)||(b==51 && a==49))
	   {
	    setcolor(15);
	    arc(280,120,20,160,60);
	    arc(280,120,20,160,51);
	    if(b==49)
	     setfillstyle(2,1);
	    else
	     setfillstyle(2,3);
	    floodfill(290,68,15);
	   }
	  else if((b==49 && a==55)||(b==55 && a==49))
	   {
	    setcolor(15);
	    arc(220,182,108,251,60);
	    arc(220,182,105,253,51);
	    if(b==49)
	     setfillstyle(2,1);
	    else
	     setfillstyle(2,12);
	    floodfill(165,180,15);
	   }
	  else if((b==57 && a==55)||(b==55 && a==57))
	   {
	    setcolor(15);
	    arc(280,245,200,-20,60);
	    arc(280,245,200,-19,51);
	    if(b==57)
	     setfillstyle(2,9);
	    else
	     setfillstyle(2,12);
	    floodfill(280,303,15);
	   }
	  else if((b==51 && a==57)||(b==57 && a==51))
	   {
	    setcolor(15);
	    arc(340,182,-72,72,60);
	    arc(340,182,-73,73,51);
	    if(b==51)
	     setfillstyle(2,3);
	    else
	     setfillstyle(2,9);
	    floodfill(395,182,15);
	   }
	  else if((b==49 && a==56)||(b==56 && a==49))
	   {
	    setcolor(13);
	    line(217,140,279,225);
	    line(224,140,283,224);
	    line(217,140,224,140);
	    line(279,225,283,225);
	    if(b==49)
	     setfillstyle(2,1);
	    else
	     setfillstyle(2,8);
	    floodfill(234,161,13);
	   }
	  else if((b==49 && a==57)||(b==57 && a==49))
	   {
	    setcolor(4);
	    arc(300,160,-58,151,110);
	    arc(300,160,-53,143,100);
	    line(203,108,219,101);
	    line(360,239,360,251);
	    if(b==49)
	     setfillstyle(2,1);
	    else
	     setfillstyle(2,9);
	    floodfill(300,58,4);
	   }
	  else if((b==50 && a==55)||(b==55 && a==50))
	   {
	    setcolor(14);
	    line(275,140,218,224);
	    line(281,140,225,225);
	    line(275,140,281,140);
	    line(218,224,225,225);
	    if(b==50)
	     setfillstyle(2,2);
	    else
	     setfillstyle(2,12);
	    floodfill(237,200,14);
	   }
	  else if((b==50 && a==57)||(b==57 && a==50))
	   {
	    setcolor(14);
	    line(278,140,284,140);
	    line(278,140,335,224);
	    line(284,140,347,225);
	    line(335,224,347,225);
	    if(b==50)
	     setfillstyle(2,2);
	    else
	     setfillstyle(2,9);
	    floodfill(304,170,14);
	   }
	  else if((b==50 && a==56)||(b==56 && a==50))
	   {
	    setcolor(13);
	    arc(238,182,-42,42,80);
	    arc(238,182,-40,40,75);
	    line(308,140,298,130);
	    if(b==50)
	     setfillstyle(2,2);
	    else
	     setfillstyle(2,8);
	    floodfill(300,229,13);
	   }

	}
     }
    else
     {
      setcolor(4);
      settextstyle(2,HORIZ_DIR,7);
      outtextxy(195,300,"PASSWORD DOESN'T MATCH");
      gotoxy(50,22);
      cout<<"more then 9";
      getch();
      break;
     }
   }
  str[i-1]='\0';
  if(counter==0&&check1<=4)
   {
    ifstream pass("password.dat",ios::in|ios::binary);
    pass.read(str1,10);
    if(strcmpi(str1,str)==0)
     {
      gotoxy(50,20);
      counter=1;
      pass.close();
      setcolor(2);
      settextstyle(2,HORIZ_DIR,7);
      outtextxy(300,300,"PASSWORD MATCHED");
      outtextxy(300,350,"CONNECTING TO NEW PASSWORD LANE");
      delay(1800);
      setcolor(15);
      settextstyle(GOTHIC_FONT, HORIZ_DIR, 5);
      pass_change();

     }
    else
     {
      setcolor(4);
      settextstyle(2,HORIZ_DIR,7);
      outtextxy(195,300,"PASSWORD DON'T MATCH");
      getch();
      pass.close();
      if(check1==4)
       {
	cout<<"maximum tries exceeded"<<endl;
	getch();
	exit(0);
       }
      pass_change();
     }
   }
  else if(counter==1)
   {
    ofstream pas("password.dat",ios::out|ios::binary);
    strcpy(str1,str);
    pas.write(str1,10);
    pas.close();
    counter=0;
    menu();
   }
  else
  exit(0);
 }

//**********************************************************
// FUNCTION FOR LOADING
//**********************************************************

void load()
 {
  setcolor(4);
  outtextxy(190,400,"CAUTION:Don't Press Any Key ");
  setcolor(15);
  /////M//////
  rectangle(20,150,35,320);
  line(40,150,40,170);
  line(40,150,80,200);
  line(40,170,80,220);
  line(115,170,80,220);
  line(115,150,80,200);
  line(115,150,115,170);
  rectangle(120,150,135,320);
  ////// E ////
  rectangle(155,150,170,320);
  rectangle(175,150,230,165);
  rectangle(175,225,210,240);
  rectangle(175,305,230,320);
  ///// D //////
  rectangle(250,150,265,320);
  line(270,150,270,170);
  line(270,150,325,232);
  line(270,170,310,232);
  line(270,320,325,232);
  line(270,300,310,232);
  line(270,300,270,320);
  ////// I/////
  rectangle(340,150,355,320);
  ///// C ////
  rectangle(375,150,390,320);
  rectangle(395,150,450,165);
  rectangle(395,305,450,320);
  ///// A /////
  line(465,320,485,150);
  line(485,150,515,320);
  line(465,320,475,320);
  line(475,320,486,200);
  line(486,200,505,320);
  line(515,320,505,320);
  rectangle(483,255,492,265);
  ////// L /////
  rectangle(530,150,545,320);
  rectangle(550,300,600,320);
  //////M//////
  delay(120);
  setfillstyle(2,2);
  floodfill(22,160,15);
  delay(120);
  floodfill(42,160,15);
  delay(120);
  floodfill(122,155,15);
  delay(120);
  //////E/////
  setfillstyle(3,3);
  floodfill(157,160,15);
  delay(120);
  floodfill(176,152,15);
  delay(120);
  floodfill(176,226,15);
  delay(120);
  floodfill(176,306,15);
  delay(120);
  /////D/////
  setfillstyle(4,4);
  floodfill(251,160,15);
  delay(120);
  floodfill(305,220,15);
  delay(120);
  /////I/////
  setfillstyle(5,5);
  floodfill(344,155,15);
  delay(120);
  /////C/////
  setfillstyle(6,6);
  floodfill(376,155,15);
  delay(120);
  floodfill(396,155,15);
  delay(120);
  floodfill(396,306,15);
  delay(120);
  /////A/////
  setfillstyle(7,7);
  floodfill(480,230,15);
  delay(120);
  floodfill(484,256,15);
  delay(120);
  /////L/////
  setfillstyle(8,8);
  floodfill(535,160,15);
  delay(120);
  floodfill(555,310,15);
  delay(1000);
 }

//**********************************************************
// FUNCTION TO CONTROL THE OPENING PAGE
//**********************************************************

void opening()
 {
  int errorcode;
  int style, midx, midy,u=0;
  int i=1;
  fg=1;
  setcolor(15);
  settextstyle(2,HORIZ_DIR,5);
  midx = getmaxx() / 2;
  midy = getmaxy() / 2;
  setfillstyle(1,8);
  bar3d(0, 0, 650, 480, 0, 0);
  outtextxy(350,440, "Press Any Key To Continue  >>>>>");
  int j=90,k=150,l=550,m=320;
  while (!kbhit())
   {
    setcolor(15);
    if (i > 15)
     i=1;
    if (j <=0 )
     {
      j=90;
      k=150;
      l=550;
      m=320;
     }
    // select the fill style
    setfillstyle(0,i);
    // fill a bar
    bar3d(j,k, l, m, i, i);
    settextjustify(CENTER_TEXT, CENTER_TEXT);
    settextstyle(GOTHIC_FONT, HORIZ_DIR, 4);
    setcolor(u);
    outtextxy(midx, midy, "MEDICAL RECORDS");
    u++;
    style++;
    i++;
    j-=10;
    k-=10;
    l+=10;
    m+=10;
    delay(200);
   }
 }

//**********************************************************
// FUNCTION TO LIMIT PASSWORD ATTEMPTS
//**********************************************************

void pass_check()
 {
  if(m<=3)
   {
    cleardevice();
    pass.pass();
   }
  else
   {
    setcolor(4);
    outtextxy(150,400,"More Than Three Tries");
    outtextxy(150,430,"Program Shutting Down");
    for(int j=0;j<4;j++)
     {
      delay(600);
      outtextxy(400+(8*j),430,".");
     }
    delay(300);
    exit(0);
   }
 }
//**********************************************************
// FUNCTION TO MANAGE FORM
//**********************************************************

void child_options()
 {
  setcolor(10);
  rectangle(60,50,601,200); //1
  rectangle(59,49,602,199);
  rectangle(58,48,603,198);
  rectangle(57,47,604,197);
  rectangle(56,46,605,196);
  setfillstyle(1,6);
  floodfill(65,65,10);
  setcolor(15);
  outtextxy(310,100,"1.View Record");
  outtextxy(310,115,"2.Delete Record");
  outtextxy(310,130,"3.Modify Record");
  outtextxy(310,145,"4.Return to Form Options");
  char fr;
  int w;
  fr=getch();
  w=fr;
  switch(w)
   {
    case 49:fg=1;
	    cd.show_form();
	    break;
    case 50:fg=1;
	    cd.delete_record();
	    break;
    case 51:fg=1;
	    md();
	    break;
    case 52:menu();
	    break;
    default:setcolor(10);
	    rectangle(60,50,601,200); //1
	    rectangle(59,49,602,199);
	    rectangle(58,48,603,198);
	    rectangle(57,47,604,197);
	    rectangle(56,46,605,196);
	    setfillstyle(1,4);
	    floodfill(65,65,10);
	    setcolor(15);
	    outtextxy(310,110,"Error In Choice");
	    outtextxy(310,130,"Please Try Again");
	    getch();
	    menu();
   }
 }
//**********************************************************
// FUNCTION TO CHECK THE ADMISSION NUMBER OF THE CHILD
//**********************************************************

void child::check_admin()
 {
  char tmp[5];
  setcolor(15);
  setfillstyle(1,0);
  floodfill(65,65,10);
  setcolor(15);
  outtextxy(330,120,"Enter Your Admission Number:");
  gotoxy(56,8);
  gets(tmp);
  strcpy(::temp,tmp);
  for(int i=1;i<6;i++)
   {
    setcolor(i);
    outtextxy(360,150,"PROCESSING");
    delay(300);
   }
  setcolor(15);
  int flag=0;
  ifstream file("stu_info.dat",ios::in|ios::binary);
  file.seekg(0);
  while(file.read((char*)&cd,sizeof(cd)))
   {
    if(strcmpi(cd.admiss,tmp)==0)
     flag=1;
    else
     continue;
   }
  file.close();
  if(flag==0)
   {
    fg=1;
    cleardevice();
    rectangle(80,150,600,300);
    settextstyle(1,0,4);
    setcolor(4);
    outtextxy(350,225,"Record Not Found");
    i=0;
    while(!kbhit())
     {
      setcolor(i);
      rectangle(80,150,600,300);
      setcolor(i+1);
      rectangle(90,160,590,290);
      setcolor(i+2);
      rectangle(100,170,580,280);
      setcolor(i+3);
      rectangle(110,180,570,270);
      delay(150);
      i++;
      if(i>10)
       i=1;
     }
    menu();
    setcolor(15);
   }
  else
   child_options();
  setcolor(15);
  menu();
 }
//**********************************************************
// FUNCTION TO DISPLAY MAIN MENU & CONTROL ALL THE FUNCTION
// IN THE MAIN MENU.
//**********************************************************

void menu()
 {
  setcolor(15);
  cleardevice();
  char ch1,choice,ch,a='a',c,b='a';
  int c1;
  do
   {
    choice='y';
    cleardevice();
    setcolor(15);
    settextstyle(GOTHIC_FONT, HORIZ_DIR, 5);
    outtextxy(300,20,"Form Options");
    rectangle(60,50,601,200); //1
    rectangle(59,49,602,199);
    rectangle(58,48,603,198);
    rectangle(57,47,604,197);
    rectangle(56,46,605,196);
    rectangle(400,250,611,460); //2
    rectangle(399,249,612,459);
    rectangle(398,248,613,458);
    rectangle(397,247,614,457);
    rectangle(396,246,615,456);
    circle(170,350,110);  //3
    circle(170,350,111);
    circle(170,350,112);
    circle(170,350,113);
    circle(170,350,114);
    rectangle(550,150,600,200);
    outtextxy(580,170,"1");
    rectangle(560,410,610,460);
    outtextxy(590,430,"3");
    arc(175,450,3,-180,40);
    outtextxy(180,430,"2");
    settextstyle(GOTHIC_FONT, HORIZ_DIR,4);
    outtextxy(310,120,"Record Action");
    settextstyle(GOTHIC_FONT, HORIZ_DIR,4);
    outtextxy(174,325,"Change");
    outtextxy(175,365,"Password");
    settextstyle(GOTHIC_FONT, HORIZ_DIR,4);
    outtextxy(500,360,"Exit");
    if(fg==1)
     {
      b=getch();
      fg=0;
     }
    else
     {
      a=getch();
      ch=a;
      settextstyle(DEFAULT_FONT, HORIZ_DIR,1);
      switch(ch)
       {
	case 49:setcolor(10);
		rectangle(60,50,601,200); //1
		rectangle(59,49,602,199);
		rectangle(58,48,603,198);
		rectangle(57,47,604,197);
		rectangle(56,46,605,196);
		setfillstyle(1,1);
		floodfill(65,65,10);
		setcolor(15);
		outtextxy(310,100,"1.Add Records");
		outtextxy(310,120,"2.Child options");
		outtextxy(310,140,"3.Return to Form Options");
		c=getch();
		c1=c;
		switch(c1)
		 {
		  case 49:setcolor(10);
			  rectangle(60,50,601,200); //1
			  rectangle(59,49,602,199);
			  rectangle(58,48,603,198);
			  rectangle(57,47,604,197);
			  rectangle(56,46,605,196);
			  setfillstyle(1,2);
			  floodfill(65,65,10);
			  setcolor(15);
			  outtextxy(310,110,"1.Add Multiple Records");
			  outtextxy(310,130,"2.Add Single Record");
			  char q;
			  int f;
			  q=getch();
			  f=q;
			  switch(f)
			   {
			    case 49:setcolor(10);
				    rectangle(60,50,601,200); //1
				    rectangle(59,49,602,199);
				    rectangle(58,48,603,198);
				    rectangle(57,47,604,197);
				    rectangle(56,46,605,196);
				    setfillstyle(1,0);
				    floodfill(65,65,10);
				    setcolor(15);
				    outtextxy(330,120,"  Number of Records:");
				    int n;
				    gotoxy(52,8);
				    cin>>n;
				    for(int i=1;i<10;i++)
				     {
				      setcolor(i);
				      outtextxy(330,150,"PROCESSING");
				      delay(200);
				     }
				    for(i=0;i<n;i++)
				     cd.med_form();
				    break;

			    case 50:for(i=1;i<10;i++)
				     {
				      setcolor(i);
				      outtextxy(330,160,"PROCESSING");
				      delay(200);
				     }
				    setcolor(15);
				    cd.med_form();
				    break;
			    default:setcolor(10);
				    rectangle(60,50,601,200); //1
				    rectangle(59,49,602,199);
				    rectangle(58,48,603,198);
				    rectangle(57,47,604,197);
				    rectangle(56,46,605,196);
				    setfillstyle(1,4);
				    floodfill(65,65,10);
				    setcolor(15);
				    outtextxy(310,110,"Error In Choice");
				    outtextxy(310,130,"Please Try Again");
				    getch();
				    menu();
			   }
			  break;
		  case 50:cd.check_admin();
			  break;
		  case 51:menu();
			  break;
		  default:setcolor(10);
			  rectangle(60,50,601,200); //1
			  rectangle(59,49,602,199);
			  rectangle(58,48,603,198);
			  rectangle(57,47,604,197);
			  rectangle(56,46,605,196);
			  setfillstyle(1,4);
			  floodfill(65,65,10);
			  setcolor(15);
			  outtextxy(310,110,"Error In Choice");
			  outtextxy(310,130,"Please Try Again");
			  getch();
			  menu();
		 }
		break;
	case 50:tp=1;
		setcolor(4);
		circle(170,350,110);  //2
		circle(170,350,111);
		circle(170,350,112);
		circle(170,350,113);
		circle(170,350,114);
		setfillstyle(1,1);
		floodfill(175,355,4);
		for(int i=1;i<10;i++)
		 {
		  setcolor(i);
		  outtextxy(172,345,"PROCESSING");
		  delay(250);
		 }
		setcolor(15);
		pass.pass_change();
		break;
	case 51:setcolor(12);
		rectangle(400,250,611,460); //3
		rectangle(399,249,612,459);
		rectangle(398,248,613,458);
		rectangle(397,247,614,457);
		rectangle(396,246,615,456);
		setfillstyle(1,1);
		floodfill(465,365,12);
		setcolor(15);
		outtextxy(500,360,"Want to quit?(y/n) : ");
		gotoxy(50,22);
		ch1=getch();
		if(ch1=='y'||ch1=='Y')
		 exit(0);
		else if(ch1=='n'|| ch1=='N')
		 menu;
		else
		 {
		  setcolor(12);
		  rectangle(400,250,611,460); //3
		  rectangle(399,249,612,459);
		  rectangle(398,248,613,458);
		  rectangle(397,247,614,457);
		  rectangle(396,246,615,456);
		  setfillstyle(1,4);
		  floodfill(465,365,12);
		  setcolor(15);
		  outtextxy(500,360,"Error In Choice");
		  getch();
		 }
		break;
	default:gotoxy(31,15);
		cout<<"Error in choice"<<endl;
		gotoxy(31,16);
		cout<<"Please try again...";
		getch();
		cleardevice();
		menu();
       }
     }
   }while(choice=='y'||choice=='Y');
 }














//**********************************************************
// MAIN FUNCTION CALLING MAIN MENU & OTHER FUNCTIONS
//**********************************************************
void main()
 {
  clrscr();
  int driver,mode;
  driver=DETECT;
  initgraph(&driver,&mode,"");
  load();
  pass_check();
  menu();
  getch(); 
}























































































































