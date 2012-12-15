//
//  CardGameSimulatorUnitTest.m
//  CardGameSimulatorUnitTest
//
//  Created by 中 青宝 on 12-12-11.
//  Copyright (c) 2012年 中 青宝. All rights reserved.
//

#import "CardGameSimulatorUnitTest.h"
#include "Battle.h"
#include "CardDetail.h"

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

- (void)testCardDetail
{
    //"No","名称","種族","レア","支配力","コスト","Slot","HP","攻撃力","能力1","能力2","成長2","成長3","成長4","成長5","成長6","成長7","成長8"
    std::string cardString[] = {"200", "name", "type", "rare", "1", "2", "1", "10", "6", "skill1", "skill2", "S1", "A2", "H1", "H1", "S1", "A2", "H1"};
    CardDetail detail(VectorString(cardString, cardString + sizeof(cardString) / sizeof(cardString[0])));
    
    STAssertTrue(detail.cardId() == 200, @"");
    STAssertTrue(detail.health() == 10, @"");
    STAssertTrue(detail.attack() == 6, @"");
    STAssertTrue(detail.skillList()[0] == "skill1", @"");
    STAssertTrue(detail.levelUpList()[0] == "S1", @"");
    STAssertTrue(detail.levelUpList()[6] == "H1", @"");
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

- (void)testGerenal
{
    Battle battle;
    
    CardSlotLocation card1Location = {0, 1};
    CardSlotLocation card2Location = {1, 1};
    battle.setGeneralToGround((Card){10, 5}, card1Location);
    battle.setGeneralToGround((Card){9, 6}, card2Location);
    
    Card generalCard;
    battle.getGeneralFromGround(generalCard, card1Location);
    
    STAssertTrue(generalCard.attack == 5, @"");
}

@end
