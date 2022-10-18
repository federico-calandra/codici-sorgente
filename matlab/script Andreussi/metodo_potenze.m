function [rq,z] = metodo_potenze(A,y,tol,nmax)
% Metodo delle potenze per determinare l'autovalore di modulo massimo di 
% una matrice A, dato y come vettore iniziale.

[n,m]=size(A) ;
if (n~=m); error('Solo sistemi quadrati') ; end

% Inizializzazione del processo
z = y/norm(y);
rq = z'*A*z;
diff = tol + 1; %questa scelta è un modo per imporre diff > tol al passo zero 
iter = 0;

while (diff > tol) && (iter < nmax)
    iter = iter + 1;
    y = A*z;
    z = y/norm(y);
    rq_temp = rq; %si salva il vecchio valore per controllare la variazione
    rq = z'*A*z;
    diff = abs(rq-rq_temp);
end

