
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
void center();
void decl();



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
			cout<<"\n\n";
			cin.ignore();
			center();
			cout<<"Enter Your Name: ";
			cin.getline(name,40);
			cout<<"\n";center();     cout<<"Enter Your Father's Name :";
			cin.getline(fname,40);
			cout<<"\n";center();cout<<"Enter Your Email-ID :";
		    cin.getline(emailid,50);
		    u=emailcheck(emailid);
			int m;
			m=r10.uniqueid(emailid);
	      	while(m){
	      		cout<<"\n\n";center();cout<<"****We are sorry, but a user with this Email-Id is already registresed\n";
				center();cout<<"Please enter another Email-Id: ";
				cin.getline(emailid,50);
			    m=r10.uniqueid(emailid);
			  }
			cout<<"\n"; center(); cout<<"Please Enter Your Password: ";
			cin.getline(password,30);
			cout<<"\n";center();
			cout<<"Please Enter Your Mobile Number : ";
		    gets(mobile);
		    int y;
		    y=mobilecheck(mobile);
		    cout<<"\n";center();
		    cout<<"Enter Your Address: ";
		    cin.getline(address,70);
		}
		void fpass(char* e);

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
                  cout<<"\n";  center();
				cout<<"***Mobile number entered by you is invalid\n";
				center();cout<<"Please Re-enter mobile number: ";
	            gets(mobile);
		        mobilecheck(mobile);
			}
           	for(int y=0;y<strlen(m);y++){
		        if(m[y]>=48 &&m[y]<=58){
			        h++;}}
	        if(h==10){
		         return 1;}
        	else{
        	  cout<<"\n";center();
				cout<<"***Mobile number entered by you is invalid\n";
				center();cout<<"Please Re-enter mobile number: ";
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
            cout<<"\n\n\n\n\n****************************YOUR RESULT HAS BEEN GENERATED****************************\n";
            cout<<"****************************PRESS ANY KEY TO SEE YOUR RESULT****************************";
            if(getch())
         {
             system("cls");
             decl();decl();decl();decl();center();
             cout<<"YOUR RESULT IS SHOWN BELOW\n\n\n";
             center();cout<<"Login ID: "<<name<<endl<<endl;
             center();cout<<"Correct Answers:"<<correct<<endl<<endl;
             center();cout<<"Incorrect Answers : "<<incorrect<<endl<<endl;
             center();cout<<"Unattempted Answers: "<<unattempted<<endl<<endl<<endl;
             decl();decl();decl();decl();center();
             cout<<"YOUR TOTAL MARKS ARE : "<<(correct*4)-incorrect<<endl;
             decl();decl();decl();decl();center();
        }}

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
	decl();decl();
	center();
	cout<<"PLEASE CHOOSE ONE OF THE BELOW TESTS : \n";
	decl();decl();
	center();cout<<"***You can give a test only once***\n";
	center();cout<<"PRESS 1. TO GIVE C++ TEST\n";
	center();cout<<"PRESS 2.TO GIVE PYTHON TEST\n";
	center();cout<<"PRESS3.TO GIVE DATA STRUCTURES(DSA) TEST\n";
	cout<<"\n\n\n\n";center();cout<<"ENTER YOUR CHOICE FOR TEST: ";
  cin>>choice;

	switch(choice){
		case 1 :
			system("cls");

			result r8;
			if(r8.ifalreadygiven(name,1))
            {
                cout<<"\n*********************************************We are Sorry, but you have already given c++ paper & you won't be able to give it again.*********************************************\n\n";
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
			cout<<"\n";center();cout<<"******TO START TEST******";
			cout<<"\n";center();cout<<"PRESS ANY KEY TO PROCEED";
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
            {cout<<"\n\n*********************************************We are Sorry, but you have already given Python paper & you won't be able to give it again.*********************************************\n\n";
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
		cout<<"\n";center();cout<<"******TO START TEST******";
			cout<<"\n";center();cout<<"PRESS ANY KEY TO PROCEED";
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
                cout<<"\n*********************************************We are Sorry, but you have already given Data Structures paper & you won't be able to give it again.*********************************************\n\n";
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
			cout<<"\n";center();cout<<"******TO START TEST******";
			cout<<"\n";center();cout<<"PRESS ANY KEY TO PROCEED";
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
                decl();decl();
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
   //cout<<c<<"  "<<un<<"  "<<at;
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
            decl();decl();
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
  // cout<<c<<"  "<<un<<"  "<<at;
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
            decl();decl();
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
   //cout<<c<<"  "<<un<<"  "<<at;
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
	cout<<"\n\n";
	cout<<" \t\t\t\t\t\t**********Congrats!!!!! Your Registration is Successful!!! ";
	cout<<"\n\n\n\t\t\t\t\t\t**********Please note that your login id for test will be your email id**********";
	}}
int registration::login(char *n,char *p){
	int flag=0;
	ifstream fin;
	fin.open("data",ios::in|ios::binary);
	fin.read((char *)this,sizeof(*this));
	while(!fin.eof()){
	if(!strcmp(n,emailid) &&!strcmp(p,password)){
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
void registration :: fpass(char* e)
		{
		    ifstream fin;
		    fin.open("data");
		    fin.read((char*)this,sizeof(*this));
		    while(fin){
                if(!strcmp(e,emailid))
                    cout<<"YOUR PASSWORD IS :"<<password<<endl;
                fin.read((char*)this,sizeof(*this));
		    }
		}
		int instructionblock(){
			center();cout<<"1. THERE ARE TEN QUESTION IN YOUR PAPER\n";
			center();cout<<"2.EACH QUESTION CONTAIN 4 MARKS FOR CORRECT ANSWER AND -1 FOR INCORRCTED ANSWER\n";
			center();cout<<"3.YOU MAY ALSO SKIP THE QUESTION \n";
            center();cout<<"4.CLICK THE SUBMIT BUTTON TO SUBMIT YOUR ANSWERS\n";
			center();cout<<"5.CHECK YOUR INTERNET CONNECTION PROPERLY\n";
			center();cout<<"6.MAXIMISE YOUR WINDOW OTHERWISE YOU MAY GET DIFFICULTY\n";
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
                cout<<"\n";    center();
				cout<<"You are Good to Go!!!!\n";
			return 0;
			}
			else if(flag==1){
				return 1;
			}
		}

void decl()
{
    for(int qw=0;qw<211;qw++)
    {
        cout<<"~";
    }
}
void center()
{
    for(int sp=0;sp<88;sp++)
    {
        cout<<" ";
    }
}


void resultdisplay()
{     decl();decl();
		center(); cout<<" WELCOME TO RESULT PAGE\n";decl();decl();
		cout<<"\n\n\n";center();cout<<"PRESS 1. TO SEE C++ RESULT.\n";
		center();cout<<"PRESS 2. TO SEE PYTHON RESULT.\n";
		center();cout<<"PRESS 3. TO SEE DATA STRUCTURES RESULT.\n";
	    center();cout<<"PRESS 4. TO GO BACK TO MAIN MENU ";
	    int n;
	    cin>>n;cout<<"\n\n\n\n";
	    switch(n)
	    {
	        case 1:
	               result r1;
                   center();cout<<"***Enter Your Login ID to See you C++ result: ";
	               char na[20];
	               cin.ignore();
	               cin.getline(na,20);

	               if(r1.search(na,1))
                    cout<<" ";
                   else
                    cout<<"\n****EITHER YOU HAVE NOT REGISTERED OR YOU HAVE NOT GIVEN TEST";
	               cout<<"\n****PRESS 1 TO CHECK ANOTHER RESULT";
	               cout<<"\n****PRESS 0 TO GO TO MAIN MENU";
	               int y;
	               cin>>y;
	               if(y==1)
                    resultdisplay();
                     else
                   {  system("cls");
                       menu();
                   }
                    break;

            case 2:
	               result r2;
                   center();cout<<"***Enter Your Login ID to See you Python result: ";
	               char pa[20];
	               cin.ignore();
	               cin.getline(pa,20);

	               if(r2.search(pa,2))
                    cout<<" ";
                   else
                    cout<<"\n****EITHER YOU HAVE NOT REGISTERED OR YOU HAVE NOT GIVEN TEST";
	               cout<<"\n****PRESS 1 TO CHECK ANOTHER RESULT";
	               cout<<"\n****PRESS 0 TO GO TO MAIN MENU";
	               int z;
	               cin>>z;
	               if(z==1)
                    resultdisplay();
                     else
                   {  system("cls");
                       menu();
                   }
                    break;

        case 3:
	               result r3;
                   center();cout<<"***Enter Your Login ID to See you DS result: ";
	               char da[20];
	               cin.ignore();
	               cin.getline(da,20);

	               if(r3.search(da,3))
                    cout<<" ";
                   else
                    cout<<"\n****EITHER YOU HAVE NOT REGISTERED OR YOU HAVE NOT GIVEN TEST";
	               cout<<"\n****PRESS 1 TO CHECK ANOTHER RESULT";
	               cout<<"\n****PRESS 0 TO GO TO MAIN MENU";
	               int q;
	               cin>>q;
	               if(q==1)
                    resultdisplay();
                   else
                   {  system("cls");
                       menu();
                   }
                    break;
        default:
            system("cls");
            menu();

}}







int menu()
{
system("cls");
	do{
     decl();
     decl();
     cout<<endl<<endl;
     center();
	cout<<"WELCOME TO ONLINE EXAMINATION PORTAL\n\n\n";
    decl();
    decl();
     cout<<endl<<endl<<endl<<endl;
     center();
     	cout<<"PRESS 1 FOR NEW REGISTRATION\n\n";
	center();
    cout<<"PRESS 2 FOR LOGIN\n\n";
    center();
	cout<<"PRESS 3 TO SEE YOUR RESULT\n\n";
	center();
	cout<<"PRESS 4 TO GET INFORMATION ABOUT TESTS\n\n";
	center();
	cout<<"PRESS 5 TO KNOW ABOUT US\n\n";
	center();
	cout<<"PRESS 6 TO EXIT\n\n\n";
	center();
	cout<<"ENTER YOUR CHOICE :  ";
	int choice;
	cin>>choice;


{

switch(choice){
	case 1 :
		    system("cls");
		    decl();
		    decl();cout<<"\n\n";
		    center();
	        cout<<"WELCOME TO REGISTRATION PAGE\n\n";
	        decl();
	        decl();
			registration r1;
	        r1.give();
	        r1.store();
	        cout<<"\n\n";
	        center();cout<<"***PRESS ANY KEY TO GO BACK TO MAIN MENU***";
	        if(getch())
	        system("cls");
	        break;
	case 2 :
		system("cls");
		cin.ignore();
		decl();
		decl();
		center();
    label:cout<<"    WELCOME TO LOGIN PAGE\n";decl();decl(); cout<<"\n\n";

		char name1[40],pass1[40],x;
		char a;
		cout<<"\n\n";center();
    	cout<<"Login Id : ";
	    cin.getline(name1,40,'\n');cout<<"\n";center();
	    cout<<"Enter Password :";
        cin.getline(pass1,40);
        registration r2;                                                                           //name1 contains login id
		int r;
		r=r2.login(name1,pass1);
		if(r==1){
                questions(name1);
			 }
		 else{
		 	 abc: cout<<"no found";
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
		        r2.fpass(e);
		        goto label;
				}
                else if(a=='N'||a=='n'){
	   	                cin.ignore();
	   	                center();
                       	cout<<"Login Id : ";
	                    cin.getline(name1,40);
                        cout<<"\n";center(); cout<<"Enter Password :";
                         cin.getline(pass1,40);
                        r=r2.login(name1,pass1);
                        if(r==1){

                        	 questions(name1);
					    	}
					    	else{

					    		goto abc;
							}

						}
				else{
					exit(0);
				}}
		break;
	case 3 :
        system("cls");
		resultdisplay();
	    break;
	case 4 :
		system("cls");
		decl();decl();decl();decl();
	          center();cout<<"THIS PROJECT CONTAIN THREE DIFFERENT TEST\n";
	          center();cout<<"1. C/C++ TEST\n";
	          center();cout<<"2. PYTHON\n";
	          center();cout<<"3. DATA STRUCTURES\n\n\n\n";
	          center();cout<<"TO KNOW FUTHER ABOUT TEST DETAILS ENTER YOUR CHOICE ACCORDING TO ABOVE CHOICES : ";
	          int c;
	          cin>>c;

	          switch(c){
	               case 1 :
                      system("cls");decl();decl();decl();decl();
				      cout<<"C/C++ TEST CONTAIN TEN QUESTIONS.EACH QUESTION CONTAIN 4 MARKS AND\n\n";
					  cout<<"-1 WILL BE DETECTED IF YOU ANSWER WRONG.THESE QUESTIONS ARE BASICALLY\n\n";
					  cout<<"ASKED INTERVEIWS AND IN UNIVERSITIES.THIS TEST CONTAIN MIXTURE OF C/C++.\n\n";
					  cout<<"EACH QUESTION CONTAIN FOUR CHOICES.SYLLABUS OF THIS TEST ARE BASED ON FOLLOWING TOPICS\n\n";
					  cout<<"if-else,for loop,while loop,classes and objects,inheritance of class,constructor,opearor oveloading,\n\n";
					  cout<<"functions,functions overloading,friend function,inline function,abstract classes,\n\n";
					   cout<<"virtual functions,hybird inheritance,mamipulators,preprocessor statements,dynamic memory allocations\n\n\n\n\n";

			  center(); cout<<"Press 1 to go back to main menu\n";
	        center();cout<<" Prees 0 to exit from program: ";
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
			         system("cls");decl();decl();decl();decl();
			        cout<<"PYTHON TEST CONTAIN TEN QUESTIONS.EACH QUESTION CONTAIN 4 MARKS AND\n\n";
					cout<<"-1 WILL BE DETECTED IF YOU ANSWER WRONG.THESE QUESTIONS ARE BASICALLY\n\n";
					cout<<"ASKED INTERVEIWS AND IN UNIVERSITIES.THIS TEST DIFFICULT QUESTIONS OF PYTHON.\n\n";
					cout<<"EACH QUESTION CONTAIN FOUR CHOICES.SYLLABUS OF THIS TEST ARE BASED ON FOLLOWING TOPICS\n\n";
			        cout<<"if-else,control statements,data types,random number,for loops,arthematic operators,bitwise operator\n\n";
                    cout<<"functions,user defined function,recursion,list,tupple,dictionary,string handing,passing th string,\n\n";
                    cout<<"file handling,string-manipultion,unicode strings.\n\n\n\n\n";

                  center();cout<<"Press 1 to go back to main menu";
	        center();cout<<"Press 0 to exit from program: ";
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
                        system("cls");decl();decl();decl();decl();
                   cout<<"DATA STRUCTURE TEST CONTAIN TEN QUESTIONS.EACH QUESTION CONTAIN 4 MARKS AND\n\n";
                   cout<<"-1 WILL BE DETECTED IF YOU ANSWER WRONG.THESE QUESTIONS ARE BASICALLY\n\n";
					cout<<"ASKED INTERVEIWS AND IN UNIVERSITIES.THIS TEST DIFFICULT QUESTIONS OF DATA STRUCTURE.\n\n";
					cout<<"EACH QUESTION CONTAIN FOUR CHOICES.SYLLABUS OF THIS TEST ARE BASED ON FOLLOWING TOPICS\n\n";
			        cout<<"complexcity,linear array,linked list,quick sort,trees,graphs,infix to postfix,queues,dequeues,\n\n";
			        cout<<"tower of hanoi,recursion,sorting,two way linked list.\n\n\n\n\n";

			      center();cout<<"Press 1 to go back to main menu";
	        center();cout<<"Press 0 to exit from program: ";
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
		    system("cls");decl();decl();decl();decl();decl();decl();decl();decl();decl();decl();decl();decl();decl();decl();decl();decl();decl();decl();decl();
            cout<<"\n\n\t\t\t\t\t\t\t\t\t\tTHIS EXAMINATION MODULE IS MANAGED BY CODEREARTH INDIA LIMITED.\n";
			cout<<"\t\t\t\t\t\t\t\t\t\tWE PROVIDE ONE OF THE BEST TECH SOLUTIONS.\n";
			cout<<"\t\t\t\t\t\t\t\t\t\tOUR COMPANY SPANS THE WHOLE WORLD WITH 500+ LOCATIONS.\n";
			cout<<"\t\t\t\t\t\t\t\t\t\tFOR FURTHER ENQUIRIES, VISIT US AT WWW.CODEREARTH.COM\n\n";
			decl();decl();decl();decl();decl();decl();decl();decl();decl();decl();decl();decl();decl();decl();decl();decl();decl();decl();decl();
	        center();cout<<"Press 1 to go back to main menu\n";
	        center();cout<<"Press 0 to exit from program: ";
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
