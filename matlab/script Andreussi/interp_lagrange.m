function pol = interp_lagrange(x,y)
%Calcola i coefficienti del polinomio di interpolazione che passa per i
%punti (x,y)

n = length(y);

lag = zeros(n);
lag(:,end) = ones(n,1)

for i=1:n
    for j=1:i-1
        temp = zeros(1,n)
        temp(n-j:n-1) = lag(i,n-j+1:end)
        lag(i,:) = (temp - x(j)*lag(i,:))/(x(i)-x(j))
    end
    for j=i+1:n
        temp = zeros(1,n)
        temp(n-j+1:n-1) = lag(i,n-j+2:end)
        lag(i,:) = (temp - x(j)*lag(i,:))/(x(i)-x(j))
    end
end

pol = y*lag;