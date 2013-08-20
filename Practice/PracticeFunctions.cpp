#include "PracticeFunctions.h"
#include <algorithm>
#include <iostream>

int practiceFunctions::FindFirstOccuranceByString(const std::vector<std::string>& vec,const std::string& strToFind ){
	int i=0;
	while (vec[i] != strToFind)
		i++;
	return i;
}

double practiceFunctions::median(std::vector<double> vec ){
		int size = vec.size();
	if (size == 0)
		throw std::domain_error("median of an empty vector");
	sort(vec.begin(),vec.end());
	int mid = size/2;
	return size%2 == 0 ? (vec[mid] + vec[mid-1]) / 2 : vec[mid];
}

double practiceFunctions::grade(double midterm, double final, const std::vector<double>& hwVecSorted){
	int size = hwVecSorted.size();
	if (size == 0)
		throw std::domain_error("student has no homework");
	return midterm*0.2 + final*0.4 + median(hwVecSorted)*0.4;
}

std::istream& practiceFunctions::read_hw(std::istream& in, std::vector<double>& hw){
	if (in){
		std::cout << "Please enter your homework grades. Terminate your entries with CTRL+Z: ";
		hw.clear();

		double x;
		while(in>>x)
			hw.push_back(x);

		in.clear();
	}
	return in;
}

std::istream& practiceFunctions::read(std::istream& is, Student_info &s){
	std::cout << "Please enter your first name, midterm score, and final score, with each seperated by a space: ";
	is >> s.name >> s.midterm >> s.final;
	if(s.name == "")
		return is;

	std::cout << std::endl;
	
	read_hw(is,s.hw);

	return is;

}

double practiceFunctions::grade(const Student_info& s){
	return grade(s.midterm,s.final,s.hw);
}

bool practiceFunctions::compare(const Student_info& x, const Student_info& y){
	return x.name < y.name;
}
bool practiceFunctions::fgrade(const Student_info& s){
	return grade(s) < 50.0;
}

std::vector<Student_info> practiceFunctions::extractFailsAndStorePassInOriginal(std::vector<Student_info>& students){
	using std::vector;
	vector<Student_info> fail;

	vector<Student_info>::const_iterator iter = students.begin();

	while(iter!=students.end()){
		if(fgrade(*iter)){
			fail.push_back(*iter);
			iter = students.erase(iter);
		}else
			iter++;
	}
	

	
	
	return fail;

}
std::vector<std::string> practiceFunctions::split(const std::string& str){
	using std::vector; using std::string;
	vector<string> toBeReturned;
	unsigned i=0;
	while (i < str.size()){
		while (i<str.size() && isspace(str[i]))
			i++;

		unsigned j=i;
		while (j<str.size() && !isspace(str[j]))
			j++;

		if(i!=j){
			toBeReturned.push_back(str.substr(i,j-i));
			i = j;
		}
	}

	return toBeReturned;
}
