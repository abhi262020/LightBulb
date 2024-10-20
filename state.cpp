// State.cpp
#include "State.h"

State::State(StateEnum initialState) : state(initialState) {}

StateEnum State::GetState() const {
    return state;
}

void State::SetState(StateEnum newState) {
    state = newState;
}

std::string State::GetStateAsString() const {
    switch (state) {
    case Off:
        return "Off";
    case On:
        return "On";
    case Broken:
        return "Broken";
    default:
        return "Unknown";
    }
}
