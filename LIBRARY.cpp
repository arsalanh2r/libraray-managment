#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>
using namespace std;

class Librarian{
	private:
		string librarianName;
		string LibrarianUserName;
		string LibrarianPassword1;
		string LibrarianPassword2;
		string LibrarianPass;
		string LibrarianDOB;
		string newUserName;
		string newLibrarianPass;
		int LibrarianPosition;
		int flag = 1;
		int i;
	public:
		void addLibrarian(Librarian L1) // SignUp Function Of Librarian
		{	
			fstream file;
			file.open("Librarian.txt",ios::app);
			if(file.is_open())
			{
				while(flag==1)
				{
					cout << "\nEnter Name : \n";
					fflush(stdin);
					cin >> L1.librarianName;
					for(i=0;L1.librarianName[i]!='\0';i++)
					{
						if(!((L1.librarianName[i] >= 'a' && L1.librarianName[i] <= 'z' )||(L1.librarianName[i] >='A'&& L1.librarianName[i] <= 'Z')))
						{
							cout << "Please Enter Valid Name : \n";
							flag = 1;
							break;
						}
						else 
							flag = 0;
					}	
				}
				
				cout << "\nEnter Date Of Birth : \n";
				cin >> L1.LibrarianDOB;
				
				flag = 1;
				
				while(flag==1)
				{
					cout << "\nEnter Position : \n";
					cout << "1.Library Head\n";
					cout << "2.Digital Library Manager\n";
					cout << "3.Staff\n";
					fflush(stdin);
					cin >> L1.LibrarianPosition;
					
					if(L1.LibrarianPosition>0&&L1.LibrarianPosition<4)
					{
						flag = 0;
						break;
					}
					else
					{
						cout << "\nEnter Valid Librarian Position :\n";
						flag = 1;
					}
				}
				
				flag = 1;
				while(flag==1)
				{
					cout << "\nEnter Password : \n";
					cin >> L1.LibrarianPassword1;
					cout << "\nConfirm Password : \n";
					cin >> L1.LibrarianPassword2;
					if(L1.LibrarianPassword1==L1.LibrarianPassword2)
					{
						flag = 0;
						break;
					}
					else
					{
						flag = 1;
						cout << "Passwords didn't match\n";
					}
				}
			}
			
			file << L1.librarianName << endl;
			file << L1.LibrarianPassword1 << endl;
			file << L1.LibrarianDOB << endl;
			if(L1.LibrarianPosition==1)
			{
				file << "Library Head" << endl << endl;	
			}
			else if(L1.LibrarianPosition==2)
			{
				file << "Library Manager " << endl << endl;
			}
			else if(L1.LibrarianPosition==3)
			{
				file << "Staff" << endl << endl;
			}
			cout << endl << "Signup successfull!!\n\n";
			system("PAUSE");
			file.close();
		}
		
		void modifyLibrarian(Librarian L) // Used to modify the detail of Librarian
		{			
			int flag=1;
			int choice;
			int i;
			string temp;
			
			ofstream tempFile;
			ifstream file;
			file.open("Librarian.txt");
			tempFile.open("tempFile.txt");
			
			if(file.is_open())
			{
				
				while(flag=1)
				{
					system("CLS");
					cout << "What would you like to modify : \n";
					cout << "1.User Name\n";
					cout << "2.Password\n";
					cout << "3.Exit\n";
					cin >> choice;
							
						if(choice==1)
						{
							cout << "Enter Old Name : \n";
							fflush(stdin);
							cin >> L.librarianName;
							cout << "Enter New Username : \n";
							fflush(stdin);
							cin >> L.newUserName;
							
							while(!file.eof())
							{
								getline(file,temp);
								if(!(L.librarianName==temp)) //Check Whether the old data doesnt transfer in new file
								{
									tempFile << temp << endl;	
								}
								else
								{
									tempFile << L.newUserName << endl;
								}
								
							}
						}
						else if(choice==2)
						{
							cout << "Enter Old Password : \n";
							fflush(stdin);
							cin >> L.LibrarianPass;
							cout << "Enter New Password : \n";
							fflush(stdin);
							cin >> L.newLibrarianPass;
							
							while(!file.eof())
							{
								getline(file,temp);
								if(!(L.LibrarianPass==temp))
								{
									tempFile << temp << endl;	
								}
								else
								{
									tempFile << L.newLibrarianPass << endl;
								}
								
							}
						}
						else if(choice==3)
						{
							exit(1);	
						}
						else
						{
							cout << "Enter Valid Choice : \n";
							flag = 1;
					}
				}
			}
			else
			{
				cout << "File not opened";
			}
			
			file.close();
			tempFile.close();
			remove("Librarian.txt");
			rename("tempFile.txt","Librarian.txt");

		}
		
