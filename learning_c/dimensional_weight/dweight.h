#ifndef DWEIGHT_H
#define DWEIGHT_H

/* Volume of a box in cubic inches. */
int calc_volume(int height, int length, int width);

/* Dimensional weight in pounds, rounded up (volume / 166). */
int calc_dimensional_weight(int volume);

#endif
