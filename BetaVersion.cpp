#include <iostream>
#include <random>
#include <queue>
#include <list>

using namespace std;

enum class Subject { analysis, algebra, sdp };
enum class TeacherType { lecturer, ta};
enum class ChasType { work, bbreak, sbreak, dupka };

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
        Subject subject;
        TeacherType type;
        int TeachingSkills;
        double Bonuses[3];
};

struct chas
{
    ChasType type;
    Teacher* teacher=nullptr;
};


void InfoWriter();      ///да записва цялата информация във log.txt файл

double RandomNum(int lower, int upper)
{
    double num = (rand() % (upper - lower + 1)) + lower;
    return num;
}

// 1 Action
void use_inventory(Hero &Student) {
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
}
// 2 Actions

void lafka(Hero &Student) {
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
}

// 3 Actions
void third_floor(Hero &Student) {
    int temp;
    cout<<" Type 1) for spane or 2) for uchene "<<endl;
    cin>>temp;
    if(temp==1)
    {
        cout<<" spane -> +20hp "<<endl;
        Student.HealthPoints+= 20;
    }
    else if(temp == 2)
    {
        cout<<"Uchene -> +4 mental  +0.5 dumb question"<<endl;
        Student.MentalPoints+=4;
        Student.DumbQuestion+=0.5;
    }
    else
    {
        cout<<"Better chose something valid next time -> -1 mental";
        Student.MentalPoints-=1;
    }
}


void actions(int Actions,Hero &Student)
{
    int temp ;
    while(Actions > 0) {
        cout<<"You currently have " << Actions << " actions, choose wisely\n";
        cout<<"Type 1) for inventory - 1 action \nType 2) for lafka - 2 actions \nType 3) to go the the third floor - 3 actions"<<endl;
        cin>>temp;
        if(temp==1)
        {
            use_inventory(Student);
            Actions-=1;
        }
        else if(temp==2)
        {
            lafka(Student);
            Actions-=2;
        }
        else  if(temp==3)
        {
            third_floor(Student);
            Actions-=3;
        }
        else
        {
            cout<<"You have chosen to be useless, congratulations!\n";
            break;
        }
    }
}

Teacher EnterTeacher(Subject subject, TeacherType type)
{
    Teacher temp;
    temp.subject=subject;
    temp.type=type;

    if(subject==Subject::algebra)
    {
        if(type==TeacherType::lecturer)
        {
            temp.TeachingSkills=29;
            temp.Bonuses[0]=2;  ///бонус психическа сила
            temp.Bonuses[1]=3;  ///бонус живот
            temp.Bonuses[2]=0.1;///въпроси
        }
        else
        {
            temp.TeachingSkills=21;
            temp.Bonuses[0]=1;  ///бонус психическа сила
            temp.Bonuses[1]=5;  ///бонус живот
            temp.Bonuses[2]=0.05;///въпроси
        }
    }

    if(subject==Subject::analysis)
    {
        if(type==TeacherType::lecturer)
        {
            temp.TeachingSkills=23;
            temp.Bonuses[0]=2;  ///бонус психическа сила
            temp.Bonuses[1]=4;  ///бонус живот
            temp.Bonuses[2]=0.2;///въпроси
        }
        else
        {
            temp.TeachingSkills=21;
            temp.Bonuses[0]=1;  ///бонус психическа сила
            temp.Bonuses[1]=5;  ///бонус живот
            temp.Bonuses[2]=0.05;///въпроси
        }
    }
    if(subject==Subject::sdp)
    {
        if(type==TeacherType::lecturer)
        {
            temp.TeachingSkills=29;
            temp.Bonuses[0]=2;  ///бонус психическа сила
            temp.Bonuses[1]=3;  ///бонус живот
            temp.Bonuses[2]=0.1;///въпроси
        }
        else
        {
            temp.TeachingSkills=21;
            temp.Bonuses[0]=1;  ///бонус психическа сила
            temp.Bonuses[1]=5;  ///бонус живот
            temp.Bonuses[2]=0.05;///въпроси
        }
    }

    return temp;
}

void copyqueue(queue <chas> day, queue <chas> &temp)
{
    while(!day.empty())
    {
        temp.push(day.front());
        day.pop();
    }
}


void work(chas hour, Hero &Student) {
    double TotalDamage=0;

    cout << "Starting {subject} classes \n";

    if( hour.teacher->type == TeacherType::lecturer){
        TotalDamage = (RandomNum(80,100)/100)*hour.teacher->TeachingSkills - (RandomNum(40,100)/100)*Student.MentalPoints;
    }
    if( hour.teacher->type == TeacherType::ta){
        TotalDamage = (RandomNum(60,100)/100)*hour.teacher->TeachingSkills - (RandomNum(40,100)/100)*Student.MentalPoints;
    }

    for(int i=0; i<4; i++)
    {
        if(rand() % 100 < Student.DumbQuestion){
            cout<<"Dumb question hits critical confusion -> 25% less damage "<<endl;
            TotalDamage *= 0.75;
        }
        if(TotalDamage<=0){
            cout<<"The Teacher is too weak to deal damage, the rest of the lecture went smoothly"<<endl;
            break;
        }
        cout<<"Teacher dealt "<< TotalDamage <<" damage"<<endl;
        Student.HealthPoints-=TotalDamage;
        cout<<"Student's current hp is "<<Student.HealthPoints<<endl;
        if(Student.HealthPoints<=0){
            cout<<" Student died "<<endl;
            Student.Failures--;
            ///нещо да приключва деня, нещо да съживява студента на следващия ден
            break;
        }
    }
    cout<<"Classes has ended "<<endl;
}

