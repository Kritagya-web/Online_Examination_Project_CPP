
#include<ctime>
#include<iostream>
#include<stdio.h>
#include<fstream>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

using namespace std;

int instructionblock();
void displayquestionsc(char *);
void displayquestionds(char *);
void displayquestionspython(char *);
int menu();




class registration{
		private:
		char name[40];
		char fname[40];                                 // class for registration of new candidate.
		char emailid[50];
		char password[30];
		char mobile[11];
		char address[70];
	public:
		int uniqueid(char *);  // function designed to remove multiple registrations of a candidate with same email id.
		void give(){
			int u;
			registration r10;
			cin.ignore();
			cout<<"\n\n\t\t\tEnter Your Name :";
			cin.getline(name,40);
			cout<<"\n\t\t\tEnter Your Father's Name :";
			cin.getline(fname,40);
			cout<<"\n\t\t\tEnter Your Email-ID :";
		    cin.getline(emailid,50);
		    u=emailcheck(emailid);
			int m;
			m=r10.uniqueid(emailid);
	      	while(m){
	      		cout<<"email is already registresed\n";
				cout<<"re-enter emailid \n";
				cin.getline(emailid,50);
			    m=r10.uniqueid(emailid);
			  }
			cout<<"\nPASSWORD :";
			cin.getline(password,30);
			cout<<"\nMOBILE :";
		    gets(mobile);
		    int y;
		    y=mobilecheck(mobile);
		    cout<<"\nADDRESS :";
		    cin.getline(address,70);
		}
		void fpass(char* n,char* e);

		void show(){
			cout<<name<<" "<<fname<<" "<<password<<" "<<emailid<<" "<<mobile<<endl;
		}
		void store();
        int login(char *,char *);
        int emailcheck(char *email){                             // FUNCTION TO CHECK WHETHER EMAIL IS VALID OR NOT
			int d=0;
			for(int i=0;i<strlen(email);i++){
	         	if(email[i]==64){                                  // 64 ASCII CODE FOR @
		        	for(int j=i+1;j<strlen(email);j++){
			        	if(email[j]==46 &&(j-i==6)){                 //46 ASCII CODE OF DOT.
					       if(email[j+1]=='c' &&email[j+2]=='o' && email[j+3]=='m'){
						  	d=1;}}}
						}
			}
	   if(d==1){
	   	return 1;}
	   else{
	   	cout<<"\nEmail entered by you is invalid";
	   	cout<<"\nPlease Re-enter your email-id: ";
	   	cin.ignore();
	   	cin.getline(emailid,50);
	   	emailcheck(emailid);}}
     int mobilecheck(char *m){
			int h=0,n;
			n=strlen(m);
			if(n!=10){
				cout<<"Mobile number entered by you is invalid\n";
				cout<<"Please Re-enter mobile number: ";
	            gets(mobile);
		        mobilecheck(mobile);
			}
           	for(int y=0;y<strlen(m);y++){
		        if(m[y]>=48 &&m[y]<=58){
			        h++;}}
	        if(h==10){
		         return 1;}
        	else{
	        	cout<<"mobile number is invalid\n";
	            gets(mobile);
		        mobilecheck(mobile);}}

		    };


class result
{
    private:
        char name[30];
        int correct,incorrect,unattempted;
    public:
        void getData(char *na,int a,int b,int d)
        { strcpy(name,na);
          correct=a;
          incorrect=b;
          unattempted=d;
        }

        void showresult(void)
        {
        cout<<"Name: "<<name<<endl<<"correct:"<<correct<<endl<<"incorrect : "<<incorrect<<"\nunattempted: "<<unattempted;
        }

        int search(char *f,int choice)