		int login(Librarian L1)
		{
			string array[200];
			string name,pass;
			int i,flag=1;
		
			fstream file;
			file.open("Librarian.txt");
		
			cout << "\n\n\t\tLOGIN\n\n";
			cout << "Enter User Name : \n";
			cin >> name;
			cout <<"Enter Password : \n";
			cin >> pass;
		
			if(file.is_open())
			{
				for(i=0;i<200;i++)
				{
					getline(file,array[i]); // used to store the data of file in array
				}
				
				for(i=0;i<200;i++)
				{
					if(array[i]==name)
					{
						flag = 0;
						
						if(array[i+1]==pass)
						{
							cout << "Login Successfull!\n";
							system("Pause");
							flag = 0;
							return 1;
							break;
						}
						else
						cout << "Incorrect Password\n";
						return 0;
					}
				}
				
				if(flag==1)
				{
					cout << "Incorrect User name\n";
					return 0;
				}
				
			}
			
			else
			{
				cout << "File Not Opened\n";
			}	
		}
		void IssuedBooks(Librarian L)
		{
			int option = 0;	
			ifstream file;
			file.open("IssueStudent.txt");
			ifstream file2;
			file2.open("IssueTeacher.txt");
			
			if(file.is_open()&&file2.is_open())
			{
				cout << "Enter The Option :\n";
				cout << "1.Student Issue Books\n";
				cout << "2.Teacher Issue Books\n";
				cin >> option;
				if(option==1)
				{
					string ch;
					cout << "Issued Books:\n\n";
					while(getline(file,ch))
					{	
						cout << ch << "\n";
					}	
				}	
				else if(option==2)
				{
					string ch2;
					cout << "Issued Books:\n\n";
					while(getline(file2,ch2))
					{	
						cout << ch2 << "\n";
					}
				}
				else
				{
					cout << "Invalid Input!\n";
				}
			}	
			else
			{
				cout << "File Does Not Exist!\n";
			}  

		}	
};

class User{
	private:
		string UserName;
		string UserPassword1;
		string UserPassword2;
		string UserPass;
		string newUserPass;
		string UserDOB;
		string newUserName;
		int UserPosition;
		int flag = 1;
		int i;
	public:
		void addUser(User U)
		{	
			fstream file;
			file.open("User.txt",ios::app);
			if(file.is_open())
			{
				while(flag==1)
				{
					cout << "\nEnter Name : \n";
					fflush(stdin);
					cin >> U.UserName;
					for(i=0;U.UserName[i]!='\0';i++) //Validation of name
					{
						if(!((U.UserName[i] >= 'a' && U.UserName[i] <= 'z' )||(U.UserName[i] >='A'&& U.UserName[i] <= 'Z')))
						{
							cout << "Please Enter Valid Name : \n";
							flag = 1;
							break;
						}
						else 
							flag = 0;
					}	
				}
				
				cout << "\nEnter Date Of Birth : \n";
				cin >> U.UserDOB;
				
				flag = 1;
				
				while(flag==1)
				{
					cout << "\nEnter Position : \n";
					cout << "1.Student\n";
					cout << "2.Teacher\n";
					fflush(stdin);
					cin >> U.UserPosition;
					
					if(U.UserPosition>0&&U.UserPosition<3)
					{
						flag = 0;
						break;
					}
					else
					{
						cout << "\nEnter Valid Position :\n";
						flag = 1;
					}
				}
				
				flag = 1;
				while(flag==1)
				{
					cout << "\nEnter Password : \n";
					cin >> U.UserPassword1;
					cout << "\nConfirm Password : \n";
					cin >> U.UserPassword2;
					if(U.UserPassword1==U.UserPassword2)
					{
						flag = 0;
						break;
					}
					else
					{
						flag = 1;
						cout << "Passwords didn't match\n";
					}
				}
			}
			
			file << U.UserName << endl;
			file << U.UserPassword1 << endl;
			file << U.UserDOB << endl;
			if(U.UserPosition==1)
			{
				file << "Teacher" << endl << endl;	
			}
			else if(U.UserPosition==2)
			{
				file << "Student" << endl << endl;
			}
			cout << endl << "Signup successfull!!\n\n";
			system("PAUSE");
		}	
		
