clear; clc;

toll = input("Tolleranza (default 1e-6): ");
if isempty(toll);   toll = 1e-6;    end;
N = input("Dimensione matrice: ");
A = rand(N,N)
y = rand(N,1)

q = y/norm(y)
y = A\q