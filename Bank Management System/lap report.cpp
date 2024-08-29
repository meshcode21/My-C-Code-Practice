#include <iostream>
using namespace std;

class Date {
    string day,month, year;

public:
	void setDate(string y,string m,string d){
		year = y;
		month = m;
		day = d;
	}
	string getDate(){
		string date = year+"/"+month+"/"+day;
		return date;
	}
};

int main() {
    Date date;
    date.setDate("2050","11","26");
    cout<<"\nDate is: "<<date.getDate()<<endl;

    return 0;
}

