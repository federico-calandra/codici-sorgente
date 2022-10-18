close all;
clear all;
clc;

%Funzione da integrare
fun = @(x) log(1+x).*sin(10*x);
%Estremi di integrazione
a = 0; b = pi/4;

%Grafico della funzione
xb = linspace(0,pi/4);
yb = fun(xb);
figure; plot(xb,yb,'r');

Ies = integral(fun,a,b)

%Rettangolo
Ir = (b-a)*fun((a+b)/2)

%Trapezio
It = ((fun(a)+fun(b))*(b-a))/2

%Trapezio composito
N = 30;
H = (b-a)/N;

xj = a+H*[0:N]

IN = H/2*(fun(xj(1))+fun(xj(N+1))+2*sum(fun(xj(2:N))))

%Rettangolo composito
xm = a+H/2*[1:2:2*N-1] %oppure: xm = (xj(1:N)+xj(2:N+1))/2

IR = H*sum(fun(xm))