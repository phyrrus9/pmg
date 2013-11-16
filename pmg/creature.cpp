//
//  creature.cpp
//  pmg
//
//  Created by Ethan Laur on 11/13/13.
//  Copyright (c) 2013 Ethan Laur. All rights reserved.
//

#include "creature.h"

creature::creature()
{
    //yeah, nothing..
}

creature::creature(FILE *f)
{
	fread(name   , 32          , 1, f);
    fread(&dead  , sizeof(bool), 1, f);
    fread(&health, sizeof(int ), 1, f);
    fread(&hp    , sizeof(int ), 1, f);
    fread(&ap    , sizeof(int ), 1, f);
    fread(&level , sizeof(int ), 1, f);
    fread(&lc    , sizeof(int ), 1, f);
    fread(&lu    , sizeof(int ), 1, f);
}

creature::creature(int _hp, int _ap, int _lu, const char * _name)
{
	strcpy(name, _name);
    dead = false;
    health = 100;
    hp = _hp;
    ap = _ap;
    level = 1;
    lc = 0;
    lu = _lu;
}

creature::creature(const creature &old)
{
	strcpy(name, old.name);
    dead = old.dead;
    health = old.health;
    hp = old.hp;
    ap = old.ap;
    level = old.level;
    lc = old.lc;
}

void creature::attack(creature * opp)
{
	if (!opp->alive())
		return; //dont beat a dead body
    opp->damage(this);
    int dmg = (hp - opp->getap()) / 2;
	health -= dmg > 0 ? 0 : dmg;
    if (!opp->alive())
    {
        operator++(0); //ignore the 0
    }
}

void creature::damage(creature * opp)
{
    int dmg = opp->getap() * (opp->getlevel() < 3 ? opp->getlevel() : opp->getlevel() / 2) - hp;
    if (dmg > 0)
    {
        health -= dmg;
        if (health <= 0)
        {
            dead = true;
        }
    }
}

void creature::operator++(int)
{
    health = (health < 100) ? 100 : health;
    lc++;
    if (lc >= lu)
    {
        lc -= lu;
        level++;
    }
}

int creature::gethealth()
{
    return health;
}

int creature::gethp()
{
    return hp;
}

int creature::getap()
{
    return ap;
}

int creature::getlevel()
{
    return level;
}

int creature::getlc()
{
    return lc;
}

bool creature::alive()
{
    return !dead;
}

char * creature::getname()
{
	return name;
}
