#include <iostream>
#include <queue>
#include <list>
using namespace std;
class Hero
{
public:
    string Name = "Az";
    int Failures=3;
    double HealthPoints=100;
    double MentalPoints=10;
    double DumbQuestion=20;
    list <string> Inventory = {"Soleti","Soleti","Pillow","Book","Piko"};
};
class Teacher
{
public:
    string Subject;
    string Title;
    int TeachingSkills;
    double Bonuses[3];
};
struct chas
{
    string subject="unknown";
    int duration =40;
    string type="unknown";

};
void InfoWriter();      ///да записва цялата информация във log.txt файл

void Generator();    /// да генерира произволни стойности за повечето неща, за да не въвеждаме 500 неща на ръка

double RandomNum(int lower, int upper)
{
    double num = (rand() % (upper - lower + 1)) + lower;
    return num;
}
void ActionUsage(queue <chas> day,int &Actions,Hero &Student)
{
    int ItemCounter=0;
    list <string>::iterator i = Student.Inventory.begin();
    /* while(i!=Student.Inventory.end())/// просто брои броя на нещата в инвентара
     {
         if(*i!="")
             ItemCounter++;
         i++;
     }
    */
    if(Actions<1)
        cout<<"You dont have actions"<<endl;
    if(Actions==1)
    {
        if(Student.Inventory.empty())
        {
            cout<<" No items so we meditate"<<endl;
            Student.HealthPoints+=5;
        }
        else if(!Student.Inventory.empty())
        {
            cout<<" Use of item "<<Student.Inventory.front()<<endl;
            Student.Inventory.front().erase();
        }
        Actions--;
    }

    if(Actions==2)
    {
        int temp ;
        cout<<"Type 1) for vafla |  Type 2) for slushane | Type 3) for 3pak soleti "<<endl;
        cin>>temp;

        if(temp==1)
        {
            cout<<" Vafla-> +15hp"<<endl;
            Student.HealthPoints+=15;
        }
        else if(temp==2)
        {
            cout<<"slushame razgovor -> dumb question +1.5"<<endl;
            Student.DumbQuestion+=1.5;
        }
        else  if(temp==3)
        {
            cout<<" zapasqvane sus 3pak soleti + 9hp"<<endl;
            for(int i=0; i<3; i++)
                Student.Inventory.push_front("Soleti");

            Student.HealthPoints+=9;
        }
        else
        {
            cout<<" you havent chosen a valid options "<<endl;
            exit(1);
        }
        Actions-=2;

    }
    if(Actions>=3)
    {
        int temp ;
        cout<<" Type 1) for spane or 2) for uchene "<<endl;
        cin>>temp;
        if(temp==1)
        {
            cout<<" spane -> +20hp "<<endl;
            Student.HealthPoints+= 20;
        }
        else if(temp ==2)
        {
            cout<<"Uchene -> +4 mental  +0.5 dumb question"<<endl;
            Student.MentalPoints+=4;
            Student.DumbQuestion+=0.5;
        }
        else
        {
            cout<<" you havent chosen a valid options ";
            exit(1);
        }
        Actions-=3;
    }
}

