//OPENING      PASSWORD :- '1234'
//DATA OPENING PASSWORD :- '1234'
//EDITNG DATA  PASSWORD :- '9539'
//VOTING START PASSWORD :- '1452'
//MAEK SURE CAP IS OFF

//ALL HEADER FILES
	#include<iostream.h>
	#include<conio.h>
	#include<dos.h>
	#include<string.h>
	#include<stdio.h>
	#include<process.h>
	#include<stdlib.h>
	#include<fstream.h>

//FUNCTIONS PROTOTYPE
//FUNCTION FOR PREFERANCE
	void skin();
	void drawbox();
// BOX WITH QUOTES
	void drawboxX();
	void main_menu();
	void help();
	int pass();
	
//FUCNTION IS FOR ENTRY , MODIFICATION & VIEWING OF  DATA (CANDIDATE / VOTERS ) 
	void data()
	{
		char key;
		int ch=1 , x=11 , menu_item=0;
		while(ch==1)
		{
			gotoxy(25, 7);cout<<"���������������������ͻ";
			gotoxy(25, 8);cout<<"�     EDIT MENU     �";
			gotoxy(25, 9);cout<<"���������������������͹";
			gotoxy(25,10);cout<<"�  �                  �";
			gotoxy(25,11);cout<<"�";gotoxy(28,11);cout<<"�   CANDIDATE DATA �";
			gotoxy(25,12);cout<<"�";gotoxy(28,12);cout<<"�   VOTERS DATA    �";
			gotoxy(25,13);cout<<"�";gotoxy(28,13);cout<<"�   VOTERS LIST    �";
			gotoxy(25,14);cout<<"�";gotoxy(28,14);cout<<"�   CANDIDATE LIST �";
			gotoxy(25,15);cout<<"�";gotoxy(28,15);cout<<"�   BACK           �";
			gotoxy(25,16);cout<<"���������������������͹";
			gotoxy(25,17);cout<<"� Use'W','S' & 'ENTER'�";
			gotoxy(25,18);cout<<"���������������������ͼ";

			key = getch();
			if(key=='s' && x!=15)
			{
				gotoxy(27,x); cout<<" ";
				x++;
				gotoxy(27,x); cout<<"";
				menu_item++;
				continue;
			}
			else if(key=='w' && x!=11)
			{
				gotoxy(27,x); cout<<" ";
				x--;
				gotoxy(27,x); cout<<"";
				menu_item--;
				continue;
			}
			else if (key==13)
			{
				switch(menu_item)
				{
					case 0:
					{

					}
					case 1:
					{

					}
					case 2:
					{



					}
					case 3:
					{

					}
					case 4:
					{
						clrscr();
						drawboxX();
						main_menu();
						break;
					}

				}
			}

		}
	}
