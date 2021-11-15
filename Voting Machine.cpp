//MAKE SURE CAP IS OFF

//ALL HEADER FILES
	#include<iostream.h>
	#include<conio.h>
	#include<dos.h>
	#include<string.h>
	#include<stdio.h>
	#include<process.h>
	#include<stdlib.h>
	#include<fstream.h>
	#include<ctype.h>
	
	

	
//FUNCTIONS PROTOTYPE
//FUNCTION FOR PREFERANCE
	void skin();
	void drawbox();
	void drawboxxx();
// BOX WITH QUOTES
	void drawboxX();
	void main_menu();
	void help();
	int pass();
	void voting();
	int string_is_number(char* s);
	void add_candidate_name(void) ;
	void delete_candidate_name(void) ;
	void modify_candidate_name(void) ;
	void list_of_candidate_names(void) ;
	void add_voter_name(void) ;
	void delete_voter_name(void) ;
	void modify_voter_name(void) ;
	void list_of_voters_names(void) ;
	int last_candidate_code(int &num_candidates) ;
	void delete_candidate_record(int) ;
	void modify_candidate_record(int) ;
	void display_candidate_record(int) ;
	int name_candidate_found(int) ;
	void candidate_sort(void) ;
	int last_voter_code(int &num_voters) ;
	void delete_voter_record(int) ;
	void modify_voter_record(int) ;
	void display_voter_record(int) ;
	int name_voter_found(int) ;
	int voter_recordno(int &voter_record) ;
	void voter_sort(void) ;

	
//FOR STRING CHECKING FOR NO
	int string_is_number(char* s)
	{
		int size = strlen(s);
		for(int i = 0; i < size; i++)
		if (!(s[i] >= '0' && s[i] <= '9'))
		return 0;
		return 1;
	}

//***************************************************//	
//                    VOTER                          //
//***************************************************//	

//CLASS1
	class voter_record
	{
		public:
		int voter_namecode ;
		char voter_name[50] ;
		char age[2], gender[2] ;
	};
//CLASS2
	class voter_status
	{
		public:
		int voter_namecode;
		int voting_status;
	};
//RECORD NO 		
	int last_voter_code(int &num_voters)
	{
		voter_record vr;
		fstream file ;
		num_voters = 0;
		file.open("VOTER.DAT", ios::in|ios::binary) ;
		file.seekg(0,ios::beg) ;
		int t=0 ;
		while (file.read((char *)&vr,sizeof(voter_record)))
		{
			t = vr.voter_namecode ;
			num_voters++;
		}
		file.close() ;
		return t ;
	}
//SORTER FOR VOTER DATABASE		
	void voter_sort() 
	{ 
		int i=0,j ; 
		voter_record *arr, temp ; 
		fstream file ; 
		file.open("VOTER.DAT", ios::in|ios::binary) ; 
		while (file.read((char *) &temp, sizeof(voter_record))) 
		i++ ; 
		file.clear(); 
		arr = (voter_record*) new voter_record[i]; 
		int size ; 
		size = i ; 
		file.seekg(0,ios::beg) ; 
		for( i = 0; i < size; i++) 
		file.read((char*)&(arr[i]),sizeof(voter_record)); 
		file.close() ; 
		for (i=1; i<size; i++) 
		{ 
			for (j=0; j<size-i; j++) 
			{ 
				if (arr[j].voter_namecode > arr[j+1].voter_namecode) 
				{ 
				temp=arr[j]; 
				arr[j]=arr[j+1]; 
				arr[j+1]=temp; 
				} 
			} 
		} 
		file.open("VOTER.DAT", ios::out|ios::binary) ; 
		for (i=0; i<size; i++) 
			file.write((char *) &arr[i], sizeof(voter_record)); 
		delete[] arr; 
		file.close() ; 
	} 	
//FUNCTION FOR DISPLAYING ALL THE DETAILS OF VOTERS 	
	void  list_of_voters_names(void)
	{
		voter_sort();
		clrscr();
		drawboxxx();
		voter_record vr;
		fstream file ;
		file.open("VOTER.DAT", ios::in|ios::binary) ;
		file.seekg(0) ;
		int row = 10 , found = 0 , pageno = 1 ;
		gotoxy(30,6) ;
		cout <<"LIST OF NAMES OF VOTERS" ;
		gotoxy(3,8) ;
		cout <<"CODE    NAME                   AGE    GENDER" ;
		while (file.read((char *)&vr, sizeof(voter_record)))
		{
			drawboxxx();
			gotoxy(30,6) ;
			cout <<"LIST OF NAMES OF VOTERS" ;
			delay(20) ;
			found = 1 ;
			gotoxy(4,row) ;
			cout <<vr.voter_namecode ;
			gotoxy(11,row) ;
			cout	<<vr.voter_name ;
			gotoxy(41,row) ;
			cout	<<vr.gender; 
			gotoxy(34,row) ;
			//cout	<<vr.age;
			for(int i=0 ;i<2;i++)
				cout<<vr.age[i] ;
			if ( row == 17 )
			{
				gotoxy(30,6) ;
				cout <<"LIST OF NAMES OF VOTERS" ;
				drawboxxx();
				row = 10 ;
				gotoxy(66,6) ;
				cout <<"Page no. : " <<pageno ;
				pageno++ ;
				gotoxy(4,20) ;
				cout <<"Press any key to continue..." ;
				getche() ;
				clrscr() ;
				gotoxy(3,8) ;
				cout <<"CODE    NAME                   AGE    GENDER" ;
				
			}
			else
				row++ ;
		}
		if ( !found )
		{
			gotoxy(5,10) ;
			cout <<"RECORDS NOT FOUND " ;
		}
		gotoxy(30,6) ;
		cout <<"LIST OF NAMES OF VOTERS" ;
		drawboxxx();
		gotoxy(66,6) ;
		cout <<"Page no. : " <<pageno ;
		gotoxy(4,20) ;
		cout <<"Press any key to continue..." ;
		getche() ;
		file.close () ;
	}
//FUNCTION FOR ADDING VOTER DETAILS TO FILE	
	void add_voter_name(void)
	{
		voter_record vr;
		int vcode, valid ;
		char ch;
		int num_voters;
		vcode = last_voter_code(num_voters) ;
		vcode++ ;
		do
		{
			clrscr() ;
			drawboxX();
			gotoxy(71,2) ;
			cout <<"<0>=Exit" ;
			gotoxy(30,6);cout <<"   ADD NEW VOTER " ;
			gotoxy(5,8)  ;cout <<"Name Code  : " <<vcode ;
			gotoxy(5,9)  ;cout <<"Name       : " ;
			gotoxy(5,10) ;cout <<"Age        : " ;
			gotoxy(5,11) ;cout <<"Gender     : " ;
			do
			{
				valid = 1 ;
				gotoxy(5,18) ;
				clreol();
				drawboxX();
				gotoxy(5,18);
				cout <<"ENTER NAME OF THE VOTER TO ADD IN THE LIST" ;
				gotoxy(5,9) ;
				cout <<"Name       : " ;
				gets(vr.voter_name) ;
				strupr(vr.voter_name) ;
				if (vr.voter_name[0] == '0')
				{
					clrscr();
					drawboxX();	
					return ; 
				}
				if ((strlen(vr.voter_name) < 1))
				{
					valid = 0 ; 
					gotoxy(5,17) ; 
					cout <<"MANDATORY REGION" ; 
					getch() ; 
					gotoxy(5,17) ;
					clreol();
					drawboxX();
				}
				if ((strlen(vr.voter_name)>20))
				{
					valid = 0 ; 
					gotoxy(5,17) ; 
					cout <<"RANGE = 20" ; 
					getch() ; 
					gotoxy(5,17) ;
					clreol();
					gotoxy(5,9);
					clreol();
					drawboxX();
				}
			} while (!valid) ;
			do
			{
				valid = 1 ;
				gotoxy(5,18) ;
				clreol();
				drawboxX();
				gotoxy(5,18);
				cout <<"ENTER AGE OF VOTER TO ADD IN THE LIST" ;
				gotoxy(5,10) ;
				cout <<"Age        : " ;
				for(int i=0 ;i<2;i++)
				{ 
					vr.age[i] = getche();
					if(i==0)
						gotoxy(19,10);
				}
				if(isalpha(vr.age[0])||isalpha(vr.age[1]))
				{	
				    valid = 0;
					gotoxy(5,17);
					
					cout<<"AGE IN NUMERIC";
					getch() ; 
					gotoxy(5,17);
					clreol();
					gotoxy(5,10);
					clreol();
					drawboxX();
				}
				else if(vr.age[0]=='0'||vr.age[0]==13 || vr.age[1]==13)
				{	
						valid = 0 ; 						
						gotoxy(5,17);
						cout<<"Too YOUNG for ELECTION OR INPUT AGE NUMERICALLY";
						getch();
						gotoxy(5,17) ;
						clreol();
						gotoxy(5,10) ; 
						clreol();
						drawboxX();					
				}
				if(vr.age[0]=='1')
				{
						if(vr.age[1]<'9')
						{	
							valid = 0 ; 
							gotoxy(5,17);
							cout<<"Too YOUNG for ELECTION KIDDOOOOO.....!!!!";
							getch();
							gotoxy(5,17) ;
							clreol();
							gotoxy(5,10) ; 
							clreol();
							drawboxX();
						}
				}
			} while (!valid) ;
			do
			{
				valid = 1 ;
				gotoxy(5,18) ;
				clreol();
				drawboxX();
				gotoxy(5,18);
				cout <<"ENTER GENDER OF VOTER TO ADD IN THE MENU" ;
				gotoxy(5,11) ;
				cout <<"Gender     : " ;
				gets(vr.gender) ;
				strupr(vr.gender);
				if (vr.gender[0] == '0')
				{
					clrscr();
					drawboxX();	
					return ; 
				}
				if ((strlen(vr.gender) < 1) ||(strlen(vr.gender) > 1)|| (strcmp(vr.gender,"M") && strcmp(vr.gender,"F")))
				{
					valid = 0 ;
					gotoxy(5,17) ;
					cout <<"M for MALE / F for FEMALE" ;
					getch() ;
					gotoxy(5,17) ;
					clreol();
					gotoxy(5,11) ;
					clreol();
					drawboxX();
				}
			} while (!valid) ;
			do
			{
				gotoxy(5,18) ;
				clreol();
				drawboxX();
				gotoxy(5,18) ;
				cout <<"DO YOU WANT TO SAVE THIS RECORD (Y/N) : " ;
				ch = getche() ;
				ch = toupper(ch) ;
				if (ch == '0')
				{
					clrscr();
					drawboxX();	
					return ; 
				}
			} while (ch != 'N' && ch != 'Y') ;
			if (ch == 'Y')
			{
			vr.voter_namecode = vcode ;
			fstream file ;
			file.open("VOTER.DAT", ios::out | ios::app |ios::binary) ;
			file.write((char *)&vr, sizeof(voter_record)) ;
			file.close() ;
			vcode++ ;
			}
			do
			{
				gotoxy(5,18) ;
				clreol();
				drawboxX();
				gotoxy(5,18) ;
				cout <<"DO YOU WANT TO ADD MORE RECORDS (Y/N) : " ;
				ch = getche() ;
				ch = toupper(ch) ;
				if (ch == '0')
				{
					clrscr();
					drawboxX();	
					return ; 
				}
			} while (ch != 'N' && ch != 'Y') ;
		} 
		while (ch == 'Y') ;
		clrscr();
		drawboxX();
	
	}