Teacher EnterTeacher(string subject="", string title="")
{
    Teacher temp;
    while(1)///за сега ще го правя с един елемент и ще спира(знам че няма смисъл), но после ще го правя със масив от учители(може ги и for loop)
    {
        if(subject=="" && title =="")
        {
            cout<<"Enter info about your teacher (type stop to stop entering)"<<endl;
            cout<<"You can choose Algebra, Analysis, SDP or your own subject"<<endl;
            cout<<"Enter subject: ";
            cin>>temp.Subject;  ///после може да го направим със getline за имена с 2 думи(ама сега да раб
            cout<<"Is he an Lecturer or an assisstant ? ";
            cin>>temp.Title;
        }
        else
        {


            if(temp.Subject=="stop")
                break;

            else if(temp.Subject=="Algebra" || temp.Subject=="algebra" || subject=="Algebra" || subject=="algebra")
            {
                if(temp.Title=="Lecturer" || temp.Title == "lecturer" || title == "lecturer" || title == "Lecturer")
                {
                    cout<<"You have summoned Bozhilov"<<endl;

                    temp.Subject="Algebra";
                    temp.Title="Lecturer";
                    temp.TeachingSkills=29;
                    temp.Bonuses[0]=2;  ///бонус психическа сила
                    temp.Bonuses[1]=3;  ///бонус живот
                    temp.Bonuses[2]=0.1;///въпроси
                    break;
                }
                else if(temp.Title=="Assisstant"|| temp.Title=="assisstant" || title == "Assisstant" || title == "assisstant")
                {
                    cout<<"You have summoned Deyan"<<endl;
                    temp.Subject="Algebra";
                    temp.Title="Assisstant";
                    temp.TeachingSkills=21;
                    temp.Bonuses[0]=1;  ///бонус психическа сила
                    temp.Bonuses[1]=5;  ///бонус живот
                    temp.Bonuses[2]=0.05;///въпроси
                    break;
                }
                else
                {

                    cout<<"You havent chosen a legitimate role"<<endl;
                    exit(1);
                }

            }

            else if(temp.Subject=="Analysis" || temp.Subject=="analysis" || subject=="Analysis" || subject=="analysis")
            {

                if(temp.Title=="Lecturer" || temp.Title == "lecturer" || title == "lecturer" || title == "Lecturer")
                {
                    cout<<"You have summoned Tolev"<<endl;

                    temp.Subject="Analysis";
                    temp.Title="Lecturer";
                    temp.TeachingSkills=23;
                    temp.Bonuses[0]=2;  ///бонус психическа сила
                    temp.Bonuses[1]=3;  ///бонус живот
                    temp.Bonuses[2]=0.2;///въпроси
                    break;
                }
                else if(temp.Title=="Assisstant"|| temp.Title=="assisstant" || title == "Assisstant" || title == "assisstant")
                {
                    cout<<"You have summoned Zhivko"<<endl;
                    temp.Subject="Analysis";
                    temp.Title="Assisstant";
                    temp.TeachingSkills=21;
                    temp.Bonuses[0]=2;  ///бонус психическа сила
                    temp.Bonuses[1]=4;  ///бонус живот
                    temp.Bonuses[2]=0.07;///въпроси
                    break;
                }
                else
                {
                    cout<<"You havent chosen a legitimate title "<<endl;
                    exit(1);
                }
            }

            else if(temp.Subject=="SDP"|| temp.Subject=="sdp" || subject=="sdp" || subject=="SDP")
            {
                if(temp.Title=="Lecturer" || temp.Title == "lecturer" || title == "lecturer" || title == "Lecturer")
                {
                    cout<<"You have summoned Mitaka/Hristo"<<endl;

                    temp.Subject="SDP";
                    temp.Title="Lecturer";
                    temp.TeachingSkills=25;
                    temp.Bonuses[0]=2;  ///бонус психическа сила
                    temp.Bonuses[1]=3;  ///бонус живот
                    temp.Bonuses[2]=0.2;///въпроси
                    break;
                }
                else if(temp.Title=="Assisstant"|| temp.Title=="assisstant" || title == "Assisstant" || title == "assisstant")
                {
                    cout<<"You have summoned Nikola"<<endl;
                    temp.Subject="SDP";
                    temp.Title="Assisstant";
                    temp.TeachingSkills=20;
                    temp.Bonuses[0]=1;  ///бонус психическа сила
                    temp.Bonuses[1]=5;  ///бонус живот
                    temp.Bonuses[2]=0.01;///въпроси
                    break;
                }



            }

            else
            {
               // cout<<"You want a custom subject and teacher "<<endl;
                cout<<"How good is he at teaching (0-30) : "<<endl;
                cin>>temp.TeachingSkills;
                cout<<"Enter his bonuses"<<endl;
                cout<<"Enter mental bonus : "<<endl;
                cin>>temp.Bonuses[0];
                cout<<"Enter his life point bonus: "<<endl;
                cin>>temp.Bonuses[1];
                cout<<"Enter his question bonus: "<<endl;
                cin>>temp.Bonuses[2];
                break;
            }
        }

    }
    return temp;
}

void PrintTeacherInfo(Teacher temp)
{

    while(1)
    {
        if(temp.Subject=="Analysis" )
        {
            if(temp.Title=="Lecturer")
                cout<<" Tolev ";
            else
                cout<<"Zhivko ";

            cout<<" teaches Analysis and has "<<temp.TeachingSkills<<" skill points at teaching "<<endl;
            cout<<" He gives "<<temp.Bonuses[0]<<"  mental points "<<temp.Bonuses[1]<<" life points "<<temp.Bonuses[2]<<" question points "<<endl;
            break;
        }


        else  if(temp.Subject=="Algebra")
        {
            if(temp.Title=="Lecturer")
                cout<<"Bozhilov ";
            else
                cout<<" Deyan ";

            cout<<" teaches Algebra and has "<<temp.TeachingSkills<<" skill points at teaching "<<endl;
            cout<<" He gives "<<temp.Bonuses[0]<<"  mental points "<<temp.Bonuses[1]<<" life points "<<temp.Bonuses[2]<<" question points "<<endl;
            break;
        }

        else  if(temp.Subject=="SDP")
        {
            if(temp.Title=="Lecturer")
                cout<<" Mitaka/Ivan ";
            else
                cout<<" Nikola ";

            cout<<" teaches SDP and has "<<temp.TeachingSkills<<" skill points at teaching "<<endl;
            cout<<" He gives "<<temp.Bonuses[0]<<"  mental points "<<temp.Bonuses[1]<<" life points "<<temp.Bonuses[2]<<" question points "<<endl;
            break;

        }


        else /* if(temp.Subject!="Analysis" && temp.Subject!="Algebra" && temp.Subject!="SDP")*/
        {
            cout<<" Your "<<temp.Subject<<" "<<temp.Title;
            cout<<" has "<<temp.TeachingSkills<<" skill points at teaching "<<endl;
            cout<<" He gives "<<temp.Bonuses[0]<<" mental points "<<temp.Bonuses[1]<<" life points "<<temp.Bonuses[2]<<" question points "<<endl;
            break;

        }
    }
}

