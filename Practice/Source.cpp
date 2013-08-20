#include "PracticeFunctions.h"
#include <typeinfo>
#include <iostream>
#include <ios>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;





int main(){
	vector<Student_info> students;

	Student_info record;
	string::size_type maxlen = 0;
	
	//start reading student informaiton
	while(practiceFunctions::read(cin,record)){
		maxlen = max(maxlen,record.name.size());
		students.push_back(record);
	}

	//sort the students alphabetically
	sort(students.begin(),students.end(),practiceFunctions::compare);

	//printing statements
	for (int i = 0; i <students.size(); i++){
		cout << students[i].name 
			<< string(maxlen + 1 - students[i].name.size(),' ');

		try{
			double final_grade = practiceFunctions::grade(students[i]);
			streamsize prec = cout.precision();
			cout << setprecision(3) << final_grade << setprecision(prec);
		}
		catch(domain_error e){
			cout << e.what();
		}

		cout << endl;
	}

	
	

	return 0;

}