//FUNCTION FOR MODIFYING VOTER RECORD		
	void  modify_voter_name() 
	{ 
		clrscr() ; 
		drawboxxx();
		char t_code[5], ch ; 
		int tcode ; 
		gotoxy(2,20) ; 
		cout <<"PRESS <ENTER> TO SEE THE LIST" ; 
		gotoxy(2,6) ; 
		cout <<"ENTER NAME CODE OF THE ITEM TO BE MODIFY : " ; 
		gets(t_code) ; 
		tcode = atoi(t_code) ; 
		if (tcode == 0) 
		{ 
			list_of_voters_names() ; 
			gotoxy(1,25) ; 
			clreol() ; 
			gotoxy(3,20) ;
			clreol(); 
			drawboxxx();
			gotoxy(3,20) ;
			cout <<"PRESS <ENTER> TO EXIT" ; 
			gotoxy(3,19) ; 
			cout <<"ENTER NAME CODE OF THE ITEM TO BE MODIFY : " ; 
			gets(t_code) ; 
			tcode = atoi(t_code) ; 
			if (tcode == 0) 
			{
				clrscr();
				drawboxX();
				return ; 
			}
		} 
		clrscr() ; 
		if (!name_voter_found(tcode)) 
		{ 
			drawboxxx();
			gotoxy(10,15) ; 
			cout <<"RECORD NOT FOUND" ; 
			getch() ; 
			clrscr();
			drawboxX();
			return ; 
		} 
		clrscr();
		drawboxX();
		display_voter_record(tcode) ; 
		do 
		{ 
		gotoxy(5,20) ; 
		cout <<"DO YOU WANT TO MODIFY THIS RECORD (Y/N) : " ; 
		ch = getche() ; 
		ch = toupper(ch) ; 
		} while (ch != 'N' && ch != 'Y') ; 
		if (ch == 'N') 
		{
			clrscr();
			drawboxX();	
			return ; 
		}
		modify_voter_record(tcode) ; 
	} 
//FUNTION FOR  DELETE VOTER RECORD 		
	void  delete_voter_name() 
	{ 
		clrscr() ; 
		drawboxxx();
		char t_code[5], ch ; 
		int tcode ; 
		gotoxy(3,20) ; 
		cout <<"PRESS <ENTER> TO SEE THE LIST" ; 
		gotoxy(2,6) ; 
		cout <<"Enter Name Code of the item to be deleted : " ; 
		gets(t_code) ; 
		tcode = atoi(t_code) ; 
		if (tcode == 0) 
		{ 
			list_of_voters_names() ; 
			gotoxy(1,25) ; 
			clreol() ; 
			drawboxxx();
			gotoxy(3,20) ; 
			clreol();
			drawboxxx();gotoxy(3,20) ;
			cout <<"Press 0 to EXIT" ; 
			gotoxy(3,19) ; 
			cout <<"Press <ENTER> to Exit" ; 
			gotoxy(3,19) ; 
			cout <<"Enter Name Code of the item to be deleted : " ; 
			gets(t_code) ; 
			tcode = atoi(t_code) ; 
			if (tcode == 0) 
			{
				clrscr();
				drawboxX();
				return ;
			}
		} 
		clrscr() ; 
		if (!name_voter_found(tcode)) 
		{
			drawboxxx();
			gotoxy(10,15) ;
			cout <<"\7Record not found" ; 
			getch() ;
			clrscr();
			drawboxxx();
			return ; 
		} 
		display_voter_record(tcode) ; 
		do 
		{ 
			gotoxy(1,8) ; 
			clreol() ; 
			drawboxX();
			gotoxy(3,20) ; 
			cout <<"Do you want to delete this record (y/n) : " ; 
			ch = getche() ;
			ch = toupper(ch) ;
		} while (ch != 'N' && ch != 'Y') ; 
		if (ch == 'N') 
		{
			clrscr();
			drawboxX();
			return ;
		} 
		delete_voter_record(tcode) ; 
		clrscr();
		drawboxX();
		gotoxy(10,15) ;
		cout <<"Record Deleted" ;
		getch() ;
		clrscr();
		drawboxX();
	} 
