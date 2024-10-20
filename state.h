#ifndef STATE_H
#define STATE_H


// State.h
#pragma once
#include "stdafx.h"

class State {
private:
    StateEnum state;

public:
    State(StateEnum initialState);
    StateEnum GetState() const;
    void SetState(StateEnum newState);

    // Optional helper function for displaying state as text
    std::string GetStateAsString() const;
};

#endif // STATE_H
