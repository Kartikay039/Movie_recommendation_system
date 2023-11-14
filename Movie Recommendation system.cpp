#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

class User{
	
	private:
		string name;
		string password;
		int age;
	
	public:
		
		void setname(string name){
			this->name = name;
		}
		void setpassword(string pass){
			this->password = pass;
		}
		void setage(int age){
			this->age = age;
		}
		
		string getname(){
			return this->name;
		}
		string getpassword(){
			return this->password;
		}
		int getage(){
			return this->age;
		}
};

void welcome(){
	cout << "\033[1;32m"; // colour code to change output stream to greeen
	cout<< "                                           WELCOME TO MOVIE MAVEN";
	cout << "\033[0m"<<endl; // reset the colour of output stream to default
}

class Node{
	public:
	string genre;
	string name;
	int ratting;
	int age_limit;
	string emotion;
	Node* next;
	
	Node(string genre, string name, int ratting, int age_limit, string emotion){
		this->genre = genre;
		this->name = name;
		this->ratting = ratting;
		this->age_limit = age_limit;
		this->emotion = emotion;
		this->next = NULL;
	}
};

bool signup(User &user){
	string name;
	string password;
	string confirmpassword;
	int password_flag = 0; //flag for password == confirm password
	int age;
	
	cout<<"Sign Up! First To Use Our Application!"<<endl;
	cout<<"Enter User Name -> ";
	cin>>name;
	user.setname(name);
	
	cout<<"Enter your age -> ";
	cin>>age;
	user.setage(age);
	
	while(password_flag == 0){
	
		cout<<"Set Password -> ";
		cin>>password;
		
		user.setname(name);
		
		cout<<"Confirm Password -> ";
		cin>>confirmpassword;
		user.setname(name);
		if(password == confirmpassword){
			user.setpassword(password);
			++password_flag;
			
		}
	}
	cout << "\033[1;32m";
	cout<<"Signed up! successfully..."<<endl;
	cout << "\033[0m"<<endl;
	return true;
	
	
}

bool login(User &user, bool &loggedin){
	string name, password;
	cout<<"Login Using Your Username and Password"<<endl;
	cout<<"Enter Your User Name -> ";
	cin>>name;
	if(name == user.getname()){
		cout<<"Enter password -> ";
		cin>>password;
		if(password == user.getpassword()){
			cout << "\033[1;32m";
			cout<<"Logged In SUCESSFULLY! Exciting And Amazing Movies Are Waiting For You...";
			cout << "\033[0m"<<endl<<endl;
			return loggedin = true;
		}
	}
	cout << "\033[1;31m"; 
	cout<<"something went wrong! try again..";
	cout << "\033[0m"<<endl;
	return login(user, loggedin);
	
}

void insertAtTail(Node* &tail, string genre, string name, int ratting, int age_limit, string emotion){
	Node* temp = new Node(genre, name, ratting, age_limit, emotion);
	tail->next = temp;
	tail = temp;		
}

void printList(Node* head, User user, bool &prohibited){
	int movie_num = 1; // for movie serial number
	int prohibited_flag = 1; //flag for checking if you are under aged or not
	Node* temp = head;
	
	while(temp != NULL){
		if(temp->age_limit <= user.getage()){
			cout<<movie_num<<". "<<temp -> name<<" | "; 
			movie_num++; 
			prohibited_flag = 0;
		}
		for(int i =0; i<5; i++){
			if(temp != NULL){
				temp = temp->next;
			}
		}
	}
	if(prohibited_flag == 1){
		cout << "\033[1;31m"; 
		cout<<"Sorry! this section of our application is prohibited for you";
		prohibited = true;
		cout << "\033[0m";
	}
	cout<<endl;
	cout<<endl;
}

