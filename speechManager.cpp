
#include <algorithm>
#include <deque>
#include <numeric>
#include <fstream>
#include "speechManager.h"

SpeechManager::SpeechManager() {
    //��ʼ������
    this->initSpeech();

    //����ѡ��
    this->createSpeaker();

    //��ȡ�����¼
    this->loadRecord();
}

SpeechManager::~SpeechManager() {

}

void SpeechManager::show_Menu() {
    cout << "***********************************************"<<endl;
    cout << "*************  ��ӭ�μ��ݽ�����  *****************"<<endl;
    cout << "*************  1.��ʼ�ݽ�����   *****************"<<endl;
    cout << "*************  2.�鿴�����¼   *****************"<<endl;
    cout << "*************  3.��ձ�����¼   *****************"<<endl;
    cout << "*************  0.�˳���������   *****************"<<endl;
    cout << "***********************************************"<<endl;
    cout <<endl;
}

void SpeechManager::exitSystem() {
    cout<<"��ӭ�´�ʹ�ã�"<<endl;

    exit(0);
}

void SpeechManager::initSpeech() {
    //������֤Ϊ��
    this->v1.clear();
    this->v2.clear();
    this->vVictory.clear();
    this->m_Speaker.clear();

    //��ʼ����������
    this->m_Index = 1;
    //��ʼ����¼����
    this->m_Record.clear();
}

void SpeechManager::createSpeaker() {
    string nameSeed = "ABCDEFGHIJKL";
    for (int i = 0; i < nameSeed.size(); i++) {
        string name("ѡ��");
        name += nameSeed[i];

        Speaker sp;

        sp.setName(name);


        for (int j = 0; j < 2; ++j) {
            sp.score_[j] = 0;
        }

        //12��ѡ�ֱ��
        this->v1.push_back(i+10001);

        //ѡ�ֱ�ţ��Ͷ�Ӧ��ѡ�� ��ŵ�map������
        this->m_Speaker.insert(make_pair(i+10001,sp));
    }
}

vector<int> &SpeechManager::getV1() {
    return v1;
}

 vector<int> &SpeechManager::getV2()  {
    return v2;
}

 vector<int> &SpeechManager::getVVictory()  {
    return vVictory;
}

 map<int, Speaker> &SpeechManager::getMSpeaker()  {
    return m_Speaker;
}

void SpeechManager::startSpeech() {
    //��һ�ֱ���

    //1.��ǩ
    speechDraw();
    //2.����
    speechContest();
    //3.��ʾ�������
    showScore();
    //�ڶ��ֱ���
    this->m_Index++;
    //1.��ǩ
    speechDraw();
    //2.����
    speechContest();
    //3.��ʾ���ս��
    showScore();
    //4.�������
    saveRecord();

    //���ñ���
    this->initSpeech();
    this->createSpeaker();
    this->loadRecord();

    cout<<"���������ϣ�"<<endl;
    system("pause");
    system("cls");
}

void SpeechManager::speechDraw() {
    cout<<"��"<<this->m_Index<<"�ֱ���ѡ�����ڳ�ǩ"<<endl;
    cout<<"--------------------------------------"<<endl;
    cout<<"��ǩ���ݽ�˳�����£�"<<endl;
    if(this->m_Index == 1){
        random_shuffle(v1.begin(),v1.end());//����v1����ѡ�ֱ�ŵ�˳��
        for(vector<int>::iterator it = v1.begin();it != v1.end();it++){
            cout<<*it<<" ";
        }
        cout<<endl;
    }
    else{
        random_shuffle(v2.begin(),v2.end());//����v2����ѡ�ֱ�ŵ�˳��
        for(vector<int>::iterator it = v2.begin();it != v2.end();it++){
            cout<<*it<<" ";
        }
        cout<<endl;
    }
    cout<<"--------------------------------------"<<endl;
    system("pause");
    cout<<endl;

}

