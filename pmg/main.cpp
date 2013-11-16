//
//  main.cpp
//  pmg
//
//  Created by Ethan Laur on 11/12/13.
//  Copyright (c) 2013 Ethan Laur. All rights reserved.
//

#include <iostream>
//#define arraylist_developer /*this way, we can use getlist()*/ /*yes, im lazy*/
//#define linkedlist_type_developer
#include <time.h>
#include <stdlib.h>
#include "arraylist.h"
#include "creature.h"

int main(int argc, const char * argv[])
{
    arraylist<creature> deck;
	srand((unsigned)time(0));
	int i;
	int hold = -1;
	for (i = 0; i < 7; i++)
	{
		deck.add(*new creature(rand() % 10, rand() % 10, rand() % 3, ""));
	}
    printf("Deck:\n");
	while (1)
	{
		for (int i = 0; i < deck.size(); i++)
		{
			printf("\t%d->%s: HP: %02d AP: %02d Health: %02d Level: %02d Alive: %s\n",
				   i,
				   deck.getro(i).getname(),
				   deck.getro(i).gethp(),
				   deck.getro(i).getap(),
				   deck.getro(i).gethealth(),
				   deck.getro(i).getlevel(),
				   deck.getro(i).alive() ? "Yes" : "No"
				   );
		}
		while (hold < 0)
		{
			printf("Pick your creature: ");
			scanf("%d", &hold);
		}
		char opt;
		printf("1. attack\n"
			   "2. end game\n");
		scanf("%c", &opt);
		if (opt == '1')
		{
			int cre;
			printf("Creature: ");
			scanf("%d", &cre);
			deck.get(hold)->attack(deck.get(cre));
			if (!deck.get(cre)->alive())
				deck.remove(cre);
		}
		if (opt == '2')
			break;
		opt = 0;
	}
    return 0;
}

