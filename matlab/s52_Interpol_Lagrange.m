%% Interpolazione polinomiale secondo Lagrange
% Viene generato un N-vettore di nodi equispaziati tra 0 e 5 e un vettore
% dei corrispondenti valori. Dato il punto xp in cui si vuole interpolare,
% si calcola il valore dei polinomi di Lagrange in xp e infine il valore
% del polinomio di interpolazione.

clear
clc

sp = input("Spaziatura dei nodi (default 1): "); if isempty(sp); sp = 1; end;
xh = [0:sp:10]
n = size(xh);
yh = rand(n)

xp = input("nodo in cui interpolare (default 0.33)"); if isempty(xp); xp=0.33; end;

l=ones(n);

for i=1:n(2)   % per ogni nodo
    for j=1:n(2) % valuto il relativo polinomio di Lagrange
        if j~=i; l(i)=l(i) * (xp-xh(j)) / (xh(i)-xh(j)); end    % tranne per i=j
    end     % ho valutato l'i-esimo polinomio
end     % ho valutato tutti i polinomi

yp=yh*l';    % valuto l'interpolazione

printf("Il valore interpolato in %f è %f\n",xp,yp)