#include "esfera_utils.h"

void CalculaVolume (float R, float *volume) {
    *volume = 4.0 / 3.0 * PI * R * R * R;
}

void CalculaArea (float R, float *area) {
    *area = 4.0 * PI * R * R;
}