        {
            if(choice==1)
            {


               ifstream fin;
               fin.open("today.txt");
               fin.read((char *)this,sizeof(*this));                      // searches for the details of user who has given test and displays it using
                                                                                //showresult function.
               while(!fin.eof())
                {
               if(!strcmp(f,name))
               {
                  showresult();
                  return 1;
                }
                 fin.read((char *)this,sizeof(*this));
                }
                fin.close();
              }
             else if(choice==2)
            {
               ifstream fin;
               fin.open("pythonresult.txt");
               fin.read((char *)this,sizeof(*this));                      // searches for the details of user who has given test and displays it using
                                                                                //showresult function.
               while(!fin.eof())
                {
               if(!strcmp(f,name))
               {
                  showresult();
                  return 1;
                }
                 fin.read((char *)this,sizeof(*this));
                }
                fin.close();
              }

            else   if(choice==3)
            {


               ifstream fin;
               fin.open("dsresult.txt");
               fin.read((char *)this,sizeof(*this));                      // searches for the details of user who has given test and displays it using
                                                                                //showresult function.
               while(!fin.eof())
                {
               if(!strcmp(f,name))
               {
                  showresult();
                  return 1;
                }
                 fin.read((char *)this,sizeof(*this));
                }
                fin.close();
              }

        return 0;
        }

        int ifalreadygiven(char *f,int choice)                  // choice if file name to open cpp,python or ds.
        {         if(choice==1){
                            ifstream fin;
                            fin.open("today.txt");
                            fin.read((char *)this,sizeof(*this));
                            while(!fin.eof())                       // retuns 1 if the user has already given a test
                                {
                                    if(!strcmp(f,name)){
                                    return 1;
                                            }
                                fin.read((char *)this,sizeof(*this));
                                }
                            fin.close();
                            }
                if(choice==2){
                            ifstream fin;
                            fin.open("pythonresult.txt");
                            fin.read((char *)this,sizeof(*this));
                            while(!fin.eof())                       // retuns 1 if the user has already given a test
                                {
                                    if(!strcmp(f,name)){
                                    return 1;
                                            }
                                fin.read((char *)this,sizeof(*this));
                                }
                            fin.close();
                              }

                if(choice==3){
                            ifstream fin;
                            fin.open("dsresult.txt");
                            fin.read((char *)this,sizeof(*this));
                            while(!fin.eof())                       // retuns 1 if the user has already given a test
                                {
                                    if(!strcmp(f,name)){
                                    return 1;
                                            }
                                fin.read((char *)this,sizeof(*this));
                                }
                            fin.close();
                              }


 return 0;
         }


        void inserttofile(char *name,int choice,int c=0,int i=0,int u=0)
        {
            if(choice==1){
                        ofstream file;
                        file.open("today.txt",ios::app|ios::out);             //inserts a new record to file by using get data function.
                        getData(name,c,i,u);
                        file.write((char*)this,sizeof(*this));
                        file.close();
                       }

                if(choice==2){
                        ofstream file;
                        file.open("pythonresult.txt",ios::app|ios::out);             //inserts a new record to file by using get data function.
                        getData(name,c,i,u);
                        file.write((char*)this,sizeof(*this));
                        file.close();
                          }


                if(choice==3){
                        ofstream file;
                        file.open("dsresult.txt",ios::app|ios::out);             //inserts a new record to file by using get data function.
                        getData(name,c,i,u);
                        file.write((char*)this,sizeof(*this));
                        file.close();
                        }                                //close the file
            }

};






