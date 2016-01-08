
#include "Plant.h"


using namespace std;


int Read(const string filename, vector<Plant*>& plants){
    ifstream ifile(filename);
    if(!ifile){
        cout << filename << "is not found!" << endl;
        return 0;
    }

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
            plants.push_back(tmp);
            ++count;
        }else{
            cout << "Memory Allocation Failure" << endl;
            // Free Memory
            for (std::vector<Plant*>::iterator it = plants.begin() ; it != plants.end(); ++it){
                delete (*it);
            }
            plants.clear();
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
