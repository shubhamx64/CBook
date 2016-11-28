#include <iostream.h>
#include <conio.h>
#include <process.h>
#include <string.h>
#include <math.h>
#include <stdio.h>

#define TRUE 1
#define FALSE 0



struct conversation{
  int chat_uid;
  int no_messages;
  char** list;
  char** sender_list;

  conversation()
  {
    no_messages = 0;
    list = new char*[10];
    sender_list = new char*[10];
    for(int a = 0; a < 10; ++a)
    {
      list[a] = new char[100];
      sender_list[a] = new char[10];
    }
    chat_uid = 0;
  }

  void addmessage(char* msg_inp, char* sender)
  {
     strcpy(list[no_messages],msg_inp);
     strcpy(sender_list[no_messages], sender);
     ++no_messages;
  }
};


struct cdb
{
conversation chat_db_list[20];
int total_chats;

chatdb()
{
  total_chats =0;
}
}chat_db;


struct Like
{
  char name[20];
};

struct FrndRqst
{
  int u_UID;
};

struct Display_name{
  int index;
  int sn;
  int u_UID;
};

struct Notifications{
 int no_likes;
 Like like [10];
 int no_dislikes;
 Like dislike[10];
 int no_friend_request;
 FrndRqst frnd[10];
 Notifications()
 {
   no_likes = 0;
   no_dislikes = 0;
   no_friend_request = 0;
 }
};

struct Post{
  char post[200];
  int likes;
  int dislikes;
  int posted_by_uid;

  Post()
  {
    likes = 0;
    dislikes = 0;
  }
};

struct Post_db
{
  int size;
  Post all_posts[100];

  Post_db()
  {
    size = 0;
  }
}master_post_db;

struct NewsFeed{
   int size;
   Post feed[20];

   NewsFeed()
   {
      size = 0;
   }
};


struct user{
  char email[100];
  char pass[10];
  char first_name[15];
  char sec_name[15];
  int age;
  int u_UID;
  int friend_list[50];
  int no_of_frnds;
  Notifications noti;

  user()
  {
    no_of_frnds = 0;
    for(int i = 0; i < 50; ++i)friend_list[i] = 0;
  }
}current;

struct DB{
  user* users;
  int size, curr_users;
  DB(){size = 2; curr_users = 0; users = new user[2];}

  void add(user temp)
  {
    if(curr_users < size)
    {
      users[curr_users] = temp;
       ++curr_users;
       return;
    }
    else
    {
      user* temp_arr = new user[size];
      for(int a = 0; a < curr_users; a++)
      {
	 temp_arr[a] = users[a];
      }
      delete users;
      users = new user[size+1];
      for(int b = 0; b < curr_users; b++)
      {
	users[b] = temp_arr[b];
      }
      users[b] = temp;
      ++size;
      ++curr_users;
      delete temp_arr;
    }
   }
} MasterDB;


void filldb();
int welcome();
int login();
void signup();
void initalize();
void enter_pass(char*);
int gen_uid(char*, char*);
int get_index(int);
char* get_firstname(int);
int MainMenu();
int Suggested_friends();
int edit_info();
int write_post();
int print_newsfeed();
void edit_post(Post);
int chatting();
int notifications_display();
void accept_frnd();


