# Dual-Active-Bridge
A dual active bridge is a bidirectional DC-DC converter with identical primary and secondary side full-bridges, a high frequency transformer, an energy transfer inductor and DC-link capacitors. Energy transfer inductance in the model refers to the leakage inductance of the transformer plus any necessary external energy transfer inductance.

Papers regarding the matter can be downloaded from Papers directory in this repository.

To control Dual Active Bridges, we need two sets of PWM signals which should be phase shifted.

I have been able to do such a thing in Arduino Uno using Timer-1 and CTC mode 12 to generate two phase shifted PWM waves.