//FUCTION CONTAIN :- NAVIGATION HELP , DETAIL SABOUT THE SOFWARE ,BASIC INSTRUTION
	void help()
	{
		clrscr();
		drawbox();
		char key;
		int ch=1 , x=11 , menu_item=0;
		while(ch==1)
		{

			gotoxy(25, 7);cout<<"���������������������ͻ";
			gotoxy(25, 8);cout<<"�     GET HELP      �";
			gotoxy(25, 9);cout<<"���������������������͹";
			gotoxy(25,10);cout<<"�  �                  �";
			gotoxy(25,11);cout<<"�";gotoxy(28,11);cout<<"�    NAVIGATION    �";
			gotoxy(25,12);cout<<"�";gotoxy(28,12);cout<<"�    BASICS        �";
			gotoxy(25,13);cout<<"�";gotoxy(28,13);cout<<"�    ABOUT         �";
			gotoxy(25,14);cout<<"�";gotoxy(28,14);cout<<"�    BACK          �";
			gotoxy(25,15);cout<<"�";gotoxy(28,15);cout<<"�    EXIT          �";
			gotoxy(25,16);cout<<"���������������������͹";
			gotoxy(25,17);cout<<"� Use'W','S' & 'ENTER'�";
			gotoxy(25,18);cout<<"���������������������ͼ";
			key = getch();
			if(key=='s' && x!=15)
			{
				gotoxy(27,x); cout<<" ";
				x++;
				gotoxy(27,x); cout<<"";
				menu_item++;
				continue;
			}
			else if(key=='w' && x!=11)
			{
				gotoxy(27,x); cout<<" ";
				x--;
				gotoxy(27,x); cout<<"";
				menu_item--;
				continue;
			}
			else if (key==13)
			{

				switch(menu_item)
				{
					case 0:
					{
						clrscr();
						drawbox();
						gotoxy(6,8);delay(2000); cout<<"���������������������������������������Ŀ";
						gotoxy(6,9);delay(500);  cout<<"�       NAVIGATION INSTRUCTIONS         �";
						gotoxy(6,10);             cout<<"���������������������������������������Ĵ";
						gotoxy(6,11); delay(500); cout<<"� USE 'W' FOR UPWARD MOVEMENT           �";
						gotoxy(6,12);delay(500); cout<<"� USE 'S' FOR DOWNWARD MOVEMENT         �";
						gotoxy(6,13);delay(500); cout<<"� USE 'ENTER' BUTTON FO ENTER FUNCTION  �";
						gotoxy(6,14);delay(500); cout<<"�����������������������������������������";
						gotoxy(6,15);delay(1000); cout<<"PLEASE PRESS ENTER to go back or ESCAPE to exit ";
						char ch;
						for(;;)
						{
							ch=getch();
							if(ch==13)
							{clrscr();
							drawboxX();
							help();
							break;}
							else if(ch==27)
							exit(1);
							else
							cout<<"! WRONG KEY ENTERED !";
						}
						break;
				}
					case 1:
					{
						clrscr();
						drawbox();
						gotoxy(4,6);
						delay(2000);cout<<"ELECTION VOTING SOFTWARE ";
						gotoxy(4,7);    cout<<"�������������������������";
						gotoxy(4,8);delay(500);cout<<"DESCRIPTION : IN THIS PROJECT , A PREDETERMINED SET OF \n";
						gotoxy(4,9);delay(500);cout<<"VOTERS WILL BE ABLE TO CAST THE VOTE .VOTERS WILL HAVE \n";
						gotoxy(4,10);delay(500);cout<<"TO PROVE THEIR IDENTITY BY GIVING THEIR IDENTIFICATION \n";
						gotoxy(4,11);delay(500);cout<<"NO. A AUTHENTICATED USER WILL BE ABLE TO CAST THE VOTE.\n";
						gotoxy(4,12);delay(500);cout<<"A USER WHO HAS CASTED THE VOTE CANNOT CAST AGAIN.AFTER \n";
						gotoxy(4,13);delay(500);cout<<"VOTING HAS FINISHED RESUTS WILL BE DECLAIR. A SETUP \n";
						gotoxy(4,14);delay(500);cout<<"OPTION BEFORE ELECTION STARTS , WILL ALLOW VOTER TO BE \n";
						gotoxy(4,15);delay(500);cout<<"CREATED AND CANDIDATE CHOOSEN. \n";
						gotoxy(4,18);delay(1500);cout<<"PLEASE Press ENTER to continue or ESCAPE to exit \t";
						char ch;
						for(;;)
						{
							ch=getch();
							if(ch==13)
							{clrscr();
							drawboxX();
							help();
							break;}
							else if(ch==27)
							exit(1);
							else
							cout<<"! WRONG KEY ENTERED !";
						}
						break;
					}

					case 2:
					{
						clrscr();
						drawbox();
						gotoxy(5, 7);cout<<"����������������������������������������͸";
						gotoxy(5, 8);cout<<"� DEVELOPER'S           � BEN ABEY       �";
						gotoxy(5,9); cout<<"�                       � AMAL MATHEW    �";
						gotoxy(5,10);cout<<"�                       � MILAN ABRAHAM  �";
						gotoxy(5,11);cout<<"�                       � JEEVAN JAMES   �";
						gotoxy(5,12);cout<<"�                       � JEFFIN P       �";
						gotoxy(5,13);cout<<"�                       � ALVIN GEORGE   �";
						gotoxy(5,14);cout<<"����������������������������������������Ĵ";
						gotoxy(5,15);cout<<"� CONTACT @G@ SUPPORT   � +91-9539771452 �";
						gotoxy(5,16);cout<<"� PRODUCT LICENSED TO   �       @G@      �";
						gotoxy(5,17);cout<<"� VERSION NUMBER        � 2.25 Biuld 24  �";
						gotoxy(5,18);cout<<"����������������������������������������;";
						gotoxy(5,20);delay(1500);cout<<"PLEASE Press ENTER to continue or ESCAPE to exit \t";
						char ch;
						for(;;)
						{
							ch=getch();
							if(ch==13)
							{clrscr();
							drawboxX();
							help();
							break;}
							else if(ch==27)
							exit(1);
							else
							cout<<"! WRONG KEY ENTERED !";
						}
						break;
					}


					case 3:
					{
						clrscr();
						drawboxX();
						main_menu();
						break;
					}

					case 4:
					{
					gotoxy(20,20);
					exit(1);

				}
				}
			}
		}
	}