//FUNCTION FOR DISPLAYING DETAILS OF VOTER WHEN NAME CODE IS PASSED AS PARAMETER		
	void  display_voter_record(int vcode) 
	{ 
		voter_record vr; 
		fstream file ; 
		file.open("VOTER.DAT", ios::in|ios::binary) ; 
		file.seekg(0,ios::beg) ; 
		while (file.read((char *)&vr, sizeof(voter_record))) 
		{ 
			if (vr.voter_namecode == vcode) 
			{ 
				gotoxy(5,8) ;  cout <<"Name Code  : "<<vr.voter_namecode ; 
				gotoxy(5,9) ;  cout <<"Name       : "<<vr.voter_name ; 
				gotoxy(5,10) ; cout <<"Age        : "<<vr.age ; 
				gotoxy(5,11) ; cout <<"Gender     : "<<vr.gender ; 
				break ; 
			} 
	} 
	file.close() ; 
} 
//TO CHECK WHETHER THE GIVEN NAME CODE IS ALREADY TAKEN
	int name_voter_found(int tcode) 
	{ 
	voter_record vr; 
	fstream file ; 
	file.open("VOTER.DAT", ios::in|ios::binary) ; 
	file.seekg(0,ios::beg) ; 
	int found=0 ; 
	while (file.read((char *)&vr, sizeof(voter_record))) 
	{ 
		if (vr.voter_namecode == tcode) 
		{ 
			found++ ; 
			break ; 
		} 
	} 
	file.close() ; 
	return found ; 
} 
//CHECKING VOTER RECORD NO
	int voter_recordno(int tcode, voter_record &vr) 
	{ 
		voter_record temp; 
		fstream file ; 
		file.open("VOTER.DAT", ios::in|ios::binary) ; 
		file.seekg(0,ios::beg) ; 
		int found=0 ; 
		while (file.read((char *)&temp, sizeof(voter_record))) 
		{ 
			found++ ; 
			if (temp.voter_namecode == tcode) 
			{ 
				vr = temp; 
				break ; 
			} 
		} 
		file.close() ; 
		return found ; 
} 
//FUNTION FOR DELETING PROCESS 
	void  delete_voter_record(int tcode) 
	{ 
		voter_record vr; 
		fstream file ; 
		file.open("VOTER.DAT", ios::in|ios::binary) ; 
		fstream temp ; 
		temp.open("temp.dat", ios::out|ios::binary) ; 
		file.seekg(0,ios::beg) ; 
		while ( !file.eof() ) 
		{ 
			file.read((char *)&vr, sizeof(voter_record)) ; 
			if ( file.eof() ) 
			break ; 
			if ( vr.voter_namecode != tcode ) 
			temp.write((char *)&vr, sizeof(voter_record)) ; 
		} 
		file.close() ; 
		temp.close() ; 
		file.open("VOTER.DAT", ios::out|ios::binary) ; 
		temp.open("temp.dat", ios::in|ios::binary) ; 
		temp.seekg(0,ios::beg) ; 
		while ( !temp.eof() ) 
		{ 
			temp.read((char *)&vr, sizeof(voter_record)) ; 
			if ( temp.eof() ) 
			break ; 
			file.write((char *)&vr, sizeof(voter_record)) ; 
		} 
		file.close() ; 
		temp.close() ; 
} 
//FUNCTION TO MODIFY VOTER DETAILS 	
	void  modify_voter_record(int tcode) 
	{ 
		
		voter_record vr; 
		int recno ; 
		recno = voter_recordno(tcode,vr) ; 
		if (recno == 0) 
			return; 
		int valid, t_code ; 
		char ch,t_namecode[5] ; 
		gotoxy(71,2) ; 
		cout <<"<0>=Exit" ; 
		gotoxy(5,15) ;cout <<"Name Code  : " ; 
		gotoxy(5,16) ;cout <<"Name       : " ; 
		gotoxy(5,17) ;cout <<"Age        : " ; 
		gotoxy(5,18) ;cout <<"Gender     : " ; 
		do 
		{ 
			gotoxy(20,15) ; 
			clreol() ; 
			drawboxX();
			gotoxy(20,15) ; 
			cout <<"CHANGE (Y/N) : " ; 
			ch = getche() ; 
			ch = toupper(ch) ; 
			if (ch == '0') 
			{
				clrscr();
				drawboxX();	
				return ; 
			}
		} while (ch != 'N' && ch != 'Y') ; 
		valid = 0 ; 
		while (ch == 'Y' && !valid) 
		{ 
			valid = 1 ; 
			gotoxy(71,2) ; 
			clreol();
			valid = 1 ; 
			gotoxy(5,15) ; 
			clreol() ; 
			gotoxy(1,19) ; 
			clreol();
			gotoxy(1,20) ; 
			clreol() ; 
			drawboxX();
			gotoxy(2,20) ; 
			cout <<"ENTER NAME CODE TO ADD IN THE MENU" ; 
			gotoxy(5,15) ; 
			cout <<"Name Code  : " ; 
			for(int i =0;i<2;i++)
			{
				t_namecode[i] = getche();
				if(t_namecode[0]==13)
				{	
					t_namecode[0]=0;
					gotoxy(19,15);
				}
			}
			vr.voter_namecode = atoi(t_namecode) ; 
			if (name_voter_found(vr.voter_namecode) && vr.voter_namecode != tcode) 
			{ 
				valid = 0 ; 
				gotoxy(35,15) ; 
				cout <<"CODE ALREADY GIVEN" ; 
				getch() ; 
				gotoxy(35,15) ; 
				clreol();
			} 
			 
			else if(!isdigit(t_namecode[0])||!isdigit(t_namecode[1]))
			{	
				valid = 0;
				gotoxy(35,15);
				cout<<"NAME CODE IN NUMERIC";
				getch() ; 
				gotoxy(35,20);
				clreol();
			}
			else if(t_namecode[0]==13)
			{	
					valid = 0 ; 
					gotoxy(19,15);
			}
			else if (vr.voter_namecode == 0)
			{
				clrscr();		
				drawboxX();
				return ; 
			} 
		}
		do 
		{ 
			gotoxy(20,16) ; 	
			clreol(); 
			drawboxX();
			gotoxy(20,16) ;
			cout <<"CHANGE (Y/N) : " ; 
			ch = getche() ; 
			ch = toupper(ch) ; 
			if (ch == '0') 
			{
				clrscr();
				drawboxX();	
				return ; 
			}
		} while (ch != 'N' && ch != 'Y') ; 
		valid = 0 ; 
		while (ch == 'Y' && !valid) 
		{ 
			valid = 1 ; 
			gotoxy(5,16) ; clreol() ; 
			gotoxy(1,19) ; clreol() ; 
			gotoxy(1,20) ; clreol() ; 
			drawboxX();
			gotoxy(2,20) ; 
			cout <<"ENTER NAME TO ADD IN THE MENU" ; 
			gotoxy(5,16);
			cout <<"Name       : " ; 
			gets(vr.voter_name) ; 
			strupr(vr.voter_name) ; 
			if (vr.voter_name[0] == '0') 
			{
				clrscr();
				drawboxX();	
				return ; 
			}
			if ((strlen(vr.voter_name) < 1) ) 
			{ 
					valid = 0 ; 
					gotoxy(35,15) ;
					cout <<"Mandatory Region" ; 
					getch() ; 
					gotoxy(35,15) ;
					clreol();
					gotoxy(5,16) ;
					clreol();
					drawboxX();
			} 
			if ( (strlen(vr.voter_name) > 20))
			{ 
				valid = 0 ; 
				gotoxy(35,15) ; 
				cout <<"Range = 20" ; 
				getch() ; 
				gotoxy(35,15) ; 
				clreol();
				gotoxy(5,16) ;
				clreol();
				drawboxX();			
			} 
		} 
		do 
		{ 
			gotoxy(20,17) ; 
			clreol() ; 
			drawboxX();
			gotoxy(20,17) ;
			cout <<"CHANGE (Y/N) : " ; 
			ch = getche() ; 
			ch = toupper(ch) ; 
			if (ch == '0') 
			{
				clrscr();
				drawboxX();	
				return ; 
			}
		} while (ch != 'N' && ch != 'Y') ; 
		valid = 0 ; 
		while (ch == 'Y' && !valid) 
		{ 
			valid = 1 ; 
			gotoxy(5,17) ; clreol() ; 
			gotoxy(2,19) ; clreol() ; 
			gotoxy(2,20) ; clreol() ; 
			drawboxX();
			gotoxy(2,20) ; 
			cout <<"ENTER AGE OF VOTER TO ADD IN THE MENU" ; 
			gotoxy(5,17) ; 
			cout <<"Age        : " ; 
			for(int i=0 ;i<2;i++)
			{ 
				vr.age[i] = getche();
				if(i==0)
					gotoxy(19,17);
			}
			if(isalpha(vr.age[0])||isalpha(vr.age[1]))
			{	
				valid = 0;
				gotoxy(35,15) ; 
				cout<<"AGE IN NUMERIC";
				getch() ; 
				gotoxy(35,15) ;
				clreol();
				gotoxy(5,17);
				clreol();	
				drawboxX();
			}
			else if(vr.age[0]=='0'||vr.age[0]==13 || vr.age[1]==13)
			{	
				valid = 0 ; 						
				gotoxy(35,15) ; 
				cout<<"Too YOUNG for ELECTION KIDDOOOOO.....!!!!";
				getch() ; 
				gotoxy(35,15) ;
				clreol();
				gotoxy(5,17);
				clreol();	
				drawboxX();					
			}
			if(vr.age[0]=='1')
			{
				if(vr.age[1]<'9')
				{	
					valid = 0 ; 
					gotoxy(30,15) ; 
					cout<<"Too YOUNG for ELECTION KIDDOOOOO.....!!!!";
					getch() ; 
					gotoxy(30,15) ;
					clreol();
					gotoxy(5,17);
					clreol();	
					drawboxX();
				}
			}
		} 
		do 
		{ 
			gotoxy(25,18) ; 
			clreol() ; 
			drawboxX();
			gotoxy(25,18) ;
			cout <<"CHANGE (Y/N) : " ; 
			ch = getche() ; 
			ch = toupper(ch) ; 
			if (ch == '0') 
			{
				clrscr();
				drawboxX();	
				return ; 
			}
		} while (ch != 'N' && ch != 'Y') ; 
		valid = 0 ; 
		while (ch == 'Y' && !valid) 
		{ 
			valid = 1 ; 
			gotoxy(2,20) ;
			clreol();
			drawboxX();
			gotoxy(2,20) ;
			cout <<"ENTER GENDER OF VOTER TO ADD IN THE MENU" ; 
			gotoxy(5,18) ; 
			cout <<"Gender     : " ; 
			gets(vr.gender) ; 
			strupr(vr.gender); 
			if (vr.gender[0] == '0') 
			{
				clrscr();
				drawboxX();	
				return ; 
			}
			if ((strlen(vr.gender) < 1) ||(strlen(vr.gender) > 1)|| (strcmp(vr.gender,"M") && strcmp(vr.gender,"F")))
			{
				valid = 0 ;
				gotoxy(35,15) ; 
				cout <<"M for MALE / F for FEMALE" ;
				getch() ; 
				gotoxy(35,15) ;
				clreol();
				gotoxy(5,18);
				clreol();	
				drawboxX();
			}
		} 
		do 
		{ 
		drawboxX();
		gotoxy(5,20) ;
		clreol();
		drawboxX();
		gotoxy(5,20) ;
		cout <<"DO YOU WANT TO SAVE THIS RECORD(Y/N) : " ;  
		ch = getche() ; 
		ch = toupper(ch) ; 
		if (ch == '0') 
		{	
			clrscr();
			drawboxX();
			return ; 
		}
		} while (ch != 'N' && ch != 'Y') ; 
		if (ch == 'N') 
		{	
			clrscr();
			drawboxX();
			return ; 
		}
		getch() ; 
		fstream file ; 
		file.open("VOTER.DAT", ios::out | ios::ate|ios::binary) ; 
		int location ; 
		location = (recno-1) * sizeof(vr) ; 
		cout << " Location is " << location; 
		file.seekp(location) ; 
		file.write((char *) &vr, sizeof(voter_record)) ; 
		file.close() ; 
		voter_sort() ; 
		clrscr() ; 
		void drawbox();
		gotoxy(10,15) ; 
		cout <<"RECORD MODIFIED" ; 
		getch() ;
		clrscr();		
		drawboxX();
} 	
//VOTED STATUS OF VOTER
	voter_status*init_voter_status(int &num) 
	{ 
		voter_status *vs = NULL; 
		num = 0; 
		last_voter_code(num); 
		if (num != 0) 
		{ 
			vs = new voter_status[num]; 
			voter_record vr; 
			fstream file ; 
			file.open("VOTER.DAT", ios::in|ios::binary) ; 
			for(int i = 0; i < num; i++) 
			{ 
				file.read((char *)&vr, sizeof(voter_record)); 
				vs[i].voter_namecode = vr.voter_namecode; 
				vs[i].voting_status = 0; 
			} 
			file.close(); 
		} 
		return vs; 
	} 


//***************************************************//
//                    CANDIDATE                      //
//***************************************************//

//CLASS1
	class candidate_record
	{
		public:
		int candidate_namecode ;
		char candidate_name[50] ;
		char partyname[50], partysign[50] ;
		char age[1];

	};
//CLASS2	
	class candidate_status
	{
		public:
		int candidate_namecode;
		int numVotes;
	};
//RECORD NO 	
	int  last_candidate_code(int &num_candidates)
	{ 
		candidate_record cr; 
		fstream file ; 
		num_candidates = 0; 
		file.open("CANDIDATE.DAT", ios::in|ios::binary) ; 
		file.seekg(0,ios::beg) ; 
		int t=0 ; 
		while (file.read((char *) &cr, sizeof(candidate_record))) 
		{ 
			t = cr.candidate_namecode ; 
			num_candidates++; 
		} 
		file.close() ; 
		return t ; 
	} 
//SORTER FOR CANDIDATE DATABASE	
	void  candidate_sort(void) 
	{ 
		int i=0,j ; 
		candidate_record *arr, temp ; 
		fstream file ; 
		file.open("CANDIDATE.DAT", ios::in|ios::binary) ; 
		while (file.read((char *) &temp, sizeof(candidate_record))) 
			i++ ; 
		file.clear(); 
		arr = (candidate_record*) new candidate_record[i]; 
		int size ; 
		size = i ; 
		file.seekg(0,ios::beg) ; 
		for( i = 0; i < size; i++) 
			file.read((char*)&arr[i],sizeof(candidate_record)); 
		file.close() ; 
		for (i=1; i<size; i++) 
		{ 
			for (j=0; j<size-i; j++) 
			{ 
				if (arr[j].candidate_namecode > arr[j+1].candidate_namecode) 
				{ 
					temp=arr[j]; 
					arr[j]=arr[j+1]; 
					arr[j+1]=temp; 
				} 
			} 
		} 
		file.open("CANDIDATE.DAT", ios::out|ios::binary) ; 
		for (i=0; i<size; i++) 
			file.write((char *) &arr[i], sizeof(candidate_record)); 
		delete[] arr; 
		file.close() ; 
	} 
