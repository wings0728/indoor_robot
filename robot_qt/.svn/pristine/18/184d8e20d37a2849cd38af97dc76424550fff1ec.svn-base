#include "T3Tool.hpp"
#include "md5_encoder.hpp"
namespace interface {
T3Tool::T3Tool(){}

T3Tool::~T3Tool(){}

QString T3Tool::md5(QString str)
{
  Md5Encode encode_obj;
  std::string ret = encode_obj.Encode(str.toStdString());
  QString qstr(ret.c_str());
  return qstr;
}

}
