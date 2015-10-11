//Steve Walker
//Sept 15, 2015
//test sorted_vector for bugs.
#define _CRT_SECURE_NO_WARNINGS//directive to compiler
#define BOOST_TEST_MODULE BoostTestIntroduction//this is a variable
#include <boost\test\unit_test.hpp>
#include <iostream>
#include <fstream>
#include "sorted_vector.hpp"

using namespace std;
using namespace boost::unit_test;



BOOST_AUTO_TEST_CASE(intro)
{
	cout << "\nBoost testing sorted_vector.\n";
	cout << "Last compiled: " << __TIMESTAMP__ << "\n\n";
}//end test case



 //default constructor tests -- DONE
BOOST_AUTO_TEST_CASE(testDefaultConstructor)
{
	//test default constructor with strings
	sorted_vector<string> stringV;
	BOOST_CHECK(stringV.empty());
	BOOST_CHECK(stringV.size() == 0);
	stringV.insert("stringWord");
	stringV.insert("steve");
	stringV.insert("bill");

	BOOST_CHECK(stringV.at(0) == "bill");
	BOOST_CHECK(stringV.at(2) == "stringWord");
	

	//test default constructor with chars
	sorted_vector<char> charV;
	BOOST_CHECK(charV.empty());
	BOOST_CHECK(charV.size() == 0);


	//test default constructor works with the ints
	sorted_vector<int> v1;
	//check if vector is empty.
	BOOST_CHECK(v1.empty());
	BOOST_CHECK(v1.size() == 0);

	//test default constructor works with the unsigned ints
	sorted_vector<unsigned int> v5;
	//check if vector is empty.
	BOOST_CHECK(v5.empty());
	BOOST_CHECK(v5.size() == 0);


	//test default constructor works with doubles
	sorted_vector<double> v2;
	//check if vector is empty.
	BOOST_CHECK(v2.empty());
	BOOST_CHECK(v2.size() == 0);


	//test default constructor works with long
	sorted_vector<long> v3;
	//check if vector is empty.
	BOOST_CHECK(v3.empty());
	BOOST_CHECK(v3.size() == 0);


	//test default constructor works with long long
	sorted_vector<long long> v4;
	//check if vector is empty.
	BOOST_CHECK(v4.empty());
	BOOST_CHECK(v4.size() == 0);

}//end default constructor test



 //copy constructor tests -- DONE
BOOST_AUTO_TEST_CASE(testCopyConstructor)
{

	sorted_vector<int> v1;

	for (int i = 0; i < 10; ++i)
	{
		v1.insert(i);
	}//end for

	sorted_vector<int> v2(v1);
	BOOST_CHECK_EQUAL(v2.size(), v1.size());//v1 should be equal to v2

	for (int i = 0; i < 10; ++i)
	{
		BOOST_CHECK(v2.at(i) == v1.at(i));//both vectors should have the same # of elements, same values in elements.
	}//end for

	sorted_vector<int> v3 = v2;
	for (int i = 0; i < 10; ++i)
	{
		BOOST_CHECK(v3.at(i) == v1.at(i));
		BOOST_CHECK(v3[i] == v1[i]);//testing [] operator here too
	}//end for

}//end test



 //--move constructor tests -- DONE
BOOST_AUTO_TEST_CASE(testMoveConstructor)
{
	sorted_vector<int> v1;

	for (int i = 0; i < 10; ++i)
	{
		v1.insert(i);
	}//end for

	sorted_vector<int> v2(move(v1));
	for (int i = 0; i < 10; ++i)
	{
		BOOST_CHECK(v2.at(i) == i);
		BOOST_CHECK(v1.empty());//make sure v1 was deleted.
	}//end for

	sorted_vector<int> v3 = move(v2);
	for (int i = 0; i < 10; ++i)
	{
		BOOST_CHECK(v3.at(i) == i);
		BOOST_CHECK(v2.size() != v3.size());//make sure v2 is deleted
	}//end for

}//end test



 //iterator constructor tests -- DONE
