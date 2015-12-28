
#include "Plant.h"
#include <fstream>
using namespace std;
void Plant::Healed(int heal_point){
    hp_+=heal_point;
    if(hp_ > max_hp_)
        hp_ = max_hp_;
}
void Plant::Suffer(int damage_point){
    hp_ -= damage_point;
    if(hp_ < 0)
        hp_ = 0;
}
bool BombPlant::ReadFile(const string &filename){
    ifstream ifile(filename);
    if(!ifile){
        return false;
    }
    string str;
    while(ifile){
        ifile >> str;
        if(str == "B"){
            id_ = str[0];
            ifile >> name_;
            getline(ifile,str,'$');
            ifile >> cost_ >> hp_;
            max_hp_ = hp_;
            //cout << id_ << ' ' << name_ << ' ' <<  cost_ << ' ' <<  hp_ << endl;
            break;
        }
    }
    ifile.close();
    return true;
}
bool HealPlant::ReadFile(const string &filename){
    ifstream ifile(filename);
    if(!ifile){
        return false;
    }
    string str;
    while(ifile){
        ifile >> str;
        if(str == "H"){
            id_ = str[0];
            ifile >> name_;
            getline(ifile,str,'$');
            ifile >> cost_ >> hp_ >> heal_point_;
            max_hp_ = hp_;
            //cout << id_ << ' ' << name_ << ' ' <<  cost_ << ' ' <<  hp_ << ' ' << heal_point_ << endl;
            break;
        }
    }
    ifile.close();
    return true;
}
int CoinPlant::max_visits_ = 0;
bool CoinPlant::ReadFile(const string &filename){
    ifstream ifile(filename);
    if(!ifile){
        return false;
    }
    string str;
    while(ifile){
        ifile >> str;
        if(str == "C"){
            id_ = str[0];
            ifile >> name_;
            getline(ifile,str,'$');
            ifile >> cost_ >> hp_ >> round_ >> earn_;
            max_hp_ = hp_;
            Set_MaxVisits(round_);
            //cout << id_ << ' ' << name_ << ' ' <<  cost_ << ' ' <<  hp_ << ' ' << round_ << ' ' << earn_ << endl;
            break;
        }
    }
    ifile.close();
    return true;
}
bool ShootPlant::ReadFile(const string &filename){
    ifstream ifile(filename);
    if(!ifile){
        return false;
    }
    string str;
    while(ifile){
        ifile >> str;
        if(str == "S"){
            id_ = str[0];
            ifile >> name_;
            getline(ifile,str,'$');
            ifile >> cost_ >> hp_ >> damage_;
            max_hp_ = hp_;
            //cout << id_ << ' ' << name_ << ' ' <<  cost_ << ' ' <<  hp_ << ' ' << damage_ << endl;
            break;
        }
    }
    ifile.close();
    return true;
}