//FUCNTION PROVIDE A CLEAN BOX WITH SOFTWARE NAME AND SOME DETAILS
	void drawbox()
	{

		for(int k=1;k<25;k++)
		{
			if(k==1)
			{
				gotoxy(1,1);
				cout<<"�";
				gotoxy(80,1);
				cout<<"�";
			}
			else if(k==5)
			{
				gotoxy(1,5);
				cout<<"�";
				gotoxy(80,5);
				cout<<"�";
			}
			else if(k==24)
			{
				gotoxy(1,24);
				cout<<"�";
				gotoxy(80,24);
				cout<<"�";
			}
			else if(k==21)
			{
				gotoxy(1,21);
				cout<<"�";
				gotoxy(80,21);
				cout<<"�";
			}
			else if(k!=1&&k!=5)
			{
				gotoxy(1,k);
				cout<<"�";
				gotoxy(80,k);
				cout<<"�";
			}
		}
		for(int l=2;l<80;l++)
		{
			gotoxy(l,5);
			cout<<"�";
			gotoxy(l,21);
			cout<<"�";
		}
		for(int i=2;i<80 ;i++)
		{
			gotoxy(i,1);
			cout<<"�";
			gotoxy(i,24);
			cout<<"�";
		}
		gotoxy(33,3);
		cout<<" VOTING  MACHINE ";
		gotoxy(51,23);
		cout<<"    Licensed to @G@ ";
		gotoxy(29,23);
		cout<<"All Rights Reserved";
		gotoxy(4,23);
		cout<<"Version :- 2.0 beta   ";
	}
//FUCNTION PROVIDE A CLEAN BOX WITH SOFTWARE NAME AND QUOTES
	void drawboxX()
	{
		char str[100]="\"Democracy is being allowed to vote for the  candidate you dislike least\"";
		char str1[100]="\"We would all like to vote for the best manbut he is never a candidate\"";
		char str2[100]="\"Thinking isn't agreeing or disagreeing ,That's voting \"";
		char str3[100]="\"Voting is a civic sacrament\"";
		char str4[100]="\"If voting changed anything, they'd make it illegal\"";
		for(int k=1;k<25;k++)
		{
			if(k==1)
			{
				gotoxy(1,1);
				cout<<"�";
				gotoxy(80,1);
				cout<<"�";
			}
			else if(k==5)
			{
				gotoxy(1,5);
				cout<<"�";
				gotoxy(80,5);
				cout<<"�";
			}
			else if(k==24)
			{
				gotoxy(1,24);
				cout<<"�";
				gotoxy(80,24);
				cout<<"�";
			}
			else if(k==21)
			{
				gotoxy(1,21);
				cout<<"�";
				gotoxy(80,21);
				cout<<"�";
			}
			else if(k!=1&&k!=5)
			{
				gotoxy(1,k);
				cout<<"�";
				gotoxy(80,k);
				cout<<"�";
			}
		}
		for(int l=2;l<80;l++)
		{
			gotoxy(l,5);
			cout<<"�";
			gotoxy(l,21);
			cout<<"�";
		}
		for(int i=2;i<80 ;i++)
		{
			gotoxy(i,1);
			cout<<"�";
			gotoxy(i,24);
			cout<<"�";
		}
		gotoxy(33,3);
		cout<<" VOTING  MACHINE ";
		gotoxy(4,23);
		int p;
		randomize();
		p = random(4);
		if(p==0)
			cout<<str;
		else if(p==1)
			cout<<str1;
		else if(p==2)
			cout<<str2;
		else if(p==3)
			cout<<str3;
		else
			cout<<str4;

	}