void copyqueue(queue <chas> day, queue <chas> &temp)
{
    while(!day.empty())
    {
        temp.push(day.front());
        day.pop();
    }
}
void LectureProcess(queue <chas> &day,Hero &Student, Teacher *Sustav,int &LecturesSurvived)
{
    chas copy = day.front();
    while(copy.duration>=0)
    {
        double TotalDamage=0;
        if(copy.subject == "algebra" && copy.type == "lecture"){
            TotalDamage = (RandomNum(80,100)/100)*Sustav[1].TeachingSkills - (RandomNum(40,100)/100)*Student.MentalPoints;
        }
        if(copy.subject == "algebra" && copy.type == "exercise"){
            TotalDamage = (RandomNum(60,100)/100)*Sustav[4].TeachingSkills - (RandomNum(40,100)/100)*Student.MentalPoints;
        }
        if(copy.subject == "analysis" && copy.type == "lecture"){
            TotalDamage = (RandomNum(80,100)/100)*Sustav[0].TeachingSkills - (RandomNum(40,100)/100)*Student.MentalPoints;
        }
        if(copy.subject == "analysis" && copy.type == "exercise"){
            TotalDamage = (RandomNum(60,100)/100)*Sustav[3].TeachingSkills - (RandomNum(40,100)/100)*Student.MentalPoints;
        }
        if(copy.subject == "sdp" && copy.type == "lecture"){
            TotalDamage = (RandomNum(80,100)/100)*Sustav[2].TeachingSkills - (RandomNum(40,100)/100)*Student.MentalPoints;
        }
        if(copy.subject == "sdp" && copy.type == "exercise"){
            TotalDamage = (RandomNum(60,100)/100)*Sustav[5].TeachingSkills - (RandomNum(40,100)/100)*Student.MentalPoints;
        }
        if(copy.subject != "sdp" && copy.subject!="algebra" && copy.subject!="analysis" && copy.type == "lecture"){
            TotalDamage = (RandomNum(80,100)/100)*Sustav[6].TeachingSkills - (RandomNum(40,100)/100)*Student.MentalPoints;
        }
        if(copy.subject != "sdp" && copy.subject!="algebra" && copy.subject!="analysis" && copy.type == "exercise"){
            TotalDamage = (RandomNum(60,100)/100)*Sustav[7].TeachingSkills - (RandomNum(40,100)/100)*Student.MentalPoints;
        }

        for(int i=0; i<4; i++)
        {
            if(rand() % 100 < Student.DumbQuestion){
                cout<<" Dumb question hits critical confusion -> 25% less damage "<<endl;
                TotalDamage *= 0.75;
            }
            if(TotalDamage<=0){
                cout<<"The Teacher is too weak to deal damage "<<endl;
               // Student.HealthPoints--;///да не стане безкраен цикъл от 0dmg и да може рано или късно да свърши
            }

            cout<<"Teacher dealt "<< TotalDamage <<" damage "<<endl;
            Student.HealthPoints-=TotalDamage;
            cout<<" Student's current hp is "<<Student.HealthPoints<<endl;
            if(Student.HealthPoints<=0){
                cout<<" Student died "<<endl;
                Student.Failures--;
                ///нещо да приключва деня, нещо да съживява студента на следващия ден
                break;
            }
            copy.duration-=10;
        }
        LecturesSurvived++;
    }
    if(copy.duration<0)
    {
        cout<<"Class has ended "<<endl;
        day.pop();
    }
}
void EnterDay(queue <chas> &day,int &HourSum,int &Actions,Hero &Student,int &LecturesSurvived, Teacher *Sustav)
{
    int Hour=40;
    HourSum=0;
    Actions=0;
    int temp =0;
    bool flag = true;
    while(flag==true)
    {
        chas TempClass;
        TempClass.subject="unknown";
        TempClass.duration=40;
        cout<<"What subject do you want :  ";
        cin>>TempClass.subject;


        if(TempClass.subject=="stop")
            flag=false;

        else if(TempClass.subject=="algebra" || TempClass.subject=="analysis" || TempClass.subject=="sdp")
        {
            cout<<" lecture or exercise: ";
            cin>>TempClass.type;
            if(TempClass.type!= "lecture" && TempClass.type!="exercise")
            {
                cout<<"neither lecture nor exercise ";
                TempClass.subject="unknown";
            }
            cout<<"How many hours? :";
            cin>>temp;

            for(int i = 0 ; i<temp; i++)
            {
                HourSum+=TempClass.duration;
                day.push(TempClass);

            }
        }
        else if(TempClass.subject=="dupka")
        {
            HourSum+=TempClass.duration;
            day.push(TempClass);
        }
        else
        {

            cout<<"You want a custom subject: "<<endl;
            cout<<" is it lecture or exercise: ";
            cin>>TempClass.type;
            if(TempClass.type!= "lecture" && TempClass.type!="exercise")
            {
                cout<<"neither lecture nor exercise ";
                TempClass.subject="unknown";
            }
            cout<<"How many hours? :";
            cin>>temp;
            for(int i=0; i<temp; i++)
            {
                HourSum+=TempClass.duration;
                day.push(TempClass);

            }
        }
    }
    LectureProcess(day,Student,Sustav,LecturesSurvived);
    if(HourSum>12*40)
        cout<<"Too many Hours"<<endl;
    if(HourSum<6*40)
        cout<<"Too little hours"<<endl;
}