		void modifyUser(User U)
		{			
			int flag=1;
			int choice;
			int i;
			string temp;
			
			ofstream tempFile;
			ifstream file;
			file.open("User.txt");
			tempFile.open("tempFile.txt");
			
			if(file.is_open())
			{
				
				while(flag=1)
				{
					system("CLS");
					cout << "What would you like to modify : \n";
					cout << "1.User Name\n";
					cout << "2.Password\n";
					cout << "3.Exit\n";
					cin >> choice;
							
						if(choice==1)
						{
							cout << "Enter Old Name : \n";
							fflush(stdin);
							cin >> U.UserName;
							cout << "Enter New Username : \n";
							fflush(stdin);
							cin >> U.newUserName;
							
							while(!file.eof())
							{
								getline(file,temp);
								if(!(U.UserName==temp))
								{
									tempFile << temp << endl;	
								}
								else
								{
									tempFile << U.newUserName << endl;
								}
								
							}
						}
						else if(choice==2)
						{
							cout << "Enter Old Password : \n";
							fflush(stdin);
							cin >> U.UserPass;
							cout << "Enter New Password : \n";
							fflush(stdin);
							cin >> U.newUserPass;
							
							while(!file.eof())
							{
								getline(file,temp);
								if(!(U.UserPass==temp))
								{
									tempFile << temp << endl;	
								}
								else
								{
									tempFile << U.newUserPass << endl;
								}
								
							}
						}
						else if(choice==3)
						{
							exit(1);	
						}
						else
						{
							cout << "Enter Valid Choice : \n";
							flag = 1;
					}
				}
			}
			else
			{
				cout << "File not opened";
			}
			
			file.close();
			tempFile.close();
			remove("Librarian.txt");
			rename("tempFile.txt","Librarian.txt");

		}
		
		int login(User U)
		{
			string array[200];
			string name,pass;
			int i,flag=1;
		
			fstream file;
			file.open("User.txt");
		
			cout << "\n\n\t\tLOGIN\n\n";
			cout << "Enter User Name : \n";
			cin >> name;
			cout <<"Enter Password : \n";
			cin >> pass;
		
			if(file.is_open())
			{
				for(i=0;i<200;i++)
				{
					getline(file,array[i]);
				}
				
				for(i=0;i<200;i++)
				{
					if(array[i]==name)
					{
						flag = 0;
						
						if(array[i+1]==pass)
						{
							cout << "Login Successfull!\n";
							system("Pause");
							flag = 0;
							return 1;
							break;
						}
						else
						cout << "Incorrect Password\n";
						return 0;
					}
				}
				
				if(flag==1)
				{
					cout << "Incorrect User name\n";
					return 0;
				}
				
			}
			
			else
			{
				cout << "File Not Opened\n";
			}	
		}
		
		
};

class Student : public User{