void filldb()
{
  Post temp_post;
  {
	strcpy(temp_post.post,"Hey! This is a sample post!");
	temp_post.likes = 10;
	temp_post.dislikes = 3;
	temp_post.posted_by_uid = gen_uid("shubham.lumia@gmail.com","shubham");
	master_post_db.all_posts[master_post_db.size] = temp_post;
	++master_post_db.size;
  }

  {
	strcpy(temp_post.post,"Mera Program nahi chal raha :/");
	temp_post.likes = 200;
	temp_post.dislikes = 0;
	temp_post.posted_by_uid = gen_uid("mehak.jeet@gmail.com","struct");
	master_post_db.all_posts[master_post_db.size] = temp_post;
	++master_post_db.size;
  }

  {
	strcpy(temp_post.post,"I am trying my best to finish CBook!");
	temp_post.likes = -999;
	temp_post.dislikes = -999;
	temp_post.posted_by_uid = gen_uid("shubham.lumia@gmail.com","shubham");
	master_post_db.all_posts[master_post_db.size] = temp_post;
	++master_post_db.size;
  }

  user temp;

   {
     strcpy(temp.email, "shubham.lumia@gmail.com");
     strcpy(temp.pass, "shubham");
     strcpy(temp.first_name, "Shubham");
     strcpy(temp.sec_name, "Srivastava");
     temp.age = 16;
     temp.u_UID = gen_uid(temp.email, temp.pass);
     //temp.friend_list[temp.no_of_frnds] = 2010;
     //++temp.no_of_frnds;
     MasterDB.add(temp);
   }

   {
     strcpy(temp.email, "mehak.jeet@gmail.com");
     strcpy(temp.pass, "struct");
     strcpy(temp.first_name, "Mehak");
     strcpy(temp.sec_name, "Sharma");
     temp.age = 16;
     temp.u_UID = gen_uid(temp.email, temp.pass);
     MasterDB.add(temp);
   }

   {
     strcpy(temp.email, "devesh.razdan12@gmail.com");
     strcpy(temp.pass, "fax");
     strcpy(temp.first_name, "Devesh");
     strcpy(temp.sec_name, "Razdan");
     temp.age = 16;
     temp.u_UID = gen_uid(temp.email, temp.pass);
     MasterDB.add(temp);
   }

   {
     strcpy(temp.email, "mehak.jeet@gmail.com");
     strcpy(temp.pass, "struct2");
     strcpy(temp.first_name, "Mehak");
     strcpy(temp.sec_name, "Jeet");
     temp.age = 16;
     temp.u_UID = gen_uid(temp.email, temp.pass);
     MasterDB.add(temp);
   }

   {
     strcpy(temp.email, "yash@gmail.com");
     strcpy(temp.pass, "android");
     strcpy(temp.first_name, "Yashvardhan");
     strcpy(temp.sec_name, "Kumar");
     temp.age = 16;
     temp.u_UID = gen_uid(temp.email, temp.pass);
     MasterDB.add(temp);
   }

   {
     strcpy(temp.email, "shrija@gmail.com");
     strcpy(temp.pass, "swapnil");
     strcpy(temp.first_name, "Shrija");
     strcpy(temp.sec_name, "Swapnil");
     temp.age = 16;
     temp.u_UID = gen_uid(temp.email, temp.pass);
     MasterDB.add(temp);
   }

   {
     strcpy(temp.email, "kabirkanha@gmail.com");
     strcpy(temp.pass, "kkk");
     strcpy(temp.first_name, "Kabir");
     strcpy(temp.sec_name, "Arora");
     temp.age = 17;
     temp.u_UID = gen_uid(temp.email, temp.pass);
     temp.no_of_frnds = 6;
     //temp.friend_list[temp.no_of_frnds] = -20347;
     //++temp.no_of_frnds;
     MasterDB.add(temp);
   }
}

void initalize()
{
  MasterDB.size = 0;
}

int welcome()
{
  redo2:
  clrscr();
  int num = 0;
  cout << "Welcome to CBook.";
  cout << "\n\n1. Login";
  cout << "\n2. Sign Up";
  cout << "\n3. Exit";
  redo:
  cout << "\n\nEnter Choice: ";

  cin >> num;
  int lop;
  if(num == 1)
  {
	int ret = login();

	if(ret == TRUE)
	{
		cout << "\nLogged in";
		//cout << current.u_UID;
		cout << "\nPress any key to continue";
		getch();
		lop = MainMenu();
		if(lop == FALSE) goto redo2;
		//return ret;
	}

	else
	{
		cout << "\nAccount not found";
		cout << "\nPress any key to continue";
		getch();
		goto redo2;
	}
  }

  if(num == 2)
  {
	signup();
	goto redo2;
  }

  if(num == 3)exit(0);

  if(num < 1 || num > 3) { cout << "\nInvalid Choice"; goto redo; }
}

