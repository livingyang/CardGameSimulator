//
//  Battle.h
//  CardGameSimulator
//
//  Created by 中 青宝 on 12-12-11.
//  Copyright (c) 2012年 中 青宝. All rights reserved.
//

#ifndef __CardGameSimulator__Battle__
#define __CardGameSimulator__Battle__

#include <iostream>
#include "BattleDefine.h"

#define MAX_BATTLE_GROUND (2)

typedef struct
{
    int groundIndex;
    int cardSlotIndex;
} CardSlotLocation;

class Battle
{
public:
    Battle();
    ~Battle();
    
    // card setter/getter
    bool isValidCardSlotLocation(CardSlotLocation cardSlotLocation);
    
    void setCardToGround(Card card, CardSlotLocation cardSlotLocation);
    void removeCardFromGround(CardSlotLocation cardSlotLocation);
    
    bool getCardSlotFromGround(CardSlot &cardSlot, CardSlotLocation cardSlotLocation);
    
    void setGeneralToGround(Card generalCard, CardSlotLocation cardSlotLocation);
    bool getGeneralFromGround(Card &generalCard, CardSlotLocation cardSlotLocation);
    
    int getCardAmoundFromGround(int groundIndex);
    
    bool moveCard(CardSlotLocation sourceLocation, CardSlotLocation targetLocation);
    bool attackCard(CardSlotLocation attackerLocation, CardSlotLocation defenserLocation);

private:
    Ground groundList[MAX_BATTLE_GROUND];
};

#endif /* defined(__CardGameSimulator__Battle__) */