void questions(char *name)
	{system("cls");
	int choice;
	cout<<"TEST CHOICES :\n";
	cout<<"PRESS 1.C++";
	cout<<"\nPRESS 2.PYTHON";
	cout<<"\nPRESS3.DataStructure";
	cout<<"\nenter your choice of test:";
lon:	cin>>choice;
	switch(choice){
		case 1 :
			system("cls");

			result r8;
			if(r8.ifalreadygiven(name,1))
            {
                cout<<"\n**************We are Sorry, but you have already given c++ paper & you won't be able to give it again.\n\n";
                cout<<"\nPress 1.To select other paper.\nPress 2.To go back to menu to check result.";
                int n;
                cin>>n;
                if(n==1)
                    questions(name);
                 else
                    menu();
            }
            else{
                    system("cls");
			instructionblock();
			cout<<"\nstart test";
			cout<<"\nPRESS ANY KEY TO PROCEED";
			if(getch())
            {
                 system("cls");
                 displayquestionsc(name);
            }

                }
			break;
		case 2 :
			 system("cls");

			result r2;
			if(r2.ifalreadygiven(name,2))
            {
                cout<<"\n**************We are Sorry, but you have already given Python paper & you won't be able to give it again.\n\n";
                cout<<"\nPress 1.To select other paper.\nPress 2.To go back to menu to check result.";
                int n;
                cin>>n;
                if(n==1)
                    questions(name);
                 else
                    menu();
            }
            else{
                    system("cls");
			instructionblock();
			cout<<"\nstart test";
			cout<<"\n prees any key to proceed to test";

            if(getch())
            {
                 system("cls");
                 displayquestionspython(name);
            }

                }
			break;
		case 3 :
			system("cls");

			result r3;
			if(r3.ifalreadygiven(name,3))
            {
                cout<<"\n**************We are Sorry, but you have already given Data Structures paper & you won't be able to give it again.\n\n";
                cout<<"\nPress 1.To select other paper.\nPress 2.To go back to menu to check result.";
                int n;
                cin>>n;
                if(n==1)
                    questions(name);
                 else
                    menu();
            }
            else{
              system("cls");
			instructionblock();
			cout<<"\nstart test";
			cout<<"\nPRESS ANY KEY TO PROCEED";
			if(getch())
            {

                system("cls");
                displayquestionds(name);
            }

                }
			break;
	}}

		    class question{
	char q[500],a[70],b[70],c[70],d[70];
	public:
		void show(){
			int choice;
			cout<<q<<endl;
			cout<<"a."<<a<<"\t\t"<<"b."<<b<<endl;
			cout<<"c."<<c<<"\t\t"<<"d."<<d<<endl<<endl;
			cout<<"1.TO ANSWER\n";
			cout<<"2.TO SKIP\n";
			cout<<"ENTER YOUR CHOICE :";
		}
		void rq(int i){
			ifstream fin;
			fin.open("QUESTIONS",ios::app);
			fin.seekg((i)*sizeof(*this),ios::beg);
			fin.read((char *)this,sizeof(*this));
     		fin.close();
		    show();
		}
};
int check[10];



void displayquestionsc(char *name)
{
    srand(time(NULL));
    int num[10];
    for(int i=0;i<10;i++){
        num[i]=i+1; }
    int x=int(rand())%10;
    int count=0;
	int choice,c=0,un=0,at=0;
	char oa[10]={'b','a','c','a','a','b','a','d','a','a'},an;
	question q1;
    while(count!=10){
    	if(!check[x]){
    		cout<<"Q"<<(count+1)<<" ";
    		q1.rq(x);
    	 	cin>>choice;
    		switch(choice){
    			case 1 :

    				repeat:cin>>an;
    				while(!((int(an)>=65&&int(an)<=69) ||(int(an)>=97&&int(an)<=100)))
    				{
    				    cout<<"Please enter valid choice: ";
    				    goto repeat;}
    				if(an>=97&&an<=100){
    				if(an==oa[x]){
    					c++;
					}
					else{
						un++;
					}}

				else if(an>=65 &&an<=69){
					an=an+32;
				   if(an==oa[x]){
					c++;
			     	}
				   else{
				    	un++;
				    }
		    	}

					break;
				case 2 :
					at++;
					break;
			}
    		count++;
    		check[x]=1;
    		x=rand()%10;
		}
		else{
			x=rand()%10;
		}
	}
   cout<<c<<"  "<<un<<"  "<<at;
   result r1;
   r1.inserttofile(name,1,c,un,at);
   r1.search(name,1);
}



		    class questionpython{
	char q[500],a[70],b[70],c[70],d[70];
	public:
		void show(){
			int choice;
			cout<<q<<endl;
			cout<<"a."<<a<<"\t\t"<<"b."<<b<<endl;
			cout<<"c."<<c<<"\t\t"<<"d."<<d<<endl<<endl;
			cout<<"1.TO ANSWER\n";
			cout<<"2.TO SKIP\n";
			cout<<"ENTER YOUR CHOICE :";
		}
		void rq(int i){
			ifstream fin;
			fin.open("QUESTIONSPYTHON",ios::app);
			fin.seekg((i)*sizeof(*this),ios::beg);
			fin.read((char *)this,sizeof(*this));
     		fin.close();
		    show();
		}
};


