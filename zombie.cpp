#include"zombie.h"
#include<stdlib.h>
#include<time.h>
int Zombie::Step()
{
    return rand()%3+1;
}
void Zombie::Init(int landNum)
{
    position_=rand()%landNum;
}
