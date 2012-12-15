//
//  CsvParser.h
//  CardGameSimulator
//
//  Created by 中 青宝 on 12-12-12.
//  Copyright (c) 2012年 中 青宝. All rights reserved.
//

#ifndef __CardGameSimulator__CsvParser__
#define __CardGameSimulator__CsvParser__

#include <fstream>
#include <iostream>

#include <string>
#include <vector>

typedef std::vector<std::string> CsvRecord;

class CsvParser
{
public:
    CsvParser(char filePath[]);
    ~CsvParser();
    
    bool parseRow();
    
    const CsvRecord &getCurRecord();
    
private:
    std::ifstream fileStream;
    
    CsvRecord curRecord;
};

#endif /* defined(__CardGameSimulator__CsvParser__) */