//FUNCTION USED FOR DISPLAYING ALL THE DETAILS OF CANDIDATES
	void  list_of_candidate_names(void)
	{
		clrscr() ;
		drawboxxx();
		candidate_record cr;
		fstream file ;
		file.open("CANDIDATE.DAT", ios::in|ios::binary) ;
		file.seekg(0) ;
		int row = 10 , found = 0 , pageno = 1 ;
		gotoxy(30,6) ;
		cout <<"LIST OF CANDIDATES" ;
		gotoxy(3,8) ;
		cout <<"  CODE     NAME                    PARTY NAME       PARTY SIGN         AGE";	
		while (file.read((char *)&cr, sizeof(candidate_record)))
		{
					gotoxy(30,6) ;
		cout <<"LIST OF CANDIDATES" ;
			drawboxxx();
			delay(20) ;
			found = 1 ;
			gotoxy(5,row) ;
			cout <<cr.candidate_namecode ;
			gotoxy(14,row) ;
			cout	<<cr.candidate_name ;
			gotoxy(38,row) ;
			cout	<<cr.partyname ;
			gotoxy(55,row) ;
			cout	<<cr.partysign ;
			
			gotoxy(74,row) ;
			for(int i=0 ;i<2;i++)
			{			cout<<cr.age[i] ;
			}
			
			if ( row == 17 )
			{
				
				drawboxxx();
				row = 10 ;
				gotoxy(66,6) ;
				cout <<"Page no. : " <<pageno ;
				pageno++ ;
				gotoxy(4,20) ;
				cout <<"Press any key to continue..." ;
				getche() ;
				clrscr() ;
				gotoxy(3,8) ;
		cout <<"  CODE     NAME                  PARTY NAME       PARTY SIGN         AGE";				

			}
			else
				row++ ;
		}
		if ( !found )
		{
			gotoxy(5,10) ;
			cout <<"\7Records not found " ;
		}
							gotoxy(30,6) ;
		cout <<"LIST OF CANDIDATES" ;
		drawboxxx();
		gotoxy(66,6) ;
		cout <<"Page no. : " <<pageno ;
		gotoxy(4,20) ;
		cout <<"Press any key to continue..." ;
		getche() ;
		file.close () ;
	}
//CHECKING CANDIDATE RECORD NO 	
	int  candidate_recordno(int tcode,candidate_record &cr) 
	{ 
		candidate_record temp; 
		fstream file ; 
		file.open("CANDIDATE.DAT", ios::in|ios::binary) ; 
		file.seekg(0,ios::beg) ; 
		int found=0 ; 
		while (file.read((char *) &temp, sizeof(candidate_record))) 
		{ 
			found++ ; 
			if (temp.candidate_namecode == tcode) 
			{ 
				cr = temp; 
				break ; 
			} 
		} 
		file.close() ; 
		return found ; 
	} 
//FUNCTION FOR ADDING CANDIDATE DETAILS TO FILE	
	void  add_candidate_name()
	{
		
		
		candidate_record cr;
		int tcode, valid ;
		char ch;
		int num_candidates;
		tcode = last_candidate_code(num_candidates) ;
		tcode++ ;
		do
		{			
			clrscr() ;
			drawboxX();
			gotoxy(71,2) ; 
			cout <<"<0>=Exit" ; 
			gotoxy(30,6);cout <<"ADD NEW CANDIDATE " ;
			gotoxy(5,8) ;cout <<"Name Code  :  " <<tcode ;
			gotoxy(5,9) ;cout <<"Name       :  " ;
			gotoxy(5,10);cout <<"Party Name :  " ;
			gotoxy(5,11);cout <<"Party Sign :  " ;
			gotoxy(5,12);cout <<"Age        :  " ;
			do
			{
				valid = 1 ;
				gotoxy(1,8) ;  
				gotoxy(1,24); 
				gotoxy(1,25);
				gotoxy(5,18) ; 
				cout <<"ENTER NAME TO ADD IN THE CANDIDATE LIST" ; 
				gotoxy(5,9);cout<<"Name       :  " ;    
				gets(cr.candidate_name) ; 
				strupr(cr.candidate_name) ; 
				if (cr.candidate_name[0] == '0') 
				{
					clrscr();
					drawboxX();	
					return ; 
				}
				if ((strlen(cr.candidate_name) < 1) ) 
				{ 
					valid = 0 ; 
					gotoxy(5,15) ; 
					cout <<"Mandatory Region" ; 
					getch() ; 
					gotoxy(5,15) ;
					clreol();
					drawboxX();
				} 
				if ((strlen(cr.candidate_name) > 20))
				{ 
					valid = 0 ; 
					gotoxy(5,15) ; 
					cout <<"Range = 20" ; 
					getch() ; 
					gotoxy(5,15) ;
					clreol();
					gotoxy(5,9);
					clreol();
					drawboxX();
								
				} 
			}while (!valid) ; 
			do 
			{ 
				gotoxy(5,18) ;
				clreol();
				drawboxX();
				valid = 1 ; 
				gotoxy(1,10) ; 
				gotoxy(1,24) ; 
				gotoxy(1,25) ; 
				gotoxy(5,18);
				cout <<"ENTER PARTY NAME TO ADD IN THE LIST" ; 
				gotoxy(5,10) ; 
				cout <<"Party Name :  " ;
				gets(cr.partyname) ; 
				strupr(cr.partyname); 
				if (cr.partyname[0] == '0') 
				{
					clrscr();
					drawboxX();	
					return ; 
				}
				if (strlen(cr.partyname) < 1) 
				{ 
					valid = 0 ; 
					gotoxy(5,15);
					cout <<"Mandatory Region" ; 
					getch() ; 
					gotoxy(5,15);
					clreol();
					drawboxX();
				} 
				if (strlen(cr.partyname) > 15)
				{ 
					valid = 0 ; 
					gotoxy(5,15) ; 
					cout <<"Range = 15" ; 
					getch() ; 
					gotoxy(5,15) ;
					clreol();
					gotoxy(5,10);
					clreol();
					drawboxX();					
				} 
			} while (!valid) ; 
			do 
			{ 
				valid = 1 ; 
				gotoxy(1,12) ; 
				gotoxy(1,24) ; 
				gotoxy(1,25) ; 
				gotoxy(5,18) ; 
				cout <<"ENTER PARTY SIGN TO ADD IN THE MENU" ; 
				gotoxy(5,11) ; 
				cout <<"Party Sign :  " ; 
				gets(cr.partysign) ; 		
				strupr(cr.partysign); 
				if (cr.partysign[0] == '0') 
				{
					clrscr();
					drawboxX();	
					return ; 
				}
				if (strlen(cr.partysign) < 1) 
				{ 
					valid = 0 ; 
					gotoxy(5,15) ; 
					cout <<"Mandatory Region" ; 
					getch() ; 
					gotoxy(5,15) ;
					clreol();
					drawboxX();
				} 
				if (strlen(cr.partysign) > 15)
				{ 
					valid = 0 ; 
					gotoxy(5,15) ; 
					cout <<"Range = 15" ; 
					getch() ; 
					gotoxy(5,15);
					clreol();
					gotoxy(5,11);
					clreol();
					drawboxX();
								
				} 
			} while (!valid) ; 
			do 
			{ 
				valid = 1; 
				gotoxy(5,18) ; 
				cout <<"ENTER AGE OF THE CANDIDATE" ; 
				gotoxy(5,12) ;
				cout <<"Age        :  " ; 
				for(int i=0 ;i<2;i++)
				{ 
					cr.age[i] = getche();
					if(i==0)
						gotoxy(20,12);
				}
				if(isalpha(cr.age[0])||isalpha(cr.age[1]))
				{	
				    valid = 0;
					gotoxy(5,15);
					cout<<"AGE IN NUMERIC";
					getch() ; 
					gotoxy(5,15);
					clreol();
					gotoxy(5,12);
					clreol();
					drawboxX();
				}
				else if(cr.age[0]=='0'||cr.age[0]==13 || cr.age[1]==13)
				{	
						valid = 0 ; 						
						gotoxy(5,15);
						cout<<"Too YOUNG for ELECTION KIDDOOOOO.....!!!!";
						getch();
						gotoxy(5,15) ;
						clreol();
						gotoxy(5,12) ; 
						clreol();
						drawboxX();					
				}
				if(cr.age[0]=='1')
				{
						if(cr.age[1]<'9')
						{	
							valid = 0 ; 
							gotoxy(5,15);
							cout<<"Too YOUNG for ELECTION KIDDOOOOO.....!!!!";
							getch();
							gotoxy(5,15) ;
							clreol();
							gotoxy(5,12) ; 
							clreol();
							drawboxX();
						}
				}
			} while (!valid) ; 
			do 
			{ 
				gotoxy(1,15) ; 
				gotoxy(1,24) ; 
				gotoxy(1,25) ; 
				gotoxy(5,18) ; 
				cout <<"DO YOU WANT TO SAVE THIS RECORD(Y/N) : " ; 
				ch = getche() ; 
				ch = toupper(ch) ; 
			} while (ch != 'N' && ch != 'Y') ; 
			if (ch == 'Y') 
			{ 
				cr.candidate_namecode = tcode ; 
				fstream file ; 
				file.open("CANDIDATE.DAT", ios::out | ios::app | ios::binary) ; 
				file.write((char *)&cr, sizeof(candidate_record)) ; 
				file.close() ; 
				tcode++ ; 
			} 
			do 
			{ 
				gotoxy(1,17) ; 
				gotoxy(1,24) ; 
				gotoxy(1,25) ; 
				gotoxy(5,18) ; 
				clreol();
				drawboxX();
				gotoxy(5,18) ;
				cout <<"DO YOU WANT TO ADD MORE DATA (Y/N) : " ; 
				ch = getche() ; 
				ch = toupper(ch) ; 
			} while (ch != 'N' && ch != 'Y') ; 
		} while (ch == 'Y') ; 
		clrscr();
		drawboxX();
	} 
