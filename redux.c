#import <stdio.h>
#import <stdlib.h>
#import <string.h>

#define SAMPLE_RATE 44100

void redux(float *buf, int len, float srate, int redux) {
    float *buf2 = malloc(sizeof(float) * len);
    memcpy(buf2, buf, len);

    for (int i = 0; i < len; i++) {
        for (int j = 0; j < redux; j++) {
            buf[i + j] = buf2[i];
        }
        i += redux;
    }    
}

int main() {
    FILE *fp = fopen("funky.pcm", "rb");

    const int crush = 32;

    fseek(fp, 0, SEEK_END);
    int len = ftell(fp);
    rewind(fp);

    float *buf = malloc(len);
    fread(buf, len, 1, fp);
    fclose(fp);

    redux(buf, len * sizeof(float), SAMPLE_RATE, crush);

    FILE *out = fopen("funky_processed.pcm", "wb");
    fwrite(buf, 1, len, out);
    fclose(out);

    return 0;
}
