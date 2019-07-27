//
//  recursion.cpp
//  Homework 3
//
//  Created by Michaella Baltazar on 7/22/19.
//  Copyright © 2019 Michaella Baltazar. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
//using std::string;
using namespace std;

// Returns the product of two non-negative integers, m and n,
// using only repeated addition.
int prod(unsigned int m, unsigned int n)
{
    if (n==0)
    {
        return 0;
    }
    else
    {
        return m + prod(m, n-1);
    }
}


// Returns the number of occurrences of digit in the decimal
// representation of num. digit is an int between 0 and 9
// inclusive.
//
// Pseudocode Example:
//    numberOfDigits(18838, 8) => 3
//    numberOfDigits(55555, 3) => 0
//    numberOfDigits(0, 0)     => 0 or 1 (either if fine)
//
int numberOfDigits(int num, int digit)
{
    if (num <10)
    {
        if (num == digit)
            return 1;
        else
            return 0;
    }
    else if (num%10==digit)
    {
            return (numberOfDigits(num/10, digit) + 1);
    }
    else
    {
            return numberOfDigits(num/10,digit);
    }
    //return -1;  // This is incorrect.
}


// Returns a string where the same characters next each other in
// string n are separated by "22"
//
// Pseudocode Example:
//    doubleDouble("goodbye") => "go22odbye"
//    doubleDouble("yyuu")    => "y22yu22u"
//    doubleDouble("aaaa")    => "a22a22a22a"
//
string doubleDouble(string n)
//    if (n.length()>3)
//    {
//        return doubleDouble(n.substr(0, n.length()/2)) + doubleDouble(n.substr(n.length()/2));
//    }
//    else if (n.length()==2)
//    {
//        if (n.at(0)==n.at(1))
//        {
//            return n.substr(0,1)+ "22" +n.substr(1);
//        }
//        else return n;
//    }
//    else if (n.length()==3)
//    {
//        if (n.at(0) == n.at(1) == n.at(2))
//        {
//            return n.substr(0,1)+ "22" +n.substr(1,2) + "22" + n.substr(2);
//        }
//        else if (n.at(0)==n.at(1))
//        {
//            return n.substr(0,1)+ "22" +n.substr(1);
//        }
//        else if (n.at(1)==n.at(2))
//        {
//            return n.substr(0,2)+ "22" +n.substr(2);
//        }
//        else
//        {
//            return n;
//        }
//    }
{
    if (n.length() <= 1)
    {
        return n;
    }
    else if (n.length() == 2)
    {
        if (n[0] == n[1])
        {
            return n.substr(0,1) + "22" + n.substr(1,1);
        }
        else
        {
            return n;
        }
    }
    else
    {
        return doubleDouble(n.substr(0, 2)) + doubleDouble(n.substr(1));
    }
}

// str contains a single pair of curly brackets, return a new
// string made of only the curly brackets and whatever those
// curly brackets contain
//
//  Pseudocode Example:
//     curlyFries("abc{ghj}789") => "{ghj}"
//     curlyFries("{x}7")
//     curlyFries("4agh{y}")
//     curlyFries("4agh{}")
//
string curlyFries(string str)
{
   if (str[0]!='{' && str[str.length()-1] != '}')
   {
        return curlyFries(str.substr((1), str.length()-2));
   }
   else if (str[0]!='{')
   {
        return curlyFries(str.substr(1));
   }
    else if (str[str.length()-1] != '}')
    {
        return curlyFries(str.substr(0, str.length()-2));
    }
    else                                //only if str[0] == '{' and str[length()-1] == '}'
    {
        return str;
    }
}


// Return true if the total of any combination of elements in
// the array a equals the value of the target.
//
//  Pseudocode Example:
//     addEmUp([2, 4, 8], 3, 10) => true
//     addEmUp([2, 4, 8], 3, 6) => true
//     addEmUp([2, 4, 8], 3, 11) => false
//     addEmUp([2, 4, 8], 3, 0)  => true
//     addEmUp([], 0, 0)         => true
//
bool addEmUp(const int a[], int size, int target)
{
    if (size == 0 && target == 0)
    {
        return true;
    }
    else if (size == 0 && target != 0)
    {
            return false;
    }
    else
    {
        return addEmUp(a+1, size - 1, target - a[0]) || addEmUp(a+1, size - 1, target);
    }
    //return false;  // This is not always correct.
}

bool canWeFinish(string maze[], int nRows, int nCols, int sr, int sc, int er, int ec)
{
    if (sr > nRows || sc > nCols || er > nRows || ec > nCols )
        return false;
    if (sr == er && sc == ec)
        return true;
    maze [sr][sc]= '#';
    if (maze[sr-1][sc] == '.')
    {
        return canWeFinish(maze, nRows, nCols, sr-1, sc, er, ec);
    }
    if (maze[sr+1][sc] == '.')
    {
        return canWeFinish(maze, nRows, nCols, sr+1, sc, er, ec);
    }
    if (maze[sr][sc-1] == '.')
    {
        return canWeFinish(maze, nRows, nCols, sr, sc-1, er, ec);
    }
    if (maze[sr][sc+1] == '.')
    {
        return canWeFinish(maze, nRows, nCols, sr, sc+1, er, ec);
    }
    return false;
}




//bool canWeFinish(string maze[], int nRows, int nCols,
//                 int sr, int sc, int er, int ec);
// Return true if there is a path from (sr,sc) to (er,ec)
// through the maze; return false otherwise



int main()
{
    cout << doubleDouble("abba") << endl;
}
