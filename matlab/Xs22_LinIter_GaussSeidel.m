%% Metodo di Gauss-Seidel
% Si fissa a priori il numero massimo di iterazioni oltre il quale il metodo
% si considera non convergente. 

%clear; clc

% dati
A = [5 2 2;1 3 1;2 0 4]
b = ones(3,1)
xes = A\b;
xp = rand(3,1); % soluzione di partenza

D1=diag(diag(A));
E1=zeros(3); for i=1:2;  E1(i+1:end,i) = A(i+1:end,i);  end
F1=zeros(3); for j=2:3;  F1(1:j-1,j) = A(1:j-1,j);    end
DE=(D1-E1)
DEi=zeros(3)
for k=1:3
    DEi(k:end,k)=1./DE(k:end,k)
end