void enter_pass(char* pa)
{
   char kp;      // s

   for(int a = 0; a < 10; ++a)
   {
      kp = getch();

	 if(kp == '\b')
	 {
	    --a;
	    cout << " \b";
	    continue;
	 }

	 else if(kp != '\r')
	 {
	   pa[a] = kp;
	   cout << "*";
	 }

	 else if(kp == '\r')
	 {
	   break;
	 }
   }
   pa[a] = '\0';
}

int login()
{
  clrscr();
  char id[100];
  char pass[10];
  cout << "Login In";
  cout << "\n\nEnter Email ID: "; cin >> id;
  cout << "\nEnter Password: "; enter_pass(pass);
  int temp = gen_uid(id, pass), flag = FALSE;

  for(int b = 0; b < MasterDB.curr_users; ++b)
  {
    if(temp == MasterDB.users[b].u_UID)
    {
	flag = TRUE;
	break;
    }
  }

  if(flag == TRUE)
  {
    current = MasterDB.users[b];
  }
  return flag;
}

void signup()
{

  clrscr();
  user new_user;
  char tpass[10];
  cout << "\nSign Up";
  cout << "\n\nWelcome to CBook! To Sign Up, Enter the following: ";
  cout << "\nFirst Name: "; cin >> new_user.first_name;
  cout << "\nLast Name: "; cin >> new_user.sec_name;
  cout << "\nEmail Address: "; cin >> new_user.email;
  redo1:
  cout << "\nPassword: "; enter_pass(new_user.pass); cout << "\n";
  cout << "\nRe-Enter Password: "; enter_pass(tpass); cout << "\n";
  if(strcmp(new_user.pass,tpass) != 0)
  {
     cout << "\nPasswords don't match. Please re-enter.\n";
     goto redo1;
  }
  cout << "\nAge: "; cin >> new_user.age;
  new_user.u_UID = gen_uid(new_user.email, new_user.pass);
  MasterDB.add(new_user);
  cout << "\n\nAccounts succesfully created.\n";
  cout << "\nPlease Login to continue.";
  getch();
}


int gen_uid(char* email, char* pass)
{

  int id = 0;
  for(int a = 0; email[a] != '\0'; ++a)
  {
     id += email[a] * pow(2,a);
  }
  for(int b = 0; pass[b] != '\0'; ++b)
  {
     id += pass[b] * pow(3,b);
  }
  return id;
}

int gen_uid2(char* email, char* pass)
{
  //cout << "\n\n****Asked to gen chat id with: \n" << email << " and "  << pass;
  //getch();

  int id = 0;
  for(int a = 0; email[a] != '\0'; ++a)
  {
     id += email[a] * pow(2,a);
  }
  for(int b = 0; pass[b] != '\0'; ++b)
  {
     id += pass[b] * pow(2,b);
  }
  return id;
}

int MainMenu()
{
  is_start:
  clrscr();

  int num;

  cout << "Welcome to CBook.";   //ACCEPT FRND RQST: DONE
  cout << "\n\nGood Morning, "<< current.first_name << "! :)";
  cout << "\n\n1. Notifications";     //DONE
  cout << "\n2. News Feed";  //DONE
  cout << "\n3. Chat";      //DISPLAY WRAPPER
  cout << "\n4. Edit Info";  //DONE
  cout << "\n5. Suggested Friends"; //ALMOST DONE?
  cout << "\n6. Post";  //DONE
  cout << "\n7. Logout"; //DONE
  redo3:
  cout << "\n\nEnter Choice: ";
  cin >> num;
  int lop;
  //int restart = 0;
  switch(num)

  {

	case 1:
	{
		lop = notifications_display();
		break;
	}

	case 2:
	{
		lop = print_newsfeed();
		break;
	}

	case 3:
	{
		lop = chatting();
		break;
	}

	case 4:
	{
		lop = edit_info();
		if(lop == FALSE)return FALSE;
		break;
	}

	case 5:
	{
		lop = Suggested_friends();
		break;
	}

	case 6:
	{
		lop = write_post();
		break;
	}

	case 7:
	{
		clrscr();
		cout <<  "Succesfully Logged Out";
		cout << "\nPress any key to continue";
		lop = FALSE;
		getch();
		return FALSE;
		break;
	}
  }

  if(lop = TRUE) goto is_start;
  else return FALSE;
  //if(restart == 1) return TRUE;
}

