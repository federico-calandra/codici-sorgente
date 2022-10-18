%% Metodo delle potenze
% Viene generata una matrice NxN e un vettore di partenza. 

clear; clc;

% dati
toll = input("Tolleranza (default 1e-6): ");
if isempty(toll);   toll = 1e-6;    end;
N = input("Dimensione matrice: ");
A = rand(N,N)
y = rand(N,1)

q = y/norm(y);
R = q'*A*q;
iter = 0;
diff = toll + 1;

while (diff > toll) && (iter < 5000)
   y = A*q;
   q = y/norm(y);
   Rtemp = q'*A*q;
   Rtemp = q'*A*q;
   diff = abs(R-Rtemp);
   R = Rtemp;
   iter = iter + 1;
end

printf("Dopo %d iterazioni si è trovato l'autovalore dominante %.3f\n", iter, R);
printf("L'autovettore associato è (");
printf(" %.3f  ",y);
printf(")");