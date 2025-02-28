# Spectrum Analyzer Project

This project is a work in progress for my capstone project at UW Superior. My teacher built a custom daughter
card for my BG22 Explorer board which allows me to collect audio through a 3.5mm headphone jack.

The main loop is called from app.c which checks to see if samples are ready from the adc and then processes them
in the doWork() method in my_math.h. There the audio samples are normalized and processed with FFT. The result
of the FFT is displayed in 16 frequency bands on an ssd1306 oled display.

Also displayed is the raw waveform which displays the raw samples from the ADC averaged with the samples collected
in the previous loop. 