void ActionMachine(queue <chas> &day, int &Actions,Hero &Student,int &LecturesSurvived)
{
    chas temp;
    Actions=0;
    while(!day.empty())
    {

        temp=day.front();
        day.pop();
        if(day.front().subject=="dupka")
        {
            cout<<" dupka "<<endl;
            Actions+=4;
            ActionUsage(day,Actions,Student);
            continue;
        }
        else if(temp.subject==day.front().subject)
        {
            cout<<" 2 blocks of "<<temp.subject<<endl;
            Actions++;
            ActionUsage(day,Actions,Student);
            continue;
        }

        else if(temp.subject=="unknown")
        {
            cout<<" something broke ";
            ActionUsage(day,Actions,Student);
            continue;
        }
        else if(temp.subject!=day.front().subject)
        {
            if(day.front().subject==""|| temp.subject=="")
                break;
            if(day.front().subject=="dupka" || temp.subject=="dupka")/// да няма случай да гледа за междучасие между дупка и предмет
                continue;
            cout<<" 2 different subjects "<<temp.subject <<" and "<< day.front().subject <<endl;
            Actions+=2;
            ActionUsage(day,Actions,Student);
            continue;
        }
        else
        {
            cout<<" ne znam kakvo shte izmisli programata ";
            exit(1000);
        }

    }
}


int main()
{
    //srand(time(0));
    Hero Student;
    queue <chas> day;
    int Actions=0;
    int HourSum=0;
    int LecturesSurvived=1;
    Teacher Sustav[8];
    Sustav[0] = EnterTeacher("analysis", "lecturer");
    Sustav[1] = EnterTeacher("algebra", "lecturer");
    Sustav[2] = EnterTeacher("SDP", "lecturer");
    Sustav[3] = EnterTeacher("analysis", "assisstant");
    Sustav[4] = EnterTeacher("algebra", "assisstant");
    Sustav[5] = EnterTeacher("sdp", "assisstant");
    cout<<"Enter info for your custom subject`s lecturer: "<<endl;
    Sustav[6] = EnterTeacher("", "lecturer");
    cout<<"Enter info for your custom subjects's assisstant "<<endl;
    Sustav[7] = EnterTeacher("","assisstant");
    cout<< "-----------DAY ONE----------- "<<endl;
    EnterDay(day,HourSum,Actions,Student,LecturesSurvived,Sustav);
    ActionMachine(day,Actions,Student,LecturesSurvived);
    LectureProcess(day,Student,Sustav,LecturesSurvived);
    HourSum/=40;
    cout<<endl<<" Today you had " <<HourSum <<" hours and survived "<< LecturesSurvived<<" of them "<<endl;
    cout<<" you have a total of "<<Actions << " actions left ";

}


/** Идеи(не са задължителни):
1) Форматирана таблица да се принти в конзолата(най-накрая + ако имаме нерви)
2) различни предмети
3) Генериране на цели произволни седмици
**/
