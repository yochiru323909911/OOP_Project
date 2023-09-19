#include "CollisionHandling.h"
#include <iostream>
#include <map>
#include <string>
#include <typeinfo>
#include <typeindex>
#include "RandomCar.h"
#include "TimeBonus.h"
#include "CurAccelerationBonus.h"
#include "CreditBonus.h"
#include "Fence.h"
#include "MaxAccelerationBonus.h"
#include "Motorcycle.h"
#include "PlayerCar.h"
#include "Police.h"
#include "Truck.h"
#include "River.h"
#include "KillBonus.h"

//=================================================================================================
namespace 
{
    //=================================================================================================
    //זוהי פונקציית ההתנגשות של מכונית רנדומלית עם מכונית רנדומלית אחרת
    bool randomCarRandomCar(GameObject& randCar1, GameObject& randCar2)  
    {
        RandomCar& randomCar1 = dynamic_cast<RandomCar&>(randCar1);
        RandomCar& randomCar2 = dynamic_cast<RandomCar&>(randCar2);
        randomCar1.changeCar();
        return false;
    }
    //=================================================================================================
    //זוהי פונקציית ההתנגשות של השחקן עם בונוס של תוספת זמן
    bool playerTimeBonus(GameObject& player, GameObject& timeB)
    {
      PlayerCar& playercar = dynamic_cast<PlayerCar&>(player);
      TimeBonus& timeBonus = dynamic_cast<TimeBonus&>(timeB);
      timeBonus.hitBonus();
      return true;
    }
    //=================================================================================================
    //זוהי פונקציית ההתנגשות של השחקן עם בונוס של תאוצה נוכחית
    bool playerCurAccelerationBonus(GameObject& player,GameObject& CurAccelerationB)
    {
        PlayerCar& playercar = dynamic_cast<PlayerCar&>(player);
        CurAccelerationBonus& curAccelerationBonus = dynamic_cast<CurAccelerationBonus&>(CurAccelerationB);
        curAccelerationBonus.hitBonus(playercar.setSpeed(), playercar.setMaxSpeed());
        return true;
    }
    //=================================================================================================
    //זוהי פונקציית ההתנגשות של שחקן עם בונוס של נקודות
    bool playerCreditBonus(GameObject& player, GameObject& creditB)
    {
        PlayerCar& playercar = dynamic_cast<PlayerCar&>(player);
        CreditBonus& creditBonus = dynamic_cast<CreditBonus&>(creditB);
        creditBonus.hitBonus();
        return true;
    }
    //=================================================================================================
    //זוהי פונקציית ההתנגשות של של שחקן עם בונוס של תאוצה מקסימלית
    bool playerMaxAccelerationBonus(GameObject& player, GameObject& maxAccelerationB)
    {
        PlayerCar& playercar = dynamic_cast<PlayerCar&>(player);
        MaxAccelerationBonus& maxAccelerationBonus = dynamic_cast<MaxAccelerationBonus&>(maxAccelerationB);
        maxAccelerationBonus.hitBonus(playercar.setMaxSpeed());
        return true;
    }
    //=================================================================================================
    //זוהי פונקציית ההתנגשות של של שחקן עם בונוס של הריגת מכוניות
    bool playerKillBonus(GameObject& player, GameObject& killB)
    {
        PlayerCar& playercar = dynamic_cast<PlayerCar&>(player);
        KillBonus& killbonus = dynamic_cast<KillBonus&>(killB);
        killbonus.hitBonus(&playercar);
        return true;
    }
    //=================================================================================================
    //זוהי פונקציית ההתנגשות של שחקן עם מכונית רנדומלית
    bool playerRandomCar(GameObject& player, GameObject& RandCar)
    {
        PlayerCar& playercar = dynamic_cast<PlayerCar&>(player);
        RandomCar& randomCar = dynamic_cast<RandomCar&>(RandCar);
        playercar.hitRandomCar(randomCar);
        return false;  
    }
    //=================================================================================================
    //זוהי פונקציית ההתנגשות של שחקן עם מכונית משטרה
    bool playerPolice(GameObject& player, GameObject& policeC)
    {
        PlayerCar& playercar = dynamic_cast<PlayerCar&>(player);
        Police& police = dynamic_cast<Police&>(policeC);
        playercar.hitSmartCar();
        return false;
    }
    //=================================================================================================
    //זוהי פונקציית ההתנגשות של שחקן עם משאית
    bool playerTruck(GameObject& player, GameObject& TruckC)
    {
        PlayerCar& playercar = dynamic_cast<PlayerCar&>(player);
        Truck& truck = dynamic_cast<Truck&>(TruckC);
        playercar.hitSmartCar();
        return false;
    }
    //=================================================================================================
    //זוהי פונקציית ההתנגשות של שחקן עם אופנוע
    bool playerMotorcycle(GameObject& player, GameObject& motorcycle)
    {
        PlayerCar& playercar = dynamic_cast<PlayerCar&>(player);
        Motorcycle& motorcycl = dynamic_cast<Motorcycle&>(motorcycle);
        playercar.hitSmartCar();
        return false;
    }
    //=================================================================================================
    //זוהי פונקציית ההתנגשות של של שחקן עם גדר
    bool playerFence(GameObject& player, GameObject& fenceObj)
    {
        PlayerCar& playercar = dynamic_cast<PlayerCar&>(player);
        Fence& fence = dynamic_cast<Fence&>(fenceObj);
        playercar.playSound();
        return false;
    }
    //=================================================================================================
    //זוהי פונקציית ההתנגשות של שחקן עם נהר
    bool playerRiver(GameObject& player, GameObject& RiverObj)
    {
        PlayerCar& playercar = dynamic_cast<PlayerCar&>(player);
        River& river = dynamic_cast<River&>(RiverObj);
        playercar.setDrownInRiver(true);
        return false;
    }
    //=================================================================================================
    //זוהי פונקציית ההתנגשות של מכונית רנדומלית עם גדר
    bool RandomCarFence(GameObject& randomCar, GameObject& fenceObj)
    {
        RandomCar& randCar = dynamic_cast<RandomCar&>(randomCar);
        Fence& fence = dynamic_cast<Fence&>(fenceObj);
        randCar.changeCar();
        return false;
    }
    //=================================================================================================
    //זוהי פונקציית ההתנגשות של מכונית רנדומלית עם נהר
    bool RandomCarRiver(GameObject& randomCar, GameObject& Riverobj)
    {
        RandomCar& randCar = dynamic_cast<RandomCar&>(randomCar);
        River& river = dynamic_cast<River&>(Riverobj);
        randCar.changeCar();
        return false;
    }
    //=================================================================================================
    //זוהי פונקציית ההתנגשות של מכונית רנדומלית עם השחקן
    bool RandomCarPlayer(GameObject& randomCar, GameObject& playerCar)
    {
        RandomCar& randCar = dynamic_cast<RandomCar&>(randomCar);
        PlayerCar& player = dynamic_cast<PlayerCar&>(playerCar);
        randCar.changeCar();
        return false;
    }
    //=================================================================================================
    //זוהי פונקציית ההתנגשות של מכונית רנדומלית עם מכונית משטרה
    bool RandomCarPolice(GameObject& randomCar, GameObject& policeCar)
    {
        RandomCar& randCar = dynamic_cast<RandomCar&>(randomCar);
        Police& police = dynamic_cast<Police&>(policeCar);
        randCar.changeCar();
        return false;
    }
    //=================================================================================================
    //זוהי פונקציית ההתנגשות של מכונית רנדומלית עם משאית
    bool RandomCarTruck(GameObject& randomCar, GameObject& TruckCar)
    {
        RandomCar& randCar = dynamic_cast<RandomCar&>(randomCar);
        Truck& truck= dynamic_cast<Truck&>(TruckCar);
        randCar.changeCar();
        return false;
    }
    //=================================================================================================
    //זוהי פונקציית ההתנגשות של מכונית רנדומלית עם אופנוע
    bool RandomCarMotorcycle(GameObject& randomCar, GameObject& motorcycle)
    {
        RandomCar& randCar = dynamic_cast<RandomCar&>(randomCar);
        Motorcycle& motor = dynamic_cast<Motorcycle&>(motorcycle);
        randCar.changeCar();
        return false;
    }
    //=================================================================================================
    //זוהי פונקציית ההתנגשות של משטרה עם שחקן
    bool PolicePlayer(GameObject& policeCar, GameObject& playerCar)
    {
        Police& police = dynamic_cast<Police&>(policeCar);
        PlayerCar& player = dynamic_cast<PlayerCar&>(playerCar);
        return false;
    }
    //=================================================================================================
    //זוהי פונקציית ההתנגשות של משטרה עם מכונית רנדומלית
    bool PoliceRandomCar(GameObject& policeCar, GameObject& randCar)
    {
        Police& police = dynamic_cast<Police&>(policeCar);
        RandomCar& randomCar = dynamic_cast<RandomCar&>(randCar);
        return false;
    }
    //=================================================================================================
    //זוהי פונקציית ההתנגשות של משטרה עם גדר
    bool PoliceFence(GameObject& policeCar, GameObject& fenceObj)
    {
        Police& police = dynamic_cast<Police&>(policeCar);
        Fence& fence = dynamic_cast<Fence&>(fenceObj);
        return false;
    }
    //=================================================================================================
    //זוהי פונקציית ההתנגשות של משטרה עם נהר
    bool PoliceRiver(GameObject& policeCar, GameObject& riverObj)
    {
        Police& police = dynamic_cast<Police&>(policeCar);
        River& river = dynamic_cast<River&>(riverObj);
        return false;
    }
    //=================================================================================================
    //זוהי פונקציית ההתנגשות של משאית עם השחקן
    bool TruckPlayer(GameObject& truckCar, GameObject& playerCar)
    {
        Truck& truck = dynamic_cast<Truck&>(truckCar);
        PlayerCar& player = dynamic_cast<PlayerCar&>(playerCar);
        return false;
    }
    //=================================================================================================
    //זוהי פונקציית ההתנגשות של משאית עם מכונית רנדומלית
    bool TruckRandomCar(GameObject& truckCar, GameObject& randCar)
    {
        Truck& truck = dynamic_cast<Truck&>(truckCar);
        RandomCar& randomCar = dynamic_cast<RandomCar&>(randCar);
        return false;
    }
    //=================================================================================================
    //זוהי פונקציית ההתנגשות של משאית עם גדר
    bool TruckFence(GameObject& truckCar, GameObject& fenceObj)
    {
        Truck& truck = dynamic_cast<Truck&>(truckCar);
        Fence& fence = dynamic_cast<Fence&>(fenceObj);
        return false;
    }
    //=================================================================================================
    //זוהי פונקציית ההתנגשות של משאית עם נהר
    bool TruckRiver(GameObject& TruckCar, GameObject& riverObj)
    {
        Truck& truck = dynamic_cast<Truck&>(TruckCar);
        River& river = dynamic_cast<River&>(riverObj);
        return false;
    }
    //=================================================================================================
    //זוהי פונקציית ההתנגשות של אופנוע עם השחקן
    bool MotorcyclePlayer(GameObject& motorcycleCar, GameObject& playerCar)
    {
        Motorcycle& motorcycle = dynamic_cast<Motorcycle&>(motorcycleCar);
        PlayerCar& player = dynamic_cast<PlayerCar&>(playerCar);
        return false;
    }
    //=================================================================================================
    //זוהי פונקציית ההתנגשות של אופנוע עם מכונית רנדומלית
    bool MotorcycleRandomCar(GameObject& motorcycleCar, GameObject& randCar)
    {
        Motorcycle& motorcycle = dynamic_cast<Motorcycle&>(motorcycleCar);
        RandomCar& randomCar = dynamic_cast<RandomCar&>(randCar);
        return false;
    }
    //=================================================================================================
    //זוהי פונקציית ההתנגשות של אופנוע עם גדר
    bool MotorcycleFence(GameObject& motorcycleCar, GameObject& fenceObj)
    {
        Motorcycle& motorcycle = dynamic_cast<Motorcycle&>(motorcycleCar);
        Fence& fence = dynamic_cast<Fence&>(fenceObj);
        return false;
    }
    //=================================================================================================
    //זוהי פונקציית ההתנגשות של אופנוע עם נהר
    bool MotorcycleRiver(GameObject& motorcycleCar, GameObject& riverObj)
    {
        Motorcycle& motorcycle = dynamic_cast<Motorcycle&>(motorcycleCar);
        River& river = dynamic_cast<River&>(riverObj);
        return false;
    }
    //=================================================================================================
    using HitFunctionPtr = bool (*)(GameObject&, GameObject&);
    using Key = std::pair<std::type_index, std::type_index>;
    using HitMap = std::map<Key, HitFunctionPtr>;
    //=================================================================================================
    //זוהי המפה עבור ההתנגשויות
    HitMap initializeCollisionMap()
    {
        HitMap phm;
        phm[Key(typeid(PlayerCar), typeid(TimeBonus))] = &playerTimeBonus;
        phm[Key(typeid(PlayerCar), typeid(CurAccelerationBonus))] = &playerCurAccelerationBonus;
        phm[Key(typeid(PlayerCar), typeid(CreditBonus))] = &playerCreditBonus;
        phm[Key(typeid(PlayerCar), typeid(MaxAccelerationBonus))] = &playerMaxAccelerationBonus;
        phm[Key(typeid(PlayerCar), typeid(RandomCar))] = &playerRandomCar;
        phm[Key(typeid(PlayerCar), typeid(Police))] = &playerPolice;
        phm[Key(typeid(PlayerCar), typeid(Truck))] = &playerTruck;
        phm[Key(typeid(PlayerCar), typeid(Motorcycle))] = &playerMotorcycle;
        phm[Key(typeid(PlayerCar), typeid(Fence))] = &playerFence;
        phm[Key(typeid(RandomCar), typeid(RandomCar))] = &randomCarRandomCar;
        phm[Key(typeid(RandomCar), typeid(Fence))] = &RandomCarFence;
        phm[Key(typeid(RandomCar), typeid(River))] = &RandomCarRiver;
        phm[Key(typeid(RandomCar), typeid(PlayerCar))] = &RandomCarPlayer;
        phm[Key(typeid(RandomCar), typeid(Police))] = &RandomCarPolice;
        phm[Key(typeid(RandomCar), typeid(Truck))] = &RandomCarTruck;
        phm[Key(typeid(RandomCar), typeid(Motorcycle))] = &RandomCarMotorcycle;
        phm[Key(typeid(Police), typeid(PlayerCar))] = &PolicePlayer;
        phm[Key(typeid(Police), typeid(RandomCar))] = &PoliceRandomCar;
        phm[Key(typeid(Police), typeid(Fence))] = &PoliceFence;
        phm[Key(typeid(Truck), typeid(PlayerCar))] = &TruckPlayer;
        phm[Key(typeid(Truck), typeid(RandomCar))] = &TruckRandomCar;
        phm[Key(typeid(Truck), typeid(Fence))] = &TruckFence;
        phm[Key(typeid(Motorcycle), typeid(Fence))] = &MotorcycleFence;
        phm[Key(typeid(Motorcycle), typeid(PlayerCar))] = &MotorcyclePlayer;
        phm[Key(typeid(Motorcycle), typeid(RandomCar))] = &MotorcycleRandomCar;
        phm[Key(typeid(PlayerCar), typeid(River))] = &playerRiver;
        phm[Key(typeid(PlayerCar), typeid(KillBonus))] = &playerKillBonus;
        return phm;
    }
    //=================================================================================================
    //זוהי פונקציה שמוצאת את הפונקציה שמטפלת בהתנגשות של האובייקטים שקיבלה (לפי הסדר!). הפונקציה מחזירה את המצביע לפונקציה או נאל אם היא לא מצאה כזו
    HitFunctionPtr lookup(const std::type_index& class1, const std::type_index& class2)
    {
        static HitMap collisionMap = initializeCollisionMap();
        auto mapEntry = collisionMap.find(std::make_pair(class1, class2));
        if (mapEntry == collisionMap.end())
        {
            return nullptr;
        }
        return mapEntry->second;
    }

}
//=================================================================================================
//פונקציה זו מבצעת את הקריאה לפונקציית ההתנגשות המתאימה לאובייקטים שקיבלה ומפעילה אותה
bool processCollision(GameObject& object1, GameObject& object2)
{
    auto phf = lookup(typeid(object1), typeid(object2));
    if (phf)
        return phf(object1, object2);
    return true;
}
