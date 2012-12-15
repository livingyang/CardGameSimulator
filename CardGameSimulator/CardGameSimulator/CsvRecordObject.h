//
//  CsvRecordObject.h
//  CardGameSimulator
//
//  Created by 中 青宝 on 12-12-13.
//  Copyright (c) 2012年 中 青宝. All rights reserved.
//

#ifndef __CardGameSimulator__CsvRecordObject__
#define __CardGameSimulator__CsvRecordObject__

#include <string>
#include <vector>

typedef std::vector<std::string> VectorString;

class CsvRecordObject
{
public:
    CsvRecordObject(const VectorString &record);
    virtual ~CsvRecordObject();
    
    virtual int fieldAmount() const = 0;
    virtual std::string description();
    
protected:
    void checkFieldAmound(std::string className) const;
    
protected:
    VectorString mRecord;
};

#endif /* defined(__CardGameSimulator__CsvRecordObject__) */