//FUNCTION FOR MODIFYING CANDIDATE RECORD	
	void  modify_candidate_name(void) 
	{ 
		clrscr() ; 
		char t_code[5], ch ; 
		int tcode ; 
		clrscr();
		drawboxxx();
		gotoxy(2,20) ; 
		cout <<"PRESS <ENTER> TO SEE THE LIST" ; 
		gotoxy(2,6) ; 
		cout <<"ENTER NAME CODE OF THE ITEM TO BE MODIFY : " ; 
		gets(t_code) ; 
		tcode = atoi(t_code) ; 
		if (tcode == 0) 
		{ 
			list_of_candidate_names() ; 
			gotoxy(1,25) ; 
			clreol() ; 
			gotoxy(3,20) ;
			clreol(); 
			drawboxxx();gotoxy(3,20) ;
			cout <<"PRESS <ENTER> TO EXIT" ; 
			gotoxy(3,19) ; 
			cout <<"ENTER NAME CODE OF THE ITEM TO BE MODIFY : " ; 
			gets(t_code) ; 
			tcode = atoi(t_code) ; 
			if (tcode == 0) 
			{
				clrscr();
				drawboxX();
				return ; 
			}
		} 
		clrscr() ; 
		if (!name_candidate_found(tcode)) 
		{ 
			drawboxxx();
			gotoxy(10,15) ; 
			cout <<"RECORD NOT FOUND" ; 
			getch() ; 
			clrscr();
			drawboxX();
			return ; 
		} 
		clrscr();
		drawboxX();
		display_candidate_record(tcode) ; 
		do 
		{ 
			gotoxy(5,20) ; 
			cout <<"DO YOU WANT TO MODIFY THIS RECORD (Y/N)  : " ; 
			ch = getche() ; 
			ch = toupper(ch) ; 
		} while (ch != 'N' && ch != 'Y') ; 
		if (ch == 'N') 
		{
			clrscr();
			drawboxX();	
			return ; 
		}
		modify_candidate_record(tcode) ; 
} 	
//FUNTION FOR  DELETE CANDIDATE RECORD 	
	void delete_candidate_name(void) 
	{ 
		clrscr();
		drawboxxx();
		char t_code[5], ch ; 
		int tcode ; 
		gotoxy(3,20) ; 
		cout <<"Press <ENTER> to see the list" ; 
		gotoxy(2,6) ;
		cout <<"Enter Name Code of the item to be deleted : " ; 
		gets(t_code) ; 
		tcode = atoi(t_code) ; 
		if (tcode == 0) 
		{ 
			list_of_candidate_names() ; 
			gotoxy(1,25) ; 
			clreol() ; 
			drawboxxx();
			gotoxy(3,20) ; 
			clreol();
			drawboxxx();gotoxy(3,20) ;
			cout <<"Press 0 to EXIT" ; 
			gotoxy(3,19) ; 
			cout <<"Enter Name Code of the item to be deleted : " ; 
			gets(t_code) ; 
			tcode = atoi(t_code) ; 
			if (tcode == 0) 
			{
				clrscr();
				drawboxX();
				return ;
			}
		} 
		clrscr() ; 
		if (!name_candidate_found(tcode)) 
		{ 
			drawboxxx();
			gotoxy(10,15) ;
			cout <<"\7Record not found" ; 
			getch() ;
			clrscr();
			drawboxxx();
			return ; 
		} 
		display_candidate_record(tcode) ; 
		do 
		{ 
			gotoxy(1,8) ; 
			clreol() ; 
			drawboxX();
			gotoxy(3,20) ; 
			cout <<"Do you want to delete this record (y/n) : " ; 
			ch = getche() ;
			ch = toupper(ch) ;
		} while (ch != 'N' && ch != 'Y') ;
		if (ch == 'N')
		{
			clrscr();
			drawboxX();
			return ;
		}
		delete_candidate_record(tcode) ;
		clrscr();
		drawboxX();
		gotoxy(10,15) ;
		cout <<"Record Deleted" ;
		getch() ;
		clrscr();
		drawboxX();
		
}
//FUNTION FOR DELETING PROCESS 	
	void  delete_candidate_record(int tcode)
	{
			
		candidate_record cr;
		fstream file ;
		file.open("CANDIDATE.DAT", ios::in|ios::binary) ;
		fstream temp ;
		temp.open("temp.dat", ios::out|ios::binary) ;
		file.seekg(0,ios::beg) ;
		while ( !file.eof() )
		{
			file.read((char *)&cr, sizeof(candidate_record)) ;
			if ( file.eof() )
				break ;
			if ( cr.candidate_namecode != tcode )
				temp.write((char *)&cr, sizeof(candidate_record)) ;
		}
		file.close() ;
		temp.close() ;
		file.open("CANDIDATE.DAT", ios::out|ios::binary) ;
		temp.open("temp.dat", ios::in|ios::binary) ;
		temp.seekg(0,ios::beg) ;
		while ( !temp.eof())
		{
			temp.read((char *)&cr, sizeof(candidate_record)) ;
			if ( temp.eof())
				break ;
			file.write((char *) &cr, sizeof(candidate_record)) ;
		}
		file.close() ;
		temp.close() ;
}
//FUNCTION TO MODIFY CANDIDATE DETAILS 	
	void  modify_candidate_record(int tcode)
	{
		candidate_record cr;
		int recno ;
		recno = candidate_recordno(tcode,cr) ;
		int valid, t_code ;
		char ch,t_namecode[5] ; 
		gotoxy(71,2) ; 
		cout <<"<0>=Exit" ; 
		gotoxy(5,15) ; cout <<"Name Code  : " ; 
		gotoxy(5,16) ; cout <<"Name       : " ; 
		gotoxy(5,17) ; cout <<"Party Name : " ; 
		gotoxy(5,18) ; cout <<"Party Sign : " ; 
		do 
		{ 	
			gotoxy(71,2) ; 
			cout <<"<0>=Exit" ; 
			gotoxy(20,15) ; 
			clreol() ; 
			drawboxX();gotoxy(20,15) ; 
			cout <<"CHANGE (Y/N) : " ; 
			ch = getche() ; 
			ch = toupper(ch) ; 
			if (ch == '0') 
			{
				clrscr();
				drawboxX();	
				return ; 
			}
		}while (ch != 'N' && ch != 'Y') ; 
		valid = 0 ; 
		while (ch == 'Y' && !valid) 
		{ 
			gotoxy(71,2) ; 
			clreol();
			valid = 1 ; 
			gotoxy(5,15) ; 
			clreol() ; 
			gotoxy(1,19) ; 
			clreol();
			gotoxy(1,20) ; 
			clreol() ; 
			drawboxX();
			gotoxy(2,20) ; 
			cout <<"ENTER NAME CODE TO ADD IN THE MENU" ; 
			gotoxy(5,15) ; 
			cout <<"Name Code  : " ; 
			for(int i =0;i<2;i++)
			{
				t_namecode[i] = getche();
				if(t_namecode[0]==13)
				{	
						t_namecode[0]=0;
						gotoxy(19,15);
										
				}
			}
			cr.candidate_namecode = atoi(t_namecode) ; 
			if (name_candidate_found(cr.candidate_namecode) && cr.candidate_namecode != tcode) 
			{ 
				valid = 0 ; 
				gotoxy(35,15) ; 
				cout <<"CODE ALREADY GIVEN" ; 
				getch() ; 
				gotoxy(35,15) ; 
				clreol();
			} 
			else if(!isdigit(t_namecode[0])||!isdigit(t_namecode[1]))
			{	
				valid = 0;
				gotoxy(35,15);
				cout<<"NAME CODE IN NUMERIC";
				getch() ; 
				gotoxy(35,20);
				clreol();
			}
			else if(t_namecode[0]==13)
			{	
					valid = 0 ; 
					gotoxy(19,15);
									
			}
			else if (cr.candidate_namecode == 0) 
			{
				clrscr();		
				drawboxX();
				return ; 
			} 
	}
		do 
		{ 	
			gotoxy(71,2) ; 
			cout <<"<0>=Exit" ; 
			gotoxy(20,16) ; 	
			clreol(); 
			drawboxX();
			gotoxy(20,16) ;
			cout <<"CHANGE (Y/N) : " ; 
			ch = getche() ; 
			ch = toupper(ch) ; 
			if (ch == '0') 
			{
				clrscr();
				drawboxX();	
				return ; 
			}
		}while (ch != 'N' && ch != 'Y') ; 
		valid = 0 ; 
		while (ch == 'Y' && !valid) 
		{ 
			valid = 1 ; 
			gotoxy(5,16) ; clreol() ; 
			gotoxy(1,19) ; clreol() ; 
			gotoxy(1,20) ; clreol() ; 
			gotoxy(2,20) ; 
			cout <<"ENTER NAME TO ADD IN THE MENU" ; 
			gotoxy(5,16) ; 
			cout <<"Name       : " ; 
			gets(cr.candidate_name) ; 
			strupr(cr.candidate_name) ; 
			if (cr.candidate_name[0] == '0') 
			{
				clrscr();
				drawboxX();	
				return ; 
			}
			if ((strlen(cr.candidate_name) < 1) ) 
			{ 
					valid = 0 ; 
					gotoxy(35,15) ;
					cout <<"Mandatory Region" ; 
					getch() ; 
					gotoxy(35,15) ;
					clreol();
					gotoxy(5,16) ;
					clreol();
			} 
			if ( (strlen(cr.candidate_name) > 20))
			{ 
				valid = 0 ; 
				gotoxy(35,15) ; 
				cout <<"Range = 20" ; 
				getch() ; 
				gotoxy(35,15) ; 
				clreol();
				gotoxy(5,16) ;
				clreol();
							
			} 
		} 
		do 
		{ 	
			gotoxy(71,2) ; 
			cout <<"<0>=Exit" ; 
			gotoxy(20,17) ; clreol() ; drawboxX();gotoxy(20,17) ;
			cout <<"CHANGE (Y/N) : " ; 
			ch = getche() ; 
			ch = toupper(ch) ; 
			if (ch == '0') 
			{
				clrscr();
				drawboxX();	
				return ; 
			}
		} while (ch != 'N' && ch != 'Y') ; 
		valid = 0 ; 
		while (ch == 'Y' && !valid) 
		{ 
			valid = 1 ; 
			gotoxy(5,17) ; clreol() ; 
			gotoxy(2,19) ; clreol() ; 
			gotoxy(2,20) ; clreol() ; 
			gotoxy(2,20) ; 
			cout <<"ENTER PARTY NAME TO ADD IN THE MENU" ; 
			gotoxy(5,17) ; 
			cout <<"Party Name : " ; 
			gets(cr.partyname) ; 
			strupr(cr.partyname); 
			if (cr.partyname[0] == '0') 
			{
				clrscr();
				drawboxX();	
				return ; 
			}
			if (strlen(cr.partyname) < 1) 
			{ 
				valid = 0 ; 
				gotoxy(35,15);
				cout <<"Mandatory Region" ; 
				getch() ; 
				gotoxy(35,15);
				clreol();
				gotoxy(5,17);
				clreol();
				
			} 
			if (strlen(cr.partyname) > 15)
			{ 
				valid = 0 ; 
				gotoxy(35,15) ; 
				cout <<"Range = 15" ; 
				getch() ; 
				gotoxy(35,15) ;
				clreol();
				gotoxy(5,17);
				clreol();	
			} 
		} 
		do 
		{ 	
			gotoxy(71,2) ; 
			cout <<"<0>=Exit" ; 
			gotoxy(20,18) ; clreol() ; drawboxX();gotoxy(20,18) ;
			cout <<"CHANGE (Y/N) : " ; 
			ch = getche() ; 
			ch = toupper(ch) ; 
			if (ch == '0') 
			{
				clrscr();
				drawboxX();	
				return ; 
			}
		} while (ch != 'N' && ch != 'Y') ; 
		valid = 0 ; 
		while (ch == 'Y' && !valid) 
		{ 
			valid = 1 ; 
			gotoxy(1,18) ; clreol() ; 
			gotoxy(1,20) ; clreol() ; 
			gotoxy(1,19) ; clreol() ; 
			gotoxy(2,20) ; 
			cout <<"ENTER PARTY SIGN TO ADD IN THE MENU" ; 
			gotoxy(5,18) ; 
			cout <<"Party Sign : " ; 
			gets(cr.partysign) ; 
			strupr(cr.partysign); 
			if (cr.partysign[0] == '0') 
			{
				clrscr();
				drawboxX();	
				return ; 
			}
			if (strlen(cr.partysign) < 1) 
			{ 
				valid = 0 ; 
				gotoxy(35,15) ; 
				cout <<"Mandatory Region" ; 
				getch() ; 
				gotoxy(35,15) ;
				clreol();
				gotoxy(5,18);
				clreol();
			} 
			if (strlen(cr.partysign) > 15)
			{ 
				valid = 0 ; 
				gotoxy(35,15) ; 
				cout <<"Range = 15" ; 
				getch() ; 
				gotoxy(35,15);
				clreol();
				gotoxy(5,18);
				clreol();						
			} 
		} 
		do 
		{ 	
			gotoxy(71,2) ; 
			cout <<"<0>=Exit" ; 
			gotoxy(1,20) ; clreol() ; 
			gotoxy(1,19) ; clreol() ; 
			drawboxX();
			gotoxy(5,20) ;
			cout <<"DO YOU WANT TO SAVE THIS RECORD(Y/N) : " ; 
			ch = getche() ; 
			ch = toupper(ch) ; 
			if (ch == '0') 
			{	
				clrscr();
				drawboxX();
				return ; 
			}
		} while (ch != 'N' && ch != 'Y') ; 
		if (ch == 'N')
		{	
			clrscr();
			drawboxX();
			return ; 
		}
		getch() ; 
		fstream file ; 
		file.open("CANDIDATE.DAT", ios::out | ios::ate|ios::binary) ; 
		int location ; 
		location = (recno-1) * sizeof(cr) ; 
		file.seekp(location) ; 
		file.write((char *) &cr, sizeof(candidate_record)) ; 
		file.close() ; 
		candidate_sort() ; 
		clrscr() ; 
		gotoxy(10,15) ; 
		cout <<"RECORD MODIFIED" ; 
		getch() ;
		clrscr();		
		drawboxX();
	} 
