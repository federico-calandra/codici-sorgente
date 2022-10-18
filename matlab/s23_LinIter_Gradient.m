%% Metodo del gradiente
% Viene generata una matrice NxN simmetrica e definita positiva. Impostata
% la tolleranza, si si parte da un punto causale, si inizializza il
% processo e si itera fino a raggiungere una stima accettabile.

clear; clc

% dati
N = input("Inserire ordine della matrice: ");
A = rand(N);
A = A'*A
b = ones(N,1);
xes=A\b;
toll = input("Inserire tolleranza: ");

% passo iniziale
c = 1;
x = rand(N,1);   % punto iniziale
d = -A*x + b;    % direzione
a = (d'*d)/(d'*A*d);   % passo
err = norm(d)/norm(b);

%passi successivi
while err > toll
    x = x + a*d;
    d = d - a*A*d;
    a = (d'*d)/(d'*A*d);
    err = norm(d)/norm(b);
    c = c+1;
end

printf("La soluzione esatta è (")
printf(" %.4f ", xes)
printf(")\n")
printf("Dopo %g iterazioni la soluzione stimata è (", c)
printf(" %.4f ", x)
printf(")\n")
printf("con un errore di %.8f\n", err)