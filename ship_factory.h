#pragma once

#include "ship.h"

class ShipFactory {
public:

    virtual Ship* CreateShip(ShipType) = 0;
    virtual void DeleteShip(Ship*);
private:

};

class FirstPlayerShipFactory : public ShipFactory {
    Ship* CreateShip(ShipType) override;
};

class SecondPlayerShipFactory : public ShipFactory {
    Ship* CreateShip(ShipType) override;
};
