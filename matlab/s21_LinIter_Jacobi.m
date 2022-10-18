%% Metodo di Jacobi
% Prima di iterare bisogna controllare il raggio di convergenza. Costruisco
% la matrice B a partire dalla matrice A. Una volta verificata si avvia il
% processo. Più la soluzione stimata è vicina a quella esatta, meno
% iterazioni sono necessarie.

clear; clc

% dati
A = [5 2 2;1 3 1;2 0 4] % la matrice ha raggio spettrale <1
b = ones(3,1)
xes = A\b;
xp = rand(3,1); % soluzione di partenza
toll = input("Tolleranza sulla soluzione (default 1e-6): ");  % tolleranza
if isempty(toll);   toll = 1e-6;    end;
c = 0;  % contatore di iterazioni

% costruisco matrice B
D=diag(diag(A));    % matrice deglielementi diagonali di A
Di=diag(1./diag(A));    % matrice degli inversi degli elementi diagonali di A
B = Di*(D-A);

% controllo raggio spettrale
spect = fSpectRad(B);
if spect > 1
    error("Il raggio spettrale è maggiore di 1, il metodo non può convergere\n")
end

crit = input("\nCriterio di arresto da utilizzare (default 1)?\n1- errore assoluto |x-x0|\n2- residuo |b-Ax|\n3- errore relativo |x-x0|/|x|\n4- residuo normalizzato (b-Ax)/|b|\n");
if isempty(crit);   crit = 1;   end;

%primo passo
x0 = xp;    % partendo dalla soluzione stimata
x = B*x0 + Di*b;    % calcolo la prima approssimazione
switch crit     % valuto l'errore a seconda del caso
    case 1
        err = norm(x-x0);
    case 2
        err = norm(b-A*x);
    case 3
        err = norm(x-x0)/norm(x);
    case 4
        err = norm(b-A*x)/norm(b);
end
c = c+1;

% processo iterativo
while err > toll
    x0 = x; % aggiorno la soluzione di partenza del passo iterativo
    x = B*x + Di*b;  % calcolo la nuova soluzione
    switch crit
        case 1
            err = norm(x-x0);
        case 2
            err = norm(b-A*x);
        case 3
            err = norm(x-x0)/norm(x);
        case 4
            err = norm(b-A*x)/norm(b);
    end   % aggiorno l'errore per la condizione
    c=c+1;
end

% quando err<toll il metodo è a convergenza
printf("La soluzione esatta è (")
printf(" %.4f ", xes)
printf(")\n")
printf("Dopo %g iterazioni la soluzione stimata è (", c)
printf(" %.4f ", x)
printf(")\n")
printf("con un errore di %.8f\n", err)