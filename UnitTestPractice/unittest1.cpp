
#include "CppUnitTest.h"
#include "..\Practice\PracticeFunctions.h"
#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace UnitTestPractice
{		
	TEST_CLASS(UnitTest1)
	{
		
	public:
		
		TEST_METHOD(testMedian)
		{
			
			double tempArr[] = {1.0,2.0,3.0,4.0};
			vector<double> testVec(tempArr,tempArr+sizeof(tempArr)/sizeof(double));
			Assert::AreEqual(practiceFunctions::median(testVec),2.5);
		}

		TEST_METHOD(testGrade){
			double midterm = 90.0;
			double final = 70.0;
			double hwArr[] = {94.0,95.0,88.0,92.0,87.0,78.0};
			vector<double> hwVec(hwArr,hwArr+sizeof(hwArr)/sizeof(double));
			Assert::AreEqual(practiceFunctions::grade(midterm,final,hwVec),82.0);
		}
		TEST_METHOD(testPass){
			Student_info s;
			s.midterm = 90.0;
			s.final = 70.0;
			double hwArr[] = {94.0,95.0,88.0,92.0,87.0,78.0};
			vector<double> hwVec(hwArr,hwArr+sizeof(hwArr)/sizeof(double));
			s.hw = hwVec;
			Assert::AreEqual(practiceFunctions::fgrade(s),false);
		}
		TEST_METHOD(testFail){
			Student_info s;
			s.midterm = 40.0;
			s.final = 30.0;
			s.hw = vector<double>(6,0.0);
			Assert::AreEqual(practiceFunctions::fgrade(s),true);
		}
		TEST_METHOD(testExtractFails){
			vector<Student_info> students;
			Student_info Jacky = {"Jacky",100.0,100.0,vector<double>(4,100)};
			Student_info Fail = {"Jacky2",0.0,0.0,vector<double>(4,100)};
			Student_info Fail2 = {"Joseph",0.0,0.0,vector<double>(4,100)};
			Student_info Pass = {"Alice",100.0,100.0,vector<double>(4,100)};
			students.push_back(Jacky);
			students.push_back(Fail);
			students.push_back(Fail2);
			students.push_back(Pass);
			auto fails = practiceFunctions::extractFailsAndStorePassInOriginal(students);
			for(int i=0;i<students.size();i++)
				Assert::AreEqual(practiceFunctions::fgrade(students[i]),false);

			for(int i=0;i<fails.size();i++)
				Assert::AreEqual(practiceFunctions::fgrade(fails[i]),true);

			Assert::AreEqual(fails[0].name,string("Jacky2"));
			Assert::AreEqual(fails[1].name,string("Joseph"));
			Assert::AreEqual(students[0].name,string("Jacky"));
			Assert::AreEqual(students[1].name,string("Alice"));


		}
		TEST_METHOD(testSplit){
			string testStr("        I am a test string.");
			vector<string> splitStrings = practiceFunctions::split(testStr);
			Assert::AreEqual(splitStrings[0],string("I"));
			Assert::AreEqual(splitStrings[1],string("am"));
			Assert::AreEqual(splitStrings[2],string("a"));
			Assert::AreEqual(splitStrings[3],string("test"));
			Assert::AreEqual(splitStrings[4],string("string."));
		}
	};
}