//
//  main.cpp
//  CardGameSimulator
//
//  Created by 中 青宝 on 12-12-11.
//  Copyright (c) 2012年 中 青宝. All rights reserved.
//
#include <iostream>
#include "CsvParser.h"
#include "CardDetail.h"

using namespace std;

int main(int argc, char *argv[])
{
    char filePath[] = "/Users/ZQP/Documents/GitWorkPlace/CardGameSimulator/CardGameSimulator/CardGameSimulatorUnitTest/test.csv";
    CsvParser parser(filePath);
    return 0;
    while (parser.parseRow())
    {
        for(int i = 0; i < parser.getCurRecord().size(); i++)
        {
            cout << parser.getCurRecord()[i] << "\t\t";
        }
        cout << endl;
        
        CardDetail detail(parser.getCurRecord());
        
        cout << "description = " << detail.description() << endl;
    }
    return 0;
}
