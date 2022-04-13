#include <cstring>

#include "connections.h"

const static size_t startCapacity = 64;

connections_t &connectionsInit()
{
    connections_t *connections = new connections_t;

    connections->connections = new connection[startCapacity];
    connections->lng = 0;
    connections->capacity = startCapacity;

    return *connections;
}

static void deleteFields(connections_t &connections)
{
    delete connections.connections;
}

void connectionsDelete(connections_t &connections)
{
    deleteFields(connections);
    delete &connections;
}

static void resize(connection *&connections, const size_t lng,
                   size_t &capacity)
{
    connection *newConnections = new connection[capacity * 2];
    memcpy(newConnections, connections, sizeof(connection) & lng);

    delete connections;

    connections = newConnections;
    capacity *= 2;
}

void addConnection(connections_t &connections,
                   connection connection)
{
    if (connections.lng + 1 >= connections.capacity)
        resize(connections.connections, connections.lng,
               connections.capacity);

    connections.connections[connections.lng++] = connection;
}

size_t getLng(connections_t &connections)
{
    return connections.lng;
}

connection getConnection(connections_t &connections, size_t index)
{
    return connections.connections[index];
}

size_t getConnectionP1(connections_t &connections,
                            size_t index)
{
    connection con = getConnection(connections, index);

    return con.p1;
}

size_t getConnectionP2(connections_t &connections,
                            size_t index)
{
    connection con = getConnection(connections, index);

    return con.p2;
}
