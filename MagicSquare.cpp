//
//  main.cpp
//  HW6pic10B
//
//  Created by Max Dorfman on 2/28/17.
//  Copyright © 2017 Max Dorfman. All rights reserved.
//  I Max Dorfman, affirm that this code is my own and I did not share or collaborate

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
#include "MagicSquare.h"


std::istream& operator>>(std::istream& in, MgcSqr& m){
    std::vector<std::string> r;
    std::string buff;
    std::string& temp = buff;
    std::getline(in, buff);
    for (int row=0;row<n;++row){
        std::getline(in, buff);
        for (int i=0;i<buff.length();++i){
            if (buff[i]=='*')
                temp[i]='0';
            else if ((buff[i]>=1 && buff[i]<=maxNum) || buff[i]==' ')
                temp[i]=buff[i];
        }
        r.push_back(temp);
    }
    for (int row=0;row<n;++row){
        std::istringstream stream(r[row]);
        // for row = 0, stream is 3 4 5.
        for (int col=0;col<n;++col){
            // col = 0
            // read input from the stream until the stream is empty.
            int input;    // store each of those inputs in m[row][col] aka m[0][0
            stream >> input;
            m[row][col] = input;
        }
    }
    return in;
}

std::ostream& operator<<(std::ostream& out, MgcSqr& m){
    for (int row=0;row<n;++row){
        for (int col=0;col<n;++col){
            out<<m[row][col]<<' ';
        }
        out<<std::endl;
    }
    return out;
}
int counter(bool b){
    static int count;
    if (b)
        count++;
    return count;
}
bool empty(MgcSqr& m, int row, int col){
    if (m[row][col] == '0')
        return true;
    else
        return false;
}

bool taken(MgcSqr& m, int row, int col){
    if (m[row][col] <= maxNum && m[row][col] >= 1)
        return true;
    else
        return false;
}
bool checkValid(MgcSqr& m){
    bool rows = false;
    bool cols = false;
    bool diag = false;
    int rowCount = 0;
    int colCount = 0;
    int diagCount = 0;
    for (int row=0;row<n;++row){
        int rowSum = 0;
        for (int col=0;col<n;++col){
            rowSum+=m[row][col];
        }
        if (rowSum == magicNum)
            ++rowCount;
    }
    if (rowCount == n)
        rows = true;
    for (int col=0;col<n;++col){
        int colSum = 0;
        for (int row=0;row<n;++row){
            colSum+=m[row][col];
        }
        if (colSum == magicNum)
            ++colCount;
    }
    if (colCount == n)
        cols = true;
    int diagSum = 0;
    for (int row=0;row<n;++row){
        diagSum+=m[row][(n-1)-row];
    }
    if (diagSum == magicNum)
        ++diagCount;
    
    diagSum = 0;
    for (int row=0;row<n;++row){
        diagSum+=m[(n-1)-row][row];
    }
    if (diagSum == magicNum)
        ++diagCount;
    if (diagCount == 2)
        diag = true;
    if (rows && cols && diag)
        return true;
    else
        return false;
}
void solveSquare(MgcSqr& m, int chk){
    int row = chk-1;
    int col = chk%n;
    if(empty(m, row, col)){
        for (int i = 1; i < maxNum; ++i){
            m[row][col] = i;
            if (chk<maxNum)
                solveSquare(m, chk + 1);
            else
                if (checkValid(m)){
                    std::cout << m;
                    counter(true);
                }
        }
    }
    else if (taken(m, row, col)){
        if (chk<maxNum)
            solveSquare(m, chk + 1);
        else
            if (checkValid(m)){
                std::cout << m;
                counter(true);
            }
    }
}

int main() {
    
    std::cout << "Welcome to Magic Square Solver" << std::endl;
    std::cout << "enter a square size: ";
    std::cin>>n;
    maxNum = n*n;
    magicNum = n*(n*n+1)/2;
    MgcSqr m;
    m.resize(n, std::vector<int>(n));
    std::cout << "enter format for " << n << "*" << n << " square:" << std::endl;
    std::cin>>m;
    std::cout<<"you input:"<<std::endl;
    std::cout<<m;
    std::cout<<"Solving!"<<std::endl;
    int chk = 1;
    solveSquare(m, chk);
    std::cout<<"Solving Complete!"<<std::endl;
    std::cout<<"There were "<< counter(false) <<" solutions!";

        return 0;
}
