#ifndef PRACTICE_FUNCTIONS_H
#define PRACTICE_FUNCTIONS_H

#include <string>
#include <vector>
#include <iostream>

struct Student_info{
	std::string name;
	double midterm,final;
	std::vector<double> hw;
};


class practiceFunctions{
public:
	 static int FindFirstOccuranceByString(const std::vector<std::string>& vec,const std::string& strToFind );
	 static double median(std::vector<double> vec );
	 static double grade(double midterm, double final, const std::vector<double>& hwVecSorted);
	 static std::istream& read_hw(std::istream& in, std::vector<double>& hw);

	 static std::istream& read(std::istream& is, Student_info &s);
	 static double grade(const Student_info& s);
	 static bool compare(const Student_info& x, const Student_info& y);
	 static bool fgrade(const Student_info& s);
	 static std::vector<Student_info> extractFailsAndStorePassInOriginal(std::vector<Student_info>& students);
	 static std::vector<std::string> split(const std::string& str);
};

#endif
