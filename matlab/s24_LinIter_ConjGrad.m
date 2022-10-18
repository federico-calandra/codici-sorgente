%dati
n = 3;
A = rand(n);
A = A'*A
b = ones(n,1);
toll = 1e-1;

%passo iniziale
x = rand(n,1)
r = -A*x+b
d = r
alpha = (d'*r)/(d'*A*d)
err = norm(r)/norm(b)
c = 1
x = x+alpha*d

%passi successivi
while err > toll 
    c = c+1
    r = r-alpha*A*d
    beta = (r'*A*d)/(d'*A*d)
    d = r-beta*d
    alpha = (d'*r)/(d'*A*d)
    x = x+alpha*d
    err = norm(r)/norm(b)
end

%verifica soluzione
c
x
xes=A\b