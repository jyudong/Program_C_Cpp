//
// main.cpp
// Cpp
// 
// Created by jy_Dong
//
// 小球碰撞

#include<iostream>
#include<cstring>
#include<algorithm> // sort() function;
#include<math.h>

using namespace std;

int main(){
    int N; // number of particles;
    double L; // length of the platform;
    cin >> N >> L;
    // cout << N << ' ' << L << endl;

    // initialize;
    double x_0[N],x[N]; // position of the particles;
    for (int i=0; i<N; i++){
        cin >> x_0[i]; // initialize the positions;
        x[i] = x_0[i];
    }
    // cout << x[2];
    int v_0[N],v[N]; // velocity of the particles;
    for (int i=0; i<N; i++){
        v_0[i] = pow(-1,i); // initialize the velocities;
    }
    // cout << v_0[2] << endl;

    // rearrange the positions and velocities from left to right;
    sort(x,x+N);
    // for (int i=0; i<N; i++){
    //     cout << x[i];
    // }
    // cout << endl;
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            if (x[i] == x_0[j]){
                v[i] = v_0[j];
                break;
            }
        }
    }
    // cout << v[0] << endl;

    double distance_min = L; // the shortest distance between two near particles which go in different directions, to determine the system state after a crash;
    
    double t_first, t_last; // times of first and last ball drop;
    double t_total; // total time from beginning to now;

    int condition; // label of which condition occur;
    int label_crash; // the crash occur between which two balls;
    int balls_drop = 0; // number of balls on the ground;
    
    int first_nonzero, last_nonzero; // label the first and last ball with nonzero velocity;

    while (true){

        distance_min = L;

        for (int i=0; i<N; i++){
            if (v[i] != 0){
                first_nonzero = i; // label of the first ball with nonzero velocity;
                if (v[i] < 0){
                    distance_min = x[i]; // if the ball go to left, then it may drop after a few seconds;
                    condition = 0;
                }
                break;
            }
        }

        for (int i=N-1; i>-1; i--){
            if (v[i] != 0){
                last_nonzero = i; // label of the last ball with nonzero velocity;
                if (v[i] > 0 && L-x[i] < distance_min){
                    distance_min = L-x[i]; // if the ball go to right, then it may drop after a few seconds;
                    condition = 1;
                }
                break;
            }
        }

        for (int i=first_nonzero; i<last_nonzero; i++){
            if (v[i] == 1 && v[i+1] == -1 && x[i+1]-x[i] < distance_min){
                distance_min = x[i+1]-x[i]; // if near two balls are getting close, they may crash after a few seconds; 
                label_crash = i;
                condition = 2;
            }
        }

        if (condition == 0){
            t_total = t_total + distance_min;
            for (int i=0; i<N; i++){
                x[i] = x[i] + v[i]*distance_min; // all balls move for a time;
            }
            v[first_nonzero] = 0; // the velocity of the ball dropped is 0;
            if (balls_drop == 0){
                t_first = t_total;
            }
            if (balls_drop == N-1){
                t_last = t_total;
            }
            balls_drop += 1; // a ball drop;
        }

        if (condition == 1){
            t_total = t_total + distance_min;
            for (int i=0; i<N; i++){
                x[i] = x[i] + v[i]*distance_min; // all balls move for a time;
            }
            v[last_nonzero] = 0; // the velocity of the ball dropped is 0;
            if (balls_drop == 0){
                t_first = t_total;
            }
            if (balls_drop == N-1){
                t_last = t_total;
            }
            balls_drop += 1; // a ball drop;
        }

        if (condition == 2){
            t_total = t_total + distance_min/2;
            for (int i=0; i<N; i++){
                x[i] = x[i] + v[i]*distance_min/2; // all balls move for a time;
            }
            // x[label_crash+1] = (x[label_crash+1]+x[label_crash])/2; x[label_crash] = (x[label_crash+1]+x[label_crash])/2; // the position of crash;
            v[label_crash+1] = 1; v[label_crash] = -1; // velocitis change direction;
        }

        // break;
        if (balls_drop == N){
            break; // all balls drop;
        }
    }

    // output;
    cout << t_first << ' ' << t_last;

    return 0;
}