BOOST_AUTO_TEST_CASE(testIteratorConstructor)
{
	sorted_vector<int> v1;
	for (int i = 0; i < 10; ++i)
	{
		v1.insert(i);
	}//end for

	sorted_vector<int> v2(v1.begin(), v1.end());
	for (int i = 0; i < v2.size(); ++i)
	{
		BOOST_CHECK(v2.at(i) == v1.at(i));
	}//end for

}//end test



 //2-arg constructor tests -- DONE
BOOST_AUTO_TEST_CASE(test2ArgConstructor)
{
	
	sorted_vector<int> v1(10, 5);

	for (int i = 0; i < 10; ++i)
	{
		BOOST_CHECK(v1.at(i) == 5);//10 elements, all values == 5
	}//end for

}//end test



 //.at method tests -- DONE
BOOST_AUTO_TEST_CASE(test_at)
{
	
	sorted_vector<int> v1(3, 1);//vector with 3 elements
	BOOST_CHECK_THROW(v1.at(3), out_of_range);//there are not 4 elements, test that an exception is thrown
	BOOST_CHECK(v1.at(2) == 1);
}//end test


 //.insert method tests -- DONE
BOOST_AUTO_TEST_CASE(test_insert)
{
	//test that values are actually inserted into the vector
	//as well as testing that they are inserted in the correct order.

	sorted_vector<int> v1;
	const int num = 50;

	v1.insert(num);//insert num into v1
	BOOST_CHECK(v1.size() == 1);//make sure value was inserted, size should be 1
	BOOST_CHECK(v1.at(0) == 50);//test that the value of element 0 is what it should be


	sorted_vector<int> v2(20);//give vector a size of 20
	const int num1 = -100;

	v2.insert(num1);//insert another value, size is now 21
	BOOST_CHECK(v2.size() == 21);//make sure size evaluates to 21
	BOOST_CHECK(v2.at(0) == -100);//check that element 0 is -100

	//test with floats
	sorted_vector<float> v4;
	float f = 1.2565;
	v4.insert(f);
	BOOST_CHECK(v4.size() == 1);
	BOOST_CHECK(v4.at(0) == f);

	
	sorted_vector<int> v5;
	int number = 10;
	int * p = &number;//pointless
	v5.insert(number);
	BOOST_CHECK(v5.at(0) == 10);

	//check that values are all in correct sorted order.
	sorted_vector<int> v6(10, 3);

	v6.insert(1);
	v6.insert(2);
	v6.insert(4);
	v6.insert(6);

	BOOST_CHECK(v6.at(0) == 1);
	BOOST_CHECK(v6.at(1) == 2);
	BOOST_CHECK(v6.at(2) == 3);
	BOOST_CHECK(v6.at(v6.size() - 1) == 6);
	BOOST_CHECK(v6.at(v6.size() - 2) == 4);
}//end test



 //.find method tests -- DONE
BOOST_AUTO_TEST_CASE(test_find)
{
	//test that .find() returns proper values

	sorted_vector<int> v1;
	v1.insert(5);
	v1.insert(3);
	sorted_vector<int>::iterator it = &v1[1];
	BOOST_CHECK(v1.find(1) == v1.end());//there is no value of 1 in the vector, it should return a pointer to the end of vector.
	BOOST_CHECK(v1.find(5));//a 5 is in the vector, it should return a pointer to that element holding 5.

}//end test



 //[] operator tests -- DONE
BOOST_AUTO_TEST_CASE(test_squareBracket_operator)
{
	//make sure square brackets[] work as intended.
	sorted_vector<int> v1;
	v1.insert(2);
	v1.insert(3);
	v1.insert(6);
	v1.insert(10);
	sorted_vector<int> v3 = v1;
	

	BOOST_CHECK(v3[0] == v1[0]);//testing [] operators here

	for (int i = 0; i < 6; ++i)
	{
		BOOST_CHECK(v3[i] == v1[i]);//testing [] operators here	
	}//end for

}//end test



 //.begin() method tests -- DONE
