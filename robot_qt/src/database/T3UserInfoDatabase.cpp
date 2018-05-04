#include "T3UserInfoDatabase.h"


namespace interface {


T3UserInfoDatabase::T3UserInfoDatabase()
{

}

void T3UserInfoDatabase::loadFaceDatabase(QList<model::T3UserInfo> &userInfoList)
{
  QSqlDatabase db_ = T3DBConnectionPool::openConnection();
  QSqlQuery query_(db_);
  query_.exec("select * from T3UserInfo");
  while (query_.next())
  {
      int id_ = query_.value(0).toInt();
      QString name_ = query_.value(1).toString();
      QString pwd_ = query_.value(2).toString();
      int gender_ = query_.value(3).toInt();
      int age_ = query_.value(4).toInt();
      QString ip_ = query_.value(5).toString();
      QByteArray feature_ = query_.value(6).toByteArray();
      int type_ = query_.value(7).toInt();
      int positionId_ = query_.value(8).toInt();
      T3DBConnectionPool::closeConnection(db_);
      T3PositionModel position_;
      _positionDB.getPositionById(positionId_,
                                  position_);

      model::T3UserInfo userInfo_ ;
      userInfo_.setID(id_);
      userInfo_.setName(name_);
      userInfo_.setPwd(pwd_);
      userInfo_.setGender((model::eUserGender)gender_);
      userInfo_.setAge(age_);
      userInfo_.setIP(ip_);
      userInfo_.setFeature(feature_);
      userInfo_.setType((model::eUserType) type_);
      userInfo_.setPosition(position_);
      userInfoList.append(userInfo_);

  }
}
int T3UserInfoDatabase::addNewFaceInfo(model::T3UserInfo &userInfo)
{
    QString name_ = userInfo.getName();
    QString pwd_ = userInfo.getPwd();
    int gender_ = static_cast<int>(userInfo.getGender());
    int age_ = userInfo.getAge();
    QString ip_ = userInfo.getIP();
    QByteArray feature_ = userInfo.getFeature();
    int type_ = static_cast<int>(userInfo.getType());
    int positionId_ = _positionDB.addNewPosition(userInfo.getPosition());
    QSqlDatabase db_ = T3DBConnectionPool::openConnection();
    QSqlQuery query_(db_);
    query_.prepare("insert into T3UserInfo values(NULL,?,?,?,?,?,?,?,?)");
    query_.bindValue(0,name_);
    query_.bindValue(1,pwd_);
    query_.bindValue(2,gender_);
    query_.bindValue(3,age_);
    query_.bindValue(4,ip_);
    query_.bindValue(5,feature_,QSql::Binary);
    query_.bindValue(6,type_);
    query_.bindValue(7,positionId_);
    int ret_ = query_.exec();
    if(ret_)
    {

      query_.exec("select max(id) from T3UserInfo");
      query_.next();
      int ret_ = query_.value(0).toInt();
      T3DBConnectionPool::closeConnection(db_);
      return ret_;

    }else
    {
      T3LOG << "insert userInfo failed";
      return -1;
    }


}

int T3UserInfoDatabase::getUserInfoById(int id,
                                         model::T3UserInfo &userInfo)
{
  QSqlDatabase db_ = T3DBConnectionPool::openConnection();
  QSqlQuery query_(db_);
  query_.prepare("select * from T3Robot.T3UserInfo where id = ?");
  query_.bindValue(0,id);
  bool ret_ = query_.exec();
  if(!ret_)
  {
    T3LOG << "search userInfo failed";
    return -1;
  }
  query_.next();

  QString name_ = query_.value(1).toString();
  QString pwd_ = query_.value(2).toString();
  int gender_ = query_.value(3).toInt();
  int age_ = query_.value(4).toInt();
  QString ip_ = query_.value(5).toString();
  QByteArray feature_ = query_.value(6).toByteArray();
  int type_ = query_.value(7).toInt();
  int positionId_ = query_.value(8).toInt();
  T3DBConnectionPool::closeConnection(db_);
  T3PositionModel position_;
  _positionDB.getPositionById(positionId_,
                              position_);


  userInfo.setID(id);
  userInfo.setName(name_);
  userInfo.setPwd(pwd_);
  userInfo.setGender((model::eUserGender)gender_);
  userInfo.setAge(age_);
  userInfo.setIP(ip_);
  userInfo.setFeature(feature_);
  userInfo.setType((model::eUserType) type_);
  userInfo.setPosition(position_);


  return 0;
}

int T3UserInfoDatabase::insertRobotSelf()
{

  model::T3UserInfo robot_;

  robot_.setAge(0);
  robot_.setGender(model::eMale);
  robot_.setName("");
  robot_.setType(model::eSelf);
  int robotId_ = addNewFaceInfo(robot_);
  return robotId_;

}
int T3UserInfoDatabase::getRobotSelf(model::T3UserInfo &robotSelf)
{
  QSqlDatabase db_ = T3DBConnectionPool::openConnection();
  QSqlQuery query_(db_);
  //query_.prepare("select * from T3Robot.T3UserInfo where id = 1");
  //query_.bindValue(0,static_cast<int>(model::eSelf));
  bool ret_ = query_.exec("select * from T3Robot.T3UserInfo where Id = 1");
  if(!ret_)
  {
    T3LOG << "search userInfo failed";
    return -1;
  }
  query_.next();
  int id_ = query_.value(0).toInt();
  QString name_ = query_.value(1).toString();
  int type_ = query_.value(7).toInt();
  T3DBConnectionPool::closeConnection(db_);
  robotSelf.setName(name_);
  robotSelf.setType(static_cast<model::eUserType>(type_));
  robotSelf.setID(id_);
}

T3UserInfoDatabase::~T3UserInfoDatabase()
{

}
}
