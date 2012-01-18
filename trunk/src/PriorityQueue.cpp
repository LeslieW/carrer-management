#include "PriorityQueue.h"

#include <iostream>
#include <string>
#include <queue>
#include <utility>

using std::queue;

using core::Priority;
using core::PriorityQueue;
using core::CRITERIAS;

void PriorityQueue::push(const Priority &priority)
{
    queue<Priority> auxQueue;

    // first by priority
    for (int i = 0; i < CRITERIAS::N; i++)
    {
        if (requests.front().first[i] == priority.first[i])
        {
            while (requests.front().second[i] >= priority.second[i])
            {
                auxQueue.push(requests.front());
                requests.pop();
            }

            auxQueue.push(priority);
        }
    }

    // then the remaining ones
    while (!requests.empty())
    {
        auxQueue.push(requests.front());
        requests.pop();
    }

    request = auxQueue;
}

const Priority& PriorityQueue::pop()
{
    Priority &ret = requests.front();
    requests.pop();

    return ret;
}

void PriorityQueue::clear()
{
    requests.clear();
}
