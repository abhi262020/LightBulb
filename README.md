# LightBulb
### In this state machine model, the light bulb operates as a simple system with three distinct states: Off, On, and Broken. Each state represents a different physical condition of the bulb, and the transitions between these states are triggered by events such as 
### turning the bulb on, turning it off, or breaking the bulb.

# States of the Light Bulb:
## Off->On:
### The bulb is not emitting light.
### The system is inactive, with no electricity flowing through the bulb, or the voltage is set to zero.
### This is the initial state of the light bulb.
## On->Off:
### The bulb is emitting light.
### In this state, the bulb is fully operational, and it receives a voltage high enough to activate the filament or the light source.
### Represents the active state where the bulb is functioning properly.
## Broken:
### The bulb is non-functional, usually due to a fault such as an internal breakage or an overload.
### In this state, the bulb cannot emit light, and it requires repair or replacement.
### Once in this state, the bulb cannot be turned back on or off until repaired, symbolizing a terminal or error state.

# Events Triggering Transitions:
## Turn On:

### Event that represents an action to power the bulb, moving it from the Off state to the On state.
### Example: Someone flips the switch to turn on the bulb, or a signal is sent to provide sufficient voltage to power the bulb.
## Turn Off:

### Event that represents an action to cut power to the bulb, transitioning it from the On state back to the Off state.
### Example: The switch is flipped off, or the power supply is cut.
## Break Bulb:

### This event represents an external factor or internal malfunction that causes the bulb to break, transitioning the state from On (or potentially Off) to Broken.
### Example: A power surge causes the filament to burn out, or physical damage breaks the bulb.
# Guard Conditions:
### Guard conditions ensure that certain transitions only occur under specific conditions. In this model:

### A transition from On to Off or from Off to On occurs only when no malfunctions are detected (i.e., the bulb is not broken).
### Example: The Turn On transition would only trigger if the bulb's guard condition for "not broken" is met.
# Effects:
### Effects represent actions that happen as part of a transition between states. In this model, effects are simple and tied to the transition:

### Turning the bulb on or off may display a message like "Bulb is On" or "Bulb is Off."
### Breaking the bulb causes the system to print "Bulb broke," signalling the fault.

# State Transitions:
## Off → On:
### Trigger: Turn On event.
### Guard: Bulb is not broken.
### Effect: Print "Bulb is On."
## On → Off:
### Trigger: Turn Off event.
### Guard: Bulb is not broken.
### Effect: Print "Bulb is Off."
## On → Broken:
### Trigger: Break Bulb event.
### Guard: Always true (the bulb can break any time when on).
### Effect: Print "Bulb broke."
               
# Real-World Analogy:
### The light bulb state machine is a simplified version of how an actual light bulb operates:
### Initially, a light bulb is off.
### When you flip the switch, an electric signal is sent, changing its state to on.
### Over time, or due to an issue, the light bulb might break, moving it into an irrecoverable state.
### This kind of state machine is very useful in systems like home automation where controlling appliances like light bulbs is critical, allowing precise behavior modeling under different scenarios (e.g., turning on lights based on sensor input or breaking the circuit ### when overload conditions occur).
