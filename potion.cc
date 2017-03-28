
#include "potion.h"

void RH::useItem(int mag) {
    int max_HP = target->getmax();
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