//
//  CardGameSimulatorUnitTest.m
//  CardGameSimulatorUnitTest
//
//  Created by 中 青宝 on 12-12-11.
//  Copyright (c) 2012年 中 青宝. All rights reserved.
//

#import "CardGameSimulatorUnitTest.h"
#include "Battle.h"

@implementation CardGameSimulatorUnitTest

- (void)setUp
{
    [super setUp];
    
    // Set-up code here.
}

- (void)tearDown
{
    // Tear-down code here.
    
    [super tearDown];
}

- (void)testExample
{
    STAssertTrue(0 == 0, @"");
}

- (void)testInit
{
    Battle battle;
    
    STAssertTrue(0 == battle.getCardAmoundFromGround(0), @"");
    battle.setCardToGround((Card){10, 5}, (CardSlotLocation){0, 1});
    battle.setCardToGround((Card){9, 6}, (CardSlotLocation){1, 1});
    
    STAssertTrue(1 == battle.getCardAmoundFromGround(0), @"");
    
    CardSlot cardSlot;
    cardSlot.hasCard = false;
    STAssertTrue(battle.getCardSlotFromGround(cardSlot, (CardSlotLocation){0, 1}) == true, @"");
    STAssertTrue(cardSlot.hasCard == true, @"");
    STAssertTrue(cardSlot.card.health == 10, @"");
    
    battle.getCardSlotFromGround(cardSlot, (CardSlotLocation){1, 1});
    STAssertTrue(cardSlot.card.attack == 6, @"");
}

- (void)testMove
{
    Battle battle;
    
    CardSlot cardSlot;
    CardSlotLocation source = {0, 1};
    battle.setCardToGround((Card){10, 5}, source);
    battle.getCardSlotFromGround(cardSlot, source);
    STAssertTrue(cardSlot.hasCard == true, @"");
    
    CardSlotLocation target = {0, 3};
    battle.getCardSlotFromGround(cardSlot, target);
    STAssertTrue(cardSlot.hasCard == false, @"");
    
    battle.moveCard(source, target);
    
    battle.getCardSlotFromGround(cardSlot, target);
    STAssertTrue(cardSlot.hasCard = true, @"");
}

- (void)testAttack
{
    Battle battle;
    
    CardSlotLocation card1Location = {0, 1};
    CardSlotLocation card2Location = {1, 1};
    battle.setCardToGround((Card){10, 5}, card1Location);
    battle.setCardToGround((Card){9, 6}, card2Location);
    
    battle.attackCard(card1Location, card2Location);
    CardSlot cardSlot;
    battle.getCardSlotFromGround(cardSlot, card2Location);
    STAssertTrue(cardSlot.card.health == 4, @"");
}

@end
