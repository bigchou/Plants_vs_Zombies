#ifndef ZOMBIE__
#define ZOMBIE__
class Zombie
{
public:
    Zombie():index_(0),hp_(40) {};
    void BeAttacked(int ap) {hp_-=ap;}

    int Step();
    void Init(int landNum);

    int HP() {return hp_;}
    int Index() {return index_;}
    int Position() {return position_;}

    static int Damage() { return damage_; }

private:
    static const int damage_ = 15;
    int index_;
    int hp_;
    int position_;
};

#endif // ZOMBIE__