//FUNCTION GIVE THE PROGRAM A BEUATIFUL LOADING SCREEN
	void loader()
	{

		int i,k=30,c=0;
		char ch=177 , ce=178;
		gotoxy(27,10);cout<<"���������������������������������ͻ";
		gotoxy(27,11);cout<<"�                         �       �";
		gotoxy(27,12);cout<<"�                         �       �";
		gotoxy(27,13);cout<<"���������������������������������ͼ";
		gotoxy(30,11);
		cout<<"Opening IVM ";
		gotoxy(30,12);
		for(i=0;i<=20;i+=1)
		{
			cout<<ch;
		}
		for(i=0;i<=50;i+=1,c+=5,k++)
		{
			if(c==105)
			{
				gotoxy(30,11);
				cout<<"Ready to ROLL on   #3";
				delay(600);
				goto i;
			}
			gotoxy(k,12);
			delay(500);
			cout<<ce;
			gotoxy(56,12);
			cout<<c<<"%";
			if(c==60)
			{
				gotoxy(30,11);
				cout<<"Recovering Database ";
			}
			if(c==35)
			{
				gotoxy(30,11);
				cout<<"Verifying License  ";
			}
			if(c==80)
			{
				gotoxy(30,11);
				cout<<"Connecting to server";
			}
			if(c==95)
			{
				gotoxy(30,11);
				cout<<"Connected to server#3";
			}
		}
		i:

	}
//FUCTION SECURE THE PROGRAM WITH PREDEFINED PASSWORD
	int pass()
	{

		char ch , t[30]="  TRY AGAIN" ,p[30] ="  INVALID PASSWORD" ;
		int r=0,F=0;
		char pass[20];
		for(;;)
		{
			char m[20]="MAX CHARACTER-18" ;
			gotoxy(30, 8);cout<<"���������������������ͻ";
			gotoxy(30, 9);cout<<"�  Enter the password �";
			gotoxy(30,10);cout<<"���������������������͹";
			gotoxy(30,11);cout<<"�                     �";
			gotoxy(15,12);cout<<" MAX TRY     ���������������������͹      MAX TRY ";
			gotoxy(30,13);cout<<"�                     �";
			gotoxy(30,14);cout<<"���������������������ͼ";
			r=0;
			gotoxy(33,13);
			puts(m);
			gotoxy(33,11);
			if(F<=7)
			{
				for(int i=0,o=0;;i++,o++)
				{
					if(o<17)
					{
						ch=getch();
						if(ch==13)
						{
							pass[r]='\0';
							break;
						}
						if(ch==8)
						{
							if(i>0)
							{
								cout<<ch<<" "<<ch;
								i-=2;r--;
							}
							else
							i--;
						}
						else
						{
							cout<<"�";
							pass[r]=ch;
							r++;
						}
					}
					else
					{
						break;
					}
				}
				if(strcmp("1234",pass)==0)
					return 0;
				else
				{
					gotoxy(31,13);
					delline();
					gotoxy(30,13);cout<<"�                     �";
					gotoxy(30,14);cout<<"���������������������ͼ";
					r=0;
					gotoxy(31,13);
					puts(p);
					delay(1000);
					gotoxy(31,13);
					delline();
					gotoxy(30,13);cout<<"�                     �";
					gotoxy(30,14);cout<<"���������������������ͼ";
					r=0;
					gotoxy(31,13);
					puts(t);
					delay(500);
					F++;
				}
			}

			else
				exit(1);
		}
	}
