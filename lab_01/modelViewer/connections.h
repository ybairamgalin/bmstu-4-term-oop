#ifndef CONNECTIONS_H
#define CONNECTIONS_H

#ifndef START_CONNECTIONS_CAPACITY
#define START_CONNECTIONS_CAPACITY 64
#endif

#include "connection.h"

struct connections
{
    connection *connections;
    size_t lng;
    size_t capacity;
};

typedef struct connections connections_t;

connections_t &connectionsInit();
void connectionsDelete(connections_t &);

void addConnection(connections_t &connections,
                   connection connection);

size_t getLng(connections_t &connections);

connection getConnection(connections_t &connections,
                         size_t index);
size_t getConnectionP1(connections_t &connections,
                            size_t index);
size_t getConnectionP2(connections_t &connections,
                            size_t index);

#endif // CONNECTIONS_H
