%% Fattorizzazione QR
% Per calcolare il fattore Q viene chiamata la funzione fGramSchmidt che
% restituisce la forma ortogonale di A. Il fattore R si ottiene come R=Q'*A

clear; clc

n = input("Specificare il n. di righe: ");
m = input("Specificare il n. di colonne: ");

if m>n
    error("La matrice deve avere più righe che colonne, oppure essere quadrata")
end

A = rand(n,m)
Q = fGramSchmidt(A)
R = Q'*A