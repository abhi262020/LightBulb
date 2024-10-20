#ifndef TRANSITION_H
#define TRANSITION_H

// Transition.h
#pragma once
#include "stdafx.h"

class Transition {
private:
    StateEnum fromState;
    StateEnum toState;
    int (*condition)(int voltage);

public:
    Transition(StateEnum from, StateEnum to, int (*condition)(int));
    bool IsTriggered(int voltage);
    StateEnum GetNextState();
};

#endif // TRANSITION_H
