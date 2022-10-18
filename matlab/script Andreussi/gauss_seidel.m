%function [x,iter] = gauss_seidel(A,b,x0,tol,nmax)
% Metodo iterativo di Gauss-Seidel per la risoluzione di sistemi lineari 
% [X,ITER] = jacobi_iter(A,B,X0,TOL,NMAX) trova la soluzione di AX=B 
% partendo dal vettore iniziale X0. 
% NMAX è il numero massimo di iterazioni. 
% TOL è la tolleranza sulla norma del residuo del criterio d'arresto. 
% ITER è il numero dell'iterazione a cui si e' ottenuta la soluzione 

[n,m]=size(A) ;
if (n~=m); error('Solo sistemi quadrati') ; end

% Calcolo di P=D-E e di F
P = zeros(n,n);
F = zeros(n,n);
for i=1:n
    if abs(A(i,i)) <= 1e-10;  error('Matrice P singolare') ; end
    P(i,1:i) = A(i,1:i);
    F(i,i+1:n) = -A(i,i+1:n);
end

P
F

% Inizializzazione del processo
x = x0;
stimaerr = 1; 
iter = 0;
while (stimaerr > tol) && (iter < nmax)
    iter = iter + 1;
    % Risoluzione del sistema P*x = F*x + b, con P triangolare inferiore
    x = P\(F*x + b);
    % Calcolo del residuo
    r = b-A*x; 
    % Calcolo dell'errore stimato stimaerr = ||r||
    stimaerr = norm(r);
end

if iter==nmax; error('Il processo non è arrivato a convergenza'); end

%return