#include "HalideRuntime.h"

#include <cmath>
#include <stdio.h>

#include "multi.h"
#include "static_image.h"

const int kSize = 32;

void verify(const Image<uint16_t> &input, const Image<uint16_t> &output, bool amplify, int scale) {
    for (int y = 0; y < kSize; y++) {
        for (int x = 0; x < kSize; x++) {
            int expected = amplify ? input(x, y) * scale : input(x, y) / scale;
            if (output(x, y) != expected) {
                printf("output[%d, %d] = %d (expected %d)\n", x, y, output(x, y), expected);
                exit(-1);
            }
        }
    }
}

void test(bool amplify, int scale, const Image<uint16_t> &input, Image<uint16_t> &output) {
    multi(amplify, scale, input, output);
    verify(input, output, amplify, scale);
}

int main(int argc, char **argv) {

  Image<uint16_t> input(kSize, kSize);
  for (int y = 0; y < kSize; y++) {
      for (int x = 0; x < kSize; x++) {
          input(x, y) = y * 2 + x + 4;
      }
  }
  Image<uint16_t> output(kSize, kSize);

  test(false, 2, input, output);
  test(false, 3, input, output);
  test(true, 2, input, output);
  test(true, 3, input, output);


  printf("Success!\n");
  return 0;
}
