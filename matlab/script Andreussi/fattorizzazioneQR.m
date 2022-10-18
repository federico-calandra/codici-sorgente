function [Q,R] = fattorizzazioneQR(A)
%Calcola la fattorizzazione A=Q*R, dove Q è una matrice ortogonale e R è 
%una matrice triangolare superiore

[n,m] = size(A);
if n<m
    error('La matrice deve essere quadrata o avere piú righe che colonne');
end

Q = A;
Q(:,1) = Q(:,1)/sqrt(Q(:,1)'*Q(:,1));
for i=2:m
    for j=1:i-1
        Q(:,i) = Q(:,i) - (Q(:,j)'*Q(:,i))*Q(:,j);
    end
    Q(:,i) = Q(:,i)/sqrt(Q(:,i)'*Q(:,i));
end

Q
R = Q'*A