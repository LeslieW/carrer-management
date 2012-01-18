/******************************************************************************
 *
 *	PriorityQueue.h
 *
 *	Represents a prioritized queue.
 *
 *	Created at:
 *	2012-01-18
 *
 *	Author(s):
 *
 *		B5-8 LAPRIII group
 *
 *****************************************************************************/

#ifndef _PRIORITYQUEUE_H
#define _PRIORITYQUEUE_H

#include <iostream>
#include <string>
#include <queue>
#include <utility>

namespace core
{

typedef enum _CRITERIAS
{
    CATEGORY,
    AGE,
    N
} CRITERIAS;

typedef std::pair<int[CRITERIAS::N], int[CRITERIAS::N]> Priority;

class PriorityQueue
{
private:
    std::queue<Priority> requests;
    int criterias[] = { CRITERIAS::CATEGORY, CRITERIAS::AGE };

public:
    PriorityQueue();

    void push(const Priority &priority);
    const Priority& pop();

    void clear();
};

}

#endif /* _PRIORITYQUEUE_H */
