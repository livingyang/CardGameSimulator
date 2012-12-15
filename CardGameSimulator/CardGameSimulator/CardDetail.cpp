//
//  Cardcpp
//  CardGameSimulator
//
//  Created by 中 青宝 on 12-12-12.
//  Copyright (c) 2012年 中 青宝. All rights reserved.
//

#include "CardDetail.h"
using std::string;

#include <sstream>
using std::stringstream;

CardDetail::CardDetail(const VectorString &vectorString)
:CsvRecordObject(vectorString)
{
    checkFieldAmound("CardDetail");
}

CardDetail::~CardDetail()
{}

int CardDetail::fieldAmount() const
{
    return 18;
}

std::string CardDetail::description()
{
    stringstream sstream;
    
    sstream << "id = " << cardId() << "\n";
    sstream << "name = " << name() << "\n";
    sstream << "type = " << type() << "\n";
    sstream << "rare = " << rare() << "\n";
    sstream << "support = " << supportPoint() << "\n";
    sstream << "cost = " << costPoint() << "\n";
    sstream << "slot = " << slot() << "\n";
    sstream << "health = " << health() << "\n";
    sstream << "attack = " << attack() << "\n";
    
    for (int i = 0; i < skillList().size(); ++i)
    {
        sstream << "skill " << i << " = " << skillList()[i] << "\n";
    }
    
    for (int i = 0; i < levelUpList().size(); ++i)
    {
        sstream << "level up " << i << " = " << levelUpList()[i] << "\n";
    }
    
    return sstream.str();
}

int CardDetail::cardId()
{
    return atoi(mRecord[0].c_str());
}

std::string CardDetail::name()
{
    return mRecord[1];
}

std::string CardDetail::type()
{
    return mRecord[2];
}

std::string CardDetail::rare()
{
    return mRecord[3];
}

int CardDetail::supportPoint()
{
    return atoi(mRecord[4].c_str());
}
int CardDetail::costPoint()
{
    return atoi(mRecord[5].c_str());
}

int CardDetail::slot()
{
    return atoi(mRecord[6].c_str());
}

int CardDetail::health()
{
    return atoi(mRecord[7].c_str());
}

int CardDetail::attack()
{
    return atoi(mRecord[8].c_str());
}

VectorString CardDetail::skillList()
{
    return VectorString(mRecord.begin() + 9, mRecord.begin() + 11);
}

VectorString CardDetail::levelUpList()
{
    return VectorString(mRecord.begin() + 11, mRecord.begin() + fieldAmount());
}
