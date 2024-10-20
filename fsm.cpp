// FSM.cpp
#include "FSM.h"

FSM::FSM(StateEnum initialState) {
    currentState = new State(initialState);  // Initialize the currentState with a new State object
}

FSM::~FSM() {
    delete currentState;  // Clean up dynamically allocated State
}

void FSM::AddTransition(Transition* transition) {
    transitions.Add(transition);  // Use LinkedList's Add method
}

void FSM::Update(int voltage) {
    transitions.ForEach([&](Transition* transition) {
        if (transition->IsTriggered(voltage)) {
            currentState->SetState(transition->GetNextState());  // Set new state using the State class
            return;
        }
        });
}

StateEnum FSM::GetCurrentState() const {
    return currentState->GetState();  // Return the state through the State class
}
