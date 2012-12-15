//
//  CardDetail.h
//  CardGameSimulator
//
//  Created by 中 青宝 on 12-12-12.
//  Copyright (c) 2012年 中 青宝. All rights reserved.
//

#ifndef __CardGameSimulator__CardDetail__
#define __CardGameSimulator__CardDetail__

#include <string>
#include <vector>

#include "CsvRecordObject.h"

//"No","名称","種族","レア","支配力","コスト","Slot","HP","攻撃力","能力1","能力2","成長2","成長3","成長4","成長5","成長6","成長7","成長8"
class CardDetail : public CsvRecordObject
{
public:
    CardDetail(const VectorString &vectorString);
    ~CardDetail();
    
    virtual int fieldAmount() const;
    virtual std::string description();
    
public:
    
    int cardId();
    std::string name();
    
    std::string type();
    std::string rare();
    
    int supportPoint();
    int costPoint();
    
    int slot();
    int health();
    int attack();
    
    VectorString skillList();
    
    // A1 = attack + 1, S1 = slot + 1, H2 = health + 2
    VectorString levelUpList();
};

#endif /* defined(__CardGameSimulator__CardDetail__) */