//TO CHECK WHETHER THE GIVEN NAME CODE IS ALREADY TAKEN	
	int  name_candidate_found(int tcode) 
	{ 
		candidate_record cr; 
		fstream file ; 
		file.open("CANDIDATE.DAT", ios::in|ios::binary) ; 
		file.seekg(0,ios::beg) ; 
		int found=0 ; 
		while (file.read((char *)&cr, sizeof(candidate_record))) 
		{ 
			if (cr.candidate_namecode == tcode) 
			{ 
				found++ ; 
				break ; 
			} 
		} 
		file.close() ; 
		return found ; 
	} 
//FUNCTION FOR DISPLAYING DETAILS OF CANDIDATE WHEN NAME CODE IS PASSED AS PARAMETER	
	void  display_candidate_record(int tcode) 
	{ 
		candidate_record cr; 
		fstream file ; 
		file.open("CANDIDATE.DAT", ios::in|ios::binary) ; 
		file.seekg(0,ios::beg) ; 
		while (file.read((char *)&cr, sizeof(candidate_record))) 
		{ 
			if (cr.candidate_namecode == tcode) 
			{ 
				gotoxy(5, 8);cout <<"Name Code  :  "<<cr.candidate_namecode ; 
				gotoxy(5, 9);cout <<"Name       :  "<<cr.candidate_name ; 
				gotoxy(5,10);cout <<"Party Name :  "<<cr.partyname ; 
				gotoxy(5,11);cout <<"Party Sign :  "<<cr.partysign ; 
				gotoxy(5,12);cout <<"Age        :  "<<cr.age ; 
				break ; 
			} 
		} 
		file.close() ; 
	} 
//VOTED STATUS OF CANDIDATE
	candidate_status*init_candidate_status(int &num) 
	{ 
		candidate_status *cs = NULL;; 
		num = 0; 
		last_candidate_code(num); 
		if (num != 0) 
		{ 
			cs = new candidate_status[num]; 
			candidate_record cr; 
			fstream file; 
			file.open("CANDIDATE.DAT",ios::in|ios::binary); 
			for(int i = 0; i < num; i++) 
			{ 
				file.read((char *)&cr, sizeof(candidate_record)); 
				cs[i].candidate_namecode = cr.candidate_namecode; 
				cs[i].numVotes = 0; 
			} 
			file.close(); 
		} 
		return cs; 
	} 
	