int notifications_display()
{
  clrscr();
  cout << "\nHere Are Your Notifications: " <<  current.noti.no_likes;
  //cout << "\n\n" << current.noti.no_likes << " People liked your posts";

  //if(current.noti.no_likes !=0)
  {
  for(int aa = 0; aa < current.noti.no_likes; ++aa)
  {
     cout << "\n" << current.noti.like[aa].name << " liked your post";
  }
  }
  //cout << "\n" << current.noti.no_dislikes << " People Diskliked your posts";

  if(current.noti.no_likes != 0)cout << "\n\n";

  //if(current.noti.no_dislikes != 0)
  {
  for(int aa = 0; aa < current.noti.no_dislikes; ++aa)
  {
     cout << "\n" << current.noti.dislike[aa].name << " disliked your post";
  }
  }
  if(current.noti.no_dislikes != 0)cout << "\n\n";
  cout << "\n" << current.noti.no_friend_request << " People want to be friends with you";
  cout << "\n\n" << "Do you want to see who wants to be friedns with you? (Y/N)";
  try7:
  cout << "\nEnter Your choice: ";
  char d;
  cin >> d;
  switch (d)
  {

     case 'n':
     {
       current.noti.no_likes = 0;
       current.noti.no_dislikes = 0;
       break;
     }

     case 'N':
     {
       current.noti.no_likes = 0;
       current.noti.no_dislikes = 0;
       break;
     }

     case 'y':
     {
       current.noti.no_likes = 0;
       current.noti.no_dislikes = 0;
       accept_frnd();
       break;
     }

     case 'Y':
     {
       current.noti.no_likes = 0;
       current.noti.no_dislikes = 0;
       accept_frnd();
       break;
     }

     default:
     {
       cout << "\nInvalid Choice. Please Try Again.";
       cout << "\nPress any key to coninue.";
       getch();
       goto try7;
     }
  }
  return TRUE;
}

void accept_frnd()
{
   clrscr();
   cout << "\nHere Are The People who want to be friends with you: ";
   int sno = 1;
   for(int a = 0; a < current.noti.no_friend_request; ++a, ++sno)
   {
     cout << "\n" << sno << ". " << get_firstname(current.noti.frnd[a].u_UID);
   }
   cout << "\n" << sno << ". Back";
   int qwe;
   try92:
   cout << "\n\n"  << "Enter your choice: ";
   cin >> qwe;
   if(qwe == sno)
   {
     MainMenu();
   }
   if(qwe > sno)goto try92;
   --qwe;


   current.friend_list[current.no_of_frnds] = current.noti.frnd[qwe].u_UID;
   ++current.no_of_frnds;
   int ind = get_index(current.noti.frnd[qwe].u_UID);
   MasterDB.users[ind].friend_list[MasterDB.users[ind].no_of_frnds] = current.u_UID;
   //++current.noti.frnd[qwe].no_of_frnds;
   ++MasterDB.users[ind].no_of_frnds;
   cout << "\nYou becmae friends with: " << MasterDB.users[ind].first_name;
   cout << "\nPress any key to continue";
   /*int del = MasterDB.users[ind].u_UID;
   int lshift;
   for(int h = 0; h < current.noti.no_friend_request; ++h)
   {
	if(current.noti.frnd[h].u_UID == del)
	{
	lshift = h;
	break;
	}
   }

   cout << "\nYou erased: " <<get_firstname(current.noti.frnd[lshift].u_UID);

   for(h = lshift; h < current.noti.no_friend_request; ++h)
   {
	//if(current.noti.frnd[h] == del)lshift = h;
	current.noti.frnd[h].u_UID = current.noti.frnd[h+1].u_UID;
   }  */
   --current.noti.no_friend_request;
   getch();
   return;
}