	public:
	void issueBook(Student S1)
	{
		string temp;
		int i=0;
		int flag = 0;
		int value;
		string line;
		string BooksData[500];
		string IssuedData[500];
		string StudentName;
		string Id;
		 
		ifstream file;
		fstream issue;
		ofstream tempFile;
		tempFile.open("temp.txt");
		file.open("Books.txt");
		issue.open("IssueStudent.txt",ios::in|ios::out); // issue file to write the data of student or teacher
		
			cout << "Enter Book Name :\n";
			fflush(stdin);
			getline(cin,temp);
			
			cout << "Enter Student Name :\n";
			fflush(stdin);
			getline(cin,StudentName);
			
			cout <<"Enter Student Id : \n";
			fflush(stdin);
			getline(cin,Id);
			
			while(!file.eof())
			{
				getline(file,BooksData[i]); 
				i++;
			}
			
			while(!issue.eof())
			{
				getline(issue,IssuedData[i]);
				i++;
			}
			
			for(i=0;i<500;i++)
			{
				if(temp==IssuedData[i]) //array1 has data of issue file
				{
					if(StudentName==IssuedData[i+1]) //check whether the student has already issued the book
					{
						cout << "You Have Already Issued The Book\n";
						flag = 1;
						break;
					}
				}		
			}	
				 
					if(flag!=1) // would only run if the student has not issued the book
					{
						issue << StudentName << endl;  // write data to file
						issue << temp << endl ;
						issue << Id << endl;
						issue << "Student" << endl << endl;

						for(i=0;i<140;i++)
						{
							if(temp==BooksData[i])
							{
								char cstr[1]; // a temporary variable to copy data of array into cstr.
								line = BooksData[i+7]; // line has the value of line used for later
								BooksData[i+7].copy(cstr,1); // function use to copy data in another variable
								value = atoi(cstr); // a built in function to convert string data into integer
								value = value - 1;	// the converted integer is then used for calculation
							}
						}
					}
					
					for(i=0;i<140;i++)
					{
						if(!(line==BooksData[i])) // if the array does not match the quantity of books then it will wrte data in another file 
						{
							tempFile << BooksData[i] << endl;
						}
						else
						{
							if(value==0)  // if the quantity of books becomes 0 an message of "Books Have Fininshed" would be written to file 
							{
								tempFile << "Books Stock Have Finished!!" << endl;	
							}
							else
							{
								tempFile << value << endl; 
							}
						}
					}
										
			tempFile.close();
			issue.close();
			file.close();
			remove("Books.txt");
			rename("temp.txt","Books.txt");
			
	}
	
};

class Teacher : public User{
	
	public:
		void issueBook(Teacher T1)
		{
		int i=0;
		int flag = 0;
		int value;
		string line;
		string BooksData[500];
		string IssuedData[500];
		string TeacherName;
		string BookName;
		 
		ifstream file;
		fstream issue;
		ofstream tempFile;
		tempFile.open("temp.txt");
		file.open("Books.txt");
		issue.open("IssueTeacher.txt",ios::app);
		
			cout << "Enter Book Name :\n";
			fflush(stdin);
			getline(cin,BookName);
			
			cout << "Enter Teacher Name :\n";
			fflush(stdin);
			getline(cin,TeacherName);
			
			while(!file.eof())
			{
				getline(file,BooksData[i]);
				i++;
			}
			
			while(!issue.eof())
			{
				getline(issue,IssuedData[i]);
				i++;
			}
			
			for(i=0;i<500;i++)
			{
				if(BookName==IssuedData[i])
				{
					if(TeacherName==IssuedData[i+1])
					{
						cout << "You Have Already Issued The Book\n";
						flag = 1;
						break;
					}
				}		
			}	
				 
					if(flag!=1)
					{
						issue << TeacherName << endl;
						issue << BookName << endl;
						issue << "Teacher" << endl << endl;

						for(i=0;i<140;i++)
						{
							if(BookName==BooksData[i])
							{
								char cstr[1];
								line = BooksData[i+7];
								BooksData[i+7].copy(cstr,1);
								value = atoi(cstr);
								value = value - 1;	
							}
						}
					}
					
					for(i=0;i<140;i++)
					{
						if(!(line==BooksData[i]))
						{
							tempFile << BooksData[i] << endl;
						}
						else
						{
							if(value==0)
							{
								tempFile << "Books Stock Have Finished!!" << endl;	
							}
							else
							{
								tempFile << value << endl; 
							}
						}
					}
										
			tempFile.close();
			issue.close();
			file.close();
			remove("Books.txt");
			rename("temp.txt","Books.txt");
			
	}
	
};


class Book{
	private:
		string bookName;
		string bookAuthor;
		string keyword;
		int bookOption;
		
