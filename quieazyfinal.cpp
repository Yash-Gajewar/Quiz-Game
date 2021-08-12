#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;

class question
{
public:
  string Question_text;
  string option1;
  string option2;
  string option3;
  string option4;

  int correct_answer;
  int score;

  public :
  void set_values()
  {
    cin.ignore();
    cout<<"\t\tEnter question: "<<endl;
    getline(cin, Question_text);

    cout<<"\t\tEnter option 1: "<<endl;
    getline(cin, option1);
    cout<<"\t\tEnter option 2: "<<endl;
    getline(cin, option2);
    cout<<"\t\tEnter option 3: "<<endl;
    getline(cin, option3);
    cout<<"\t\tEnter option 4: "<<endl;
    getline(cin, option4);

    cout<<"\n\n\t\tEnter correct option number: "<<endl;
    cin>>correct_answer;
    cout<<"\t\tEnter marks of that question: "<<endl;
    cin>>score;
  }

  void display()
  {
    cout<<"\t\tquestion: "<<Question_text<<endl;
    cout<<"\t\toption1: "<<option1<<endl;
    cout<<"\t\toption2: "<<option2<<endl;
    cout<<"\t\toption3: "<<option3<<endl;
    cout<<"\t\toption4: "<<option4<<endl;
  //  cout<<"\t\tPosition of correct answer: "<<correct_answer<<endl;
    cout<<"\t\tScore: "<<score<<endl;
  }
};

class student
{
public:
  string name;
  char roll_id [30];
  int gamepin;
  int score=0;
  int guess;
  char student_response[5];


public:
  void student_data()
  {
    cin.ignore();
    cout<<"\n\n\t\tEnter your name / nickname: "<<endl;
    getline(cin,name );
    cout<<"\n\n\t\tEnter your roll id: "<<endl;
    cin>>roll_id;
    /*
    cout<<"Enter gamepin: "<<endl;
    cin>>gamepin;
    cout<<"Enter score: "<<endl;
    cin>>score;
    cout<<"Enter guess: "<<endl;
    cin>>guess;
    cout<<"Enter response: "<<endl;
    cin>>student_response;
    */
  }



  void display_student_data()
  {
    cout<<"Nickname: "<<name<<endl;
    cout<<"Roll id: "<<roll_id<<endl;
    cout<<"gamepin: "<<gamepin<<endl;
    cout<<"score: "<<score<<endl;
    cout<<"guess: "<<guess<<endl;
    cout<<"yes or no: "<<student_response<<endl;

  }

  void answer_quiz()
  {
      cout<<"Enter your guess: "<<endl;
      cin>>guess;
      cout<<guess<<endl;
  }
};

class teacher
{
public:
  string name;
  string subject;
  int subject_code;

public:
  void teacher_info()
  {

    cin.ignore();
    cout<<"1.Enter your name: "<<endl;
    getline(cin, name);
    cout<<"2.Enter your subject of quiz: "<<endl;
    getline(cin, subject);
    cout<<"3.Enter subject code: "<<endl;
    cin>>subject_code;
    cout<<"\n\n\t\tThis subject code "<<subject_code<<" will be later used as game pin"<<endl;


  }

  void display_tacher_data()
  {
    cout<<"1.Name: "<<name<<endl;
    cout<<"2.subject: "<<subject<<endl;
    cout<<"3.Subject code: "<<subject_code<<endl;

  }
};

void app_info()
{
  cout<<"\n\n\t\tThis software is designed and developed by Yash Gajewar in second year; studying at Vidyalankar Polytechnic."<<endl;
  cout<<"\t\tThis software is exclusively designed for schools, colleges and universities for conducting secured quizes on a regular basis with ease."<<endl;
  cout<<"\t\tThis software is mainly focused on teachers and students for performing quizes"<<endl;
  cout<<"\t\tMorever it can also be used by the students for revising their term work and test their knowledge."<<endl;
  cout<<"\n\n\t\tThe instruction of this software are as follows: "<<endl;
  cout<<"\t\t1. Teacher has to fill their details and create a quiz along with their correct options and marks."<<endl;
  cout<<"\t\t2. Students has to fill in their details and solve the quiz along by choosing the correct option."<<endl;
  cout<<"\t\t3. The score of each student is displayed after every question and final score is displayed after the completion of the quiz"<<endl;
  cout<<"\t\t4. Students are requested to read the question patiently and answer the question wisely."<<endl;
  cout<<"\t\tThat's it !!!!"<<endl;
  cout<<"\t\tThank you for using this app !!!"<<endl;
  cout<<"\t\t:) :) :)"<<endl;
}