int chatting()
{
  clrscr();
  cout << "\nAvailable Friends: ";
  int sno = 1, inde = 0;
  Display_name* display = new Display_name[current.no_of_frnds];
  for(int b = 0; b < MasterDB.curr_users; ++b)
  {
   for(int c = 0; c < current.no_of_frnds; ++c)
    {
	if(MasterDB.users[b].u_UID == current.friend_list[c] && MasterDB.users[b].u_UID != current.u_UID)
	{
	cout << "\n" << sno << ". " << MasterDB.users[b].first_name << " " << MasterDB.users[b].sec_name;
	display[inde].index = b;
	display[inde].sn = sno;
	display[inde].u_UID =  MasterDB.users[b].u_UID;
	++sno;
	++inde;
	}
    }
  }
  cout << "\n" << sno << ". Back";
  cout << "\nFrnds: " << current.no_of_frnds;
  if(current.no_of_frnds == 0)
  {
	cout << "\nYou're soooo lonely :P";
	cout << "\nGo back and select \"suggested friends\" to get some suggestions!";
  }
  int input, choice = 0;
  cout << "\n\n\nEnter Choice: ";
  cin >> input; --input;
  if(input+1 == sno)
  {
     return TRUE;
  }
  /*for(int a = 0; a < MasterDB.curr_users; ++a)
  {
    for(int d = 0; d < current.no_of_frnds; ++d)
    {
	if(MasterDB.users[a].u_UID != current.friend_list[d] && MasterDB.users[a].u_UID != current.u_UID)
	{
	   ++choice;
	   if(choice == input)break;
	}
	if(choice == input)break;
    }
    if(choice == input)break;
  } */
  choice = display[input].index;
  int chat_temp_uid = gen_uid2(current.first_name, MasterDB.users[choice].first_name);
  int chat_index = -1;
  for(int z = 0; z < chat_db.total_chats; ++z)
  {
    if(chat_db.chat_db_list[z].chat_uid == chat_temp_uid)
    {
      chat_index = z;
      break;
    }
  }
  if(chat_index == -1)
  {
    chat_db.chat_db_list[chat_db.total_chats].chat_uid = gen_uid2(current.first_name, MasterDB.users[choice].first_name);
    chat_index = chat_db.total_chats;
    ++chat_db.total_chats;
  }
  //////WRITE The chat display wrapper
  //chat_db.chat_db_list[chat_db.total_chats]
  /////you have the converssation to deal with
  clrscr();
  cout << "Your chat with: " <<MasterDB.users[choice].first_name;
  for(int ab = 0; ab < chat_db.chat_db_list[chat_index].no_messages; ++ab)
  {
    cout << "\n" << chat_db.chat_db_list[chat_index].sender_list[ab] << ": ";
    cout << "\n" << "\"" << chat_db.chat_db_list[chat_index].list[ab] << "\"";
    cout << "\n";
  }
  cout << "\n\nEnter Your Message: ";
  char temp_msg[100];
  gets(temp_msg);
  chat_db.chat_db_list[chat_index].addmessage(temp_msg, current.first_name);
  //++chat_db.chat_db_list[chat_index].no_messages;
  cout << "\n\nMessage sent succesfully.";
  cout << "\nPress any key to continue.";
  getch();
  delete display;
  return TRUE;
}

void chat_display_writer()
{

}

char* get_firstname(int id)
{
  for(int b = 0; b < MasterDB.curr_users; ++b)
  {
    if(MasterDB.users[b].u_UID == id)
    {
       return MasterDB.users[b].first_name;
    }
  }
}

int get_index(int id)
{
  for(int b = 0; b < MasterDB.curr_users; ++b)
  {
    if(MasterDB.users[b].u_UID == id)
    {
       return b;
    }
  }
}