void printList(int genre, Node* head, User user, bool &prohibited){
	
	int movie_num = 1; // for movie serial number
	int prohibited_flag = 1; //flag for checking if you are under aged or not
	Node* temp = head;
	
	for(int i = 1; i<genre; i++){
		temp = temp->next;
	}
	
	while(temp != NULL){
		if(temp->age_limit <= user.getage()){
			cout<<movie_num<<". "<<temp -> name<<" | "; 
			movie_num++; 
			prohibited_flag = 0;
		}
		for(int i =0; i<5; i++){
			if(temp != NULL){
				temp = temp->next;
			}
		}
	}
	if(prohibited_flag == 1){
		cout << "\033[1;31m"; 
		cout<<"Sorry! this section of our application is prohibited for you";
		prohibited = true;
		cout << "\033[0m";
	}
	cout<<endl;
	cout<<endl;
}
string movie_name(Node *head, User user, int genre, int movie_number){
	int movie_counter = 0;
	//string name;
	
	for(int i = 1; i<genre; i++){
		head = head->next;
	}
	
	while(movie_counter != movie_number){
		if(head->age_limit <= user.getage()){
			movie_counter++;
		}
		if(movie_counter != movie_number){
			for(int i =0; i<5; i++){
				if(head != NULL){
					head = head->next;
				}
			}
		}
	}
	return head->name;
}

void updateMovieRating(Node *head, User user, int genre, int movie_number, int new_ratting){
	int movie_counter = 0;
	string name;
	
	for(int i = 1; i<genre; i++){
		head = head->next;
	}
	
	while(movie_counter != movie_number){
		if(head->age_limit <= user.getage()){
			movie_counter++;
		}
		if(movie_counter != movie_number){
			for(int i =0; i<5; i++){
				if(head != NULL){
					head = head->next;
				}
			}
		}
	}
	head->ratting = head->ratting + new_ratting;
	
}


void sort_movies(Node* head, int genre){
	
	for(int i = 1; i<genre; i++){
		head = head->next;
	}
	
	Node* current = head;
	

	
	string temp_genre;
	string temp_name;
	int temp_ratting;
	int temp_age_limit;
	string temp_emotion;
	
	for(int i = 0; i<8; i++){
		current = head;
		
		for(int i =0; i<8; i++){
			if(current->ratting < current->next->next->next->next->next->ratting){
			
				temp_genre = current->genre;
				temp_name = current->name;
				temp_ratting = current->ratting;
				temp_age_limit = current->age_limit;
				temp_emotion = current->emotion;
			
				current->genre = current->next->next->next->next->next->genre;
				current->name = current->next->next->next->next->next->name;
				current->ratting = current->next->next->next->next->next->ratting;
				current->age_limit = current->next->next->next->next->next->age_limit;
				current->emotion = current->next->next->next->next->next->emotion;
			
				current->next->next->next->next->next->genre = temp_genre;
				current->next->next->next->next->next->name = temp_name;
				current->next->next->next->next->next->ratting = temp_ratting;
				current->next->next->next->next->next->age_limit = temp_age_limit;
				current->next->next->next->next->next->emotion = temp_emotion;
				
				
			}
			current = current->next->next->next->next->next;
		}
	}
	
	
}

string emotion_of_movie(Node* head, User user, int genre, int movie_to_watch){
	
	int movie_counter = 0;
	
	for(int i = 1; i<genre; i++){
		head = head->next;
	}
	
	while(movie_counter != movie_to_watch){
		if(head->age_limit <= user.getage()){
			movie_counter++;
		}
		if(movie_counter != movie_to_watch){
			for(int i =0; i<5; i++){
				if(head != NULL){
					head = head->next;
				}
			}
		}
	}
	return head->emotion;
	
}

void recommand_movie(Node* head, User user, string movie_emotion){
	while(head->next != NULL){
		if(head->emotion == movie_emotion){
			if(head->age_limit <= user.getage()){
				cout << "\033[1;32m";
				cout<<head->genre<<" - "<<head->name<<" | ";
				cout << "\033[0m";
			}
		}
		head = head->next;
	}
	cout<<endl;
}

bool find_movie(string arr[], Node* head, User user, int genre, int movie_number){
	for(int i = 0; i<45; i++){
		if(arr[i] == movie_name(head, user, genre, movie_number)){
			return true;
		}
	}
	return false;
}