//FUCNTION IS FOR ENTRY , MODIFICATION & VIEWING OF  DATA (CANDIDATE / VOTERS )
	void data()
	{
		char key;
		int ch=1 , x=11 , menu_item=0;gotoxy(27,x+1); cout<<" ";
		while(ch==1)
		{
			gotoxy(25, 7);cout<<"ษอออออออออออออออออออออป";
			gotoxy(25, 8);cout<<"บ     EDIT MENU     บ";
			gotoxy(25, 9);cout<<"ฬออหออออออออออออออออออน";
			gotoxy(25,10);cout<<"บ  บ                  บ";
			gotoxy(25,11);cout<<"บ";gotoxy(28,11);cout<<"บ   CANDIDATE DATA บ";
			gotoxy(25,12);cout<<"บ";gotoxy(28,12);cout<<"บ   CANDIDATE LIST บ";
			gotoxy(25,13);cout<<"บ";gotoxy(28,13);cout<<"บ   VOTERS DATA    บ";
			gotoxy(25,14);cout<<"บ";gotoxy(28,14);cout<<"บ   VOTERS LIST    บ";
			gotoxy(25,15);cout<<"บ";gotoxy(28,15);cout<<"บ   BACK           บ";
			gotoxy(25,16);cout<<"ฬออสออออออออออออออออออน";
			gotoxy(25,17);cout<<"บ Use'W','S' & 'ENTER'บ";
			gotoxy(25,18);cout<<"ศอออออออออออออออออออออผ";
			
			gotoxy(27,x);
			cout<<"";
			gotoxy(48,18);
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
				gotoxy(27,x); cout<<" ";
				switch(menu_item)
				{

					case 0:
					{
						pass();
						clrscr();
						drawboxX();
						char key;
						int ch=1 , x=11 , menu_item=0;
						while(ch==1)
						{
							gotoxy(25, 7);cout<<"ษอออออออออออออออออออออป";
							gotoxy(25, 8);cout<<"บ     MAIN MAIN     บ";
							gotoxy(25, 9);cout<<"ฬออหออออออออออออออออออน";
							gotoxy(25,10);cout<<"บ  บ                  บ";
							gotoxy(25,11);cout<<"บ";gotoxy(28,11);cout<<"บ      ADD         บ";
							gotoxy(25,12);cout<<"บ";gotoxy(28,12);cout<<"บ      MODIFY      บ";
							gotoxy(25,13);cout<<"บ";gotoxy(28,13);cout<<"บ      DELETE      บ";
							gotoxy(25,14);cout<<"บ";gotoxy(28,14);cout<<"บ      BACK        บ";
							gotoxy(25,15);cout<<"บ";gotoxy(28,15);cout<<"บ      EXIT        บ";
							gotoxy(25,16);cout<<"ฬออสออออออออออออออออออน";
							gotoxy(25,17);cout<<"บ Use'W','S' & 'ENTER'บ";
							gotoxy(25,18);cout<<"ศอออออออออออออออออออออผ";
							gotoxy(27,x);
							cout<<"";
							gotoxy(48,18);	
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
										add_candidate_name() ;
										break;
									}
									case 1:
									{
										modify_candidate_name() ;
										break;
									}
									case 2:
									{
										delete_candidate_name() ; 
										break;
									}
									case 3:
									{
										clrscr();
										drawboxX();
										data();
										break;
									}
									case 4:
									{
										exit(1);
									}

								}
							}

						}
						break;
					}
					case 1:
					{
						
						list_of_candidate_names();
						clrscr();
						drawboxX();
						break;

					}
					case 2:
					{
						pass();
						clrscr();
						drawboxX();
						char key;
						int ch=1 , x=11 , menu_item=0;
						while(ch==1)
						{
							gotoxy(25, 7);cout<<"ษอออออออออออออออออออออป";
							gotoxy(25, 8);cout<<"บ     MAIN MAIN     บ";
							gotoxy(25, 9);cout<<"ฬออหออออออออออออออออออน";
							gotoxy(25,10);cout<<"บ  บ                  บ";
							gotoxy(25,11);cout<<"บ";gotoxy(28,11);cout<<"บ      ADD         บ";
							gotoxy(25,12);cout<<"บ";gotoxy(28,12);cout<<"บ      MODIFY      บ";
							gotoxy(25,13);cout<<"บ";gotoxy(28,13);cout<<"บ      DELETE      บ";
							gotoxy(25,14);cout<<"บ";gotoxy(28,14);cout<<"บ      BACK        บ";
							gotoxy(25,15);cout<<"บ";gotoxy(28,15);cout<<"บ      EXIT        บ";
							gotoxy(25,16);cout<<"ฬออสออออออออออออออออออน";
							gotoxy(25,17);cout<<"บ Use'W','S' & 'ENTER'บ";
							gotoxy(25,18);cout<<"ศอออออออออออออออออออออผ";
							gotoxy(27,x);
							cout<<"";
							gotoxy(48,18);	
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
										add_voter_name();
										break;
									}
									case 1:
									{
										modify_voter_name() ;
										break;
									}
									case 2:
									{
										delete_voter_name() ;
										break;
									}
									case 3:
									{
										clrscr();
										drawboxX();
										data();
										break;
									}
									case 4:
									{
										exit(1);
									}

								}
							}

						}						
						break;

					}
					case 3:
					{
						list_of_voters_names();
						clrscr();
						drawboxX();
						break;

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
						gotoxy(27,x);
			cout<<"";
			gotoxy(48,18);
			key = getch();
			if(key=='s' && x!=15)
			{
				gotoxy(27,x); 
				cout<<" ";
				x++;
				gotoxy(27,x); 
				cout<<"";
				menu_item++;
				continue;
			}
			else if(key=='w' && x!=11)
			{
				gotoxy(27,x);
				cout<<" ";
				x--;
				gotoxy(27,x);
				cout<<"";
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
						gotoxy(6,8);
						delay(2000);              cout<<"ฺฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฟ";
						gotoxy(6,9);delay(500);   cout<<"ณ       NAVIGATION INSTRUCTIONS         ณ";
						gotoxy(6,10);             cout<<"รฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤด";
						gotoxy(6,11); delay(500); cout<<"ณ USE 'W' FOR UPWARD MOVEMENT           ณ";
						gotoxy(6,12);delay(500);  cout<<"ณ USE 'S' FOR DOWNWARD MOVEMENT         ณ";
						gotoxy(6,13);delay(500);  cout<<"ณ USE 'ENTER' BUTTON FO ENTER FUNCTION  ณ";
						gotoxy(6,14);delay(500);  cout<<"ภฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤู";
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
							
						}
						break;
				}
					case 1:
					{
						clrscr();
						drawbox();
						gotoxy(4,6);
						delay(2000);             cout<<"ELECTION VOTING SOFTWARE ";
						gotoxy(4,7);             cout<<"ฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤ";
						gotoxy(4,8);delay(500);  cout<<"DESCRIPTION : IN THIS PROJECT , A PREDETERMINED SET OF \n";
						gotoxy(4,9);delay(500);  cout<<"VOTERS WILL BE ABLE TO CAST THE VOTE .VOTERS WILL HAVE \n";
						gotoxy(4,10);delay(500); cout<<"TO PROVE THEIR IDENTITY BY GIVING THEIR IDENTIFICATION \n";
						gotoxy(4,11);delay(500); cout<<"NO. A AUTHENTICATED USER WILL BE ABLE TO CAST THE VOTE.\n";
						gotoxy(4,12);delay(500); cout<<"A USER WHO HAS CASTED THE VOTE CANNOT CAST AGAIN.AFTER \n";
						gotoxy(4,13);delay(500); cout<<"VOTING HAS FINISHED RESUTS WILL BE DECLAIR. A SETUP \n";
						gotoxy(4,14);delay(500); cout<<"OPTION BEFORE ELECTION STARTS , WILL ALLOW VOTER TO BE \n";
						gotoxy(4,15);delay(500); cout<<"CREATED AND CANDIDATE CHOOSEN. \n";
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
		char str1[100]="\"We would all like to vote for the best man but he is never a candidate\"";
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
//FUNCTION PROVIDE A CLEAN BOX FOR VIEWING DATA'S OF CANDIDTAE AND VOTERS
	void drawboxxx()
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
			else if(k==7)
			{
				gotoxy(1,7);
				cout<<"ร";
				gotoxy(80,7);
				cout<<"ด";
			}

			else if(k==9)
			{
				gotoxy(1,9);
				cout<<"ร";
				gotoxy(80,9);
				cout<<"ด";
			}
			else if(k==18)
			{
				gotoxy(1,18);
				cout<<"ร";
				gotoxy(80,18);
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
				cout<<"บ";
				gotoxy(80,k);
				cout<<"บ";
			}
		}

		for(int l=2;l<80;l++)
		{
			gotoxy(l,7);
			cout<<"อ";
			gotoxy(l,9);
			cout<<"อ";
			gotoxy(l,5);
			cout<<"อ";
			gotoxy(l,21);
			cout<<"อ";
		}
		for(int i=2;i<80 ;i++)
		{
			gotoxy(i,1);
			cout<<"อ";
			gotoxy(i,24);
			cout<<"อ";
			gotoxy(i,18);
			cout<<"อ";
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
		
		
		
		clrscr();
		char masterkey[18] = "3030"; 
		char ch , t[30]="  TRY AGAIN" ,p[30] ="  INVALID PASSWORD" ,k[30]="OUT OF TRY..bye ";
		int r=0,F=0;
		char pass[20];
		for(;;)
		{
			char m[20]="MAX CHARACTER-18" ;
			gotoxy(30, 8);cout<<"ษอออออออออออออออออออออป";
			gotoxy(30, 9);cout<<"บ  Enter the password บ";
			gotoxy(30,10);cout<<"ฬอออออออออออออออออออออน";
			gotoxy(30,11);cout<<"บ                     บ";
			gotoxy(30,12);cout<<"ฬอออออออออออออออออออออน";
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
								i-=2;
								r--;
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
				if((strcmp(masterkey ,pass)==0))
					return 0;
				else
				{
					gotoxy(31,13);
					delline();
					gotoxy(30,13);
					cout<<"บ                     บ";
					gotoxy(30,14);
					cout<<"ศอออออออออออออออออออออผ";
					r=0;
					gotoxy(31,13);
					puts(p);
					delay(1000);
					gotoxy(31,13);
					delline();
					gotoxy(30,13);
					cout<<"บ                     บ";
					gotoxy(30,14);
					cout<<"ศอออออออออออออออออออออผ";
					r=0;
					gotoxy(31,13);
					puts(t);
					delay(500);
					F++;
				}
			}

			else
			{
				if(F==8)
			{
				gotoxy(33,13);
				puts(k);
				delay(1000);
			}
				exit(1);
			}
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

			gotoxy(27,x);
			cout<<"";
			gotoxy(48,18);

			key = getch();

			if(key=='s' && x!=15)
			{
				gotoxy(27,x); 
				cout<<" ";
				x++;
				gotoxy(27,x); 
				cout<<"";
				menu_item++;
				continue;
			}
			else if(key=='w' && x!=11)
			{
				gotoxy(27,x); 
				cout<<" ";
				x--;
				gotoxy(27,x);
				cout<<"";
				menu_item--;
				continue;
			}
			else if (key==13)
			{
				switch(menu_item)
				{
					case 0:
					{
						voting() ;
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
			gotoxy(25,13);cout<<"บ";gotoxy(28,13);cout<<"บ   PASSWORD       บ ";
			gotoxy(25,14);cout<<"บ";gotoxy(28,14);cout<<"บ   VIEW LOGS      บ ";
			gotoxy(25,15);cout<<"บ";gotoxy(28,15);cout<<"บ   BACK           บ ";
			gotoxy(25,16);cout<<"ฬออสออออออออออออออออออน";
			gotoxy(25,17);cout<<"บ Use'W','S' & 'ENTER'บ";
			gotoxy(25,18);cout<<"ศอออออออออออออออออออออผ";
			gotoxy(27,x);
			cout<<"";
			gotoxy(48,18);
			key = getch();
			if(key=='s' && x!=15)
			{
				gotoxy(27,x); 
				cout<<" ";
				x++;
				gotoxy(27,x); 
				cout<<"";
				menu_item++;
				continue;
			}
			else if(key=='w'&& x!=11)
			{
				gotoxy(27,x); 
				cout<<" ";
				x--;
				gotoxy(27,x); 
				cout<<"";
				menu_item--;
				continue;
			}
			else if (key==13)
			{
				gotoxy(27,x); 
				cout<<" ";
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
							gotoxy(27,x);
							cout<<"";
							gotoxy(48,18);
							key = getch();
							if(key=='s' && x!=15)
							{
								gotoxy(27,x); 
								cout<<" ";
								x++;
								gotoxy(27,x); 
								cout<<"";
								menu_item++;
								continue;
							}
							else if(key=='w'&& x!=11)
							{
								gotoxy(27,x); 
								cout<<" ";
								x--;
								gotoxy(27,x); 
								cout<<"";
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
							gotoxy(27,x);
							cout<<"";
							gotoxy(48,18);
							key = getch();
							
							if(key=='s' && x!=15)
							{
								gotoxy(27,x); 
								cout<<" ";
								x++;
								gotoxy(27,x); 
								cout<<"";
								menu_item++;
								continue;
							}
							else if(key=='w'&& x!=11)
							{
								gotoxy(27,x); 
								cout<<" ";
								x--;
								gotoxy(27,x); 
								cout<<"";
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
					}

				}
			}
		}
	}
//ENTRY FUNCTION 
	void front()
	{
		
		clrscr();
		
		for(int i =2;i<8;i++)
		{
			clrscr();
			textcolor(i);
			gotoxy(30,10);
			cout<<" I.V.M";
			gotoxy(37,11);
			cout<<"ICHAYAN'S TECH ";
			delay(1000);
			
		}

		char ch=177 ;
		gotoxy(30,12);
		for(i=0;i<=20;i+=1)
		{
			cout<<ch;
			delay(250);
		}
		getch();
	}

//MAIN FUCTION FOR WHOLE PROGRAM
	void main()
	{

		
		clrscr();
		front();
		textbackground(8);
		textcolor(RED);
		pass();
		clrscr();
		drawbox();
		loader();
		clrscr();
		drawboxX();
		main_menu();
	}

	
//FUNCTION FOR LETS VOTE MENU 
	void voting() 
	{	 
		pass();
		clrscr() ; 
		drawboxX();
		char ch,name[50]; 
		int n ,num_voters = 0, num_candidates = 0; 
		int vtr_rec; 
		voter_status* vs = init_voter_status(num_voters); 
		candidate_status* cs = init_candidate_status(num_candidates); 
		int valid=0; 
		if (num_voters == 0) 
		{ 
			gotoxy(10,15); 
			cout << "There are NO VOTERS"; 
			ch = getche(); 
			gotoxy(10,15); 
			clreol();
			drawboxX();
			delete[] vs; 
			delete[] cs; 
			return; 
		} 
		if (num_candidates == 0) 
		{ 
			gotoxy(10,15); 
			cout << "There are NO CANDIDATES"; 
			ch = getche(); 
			gotoxy(10,15); 
			clreol();
			drawboxX();
			delete[] vs; 
			delete[] cs; 
			return; 
		} 

		while(1) 
		{ 
			clrscr();
			gotoxy(30,6); 
			clreol() ; 
			drawboxX();
			gotoxy(30,6); 
			cout <<"VOTING HAS STARTED"; 
			{ 
				int i; 
				for(i = 0; i < num_voters; i++) 
				{ 
					if (vs[i].voting_status == 0)
					break; 
				} 
				if (i == num_voters) 
				{ 
					gotoxy(10,15); 
					clreol() ; 
					drawboxX();
					gotoxy(10,15);
					cout<<"ALL VOTES HAVE BEEN CASTED"; 
					getche(); 
					break; 
				} 

			} 
			gotoxy(3,20); 
			clreol();
			drawboxX();
			gotoxy(3,20); 
			cout <<"ONCE VOTING IS STOPPED IT CAN'T RESUME. YOU WILL HAVE TO START A FRESH" ; 
			gotoxy(3,11);
			cout <<"ENTER THE  VOTER CODE   <   TO VIEW LISTOF VOTERS PRESS <ENTER>- "; 
			
			gets(name); 
			if (strcmp(name,"STOP") == 0) 
			{ 
				//Terminate the Voting; 
				gotoxy(3,20);  
				clreol();
				drawboxX();
				gotoxy(3,20); 
				cout <<"DO YOU WANT TO STOP THE VOTING AND START COUNTING VOTES (Y/N) - "; 
				ch = getche(); 
				ch = toupper(ch); 
				while(!(ch == 'Y' || ch == 'N')) 
				{ 
					gotoxy(70,5); 
					clreol(); 
					ch = getche(); 
					ch = toupper(ch); 
					clrscr(); 
					gotoxy(20,9); 
					cout<<"VOTING RESULTS"; 
					int tie =0; 
					int winner=0; 
					int max = 0; 
					int i; 
					for(i = 0; i < num_candidates; i++) 
					{ 
						if (cs[i].numVotes > max) 
						{ 
							max = cs[i].numVotes; 
						} 
						else if (cs[i].numVotes == max && max > 0) 
							tie = 1; 
					} 
					gotoxy(20,12); 
					if (tie) 
						cout<<"Voting has resulted in tie, joint winners are "; 
					else 
						cout <<"WINNER is "; 
						gotoxy(20,13); 
					for(i = 0; i < num_candidates; i++) 
					{ 
						if (cs[i].numVotes == max) 
						{ 

									if(i>0)
					{gotoxy(20,18); 
						candidate_record cr; 
					candidate_recordno(cs[i].candidate_namecode,cr); 
					if (winner) 
					cout << cr.candidate_name<<endl; 
					delay(500); 
					gotoxy(20,19); 
					cout << "PARTY NAME -->"<<cr.partyname<<endl; 
					gotoxy(20,20); 
					delay(500); 
					cout << "PARTY SIGN -->"<<cr.partysign<<endl; 
					gotoxy(20,21); 
					delay(500); 
					cout << "AGE        -->";
					for(int i=0 ;i<2;i++)
						cout<<cr.age[i] ; 
					winner++;
					}
					else{	
					gotoxy(20,13); 
					candidate_record cr; 
					candidate_recordno(cs[i].candidate_namecode,cr); 
					if (winner) 
					cout<<" "; 
					cout << cr.candidate_name<<endl; 
					delay(500); 
					gotoxy(20,14); 
					cout << "PARTY NAME -->"<<cr.partyname<<endl; 
					gotoxy(20,15); 
					delay(500); 
					cout << "PARTY SIGN -->"<<cr.partysign<<endl; 
					gotoxy(20,16); 
					delay(500); 
					cout << "AGE        -->";
					for(int i=0 ;i<2;i++)
						cout<<cr.age[i] ; 
					winner++; }
						} 
					} 
					ch = getche(); 
					delete[] vs; 
					delete[] cs; 
					clrscr();
					drawboxX();
				}	
			if (ch == 'N') 
			{ 
			gotoxy(6,5); 
			clreol(); 
			continue; 
			} 
			else break; 
			} 			
				
			n = string_is_number(name); 
			gotoxy(6,5); 
			clreol(); 
			if (n == 0) 
			{ 
				gotoxy(3,19); 
				clreol() ; 
				drawboxX();
				gotoxy(3,19); 
				cout << "INCORRECT VOTER CODE, ENTER ONLY DIGITS, TRY AGAIN "; 
				getche(); 
				gotoxy(3,19); 
				clreol() ; 
				drawboxX();
				continue; 
			} 
			n = atoi(name); 
			if (n == 0) 
			{ 
				list_of_voters_names(); 
				continue; 
			} 
			for(vtr_rec = 0; vtr_rec < num_voters; vtr_rec++) 
			{ 
				if (vs[vtr_rec].voter_namecode == n) 
				{ 
					if (vs[vtr_rec].voting_status == 1) 
					{ 
						gotoxy(3,19); 
						clreol() ; 
						drawboxX();
						gotoxy(3,19);
						cout << "Voter with voter code "<< n <<" has alread voted"; 
						getche(); 
						gotoxy(3,19); 
						clreol() ; 
						drawboxX();
					} 
					
					break; 
				} 
			} 
			if ( vtr_rec == num_voters) 
			{ 
				gotoxy(3,19); 
				clreol() ; 
				drawboxX();
				gotoxy(3,19);
				cout << "Voter code "<< n << " not found in Voter list"; 
				getche(); 
				gotoxy(3,19); 
				clreol() ; 
				drawboxX();
				continue; 
			} 
			if (vs[vtr_rec].voting_status == 1) 
			{ 
				gotoxy(3,19); 
				clreol() ; 
				drawboxX();
				gotoxy(3,19); 
				cout << "Voter code "<<n<< " has already voted, can't vote again"; 
				getche(); 
				gotoxy(3,19); 
				clreol() ; 
				drawboxX();
				continue; 
			} 
			while(1) 
			{ 
				clrscr(); 
				gotoxy(3,20) ; 
				clreol(); 
				drawboxX();
				gotoxy(3,20) ;
				clreol(); 
				drawboxX();	
				gotoxy(3,20) ;				
				cout<<"TO CAST INVALID VOTE PRESS <Y>"; 
				gotoxy(3,11); 
				clreol(); 
				drawboxX();	
				gotoxy(3,11); 
				cout <<"Voter with voter code " << vs[vtr_rec].voter_namecode<<" is voting"; 
				gotoxy(3,12); 
				clreol(); 
				drawboxX();	
				gotoxy(3,12); 
				cout<<"ENTER THE CANDIDATE CODE <   TO VIEW LIST OF CANDIDATE PRESS <ENTER>-" ; 
				char can_code[50]; 
				gets(can_code); 
				if (can_code[0] == 'Y' || can_code[0] == 'y') 
				{ 
					vs[vtr_rec].voting_status = 1; 
					clrscr(); 
					drawboxX();
					gotoxy(5,6);
					cout<<"Voter "; 
					gotoxy(3,7); 
					display_voter_record(vs[vtr_rec].voter_namecode); 
					gotoxy(10,13); 
					cout <<"has casted a invalid vote"; 
					getche(); 
					break; 
				} 
				int can = string_is_number(can_code); 
				gotoxy(3,6); 
				if (can == 0) 
				{ 
					gotoxy(3,20) ;
					clreol(); 
					drawboxX();	
					gotoxy(3,20) ;	
					cout << "Incorrect candidate code, enter only digits, try again "; 
					getche(); 
					continue; 
				} 
				can = atoi(can_code); 
				if (can == 0) 
				{ 
					list_of_candidate_names(); 
					getche(); 
					continue; 
				} 
				int can_rec; 
				for(can_rec=0; can_rec<num_candidates; can_rec++) 
				{ 
					if (cs[can_rec].candidate_namecode == can) 
					break; 
				} 
				if (can_rec == num_candidates) 
				{ 
					cout <<"Candidate code "<<can<<" not found in Candidate List"; 
					getche(); 
					continue; 
				} 
				cs[can_rec].numVotes++; 
				vs[vtr_rec].voting_status = 1; 
				clrscr(); 
				drawboxX();
				voter_record vr; 
				voter_recordno(vs[vtr_rec].voter_namecode, vr) ; 
				gotoxy(5,11);
				clreol();
				drawboxX();
				gotoxy(5,11);
				cout<<"Voter " << vr.voter_name<< " has voterd for Candidate "; 
				candidate_record cr; 
				candidate_recordno(cs[can_rec].candidate_namecode,cr); 
				cout << cr.candidate_name; 
				gotoxy(10,15); 
				cout<<"VOTE CASTED"; 
				getche(); 
				valid=1; 
				break; 
			} 
		} 
		if (valid) 
		{ 
			clrscr(); 
			gotoxy(20,9); 
			cout<<"VOTING RESULTS"; 
			int tie =0; 
			int winner=0; 
			int max = 0; 
			int i; 
			for(i = 0; i < num_candidates; i++) 
			{ 
				if (cs[i].numVotes > max) 
				{ 
					max = cs[i].numVotes; 
				} 
				else if (cs[i].numVotes == max && max > 0) 
					tie = 1; 
			} 
			gotoxy(20,12); 
			if (tie) 
				cout<<"Voting has resulted in tie, joint winners are "; 
			else 
				cout <<"WINNER is "; 
				
			for(i = 0; i < num_candidates; i++) 
			{ 
				if (cs[i].numVotes == max) 
				{ 
			
					if(i>0)
					{gotoxy(20,18); 
						candidate_record cr; 
					candidate_recordno(cs[i].candidate_namecode,cr); 
					
					gotoxy(20,18); 
					cout << cr.candidate_name<<endl; 
					delay(500); 
					gotoxy(20,19); 
					cout << "PARTY NAME -->"<<cr.partyname<<endl; 
					gotoxy(20,20); 
					delay(500); 
					cout << "PARTY SIGN -->"<<cr.partysign<<endl; 
					gotoxy(20,21); 
					delay(500); 
					cout << "AGE        -->";
					for(int i=0 ;i<2;i++)
						cout<<cr.age[i] ; 
					winner++;
					}
					else
					{	
					gotoxy(20,13); 
					candidate_record cr; 
					candidate_recordno(cs[i].candidate_namecode,cr); 
					
					gotoxy(20,13); 
					cout << cr.candidate_name<<endl; 
					delay(500); 
					gotoxy(20,14); 
					cout << "PARTY NAME -->"<<cr.partyname<<endl; 
					gotoxy(20,15); 
					delay(500); 
					cout << "PARTY SIGN -->"<<cr.partysign<<endl; 
					gotoxy(20,16); 
					delay(500); 
					cout << "AGE        -->";
					for(int i=0 ;i<2;i++)
						cout<<cr.age[i] ; 
					winner++; }
					
					
				} 
			} 
		} 
		ch = getche(); 
		delete[] vs; 
		delete[] cs; 
		clrscr();
		drawboxX();
	} 


	