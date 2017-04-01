
#include "potion.h"
#include "pc.h"
#include "character.h"

using namespace std;

Potion::Potion(PC* player, char itemType): Item{itemType, player} {}

Potion::~Potion() {}

string Potion::getPotionType() {
  return potionType;
}


RH::RH(PC* player): Potion(player) {potionType = "RH"; }
BA::BA(PC* player): Potion(player) {potionType = "BA"; }
BD::BD(PC* player): Potion(player) {potionType = "BD"; }
PH::PH(PC* player): Potion(player) {potionType = "PH"; }
WD::WD(PC* player): Potion(player) {potionType = "WD"; } 
WA::WA(PC* player): Potion(player) {potionType = "WA"; }

RH::~RH() {}
BA::~BA() {}
BD::~BD() {}
PH::~PH() {}
WD::~WD() {}
WA::~WA() {}

void RH::useItem(int mag) {
    int max_HP = target->getMax();
    int cur_HP = target->getHP();
    
    if (cur_HP+mag <= max_HP) {
        target->changeHP(mag);
    } else {
        target->changeHP(max_HP);
    }
}

void BA::useItem(int mag) {
    int cur_Atk = target->getAtk();
    target->changeAtk(mag);
}

void BD::useItem(int mag) {
    int cur_Def = target->getDef();
    target->changeDef(mag);
}

void PH::useItem(int mag) {
    int cur_HP = target->getHP();
    if (cur_HP-mag >= 0) {
        target->changeHP(0-mag);
    } else {
        target->changeHP(0);
    }
}

void WA::useItem(int mag) {
    int cur_Atk = target->getAtk();
    target->changeAtk(0-mag);
}

void WD::useItem(int mag) {
    int cur_Def = target->getDef();
    target->changeAtk(0-mag);
}
