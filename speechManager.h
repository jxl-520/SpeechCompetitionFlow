#pragma once
#include <iostream>
#include <vector>
#include <map>
#include "speaker.h"
#include <string>

using namespace std;

//演讲管理类
class SpeechManager{
public:
    //构造函数
    SpeechManager();

    //展示菜单
    void show_Menu();

    //初始化比赛
    void initSpeech();

    //开始比赛 - 比赛流程控制
    void startSpeech();

    //抽签
    void speechDraw();

    //比赛
    void speechContest();

    //显示比赛结果
    void showScore();

    //保存记录
    void saveRecord();

    //清空记录
    void clearRecord();

    //创建选手
    void createSpeaker();

    //查看记录
    void loadRecord();

    //显示往届得分
    void showRecord();

    //退出系统
    void exitSystem();

    //析构函数
    ~SpeechManager();

private:
    int m_Index;
    bool fileIsEmpty; //文件为空的标志
public:
    vector<int> &getV1();

    vector<int> &getV2();

    vector<int> &getVVictory();

    map<int, Speaker> &getMSpeaker();



private:
    vector<int> v1; //比赛选手 12人
    vector<int> v2; //第一轮晋级容器  6人
    vector<int> vVictory; //胜利前3名容器 3人
    map<int,Speaker> m_Speaker; //存放编号以及对应的具体选手容器
    map<int, vector<string>> m_Record;//往届记录
};