int main(){
	
	
	welcome();
	
	string movies_watched[45];
	int movie_watched_counter = 0;
	
	
	bool user_logged_in = false; // flag for if user is logged in or not --
																	// 	  |	
    User user;// creating user object                                     |
	signup(user); // signing up user by adding info to user               |  
	           														   // |
	login(user, user_logged_in);// loging in user  -----------------------| 
	 
	
	Node* node = new Node("Horror", "The Exorcist", 8, 18, "Scared");
	Node* tail = node;
	Node* head = node;
	//-------------------------------------------------------------------------------------- data set here
	{
	//1
	insertAtTail(tail, "Anime", "Spirited Away", 9, 7, "Excited");
	insertAtTail(tail, "Action", "Die Hard", 8, 17, "Excited");
	insertAtTail(tail, "Thriller", "Se7en", 9, 18, "Scared");
	insertAtTail(tail, "Science Fiction", "Blade Runner", 8, 16, "Mysterious");
	//2
	insertAtTail(tail, "Horror", "The Shining", 9, 18, "Scared");
	insertAtTail(tail, "Anime", "Akira", 8, 16, "Angry");
	insertAtTail(tail, "Action", "Mad Max: Fury Road", 8, 17, "Excited");
	insertAtTail(tail, "Thriller", "Inception", 9, 13, "Excited");
	insertAtTail(tail, "Science Fiction", "The Matrix", 8, 15, "Surprised");
	//3
	insertAtTail(tail, "Horror", "Get Out", 7, 17, "Scared");
	insertAtTail(tail, "Anime", "My Neighbor Totoro", 8, 7, "Happy");
	insertAtTail(tail, "Action", "Gladiator", 8, 16, "Excited");
	insertAtTail(tail, "Thriller", "The Silence of the Lambs", 9, 18, "Scared");
	insertAtTail(tail, "Science Fiction", "Interstellar", 8, 13, "Surprised");
	//4
	insertAtTail(tail, "Horror", "Psycho", 9, 18, "Scared");
	insertAtTail(tail, "Anime", "Cowboy Bebop: The Movie", 8, 15, "Excited");
	insertAtTail(tail, "Action", "John Wick", 8, 18, "Excited");
	insertAtTail(tail, "Thriller", "Heat", 8, 18, "Scared");
	insertAtTail(tail, "Science Fiction", "E.T. the Extra-Terrestrial", 7, 7, "Happy");
	//5
	insertAtTail(tail, "Horror", "A Nightmare on Elm Street", 7, 17, "Scared");
	insertAtTail(tail, "Anime", "Your Name", 9, 7, "Happy");
	insertAtTail(tail, "Action", "The Dark Knight", 9, 18, "Angry");
	insertAtTail(tail, "Thriller", "Zodiac", 8, 18, "Scared");
	insertAtTail(tail, "Science Fiction", "Avatar", 7, 13, "Surprised");
	//6
	insertAtTail(tail, "Horror", "Hereditary", 7, 18, "Scared");
	insertAtTail(tail, "Anime", "Princess Mononoke", 8, 12, "Sad");
	insertAtTail(tail, "Action", "Jurassic Park", 8, 13, "Excited");
	insertAtTail(tail, "Thriller", "Gone Girl", 8, 18, "Angry");
	insertAtTail(tail, "Science Fiction", "The War of the Worlds", 7, 7, "Surprised");
	//7
	insertAtTail(tail, "Horror", "The Conjuring", 7, 17, "Scared");
	insertAtTail(tail, "Anime", "Nausicaä of the Valley of the Wind", 8, 7, "Happy");
	insertAtTail(tail, "Action", "Lethal Weapon", 7, 18, "Angry");
	insertAtTail(tail, "Thriller", "The Sixth Sense", 8, 18, "Scared");
	insertAtTail(tail, "Science Fiction", "2001: A Space Odyssey", 8, 7, "Surprised");
	//8
	insertAtTail(tail, "Horror", "The Witch", 7, 17, "Scared");
	insertAtTail(tail, "Anime", "Ghost in the Shell", 8, 16, "Surprised");
	insertAtTail(tail, "Action", "Taken", 8, 17, "Angry");
	insertAtTail(tail, "Thriller", "Seven Samurai", 9, 13, "Happy");
	insertAtTail(tail, "Science Fiction", "The Day the Earth Stood Still", 7, 7, "Surprised");
	//9
	insertAtTail(tail, "Horror", "The Silence of the Lambs", 8, 18, "Scared");
	insertAtTail(tail, "Anime", "Grave of the Fireflies", 9, 12, "Sad");
	insertAtTail(tail, "Action", "Die Hard 2", 7, 17, "Excited");
	insertAtTail(tail, "Thriller", "The Bourne Identity", 8, 13, "Excited");
	insertAtTail(tail, "Science Fiction", "Invasion of the Body Snatchers", 7, 7, "Scared");
	// 45 movies data_set
	}
	// data_set of movies above
	//---------------------------------------------------------------------------------------data set here
	
	
	int genre; // for chossing genre
	int movie_to_wath; //sellecting which movie to watch
	bool prohibited = false;
	
	while(user_logged_in){
		cout<<"Welcome "<<user.getname()<<"! "; // welcome msg for usser
		cout<<"In which genre do you want to dive in ?"<<endl;
		cout<<"1. Horror"<<endl<<"2. anime"<<endl<<"3. Action"<<endl<<"4. Thriller"<<endl<<"5. science fiction"<<endl<<"6. exit the program"<<endl;
		cin>>genre; //for chossing genre
		if(genre == 1){
			printList(head, user, prohibited);
			if(prohibited == false){
				cout<<"which movie would you like to watch ?";
				cout<<endl;
				cin>>movie_to_wath;
			}
		}
		else if(genre == 2){
			// we created temp head here so we dose not change the orignal head
			Node* temp_head = head; 
			temp_head = temp_head->next;
			printList(temp_head, user, prohibited);
			if(prohibited == false){
				cout<<"which movie would you like to watch";
				cout<<endl;	
				cin>>movie_to_wath;
			}
			
		}
		else if(genre == 3){
			Node* temp_head = head; 
			temp_head = temp_head->next->next;
			printList(temp_head, user, prohibited);
			if(prohibited == false){
				cout<<"which movie would you like to watch";
				cout<<endl;
				cin>>movie_to_wath;
			}
		}
		else if(genre == 4){
			Node* temp_head = head; 
			temp_head = temp_head->next->next->next;
			printList(temp_head, user, prohibited);
			if(prohibited == false){
				cout<<"which movie would you like to watch";
				cout<<endl;	
				cin>>movie_to_wath;
			}
		}
		else if(genre == 5){
			Node* temp_head = head; 
			temp_head = temp_head->next->next->next->next;
			printList(temp_head, user, prohibited);
			if(prohibited == false){
				cout<<"which movie would you like to watch";
				cout<<endl;
				cin>>movie_to_wath;	
			}
		}
		else if(genre == 6){
			user_logged_in = false;
			cout << "\033[1;32m";
			cout<<"Thanks for using movie maven"<<endl;
			cout<<"Made with love by Prateek, Kartikay and Aryan";
			cout<<endl;
			cout << "\033[0m"<<endl;
		}
		else{
			cout<<"Enter valid number";
		}
		
		if(prohibited == false && user_logged_in == true){ // this if statement stops small kids to watch movies
			cout << "\033[1;32m"<<endl;
			cout<<"you are currently watching "<<movie_name(head, user, genre, movie_to_wath)<<".... ";
			cout << "\033[0m"<<endl<<endl;
			cout<<"How much rating would you like to give this movie between 0 - 5"<<endl;
			int movie_ratting; // how much will user rate this movie
			cin>>movie_ratting;
			cout<<"Thanks for your feed back we are working on it"<<endl<<endl;
			cout << "\033[1;32m"<<endl;
			cout << "Press any key to continue...";
    		_getch();
    		cout << "\033[0m"<<endl<<endl;
			
			cout<<"after sorting the movies on the basis of ratting and age limmit"<<endl;
			printList(genre, head, user, prohibited);
			cout<<"you may also like these movies to!..."<<endl<<endl;
			string movie_emotion = emotion_of_movie(head, user, genre, movie_to_wath);
			recommand_movie(head,user, movie_emotion);
			cout << "\033[1;32m"<<endl;
			cout << "Press any key to continue...";
    		_getch();
    		cout << "\033[0m"<<endl<<endl;
    		cout<<"movies you have already watched..."<<endl;
    		if(!find_movie(movies_watched, head, user, genre, movie_to_wath)){
    			movies_watched[movie_watched_counter] = movie_name(head, user, genre, movie_to_wath);
    			movie_watched_counter++;
			}
			for(int i = 0; i<movie_watched_counter; i++){
				cout<<movies_watched[i]<<" | ";
			}
			cout<<endl;
			cout<<endl;
			updateMovieRating(head, user, genre, movie_to_wath, movie_ratting); //will update the movie ratting;
			sort_movies(head, genre);
    		
		}
	}
	return 0;
}