int main()
{
  char start_quiz [5];
  int login_choice;
  question q[100];
  int number_of_questions = 0;
  student s[100];
  teacher t1;
  fstream fout;
  fout.open("quieazyBackup.txt", ios :: app);

    cout<<"\n\n\t\t\t******************************************************************"<<endl;

    cout<<"\n\t\t\t\t\t\tWelcome to quieazy"<<endl;

    cout<<"\n\n\t\t\t******************************************************************"<<endl;

    cout<<"\n\n\n\t\t\t\t!!!!!!!Are you ready to play Quieazy !!!!!!? "<<endl;
    cin>>start_quiz;


if(strcmp(start_quiz, "yes")==0)
{


do{
  cout<<"\n\n\n\t\tWho are you: "<<endl;
  cout<<"\t\t1.Teacher"<<endl;
  cout<<"\t\t2.Student"<<endl;
  cout<<"\t\t3.About App"<<endl;
  cout<<"\t\t4.Exit"<<endl;
  cout<<"\t\tEnter your choice ( 1 // 2 // 3 // 4)"<<endl;
  cin>>login_choice;


    switch(login_choice)
    {

      case 1:
        system("cls");
        int teacher_choice;

        t1.teacher_info();
        fout<<"Name of teacher: "<<t1.name<<endl;
        fout<<"Name of subject1: "<<t1.subject<<endl;
        fout<<"Subject code: "<<t1.subject_code<<endl;
        //t1.display_tacher_data();
        cout<<"\n\n\n\t\tWhat do you wish to do? "<<endl;
        cout<<"\t\t1.Create Quiz"<<endl;
        cout<<"\t\t2.Back to main menu"<<endl;
        cout<<"\t\t3.Exit"<<endl;
        cin>>teacher_choice;
        //cout<<teacher_choice<<endl;

                if(teacher_choice==1)
                {

                    cout<<"\t\tHow many question you wish to ask in your quiz?\n\t\tYou can create maximum one hundred questions. "<<endl;
                    cin>>number_of_questions;
                  //  cout<<number_of_questions<<endl;
                    for(int i=0; i<number_of_questions; i++)
                    {
                      cout<<"\n\n\t\t"<<endl;
                      q[i].set_values();

                    }
                    fout<<t1.name<<" created "<<t1.subject<<" quiz successfully"<<endl;
                    cout<<"\n\n\t\t................Quiz created succesfully....................\n\n\n"<<endl;
                    cout<<"\t\tBack to main menu"<<endl;

                }

                else if(teacher_choice==2){
                fout<<"Logged in but not created quiz"<<endl;
                break;
              }

                else
                {
                fout<<"Logged in but not created quiz"<<endl;
                exit (0);
                }

                break;



                case 2:
                system("cls");
                if(number_of_questions == 0)
                {
                  cout<<"\n\n\t\tThere is no quiz prepared !!!!"<<endl;
                }
                else{
                cout<<"\n\n\t\t"<<t1.subject<<" quiz is pending !!"<<endl;
                for(int i=0; i<500; i++)
                {
                s[i].student_data();
                fout<<"Student name: "<<s[i].name<<endl;
                fout<<"Student roll: "<<s[i].roll_id<<endl;
                //s1.display_student_data();

                cout<< "\n\n\t\t"<<s[i].name<<" Are you ready to play the quiz? (yes // no)"<<endl;
                cin>>s[i].student_response;

              if(strcmp(s[i].student_response, "yes")==0)
                  {

                    cout<<"\n\t\tEnter gamepin (subject code): "<<endl;
                    cin>>s[i].gamepin;

                    if(s[i].gamepin==t1.subject_code)
                    {

                    cout<<"\n\n........!!!! Good Luck !!!!................"<<endl;
                    cout<<"\n\n\t\tHere are your set of questions : "<<endl;
                    for(int j=0; j<number_of_questions; j++)
                    {
                      cout<<"\n\t\tQuestion Number "<<j+1<<" :"<<endl;
                      q[j].display();
                      cout<<"\n\t\tEnter your guess: "<<endl;
                      cin>>s[i].guess;

                      if(s[i].guess == q[j].correct_answer)
                      {
                        cout<<"\n\t\tHurray correct answer!!!"<<endl;
                        s[i].score = s[i].score + q[j].score;
                        cout<<"\n\t\t"<<s[i].name<<" Your current score: "<<s[i].score<<endl;
                      }

                      else
                      {
                        cout<<"\n\t\t:( :( :( Sorry wrong answer\n\t\tThe correct option is "<<q[j].correct_answer<<endl;
                        cout<<"\n\t\tYou can still redeem yourself\n"<<endl;
                        s[i].score = s[i].score + 0;
                        cout<<"\n\t\t"<<s[i].name<<" your current score: "<<s[i].score<<endl;

                      }


                    }

                    cout<<"\n\t\t"<< s[i].name <<" Your final score: "<<s[i].score<<endl;
                    fout<<s[i].name<<" final result: "<<s[i].score<<endl;
                    char response [5];
                    cout<<"\n\t\tReady next student ?  "<<endl;
                    cin>>response;

                    if(strcmp(response, "no") == 0)
                    {
                      cout<<"\n\t\tBack to main menu "<<endl;
                      break;
                    }


                    }

                    else
                    {


                    cout<<"\n\t\tYour game pin is wrong !!!"<<endl;
                    fout<<s[i].name<<" Entered wrong game pin"<<endl;
                    cout<<"\n\t\tTry again :( :( :("<<endl;
                  }

                }

                else{
                  char response [5];
                  cout<<"\n\t\tBe prepared next time!!"<<endl;
                  fout<<s[i].name<<" Logged in but not submitted the quiz"<<endl;
                  cout<<"\n\t\tReady next student ?  "<<endl;
                  cin>>response;


                  if(strcmp(response, "no") == 0){
                    cout<<"\n\t\tBack to main menu "<<endl;
                    break;
                  }

                  system("cls");

                }

              }
            }

                break;


                case 3:
                system("cls");
                app_info();
                break;


                case 4:
                fout.close();
                return 0;



                default :
                cout<<"\n\n\t\tInvalid choice !! "<<endl;

              }




}while(login_choice!=3);


}

else{
  cout<<"\t\t\t\t ************* We are sorry ****************"<<endl;
  cout<<"\t\t\t\t *************:(:(:(:(:( ****************"<<endl;

  return 0;
}

  fout.close();
  return 0;

}
