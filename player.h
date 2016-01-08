#ifndef PLAYER__
#define PLAYER__
#include "Plant.h"
class Player
{
public:
    Player():dollar_(150){};
    Player(int dollar):dollar_(dollar){};

    void BuyPlant(int price) { dollar_-=price; }
    void AddDollar(int price) { dollar_+= price; }
    int Dollar() { return dollar_; }

//    void Init(int landNum);
//    int Step();
//    int Position() const { return position_; }
//
//    void plant_readfile();
//    Plant *get_plant(int i) const { return plants_[i]; }
//
//    int get_default_choose() const {return default_choose_; }
//    void change_default_choose(int i) {default_choose_ = i; }

private:
    int dollar_;
//    int position_;
//    int default_choose_ = 4;
//    Plant *plants_[4] = {new CoinPlant, new ShootPlant, new BombPlant, new HealPlant};
};
#endif // PLAYER__
