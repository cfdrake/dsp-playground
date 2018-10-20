#import <stdio.h>
#import <stdlib.h>
#import <string.h>

#define SAMPLE_RATE 44100

void redux(float *buf, int len, float srate, int redux) {
    for (int i = 0; i < len; i += redux) {
        float sample = buf[i];
        for (int j = 0; j < redux; j++) {
            buf[i + j] = sample;
        }
    }
}

int main() {
    FILE *fp = fopen("funky.pcm", "rb");

    fseek(fp, 0, SEEK_END);
    int len = ftell(fp);
    rewind(fp);

    float *buf = malloc(len);
    fread(buf, len, 1, fp);
    fclose(fp);

    const int factor = 32;
    redux(buf, len / sizeof(float), SAMPLE_RATE, factor);

    FILE *out = fopen("funky_processed.pcm", "wb");
    fwrite(buf, 1, len, out);
    fclose(out);

    return 0;
}
