#ifndef Plant_HHH
#define Plant_HHH
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "zombie.h"
#include "player.h"

static const std::string filename("plants.txt");

class Plant{
public:
    Plant(int id = '\0',std::string name = "unnamed", int cost = 0, int hp = 0, int max_hp = 0):id_(id),name_(name),cost_(cost),hp_(hp),max_hp_(max_hp){}
    virtual ~Plant(){}
    virtual void Interact(Player &player){};
    virtual void Interact(Zombie &zombie)const{};
    virtual int GetHealPt()const{return 0;};
    virtual void Display()const{
        std::cout << name_ << " $" << cost_ << " HP: " << hp_ <<" - gives ";
    }
    virtual void ShowStatus()const{
        std::cout << name_ << ' ' << "HP: " << hp_ << ' ';
    }
    void Healed(int heal_point);
    void Suffer(int damage_point);
    char Id()const{return id_;}
    const std::string &Name()const{ return name_;}
    int Cost()const{return cost_;}
    int Hp()const{return hp_;}
    int Max_Hp()const{return max_hp_;}
protected:
    char id_ = '\0';
    std::string name_ = "unnamed";
    int cost_ = 0;
    int hp_ = 0;
    int max_hp_ = 0;
private:
};
inline std::ostream& operator << (std::ostream& os, const Plant *plant){//by pointer
    plant->Display();
    return os;
}






class BombPlant : public Plant{
public:
    BombPlant():Plant(){}
    BombPlant(std::ifstream& ifile, Plant plant):Plant(plant.Id(),plant.Name(),plant.Cost(),plant.Hp(),plant.Hp()){}
    virtual void Display()const override{
        Plant::Display();
        std::cout << hp_ << " damage points";
    }
    virtual void Interact(Zombie &zombie)const override{
        zombie.BeAttacked(Max_Hp());
    };
private:
};








class HealPlant : public Plant{
public:
    HealPlant(int heal_point = 0):Plant(),heal_point_(heal_point){}
    HealPlant(std::ifstream& ifile, Plant plant):Plant(plant.Id(),plant.Name(),plant.Cost(),plant.Hp(),plant.Hp()){
        ifile >>  heal_point_;
    }
    virtual void Display()const override{
        Plant::Display();
        std::cout << "gives all your plants " << heal_point_ << " HP back.";
    }
    virtual int GetHealPt()const override{
        return Heal_Point_();
    };
    int Heal_Point_()const{return heal_point_;}
private:
    int heal_point_ = 0;
};






class CoinPlant : public Plant{
public:
    CoinPlant(int round = 0,int earn = 0):Plant(),round_(round),earn_(earn){}
    CoinPlant(std::ifstream& ifile, Plant plant):Plant(plant.Id(),plant.Name(),plant.Cost(),plant.Hp(),plant.Hp()){
        ifile >> round_ >> earn_;
        Set_MaxVisits(round_);
    }
    virtual void Display()const override{
        Plant::Display();
        std::cout << "gives $" << earn_ << " every " << round_ << " rounds";
    }
    virtual void ShowStatus()const{
        Plant::ShowStatus();
        std::cout << '(' << round_ << " more visit" <<  (  round_ > 1 ? "s)" : ")" );
    }
    virtual void Interact(Player &player)override{
        round_--;
        if(round_ <= 0){
            player.AddDollar(earn_);
            round_ = max_visits_;
        }
    };
    void Decre_Round(){round_--;}
    int Round()const{return round_;}
    int Earn()const{return earn_;}
    int Max_Visits()const{return max_visits_;}
private:
    int round_ = 0;
    int earn_ = 0;
    static int max_visits_;
    static void Set_MaxVisits(int max_visits){max_visits_ = max_visits;}
};



class ShootPlant : public Plant{
public:
    ShootPlant(int damage = 0):Plant(),damage_(damage){}
    ShootPlant(std::ifstream& ifile, Plant plant):Plant(plant.Id(),plant.Name(),plant.Cost(),plant.Hp(),plant.Hp()){
        ifile >> damage_;
    }
    virtual void Display()const override{
        Plant::Display();
        std::cout << "gives " << damage_ << " damage points";
    }
    virtual void Interact(Zombie &zombie)const override{
        zombie.BeAttacked(damage_);
    };
    int Damage()const{return damage_;}
private:
    int damage_ = 0;
};

int Read(const std::string filename, std::vector<Plant*>& plant);

#endif // Plant_HHH