void SpeechManager::speechContest() {
    cout<<"��<<"<<this->m_Index<<">>����ʽ������ʼ��"<<endl;
    multimap<double,int,greater<int>> groupScore;//��ʱ����������key������value ѡ�ֱ�� ���ҷ����Ӵ�С

    int num = 0; //��¼��Ա����6��Ϊ1��

    vector<int> v_Src; //��������Ա����
    if(this->m_Index==1){
        v_Src = v1;
    }else
    {
        v_Src = v2;
    }

    //�������в���ѡ��
    for(vector<int>::iterator it = v_Src.begin();it!=v_Src.end();it++){
        num++;

        //��ί���
        deque<double> d;
        for(int i = 0;i<10;i++){
            double score = (rand()%401 + 600)/10.f;
            d.push_back(score);
        }
        sort(d.begin(),d.end(),greater<double>());  //����
        d.pop_front();//ȥ����߷�
        d.pop_back();//ȥ����ͷ�

        double sum = accumulate(d.begin(),d.end(),0.0f); //��ȡ�ܷ�
        double avg = sum/(double)d.size(); //ƽ����

        this->m_Speaker[*it].score_[this->m_Index-1] = avg;
//        cout<<"��ţ�"<<*it<<"������"<<this->m_Speaker[*it].getName()<<"ƽ���֣�"<<avg<<endl;
        groupScore.insert(make_pair(avg,*it));

        if(num % 6==0){
            cout<<"��"<<num/6<<"С���������"<<endl;
            for(multimap<double,int,greater<int>>::iterator it = groupScore.begin();it!=groupScore.end();it++){
                cout<<"��ţ�"<<it->second<<" ������"<<this->m_Speaker[it->second].getName()
                    <<" �ɼ���"<<this->m_Speaker[it->second].score_[this->m_Index-1]<<endl;
            }

            int count = 0;
            //ȡǰ����
            for(multimap<double,int,greater<int>>::iterator it=groupScore.begin();it!=groupScore.end()&&count<3;it++,count++){
                if(this->m_Index ==1 ){
                    v2.push_back((*it).second);
                } else{
                    vVictory.push_back((*it).second);
                }
            }
            groupScore.clear();
            cout<<endl;

        }

    }
    cout<<"��<<"<<this->m_Index<<">>����ʽ����������"<<endl;
    system("pause");
}

void SpeechManager::showScore() {
    cout<<"��"<<this->m_Index<<"�ֽ���ѡ����Ϣ���£�"<<endl;
    vector<int>v;
    if(this->m_Index==1){
        v=v2;
    }
    else{
        v=vVictory;
    }

    for(vector<int>::iterator it = v.begin();it!=v.end();it++){
        cout<<"ѡ�ֱ�ţ�"<<(*it)<<" ������"<<this->m_Speaker[*it].getName()
            <<" �÷֣�"<<this->m_Speaker[*it].score_[m_Index-1]<<endl;
    }
    cout<<endl;

    system("pause");
    system("cls");

}

void SpeechManager::saveRecord() {
    ofstream ofs;
    ofs.open("speech.csv",ios::out|ios::app);//������ķ�ʽ���ļ� --д�ļ�

    //��ÿ���˵�����д�뵽�ļ���
    for(vector<int>::iterator it = vVictory.begin();it!=vVictory.end();it++){
        ofs<<*it<<","
        <<m_Speaker[*it].getName()<<","
        <<m_Speaker[*it].score_[1]<<",";
    }
    ofs<<endl;
    ofs.close();

    cout<<"��¼�Ѿ�����"<<endl;

    //�м�¼�ˣ��ļ���Ϊ��
    this->fileIsEmpty = false;
}

void SpeechManager::loadRecord() {
    ifstream  ifs("speech.csv",ios::in);//���������� ��ȡ�ļ�

    if(!ifs.is_open()){
        this->fileIsEmpty = true;
        cout<<"�ļ�������"<<endl;
        ifs.close();
        return;
    }

    char ch;
    ifs>>ch;
    if(ifs.eof()){
        cout<<"�ļ�Ϊ�գ�"<<endl;
        this->fileIsEmpty = true;
        ifs.close();
        return;
    }
    this->fileIsEmpty = false;

    ifs.putback(ch);//��ȡ�ĵ����ַ��Ż�ȥ

    string data;
    int index = 0;
    while(ifs>>data){
        vector<string>v;

        int pos = -1;
        int start = 0;

        while(true){
            pos = data.find(",",start);
            if(pos==-1){
                break;
            }
            string tmp = data.substr(start,pos-start);
            v.push_back(tmp);
            start = pos+1;
        }
        this->m_Record.insert(make_pair(index,v));
        index++;

    }
    ifs.close();
}

void SpeechManager::showRecord() {

    if(this->fileIsEmpty){
        cout<<"�ļ������ڣ����¼Ϊ�գ�"<<endl;
    }
    for (int i = 0; i < this->m_Record.size(); i++)
    {
        cout << "��" << i + 1 << "�� " <<endl;
        cout<<"�ھ���ţ�" << this->m_Record[i][0] << " ������" << this->m_Record[i][1] << " �÷֣�"<<this->m_Record[i][2]<<endl;
        cout<<"�Ǿ���ţ�" << this->m_Record[i][3] << " ������" << this->m_Record[i][4] << " �÷֣�"<<this->m_Record[i][5]<<endl;
        cout<<"������ţ�" << this->m_Record[i][6] << " ������" << this->m_Record[i][7] << " �÷֣�"<<this->m_Record[i][8]<<endl<<endl;
    }
    system("pause");
    system("cls");

}

void SpeechManager::clearRecord() {
    cout<<"ȷ����գ�"<<endl;
    cout<<"1.ȷ��"<<endl;
    cout<<"2.����"<<endl;

    int select = 0;
    cin>>select;
    if(select==1){
        ofstream  ofs("speech.csv",ios::trunc);
        ofs.close();

        //��ʼ������
        this->initSpeech();
        //����ѡ��
        this->createSpeaker();
        //��ȡ�����¼
        this->loadRecord();

        cout << "��ճɹ���" << endl;

    }
    system("pause");
    system("cls");
}
