#include <stdio.h>
#include "LSTM_classify.h"
#include "LSTM_classify_initialize.h"
#include "LSTM_classify_terminate.h"

// Example input (replace this with real data from sensors or file)
double inputWindow[500][4] = {0};  // fill with test values

int main() {
    LSTM_classify_initialize();

    // Output is a class label (categorical in MATLAB, double here)
    double output;
    LSTM_classify((const double *)inputWindow, &output);

    printf("Predicted class: %.0f\n", output);

    LSTM_classify_terminate();
    return 0;
}