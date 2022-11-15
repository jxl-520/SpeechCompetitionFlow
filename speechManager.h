#pragma once
#include <iostream>
#include <vector>
#include <map>
#include "speaker.h"
#include <string>

using namespace std;

//�ݽ�������
class SpeechManager{
public:
    //���캯��
    SpeechManager();

    //չʾ�˵�
    void show_Menu();

    //��ʼ������
    void initSpeech();

    //��ʼ���� - �������̿���
    void startSpeech();

    //��ǩ
    void speechDraw();

    //����
    void speechContest();

    //��ʾ�������
    void showScore();

    //�����¼
    void saveRecord();

    //��ռ�¼
    void clearRecord();

    //����ѡ��
    void createSpeaker();

    //�鿴��¼
    void loadRecord();

    //��ʾ����÷�
    void showRecord();

    //�˳�ϵͳ
    void exitSystem();

    //��������
    ~SpeechManager();

private:
    int m_Index;
    bool fileIsEmpty; //�ļ�Ϊ�յı�־
public:
    vector<int> &getV1();

    vector<int> &getV2();

    vector<int> &getVVictory();

    map<int, Speaker> &getMSpeaker();



private:
    vector<int> v1; //����ѡ�� 12��
    vector<int> v2; //��һ�ֽ�������  6��
    vector<int> vVictory; //ʤ��ǰ3������ 3��
    map<int,Speaker> m_Speaker; //��ű���Լ���Ӧ�ľ���ѡ������
    map<int, vector<string>> m_Record;//�����¼
};