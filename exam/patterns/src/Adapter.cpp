#include <iostream>

class MySqlConnection
{
public:
    void mySqlInsert() { std::cout << "MY SQL INSERT\n"; };
};

class PostgreSqlConnection
{
public:
    void postgresInsert() { std::cout << "POSTGRES INSERT\n"};
};

class BaseConnection
{
public:
    virtual void insert() = 0;
};


class MySqlAdapter : public BaseConnection
{
public:
    MySqlAdapter() { connection = new MySqlConnection; }
    void insert() override { connection->mySqlInsert(); }

private:
    MySqlConnection *connection;
};

class PostgresAdapter : public BaseConnection
{
public:
    PostgresAdapter() { connection = new PostgreSqlConnection; }
    void insert() override { connection->postgresInsert(); }

private:
    PostgreSqlConnection *connection;
};

int main()
{
    BaseConnection *connection = new PostgresAdapter();
    connection->insert();

    connection = new MySqlAdapter;
    connection->insert();

    return 0;
}
