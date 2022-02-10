#include<iostream>
#include<string>
#include<fstream>
#include<time.h>
using namespace std;

/////////////////////////////////////////////////////////////////////////////////////////////

class date
{
    public:
    int day,month,year;
    void input_date();
    friend ostream & operator<<(ostream &o,date input);
};
ostream & operator<<(ostream &o,date input)
{
    o<<input.day<<"/"<<input.month<<"/"<<input.year;
    return o;
}

void date::input_date()
{
    cout<<"Enter the day date and month in numbers"<<endl;
    cin>>day>>month>>year;
    try
    {
        if(year<100)
            throw 1;
        this->day=day;
        this->month=month;
        this->year=year;
        cout<<"date taken succesfully"<<endl<<endl;
    }
    catch(int e)
    {
        cout<<"Enter the the year in full form"<<endl<<endl;
        input_date();
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////

class expences
{
private:
    int amount;
    string reason;
public:
    void input();
    void expense_month();
};

void expences::input()
{
    ofstream inp("expenses.txt",ios::app);
    date date;
    int amount;
    string reason;
    date.input_date();
    cout<<"Enter the amount and reason"<<endl;
    cin>>amount;
    getline(cin,reason);
    inp<<date.year<<" "<<date.month<<" "<<date.day<<" "<<amount<<" "<<reason<<endl;
    cout<<"Expences are taken successfully"<<endl;
    inp.close();
}

void expences::expense_month()
{
    int total=0,temp_amount,month,year;
    string line,inp_reason;
    date date;
    cout<<"Enter the month and year";
    cin>>month>>year;
    ifstream out("expenses.txt",ios::in);

    while(!out.eof())
    {
        out>>date.year;
        out>>date.month;
        out>>date.day;
        out>>temp_amount;
        getline(out,line);
        if(date.year==year && date.month==month)
        {
            cout<<date<<" "<<temp_amount<<line<<endl;
        }
    }


    out.close();
}

///////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    expences e;
    int decision;
    while (1)
    {
        cout<<"Enter "<<endl;
        cout<<"1.To enter an expense"<<endl;
        cout<<"2.To track all the expenses of the month"<<endl;
        cin>>decision;
        if(decision==1)
        {
            e.input();
            system("clrscr");
            cout<<"Expenses are taken successfully"<<endl;
        }
        else
        {
            e.expense_month();  
        } 
    }
    return 0;
}
