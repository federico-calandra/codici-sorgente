function [Q] = m02_GramSchmidt(A)

n = size(A);
Q = A;  %   invece di sovrascrivere A, lavoro sulla futura matrice ortogonale

Q(:,1) = Q(:,1) / sqrt(Q(:,1)'*Q(:,1));   % il primo vettore va solo normalizzato

for i = 2:n(2)     % tutti gli altri vettori
    for j = 1:i-1   % vanno resi ortogonali rispetto ai precedenti
        Q(:,i) = Q(:,i) - (Q(:,j)'*Q(:,i)) * Q(:,j);
    end
    Q(:,i) = Q(:,i) / sqrt(Q(:,i)'*Q(:,i));     % e poi normalizzati
end

end

