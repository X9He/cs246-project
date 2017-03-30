#include "enemy.h"
#include "pc.h"

Enemy::~Enemy() {}

// enemy attack 50% miss
// generate random number
int random2(int x, int y){
    int ran;
    ran = x + (rand() % (y - x + 1));
    return ran;
}

// generate random gold
int random_gold(){
    int ran;
    ran = 0 + (rand() % (1 - 0 + 1));
    if (ran == 0) return 1;
    return 2;
}

NormalEnemy::NormalEnemy(int initHP, int initAtk, int initDef, int Gold, PC * target, bool isFrozen, bool moved):
Enemy{initHP, initAtk, initDef, Gold, target, isFrozen, moved}{}

Human::Human(PC * target):
Enemy{140, 20, 20, 0, target}{
    name = 'H';
}

Dwarf::Dwarf(PC * target):
NormalEnemy{100, 20, 30, random_gold(), target}{
    name = 'D';
}

Elf::Elf(PC * target):
NormalEnemy{140, 30, 10, random_gold(), target}{
    name = 'E';
}

Orcs::Orcs(PC * target):
NormalEnemy{180, 30, 25, random_gold(), target}{
    name = 'O';
}

Merchant::Merchant(PC * target):
Enemy{30, 70, 5, 0, target}{
    name = 'M';
}

Dragon::Dragon(PC * target, Treasure * t):
Enemy{150, 20, 20, 0, target}{
    hoard = t;
    name = 'D';
}

Halfling::Halfling(PC * target):
NormalEnemy{100, 15, 20, random_gold(), target} {
    name = 'L';
}



Enemy::Enemy(int initHP, int initAtk, int initDef, int Gold, PC * target, bool isFrozen, bool moved)
: Character{initHP, initAtk, initDef, Gold}, Target(target), isFrozen{isFrozen}, moved{moved} {}


void Enemy::changeFrozen() {
    isFrozen = !isFrozen;
}

// hurt
void Enemy::hurt(Troll *p) {
    int effect = damage(*p);
    changeHP(effect);
}

void Enemy::hurt(Vampire *p) {
    int effect = damage(*p);
    changeHP(effect);
}

void Enemy::hurt(Goblin *p) {
    int effect = damage(*p);
    changeHP(effect);
}

void Enemy::hurt(Drow *p) {
    int effect = damage(*p);
    changeHP(effect);
}

void Enemy::hurt(PC *p) {
    int effect = damage(*p);
    int r = random2(0, 1);
    if (r == 0) {
        changeHP(effect);
    }
}

void Halfling::hurt(Troll *p) {
    int effect = damage(*p);
    int r = random2(0, 1);
    if (r == 0) {
        changeHP(effect);
    }
}

void Halfling::hurt(Vampire *p) {
    int effect = damage(*p);
    int r = random2(0, 1);
    if (r == 0) {
        changeHP(effect);
    }
}

void Halfling::hurt(Goblin *p) {
    int effect = damage(*p);
    int r = random2(0, 1);
    if (r == 0) {
        changeHP(effect);
    }
}

void Halfling::hurt(Drow *p) {
    int effect = damage(*p);
    int r = random2(0, 1);
    if (r == 0) {
        changeHP(effect);
    }
}


void Halfling::hurt(PC *p) {
    int effect = damage(*p);
    int r = random2(0, 1);
    if (r == 0) {
        changeHP(effect);
    }
}

//
void Enemy::changeMoved() {
    moved = !moved;
}

bool Enemy::getMoved() {
    return moved;
}

// attack
void Elf::attack(PC * player) {
    int rad = random2(0, 1);
    if (rad == 0) {
        player->hurt(*this);
    }
}


void Dwarf::attack(PC * player) {
    int rad = random2(0, 1);
    if (rad == 0) {
        player->hurt(*this);
    }
}

void Halfling::attack(PC * player) {
    int rad = random2(0, 1);
    if (rad == 0) {
        player->hurt(*this);
    }
}

void Orcs::attack(PC * player) {
    int rad = random2(0, 1);
    if (rad == 0) {
        player->hurt(*this);
    }
}

void Merchant::attack(PC * player) {
    int rad = random2(0, 1);
    if (rad == 0) {
        player->hurt(*this);
    }
}

void Dragon::attack(PC * player) {
    int rad = random2(0, 1);
    if (rad == 0) {
        player->hurt(*this);
    }
}

void Human::attack(PC * player) {
    int rad = random2(0, 1);
    if (rad == 0) {
        player->hurt(*this);
    }
}


Treasure * Dragon::getHoard(){
    return hoard;
}

bool Merchant::isHostile() {
    return status;
}