	public:
		void showBook(Book B)
		{
			fstream my_file;
			my_file.open("Books.txt");
			
			cout << "Enter the type of choice : \n";
			cout << "1.Search All Books\n";
			cout << "2.Search Book By Author Name\n";
			cout << "3.Search Book By Book Name\n";
			cout << "4.Search Book By Keyword\n";
			cin >> bookOption;
			
			if(bookOption==1)
			{
				if(my_file==NULL)
				{
					cout << "File Not Opened\n";
				}
				else
				{
					string ch;
					while(getline(my_file,ch)) // used to print the whole books file
					{	
						cout << ch << "\n";
					}
				}
				
				my_file.close();	
			} 
			else if(bookOption==2)
			{
				string AuthorName;
				int i,n=0;
				string BooksData[300];
				
				if(my_file.is_open())
				{	
					for(i=0;i<130;i++)
					{
						getline(my_file,BooksData[i]); //array used to store the books data
					}
					
					cout << "Enter Author Name : \n";
					fflush(stdin);
					getline(cin,AuthorName);
					
					for(i=2;i<130;i=i+11)
					{
						if(AuthorName==BooksData[i]) // if the author matches the user input htne print detail accordingly
						{
							cout << endl << "Book Details : " <<endl;
							cout << "Name : " << BooksData[i-2] <<endl;
							cout << "Description : " << BooksData[i-1] <<endl;
							cout << "Author : " << BooksData[i] <<endl;
							cout << "Genre : " << BooksData[i+1] <<endl;
							cout << "Pages : " << BooksData[i+2] <<endl;
							cout << "Price : " << BooksData[i+3] <<endl;
							cout << "Publisher : " << BooksData[i+4] <<endl;
							cout << "Quantity : " << BooksData[i+5] <<endl;
							cout << "Serial Number : " << BooksData[i+6] <<endl;
							cout << "ISBN Number : " << BooksData[i+7] <<endl;
							n=1; // n used to check whether the author is available or not
						}
					}
					if(n==0)
					{
						cout << "\nThe Author " << AuthorName << " is not available!\n";
					}
				}
				else 
					cout << "File Not Opened";
					
				my_file.close();				
			}
			else if(bookOption==3)
			{
				string BookName;
				int i,n=0;
				string BooksData[300];
								
				if(my_file.is_open())
				{	
					for(i=0;i<130;i++)
					{
						getline(my_file,BooksData[i]);
					}
					
					cout << "Enter Book Name : \n";
					fflush(stdin);
					getline(cin,BookName);
					
					for(i=0;i<130;i=i+11)
					{
						if(BookName==BooksData[i])
						{
							cout << endl << "Book Details : " <<endl;
							cout << "Name : " << BooksData[i] <<endl;
							cout << "Description : " << BooksData[i+1] <<endl;
							cout << "Author : " << BooksData[i+2] <<endl;
							cout << "Genre : " << BooksData[i+3] <<endl;
							cout << "Pages : " << BooksData[i+4] <<endl;
							cout << "Price : " << BooksData[i+5] <<endl;
							cout << "Publisher : " << BooksData[i+6] <<endl;
							cout << "Quantity : " << BooksData[i+7] <<endl;
							cout << "Serial Number : " << BooksData[i+8] <<endl;
							cout << "ISBN Number : " << BooksData[i+9] <<endl;
							n=1;
						}
					}
					if(n==0)
					{
						cout << "\nThe book " << BookName << " is not available!\n";
					}
				}
				else 
					cout << "File Not Opened";
					
				my_file.close();
			}
			
			else if(bookOption==4)
			{
				string Genre;
				int i,n=0;
				string BooksData[300];
								
				if(my_file.is_open())
				{	
					for(i=0;i<130;i++)
					{
						getline(my_file,BooksData[i]);
					}
					
					cout << "Enter Genre : \n";
					fflush(stdin);
					getline(cin,Genre);
					
					for(i=3;i<130;i=i+11)
					{
						if(Genre==BooksData[i])
						{
							cout << endl << "Book Details : " <<endl;
							cout << "Name : " << BooksData[i-3] <<endl;
							cout << "Description : " << BooksData[i-2] <<endl;
							cout << "Author : " << BooksData[i-1] <<endl;
							cout << "Genre : " << BooksData[i] <<endl;
							cout << "Pages : " << BooksData[i+1] <<endl;
							cout << "Price : " << BooksData[i+2] <<endl;
							cout << "Publisher : " << BooksData[i+3] <<endl;
							cout << "Quantity : " << BooksData[i+4] <<endl;
							cout << "Serial Number : " << BooksData[i+5] <<endl;
							cout << "ISBN Number : " << BooksData[i+6] <<endl;
							n=1;
						}
					}
					if(n==0)
					{
						cout << "\nThe Genre " << Genre << " is not available!\n";
					}
				}
				else 
					cout << "File Not Opened";
					
				my_file.close();	
			}
		}
		void addBook(Book B) // function to add a new book
		{
			
			fstream my_file;
			my_file.open("Books.ate");
			
			char BookName[100];
			char desc[100];
			char Author[50];
			char genre[20];
			char pub[20];
			double price;
			int quan;
			double serNo;
			double isbn;
			
			cout << "Enter details to add book : \n\n";
			cout << "Book Name : \n";
			cin.getline(BookName,100);
			cout << "Desciption : \n";
			fflush(stdin);
			cin.getline(desc,100);
			cout << "Author Name : \n";
			fflush(stdin);
			cin.getline(Author,50);
			cout << "Genre : \n";
			fflush(stdin);
			cin.getline(genre,20);
			cout << "Price : \n";
			fflush(stdin);
			cin >> price;
			cout << "Publisher Name : \n";
			fflush(stdin);
			cin.getline(pub,20);
			cout << "Quantity : \n";
			fflush(stdin);
			cin >> quan;
			cout << "Serial Nummber : \n";
			fflush(stdin);
			cin >> serNo;
			cout << "ISBN Number : \n";
			fflush(stdin);
			cin >> isbn;
			
			if(my_file==NULL)
			{
				cout << "File not opened\n";
			}
			else
			{
				if(my_file.is_open())
				{
					my_file << BookName << endl;
					my_file << desc << endl;
					my_file << Author << endl;
					my_file << genre << endl;
					my_file << price << endl;
					my_file << pub << endl;
					my_file << quan << endl;
					my_file << serNo << endl;
					my_file << isbn << endl << endl;
				}	
			}
			
			my_file.close();
			
		}
		
