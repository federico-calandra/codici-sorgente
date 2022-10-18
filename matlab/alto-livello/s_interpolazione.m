close all; clear all; clc;
# funzione di partenza
xf = [0:0.05:10];
yf = sin (2*pi*xf/5);
plot(xf,yf,'k-'); hold on;

# estraggo alcuni dati
xp = [0:10];
yp = sin (2*pi*xp/5);
plot(xp,yp,"r*");

#faccio l'interpolazione lineare
lin = interp1(xp,yp,xf);   #determino più dati del tipo (xp,yp) sull'intervallo xf
plot(xf,lin,"g-");

#faccio l'interpolazione spline
spl = interp1(xp,yp,xf,"spline");
plot(xf,spl,"b");

legend('y=sin(x)','estrezione dati','lineare','spline');