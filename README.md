WAV-Trigger-YUN-Sample-Sketch
=============================

Sample Arduino YUN Sketch for WAV Trigger control over wifi from a browser.

This sketch is extremely basic due to my limited knowledge of html/CSS.
The single html page provides one ON/OFF toggle switch and one range
slider, and the sketch is written to turn on (with looping enabled),
turn off and control the volume of track 1. That's it.


![screenshot](/pictures/example1.jpg)


I've noticed that Android mobile browsers don't update the volume slider
value while it is moving. Desktop Chrome does, but this somehow messes
up the communication path for a bit. The sketch limits WAV Trigger
volume updates to one every 50 msecs, so I'll have to dig into it see what
else might be going on.

In the meantime, this will serve as a basic example of how to use the
WAV Trigger Arduino library, which is also in its early stages of
development. Please see the readme file in the corresponding library repo
for current limitations.
