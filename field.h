#pragma once

#include <vector>
#include "ship.h"

class Field {
private:
    std::vector<std::vector<Ship*>> field_;
public:
    void show_field();
};