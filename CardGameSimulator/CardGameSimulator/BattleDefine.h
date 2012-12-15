//
//  BattleDefine.h
//  CardGameSimulator
//
//  Created by 中 青宝 on 12-12-11.
//  Copyright (c) 2012年 中 青宝. All rights reserved.
//

#ifndef CardGameSimulator_BattleDefine_h
#define CardGameSimulator_BattleDefine_h

typedef struct
{
    int health;
    int attack;
} Card;

#define MAX_GROUND_CARDSLOT (6)

typedef struct
{
    bool hasCard;
    
    Card card;
} CardSlot;

typedef struct
{
    CardSlot cardSlotList[MAX_GROUND_CARDSLOT];
} Ground;

#endif
