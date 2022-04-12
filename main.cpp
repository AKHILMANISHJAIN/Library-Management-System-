#include<bits/stdc++.h>
using namespace std;
class user{
    public:
    string username;
    string password;
    void reg_login();
    void display_books();
    void login();
    //void reg();
    void search();
    vector<vector<string>> view_issued_books(string username);
};
class student:public user{
    public:
    int fine;
    vector<vector<string>>issued_books;
    void request_book(string username);
    int fine_calc(string username);
    void return_book(string username);
    string show_due_date(string timestamp);
    void student_main_menu(string username);
};
class professor:public user{
    public:
    int fine;
    vector<vector<string>>issued_books;
    void request_book(string username);
    int calc_fine(string username);
    void return_book(string username);
    string show_due_date(string timestamp);
    void prof_main_menu(string username);
};
class librarian:public user{
    public:
    void update_user();
    void update_book();
    void add_user(int k);
    void add_book();
    void delete_user(int k);
    void delete_book();
    void all_users();
    void issued_books();
    void show_fine();
    void librarian_main_menu(string username);
    void clear_fine_amount();
};
class books{
    public:
    string title;
    string author;
    string isbn;
    string publication;
    string quantity;
    vector<string> search_book(string book_name);
};
void librarian::add_user(int k){
    string username,password;
    fstream fout;
    cout<<"Enter username : ";
    cin>>username;
    cout<<"\nEnter password : ";
    cin>>password;
    if(k==1){
    fout.open("students.csv",ios::out | ios::app);
    fout<<username<<","<<password<<"\n";
    }
    else if(k==2){
    fout.open("professors.csv",ios::out | ios::app);
    fout<<username<<","<<password<<"\n";
    }
    else if(k==3){
    fout.open("librarian.csv",ios::out | ios::app);
    fout<<username<<","<<password<<"\n";
    }
}
void librarian::delete_user(int k){
    string username,password;
    cout<<"Enter the username of the user to be deleted : ";
    cin>>username; 
    cout<<"Enter the password of the user to be deleted : ";
    cin>>password;
    cout<<endl;
    vector<vector<string>> content;
    vector<string> row;
	string line, word;
    fstream fin;
    if(k==1){
	fin.open("students.csv", ios::in);
	if(fin.is_open())
	{
		while(getline(fin, line))
		{
			row.clear();
 
			stringstream str(line);
 
			while(getline(str, word, ','))
				row.push_back(word);
			content.push_back(row);
		}
	}
    int count=0;
	for(int i=0;i<content.size();i++)
	{
		if(content[i][0]==username && content[i][1]==password){
            content.erase(content.begin()+i);
            count=1;
            break;
		}
	}
    if(count==0)
    cout<<"Incorrect Credentials"<<endl;
    else{
        fstream fout;
        fout.open("studentsnew.csv",ios::out);
        cout<<"User "<<username<<" is deleted successfully"<<endl;
        for(int i=0;i<content.size();i++){
            for(int j=0;j<content[i].size();j++){
                if(j==0){
                fout<<content[i][j];
                }
                else{
                fout<<","<<content[i][j];
                }
            }
            fout<<"\n";
       }
       fout.close();
    }
       fin.close();
       if(count==1){
       remove("students.csv");
       rename("studentsnew.csv","students.csv");
       }
  }
  else if(k==2){
	fin.open("professors.csv", ios::in);
	if(fin.is_open())
	{
		while(getline(fin, line))
		{
			row.clear();
 
			stringstream str(line);
 
			while(getline(str, word, ','))
				row.push_back(word);
			content.push_back(row);
		}
	}
    int count=0;
	for(int i=0;i<content.size();i++)
	{
		if(content[i][0]==username){
            content.erase(content.begin()+i);
            count=1;
            break;
		}
	}
    if(count==0)
    cout<<"Record of "<<username<<"not found"<<endl;
    else{
        cout<<"User "<<username<<" is deleted successfully"<<endl;
        fstream fout;
        fout.open("professorsnew.csv",ios::out);
        for(int i=0;i<content.size();i++){
            for(int j=0;j<content[i].size();j++){
                if(j==0){
                fout<<content[i][j];
                }
                else{
                fout<<","<<content[i][j];
                }
            }
            fout<<"\n";
       }
       fout.close();
    }
    fin.close();
    if(count==1){ 
    remove("professors.csv");
    rename("professorsnew.csv","professors.csv");
    }
  }
  else if(k==3){
	fin.open("librarian.csv", ios::in);
	if(fin.is_open())
	{
		while(getline(fin, line))
		{
			row.clear();
 
			stringstream str(line);
 
			while(getline(str, word, ','))
				row.push_back(word);
			content.push_back(row);
		}
	}
    int count=0;
	for(int i=0;i<content.size();i++)
	{
		if(content[i][0]==username){
            content.erase(content.begin()+i);
            count=1;
            break;
		}
	}
    if(count==0)
    cout<<"Record of "<<username<<"not found"<<endl;
    else{
        cout<<"User "<<username<<" is deleted successfully"<<endl;
        fstream fout;
        fout.open("librariannew.csv",ios::out);
        for(int i=0;i<content.size();i++){
            for(int j=0;j<content[i].size();j++){
                if(j==0){
                fout<<content[i][j];
                }
                else{
                fout<<","<<content[i][j];
                }
            }
            fout<<"\n";
       }
       fout.close();
    }
    fin.close();
    if(count==1){
       remove("librarian.csv");
       rename("librariannew.csv","librarian.csv");
    }
  }
}
void librarian::add_book(){
    string title,author,publication,isbn,quantity;
    cout<<"Please enter the book details\n";
    cout<<" Title : ";
    cin>>title;
    cout<<"Author : ";
    cin>>author;
    cout<<"ISBN No. : ";
    cin>>isbn;
    cout<<"Publication : ";
    cin>>publication;
    cout<<"Quantity : ";
    cin>>quantity;
    fstream fout;
        fout.open("books.csv", ios::out | ios::app);
        //setpassword(s);
        fout<<title<<","<<author<<","<<isbn<<","<<publication<<","<<quantity<<"\n";   
}
void user::display_books(){
    vector<vector<string>> content;
       vector<string> row;
	   string line, word;
	   fstream fin ("books.csv", ios::in);
	   if(fin.is_open())
	   {
		   while(getline(fin, line))
		  {
			row.clear();
 
			stringstream str(line);
 
			while(getline(str, word, ','))
				row.push_back(word);
			content.push_back(row);
		    }
	    }
       cout<<endl;
       for(int i=0;i<content.size();i++)
	   {
		   cout<<"Name : "<<content[i][0]<<" | Author : "<<content[i][1]<<" | ISBN : "<<content[i][2]<<" | Publication : "<<content[i][3]<<" | Available Quantity : "<<content[i][4]<<endl;
		}
}
void librarian::delete_book(){
     string isbn;
     cout<<"Enter the ISBN of the book to be deleted : ";
     cin>>isbn; 
    vector<vector<string>> content;
    vector<string> row;
	string line, word;
    fstream fin,fout;
	fin.open("books.csv", ios::in);
    fout.open("booksnew.csv",ios::out);
	if(fin.is_open())
	{
		while(getline(fin, line))
		{
			row.clear();
 
			stringstream str(line);
 
			while(getline(str, word, ','))
				row.push_back(word);
			content.push_back(row);
		}
	}
    int count=0;
	for(int i=0;i<content.size();i++)
	{
		if(content[i][2]==isbn){
            content.erase(content.begin()+i);
            count=1;
            break;
		}
	}
    if(count==0)
    cout<<"Record of book with ISBN = "<<isbn<<" not found"<<endl;
    else{
        cout<<"Book with ISBN = "<<isbn<<" is deleted successfully"<<endl;
        for(int i=0;i<content.size();i++){
            for(int j=0;j<content[i].size();j++){
                if(j==0){
                fout<<content[i][j];
                }
                else{
                fout<<","<<content[i][j];
                }
            }
            fout<<"\n";
       }
       fin.close();
       fout.close();
       remove("books.csv");
       rename("booksnew.csv","books.csv");
  }
}  
vector<vector<string>> user::view_issued_books(string username){
    student s;
    s.username=username;
    vector<vector<string>>content,v;
    vector<string>row,v1;
	string line, word;
    fstream fin;
	fin.open("issued_books.csv", ios::in);
	if(fin.is_open())
	{
		while(getline(fin, line))
		{
			row.clear();
 
			stringstream str(line);
 
			while(getline(str, word, ','))
				row.push_back(word);
			content.push_back(row);
		}
	}
	for(int i=0;i<content.size();i++)
	{  
		if(content[i][0]==username){
          for(int j=0;j<content[i].size();j++){
           v1.push_back(content[i][j]);
          }
        v.push_back(v1);
        v1.clear();
        }
	}
    fin.close();
    return v;
}
void student::request_book(string username){
    student s;
    s.username=username;
    s.issued_books=s.view_issued_books(s.username);
    if(s.issued_books.size()==5){
         cout<<"\nYou have already issued 5 books\n";
    }
    else{
       int count=0;
       string isbn;
       cout<<"Enter the ISBN of the book you want to issue : ";
       cin>>isbn;
       vector<vector<string>>content;
       vector<string>row;
       fstream fin;
       string line,word;
       fin.open("books.csv",ios::in);
       if(fin.is_open())
	    {
		while(getline(fin, line))
		{
			row.clear();
 
			stringstream str(line);
 
			while(getline(str, word, ','))
				row.push_back(word);
			content.push_back(row);
		    }
	    }
        for(int i=0;i<content.size();i++){
            if(content[i][2]==isbn){
                count=1;
              if(content[i][4]=="0"){
                  cout<<"Sorry, the book is currently unavailable\n";
              }
              else{
                cout<<"\nThe book is issued to you\n";
                fstream f1,f2;
                f1.open("issued_books.csv",ios::out | ios::app);
                f1<<username<<","<<content[i][0]<<","<<content[i][1]<<","<<content[i][2]<<","<<content[i][3]<<","<<to_string(time(0))<<","<<s.show_due_date(to_string(time(0)))<<"\n";
                int k = stoi(content[i][4]);
                k-=1;
                string m=to_string(k);
                content[i][4]=m;
              }
              break;
            }
        }
        if(count==0)
        cout<<"Record of book with ISBN "<<isbn<<" is not found\n";
        else{
           fstream fout;
           fout.open("booksnew.csv",ios::out);
        for(int i=0;i<content.size();i++){
            for(int j=0;j<content[i].size();j++){
                if(j==0){
                fout<<content[i][j];
                }
                else{
                fout<<","<<content[i][j];
                }
            }
            fout<<"\n";
          }
          fout.close(); 
        }
    fin.close();
    if(count==1){
        remove("books.csv");
        rename("booksnew.csv","books.csv");
    }  
  }
}
void librarian::update_user(){
    int designation;
    int count=0;
    cout<<"Choose the type of user from below  :\n 1. Student\n 2. Professor\n 3. Librarian\n Enter your choice : ";
    cin>>designation;
    cout<<"Choose from below :\n 1. Update Username\n 2. Update Password\n Enter your choice : ";
    int inp;
    cin>>inp;
    string u_name;
    cout<<"Enter the username of the user whose detail is to be updated : ";
    cin>>u_name;
    vector<vector<string>> content;
    vector<string>row;
    string line,word;
    string user_name;
    if(designation==1){
    fstream fin;
    fin.open("students.csv", ios::in);
	if(fin.is_open())
	{
		while(getline(fin, line))
		{
			row.clear();
 
			stringstream str(line);
 
			while(getline(str, word, ','))
				row.push_back(word);
			content.push_back(row);
		}
	}
	for(int i=0;i<content.size();i++){
		   if(content[i][0]==u_name){
            count=1;
            if(inp==1){
                cout<<"Enter new Username : ";
                cin>>user_name;
                content[i][0]=user_name;
            }
            else if(inp==2){
                string p_word;
                cout<<"Enter new Password : ";
                cin>>p_word;
                content[i][1]=p_word;
            }
        }
	}
        if(count==1){
            cout<<"\nDetails of "<<u_name<<" have been updated successfully"<<endl;
            fstream fout;
            fout.open("studentsnew.csv",ios::out);
            for(int i=0;i<content.size();i++){
                for(int j=0;j<content[i].size();j++){
                    if(j==0)
                    fout<<content[i][0];
                    else
                    fout<<","<<content[i][1];
                }
                fout<<"\n";
            }
            fout.close();
        }
        else{
            cout<<"\nThere is no user with username \""<<u_name<<"\""<<endl;
        }
        fin.close();
        if(count==1){
            remove("students.csv");
            rename("studentsnew.csv","students.csv");
        }
        if(inp==1 && count==1){
           int count1=0;
           vector<vector<string>>v;
           vector<string>r;
           fstream fin1;
           fin1.open("issued_books.csv", ios::in);
	       if(fin1.is_open())
	       {
		   while(getline(fin1, line))
		   {
			r.clear();
 
			stringstream str(line);
 
			while(getline(str, word, ','))
			r.push_back(word);
			v.push_back(r);
		    }
	    }
	for(int i=0;i<v.size();i++){
		   if(v[i][0]==u_name){
               count1=1;
               v[i][0]=user_name;
           }
		}
        if(count1==1){
            fstream fout1;
            fout1.open("issued_booksnew.csv",ios::out);
            for(int i=0;i<v.size();i++){
                for(int j=0;j<v[i].size();j++){
                    if(j==0)
                    fout1<<v[i][0];
                    else
                    fout1<<","<<v[i][j];
                }
                fout1<<"\n";
            }
            fout1.close();
        }
        fin1.close();
        if(count1==1){
            remove("issued_books.csv");
            rename("issued_booksnew.csv","issued_books.csv");
            } 
        }
    }
    else if(designation==2){
    fstream fin;
    fin.open("professors.csv", ios::in);

	if(fin.is_open())
	{
		while(getline(fin, line))
		{
			row.clear();
 
			stringstream str(line);
 
			while(getline(str, word, ','))
				row.push_back(word);
			content.push_back(row);
		}
	}
	for(int i=0;i<content.size();i++){
		for(int j=0;j<content[i].size();j++){
		   if(content[i][0]==u_name){
            count=1;
            if(inp==1){
                cout<<"Enter new username : ";
                cin>>user_name;
                content[i][0]=user_name;
            }
            else if(inp==2){
                string p_word;
                cout<<"Enter new Password : ";
                cin>>p_word;
                content[i][1]=p_word;
            }
           }
		}
	}
        if(count==1){
            cout<<"\nDetails of "<<u_name<<" have been updated successfully"<<endl;
            fstream fout;
            fout.open("professorsnew.csv",ios::out);
              for(int i=0;i<content.size();i++){
                for(int j=0;j<content[i].size();j++){
                    if(j==0)
                    fout<<content[i][0];
                    else
                    fout<<","<<content[i][1];
                }
                fout<<"\n";
            }
            fout.close();
          }
        else{
            cout<<"There is no user with username \""<<u_name<<"\""<<endl;
        }
    fin.close();
    if(count==1){
        remove("professors.csv");
        rename("professorsnew.csv","professors.csv");
    }
    if(inp==1 && count==1){
           int count1=0;
           vector<vector<string>>v;
           vector<string>r;
           fstream fin1;
           fin1.open("issued_books.csv", ios::in);
	       if(fin1.is_open())
	       {
		   while(getline(fin1, line))
		   {
			r.clear();
 
			stringstream str(line);
 
			while(getline(str, word, ','))
			r.push_back(word);
			v.push_back(r);
		    }
	    }
	for(int i=0;i<v.size();i++){
		   if(v[i][0]==u_name){
               count1=1;
               v[i][0]=user_name;
           }
		}
        if(count1==1){
            fstream fout1;
            fout1.open("issued_booksnew.csv",ios::out);
            for(int i=0;i<v.size();i++){
                for(int j=0;j<v[i].size();j++){
                    if(j==0)
                    fout1<<v[i][0];
                    else
                    fout1<<","<<v[i][j];
                }
                fout1<<"\n";
            }
            fout1.close();
        }
        fin1.close();
        if(count==1){
            remove("issued_books.csv");
            rename("issued_booksnew.csv","issued_books.csv");
            } 
        }
  }
    else if(designation==3){
    fstream fin;
    fin.open("librarian.csv", ios::in);
	if(fin.is_open())
	{
		while(getline(fin, line))
		{
			row.clear();
 
			stringstream str(line);
 
			while(getline(str, word, ','))
				row.push_back(word);
			content.push_back(row);
		}
	}
	for(int i=0;i<content.size();i++){
		for(int j=0;j<content[i].size();j++){
		   if(content[i][0]==u_name){
            count=1;
            if(inp==1){
                cout<<"Enter new username : ";
                cin>>user_name;
                content[i][0]=user_name;
            }
            else if(inp==2){
                string p_word;
                cout<<"Enter new Password : ";
                cin>>p_word;
                content[i][1]=p_word;
            }
           }
		}
	}
        if(count==1){
            cout<<"\nDetails of "<<u_name<<" have been updated successfully"<<endl;
            fstream fout;
            fout.open("librarian_new.csv",ios::out);
            for(int i=0;i<content.size();i++){
                for(int j=0;j<content[i].size();j++){
                    if(j==0)
                    fout<<content[i][0];
                    else
                    fout<<","<<content[i][1];
                }
                fout<<"\n";
            }
            fout.close();
        }
        else{
            cout<<"\nThere is no user with username \""<<u_name<<"\""<<endl;
        }
        fin.close();
        if(count==1){
            remove("librarian.csv");
            rename("librarian_new.csv","librarian.csv");
        }
    }
}
int student::fine_calc(string username){
    int fine=0;
    student s;
    s.username=username;
    s.issued_books=s.view_issued_books(s.username);
    for(int i=0;i<s.issued_books.size();i++){
        if(s.issued_books[i][0]==s.username){
            int t=stoi(s.issued_books[i][5]);
            int z=ceil((time(0)-t)/86400);
            if(z>30)
            fine+=2*(z-30);
        }
    }
    cout<<endl;
    return fine;
}
void librarian::all_users(){
    fstream fin;
    cout<<"\nStudent Users\n";
    fin.open("students.csv",ios::in);
    vector<vector<string>> content;
    vector<string>row;
    string line,word;
    if(fin.is_open())
	{
		while(getline(fin, line))
		{
			row.clear();
 
			stringstream str(line);
 
			while(getline(str, word, ','))
				row.push_back(word);
			content.push_back(row);
		}
	}
    for(int i=0;i<content.size();i++){
        cout<<content[i][0]<<endl;
    }
    fin.close();
    fstream fin1;
    cout<<"\nProfessor Users\n";
    fin1.open("professors.csv",ios::in);
    content.clear();
    row.clear();
    if(fin1.is_open())
	{
		while(getline(fin1, line))
		{
			row.clear();
 
			stringstream str(line);
 
			while(getline(str, word, ','))
				row.push_back(word);
			content.push_back(row);
		}
	}
    for(int i=0;i<content.size();i++){
        cout<<content[i][0]<<endl;
    }
    fin1.close();
    fstream fin2;
    cout<<"\nLibrarian Users\n";
    content.clear();
    row.clear();
    fin2.open("librarian.csv",ios::in);
    if(fin2.is_open())
	{
		while(getline(fin2, line))
		{
			row.clear();
 
			stringstream str(line);
 
			while(getline(str, word, ','))
				row.push_back(word);
			content.push_back(row);
		}
	}
    for(int i=0;i<content.size();i++){
        cout<<content[i][0]<<endl;
    }
    fin2.close();
}
void librarian::issued_books(){
    fstream fin;
    fin.open("issued_books.csv",ios::in);
    vector<vector<string>> content;
    vector<string>row;
    string line,word;
    if(fin.is_open())
	{
		while(getline(fin, line))
		{
			row.clear();
 
			stringstream str(line);
 
			while(getline(str, word, ','))
				row.push_back(word);
			content.push_back(row);
		}
	}
    cout<<endl;
    for(int i=0;i<content.size();i++){
        cout<<"Username : "<<content[i][0]<<"Name of Book : "<<content[i][1]<<" | Author : "<<content[i][2]<<" | ISBN : "<<content[i][3]<<" | Publication : "<<content[i][4]<<" | Due Date : "<<content[i][6]<<endl;
    }
    fin.close();
}
void librarian::show_fine(){
    int count=0;
    fstream fin;
    fin.open("issued_books.csv",ios::in);
    vector<vector<string>> content;
    vector<string>row;
    string line,word;
    if(fin.is_open())
	{
		while(getline(fin, line))
		{
			row.clear();
 
			stringstream str(line);
 
			while(getline(str, word, ','))
				row.push_back(word);
			content.push_back(row);
		}
	}
    for(int i=0;i<content.size();i++){
        student s;
        s.username=content[i][0];
        int f=s.fine_calc(s.username);
        if(f){
        count=1;
        cout<<s.username<<" "<<f<<endl;
        }
    }
    if(count==0){
        cout<<"No fine on any user\n";
    }
    fin.close();
}
int professor::calc_fine(string username){
    int fine=0;
    professor p;
    p.username=username;
    p.issued_books=p.view_issued_books(p.username);
    for(int i=0;i<p.issued_books.size();i++){
        if(p.issued_books[i][0]==p.username){
            int t=stoi(p.issued_books[i][5]);
            int z=ceil((time(0)-t)/86400);
            if(z>60)
            fine+=5*(z-60);
        }
    }
    cout<<endl;
    return fine;
}
void professor::request_book(string username){
    professor p;
    p.username=username;
    p.issued_books=p.view_issued_books(p.username);
       int count=0;
       string isbn;
       cout<<"Enter the ISBN of the book you want to issue : ";
       cin>>isbn;
       vector<vector<string>>content;
       vector<string>row;
       fstream fin,fout;
       string line,word;
       fin.open("books.csv",ios::in);
       if(fin.is_open())
	    {
		while(getline(fin, line))
		{
			row.clear();
 
			stringstream str(line);
 
			while(getline(str, word, ','))
				row.push_back(word);
			content.push_back(row);
		    }
	    }
        for(int i=0;i<content.size();i++){
            if(content[i][2]==isbn){
                count=1;
              if(content[i][4]=="0"){
                  cout<<"Sorry, the book is currently unavailable\n";
              }
              else{
                cout<<"\nThe book is issued to you\n";
                fstream f1,f2;
                f1.open("issued_books.csv",ios::out | ios::app);
                f1<<username<<","<<content[i][0]<<","<<content[i][1]<<","<<content[i][2]<<","<<content[i][3]<<","<<time(0)<<","<<p.show_due_date(to_string(time(0)))<<"\n";
                int k = stoi(content[i][4]);
                k-=1;
                string m=to_string(k);
                content[i][4]=m;
              }
              break;
            }
        }
        if(count==0)
        cout<<"Record of book with ISBN "<<isbn<<" is not found\n";
        else{
           fout.open("booksnew.csv",ios::out);
        for(int i=0;i<content.size();i++){
            for(int j=0;j<content[i].size();j++){
                if(j==0){
                fout<<content[i][j];
                }
                else{
                fout<<","<<content[i][j];
                }
            }
            fout<<"\n";
          } 
        }
    fin.close();
    fout.close();
    if(count==1){
        remove("books.csv");
        rename("booksnew.csv","books.csv");
    }  
}
void librarian::update_book(){
    cout<<"Enter the ISBN of the book to be updated : ";
    string isbn;
    cin>>isbn;
    cout<<"\n";
    cout<<"Enter the new quantity of the book : ";
    int q;
    cin>>q;
    fstream fin,fout;
    string line,word;
    vector<vector<string>>content;
    vector<string>row;
    fin.open("books.csv", ios::in);
    fout.open("booksnew.csv",ios::out);
	if(fin.is_open())
	{
		while(getline(fin, line))
		{
			row.clear();
 
			stringstream str(line);
 
			while(getline(str, word, ','))
				row.push_back(word);
			content.push_back(row);
		}
	}
    int count=0;
	for(int i=0;i<content.size();i++)
	{
		if(content[i][2]==isbn){
            string s=to_string(q);
            content[i][4]=s;
            count=1;
            break;
		}
	}
    if(count==0)
    cout<<"Record of book with ISBN = "<<isbn<<" not found"<<endl;
    else{
        cout<<"Quantity of book with ISBN = "<<isbn<<" is updated successfully"<<endl;
        for(int i=0;i<content.size();i++){
            for(int j=0;j<content[i].size();j++){
                if(j==0){
                fout<<content[i][j];
                }
                else{
                fout<<","<<content[i][j];
                }
            }
            fout<<"\n";
       }
       fin.close();
       fout.close();
       remove("books.csv");
       rename("booksnew.csv","books.csv");
  }
}
void student::return_book(string username){
    int count=0;
    cout<<"Enter the ISBN of the book to be returned : ";
    string isbn;
    cin>>isbn;
    fstream fin;
    fin.open("issued_books.csv",ios::in);
    vector<vector<string>> content;
    vector<string>row;
    string line,word;
    if(fin.is_open())
	{
		while(getline(fin, line))
		{
			row.clear();
 
			stringstream str(line);
 
			while(getline(str, word, ','))
				row.push_back(word);
			content.push_back(row);
		}
	}
    for(int i=0;i<content.size();i++){
        if(content[i][0]==username && content[i][3]==isbn){
            count=1;
            content.erase(content.begin()+i);            
        }
    }
    if(count==0){
        cout<<"\nYou have not issued this book\n";
    }
    else{
        cout<<"The book is returned successfully"<<endl;
        fstream fout;
        fout.open("issued_booksnew.csv",ios::out);
        for(int i=0;i<content.size();i++){
            for(int j=0;j<content[i].size();j++){
                if(j==0)
                fout<<content[i][0];
                else
                fout<<","<<content[i][j];
            }
            fout<<'\n';
        }
        fout.close();
    }
    fin.close();
    if(count==1){
        remove("issued_books.csv");
        rename("issued_booksnew.csv","issued_books.csv");
    }
    if(count==1){
        int count1=0;
           vector<vector<string>>v;
           vector<string>r;
           fstream fin1;
           fin1.open("books.csv", ios::in);
	       if(fin1.is_open())
	       {
		   while(getline(fin1, line))
		   {
			r.clear();
 
			stringstream str(line);
 
			while(getline(str, word, ','))
			r.push_back(word);
			v.push_back(r);
		    }
	    }
	for(int i=0;i<v.size();i++){
		   if(v[i][2]==isbn){
              count1=1;
              int t=stoi(v[i][4]);
              t=t+1;
              string my=to_string(t);
              v[i][4]=my;
           }
		}
        if(count1==1){
            fstream fout1;
            fout1.open("booksnew.csv",ios::out);
            for(int i=0;i<v.size();i++){
                for(int j=0;j<v[i].size();j++){
                    if(j==0)
                    fout1<<v[i][0];
                    else
                    fout1<<","<<v[i][j];
                }
                fout1<<"\n";
            }
            fout1.close();
        }
        fin1.close();
        if(count1==1){
            remove("books.csv");
            rename("booksnew.csv","books.csv");
            } 
    }
}
void professor::return_book(string username){
    int count=0;
    cout<<"Enter the ISBN of the book to be returned : ";
    string isbn;
    cin>>isbn;
    fstream fin;
    fin.open("issued_books.csv",ios::in);
    vector<vector<string>> content;
    vector<string>row;
    string line,word;
    if(fin.is_open())
	{
		while(getline(fin, line))
		{
			row.clear();
 
			stringstream str(line);
 
			while(getline(str, word, ','))
				row.push_back(word);
			content.push_back(row);
		}
	}
    for(int i=0;i<content.size();i++){
        if(content[i][0]==username && content[i][3]==isbn){
            count=1;
            content.erase(content.begin()+i);            
        }
    }
    if(count==0){
        cout<<"\nYou have not issued this book\n";
    }
    else{
        fstream fout;
        fout.open("issued_booksnew.csv",ios::out);
        for(int i=0;i<content.size();i++){
            for(int j=0;j<content[i].size();j++){
                if(j==0)
                fout<<content[i][0];
                else
                fout<<","<<content[i][j];
            }
            fout<<'\n';
        }
        fout.close();
    }
    fin.close();
    if(count==1){
        remove("issued_books.csv");
        rename("issued_booksnew.csv","issued_books.csv");
    }
    if(count==1){
        int count1=0;
           vector<vector<string>>v;
           vector<string>r;
           fstream fin1;
           fin1.open("books.csv", ios::in);
	       if(fin1.is_open())
	       {
		   while(getline(fin1, line))
		   {
			r.clear();
 
			stringstream str(line);
 
			while(getline(str, word, ','))
			r.push_back(word);
			v.push_back(r);
		    }
	    }
	for(int i=0;i<v.size();i++){
		   if(v[i][2]==isbn){
              count1=1;
              int t=stoi(v[i][4]);
              t=t+1;
              string my=to_string(t);
              v[i][4]=my;
           }
		}
        if(count1==1){
            fstream fout1;
            fout1.open("booksnew.csv",ios::out);
            for(int i=0;i<v.size();i++){
                for(int j=0;j<v[i].size();j++){
                    if(j==0)
                    fout1<<v[i][0];
                    else
                    fout1<<","<<v[i][j];
                }
                fout1<<"\n";
            }
            fout1.close();
        }
        fin1.close();
        if(count1==1){
            remove("books.csv");
            rename("booksnew.csv","books.csv");
            } 
    }
}
string student::show_due_date(string timestamp){
    
    time_t ttime;

    ttime = stoi(timestamp)+2592000;
    tm *local_time = localtime(&ttime);
    //cout<< local_time->tm_mday<<"/"<<1 + local_time->tm_mon<<"/"<<1900 + local_time->tm_year<<"\n";

    string s;
    s+=to_string(local_time->tm_mday);
    s+="/";
    s+=to_string(1 + local_time->tm_mon);
    s+="/";
    s+=to_string(1900 + local_time->tm_year);

    return s;
	}
