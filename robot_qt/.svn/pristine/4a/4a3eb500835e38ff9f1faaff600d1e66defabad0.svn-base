#ifndef T3DBCONNECTIONPOOL_HPP
#define T3DBCONNECTIONPOOL_HPP
/**
  ******************************************************************************
  * 公司    T3
  * 文件名  T3DBConnectionPool.hpp
  * 作者    HXP
  * 版本    V1.0.0
  * 日期    2018.05.02
  * 说明    数据库连接池
  ******************************************************************************
*/
#include <QtSql>
#include <QQueue>
#include <QString>
#include <QMutex>
#include <QMutexLocker>

#include "../config/config.hpp"

namespace interface
{
class T3DBConnectionPool
{
public:
  /**
   * @brief release 关闭所有数据库连接
   */
  static void release();

  /**
   * @brief openConnection 获取数据库连接
   * @return               数据库连接
   */
  static QSqlDatabase openConnection();

  /**
   * @brief closeConnection 释放数据库连接回数据池
   * @param connection      需要释放的数据库连接
   */
  static void closeConnection(QSqlDatabase connection);

  ~T3DBConnectionPool();

private:
  static T3DBConnectionPool& getInstance();
  static T3DBConnectionPool* _connectionPoolInstance;

  T3DBConnectionPool();
  T3DBConnectionPool(const T3DBConnectionPool &other);
  T3DBConnectionPool& operator =(const T3DBConnectionPool &other);
  /**
   * @brief createConnection 创建数据库连接
   * @param connectionName   连接名
   * @return
   */
  QSqlDatabase createConnection(const QString &connectionName);

  QQueue<QString> _usedConnectionNames; // 已经使用的数据库连接名
  QQueue<QString> _unusedConnectionNames;


  //数据库信息
  QString _hostName;
  QString _databaseName;
  QString _userName;
  QString _password;
  QString _databaseType;

  bool _testOnBorrow;  //取得连接的时候验证连接是否有效
  QString _testonBorrowSql; //测试访问数据库的SQL

  int _maxWaitTime; //获取连接最大等待时间
  int _waitInterval; //尝试获取连接时等待间隔时间
  int _maxConnectionCount; //最大连接数

  static QMutex _mutex;
  static QWaitCondition _waitCondition;

};
}


#endif // T3DBCONNECTIONPOOL_HPP
