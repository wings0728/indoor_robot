#include "T3Wifi.hpp"
#include "../config/config.hpp"
#include <QStringList>

//待定
#define kUpBtnPath "0"
#define kDownBtnPath "0"

#define kUpBtn_W 0
#define kUpBtn_H 0
#define kUpBtn_X 0
#define kUpBtn_Y 0

#define kDownBtn_W 0
#define kDownBtn_H 0
#define kDownBtn_X 0
#define kDownBtn_Y 0

T3Wifi::T3Wifi():
  T3UserController(kMainBackground)
{
    _index = 0;
    init();
    searchWifi();
}


void T3Wifi::searchWifi()
{
  //QString search_ = "nmcli d wifi list|awk '{if(NR!=1) print $1}'";
  //QString search_ = "nmcli d wifi list |awk '{if(NR!=1) print $1}'";
  //QString search_ = (QString)"nmcli d wifi list |awk '{if(NR!=1) print $1"+","+"$6"+","+"$8 }'";
  _process = new QProcess();
  _process->start("/home/kzw/search");
  connect(_process,SIGNAL(readyRead()),this,SLOT(readOut()));
}

void T3Wifi::readOut()
{
  QString out_;
  out_ += _process->readAll();

  disconnect(_process,SIGNAL(readyRead()),this,SLOT(readOut()));
  _process->kill();
  _wifiList = out_.split("\n");
  _wifiList.removeDuplicates();
  _wifiList.removeAll("");
  _wifiList.removeAll("*");
  _wifiList.removeAll("--");
//  for(int i=0;i<_wifiList.count();i++)
//  {qDebug()<<_wifiList.at(i);}

  saveWifiList();
  setWifiButton();
}


void T3Wifi::init()
{
  _wifiBox = new T3View::T3Label(this->_window,
                                 kWifiBox_X,
                                 kWifiBox_Y,
                                 kWifiBox_W,
                                 kWifiBox_H,
                                 kWifiBoxPath);
}

void T3Wifi::saveWifiList()
{
  _length = _wifiList.count();

  for(int i=0;i<_length;i++)
      {
        _wifi[i] = _wifiList.at(i);
        QStringList singleWifi_= _wifi[i].split(" ");
        qDebug()<<singleWifi_;
        _wifiSSID[i] = singleWifi_.at(0);
        QString valueStr_ = singleWifi_.at(1);
        int value_ = valueStr_.toInt();
        _signalValue[i] = 0;
        if(value_>0 &&value_<=30)
        {
          _signalValue[i] =1;
        }else if(value_>30 &&value_<=70)
          {
            _signalValue[i] =2;
          }else if(value_>70)
            {
              _signalValue[i] =3;
            }

        QString encryptStyle = singleWifi_.at(2);
        encryptStyle.toUpper();
        _encryptStatus[i] = false;
        if(encryptStyle.indexOf("WPA")){
          _encryptStatus[i] = true;
        }
    }

  if(5<_length)
  {
    _upBtn = new T3View::T3Button(this->_window,
                                  600,
                                  50,
                                  50,
                                  50,
                                  "/home/kzw/桌面/123.png",
                                  kMainBackground);
    _downBtn = new T3View::T3Button(this->_window,
                                    700,
                                    50,
                                    50,
                                    50,
                                    "/home/kzw/桌面/123.png",
                                    kMainBackground);

    _upBtn->show();
    _downBtn->show();

    connect(_upBtn,SIGNAL(clicked()),this,SLOT(clickUpBtn()));
    connect(_downBtn,SIGNAL(clicked()),this,SLOT(clickDownBtn()));

  }
}

void T3Wifi::setWifiButton()
{
  //qDebug()<<_index;
  int n = _length;
  if(5<_length)
  {
    n = 5+_index;
  }

  for(int i=_index;i<n;i++)
  {
    _wifiButton[i] = new T3View::T3WifiButton(this->_window,
                                             i-_index,
                                             kMainBackground,
                                             "/home/kzw/桌面/123.png",
                                             _wifiSSID[i],
                                             _encryptStatus[i],
                                             _signalValue[i]);
    _wifiButton[i]->show();
    connect(_wifiButton[i],SIGNAL(clicked()),this,SLOT(connectWifi()));
  }

}

void T3Wifi::clickUpBtn()
{
  qDebug()<<_index;
  if(_index>0)
  {
   _index = _index-1;
   setWifiButton();
  }
}

void T3Wifi::clickDownBtn()
{
  qDebug()<<_index;
  if(_index<(_length-5))
  {
   _index = _index+1;
   setWifiButton();
  }
}

void T3Wifi::connectWifi()
{
  T3View::T3WifiButton *wifiButton_ = dynamic_cast<T3View::T3WifiButton *>(sender());

  QString SSID_ = wifiButton_->_wifiSSID->text();

  //QString pwd_ = inputPassword();
  QString pwd_ = "T3keji66";

  _process = new QProcess();
  QString con_ = "nmcli d wifi connect "+SSID_+" password "+pwd_;
  _process->start(con_);
  //
  connect(_process,SIGNAL(readyRead()),this,SLOT(connecting()));
  qDebug()<<"connectWifi";;
}

void T3Wifi::connecting()//check password
{

  _process->kill();
  disconnect(_process,SIGNAL(readyRead()),this,SLOT(connecting()));
  //QString status_ = (QString)"nmcli device status|awk '$1=="+"\""+"wlp5s0"+"\""+"{print $3}'";
  //QString status_ = "nmcli device status";
  QString status_ = "iwconfig wlp5s0";
  _process = new QProcess();
  //_process->start("/home/kzw/status");
  _process->start(status_);
  connect(_process,SIGNAL(readyRead()),this,SLOT(connectStatus()));

  qDebug()<<"connecting";
}
void T3Wifi::connectStatus()//connect status()
{
  QString res_;
  res_ += _process->readAll();
  qDebug()<<res_;
  bool contans_ = res_.contains("ESSID:off/any");
  //QStringList resList_ = res_.split("\n");
  if(!contans_)
  {
    qDebug()<<"true";//连接成功。

  }else{
    qDebug()<<"false";//连接失败。

  }
}

QString T3Wifi::inputPassword()
{

}
