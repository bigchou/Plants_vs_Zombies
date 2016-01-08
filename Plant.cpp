
#include "Plant.h"


using namespace std;
int ReadFile(const string &filename, Plant* plants[]){
    ifstream ifile(filename);
    if(!ifile){
        return 0;
    }
    int num_of_plants = Read(ifile,plants);
    if(num_of_plants){
        ifile.close();
    }
    return num_of_plants;
}

int Read(ifstream& ifile, Plant* plants[]){
    char id = '\0';
    string str, name;
    int cost = 0, hp = 0, count = 0;

    while(ifile >> id){
        ifile >> name;
        getline(ifile,str,'$');
        ifile >> cost >> hp;
        Plant plant(id,name,cost,hp,hp);

        Plant *tmp = 0;
        switch(id){
            case 'C':

                tmp = new(nothrow) CoinPlant(ifile,plant);
                break;
            case 'S':

                tmp = new(nothrow) ShootPlant(ifile,plant);
                break;
            case 'H':
                tmp = new(nothrow) HealPlant(ifile,plant);
                break;
            case 'B':
                tmp = new(nothrow) BombPlant(ifile,plant);
                break;
        }
        if(tmp){
            plants[count] = tmp;
            ++count;
        }else{
            cout << "Memory Allocation Failure" << endl;
            for(int i=0;i<count;++i){
                delete plants[i];
            }
            ifile.close();
            return 0;
        }
    }
    return count;
}

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

int CoinPlant::max_visits_ = 0;
/*bool BombPlant::ReadFile(const string &filename){
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
}*/

