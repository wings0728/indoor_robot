#include "T3Database.hpp"

namespace interface
{
T3Database::T3Database()
{
    //connectDatabase();
}

T3Database* T3Database::_t3datebase = new T3Database();

T3Database* T3Database::getInstance()
{
  return _t3datebase;
}

T3DatabaseIdenCode T3Database::connectDatabase()
{

    if(_database.open())
    {
      return DatabaseOpenSuccess;
    }
    _database = QSqlDatabase::addDatabase(kDatabaseEngine);
    _database.setDatabaseName(kDatabaseName);
    _database.setHostName(kDatabaseURL);
    _database.setUserName(kDatabaseUserName);
    _database.setPassword(kDatabasePassword);
    if(!_database.open())
    {
        T3LOG << "database not open";
        return DatabaseNotOpen;

    }
    return DatabaseOpenSuccess;
}

T3Database::~T3Database()
{
  _database.close();
  QSqlDatabase::removeDatabase(kDatabaseName);
}
}