//FUCTION CONTROLS OVER ALL MAIN MENU WORKING
	void main_menu()
	{
		char key;
		int ch=1 , x=11 , menu_item=0;
		while(ch==1)
		{
			gotoxy(25, 7);cout<<"���������������������ͻ";
			gotoxy(25, 8);cout<<"�     MAIN MAIN     �";
			gotoxy(25, 9);cout<<"���������������������͹";
			gotoxy(25,10);cout<<"�  �                  �";
			gotoxy(25,11);cout<<"�";gotoxy(28,11);cout<<"�    LET'S VOTE    �";
			gotoxy(25,12);cout<<"�";gotoxy(28,12);cout<<"�    DATA ENTRY    �";
			gotoxy(25,13);cout<<"�";gotoxy(28,13);cout<<"�    PREFERANCE    �";
			gotoxy(25,14);cout<<"�";gotoxy(28,14);cout<<"�    GET HELP      �";
			gotoxy(25,15);cout<<"�";gotoxy(28,15);cout<<"�    EXIT          �";
			gotoxy(25,16);cout<<"���������������������͹";
			gotoxy(25,17);cout<<"� Use'W','S' & 'ENTER'�";
			gotoxy(25,18);cout<<"���������������������ͼ";
			
			key = getch();
			if(key=='s' && x!=15)
			{
				gotoxy(27,x); cout<<" ";
				x++;
				gotoxy(27,x); cout<<"";
				menu_item++;
				continue;
			}
			else if(key=='w' && x!=11)
			{
				gotoxy(27,x); cout<<" ";
				x--;
				gotoxy(27,x); cout<<"";
				menu_item--;
				continue;
			}
			else if (key==13)
			{
				switch(menu_item)
				{
					case 0:
					{
						gotoxy(20,20);
						cout << "vote   ";
						break;
					}
					case 1:
					{
						data();
						break;
					}
					case 2:
					{
						clrscr();
						drawboxX();
						skin();
						break;
					}
					case 3:
					{
						help();
						clrscr();
						drawboxX();
						main_menu();
						break;
					}
					case 4:
					{
						gotoxy(20,20);
						exit(1);
					}

				}
			}

		}
	}
