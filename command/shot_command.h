#pragma once

#include "command.h"

class ShotCommand : Command {
    ShotCommand();

    ~ShotCommand();

    void action() override;
};
