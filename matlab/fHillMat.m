function [H] = HillMat(N)
%% Genera una matrice di Hillbert N-dimensionale. Essa è simmetrica e
% definita positiva.

H=zeros(N);

for j=1:N
    for i=1:N
        H(i,j)=1/(i+j-1);
    end
end

H;