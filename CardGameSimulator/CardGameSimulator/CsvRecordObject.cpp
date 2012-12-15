//
//  CsvRecordObject.cpp
//  CardGameSimulator
//
//  Created by 中 青宝 on 12-12-13.
//  Copyright (c) 2012年 中 青宝. All rights reserved.
//

#include "CsvRecordObject.h"

#include <iostream>
using std::cout;
using std::endl;

CsvRecordObject::CsvRecordObject(const VectorString &record):
mRecord(record)
{}

CsvRecordObject::~CsvRecordObject()
{}

std::string CsvRecordObject::description()
{
    if (mRecord.size() == 0)
    {
        return "";
    }
    
    std::string str(mRecord[0]);
    for (int i = 1; i < mRecord.size(); ++i)
    {
        str.append("," + mRecord[i]);
    }
    return str;
}

void CsvRecordObject::checkFieldAmound(std::string className) const
{
    if (mRecord.size() != this->fieldAmount())
    {   
        cout << className << "::checkFieldAmound fieldAmount should be " << fieldAmount() << ", but is " << mRecord.size() << endl;
    }
}