BOOST_AUTO_TEST_CASE(testBeginFunction)
{
	//make sure .begin() points to the first element[0] of the vector.

	//ints
	sorted_vector<int> v1(3);
	int num = 50;
	sorted_vector<int>::iterator it = v1.begin();
	v1.at(0) = num;

	BOOST_CHECK(it == v1.begin());
	BOOST_CHECK(*v1.begin() == num);

	//doubles
	sorted_vector<double> v2(3);
	sorted_vector<double>::iterator it2 = v2.begin();
	double num1 = 1000;
	v2.at(0) = num1;
	BOOST_CHECK(v2.begin() == it2);
	BOOST_CHECK(*v2.begin() == num1);


	//long
	sorted_vector<long> v3(3);
	sorted_vector<long>::iterator it3 = v3.begin();

	BOOST_CHECK(v3.begin() == it3);

	//long long
	sorted_vector<long long> v4(3);
	sorted_vector<long long>::iterator it4 = v4.begin();

	BOOST_CHECK(v4.begin() == it4);


}//end begin test



 //.end() method tests -- DONE
BOOST_AUTO_TEST_CASE(testEndFunction)
{
	//make sure .end() is really pointing to one past last element in vectors.

	//ints
	sorted_vector<int> v1;
	sorted_vector<int>::iterator it = v1.end();
	BOOST_CHECK(v1.end() == it);

	it = v1.end() - 1;
	BOOST_CHECK(v1.end() == it + 1);

	//double
	sorted_vector<double> v2;
	sorted_vector<double>::iterator it2 = v2.end();
	BOOST_CHECK(v2.end() == it2);

	it2 = v2.end() - 1;
	BOOST_CHECK(v2.end() == it2 + 1);

	//long
	sorted_vector<long> v3;
	sorted_vector<long>::iterator it3 = v3.end();
	BOOST_CHECK(v3.end() == it3);

	it3 = v3.end() - 1;
	BOOST_CHECK(v3.end() == it3 + 1);

	//long long
	sorted_vector<long long> v4;
	sorted_vector<long long>::iterator it4 = v4.end();
	BOOST_CHECK(v4.end() == it4);

	it4 = v4.end() - 1;
	BOOST_CHECK(v4.end() == it4 + 1);

}//end .end test



 //== != operator AND bool == tests -- DONE
BOOST_AUTO_TEST_CASE(test_equality_operators)
{
	//test that == evaluates properly
	sorted_vector<int> v1(5, 3);
	sorted_vector<int> v2(5, 3);
	BOOST_CHECK(v1 == v2);
	
	v1.insert(5);
	BOOST_CHECK(v1 != v2);

	BOOST_CHECK(v1.empty() == false);
	BOOST_CHECK(!v1.empty() == true);

}//end test



 //.erase() method and .find method tests-- DONE
BOOST_AUTO_TEST_CASE(test_erase)
{
	sorted_vector<int> v1;

	for (int i = 0; i < 5; ++i)
	{
		v1.insert(i);
	}//end for

	sorted_vector<int>::iterator it = v1.find(0);
	v1.erase(it);
	BOOST_CHECK(v1.at(0) == 1);
	v1.erase(&v1.at(1));//passes into erase a reference to the iterator at element 1 in v1.
	sorted_vector<int>::iterator it2 = v1.find(100) - 1;// - 1 makes it so it2 will point to the end of v1 instead of 1 past the end of v1.
	sorted_vector<int>::iterator it3 = v1.erase(it2);
	BOOST_CHECK(it3 == v1.end());
	BOOST_CHECK_EQUAL(it3, v1.end());
}//end test



 //.size() method tests -- DONE
