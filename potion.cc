
#include "potion.h"
#include "pc.h"
#include "character.h"


Potion::Potion(PC* player, char itemType): Item{itemType, player} {}

Potion::~Potion() {}
  
RH::RH(PC* player): Potion(player) {}
BA::BA(PC* player): Potion(player) {}
BD::BD(PC* player): Potion(player) {}
PH::PH(PC* player): Potion(player) {}
WD::WD(PC* player): Potion(player) {}
WA::WA(PC* player): Potion(player) {}

RH::~RH() {}
BA::~BA() {}
BD::~BD() {}
PH::~PH() {}
WD::~WD() {}
WA::~WA() {}

void RH::useItem(int mag) {
    int max_HP = target->getMax();
    int cur_HP = target->getHP();
    
    if (cur_HP+mag*10 <= max_HP) {
        target->changeHP(cur_HP+mag*10);
    } else {
        target->changeHP(max_HP);
    }
}

void BA::useItem(int mag) {
    int cur_Atk = target->getAtk();
    target->changeAtk(cur_Atk+mag*5);
}

void BD::useItem(int mag) {
    int cur_Def = target->getDef();
    target->changeDef(cur_Def+mag*5);
}

void PH::useItem(int mag) {
    int cur_HP = target->getHP();
    if (cur_HP-mag*10 >= 0) {
        target->changeHP(cur_HP-mag*10);
    } else {
        target->changeHP(0);
    }
}

void WA::useItem(int mag) {
    int cur_Atk = target->getAtk();
    target->changeAtk(cur_Atk-mag*5);
}

void WD::useItem(int mag) {
    int cur_Def = target->getDef();
    target->changeAtk(cur_Def-mag*5);
}
