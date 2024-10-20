// Transition.cpp
#include "Transition.h"

Transition::Transition(StateEnum from, StateEnum to, int (*condition)(int))
    : fromState(from), toState(to), condition(condition) {}

bool Transition::IsTriggered(int voltage) {
    return condition(voltage);
}

StateEnum Transition::GetNextState() {
    return toState;
}
