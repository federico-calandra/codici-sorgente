%% Algoritmo di riduzione di Gauss
% Genera una matrice casuale NxN e risolve il sistema Ax=1 mediante
% l'algortimo di Gauss, ottenendo una matrice triangolare superiore.

clear; clc;

N=input('Specifica la dimensione della matrice: ');

A=rand(N)
b=ones(N,1);

xes=A\b;

for i=1:N-1 % loop sulle colonne
    M=eye(N);   % genera una matrice diagonale unitaria
    M(i+1:end,i)=-A(i+1:end,i)/A(i,i);  % elabora gli elementi sotto quello diagonale
    A=M*A;   % la nuova matrice ha tutti zeri sotto la diagonale (dell'i-esima colonna)
    b=M*b;   % calcola il nuovo termine noto
end
% alla fine del ciclo ho una matrice triangolare superiore
x = A\b;

% confronta le soluzioni
fprintf("La soluzione esatta è (")
fprintf("%.4f ",xes)
fprintf( ")\n")
fprintf("La soluzione trovata è (")
fprintf(" %.4f ",x)
fprintf(")")