#include <iostream>
#include <cstdlib>
#include "Plant.h"
#include "player.h"
#include "zombie.h"
using namespace std;

int main(){
    // Initialize
    vector<Plant*> plants;
    // ReadFile
    int num = Read(filename,plants);//the subroutine will return the number of plants.
    if(!num) return 0;//if number of plants is 0, the program should exit!
    // Display
    cout << "DisplayAll" << endl;
    for(int i=0;i<num;++i)
        cout << "[" << i << "]" << plants[i] <<endl;//optional: plants[i]->Display();
    cout << "Show_Status" << endl;
    for(int i=0;i<num;++i){
        plants[i]->ShowStatus();
        cout << endl;
    }
    cout << endl;










    Zombie zombie;
    Player player;
    // Being attacked
    cout << "After being attacked by enemy and the attack of enemy is " << zombie.Damage() << endl;
    for(int i=0;i<num;++i){
        plants[i]->Suffer(zombie.Damage());
        cout << "[" << i << "]" << plants[i] << endl;//optional: plants[i]->Display();
    }
    // Being healed
    cout << "After being healed (notice that HP cannot be greater than MAX_HP)" << endl;
    for(int i=0;i<num;++i){
        if(plants[i]->Id() == 'H'){
            int recover = plants[i]->GetHealPt();
            for(int j=0;j<num;++j){
                plants[j]->Healed(recover);
            }
            break;
        }
    }
    for(int i=0;i<num;++i)
        cout << "[" << i << "]" << plants[i] << endl;//optional: plants[i]->Display();
    cout << endl;










    // Visit the land with CoinPlant
    cout << "Visit the land with CoinPlant" << endl;
    cout << "I have " << player.Dollar() << " now" << endl;
    cout << "Before: " << endl;
    for(int i=0;i<num;++i){
        if(plants[i]->Id() == 'C'){
            plants[i]->ShowStatus();
            cout << endl;
        }
    }
    cout << "Visit the land!" << endl;
    cout << "After: " << endl;
    for(int i=0;i<num;++i){
        if(plants[i]->Id() == 'C'){
            plants[i]->Interact(player);
            plants[i]->ShowStatus();
            cout << endl;
        }
    }
    cout << "Visit the land again!" << endl;
    for(int i=0;i<num;++i){
        if(plants[i]->Id() == 'C'){
            plants[i]->Interact(player);
            plants[i]->ShowStatus();
            cout << endl;
        }
    }
    cout << "Yeah! I get " << player.Dollar() << endl;
    cout << endl;













    // HornPlant attacks enemy
    cout << "HornPlant attacks enemy" << endl;
    cout << "Before: zombie_hp : " << zombie.HP() << endl;
    for(int i=0;i<num;++i){
        if(plants[i]->Id() == 'S')plants[i]->Interact(zombie);
    }
    cout << "After: zombie_hp : " << zombie.HP() << endl;
    cout << endl;












    // BombPlant attacks enemy
    cout << "BombPlant attacks enemy" << endl;
    cout << "Before: zombie_hp : " << zombie.HP() << endl;
    for(int i=0;i<num;++i){
        if(plants[i]->Id() == 'B')plants[i]->Interact(zombie);
    }
    cout << "After: zombie_hp : " << zombie.HP() << endl;
    cout << endl;















    // Deallocating Memory is highly necessary!
    cout << "Remember to deallocate memory" << endl << endl;
    for (std::vector<Plant*>::iterator it = plants.begin() ; it != plants.end(); ++it){
        delete (*it);
    }
    plants.clear();
    system("pause");
    return 0;
}
