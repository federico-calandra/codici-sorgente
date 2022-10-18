function [norma] = fPNorm(v,p)
%% Calcola la p-norma di un vettore v

norma = 0;
for i=1:lenght(v)
   norma = norma + v(i)^p;
end

norma = nthroot(norma,p);
norma;
