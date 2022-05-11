#pragma once

class Command {
    Command();

    virtual ~Command();

    virtual void action() = 0;
};

