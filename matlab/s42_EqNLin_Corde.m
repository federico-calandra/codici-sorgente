%% Metodo delle corde
% Determina uno zero di uno funzione tramite il metodo dell

close all; clear; clc;

% inserisco funzione, intervallo e punto iniziale
f = @(x) x-cos(x);

x = input("Punto iniziale: ");
m = input("Valore di m: ");
toll = input("Tolleranza: ");
imax = input("Numero massimo di iterazioni: ");
delta = 1;
i = 0;

while (delta>toll && i<imax)    % finché non si verifica il criterio di arresto
    zero = x - (f(x)/m);    % determino il prossimo elemento della successione
    delta = abs(zero-x);    % calcolo la distanza dal precedente
    res = abs(f(zero));     % calcolo anche il residuo
    x = zero;   % prendo l'elemento calcolato come partenza per il passo successivo
    i = i+1;
end     % quando si è verificato il criterio di arresto
% stampo i rislutati
printf("Dopo %d iterazioni si è trovato uno zero in %f con un residuo di %f",i,zero,res)