BOOST_AUTO_TEST_CASE(test_size)
{
	//test that .size() evaluates to the correct number for each vector

	sorted_vector<int> v1;
	for (int i = 0; i < 100; ++i)
	{
		BOOST_CHECK(v1.size() == i);
		v1.insert(i);
	}//end for


	sorted_vector<float> v2(998);
	for (float i = 999; i < 1110; ++i)
	{
		v2.insert(i);
		BOOST_CHECK(v2.size() == i);
	}//end for


	sorted_vector<long> v3(1000098);
	for (long long i = 1000099; i < 1000105; ++i)
	{
		v3.insert(i);
		BOOST_CHECK(v3.size() == i);
	}//end for

	sorted_vector<long long> v4(10000000);
	for (long long i = 10000001; i < 10000050; ++i)
	{
		v4.insert(i);
		BOOST_CHECK(v4.size() == i);
	}//end for

}//end .size test



 //.empty() method tests -- DONE
BOOST_AUTO_TEST_CASE(test_empty)
{
	//test the .empty() method
	//if vector is full, .empty() should return FALSE
	//if vector is empty, .empty() shold return TRUE

	//with ints
	sorted_vector<int> v1;

	BOOST_CHECK(v1.size() == 0);
	BOOST_CHECK(v1.empty() == true);

	sorted_vector<int> v2(10);
	BOOST_CHECK(v2.empty() == false);
	BOOST_CHECK(v2.size() > 0);

	//with doubles
	sorted_vector<double> v3;

	BOOST_CHECK(v3.size() == 0);
	BOOST_CHECK(v3.empty() == true);


	sorted_vector<double> v4(10);

	BOOST_CHECK(v4.size() > 0);
	BOOST_CHECK(v4.empty() == false);

	//with long
	sorted_vector<long> v5;

	BOOST_CHECK(v5.size() == 0);
	BOOST_CHECK(v5.empty() == true);


	sorted_vector<long> v6(10);

	BOOST_CHECK(v6.size() > 0);
	BOOST_CHECK(v6.empty() == false);


	//with long long
	sorted_vector<long long> v7;

	BOOST_CHECK(v7.size() == 0);
	BOOST_CHECK(v7.empty() == true);


	sorted_vector<string> svector;
	string str = "element one";
	svector.insert(str);
	BOOST_TEST(!svector.empty());
	BOOST_TEST(svector.empty() == false);
}//end .empty test



 //.capacity() method tests -- DONE
BOOST_AUTO_TEST_CASE(test_capacity)
{
	//testing for each integer data type
	//testing to make sure capacity is equal to what it should be

	sorted_vector<short> shortV(3, 3);
	BOOST_CHECK(shortV.capacity() == 3);


	sorted_vector<int> v1(3, 3);
	BOOST_CHECK(v1.capacity() == 3);

	
	for (int i = 0; i < 200; ++i)
	{
		sorted_vector<int> v1(i);
		BOOST_CHECK(v1.capacity() == i);
	}//end for


	for (int i = 0; i < 200; ++i)
	{
		sorted_vector<double> v1(i);
		BOOST_CHECK(v1.capacity() == i);
	}//end for


	for (int i = 0; i < 200; ++i)
	{
		sorted_vector<long> v1(i);
		BOOST_CHECK(v1.capacity() == i);
	}//end for

	for (int i = 0; i < 200; ++i)
	{
		sorted_vector<long long> v1(i);
		BOOST_CHECK(v1.capacity() == i);
	}//end for

}//end .capacity function



 //cend/cbegin method tests -- DONE
BOOST_AUTO_TEST_CASE(test_cend_cbegin)
{
	
	sorted_vector<int> v1(3);
	const int *p = v1.cend();
	BOOST_CHECK(v1.end() == p);

	const int *p2 = v1.cbegin();
	BOOST_CHECK(v1.begin() == p2);
}//end test



