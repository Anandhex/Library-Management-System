#include<iostream>
#include<fstream>
#include<string.h>
#include<iomanip>
#include<ctime>
#include<conio.h>
int date1;
int mon1;
void line();
void date(int &a,int&b){
	time_t now=time(0);
	tm *ltm =localtime(&now);
	a = ltm->tm_mday;
	b = ltm->tm_mon+1;
}
using namespace std;
class book{
	int count;
	protected:
	char bname[30];
	char author[30];
	int bookid;
	char category[20];
	public:
		book();
		void addbook();
		int searchbook(char* input);
		int searchbook(int id);
		void display();
		int delbook(int x);
}b;
class issual:public book{
	int ref;
	char stdid[30];
	char stdname[30];
	int date;
	int mon;
	public:
		void issue();
		void returnbook();
		friend void issuedbooks();
		void delbook1(int x);
}i;
book::book(){
	count=1000;
	ifstream file("book.txt");
	while(file >>bookid>> bname>>author>>category){
		
	}
	count=bookid+1;
}
int book::searchbook(int id){
	int k=0;
		ifstream file("book.txt");
		
	while(file >>bookid>> bname>>author>>category){
		if(id==bookid){
			cout<<bookid<<' '<<bname<<' '<<author<<' '<<category<<endl;
			k++;
		}
	}
	if(k==0){
		cout<<"No such book with the required id present\n";
		return 1;
	}
	return 0;
}
int check(char *s){
	int i=0;
	while(s[i]!='\0'){
		if(!isalpha(s[i])){
			return 1;
		}
		i++;
	}
	return 0;
}
void book::addbook(){
	ab:ofstream file("book.txt",ios::app);
	char ch;
	bookid=count;
	cout<<"enter the details of the book\n";
	cout<<"Book id of the book :";
	cout<<bookid;
	cout<<"\n";
	cout<<"Enter the bookname:";
	cin>>bname;
	cout<<"\n";
	cout<<"Enter the author:";
	ea:cin>>author;
	if(check(author)){
		cout<<"Invalid enter again\n";
		goto ea;
	}
	cout<<"\n";
	cout<<"Enter the category:";
	ca:cin>>category;
	if(check(category)){
		cout<<"Invalid enter again\n";
		goto ca;
	}
	cout<<"\n";
	file <<bookid<<' '<<bname<<' '<<author<<' '<<category<<endl;
	count++;
	getch();
	system("cls");
	cout<<"Do you want to add another book: Y to add and N to go to Main menu\n";
	cab:cin>>ch;
	ch=toupper(ch);
	if(ch=='Y'||ch=='N'){
		if(ch=='Y'){
			goto ab;
		}
	}else{
		cout<<"invalid input\nEnter again:\n";
		goto cab;
	}
}
int book::searchbook(char* input){
int k=0;
		ifstream file("book.txt");
		cout<<setw(49)<<"BOOK'S UNDER THE CATEGORY ARE:\n";
		line();
		cout<<setw(15)<<"bookid"<<setw(30)<<"bookname"<<setw(15)<<"author"<<endl;
	line();
	while(file >>bookid>> bname>>author>>category){
		if(strcmp(input,category)==0){
			cout<<setw(15)<<bookid<<setw(30)<<bname<<setw(15)<<author<<endl;
			k++;
		}
	}
	line();
	if(k==0){
		cout<<"Book belonging to this category dosen't exits\n";
		getch();
		return 1;
	}
	getch();
	return 0;
}
int book::delbook(int x){	
	int c1,c2=0;
	int n;
	n=x;
	fstream in("book.txt",ios::in|ios::out);
	fstream op("Temp.txt",ios::out);
	in.seekp(0,ios::beg);
	while(in>>bookid>>bname>>author>>category)
	{    c1++;
		if(bookid!=n)  
		{
			op<<bookid<<' '<<bname<<' '<<author<<' '<<category<<endl;
			c2++;
		}
	}
	if(c1!=c2){
	in.close();
	op.close();
	remove("book.txt");
	rename("Temp.txt","book.txt");
    }
    else{
    	cout<<"The book with book id "<<n<<" dosen't exits\n"; 
    	return 1;
	}
	return 0;
}
void issual::delbook1(int x){	
	int c1,c2=0;
	int n;
	n=x;
	fstream in("issued.txt",ios::in|ios::out);
	fstream op("peek.txt",ios::out);
	in.seekp(0,ios::beg);
	while(in>>bookid>>bname>>author>>category>>stdid>>stdname>>date>>mon)
	{    c1++;
		if(bookid!=n)  
		{
			op<<bookid<<' '<<bname<<' '<<author<<' '<<category<<' '<<stdid<<' '<<stdname<<' '<<date<<' '<<mon<<endl;
			c2++;
		}
	}
	if(c1!=c2){
	in.close();
	op.close();
	remove("issued.txt");
	rename("peek.txt","issued.txt");
    }
    else{
    	cout<<"The book with book id "<<n<<" dosen't exits\n"; 
	}
}
void line(){
	for(int i=1;i<61;i++)
		cout<<"--";
		cout<<"\n";
	
}
void book::display(){
		ifstream file("book.txt");
		system("cls");
		cout<<setw(49)<<"BOOK'S\n";
		line();
		cout<<setw(15)<<"bookid"<<setw(30)<<"bookname"<<setw(15)<<"author"<<setw(15)<<"category"<<endl;
	line();
	while(file >>bookid>> bname>>author>>category){
		cout<<setw(15)<<bookid<<setw(30)<<bname<<setw(15)<<author<<setw(15)<<category<<endl;	
	}
	line();
}
void issual::issue(){
	iss:ifstream in("ref.txt");
	int a,b;	char ch;
	ofstream issual("issued.txt",ios::app);
	ifstream book("book.txt");	
	int n,flag=0,count=0;
	cout<<"enter the book id of the book to be issued\n";
	cin>>n;
	while(in>>ref){
		if(n==ref){
			cout<<"book cant be isssued only for reference\n";		
			goto ise;
		}
		}	
	while(book >>bookid>> bname>>author>>category){
		if(n==bookid){
			count=1;
			cout<<"enter the student id:\n";
			cin>>stdid;
			cout<<"enter the studentname:\n";
			cin>>stdname;
	    	date=date1;
	    	mon=mon1;
			issual<<bookid<<' '<<bname<<' '<<author<<' '<<category<<' '<<stdid<<' '<<stdname<<' '<<date<<' '<<mon<<endl;
			cout<<"The book "<<bname<<" is issued"<<" to the student "<<stdname<<endl;
			book.close();
			in.close();
			issual.close();
			delbook(n);
			break;
		}
	}
		
		if(flag==1||count==0){
			cout<<"book with "<<n<<" id not present\n";
		}
		getch();
		system("cls");
		ise:cout<<"Do you want to issue another book?Y to issue or N to go to Main menu\n";
		cin>>ch;
		ch=toupper(ch);
		book.close();
		issual.close();
		in.close();
		if(ch=='Y'||ch=='N'){
			if(ch=='Y'){
				goto iss;
			}
		}
	}