void displayquestionspython(char *name)
{
    srand(time(NULL));
    int num[10];
    for(int i=0;i<10;i++){
        num[i]=i+1; }
    int x=int(rand())%10;
    int count=0;
	int choice,c=0,un=0,at=0;
	char oa[10]={'d','d','b','b','b','a','b','b','d','b'},an;
	questionpython q1;
    while(count!=10){
    	if(!check[x]){
    		cout<<"Q"<<(count+1)<<" ";
    		q1.rq(x);
    	 	cin>>choice;
    		switch(choice){
    			case 1 :

    				repeat:cin>>an;
    				while(!((int(an)>=65&&int(an)<=69) ||(int(an)>=97&&int(an)<=100)))
    				{
    				    cout<<"Please enter valid choice: ";
    				    goto repeat;}
    				if(an>=97&&an<=100){
    				if(an==oa[x]){
    					c++;
					}
					else{
						un++;
					}}

				else if(an>=65 &&an<=69){
					an=an+32;
				   if(an==oa[x]){
					c++;
			     	}
				   else{
				    	un++;
				    }
		    	}

					break;
				case 2 :
					at++;
					break;
			}
    		count++;
    		check[x]=1;

    		x=rand()%10;
		}
		else{
			x=rand()%10;
		}
	}
   cout<<c<<"  "<<un<<"  "<<at;
   result r7;
   r7.inserttofile(name,2,c,un,at);
   r7.search(name,2);
}




		    class questionds{
	char q[500],a[70],b[70],c[70],d[70];
	public:
		void show(){
			int choice;
			cout<<q<<endl;
			cout<<"a."<<a<<"\t\t"<<"b."<<b<<endl;
			cout<<"c."<<c<<"\t\t"<<"d."<<d<<endl<<endl;
			cout<<"1.TO ANSWER\n";
			cout<<"2.TO SKIP\n";
			cout<<"ENTER YOUR CHOICE :";
		}
		void rq(int i){
			ifstream fin;
			fin.open("QUESTIONSDS",ios::app);
			fin.seekg((i)*sizeof(*this),ios::beg);
			fin.read((char *)this,sizeof(*this));
     		fin.close();
		    show();
		}
};





void displayquestionds(char *name)
{
    srand(time(NULL));
    int x=int(rand())%10;
    int count=0;
	int choice,c=0,un=0,at=0;
	char oa[10]={'d','b','a','a','a','b','b','b','b','d'},an;
	questionds q1;
    while(count!=10){
    	if(!check[x]){
    		cout<<"Q"<<(count+1)<<" ";
    		q1.rq(x);
    	 	cin>>choice;
    		switch(choice){
    			case 1 :

    				repeat:cin>>an;
    				while(!((int(an)>=65&&int(an)<=69) ||(int(an)>=97&&int(an)<=100)))
    				{
    				    cout<<"Please enter valid choice: ";
    				    goto repeat;}
    				if(an>=97&&an<=100){
    				if(an==oa[x]){
    					c++;
					}
					else{
						un++;
					}}

				else if(an>=65 &&an<=69){
					an=an+32;
				   if(an==oa[x]){
					c++;
			     	}
				   else{
				    	un++;
				    }
		    	}

					break;
				case 2 :
					at++;
					break;
			}
    		count++;
    		check[x]=1;
    		x=rand()%10;
		}
		else{
			x=rand()%10;
		}
	}
   cout<<c<<"  "<<un<<"  "<<at;
   result r1;
   r1.inserttofile(name,3,c,un,at);
   r1.search(name,3);
}




void registration::store(){
	int m,y;
	y=emailcheck(emailid);
	m=mobilecheck(mobile);
	if(m==1 && y==1){
	ofstream fout;
	fout.open("data",ios::app|ios::binary);
	fout.write((char *)this,sizeof(*this));
	fout.close();
	cout<<"    YOU ARE REGISTERED COMPLETELY";}}
