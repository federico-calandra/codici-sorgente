function [rho] = SpectRad(A)
%Calcolo del raggio spettrale di A
[N M] = size(A);
if N ~= M
    error("La matrice deve essere quadrata")
end
rho = max(norm(eig(A)));
end

