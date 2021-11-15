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
			gotoxy(25, 7);cout<<"ษอออออออออออออออออออออป";
			gotoxy(25, 8);cout<<"บ     EDIT MENU     บ";
			gotoxy(25, 9);cout<<"ฬออหออออออออออออออออออน";
			gotoxy(25,10);cout<<"บ  บ                  บ";
			gotoxy(25,11);cout<<"บ";gotoxy(28,11);cout<<"บ   CANDIDATE DATA บ";
			gotoxy(25,12);cout<<"บ";gotoxy(28,12);cout<<"บ   VOTERS DATA    บ";
			gotoxy(25,13);cout<<"บ";gotoxy(28,13);cout<<"บ   VOTERS LIST    บ";
			gotoxy(25,14);cout<<"บ";gotoxy(28,14);cout<<"บ   CANDIDATE LIST บ";
			gotoxy(25,15);cout<<"บ";gotoxy(28,15);cout<<"บ   BACK           บ";
			gotoxy(25,16);cout<<"ฬออสออออออออออออออออออน";
			gotoxy(25,17);cout<<"บ Use'W','S' & 'ENTER'บ";
			gotoxy(25,18);cout<<"ศอออออออออออออออออออออผ";

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

			gotoxy(25, 7);cout<<"ษอออออออออออออออออออออป";
			gotoxy(25, 8);cout<<"บ     GET HELP      บ";
			gotoxy(25, 9);cout<<"ฬออหออออออออออออออออออน";
			gotoxy(25,10);cout<<"บ  บ                  บ";
			gotoxy(25,11);cout<<"บ";gotoxy(28,11);cout<<"บ    NAVIGATION    บ";
			gotoxy(25,12);cout<<"บ";gotoxy(28,12);cout<<"บ    BASICS        บ";
			gotoxy(25,13);cout<<"บ";gotoxy(28,13);cout<<"บ    ABOUT         บ";
			gotoxy(25,14);cout<<"บ";gotoxy(28,14);cout<<"บ    BACK          บ";
			gotoxy(25,15);cout<<"บ";gotoxy(28,15);cout<<"บ    EXIT          บ";
			gotoxy(25,16);cout<<"ฬออสออออออออออออออออออน";
			gotoxy(25,17);cout<<"บ Use'W','S' & 'ENTER'บ";
			gotoxy(25,18);cout<<"ศอออออออออออออออออออออผ";
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
						gotoxy(6,8);delay(2000); cout<<"ฺฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฟ";
						gotoxy(6,9);delay(500);  cout<<"ณ       NAVIGATION INSTRUCTIONS         ณ";
						gotoxy(6,10);             cout<<"รฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤด";
						gotoxy(6,11); delay(500); cout<<"ณ USE 'W' FOR UPWARD MOVEMENT           ณ";
						gotoxy(6,12);delay(500); cout<<"ณ USE 'S' FOR DOWNWARD MOVEMENT         ณ";
						gotoxy(6,13);delay(500); cout<<"ณ USE 'ENTER' BUTTON FO ENTER FUNCTION  ณ";
						gotoxy(6,14);delay(500); cout<<"ภฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤู";
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
						gotoxy(4,7);    cout<<"ฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤ";
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
						gotoxy(5, 7);cout<<"ีอออออออออออออออออออออออัออออออออออออออออธ";
						gotoxy(5, 8);cout<<"ณ DEVELOPER'S           ณ BEN ABEY       ณ";
						gotoxy(5,9); cout<<"ณ                       ณ AMAL MATHEW    ณ";
						gotoxy(5,10);cout<<"ณ                       ณ MILAN ABRAHAM  ณ";
						gotoxy(5,11);cout<<"ณ                       ณ JEEVAN JAMES   ณ";
						gotoxy(5,12);cout<<"ณ                       ณ JEFFIN P       ณ";
						gotoxy(5,13);cout<<"ณ                       ณ ALVIN GEORGE   ณ";
						gotoxy(5,14);cout<<"รฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤลฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤด";
						gotoxy(5,15);cout<<"ณ CONTACT @G@ SUPPORT   ณ +91-9539771452 ณ";
						gotoxy(5,16);cout<<"ณ PRODUCT LICENSED TO   ณ       @G@      ณ";
						gotoxy(5,17);cout<<"ณ VERSION NUMBER        ณ 2.25 Biuld 24  ณ";
						gotoxy(5,18);cout<<"ิอออออออออออออออออออออออฯออออออออออออออออพ";
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
				cout<<"ฺ";
				gotoxy(80,1);
				cout<<"ฟ";
			}
			else if(k==5)
			{
				gotoxy(1,5);
				cout<<"ร";
				gotoxy(80,5);
				cout<<"ด";
			}
			else if(k==24)
			{
				gotoxy(1,24);
				cout<<"ภ";
				gotoxy(80,24);
				cout<<"ู";
			}
			else if(k==21)
			{
				gotoxy(1,21);
				cout<<"ร";
				gotoxy(80,21);
				cout<<"ด";
			}
			else if(k!=1&&k!=5)
			{
				gotoxy(1,k);
				cout<<"ณ";
				gotoxy(80,k);
				cout<<"ณ";
			}
		}
		for(int l=2;l<80;l++)
		{
			gotoxy(l,5);
			cout<<"ฤ";
			gotoxy(l,21);
			cout<<"ฤ";
		}
		for(int i=2;i<80 ;i++)
		{
			gotoxy(i,1);
			cout<<"ฤ";
			gotoxy(i,24);
			cout<<"ฤ";
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
				cout<<"ฺ";
				gotoxy(80,1);
				cout<<"ฟ";
			}
			else if(k==5)
			{
				gotoxy(1,5);
				cout<<"ร";
				gotoxy(80,5);
				cout<<"ด";
			}
			else if(k==24)
			{
				gotoxy(1,24);
				cout<<"ภ";
				gotoxy(80,24);
				cout<<"ู";
			}
			else if(k==21)
			{
				gotoxy(1,21);
				cout<<"ร";
				gotoxy(80,21);
				cout<<"ด";
			}
			else if(k!=1&&k!=5)
			{
				gotoxy(1,k);
				cout<<"ณ";
				gotoxy(80,k);
				cout<<"ณ";
			}
		}
		for(int l=2;l<80;l++)
		{
			gotoxy(l,5);
			cout<<"ฤ";
			gotoxy(l,21);
			cout<<"ฤ";
		}
		for(int i=2;i<80 ;i++)
		{
			gotoxy(i,1);
			cout<<"ฤ";
			gotoxy(i,24);
			cout<<"ฤ";
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
		gotoxy(27,10);cout<<"ษอออออออออออออออออออออออออหอออออออป";
		gotoxy(27,11);cout<<"บ                         บ       บ";
		gotoxy(27,12);cout<<"บ                         บ       บ";
		gotoxy(27,13);cout<<"ศอออออออออออออออออออออออออสอออออออผ";
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
			gotoxy(30, 8);cout<<"ษอออออออออออออออออออออป";
			gotoxy(30, 9);cout<<"บ  Enter the password บ";
			gotoxy(30,10);cout<<"ฬอออออออออออออออออออออน";
			gotoxy(30,11);cout<<"บ                     บ";
			gotoxy(15,12);cout<<" MAX TRY     ฬอออออออออออออออออออออน      MAX TRY ";
			gotoxy(30,13);cout<<"บ                     บ";
			gotoxy(30,14);cout<<"ศอออออออออออออออออออออผ";
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
							cout<<"๙";
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
					gotoxy(30,13);cout<<"บ                     บ";
					gotoxy(30,14);cout<<"ศอออออออออออออออออออออผ";
					r=0;
					gotoxy(31,13);
					puts(p);
					delay(1000);
					gotoxy(31,13);
					delline();
					gotoxy(30,13);cout<<"บ                     บ";
					gotoxy(30,14);cout<<"ศอออออออออออออออออออออผ";
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
			gotoxy(25, 7);cout<<"ษอออออออออออออออออออออป";
			gotoxy(25, 8);cout<<"บ     MAIN MAIN     บ";
			gotoxy(25, 9);cout<<"ฬออหออออออออออออออออออน";
			gotoxy(25,10);cout<<"บ  บ                  บ";
			gotoxy(25,11);cout<<"บ";gotoxy(28,11);cout<<"บ    LET'S VOTE    บ";
			gotoxy(25,12);cout<<"บ";gotoxy(28,12);cout<<"บ    DATA ENTRY    บ";
			gotoxy(25,13);cout<<"บ";gotoxy(28,13);cout<<"บ    PREFERANCE    บ";
			gotoxy(25,14);cout<<"บ";gotoxy(28,14);cout<<"บ    GET HELP      บ";
			gotoxy(25,15);cout<<"บ";gotoxy(28,15);cout<<"บ    EXIT          บ";
			gotoxy(25,16);cout<<"ฬออสออออออออออออออออออน";
			gotoxy(25,17);cout<<"บ Use'W','S' & 'ENTER'บ";
			gotoxy(25,18);cout<<"ศอออออออออออออออออออออผ";
			
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

			gotoxy(25, 7);cout<<"ษอออออออออออออออออออออป";
			gotoxy(25, 8);cout<<"บ    PREFERENCE     บ";
			gotoxy(25, 9);cout<<"ฬออหออออออออออออออออออน";
			gotoxy(25,10);cout<<"บ  บ                  บ";
			gotoxy(25,11);cout<<"บ";gotoxy(28,11);cout<<"บ   BG COLOR       บ ";
			gotoxy(25,12);cout<<"บ";gotoxy(28,12);cout<<"บ   TEXT COLOR     บ ";
			gotoxy(25,13);cout<<"บ";gotoxy(28,13);cout<<"บ   COMING SOON    บ ";
			gotoxy(25,14);cout<<"บ";gotoxy(28,14);cout<<"บ   COMING SOON    บ ";
			gotoxy(25,15);cout<<"บ";gotoxy(28,15);cout<<"บ   BACK           บ ";
			gotoxy(25,16);cout<<"ฬออสออออออออออออออออออน";
			gotoxy(25,17);cout<<"บ Use'W','S' & 'ENTER'บ";
			gotoxy(25,18);cout<<"ศอออออออออออออออออออออผ";
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

							gotoxy(25, 7);cout<<"ษอออออออออออออออออออออป";
							gotoxy(25, 8);cout<<"บ     BG COLOUR     บ";
							gotoxy(25, 9);cout<<"ฬออหออออออออออออออออออน";
							gotoxy(25,10);cout<<"บ  บ                  บ";
							gotoxy(25,11);cout<<"บ";gotoxy(28,11);cout<<"บ       WHITE      บ";
							gotoxy(25,12);cout<<"บ";gotoxy(28,12);cout<<"บ       BLACK      บ";
							gotoxy(25,13);cout<<"บ";gotoxy(28,13);cout<<"บ       GREEN      บ";
							gotoxy(25,14);cout<<"บ";gotoxy(28,14);cout<<"บ       YELLOW     บ";
							gotoxy(25,15);cout<<"บ";gotoxy(28,15);cout<<"บ       BACK       บ";
							gotoxy(25,16);cout<<"ฬออสออออออออออออออออออน";
							gotoxy(25,17);cout<<"บ Use'W','S' & 'ENTER'บ";
							gotoxy(25,18);cout<<"ศอออออออออออออออออออออผ";
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

							gotoxy(25, 7);cout<<"ษอออออออออออออออออออออป";
							gotoxy(25, 8);cout<<"บ      COLOUR       บ";
							gotoxy(25, 9);cout<<"ฬออหออออออออออออออออออน";
							gotoxy(25,10);cout<<"บ  บ                  บ";
							gotoxy(25,11);cout<<"บ";gotoxy(28,11);cout<<"บ      BLACK       บ ";
							gotoxy(25,12);cout<<"บ";gotoxy(28,12);cout<<"บ      BROWN       บ ";
							gotoxy(25,13);cout<<"บ";gotoxy(28,13);cout<<"บ      GREEN       บ ";
							gotoxy(25,14);cout<<"บ";gotoxy(28,14);cout<<"บ      RED         บ ";
							gotoxy(25,15);cout<<"บ";gotoxy(28,15);cout<<"บ      BACK        บ ";
							gotoxy(25,16);cout<<"ฬออสออออออออออออออออออน";
							gotoxy(25,17);cout<<"บ Use'W','S' & 'ENTER'บ";
							gotoxy(25,18);cout<<"ศอออออออออออออออออออออผ";
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