int print_newsfeed()
{
  clrscr();
  cout << "\nCbook NewsFeed";
  cout << "\n\n";
  for(int i = 0; i < master_post_db.size; ++i)
  {
     cout << "\n\n" << i+1 << ". \"" << master_post_db.all_posts[i].post<<"\"";
     cout << "\nPosted by: " <<  get_firstname(master_post_db.all_posts[i].posted_by_uid);
     cout << "\nLikes: " << master_post_db.all_posts[i].likes;
     cout << "\nDislikes: " << master_post_db.all_posts[i].dislikes;
  }
  cout << "\n\n" << i+1 << ". Back";
  cout << "\n\nEnter The Post You Want To interact with ";
  int ch;
  cin >> ch;
  --ch;
  if(ch != master_post_db.size) edit_post(master_post_db.all_posts[ch]);
  else return TRUE;
  return TRUE;
}

void edit_post(Post temp_p)
{
   clrscr();
   cout << "\""<<temp_p.post<<"\"";
   cout << "\nPosted by: " <<  get_firstname(temp_p.posted_by_uid);
   cout << "\nLikes: " << temp_p.likes;
   cout << "\nDislikes: " << temp_p.dislikes;
   ret5:
   cout << "\n\n";
   cout << "\n1. Like";
   cout << "\n2. Dislike";
   cout << "\n3. Back";
   cout << "\nEnter Your Choice: ";
   int ch;
   cin >> ch;
   if(ch == 1)
   {
      temp_p.likes++;
      int ind = get_index(temp_p.posted_by_uid);
      strcpy(MasterDB.users[ind].noti.like[MasterDB.users[ind].noti.no_likes].name,current.first_name);
      ++MasterDB.users[ind].noti.no_likes;
      //cout << "\nNotified:  " << MasterDB.users[ind].first_name << "  " << MasterDB.users[ind].noti.no_likes << " " << get_firstname(temp_p.posted_by_uid);
   }

   else if(ch ==  2)
   {
      temp_p.dislikes++;
      int ind = get_index(temp_p.posted_by_uid);
      strcpy(MasterDB.users[ind].noti.dislike[MasterDB.users[ind].noti.no_dislikes].name,current.first_name);
      ++MasterDB.users[ind].noti.no_dislikes;
   }
   else if(ch ==  3)
   {
      cout << "\nPress Any key to continue";
      getch();
      return;
   }
   else goto ret5;
}

int write_post()
{
  clrscr();
  cout << "\nWrite Your Post: \n";
  gets(master_post_db.all_posts[master_post_db.size].post);
  master_post_db.all_posts[master_post_db.size].posted_by_uid = current.u_UID;
  ++master_post_db.size;
  cout << "\n\nPost Succesfully Recoreded";
  cout << "\nPress Any Key To Coninue.";
  getch();
  return TRUE;
}

int Suggested_friends()
{
  clrscr();
  cout << "\nSuggested Friends: ";
  int sno = 1, flag = 0, inde = 0;
  Display_name* display = new Display_name[MasterDB.curr_users - current.no_of_frnds + 1];
  for(int b = 0; b < MasterDB.curr_users; ++b)
  {
    for(int c = 0; c < current.no_of_frnds; ++c)
    {
	if(MasterDB.users[b].u_UID == current.friend_list[c])
	{
	   flag = 1;
	}
    }
    for(int d =0; d < MasterDB.users[b].noti.no_friend_request; ++d)
    {
       if(MasterDB.users[b].noti.frnd[d].u_UID == current.u_UID)
	{
	   flag = 1;
	}
    }
    if(flag == 1)
    {
       flag = 0;
       continue;
    }
    if(MasterDB.users[b].u_UID == current.u_UID)
    {
       continue;
    }
    //if(MasterDB.users[b].u_UID != current.u_UID)
    {
	cout << "\n" << sno << ". " << MasterDB.users[b].first_name << " " << MasterDB.users[b].sec_name;
	display[inde].index = b;
	display[inde].sn = sno;
	display[inde].u_UID = MasterDB.users[b].u_UID;
	++inde;
	++sno;
    }
  }

  cout << "\n" << sno << ". Back";
  int input, choice = 0;
  gh:
  cout << "\n\n\nEnter Choice: ";
  cin >> input;
  if(input > sno)
  {
    cout << "\nInvalid choice. Please try again.";
    goto gh;
  }

  --input;

  if(input+1 == sno)
  {
    delete display;
    return TRUE;
  }
  /*for(int a = 0; a < MasterDB.curr_users; ++a)
  {
    for(int d = 0; d < current.no_of_frnds; ++d)
    {
	if(MasterDB.users[a].u_UID != current.friend_list[d] && MasterDB.users[a].u_UID != current.u_UID)
	{
	   ++choice;
	   if(choice == input)break;
	}
	if(choice == input)break;
    }
    if(choice == input)break;
  }*/
  choice = display[input].index;
  MasterDB.users[choice].noti.frnd[MasterDB.users[choice].noti.no_friend_request].u_UID = current.u_UID;
  ++MasterDB.users[choice].noti.no_friend_request;
  cout << "\n\nSuccesfully sent a friend request to:" << get_firstname(MasterDB.users[choice].u_UID);
  cout << "\nPress Any Key To continue";
  getch();
  delete display;
  return TRUE;
}

