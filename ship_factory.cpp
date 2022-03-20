#include "ship_factory.h"
#include "ship.h"

void ShipFactory::DeleteShip(Ship* unit) {
    delete unit;
}

Ship* FirstPlayerShipFactory::CreateShip(ShipType ship_type) {
    Ship* ship = new Ship();
    return ship;
}

Ship* SecondPlayerShipFactory::CreateShip(ShipType ship_type) {
    Ship* ship = new Ship();
    return ship;
}