string professor::show_due_date(string timestamp){
    
    time_t ttime;

    ttime = stoi(timestamp)+2*2592000;
    tm *local_time = localtime(&ttime);
    //cout<< local_time->tm_mday<<"/"<<1 + local_time->tm_mon<<"/"<<1900 + local_time->tm_year<<"\n";

    string s;
    s+=to_string(local_time->tm_mday);
    s+="/";
    s+=to_string(1 + local_time->tm_mon);
    s+="/";
    s+=to_string(1900 + local_time->tm_year);

    return s;
	}
void librarian::clear_fine_amount(){
    string user_name,isbn;
    int count=0;
    cout<<"Enter the username of the user : ";
    cin>>user_name;
    cout<<"Enter the isbn of the book : ";
    cin>>isbn;
    vector<vector<string>>content;
    vector<string>row;
    fstream fin;
    string line,word;
    fin.open("issued_books.csv",ios::in);
    if(fin.is_open())
	{
		while(getline(fin, line))
		{
			row.clear();
 
			stringstream str(line);
 
			while(getline(str, word, ','))
				row.push_back(word);
			content.push_back(row);
		    }
	    }
        for(int i=0;i<content.size();i++){
            if(content[i][0]==user_name && content[i][3]==isbn){
                count=1;
                content[i][5]=to_string(time(0));
                break;
            }
        }
        if(count==0)
        cout<<"Incorrect Details Entered"<<endl;
        else{
            fstream fout;
            cout<<endl<<"Fine for the book with isbn : "<<isbn<<" has been cleared"<<endl;
            fout.open("issued_booksnew.csv",ios::out);
            for(int i=0;i<content.size();i++){
                for(int j=0;j<content[i].size();j++){
                    if(j==0)
                    fout<<content[i][0];
                    else
                    fout<<","<<content[i][j];
                }
                fout<<"\n";
            }
            fout.close();
        }
    fin.close();
    if(count==1){
        remove("issued_books.csv");
        rename("issued_booksnew.csv","issued_books.csv");
    }
}
vector<string> books::search_book(string book_name){
      int count=0;
      vector<vector<string>>content;
       vector<string>row,v;
       fstream fin;
       string line,word;
       fin.open("books.csv",ios::in);
       if(fin.is_open())
	    {
		while(getline(fin, line))
		{
			row.clear();
 
			stringstream str(line);
 
			while(getline(str, word, ','))
				row.push_back(word);
			content.push_back(row);
		    }
	    }
        for(int i=0;i<content.size();i++){
           if(content[i][0]==book_name){
               count=1;
               for(int j=0;j<content[i].size();j++){
               v.push_back(content[i][j]);
               }
               break;
           }
        }
    return v;
}
void student::student_main_menu(string username){
    student s;
    s.username=username;
    int c=0; 
    cout<<endl<<s.username<<" ,your are successfully logged in .\n\n"<<endl;
    while(c!=5){
    cout<<"\nWhat do you want to see ?\n" ;
    cout<<" 1. List of All Books\n";
    cout<<" 2. Search a Book\n";
    cout<<" 3. Books issued by you along with their due date\n";
    cout<<" 4. Request a Book\n";
    cout<<" 5. Fine Amount\n";
    cout<<" 6. Return a Book\n";
    cout<<" 7. Logout\n";
    cout<<"Enter your choice : ";
    cin>>c;
    if(c==1){
        s.display_books();
	}
    else if(c==2){
        string book_name;
        cout<<"Enter the name of book : ";
        cin>>book_name;
        books b;
        b.title=book_name;
        vector<string>v = b.search_book(book_name);
        if(v.size()==0)
        cout<<"\nThe book is not available in the library\n";
        else{
            cout<<"\n Details of the book are : \n";
            cout<<"Name : "<<v[0]<<" | Author : "<<v[1]<<" | ISBN : "<<v[2]<<" | Publication : "<<v[3]<<" | Available Quantity : "<<v[4]<<endl;
        }
    }
    else if(c==3){
        s.issued_books=s.view_issued_books(username);
        if(s.issued_books.size()==0)
        cout<<"\nNo book is issued to you"<<endl;
        else{
            cout<<"Books issued by you are : \n\n0";
            for(int i=0;i<s.issued_books.size();i++){
                cout<<i+1<<".) ";
                for(int j=1;j<s.issued_books[i].size()-2;j++){
                cout<<s.issued_books[i][j]<<" ";
                }
                int j=s.issued_books[i].size() - 1;
                cout<<endl<<"     Deadline to submit the Book is : "<<s.issued_books[i][j]<<endl;
                cout<<endl;
            }
        }
    }
    else if(c==4){
        s.request_book(username);
    }
    else if(c==5){
        int f=s.fine_calc(s.username);
        cout<<f<<endl;
    }
    else if(c==6){
        s.return_book(s.username);
    }
    else if(c==7){
        s.reg_login();
    }
  }  
}
void professor::prof_main_menu(string username){
    professor p;
    p.username=username;
    int c=0; 
    cout<<username<<"\n ,your are successfully logged in .\n"<<endl;
    while(c!=5){
    cout<<"\nWhat do you want to see ?\n" ;
    cout<<" 1. List of All Books\n";
    cout<<" 2. Search a book\n";
    cout<<" 3. Books issued by you along with their due date\n";
    cout<<" 4. Issue a Book\n";
    cout<<" 5. Fine Amount\n";
    cout<<" 6. Return a Book\n";
    cout<<" 7. Logout\n";
    cout<<"\nEnter your choice : ";
    cin>>c;
    if(c==1){
        p.display_books();
		}
    else if(c==2){
        string book_name;
        cout<<"Enter the name of book : ";
        cin>>book_name;
        books b;
        b.title=book_name;
        vector<string>v = b.search_book(book_name);
        if(v.size()==0)
        cout<<"\nThe book is not available in the library\n";
        else{
            cout<<"\n Details of the book are : \n\n";
           cout<<"Name : "<<v[0]<<" | Author : "<<v[1]<<" | ISBN : "<<v[2]<<" | Publication : "<<v[3]<<" | Available Quantity : "<<v[4]<<endl;
        }
    }
    else if(c==3){
        p.issued_books=p.view_issued_books(p.username);
        if(p.issued_books.size()==0)
        cout<<"\nNo book is issued to you\n"<<endl;
        else{
            cout<<"\nBooks issued by you are : \n\n";
            for(int i=0;i<p.issued_books.size();i++){
                cout<<i+1<<".) ";
                for(int j=1;j<p.issued_books[i].size()-2;j++){
                cout<<p.issued_books[i][j]<<" ";
                }
                int j=p.issued_books[i].size()-1;
                cout<<endl<<"     Deadline to submit this book is : "<<p.issued_books[i][j]<<endl;
                cout<<endl;
            }
        }
    }
    else if(c==4){
        p.request_book(p.username);
    }
    else if(c==5){
        int f=p.calc_fine(p.username);
        cout<<f<<endl;
    }
    else if(c==6){
        p.return_book(p.username);
    }
    else if(c==7){
        p.reg_login();
    }
  }  
}
void librarian::librarian_main_menu(string username){
    librarian l;
    l.username=username;
    l.password=password;
    int c=0; 
    cout<<username<<"\n ,your are successfully logged in as librarian.\n"<<endl;
    while(c!=9){
    cout<<"\nWhat do you want to do?\n" ;
    cout<<" 1. See List of All Books\n";
    cout<<" 2. Books issued to different users\n";
    cout<<" 3. Fine on different users\n";
    cout<<" 4. All Users\n";
    cout<<" 5. Add User\n";
    cout<<" 6. Delete User\n";
    cout<<" 7. Update User\n";
    cout<<" 8. Add Book\n";
    cout<<" 9. Delete Book\n";
    cout<<" 10. Update Book\n";
    cout<<" 11. Clear Fine of a User\n";
    cout<<" 12. Logout\n";
    cout<<" 13. Search a book\n";
    cout<<"Enter your choice : ";
    cin>>c;
    if(c==1){
        l.display_books();
	}
    else if(c==2){
        l.issued_books();
    }
    else if(c==3){
        l.show_fine();
    }
    else if(c==4){
        l.all_users();
    }
    else if(c==5){
        cout<<"\nChoose from below : \n";
        cout<<" 1. Add Student user\n";
        cout<<" 2. Add Professor user\n";
        cout<<" 3. Add Librarian user\n";
        cout<<"\n Enter you choice : ";
        int in;
        cin>>in;
        l.add_user(in);
    }
    else if(c==6){
        cout<<"\nChoose from below :\n";
        cout<<" 1. Delete Student user\n";
        cout<<" 2. Delete Professor user\n";
        cout<<" 3. Delete Librarian user\n";
        cout<<"\n Enter your choice : ";
        int in;
        cin>>in;
        l.delete_user(in);
    }
    else if(c==7){
        l.update_user();
    }
    else if(c==8){
        l.add_book();
    }
    else if(c==9){
        l.delete_book();
    }
    else if(c==10){
        l.update_book();
    }
    else if(c==11){
        l.clear_fine_amount();
    }
    else if(c==12){
        l.reg_login();
    }
    else if(c==13){
        string book_name;
        cout<<"Enter the name of book : ";
        cin>>book_name;
        books b;
        b.title=book_name;
        vector<string>v = b.search_book(book_name);
        if(v.size()==0)
        cout<<"\nThe book is not available in the library\n";
        else{
            cout<<"\n Details of the book are : \n";
            cout<<"Name : "<<v[0]<<" | Author : "<<v[1]<<" | ISBN : "<<v[2]<<" | Publication : "<<v[3]<<" | Available Quantity : "<<v[4]<<endl;
            cout<<endl;
        }
    }
  }
}
void user::login(){
    cout<<"\nPlease choose your Designation"<<endl;
    cout<<"1. Student"<<endl;
    cout<<"2. Professor"<<endl;
    cout<<"3. Librarian"<<endl;
    cout<<"Enter your Choice : ";
    int designation;
    cin>>designation;
        int count=0;
        string username,password;
        cout<<"\nPlease enter your username and password\n username : ";
        cin>> username;
        cout<<" password : ";
        cin>>password;
    vector<vector<string>> content;
    vector<string> row;
	string line, word;
    if(designation==1){
    student s;
    s.username=username;
	fstream fin ("students.csv", ios::in);
	if(fin.is_open())
	{
		while(getline(fin, line))
		{
			row.clear();
 
			stringstream str(line);
 
			while(getline(str, word, ','))
				row.push_back(word);
			content.push_back(row);
		}
	}

	for(int i=0;i<content.size();i++)
	{
		for(int j=0;j<content[i].size();j++)
		{
		   if(content[i][0]==username && content[i][1]==password){
               count=1;
           }
		}
	}
        if(count==1){
            s.student_main_menu(username);
        }
        else{
            cout<<"\nSorry, you have entered incorrect credentials .\n"<<endl;
            s.reg_login();
        }
    }
    else if(designation==2){
        professor p;
        p.username=username;
	    fstream fin ("professors.csv", ios::in);
	    if(fin.is_open())
	    {
		    while(getline(fin, line))
		    {
			row.clear();
 
			stringstream str(line);
 
			    while(getline(str, word, ','))
				row.push_back(word);
			    content.push_back(row);
		    }
	    }

	    for(int i=0;i<content.size();i++)
	    {
		    for(int j=0;j<content[i].size();j++)
		    {
		        if(content[i][0]==username && content[i][1]==password){
                count=1;
                }
		    }
	    }
        if(count==1){
            p.prof_main_menu(username);
        }
        else{
            cout<<"\nSorry, you have entered incorrect credentials .\n"<<endl;
            p.reg_login();
        }
    }
    else if(designation==3){
    librarian l;
    l.username=username;
	fstream fin ("librarian.csv", ios::in);
	if(fin.is_open())
	{
		while(getline(fin, line))
		{
			row.clear();
 
			stringstream str(line);
 
			while(getline(str, word, ','))
				row.push_back(word);
			content.push_back(row);
		}
	}

	for(int i=0;i<content.size();i++)
	{
		for(int j=0;j<content[i].size();j++)
		{
		   if(content[i][0]==username && content[i][1]==password){
               count=1;
           }
		}
	}
        if(count==1){
            l.librarian_main_menu(username);
        }
        else{
            cout<<"\nSorry, you have entered incorrect credentials .\n"<<endl;
            l.reg_login();
        }
    }
    else{
        cout<<"Wrong Choice"<<endl;
        user u;
        u.reg_login();
    }
}
void user::reg_login(){
    user u;
    cout<<"\nPlease enter your choice \n 1. Login \n 2. EXIT\n Enter your choice : ";
    int c;
    cin>>c;
    if(c==1){
     u.login();
    }
    else if(c==2){
        return;
    }
    else{
    cout<<"Wrong Choice"<<endl;
    user u;
    u.reg_login();
    }
}
int main(){
    user u;
    u.reg_login();
}