int registration::login(char *n,char *p){
	int flag=0;
	ifstream fin;
	fin.open("data",ios::in|ios::binary);
	fin.read((char *)this,sizeof(*this));
	while(!fin.eof()){
	if(!strcmp(n,name) &&!strcmp(p,password)){
		flag++;
	}
	fin.read((char *)this,sizeof(*this));
	}
	fin.close();
	if(flag==0){
		return 0;
	}
	else{
		return 1;
	}
}
void registration :: fpass(char* n,char* e)
		{
		    ifstream fin;
		    fin.open("data");
		    fin.read((char*)this,sizeof(*this));
		    while(fin){
                if(!strcmp(n,name)&&!strcmp(e,emailid))
                    cout<<"YOUR PASSWORD IS :"<<password<<endl;
                fin.read((char*)this,sizeof(*this));
		    }
		}
		int instructionblock(){
			cout<<"1. THERE ARE TEN QUESTION IN YOUR PAPER\n";
			cout<<"2.EACH QUESTION CONTAIN 4 MARKS FOR CORRECT ANSWER AND -1 FOR INCORRCTED ANSWER\n";
			cout<<"3.YOU MAY ALSO SKIP THE QUESTION \n";
            cout<<"4.CLICK THE SUBMIT BUTTON TO SUBMIT YOUR ANSWERS\n";
			cout<<"5.CHECK YOUR INTERNET CONNECTION PROPERLY\n";
			cout<<"6.MAXIMISE YOUR WINDOW OTHERWISE YOU GET DIFFICULTY\n";
		return 0;
		}
		int registration::uniqueid(char *e){
			int flag=0;
			ifstream fout;
			fout.open("data");
			fout.read((char *)this,sizeof(*this));
		    while(!fout.eof()){
				if (!strcmp(e,emailid)){
					flag=1;
					break;
				}
				fout.read((char *)this,sizeof(*this));
			}
			fout.close();
			if(flag==0){
				cout<<"email is available\n";
			return 0;
			}
			else if(flag==1){
				return 1;
			}
		}