void LectureProcess(queue <chas> &day,Hero &Student)
{
    while(!day.empty()) 
    {
        chas hour = day.front();
        day.pop();
        if(hour.type == ChasType::work) {
            work(hour, Student);
        }
        if(hour.type == ChasType::dupka) {
            actions(4, Student);
        }
        if(hour.type == ChasType::bbreak) {
            actions(2, Student);
        }
        if(hour.type == ChasType::sbreak) {
            actions(1, Student);
        }
    }
    cout<<"The day has passed! \n\n"<<endl;
}

void big_break(queue <chas> &day, Subject &current_subject, int &current_hours) {
    chas TempClass;
    TempClass.type = ChasType::bbreak;
    TempClass.teacher = nullptr;
    day.push(TempClass);
    int rand_subject = RandomNum(0,2);
    switch (rand_subject) {
        case 0 : current_subject = Subject::analysis;
        case 1 : current_subject = Subject::algebra;
        case 2 : current_subject = Subject::sdp;
    }
    current_hours=0;
    return;
}


void small_break(queue <chas> &day) {
    chas TempClass;
    TempClass.type = ChasType::sbreak;
    TempClass.teacher = nullptr;
    day.push(TempClass);
}

void dupka(queue <chas> &day, int &hours) {
    chas TempClass;
    TempClass.type = ChasType::dupka;
    TempClass.teacher = nullptr;
    day.push(TempClass);
    hours--;
}

void work_hour(queue <chas> &day, Teacher *Sustav, Subject current_subject,int &hours) {
    chas TempClass;
    int rand_teacher = RandomNum(0,1);
    Teacher teacher;
    TeacherType type = TeacherType::lecturer;
    switch(rand_teacher) {
        case 0: type = TeacherType::lecturer;
                break;
        case 1: type = TeacherType::ta;
                break;
    }
    for(int i=0;i<6;i++) {
        if(Sustav[i].subject == current_subject && Sustav[i].type == type) {
            teacher = Sustav[i];
            break;
        }
    }
    TempClass.type = ChasType::work;
    TempClass.teacher = &teacher;
    day.push(TempClass);
    hours--;

}

void make_day(queue <chas> &day, Hero &Student, Teacher *Sustav)
{

    int hours = RandomNum(6,12);

    int current_hours = 0;
    Subject current_subject = Subject::analysis;
    int rand_subject = RandomNum(0,2);
    switch (rand_subject) {
        case 0 : current_subject = Subject::analysis;
                break;
        case 1 : current_subject = Subject::algebra;
                break;
        case 2 : current_subject = Subject::sdp;
                break;
    }

    while(hours>0)
    {
        if(day.front().type == ChasType::work && current_hours >3) {
            big_break(day, current_subject, current_hours);
        }
        else if(day.front().type == ChasType::work && current_hours == 2) {
            int rand_stop = RandomNum(0,1);
            switch(rand_stop) {
                case 0: small_break(day);
                break;
                case 1: big_break(day, current_subject, current_hours);
                break;
            }
        }
        else if(day.front().type == ChasType::work) {
            small_break(day);
        }
        else if(day.front().type == ChasType::dupka) {
            work_hour(day, Sustav, current_subject, hours);
        }
        else {
            int rand_hour = RandomNum(0,4);
            if(rand_hour > 3) {
                dupka(day, hours);
            }
            work_hour(day, Sustav, current_subject, hours);
        }
    }
}

string print_enum(Subject type) {
    string str;
    switch(type) {
        case Subject::analysis : return str ="analysis";
        case Subject::algebra : return str ="analysis";
        case Subject::sdp : return str ="analysis";
    }
    return str;
}

int main()
{
    //srand(time(0));
    Hero Student;
    queue <chas> day;
    Teacher Sustav[6];
    
    Sustav[0] = EnterTeacher(Subject::analysis, TeacherType::lecturer);
    Sustav[1] = EnterTeacher(Subject::algebra, TeacherType::lecturer);
    Sustav[2] = EnterTeacher(Subject::sdp, TeacherType::lecturer);
    Sustav[3] = EnterTeacher(Subject::analysis, TeacherType::ta);
    Sustav[4] = EnterTeacher(Subject::algebra, TeacherType::ta);
    Sustav[5] = EnterTeacher(Subject::sdp, TeacherType::ta);

    int day_count=0;
    while(true) {
        cout<< "-----------DAY " << day_count << " ----------- "<<endl;
        make_day(day, Student, Sustav);
        /*while (!day.empty())
        {
            std::cout << print_enum(day.front().teacher->subject) << " ";
            day.pop();
        }
        */
        std::cout << std::endl;
        LectureProcess(day, Student);
    }


}


/** Идеи(не са задължителни):
1) Форматирана таблица да се принти в конзолата(най-накрая + ако имаме нерви)
2) различни предмети
3) Генериране на цели произволни седмици
**/
