# Writeup

## P, I and D components

The P component controls the rate at which the car returns to the point of 0 CTE.

The I component reduces the effect of bias from the controller, by using the sum of the CTE. Since this is a perfect simulator, there is no I component.

The D component tries to fix the osciallation of the two previous components by using the difference of the CTE on the current timestep and CTE from the previous timestep

## Hyperparameter tuning

Seeing as implementing twiddle is a little hard without a headless mode, I decided to tune my parameters manually.

Also, seeing as this is a highly controlled track, tuning by hand seemed to be a good option.  If I were to try varied tracks/real world uses, I would 
probably tune my parameters by twiddle or some other algorithm.

I started out by using -.5 for P, 0 for I and -.5 for D.  This yielded a lot of oscillations around the center line, so I changed the D component to a much larger -3.0.  This made the car a lot more stable, but the corrections to the CTE were still very large.  Using this, I then changed the P component to -.1.  This made the car get very close to finishing a whole lap, but the corrections to the center line were not large enough.  I then changed the P component to -.2, and the car successfully navigated the track.

My final parameters:
1) P = -0.2
2) I = 0
3) D = -3.0