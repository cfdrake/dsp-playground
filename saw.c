#import <stdio.h>

#define SAMPLE_RATE 44100

void saw_wave(float freq, float *buf, int len, float srate) {
    float pos = 0;
    float delta = freq / srate;

    for (int i = 0; i < len; i++) {
        // Offset saw wave to run between -1 and 1.
        buf[i] = (pos - 0.5) * 2.0;
        pos += delta;

        if (pos >= 1.0) {
            pos -= 1.0;
        }        
    }    
}

int main() {
    const float freq = 220.0;
    const int nsamples = SAMPLE_RATE * 4;
    float buf[nsamples] = {0};
    FILE *fp = fopen("saw.wav", "wb");

    saw_wave(freq, buf, nsamples, SAMPLE_RATE);

    fwrite(buf, sizeof(float), nsamples, fp);
    fclose(fp);

    return 0;
}
