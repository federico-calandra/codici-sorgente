%% Metodo di bisezione
% Applica l'algoritmo di bisezione per trovare lo zero di f in [a,b]
% Si sfrutta il fatto che l'intervallo in cui si trova lo zero può essere
% reso più piccolo di una certa tolleranza.

clear; clc;

% inserisco funzione, intervallo e tolleranza
f = @(x) x-cos(x);
a = input("Inserisci estremo destro: ");
b = input("Inserisci estremo sinistro: ");

% controllo che nell'intervallo ci sia almeno uno zero
if sign(f(a)*f(b))>0; error("La funzione non ha uno zero in [%.2f,%.2f]\n",a,b); end

toll = input("Inserisci tolleranza: ");

% calcolo il num. di iterazioni necessarie per soddisfare la tolleranza
n = ceil(log((b-a)/toll)/log(2));

for i=1:n
    c = (a+b)/2;  % calcolo in p.to medio dell'intervallo
    if (f(a)*f(c))<0    % lo zero si trova in [a,c]
        b=c;
    elseif (f(c)*f(b))<0    % lo zero si trova in [c,b]
        a=c;
    else    % lo zero è proprio c
        zero=c;
    end
end     % dopo n iterazioni l'intervallo è più piccolo di toll
zero = (a+b)/2;   % quindi il p.to medio è con buona approssimazione lo zero
res = f(zero);

printf("La funzione ha uno zero in %f\n", zero)
printf("Il residuo è %f",res)