int menu()
{
system("cls");
	do{
	cout<<"\t\t\t\t\tWELCOME TO ONLINE EXAMINATION PORTAL";
    cout<<"\n\t\t\t\t\t************************************";
	cout<<"\n\t\t\t\tPRESS 1 FOR NEW REGISTRATION\n";
	cout<<"\n\t\t\t\tPRESS 2 FOR LOGIN\n";
	cout<<"\n\t\t\t\tPRESS 3 FOR RESULT\n";
	cout<<"\n\t\t\t\tPRESS 4 FOR GET INFORMATION ABOUT TESTS\n";
	cout<<"\n\t\t\t\tPRESS 5 FOR TO KNOW ABOUT US\n";
	cout<<"\n\t\t\t\tPRESS 6 FOR EXIT\n";
	cout<<"\n\t\t\t\tENTER YOUR CHOICE: ";
	int choice;
	cin>>choice;


{

switch(choice){
	case 1 :
		    system("cls");
	        cout<<"\t\t\t\t\tWELCOME TO REGISTRATION PAGE\n";
			registration r1;
	        r1.give();
	        r1.store();
	        break;
	case 2 :
		system("cls");
		cin.ignore();
    label:cout<<"WELCOME TO LOGIN PAGE\n";
		char name1[40],pass1[40],x;
		char a;
    	cout<<"\nname :";
    	//char *pswrd;
	    cin.getline(name1,40,'\n');
	    cout<<"\npassword :";
        cin.getline(pass1,40);
        registration r2;
		int r;
		r=r2.login(name1,pass1);
		if(r==1){
		 	cout<<"found";
			 questions(name1);
			 }
		 else{
		 	  cout<<"no found";
		 	  cout<<"\nIF YOU FORGET PASSWORD(Y)";
		 	  cout<<"\nIF YOU WANT TO RE-ENTER YOUR DETAILS(N)";
		 	  cout<<"\nPRESS(E) TO EXIT THE PROGRAMME";
		 	  cout<<"\nENTER YOUR CHOICE :";
              cin>>a;
		    	if(a=='y'||a=='Y'){
		    	cout<<"Enter your email id : ";
                char e[30];
                cin.ignore();
                cin.getline(e,30,'\n');
		        r2.fpass(name1,e);
		        goto label;
				}
                else if(a=='N'||a=='n'){
	   	                cin.ignore();
                       	cout<<"\nname :";
	                    cin.getline(name1,40);
	                abc:cout<<"\npassword :";
                         cin.getline(pass1,40);
                        r=r2.login(name1,pass1);
                        if(r==1){
                        	cout<<"found";
                        	 questions(name1);
					    	}
					    	else{
					    		cout<<"again enter";
					    		goto abc;
							}

						}
				else{
					exit(0);
				}}
		break;
	case 3 :
		system("cls");
		cout<<"WELCOME TO RESULT PAGE\n";
	res:	cout<<"\nPRESS 1. TO SEE C++ RESULT.";
		cout<<"\nPRESS 2. TO SEE PYTHON RESULT.";
		cout<<"\nPRESS 3. TO SEE DATA STRUCTURES RESULT.";
	    cout<<"\nPRESS 4. TO GO BACK TO MAIN MENU";
	    int n;
	    cin>>n;
	    switch(n)
	    {
	        case 1:
	               result r1;
                   cout<<"\nEnter Your Name to See you C++ result\n";
	               char na[20];
	               cin.ignore();
	               cin.getline(na,20);

	               if(r1.search(na,1))
                    cout<<" ";
                   else
                    cout<<"\nEITHER YOU HAVE NOT REGISTERED OR YOU HAVE NOT GIVEN TEST";
	               cout<<"\nRRESS 1 TO CHECK ANOTHER RESULT";
	               cout<<"\nPRESS 0 TO GO TO MAIN MENU";
	               int y;
	               cin>>y;
	               if(y==1)
                    goto res;
                   else
                    menu();
                    break;

            case 2:
	               result r2;
                   cout<<"\nEnter Your Name to See you Pyton result\n";
	               char pa[20];
	               cin.ignore();
	               cin.getline(pa,20);

	               if(r2.search(pa,2))
                    cout<<" ";
                   else
                    cout<<"\nEITHER YOU HAVE NOT REGISTERED OR YOU HAVE NOT GIVEN TEST";
	               cout<<"\nRRESS 1 TO CHECK ANOTHER RESULT";
	               cout<<"\nPRESS 0 TO GO TO MAIN MENU";
	               int z;
	               cin>>z;
	               if(z==1)
                    goto res;
                   else
                    menu();
                    break;

        case 3:
	               result r3;
                   cout<<"\nEnter Your Name to See you DS result\n";
	               char da[20];
	               cin.ignore();
	               cin.getline(da,20);

	               if(r3.search(da,3))
                    cout<<" ";
                   else
                    cout<<"\nEITHER YOU HAVE NOT REGISTERED OR YOU HAVE NOT GIVEN TEST";
	               cout<<"\nRRESS 1 TO CHECK ANOTHER RESULT";
	               cout<<"\nPRESS 0 TO GO TO MAIN MENU";
	               int q;
	               cin>>q;
	               if(q==1)
                    goto res;
                   else
                    menu();
                    break;

	    }
	    break;
	case 4 :
		system("cls");
	          cout<<"THIS PROJECT CONTAIN THREE DIFFERENT TEST\n";
	          cout<<"1. C/C++ TEST\n";
	          cout<<"2. PYTHON\n";
	          cout<<"3. DATA STRUCTURES\n";
	          cout<<"TO KNOW FUTHER ABOUT TEST DETAILS ENTER YOUR CHOICE ACCORDING GIVEN CHOICE :";
	          int c;
	          cin>>c;

	          switch(c){
	               case 1 :
                      system("cls");
				      cout<<"C/C++ TEST CONTAIN TEN QUESTIONS.EACH QUESTION CONTAIN 4 MARKS AND\n";
					  cout<<"-1 WILL BE DETECTED IF YOU ANSWER WRONG.THESE QUESTIONS ARE BASICALLY\n";
					  cout<<"ASKED INTERVEIWS AND IN UNIVERSITIES.THIS TEST CONTAIN MIXTURE OF C/C++.\n";
					  cout<<"EACH QUESTION CONTAIN FOUR CHOICES.SYLLABUS OF THIS TEST ARE BASED ON FOLLOWING TOPICS\n";
					  cout<<"if-else,for loop,while loop,classes and objects,inheritance of class,constructor,opearor oveloading,\n";
					  cout<<"functions,functions overloading,friend function,inline function,abstract classes,\n";
					  cout<<"virtual functions,hybird inheritance,mamipulators,preprocessor statements,dynamic memory allocations";

			   cout<<"\nPress 1 to go back to main menu";
	        cout<<"\n prees 0 to exit from program";
	        int c4;
	        cin>>c4;
	        if(c4==1)
            {
                menu();
            }
            else
                exit(0);
			        break;
					case 2 :
			         system("cls");
			         cout<<"PYTHON TEST CONTAIN TEN QUESTIONS.EACH QUESTION CONTAIN 4 MARKS AND\n";
					cout<<"-1 WILL BE DETECTED IF YOU ANSWER WRONG.THESE QUESTIONS ARE BASICALLY\n";
					cout<<"ASKED INTERVEIWS AND IN UNIVERSITIES.THIS TEST DIFFICULT QUESTIONS OF PYTHON.\n";
					cout<<"EACH QUESTION CONTAIN FOUR CHOICES.SYLLABUS OF THIS TEST ARE BASED ON FOLLOWING TOPICS\n";
			        cout<<"if-else,control statements,data types,random number,for loops,arthematic operators,bitwise operator\n";
                    cout<<"functions,user defined function,recursion,list,tupple,dictionary,string handing,passing th string,\n";
                    cout<<"file handling,string-manipultion,unicode strings.";
                  cout<<"\nPress 1 to go back to main menu";
	        cout<<"\n prees 0 to exit from program";
	        int c6;
	        cin>>c6;
	        if(c6==1)
            {
                menu();
            }
            else
                exit(0);
                      break;
                    case 3 :
                        system("cls");
                    	cout<<"DATA STRUCTURE TEST CONTAIN TEN QUESTIONS.EACH QUESTION CONTAIN 4 MARKS AND\n";
					  cout<<"-1 WILL BE DETECTED IF YOU ANSWER WRONG.THESE QUESTIONS ARE BASICALLY\n";
					  cout<<"ASKED INTERVEIWS AND IN UNIVERSITIES.THIS TEST DIFFICULT QUESTIONS OF DATA STRUCTURE.\n";
					  cout<<"EACH QUESTION CONTAIN FOUR CHOICES.SYLLABUS OF THIS TEST ARE BASED ON FOLLOWING TOPICS\n";
			          cout<<"complexcity,linear array,linked list,quick sort,trees,graphs,infix to postfix,queues,dequeues,\n";
			          cout<<"tower of hanoi,recursion,sorting,two way linked list.";

			      cout<<"\nPress 1 to go back to main menu";
	        cout<<"\n prees 0 to exit from program";
	        int c1;
	        cin>>c1;
	        if(c1==1)
            {
                menu();
            }
            else
                exit(0);
			          break;
					}
					break;
		case 5 :
		    system("cls");
			  cout<<"THIS EXAMINATION MODULE IS MANAGED BY PRIVATE COMPANY .OUR COMPANY ALSO CONDUCT VARIOUS OTHER PROJECTS.\n";
			cout<<"WE PROVIDE ONE OF BEST TEST TO YOU SO THAT YOU ALL GET GOOD JOBS.WE ARE DEVLOPING THESE TYPES OF PROJECT ALL OVER THE WORLD.";
	        cout<<"\nPress 1 to go back to main menu";
	        cout<<"\n prees 0 to exit from program";
	        int c1;
	        cin>>c1;
	        if(c1==1)
            {
                menu();
            }
            else
                exit(0);
	        break;
	    case 6 :
	    	   exit(0);
	    	   break;
	    default:
	    	cout<<"SORRY,INVALID CHOICE\n";
	    	break;
	       getch();
}
}
}while(1);
}
int main()
{
system("cls");
menu();
}
