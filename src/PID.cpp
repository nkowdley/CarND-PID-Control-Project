#include "PID.h"

/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID() {} //:Kp(Kp_), Ki(Ki_), Kd(Kd_)

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_)
{
  /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   */
   K_array[0] = Kp_;
   K_array[1] = Ki_;
   K_array[2] = Kd_;
   p_error = 0;
   d_error = 0;
   i_error = 0;
}

void PID::UpdateError(double cte) {
  /**
   * TODO: Update PID errors based on cte.
   */
  double previous_cte = p_error;
  p_error = cte;
  i_error += cte;
  d_error = cte - previous_cte;
}

double PID::TotalError() {
  /**
   * TODO: Calculate and return the total error
   */
  return K_array[0] * p_error + K_array[1] * i_error + K_array[2] * d_error;  // TODO: Add your total error calc here!
}