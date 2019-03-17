//
//  Header.h
//  HW6pic10B
//
//  Created by Max Dorfman on 2/28/17.
//  Copyright © 2017 Max Dorfman. All rights reserved.
//  I Max Dorfman, affirm that this code is my own and I did not share or collaborate

#ifndef Header_h
#define Header_h

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>

int n;
int maxNum;
int magicNum;
using MgcSqr = std::vector<std::vector<int>>;

std::istream& operator>>(std::istream& in, MgcSqr& m);
 
std::ostream& operator<<(std::ostream& out, MgcSqr& m);
    
int counter(bool b);
    
bool empty(MgcSqr& m, int row, int col);
    
bool taken(MgcSqr& m, int row, int col);

bool checkValid(MgcSqr& m);
    
void solveSquare(MgcSqr& m, int chk);
 

#endif /* Header_h */
