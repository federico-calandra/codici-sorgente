%% Fattorizzazione LU
% Dal metodo di Gauss si ottiene una matrice trangolare superiore U mediante
% le matrici dei moltiplicatori M1*M2*...*Mn*A=U. Queste matrici sono
% triangolari inferiori così come il loro prodotto e le loro inverse,
% perciò (M1*...*Mn)^(-1)=L è triangolare inferiore e si può scrivere A=LU.

clear; clc;

N = input('Specifca la dimensione della matrice: ');
A = rand(N)
b = ones(N,1)

xes = A\b

L = eye(N)    % la definisco fuori dal ciclo e la costruisco ad ogni passo

for i = 1:N-1 % loop sulle colonne
   M = eye(N);    % parte da una diagonale unitaria
   M(i+1:end,i) = -A(i+1:end,i)/A(i,i)   % come nell'algoritmo di Gauss
   L(i+1:end,i) = A(i+1:end,i)/A(i,i) % costruisco le colonne calcolando l'inversa
   A = M*A    % come in Gauss
end

U = A;

y = L\b;
x = U\y
xes