//FUCTION SET THE BG COLOR AND TEXT COLOR
	void skin()
	{

		char key ;
		int ch=1 , x=11 , menu_item=0;
		while(ch==1)
		{

			gotoxy(25, 7);cout<<"���������������������ͻ";
			gotoxy(25, 8);cout<<"�    PREFERENCE     �";
			gotoxy(25, 9);cout<<"���������������������͹";
			gotoxy(25,10);cout<<"�  �                  �";
			gotoxy(25,11);cout<<"�";gotoxy(28,11);cout<<"�   BG COLOR       � ";
			gotoxy(25,12);cout<<"�";gotoxy(28,12);cout<<"�   TEXT COLOR     � ";
			gotoxy(25,13);cout<<"�";gotoxy(28,13);cout<<"�   COMING SOON    � ";
			gotoxy(25,14);cout<<"�";gotoxy(28,14);cout<<"�   COMING SOON    � ";
			gotoxy(25,15);cout<<"�";gotoxy(28,15);cout<<"�   BACK           � ";
			gotoxy(25,16);cout<<"���������������������͹";
			gotoxy(25,17);cout<<"� Use'W','S' & 'ENTER'�";
			gotoxy(25,18);cout<<"���������������������ͼ";
			key = getch();
			if(key=='s' && x!=15)
			{
				gotoxy(27,x); cout<<" ";
				x++;
				gotoxy(27,x); cout<<"";
				menu_item++;
				continue;
			}
			else if(key=='w'&& x!=11)
			{
				gotoxy(27,x); cout<<" ";
				x--;
				gotoxy(27,x); cout<<"";
				menu_item--;
				continue;
			}
			else if (key==13)
			{
				switch(menu_item)
				{
					case 0:
					{
						char key ;
						int ch=1 , x=11 , menu_item=0;
						while(ch==1)
						{

							gotoxy(25, 7);cout<<"���������������������ͻ";
							gotoxy(25, 8);cout<<"�     BG COLOUR     �";
							gotoxy(25, 9);cout<<"���������������������͹";
							gotoxy(25,10);cout<<"�  �                  �";
							gotoxy(25,11);cout<<"�";gotoxy(28,11);cout<<"�       WHITE      �";
							gotoxy(25,12);cout<<"�";gotoxy(28,12);cout<<"�       BLACK      �";
							gotoxy(25,13);cout<<"�";gotoxy(28,13);cout<<"�       GREEN      �";
							gotoxy(25,14);cout<<"�";gotoxy(28,14);cout<<"�       YELLOW     �";
							gotoxy(25,15);cout<<"�";gotoxy(28,15);cout<<"�       BACK       �";
							gotoxy(25,16);cout<<"���������������������͹";
							gotoxy(25,17);cout<<"� Use'W','S' & 'ENTER'�";
							gotoxy(25,18);cout<<"���������������������ͼ";
							key = getch();
							if(key=='s' && x!=15)
							{
								gotoxy(27,x); cout<<" ";
								x++;
								gotoxy(27,x); cout<<"";
								menu_item++;
								continue;
							}
							else if(key=='w'&& x!=11)
							{
								gotoxy(27,x); cout<<" ";
								x--;
								gotoxy(27,x); cout<<"";
								menu_item--;
								continue;
							}
							else if (key==13)
							{
								switch(menu_item)
								{
									case 0:
									{
										textbackground(15);
										break;
									}
									case 1:
									{
										textbackground(0);
										break;
									}
									case 2:
									{
										textbackground(2);
										break;
									}
									case 3:
									{
										textbackground(14);
										break;
									}
									case 4:
									{
										clrscr();
										drawboxX();
										skin();
									}

								}
							}
						}
						break;
				}
					case 1:
					{
						char key ;
						int ch=1 , x=11 , menu_item=0;
						while(ch==1)
						{

							gotoxy(25, 7);cout<<"���������������������ͻ";
							gotoxy(25, 8);cout<<"�      COLOUR       �";
							gotoxy(25, 9);cout<<"���������������������͹";
							gotoxy(25,10);cout<<"�  �                  �";
							gotoxy(25,11);cout<<"�";gotoxy(28,11);cout<<"�      BLACK       � ";
							gotoxy(25,12);cout<<"�";gotoxy(28,12);cout<<"�      BROWN       � ";
							gotoxy(25,13);cout<<"�";gotoxy(28,13);cout<<"�      GREEN       � ";
							gotoxy(25,14);cout<<"�";gotoxy(28,14);cout<<"�      RED         � ";
							gotoxy(25,15);cout<<"�";gotoxy(28,15);cout<<"�      BACK        � ";
							gotoxy(25,16);cout<<"���������������������͹";
							gotoxy(25,17);cout<<"� Use'W','S' & 'ENTER'�";
							gotoxy(25,18);cout<<"���������������������ͼ";
							key = getch();
							if(key=='s' && x!=15)
							{
								gotoxy(27,x); cout<<" ";
								x++;
								gotoxy(27,x); cout<<"";
								menu_item++;
								continue;
							}
							else if(key=='w'&& x!=11)
							{
								gotoxy(27,x); cout<<" ";
								x--;
								gotoxy(27,x); cout<<"";
								menu_item--;
								continue;
							}
							else if (key==13)
							{
								switch(menu_item)
								{
									case 0:
									{
										textcolor(0);
										break;
									}
									case 1:
									{
										textcolor(6);
										break;
									}
									case 2:
									{
										textcolor(2);
										break;
									}
									case 3:
									{
										textcolor(4);
										break;
									}
									case 4:
									{
										clrscr();
										drawboxX();
										skin();
									}

								}
							}

						}
						break;
					}
					case 4:
					{
						clrscr();
						drawboxX();
						main_menu();
					}

				}
			}
		}
	}
//MAIN FUCTION FOR WHOLE PROGRAM
	void main()
	{
		clrscr();
		textbackground(WHITE);
		textcolor(0);
		pass();
		clrscr();
		drawbox();
		loader();
		clrscr();
		drawboxX();
		main_menu();
	}

