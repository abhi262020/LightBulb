#ifndef FSM_H
#define FSM_H

#pragma once
#include "stdafx.h"
#include "Transition.h"
#include "LinkedList.h"
#include "State.h"  // Include the new State class

class FSM {
private:
    State* currentState;  // Use the State class instead of raw StateEnum
    LinkedList<Transition*> transitions;  // Use LinkedList instead of std::vector

public:
    FSM(StateEnum initialState);
    void AddTransition(Transition* transition);
    void Update(int voltage);
    StateEnum GetCurrentState() const;
    ~FSM();
};


#endif // FSM_H
