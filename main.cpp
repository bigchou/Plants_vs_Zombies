#include <iostream>
#include "Plant.h"
using namespace std;

int main(){
    // Initialize
    cout << "=== Initialize ===" << endl << endl;
    Plant *plants[num_of_plants] = {new BombPlant, new HealPlant, new CoinPlant, new ShootPlant};
    // Read_File
    cout << "=== Read ===" << endl << endl;
    for(int i=0;i<num_of_plants;++i){
        plants[i]->ReadFile(filename);
    }
    // Print_BombPlant
    cout << "=== Print_BombPlant ===" << endl ;
    cout << plants[0]->Id() << ' ' << plants[0]->Name() << " $" << plants[0]->Cost() << ' ' << plants[0]->Hp() << " Max_hp: " << plants[0]->Max_Hp() << endl << endl;
    BombPlant* bombplant = dynamic_cast<BombPlant*>(plants[0]);
    // Print_HealPlant
    cout << "=== Print_HealPlant ===" << endl ;
    cout << plants[1]->Id() << ' ' << plants[1]->Name() << " $" << plants[1]->Cost() << ' ' << plants[1]->Hp() << ' ' << " Max_hp: " << plants[1]->Max_Hp() << ' ';
    HealPlant* healplant = dynamic_cast<HealPlant*>(plants[1]);
    if(healplant)
        cout << "recover " << healplant->Heal_Point() << " hp per visit!" << endl << endl;
    // Print_CoinPlant
    cout << "=== Print_CoinPlant ===" << endl ;
    cout << plants[2]->Id() << ' ' << plants[2]->Name() << " $" << plants[2]->Cost() << ' ' << plants[2]->Hp() << " Max_hp: " << plants[2]->Max_Hp() << ' ';
    CoinPlant* coinplant = dynamic_cast<CoinPlant*>(plants[2]);
    if(coinplant){
        cout << "earn " << coinplant->Earn() << " every " << coinplant->Round() << " round(s)!" << endl;
        cout << "max_visits = " << coinplant->Max_Visits() << endl << endl;
    }

    // Print_ShootPlant
    cout << "=== Print_ShootPlant ===" << endl;
    cout << plants[3]->Id() << ' ' << plants[3]->Name() << " $" << plants[3]->Cost() << ' ' << plants[3]->Hp() << ' ' << " Max_hp: " << plants[3]->Max_Hp() << ' ';
    ShootPlant* shootplant = dynamic_cast<ShootPlant*>(plants[3]);
    if(coinplant)
        cout << "damage: " << shootplant->Damage() << endl << endl;
    // Print
    cout << "=== DisplayAll ===" << endl;
    for(int i=0;i<num_of_plants;++i){
        cout << "[" << i << "]" << plants[i] << endl;//optional: plants[i]->Display();
    }
    // Show Status
    cout << "=== Show_Status ===" << endl;
    for(int i=0;i<num_of_plants;++i){
        plants[i]->ShowStatus();
        cout << endl;
    }
    // Being attacked
    cout << "=== After being attacked by enemy (Suppose enemy's damage point is 15 ===" << endl;
    int damage_point = 15;
    for(int i=0;i<num_of_plants;++i){
        plants[i]->Suffer(damage_point);
        cout << "[" << i << "]" << plants[i] << endl;//optional: plants[i]->Display();
    }
    // being healed
    cout << "=== After being healed (notice that HP cannot be greater than MAX_HP) ===" << endl;
    for(int i=0;i<num_of_plants;++i){
        plants[i]->Healed(healplant->Heal_Point());
        cout << "[" << i << "]" << plants[i] << endl;//optional: plants[i]->Display();
    }
    // Visit the land with CoinPlant
    cout << "=== Visit the land with CoinPlant ===" << endl;
    cout << "Before: ";
    coinplant->ShowStatus();
    cout << endl << "*** Visit the land! ***" << endl;
    coinplant->Decre_Round();
    cout << "After: ";
    coinplant->ShowStatus();
    cout << endl << "*** Visit the land again! ***" << endl;
    cout << "Yeah! I get " << coinplant->Earn() << endl;
    // HornPlant attacks enemy
    cout << "=== HornPlant attacks enemy ===" << endl;
    cout << "the zombie suffers " << shootplant->Damage() << "-point damage" << endl;
    // BombPlant attacks enemy
    cout << "=== BombPlant attacks enemy ===" << endl;
    cout << "the zombie suffers " << bombplant->Hp() << "-point damage" << endl;
    // Remember to deallocate memory
    cout << "=== Deallocate_Memory ===" << endl << endl;
    for(int i=0;i<num_of_plants;++i){
        delete plants[i];
    }
    return 0;
}
