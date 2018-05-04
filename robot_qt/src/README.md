# rosgui
## ros接口 v1.0
> 主要方法：
- public:

> `static QNode * getInstance();`
*获取单例对象*

> `bool init(int argc, char** argv);`
*初始化*

> `std::vector<double> getRobotPose();`
*返回值表示机器人相对于开机位置的坐标，其中包含4个变量，分别对应x,y,z,w, Z和W能组成机器人角度*

> `std::vector<double> getMapOrigin();`
*返回值表示地图原点相对于坐标系原点的偏移，其中包含3个变量，分别对应x,y,z, Z为机器人朝向（初始为0）*

- 信号:

> `void rosShutdown();`
*ros系统关闭*
    
> `void poseUpdated();`
*坐标点更新*

> `void lowPower();`
*低电量*

> `void isAbortedSignal(bool a);`
*机器人是否陷入危险区域*


### 初始化：
- 包含qnode.hpp
- 创建一个单例对象：rosgui::QNode *qnode = rosgui::QNode::getInstance();
- 第一次创建单例时，需要调用init函数并传入argc、argv，所以一般在main中第一次创建**qnode->init(argc, argv)**;
- 第一次创建之后，其余类再创建时，可以直接使用**rosgui::QNode *qnode = rosgui::QNode::getInstance()**获取对象;
- 当有数据更新时，会有**signals：poseUpdated()**, 坐标点数组为**std::vector<double> _robotPose**;当信号被触发时，可以写一个槽来调用_robotPose，查看最新坐标点。
- 当ros被关闭时，会有**signals：rosShutdown()**，可以写对应的槽函数来做相应处理。
> example:
- 初始化(第一次调用)
```cpp
    rosgui::QNode *qnode = rosgui::QNode::getInstance();
    qnode->init(argc, argv);
```
- hpp
```cpp
namespace Ui {
class T3_AF_welcome;
}

class T3_AF_welcome : public QDialog
{
    Q_OBJECT

public:
    explicit T3_AF_welcome(int argc, char** argv, QWidget *parent = 0);


private slots:
//--------------jason code
    void rosUpdate();
//--------------jason end
private:
    Ui::T3_AF_welcome *ui;
    rosgui::QNode *qnode;
};
```
- cpp
```cpp
T3_AF_welcome::T3_AF_welcome(int argc, char** argv, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::T3_AF_welcome),
    qnode(argc,argv)
{
...
    //----------jason code
    qnode = rosgui::QNode::getInstance();
    QObject::connect(qnode, SIGNAL(rosShutdown()), this, SLOT(close()));
    QObject::connect(qnode, SIGNAL(poseUpdated()), this, SLOT(rosUpdate()));
    //----------jason end
...
}

void T3_AF_welcome::rosUpdate()
{
  T3LOG("%f %f %f",qnode->_robotPose[0], qnode->_robotPose[1], qnode->_robotPose[2]);
}
```

### 手动&自动切换

> 读取现在的模式,返回值为OprationMode类型。
```cpp
OprationMode getOprationMode();
```

> 设置手动或自动，传入Auto或者Manual即可。
```cpp
  enum OprationMode {
           Auto,
           Manual
   };

void setOperationMode(OprationMode operation);
```

> 设置手动方向（确保目前在手动模式）。
```cpp
  enum ManualCmd {
           Forward,
           Backward,
           LeftTurn,
           RightTurn,
           Stop
   };

bool setManualCmd(ManualCmd cmd);
```

> 设置自动行走要去的目标位置（确保目前在自动模式）。
```cpp
void goalUpdate(float x, float y, float z);
```

### 获取机器人当前线速度与角速度
> 传入两个double类型的**指针**即可。
```cpp
void getRobotSpeed(double* linearX, double* anglarZ);
```

### 电池电量
> 返回值为电量百分比。
```cpp
int getBatt();
```

### 低电量
> 当电池电量低时，会发送信号`lowPower()`，同时可以调用函数`bool isLowPower()`来判断现在是否电量过低。
```cpp
Q_SINGAL
	void lowPower();

bool isLowPower();
```

### 将要碰撞状态读取
```cpp
Q_SINGAL
	void isAbortedSignal(bool a);

bool isAborted();
```

### 关闭ros
> 当退出程序时，需要调用此函数来关闭ros。
```cpp
void shutDownRos();
```