void issual::returnbook(){
	iss:int k,flag=0;// made cahnges to return boook but didnt verify with the output simple
	int bid;
	char bn[20],auth[20],cat[20];
	ifstream file("issued.txt");
	cout<<"enter the book id of the book to be returned:\n";
	cin>>k;
	while(file>>bookid>>bname>>author>>category>>stdid>>stdname>>date>>mon){
		bid=bookid;
		strcpy(bn,bname);	
		strcpy(auth,author);
		strcpy(cat,category);
		if(k==bookid){
				file.close();
				delbook1(k);
		    ifstream in("book.txt");
		    ofstream out("temp.txt");
		    while(in>>bookid>>bname>>author>>category){
		    	out<<bookid<<' '<<bname<<' '<<author<<' '<<category<<endl;
				if(bookid==bid-1){
		    		out<<bid<<' '<<bn<<' '<<auth<<' '<<cat<<endl;
				}
			}
			in.close();
			out.close();
			remove("book.txt");
			rename("temp.txt","book.txt");
			flag=1;
			break;
		}
	}
	if(flag==0){
		cout<<"incorect inforamtion\n";
	}
	if(flag==1){
		int fine=0;
		if(mon<mon1){
			fine=date;
			cout<<date;
		}
		if(date>date1+10){
			fine=fine+(date+15-date1);
		}
		if(fine>0){
	cout<<"fine is :"<<fine<<endl;
	}
	else{
		cout<<"book returned\n";
	}}
	getch();
	system("cls");
	cout<<"Do you want to return another book? Y to proceed or N to main menu.\n";
		char ch;
		cin>>ch;
		ch=toupper(ch);
		file.close();
		if(ch=='Y'||ch=='N'){
			if(ch=='Y'){
				goto iss;
			}
		}
}	
void issuedbooks(){
	ifstream file("issued.txt");
	cout<<setw(49)<<"BOOK'S	 ISSUED:\n";
		line();
		cout<<setw(15)<<"bookid"<<setw(30)<<"bookname"<<setw(15)<<"author"<<setw(15)<<"category"<<setw(15)<<"student_id"<<setw(15)<<"student_name"<<setw(15)<<"date"<<endl;
	line();
	while(file >>i.bookid>>i.bname>>i.author>>i.category>>i.stdid>>i.stdname>>i.date>>i.mon){
		cout<<setw(15)<<i.bookid<<setw(30)<<i.bname<<setw(15)<<i.author<<setw(15)<<i.category<<setw(15)<<i.stdid<<setw(15)<<i.stdname<<setw(15)<<i.date<<":"<<i.mon<<":2018"<<endl;	
	}
	line();
}	
int main(){
	char get[30];
	int x=1;
	int ch;
	char choice;
	date(date1,mon1);
	while(x){
	menu : system("cls");
	cout<<setw(25)<<"MAIN MENU\n";
	cout<<"1.To add a book\n";
	cout<<"2.To delete a book\n";
	cout<<"3.To searchbook by category\n";
	cout<<"4.To searchbook by book_id\n";
	cout<<"5.To display all the books present in library\n";
	cout<<"6.For Issual of book\n";
	cout<<"7.For Issued books\n";
	cout<<"8.For Return of book\n";
	cout<<"9.To exit\n";
	cin>>ch;
	system("cls");
	switch(ch){
		case 1:i.addbook();
		       break;
		case 2:cde:cout<<"enter the book id to be deleted:\n";
			   cin>>x;		
			   if(!i.delbook(x)){
			   	cout<<"Book Deleted ..\n";
			   }
			   getch();
			   system("cls");
			   cout<<"Do you want to delte another book?Y to delete or N to go to Main menu\n";
			   ccd:cin>>choice;
		       choice=toupper(choice);
			   	if(choice=='Y'||choice=='N'){
			   		if(choice=='Y'){
			   			goto cde;
					   }
				   }else{
				   	cout<<"Invalid input\nEnter again:\n";
				   	goto ccd;
				   }
			   break;
		case 3:cs:cout<<"enter the category of book to be found:\n";
			   cin>>get;
			   if(i.searchbook(get)){
			   	getch();
			   	system("cls");
			   	cout<<"Do you want to search for another category?:Y to procced or N to go to Main menu\n";
			   	cc:cin>>choice;
			   	val1:choice=toupper(choice);
			   	if(choice=='Y'||choice=='N'){
			   		if(choice=='Y'){
			   			goto cs;
					   }
				   }else{
				   	cout<<"Invalid input\nEnter again:\n";
				   	goto cc;
				   }
			   }else{
			   system("cls");
			   cout<<"Do you want to search for another book?:Y to procced or N to go to Main menu\n";
			   	cin>>choice;
			   	goto val1;
			   }
			   break;
		case 4:cis:cout<<"Enter the book id to be found:\n";
			   cin>>x;
			   if(i.searchbook(x)){
			   	getch();
			   	system("cls");
				cout<<"Do you want to search for another book?:Y to procced or N to go to Main menu\n";
			   	cic:cin>>choice;
			   	val:choice=toupper(choice);
			   	if(choice=='Y'||choice=='N'){
			   		if(choice=='Y'){
			   			goto cis;
					   }
				   }else{
				   	cout<<"Invalid input\nEnter again:\n";
				   	goto cic;
				   }
			   }else{
			   system("cls");
			   cout<<"Do you want to search for another book?:Y to procced or N to go to Main menu\n";
			   	cin>>choice;
			   	goto val;
			   }
			   break;		          
		case 5:cout<<"The books present in the library are:\n";
		       i.display();
			   break;
		case 6:i.issue();	
			   break;
		case 7:issuedbooks();
			   break;		   	   
		case 8:i.returnbook();
				break;	
		case 9:cout<<"\n\n\n\n\t\t\t\t\t Thankyou";
				exit(0);
				break;		   
		default:cout<<"Invalid option enter again\n";	   	   	   
	}
getch();
}
}
