#include "T3DBConnectionPool.hpp"


namespace interface
{
QMutex T3DBConnectionPool::_mutex;
QWaitCondition T3DBConnectionPool::_waitCondition;
T3DBConnectionPool* T3DBConnectionPool::_connectionPoolInstance = NULL;

T3DBConnectionPool::T3DBConnectionPool()
{
  _hostName = kDatabaseURL;
  _databaseName = kDatabaseName;
  _userName = kDatabaseUserName;
  _password = kDatabasePassword;
  _databaseType = kDatabaseEngine;

  _testOnBorrow = true;
  _testonBorrowSql = "SELECT 1";

  _maxWaitTime = 1000;
  _waitInterval = 200;
  _maxConnectionCount = 10;
}
T3DBConnectionPool::~T3DBConnectionPool()
{
  foreach (QString connectionName_, _usedConnectionNames)
  {
    QSqlDatabase::removeDatabase(connectionName_);
  }
  foreach (QString connectionName_, _unusedConnectionNames)
  {
    QSqlDatabase::removeDatabase(connectionName_);
  }
}
T3DBConnectionPool& T3DBConnectionPool::getInstance()
{
  if(NULL == _connectionPoolInstance)
  {
    QMutexLocker locker(&_mutex);
    if(NULL == _connectionPoolInstance)
    {
      _connectionPoolInstance = new T3DBConnectionPool();
    }
  }
  return *_connectionPoolInstance;
}

void T3DBConnectionPool::release()
{
  QMutexLocker locker(&_mutex);
  delete _connectionPoolInstance;
  _connectionPoolInstance = NULL;
}

QSqlDatabase T3DBConnectionPool::openConnection()
{
  T3DBConnectionPool& pool_ = T3DBConnectionPool::getInstance();
  QString connectionName_;
  QMutexLocker locker(&_mutex);

  //已经创建连接数
  int connectionCount_ = pool_._unusedConnectionNames.size() + pool_._usedConnectionNames.size();

  //如果连接已经用完,等待 waitInterval 毫秒查看连接是否可用,最长等待时间为 maxWaitTime 毫秒
  for(int i = 0;
      i < pool_._maxWaitTime && pool_._unusedConnectionNames.size() == 0 && connectionCount_ == pool_._maxConnectionCount;
      i += pool_._waitInterval)
  {
    _waitCondition.wait(&_mutex,pool_._waitInterval);

    //重新计算已经创建的连接数
    connectionCount_ = pool_._unusedConnectionNames.size() + pool_._usedConnectionNames.size();
  }

  if(pool_._unusedConnectionNames.size() > 0)
  {
    //有已经回收的连接,复用他们
    connectionName_ = pool_._unusedConnectionNames.dequeue();

  }else if (connectionCount_ < pool_._maxConnectionCount)
  {
    //没有已经回收的连接,但是没有达到最大连接数,则创建新的连接
    connectionName_ = QString("Connection-%1").arg(connectionCount_ + 1);
  }else {
    //已经达到最大连接数
    T3LOG << "cannot create more connections.";
    return QSqlDatabase();
  }

  //创建连接
  QSqlDatabase db_ = pool_.createConnection(connectionName_);

  //有效的连接才放入 usedConnectionName;
  if(db_.isOpen())
  {
    pool_._usedConnectionNames.enqueue(connectionName_);
  }
  return db_;

}

void T3DBConnectionPool::closeConnection(QSqlDatabase connection)
{
  T3DBConnectionPool& pool_ = T3DBConnectionPool::getInstance();
  QString connectionName_ = connection.connectionName();

  //如果是我们创建的连接,从used里删除,放入unsed里
  if(pool_._usedConnectionNames.contains(connectionName_))
  {
    QMutexLocker locker(&_mutex);
    pool_._usedConnectionNames.removeOne(connectionName_);
    pool_._unusedConnectionNames.enqueue(connectionName_);
    _waitCondition.wakeOne();
  }
}

QSqlDatabase T3DBConnectionPool::createConnection(const QString &connectionName)
{
  //连接已经创建了,复用他,而不是重新创建
  if(QSqlDatabase::contains(connectionName))
  {
    QSqlDatabase db1_ = QSqlDatabase::database(connectionName);
    if(_testOnBorrow)
    {
      //返回连接前访问数据库,如果连接断开,重新创建连接
      //T3LOG << "Text connection on borrow execute:" << _testonBorrowSql << ", for" << connectionName;
      QSqlQuery query_(_testonBorrowSql, db1_);
      if(query_.lastError().type() != QSqlError::NoError && !db1_.open())
      {
        T3LOG << "open database error :" << db1_.lastError().text();
        return QSqlDatabase();
      }
    }
    return db1_;
  }

  //创建一个新的连接
  QSqlDatabase db_ = QSqlDatabase::addDatabase(_databaseType,connectionName);
  db_.setHostName(_hostName);
  db_.setDatabaseName(_databaseName);
  db_.setUserName(_userName);
  db_.setPassword(_password);

  if(!db_.open())
  {
    T3LOG << "open database connection error :" << db_.lastError().text();
    return QSqlDatabase();
  }
  return db_;
}
}

