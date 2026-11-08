# Day 16: ADC smoothing and scaling

**Goal:** Reduce noisy potentiometer readings by averaging multiple samples and convert the result to a percentage.

## Wiring
Potentiometer outer legs → 3V3 and GND; center wiper → GPIO 34.

## Run
Upload and open Serial Monitor at 115200 baud. Rotate the potentiometer slowly and compare the stable percentage output.

## Concepts
The sketch averages 20 readings. Averaging reduces random noise but adds a little response delay. `map()` converts the 0–4095 raw scale to 0–100. The mapping assumes the full raw range and is not a substitute for ADC calibration.

## Exercise
Change `SAMPLE_COUNT` to 5 and 50. Observe the trade-off between responsiveness and stability.