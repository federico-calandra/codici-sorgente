function [rq,z] = metodo_potenze_inverse(A,y,lval,tol,nmax)
% Metodo delle potenze inverse per determinare l'autovalore della matrice A
% più vicino a lval, dato y come vettore iniziale.

[n,m]=size(A) ;
if (n~=m); error('Solo sistemi quadrati') ; end

N = sparse(A - lval*eye(n));

%La risoluzione del sistema Ny=z si compie sfruttando la fattorizzazione LU
%con pivot totale PNQ=LU. 
[L,U,P,Q] = lu(N);
%Si ricava: Ny=z --> PNQQ'y=Pz --> w=Q'y e LUw=Pz --> q=Uw e Lq=Pz
%Quindi:    q=L\(Pz) --> w=U\q --> y=Qw
M = @(x) Q*(U\(L\(P*x)));

% Inizializzazione del processo
z = y/norm(y);
rq = z'*A*z;
diff = tol + 1; %questa scelta è un modo per imporre diff > tol al passo zero
iter = 0;

while (diff > tol) && (iter < nmax)
    iter = iter + 1;
    y = M(z);
    z = y/norm(y);
    rq_temp = rq; %si salva il vecchio valore per controllare la variazione
    rq = z'*A*z;
    diff = abs(rq-rq_temp);
end

