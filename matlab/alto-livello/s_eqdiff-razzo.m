close all; clear all; clc;
T = 48000
g = 9.81
m0 = 2200
r = 0.8
b = 40

vdot=@(t) (T/(m0*(1-(r*t/b))))-g;

[time23,v23]=ode23(vdot,[0,b],0);
[time45,v45]=ode45(vdot,[0,b],0);
plot(time23,v23,'k',time45,v45,'r');
legend('ode23','ode45');

printf("la velocità del razzo all'istante di burnout è %.0f m/s",v(size(v,1)))