		void modifyBook(Book B) // fucntion to update the detail of books
		{
			int option;
			int i;
			string array[250];
			string temp;
			string line;
			string newAuthor;
			string newPrice;
			string newSerno;
			string ok;
			
			ifstream my_file;
			ofstream tempFile;
			my_file.open("Books.txt");
			tempFile.open("tempFile.txt");
			
			if(my_file.is_open())
			{
				cout << "Enter Option : \n";
				cout << "1.Book New Author : \n";
				cout << "2.Book New Price : \n";
				cout << "3.Book New Serial Number : \n";
				cin >> option;
				
				if(option==1)
				{
					cout << "Enter Author Name To Modify :";
					fflush(stdin);
					getline(cin,ok);
					cout << "Enter new Author Name :";
					fflush(stdin);
					getline(cin,newAuthor);  
					while(!my_file.eof())
					{
						getline(my_file,line);
						if(!(line==ok))
						{
							tempFile << line << endl;
						}
						else
						{
							tempFile << newAuthor << endl;
						}
					}
				}
			}
			else
			{
				cout << "File not opened";
			}
			
			my_file.close();
			tempFile.close();
			remove("Books.txt");
			rename("tempfile.txt","Books.txt");
		}
			
		void deleteBook(Book B)
		{
			int i;
			string deleteLine;
			string array[130];
			ifstream my_file;
			ofstream temp;
			my_file.open("Books.txt");
			temp.open("tempfile.txt");

			if(!my_file.is_open())
			{
				cout << "Input file failed to open\n";	
			}
			
			for(i=0;i<130;i++)
			{
				getline(my_file,array[i]);
			}
			
				cout << "Enter Book Name To Delete : \n";
				fflush(stdin);
				getline(cin,deleteLine);
				
				for(i=0;i<130;i++)
				{
					if(!(deleteLine==array[i]))
					{
						temp << array[i] << endl;
					}
					else
					{
						i = i + 10;					
					}
				}
				
				cout << "Book Deleted Successfully!\n";				
				
			my_file.close();
			temp.close();
			remove("Books.txt");
			rename("tempfile.txt","Books.txt");
		}
	
};

