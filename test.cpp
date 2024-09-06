
//
//#include <catch2/catch_test_macros.hpp>
//#include <iostream>
//#include "AdjacencyList.h"
//
//using namespace std;
//
//TEST_CASE("Test 1", "[PageRank]"){
//string input = R"(5 3
//facebook.com google.com
//google.com gmail.com
//gmail.com facebook.com
//maps.com ufl.edu
//ufl.edu gmail.com)";
//
//string expectedOutput = R"(facebook.com 0.40
//gmail.com 0.40
//google.com 0.20
//maps.com 0.00
//ufl.edu 0.00
//)";
//
//string actualOutput; //tested these manually on my local, matched
//
//
//REQUIRE(actualOutput == expectedOutput);
//}
//
//TEST_CASE("Test 2", "[PageRank]"){
//string input = R"(6 2
//ufl.edu google.com
//google.com ufl.edu
//facebook.com maps.com
//maps.com gmail.com
//gmail.com facebook.com
//gmail.com maps.com)";
//
//string expectedOutput = R"(facebook.com 0.10
//gmail.com 0.20
//google.com 0.20
//maps.com 0.30
//ufl.edu 0.20
//)";
//
//string actualOutput; //tested these manually on my local, matched
//
//
//REQUIRE(actualOutput == expectedOutput);
//}
//
//TEST_CASE("Test 3", "[PageRank]"){
//string input = R"(4 4
//gmail.com google.com
//google.com gmail.com
//facebook.com google.com
//ufl.edu google.com)";
//
//string expectedOutput = R"(facebook.com 0.00
//gmail.com 0.25
//google.com 0.75
//ufl.edu 0.00
//)";
//
//string actualOutput;//tested these manually on my local, matched
//
//
//REQUIRE(actualOutput == expectedOutput);
//}
//
//TEST_CASE("Test 4", "[PageRank]"){
//string input = R"(3 3
//google.com facebook.com
//maps.com gmail.com
//ufl.edu facebook.com)";
//
//string expectedOutput = R"(facebook.com 0.00
//gmail.com 0.00
//google.com 0.00
//maps.com 0.00
//ufl.edu 0.00
//)";
//
//string actualOutput; //tested these manually on my local, matched
//
//
//REQUIRE(actualOutput == expectedOutput);
//}
//
//TEST_CASE("Test 5", "[PageRank]"){
//string input = R"(8 2
//google.com facebook.com
//facebook.com google.com
//google.com gmail.com
//gmail.com google.com
//gmail.com maps.com
//maps.com gmail.com
//ufl.edu facebook.com
//facebook.com ufl.edu)";
//
//string expectedOutput = R"(facebook.com 0.30
//gmail.com 0.30
//google.com 0.20
//maps.com 0.10
//ufl.edu 0.10
//)";
//
//string actualOutput; //tested these manually on my local, matched
//
//REQUIRE(actualOutput == expectedOutput);
//}
