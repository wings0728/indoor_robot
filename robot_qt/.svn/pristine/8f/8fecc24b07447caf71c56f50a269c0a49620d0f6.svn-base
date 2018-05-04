#ifndef robot_qt_T3VOICE_H
#define robot_qt_T3VOICE_H
/**
  ******************************************************************************
  * @file
  * @author   孔志伟
  * @version  V1.0.0
  * @date    2018-04-16
  * @brief    语音合成接口
  ******************************************************************************
*/
//#include "../../base/T3BaseClass.hpp"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QList>
#include <QSoundEffect>
#include <QUrl>
#include <QTimer>

extern "C"
{
#include "msp_cmn.h"
#include "msp_errors.h"
#include "msp_types.h"
#include "qtts.h"
}

struct WavePcmHdr
{
    char            riff[4];                // = "RIFF"
    int				size_8;                 // = FileSize - 8
    char            wave[4];                // = "WAVE"
    char            fmt[4];                 // = "fmt "
    int				fmt_size;				// = 下一个结构体的大小 : 16

    short int       format_tag;             // = PCM : 1
    short int       channels;               // = 通道数 : 1
    int				samples_per_sec;        // = 采样率 : 8000 | 6000 | 11025 | 16000
    int				avg_bytes_per_sec;      // = 每秒字节数 : samples_per_sec * bits_per_sample / 8
    short int       block_align;            // = 每采样点字节数 : wBitsPerSample / 8
    short int       bits_per_sample;        // = 量化比特数: 8 | 16

    char            data[4];                // = "data";
    int				data_size;              // = 纯数据长度 : FileSize - 44
} ;

class T3Voice : public QObject
{
    Q_OBJECT
public:
    static T3Voice* getInstance();
    T3Voice();
    ~T3Voice();
    /**
     * @brief textToSpeech  将字符串转化为语音并播放
     * @param text          需要转化的字符串
     * @return              状态码
     */
    int textToSpeech(const char *srcText);
private:
    int initTTS();
    int textListToSpeech();
    int inputToText(QString role,int gender,QString name);
    void lowPower();
    int ret ;
    const char* _sessionBeginParams;
    QString _fileName;
    bool _isPlayVoice;
    QList<QString> _textList;
    int _textListIndex;
    QTimer *_playTimer;
    WavePcmHdr _defaultWavHdr ;

private slots:
    void playingChange();
    void stopPlay();
};
#endif