void LibMenu2()
{
	Librarian L[100];
	int k = 0;
	Book B[100];
	int j = 0;
	int flag=1,option;
	
	
		cout << "\n\n";
		cout << "\t1.Modify Librarian\n";
		cout << "\t2.View Booklist\n";
		cout << "\t3.View Issued Books\n";
		cout << "\t4.Add Books\n";
		cout << "\t5.Delete Books\n";
		cout << "\t6.Modify Books\n";
		cout << "\t7.Exit\n\n";
		
		fflush(stdin);
		cin >> option;
		
		while(flag==1)
		{
			if(option==1)
			{
				system("cls");
				L[k].modifyLibrarian(L[k]);
				system("Pause");
				system("cls");
				LibMenu2(); 
				flag = 0;
				k++;
			}	
			else if(option==2)
			{
				system("cls");
				B[j].showBook(B[j]);
				system("Pause");
				system("cls");
				LibMenu2();
				flag = 0;
				j++;	
			}
			else if(option==3)
			{
				system("cls");
				L[k].IssuedBooks(L[k]);
				system("Pause");
				system("cls");
				LibMenu2(); 
				flag = 0;
				k++;
			}
			else if(option==4)
			{
				system("cls");
				B[j].addBook(B[j]);
				flag = 0;
				system("cls");
				LibMenu2();
				j++;
			}
			else if(option==5)
			{
				system("cls");
				B[j].deleteBook(B[j]);
				flag = 0;
				system("cls");
				LibMenu2();
				j++;
			}
			else if(option==6)
			{
				system("cls");
				B[j].modifyBook(B[j]);
				flag = 0;
				system("cls");
				LibMenu2();
				j++;
			}
			else if(option==7)
			{
				exit(1);
			}
			else
			{
				cout << "Invalid Input";
				flag = 1;
			}
		}
}
	

void LibMenu()
{
	Librarian L[100];
	int k = 0;
	int flag = 1;
	int option;
	
	while(flag==1)
	{
		system("CLS");
		cout << "\t\t\nChoose the option:\n";
		cout << "\t1.SignUp\n";
		cout << "\t2.Login\n";
		cout << "\t3.Exit\n\n";
		
		cin >> option;
		
		if(option==1)
		{
			system("cls");
			L[k].addLibrarian(L[k]);
			flag = 1;
			k++;
		}
		else if(option==2)
		{
			system("cls");
			if(L[k].login(L[k])==1)
			{
				system("ClS");
				LibMenu2();	
			}
			flag = 1;
			k++;
		}
		else if(option==3)
		{
			exit(1);
		}
		else
		{
			cout << "Invalid Input";
			flag = 1;
		}
		
	}
}

