WAV-Trigger-YUN-Sample-Sketch
=============================

Sample Arduino YUN Sketch for WAV Trigger control from a browser.

This sketch is extremely simple due to my limited knowledge of html/CSS.
The single html page provides one ON/OFF toggle switch and one range
slider, and the sketch is written to turn on (with looping enabled),
turn off and control the volume of track 1. that's it.

I have noticed that mobile browsers don't update the volume slider
value while it is moving. Desktop Chrome does, but this somehow messes
up the communication path for a bit. The sketch limits changes to
every 50 msecs, so I'll have to dig into see what's going on.

In the meantime, this will serve as a basic example of how to use the
WAV Trigger, which is also in its early stages of development.
