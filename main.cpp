#include <iostream>
#include <string>
#include "speechManager.h"

using namespace std;


int main() {
    srand((unsigned int)time(NULL));
    SpeechManager sm;

    int choice = 0; //�����洢�û���ѡ��

//    for(map<int,Speaker>::iterator it = sm.getMSpeaker().begin();it!=sm.getMSpeaker().end();it++){
//        cout<<"ѡ�ֱ�ţ�"<<it->first
//            <<" ������"<<it->second.getName()
//            <<" �ɼ���"<<it->second.score_[0]<<endl;
//    }

    while(true){
        sm.show_Menu();

        cout<<"����������ѡ��"<<endl;
        cin>>choice;

        switch (choice) {
            case 1://��ʼ����
            sm.startSpeech();
                break;
            case 2://�鿴��¼
            sm.showRecord();
                break;
            case 3://��ռ�¼
            sm.clearRecord();
                break;
            case 0://�˳�ϵͳ
                sm.exitSystem();
                break;
            default:
                system("cls");//����
                break;
        }
    }

    return 0;
}