void UserMenu2()
{
	Student S[100];
	int k = 0;
	Book B[100];
	int j = 0;
	int flag=1,option;
	
	
		cout << "\n\n";
		cout << "\t1.Modify User\n";
		cout << "\t2.View Booklist\n";
		cout << "\t3.Issue Book\n";
		cout << "\t4.Exit\n\n";
		
		fflush(stdin);
		cin >> option;
		
		while(flag==1)
		{
			if(option==1)
			{
				system("cls");
				S[k].modifyUser(S[k]);
				system("Pause");
				system("cls");
				UserMenu2();
				flag = 0;
				k++;
			}	
			else if(option==2)
			{
				system("cls");
				B[j].showBook(B[j]);
				system("Pause");
				system("cls");
				UserMenu2();
				flag = 0;
				j++;	
			}
			else if(option==3)
			{
				system("cls");
				S[k].issueBook(S[k]);
				system("Pause");
				system("cls");
				UserMenu2();
				flag = 0;
				k++;
			}
			else if(option==4)
			{
				exit(1);
			}
			else
			{
				cout << "Invalid Input";
				flag = 1;
			}
		}
}
void UserMenu1()
{
	Teacher T[100];
	int k = 0;
	Book B[100];
	int j = 0;
	int flag=1,option;
	
	
		cout << "\n\n";
		cout << "\t1.Modify User\n";
		cout << "\t2.View Booklist\n";
		cout << "\t3.Issue Book\n";
		cout << "\t4.Exit\n\n";
		
		fflush(stdin);
		cin >> option;
		
		while(flag==1)
		{
			if(option==1)
			{
				system("cls");
				T[k].modifyUser(T[k]);
				system("Pause");
				system("cls");
				UserMenu1();
				flag = 0;
				k++;
			}	
			else if(option==2)
			{
				system("cls");
				B[j].showBook(B[j]);
				system("Pause");
				system("cls");
				UserMenu1();
				flag = 0;
				j++;	
			}
			else if(option==3)
			{
				system("cls");
				T[k].issueBook(T[k]);
				system("Pause");
				system("cls");
				UserMenu1();
				flag = 0;
				k++;
			}
			else if(option==4)
			{
				exit(1);
			}
			else
			{
				cout << "Invalid Input";
				flag = 1;
			}
		}	
}

void TeaMenu()
{
	Teacher T[100];
	int k = 0;
	int flag = 1;
	int option;
	
	while(flag==1)
	{
		system("CLS");
		cout << "\t\t\nChoose the option:\n";
		cout << "\t1.SignUp\n";
		cout << "\t2.Login\n";
		cout << "\t3.Exit\n\n";
		
		cin >> option;
		
		if(option==1)
		{
			system("cls");
			T[k].addUser(T[k]);
			system("pause");
			flag = 1;
			k++;
		}
		else if(option==2)
		{
			system("cls");
			if(T[k].login(T[k])==1)
			{
				system("ClS");
				UserMenu1();
				system("pause");	
			}
			flag = 1;
			k++;
		}
		else if(option==3)
		{
			exit(1);
		}
		else
		{
			cout << "Invalid Input";
			flag = 1;
		}
		
	}
}

void StuMenu()
{
	Student S[100];
	int k = 0;
	int flag = 1;
	int option;
	
	while(flag==1)
	{
		system("CLS");
		cout << "\t\t\nChoose the option:\n";
		cout << "\t1.SignUp\n";
		cout << "\t2.Login\n";
		cout << "\t3.Exit\n\n";
		
		cin >> option;
		
		if(option==1)
		{
			system("cls");
			S[k].addUser(S[k]);
			system("pause");
			flag = 1;
			k++;
		}
		else if(option==2)
		{
			system("cls");
			if(S[k].login(S[k])==1)
			{
				system("ClS");
				UserMenu2();
				system("pause");	
			}
			flag = 1;
			k++;
		}
		else if(option==3)
		{
			exit(1);
		}
		else
		{
			cout << "Invalid Input";
			flag = 1;
		}
	}
}


int menu()
{
	int option;
	int flag = 1;

	while(flag==1)
	{	
		cout << "\n\n\t\t\t*****LIBRARY MANAGEMENT SYSTEM*****\n\n";
		cout << "\tChoose the option : \n\n";
		cout << "\t1.Librarian\n";
		cout << "\t2.Student\n";
		cout << "\t3.Teacher\n";
		cout << "\t4.Exit\n\n";
		
		cin >> option;
		
		if(option==1)
		{
			system("CLS");
			system("color 30");
			LibMenu();
		}
		else if(option==2)
		{
			system("CLS");
			system("color 70");
			StuMenu();
		}
		else if(option==3)
		{
			system("CLS");
			system("color 70");
			TeaMenu();	
		}
		else if(option==4)
		{
			exit(1);
		}
		else if(option > 4)
		{
			cout << "Invalid Option!!!\n";
			cout << "Enter Again\n\n";
			system("Pause");
			system("CLS");
			menu();
		}
	}
}


int main(){
	
	system("color F4");
	menu();
}
	
