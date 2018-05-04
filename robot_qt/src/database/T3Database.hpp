#ifndef robot_qt_T3DATABASE_HPP_
#define robot_qt_T3DATABASE_HPP_

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QUuid>
#include "../T3base/T3IOBase.hpp"
#include "T3DBConnectionPool.hpp"


/**
  ******************************************************************************
  * @file
  * @author     HXP
  * @version    V1.0.0
  * @date       2018/02/24
  * @brief      数据库相关操作
  ******************************************************************************
*/
namespace interface {

enum T3DatabaseIdenCode
{
    DatabaseNotOpen,
    DatabaseOpenSuccess
};
class T3Database : public T3IOBase
{
public:

    static T3Database* getInstance();
    ~T3Database();

private:
    static T3Database* _t3datebase;
    QSqlDatabase _database;
    explicit T3Database();

    /**
     * @brief connectDatabase 初始化连接数据库
     * @return
     */
    T3DatabaseIdenCode connectDatabase();


};
}

#endif
