%% Metodo delle tangenti
%

clear; %clc;

f = @(x) x-cos(x);
df = @(x) 1+sin(x);

x = input("Punto iniziale: ");
toll = input("Tolleranza: ");
imax = input("Numero massimo di iterazioni");
delta = 1;
i = 0;

while (delta>toll && i<imax)
    zero = x - (f(x)/df(x));
    delta = abs(zero-x);
    res = abs(f(zero));
    x = zero;
    i = i+1;
end

printf("Dopo %d iterazioni si è trovato uno zero in %f con un residuo di %f",i,zero,res)