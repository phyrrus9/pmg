//
//  creature.h
//  pmg
//
//  Created by Ethan Laur on 11/13/13.
//  Copyright (c) 2013 Ethan Laur. All rights reserved.
//

#ifndef __pmg__creature__
#define __pmg__creature__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class creature
{
protected:
    bool dead;
    int health;
    int hp, ap;
    int level, lc, lu;
    char name[32];
public:
    creature();
    creature(FILE *f);
    creature(int _hp, int _ap, int _lu, const char * _name);
    creature(const creature &old);
    void attack(creature * opp); //give damage
    void damage(creature * opp); //take damage
    void operator++(int); //just lc++ and some others
    int gethealth();
    int gethp();
    int getap();
    int getlevel();
    int getlc();
    bool alive();
	char * getname();
};

#endif /* defined(__pmg__creature__) */
