//
//  Battle.cpp
//  CardGameSimulator
//
//  Created by 中 青宝 on 12-12-11.
//  Copyright (c) 2012年 中 青宝. All rights reserved.
//

#include "Battle.h"

// return num is [min, max);
bool betweenFunc(int num, int min, int max)
{
    if (min > max)
    {
        int temp = min;
        min = max;
        max = temp;
    }
    
    return (num >= min && num < max);
}

Battle::Battle()
{
    memset(&groundList, 0, sizeof(groundList));
}

Battle::~Battle()
{
}

bool Battle::isValidCardSlotLocation(CardSlotLocation cardSlotLocation)
{
    return (betweenFunc(cardSlotLocation.groundIndex, 0, MAX_BATTLE_GROUND)
            && betweenFunc(cardSlotLocation.cardSlotIndex, 0, MAX_GROUND_CARDSLOT));
}

void Battle::setCardToGround(Card card, CardSlotLocation cardSlotLocation)
{
    if (!isValidCardSlotLocation(cardSlotLocation))
    {
        return;
    }
    
    groundList[cardSlotLocation.groundIndex].cardSlotList[cardSlotLocation.cardSlotIndex].card = card;
    groundList[cardSlotLocation.groundIndex].cardSlotList[cardSlotLocation.cardSlotIndex].hasCard = true;
}

void Battle::removeCardFromGround(CardSlotLocation cardSlotLocation)
{
    if (!isValidCardSlotLocation(cardSlotLocation))
    {
        return;
    }
    
    groundList[cardSlotLocation.groundIndex].cardSlotList[cardSlotLocation.cardSlotIndex].hasCard = false;
}

bool Battle::getCardSlotFromGround(CardSlot &cardSlot, CardSlotLocation cardSlotLocation)
{
    if (!isValidCardSlotLocation(cardSlotLocation))
    {
        return false;
    }
    
    cardSlot = groundList[cardSlotLocation.groundIndex].cardSlotList[cardSlotLocation.cardSlotIndex];
    return true;
}

int Battle::getCardAmoundFromGround(int groundIndex)
{
    if (!betweenFunc(groundIndex, 0, MAX_BATTLE_GROUND))
    {
        return 0;
    }
    
    int cardAmound = 0;
    for (int i = 0; i < MAX_GROUND_CARDSLOT; ++i)
    {
        if (groundList[groundIndex].cardSlotList[i].hasCard)
        {
            ++cardAmound;
        }
    }
    return cardAmound;
}

bool Battle::moveCard(CardSlotLocation sourceLocation, CardSlotLocation targetLocation)
{
    if (!isValidCardSlotLocation(sourceLocation) || !isValidCardSlotLocation(targetLocation))
    {
        return false;
    }
    
    CardSlot sourceSlot;
    CardSlot targetSlot;
    
    getCardSlotFromGround(sourceSlot, sourceLocation);
    getCardSlotFromGround(targetSlot, targetLocation);
    
    if (sourceSlot.hasCard && targetSlot.hasCard == false)
    {
        setCardToGround(sourceSlot.card, targetLocation);
        removeCardFromGround(sourceLocation);
        return true;
    }
    
    return false;
}

bool Battle::attackCard(CardSlotLocation attackerLocation, CardSlotLocation defenserLocation)
{
    if (!isValidCardSlotLocation(attackerLocation) || !isValidCardSlotLocation(defenserLocation))
    {
        return false;
    }
    
    CardSlot attackerSlot;
    CardSlot defenserSlot;
    
    getCardSlotFromGround(attackerSlot, attackerLocation);
    getCardSlotFromGround(defenserSlot, defenserLocation);
    
    if (attackerSlot.hasCard && defenserSlot.hasCard)
    {
        defenserSlot.card.health -= attackerSlot.card.attack;
        setCardToGround(defenserSlot.card, defenserLocation);
        return true;
    }
    
    return false;
}
