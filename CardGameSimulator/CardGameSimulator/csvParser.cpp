//
//  CsvParser.cpp
//  CardGameSimulator
//
//  Created by 中 青宝 on 12-12-12.
//  Copyright (c) 2012年 中 青宝. All rights reserved.
//

#include "CsvParser.h"

using std::string;
using std::vector;

void csvline_populate(vector<string> &record, const string& line, char delimiter);

CsvParser::CsvParser(char filePath[])
:fileStream(filePath)
{
    if (fileStream.fail())
    {
        std::cout << "File not found" << std::endl;
    }
}

CsvParser::~CsvParser()
{
    fileStream.close();
}

bool CsvParser::parseRow()
{
    if (fileStream.fail())
    {
        return false;
    }
    
    string line;
    if (getline(fileStream, line)  && fileStream.good())
    {
        csvline_populate(curRecord, line, ',');
        return true;
    }
    
    return false;
}

const CsvRecord & CsvParser::getCurRecord()
{
    return curRecord;
}


void csvline_populate(vector<string> &record, const string& line, char delimiter)
{
    int linepos=0;
    int inquotes=false;
    char c;
    string curstring;
    record.clear();
    
    while(line[linepos]!=0 && linepos < line.length())
    {
        
        c = line[linepos];
        
        if (!inquotes && curstring.length()==0 && c=='"')
        {
            //beginquotechar
            inquotes=true;
        }
        else if (inquotes && c=='"')
        {
            //quotechar
            if ( (linepos+1 <line.length()) && (line[linepos+1]=='"') )
            {
                //encountered 2 double quotes in a row (resolves to 1 double quote)
                curstring.push_back(c);
                linepos++;
            }
            else
            {
                //endquotechar
                inquotes=false;
            }
        }
        else if (!inquotes && c==delimiter)
        {
            //end of field
            record.push_back( curstring );
            curstring="";
        }
        else if (!inquotes && (c=='\r' || c=='\n') )
        {
            record.push_back( curstring );
            return;
        }
        else
        {
            curstring.push_back(c);
        }
        linepos++;
    }
    record.push_back( curstring );
    return;
}