int edit_info()
{
  clrscr();
  cout << "\nEdit Info";
  cout << "\n\n\nChoose The Field To Edit";
  cout << "\n1. First Name";
  cout << "\n2. Last Name";
  cout << "\n3. Email Address";
  cout << "\n4. Password";
  cout << "\n5. Age";
  cout << "\n6. Back";
  int choice;
  cout << "\n\n\nEnter Choice: ";
  cin >> choice;

   switch(choice)
  {

    case 1:
     {
       clrscr();
       cout <<  "Current First Name: " << current.first_name;
       cout << "\nEnter New First Name: "; cin >> current.first_name;
       break;
     }

    case 2:
    {
       clrscr();
       cout <<  "Current Second Name: " << current.sec_name;
       cout << "\nEnter New Second Name: "; cin >> current.sec_name;
       break;
    }

    case 3:
    {

       clrscr();
       cout <<  "Current Email: " << current.email;
       char email_temp[20];
       cout << "\nEnter New Email: "; cin >> email_temp;
       strcpy(current.email, email_temp);
       /*int old_uid = current.u_UID;
       for(int y = 0; y < current.no_of_frnds; ++y)
       {
	   int index_r = get_index(current.friend_list[y]);
	   int temp_r = MasterDB.users[index_r].no_of_frnds;
	   for(int zz = 0; zz < temp_r; ++zz)
	   {
	       if(MasterDB.users[index_r].friend_list[zz] == old_uid)
	       {
		 MasterDB.users[index_r].friend_list[zz] = current.u_UID;
		 break;
	       }
	   }
       }*/
       current.u_UID = gen_uid(current.email, current.pass);
       //update the UID with EVryone!!!!
       break;
    }

    case 4:
    {

       clrscr();
       char temp_pass[10];
       redo4:
       cout <<  "\nEnter Current Password: "; enter_pass(temp_pass); cout << "\n";
       if(strcmp(current.pass,temp_pass) != 0)
	{
		cout << "\nPasswords don't match. Please re-enter.\n";
		goto redo4;
	}
       cout << "\nEnter New Pass: "; ///make this routine;
       enter_pass(temp_pass);
       strcpy(current.pass, temp_pass);
       int old = current.u_UID;
       current.u_UID =  gen_uid(current.email, current.pass);
       for(int a = 0; a < current.no_of_frnds; ++a)
       {
	 /////////////update the new uid with evryone!
       }
       break;
    }

    case 5:
    {
       clrscr();
       cout <<  "Current Age: " << current.age;
       cout << "\nEner New Age: "; cin >> current.age;
       break;
    }

    case 6:
    {
	cout << "\nPress any key to continue";
	getch();
	return TRUE;
    }
  }

  clrscr();
  cout << "\n\nAccount information succesfully edited.\n";
  cout << "\nPlease Login to continue.";
  getch();
  return FALSE;
}

void main()
{
  clrscr();
  initalize();
  filldb();
  int temp_ret = welcome();
  //if(temp_ret == TRUE)MainMenu();
  getch();
}